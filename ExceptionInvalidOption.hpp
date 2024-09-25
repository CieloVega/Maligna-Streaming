#pragma once
#include <exception>
#include <iostream>

class ExceptionInvalidOption:public std::exception{
private:
    std::string m_error{"Opcion Invalida"};
public:
    ExceptionInvalidOption(const std::string& error):m_error{error}{};

    const char* what() const noexcept;  
};