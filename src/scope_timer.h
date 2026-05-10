#pragma once
#include <chrono>
#include <iostream>
#include <string>

class scope_timer
{
public:
    scope_timer(const std::string& name) : name_(name), start_(std::chrono::high_resolution_clock::now()) {}
    ~scope_timer()
    {
        using namespace std::chrono;
        auto end = high_resolution_clock::now();
        auto ms = duration_cast<milliseconds>(end - start_).count();
        std::clog << name_ << " took " << ms << " ms\n";
    }
private:
    std::string name_;
    std::chrono::high_resolution_clock::time_point start_;
};