#include <iostream>
#define BASE_DEFINE_FLOAT_TYPE
#include "../base/base.hpp"

class MyApp : public base::Application
{
private:
    base::Logger logger;
    base::SystemTime time;

protected:
    void _initialize() override
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

        logger.logi("successfully output log");

        auto dur = time.get_current_time().time_since_epoch();
        std::cout << base::SystemTime::Duration(dur).count() << std::endl;
    }
};

int main(int argc, char *argv[])
{
    MyApp app;
    app.run(argc, argv);
    return app.get_exit_code();
}
