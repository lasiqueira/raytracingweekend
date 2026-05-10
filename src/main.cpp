#include "rtweekend.h"

#include "camera.h"
#include "hittable.h"
#include "hittable_list.h"
#include "material.h"
#include "sphere.h"
#include "scope_timer.h"
#include <vector>

int main()
{
	hittable_list world;

	std::vector<lambertian> lambertians;
	std::vector<metal> metals;
	std::vector<dielectric> dielectrics;
	
	lambertians.reserve(1000);
	metals.reserve(1000);
	dielectrics.reserve(1000);

	int lambertian_idx = 0;
	int metal_idx = 0;
	int dieletric_idx = 0;
	
	lambertians.emplace_back(color(0.5, 0.5, 0.5));

	world.objects.reserve(1000);
	
	world.objects.emplace_back(point3(0, -1000, 0), 1000, material_type::Lambertian, lambertian_idx++);

	for (int a = -11; a < 11; a++)
	{
		for (int b = -11; b < 11; b++)
		{
			auto choose_mat = random_double();
			point3 center(a + 0.9 * random_double(), 0.2, b + 0.9 * random_double());

			if ((center - point3(4, 0.2, 0)).length() > 0.9)
			{
				material_type sphere_material;

				if (choose_mat < 0.8)
				{
					// diffuse
					auto albedo = color::random() * color::random();
					sphere_material = material_type::Lambertian;
					lambertians.emplace_back(albedo);
					world.objects.emplace_back(center, 0.2, sphere_material, lambertian_idx++);
				}
				else if (choose_mat < 0.95)
				{
					// metal
					auto albedo = color::random(0.5, 1);
					auto fuzz = random_double(0, 0.5);
					sphere_material = material_type::Metal;
					metals.emplace_back(albedo, fuzz);
					world.objects.emplace_back(center, 0.2, sphere_material, metal_idx++);
					
				}
				else
				{
					//glass
					sphere_material = material_type::Dielectric;
					dielectrics.emplace_back(1.5);
					world.objects.emplace_back(center, 0.2, sphere_material, dieletric_idx++);
				}
			}
		}
	}

	dielectrics.emplace_back(1.5);
	world.objects.emplace_back(point3(0, 1, 0), 1.0, material_type::Dielectric, dieletric_idx++);

	lambertians.emplace_back(color(0.4, 0.2, 0.1));
	
	world.objects.emplace_back(point3(-4, 1, 0), 1.0, material_type::Lambertian, lambertian_idx++);

	metals.emplace_back(color(0.7, 0.6, 0.5), 0.0);
	
	world.objects.emplace_back(point3(4, 1, 0), 1.0, material_type::Metal, metal_idx++);

	camera cam;

	cam.aspect_ratio = 16.0 / 9.0;
	cam.image_width = 1920;
	cam.samples_per_pixel = 50;
	cam.max_depth = 10;

	cam.vfov = 20;
	cam.lookfrom = point3(13, 2, 3);
	cam.lookat = point3(0, 0, 0);
	cam.vup = vec3(0, 1, 0);

	cam.defocus_angle = 0.6;
	cam.focus_dist =10.0;
	std::ofstream out("image_original.ppm");
	scope_timer t("Original render");
	cam.render(world,lambertians, metals, dielectrics, out);
	out.close();
}