#ifndef EXCEPTION_H

#define EXCEPTION_H

#include <exception>
#include <iostream>
#include <stdexcept>
#include <string>

class Exception : public std::runtime_error {
public:
    explicit Exception(const std::string &message);
    Exception(const std::string &message, std::exception_ptr cause);

    std::exception_ptr cause() const;

    void print(std::ostream &out = std::cerr) const;

    static void print(const std::exception &e, std::ostream &out = std::cerr,
        int level = 0);

private:
    std::exception_ptr cause_;
};

#endif 
