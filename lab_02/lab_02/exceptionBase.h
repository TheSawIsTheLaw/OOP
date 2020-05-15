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
    virtual const char *what() const noexcept override{
        return errorInformation.c_str();
    }

    virtual ~VectorException() { }

protected:
    std::string errorInformation;
};

// Реализация в отдельный файл
VectorException::VectorException(std::string fileName, std::string className,
                             int currentLine, const char *errorTime,
                             std::string information = "Error") {
    errorInformation = "\nFile: " + fileName + "\nClass: " + className +
            "\nAt line: " + std::to_string(currentLine) + "\nTime: " + errorTime +
            "Information about error: " + information;
}

#endif // EXCEPTIONBASE_H
