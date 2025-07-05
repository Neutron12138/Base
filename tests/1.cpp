#include <iostream>
#define BASE_DEFINE_FLOAT_TYPE
#include "../base/base.hpp"

int main()
{
    std::cout << "Float32: " << sizeof(base::Float32) << std::endl
              << "Float64: " << sizeof(base::Float64) << std::endl
              << "Float128: " << sizeof(base::Float128) << std::endl
              << std::endl;

    std::cout << "test to_string:" << std::endl
              << base::to_string() << std::endl
              << base::to_string(123) << std::endl
              << base::to_string("good", " ", "job") << std::endl
              << std::endl;

    std::cout << "read string from \"1.txt\":" << std::endl
              << base::read_string_from_file("1.txt") << std::endl
              << std::endl;

    base::Logger logger;
    logger.logi("successfully output log");

    return 0;
}
