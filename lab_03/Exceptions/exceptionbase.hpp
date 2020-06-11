#ifndef EXCEPTIONBASE_HPP
#define EXCEPTIONBASE_HPP

#include "exceptionbase.h"

VectorException::VectorException(std::string fileName,
                                 std::string className,
                                 int currentLine,
                                 const char *errorTime,
                                 std::string information = "Error")
{
    errorInformation = "\nFile: " + fileName + "\nClass: " + className
                       + "\nAt line: " + std::to_string(currentLine) + "\nTime: " + errorTime
                       + "Information about error: " + information;
}

const char *VectorException::what() const noexcept
{
    return errorInformation.c_str();
}

#endif // EXCEPTIONBASE_HPP
