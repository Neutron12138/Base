#include <iostream>
#define BASE_DEFINE_FLOAT_TYPE
#include "../base/base.hpp"

class MyApp : public base::Application
{
private:
    base::SystemTime time;

protected:
    void _initialize() override
    {
        base::print_line("test print");

        base::print_line("Float32: ", sizeof(base::Float32));
        base::print_line("Float64: ", sizeof(base::Float64));
#ifdef BASE_TYPE_HAS_FLOAT_128
        base::print_line("Float128: ", sizeof(base::Float128));
#endif
        base::print_line();

        base::print_line("test to_string:");
        base::print_line("base::to_string(): ", base::to_string());
        base::print_line("base::to_string(123): ", base::to_string(123));
        base::print_line("base::to_string(\"good\", \" \", \"job\"): ", base::to_string("good", " ", "job"));
        base::print_line();

        base::print_line("read string from \"1.txt\":");
        base::print_line(base::read_string_from_file("1.txt"));
        base::print_line();

        auto buffer = base::read_bytes_from_file("1.txt");
        base::print_line("read bytes from \"1.txt\":");
        base::print_line("buffer size: ", buffer.size());
        base::print_line(std::string(buffer.begin(), buffer.end()));
        base::print_line();

        base::print_line("sizeof(base::PolymorphicObject): ", sizeof(base::PolymorphicObject));
        base::print_line("sizeof(base::ReferenceObject): ", sizeof(base::ReferenceObject));
        base::print_line();
    }
};

int main(int argc, char *argv[])
{
    MyApp app;
    app.run(argc, argv);
    return app.get_exit_code();
}
