// class-templates-2.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include <string>
#include <iomanip>

template <typename T, int N>
class Array {
private:
    int size{ N };
    T values[N];

    friend std::ostream& operator<< (std::ostream& os, const Array<T, N>& arr) {
    os << "[";
    for (const auto& val : arr.values)
        os << val << " ";
    os << "]" << std::endl;
    return os;
    }
public:
    Array() {};
    Array(T init_val) {
        for (auto& item : values)
            item = init_val;
    }
    void fill(T val) {
        for (auto& item : values)
            item = val;
    }
    int get_size() const {
        return size;
    }
    //overloaded subscript operator [] for easy use
    T& operator[](int index) {
        return values[index];
    }
    ~Array() = default;
};

int main()
{
    Array< int, 5> nums;
    std::cout << "The size of nums is: " << nums.get_size() << std::endl;
    std::cout << nums << std::endl;

    nums.fill(0);
    std::cout << "The size of nums is: " << nums.get_size() << std::endl;
    std::cout << nums << std::endl;

    nums.fill(10);
    std::cout << nums << std::endl;
    nums[0] = 1000;
    nums[3] = 2000;
    std::cout << nums << std::endl;

    Array<std::string, 5> nums2{ "Jenny" };
    std::cout << nums2.get_size() << std::endl;
    std::cout << nums2 << std::endl;

    nums2.fill("Elizabeth");
    std::cout << nums2 << std::endl;
    nums2[0] = { "Gabriel" };
    std::cout << nums2 << std::endl;
    nums2[4] = { "Gabriel" };
    std::cout << nums2 << std::endl;

    Array<double, 100> nums3;
    std::cout << nums3 << std::endl;
    nums3.fill(1);
    std::cout << nums3 << std::endl;

    return 0;
}
