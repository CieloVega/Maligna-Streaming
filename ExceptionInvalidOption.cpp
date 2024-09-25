#include "ExceptionInvalidOption.hpp"


const char* ExceptionInvalidOption::what() const noexcept
{
    return m_error.c_str();
}