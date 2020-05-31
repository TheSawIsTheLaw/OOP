#ifndef EXCEPTIONBASE_H
#define EXCEPTIONBASE_H

#include <exception>
#include <iostream>

// Переименовать
class VectorException: public std::exception {
public:
   VectorException(std::string fileName, std::string className,
                  int currentLine, const char *errorTime,
                  std::string information);
    virtual const char *what() const noexcept override;

    virtual ~VectorException() { }

protected:
    std::string errorInformation;
};

//! Реализация в отдельный файл
#include "ExceptionBase.hpp"

#endif // EXCEPTIONBASE_H
