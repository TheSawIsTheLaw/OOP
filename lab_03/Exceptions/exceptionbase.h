#ifndef EXCEPTIONBASE_H
#define EXCEPTIONBASE_H

#include <exception>
#include <iostream>

class VectorException : public std::exception
{
public:
    VectorException(std::string fileName,
                    std::string className,
                    int currentLine,
                    const char *errorTime,
                    std::string information);
    virtual const char *what() const noexcept override;

    virtual ~VectorException() {}

protected:
    std::string errorInformation;
};

class MatrixException : public std::exception
{
public:
    MatrixException(std::string fileName,
                    std::string className,
                    int currentLine,
                    const char *errorTime,
                    std::string information);
    virtual const char *what() const noexcept override;

    virtual ~MatrixException() {}

protected:
    std::string errorInformation;
};

class SceneException : public std::exception
{
public:
    SceneException(std::string fileName,
                   std::string className,
                   int currentLine,
                   const char *errorTime,
                   std::string information);
    virtual const char *what() const noexcept override;

    virtual ~SceneException() {}

protected:
    std::string errorInformation;
};

#include "exceptionbase.hpp"

#endif // EXCEPTIONBASE_H
