#include <iostream>
#include <io.h>
#include <fcntl.h>
#include "../base/base.hpp"

struct A
{
    void func()
    {
        throw BASE_MAKE_CLASS_RUNTIME_ERROR("an error");
    }
};

class MyApp : public base::Application
{
private:
    base::SystemTime time;

protected:
    void _initialize() override
    {
        base::print_line("Float32: ", sizeof(base::Float32));
        base::print_line("Float64: ", sizeof(base::Float64));
#ifdef BASE_TYPE_HAS_FLOAT_128
        base::print_line("Float128: ", sizeof(base::Float128));
#endif
        base::print_line();

        base::print_line("test to_string:");
        base::print_line("to_string(): ", base::to_string());
        base::print_line("to_string(123): ", base::to_string(123));
        base::print_line("to_string(\"good\", \" \", \"job\"): ", base::to_string("good", " ", "job"));
        base::print_line();

        base::print_line_w("test to_wstring:");
        base::print_line_w("to_wstring(): ", base::to_wstring());
        base::print_line_w("to_wstring(123): ", base::to_wstring(123));
        base::print_line_w("to_wstring(\"good\", \" \", \"job\"): ", base::to_wstring("good", " ", "job"));
        base::print_line_w();

        try
        {
            A a;
            a.func();
        }
        catch (const std::exception &e)
        {
            base::print_line(e.what());
            base::print_line();
        }

        base::print_line("read bytes from \"1.txt\": ");
        auto buffer = base::read_bytes_from_file("1.txt");
        base::print_line("file size: ", buffer.size(), " bytes");
        std::string content = {buffer.cbegin(), buffer.cend()};
        base::print_line("file content: \"", content, "\"");
        base::print_line();

        base::print_line("你好，世界");
        base::print_line("read string from \"1.txt\": ");
        base::print_line(base::read_string_from_file("1.txt"));
        base::print_line();

        _setmode(_fileno(stdout), _O_U8TEXT);
        base::print_line_w(L"你好，世界");
        base::print_line_w(L"read string from \"1.txt\": ");
        base::print_line_w(base::read_wstring_from_file(L"1.txt"));
        base::print_line_w();
    }
};

int main(int argc, char *argv[])
{
    MyApp app;
    app.run(argc, argv);
    return app.get_exit_code();
}
