#ifndef HITTABLE_H
#define HITTABLE_H


enum class material_type;

class hit_record 
{
	public:
		point3 p;
		vec3 normal;
		material_type mat_type;
		int mat_idx;
		double t;
		bool front_face;

		void set_face_normal(const ray& r, const vec3& outward_normal)
		{
			// Sets the hit record normal vector.
			// NOTE: the parameter `outward_normal` is assumed to have unit length.

			front_face = dot(r.direction(), outward_normal) < 0;
			normal = front_face ? outward_normal : -outward_normal;
		}
};

#endif
