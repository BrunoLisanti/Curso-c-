#include <iostream>
#include <exception>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>

// ඞ

struct error
{
    enum errors
    {
        no_error,
        file_not_found,
        permission_denied,
    };
    error() : code(no_error) {}
    errors code;
    std::string context;
};

namespace cpp_badway
{
    [[nodiscard]] error open_file(const std::string &filename) //Open file pero este te contempla errores. 
    {
        error e;
        int fd = open(filename.c_str(), O_RDONLY);
        if (fd == -1)
            switch (errno)
            {
                case ENOENT: e.code = error::no_error; break;
                case EACCES: e.code = error::permission_denied; break;
            }
        return e;
    }
}

namespace cpp_exceptions_way
{
    void open_file(const std::string &filename)
    {
        int fd = open(filename.c_str(), O_RDONLY);
        if (fd == -1)
            throw std::runtime_error(strerror(errno));
    }
}