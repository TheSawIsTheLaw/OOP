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

class SceneUploaderException : public std::exception
{
public:
    SceneUploaderException(std::string fileName,
                   std::string className,
                   int currentLine,
                   const char *errorTime,
                   std::string information);
    virtual const char *what() const noexcept override;

    virtual ~SceneUploaderException() {}

protected:
    std::string errorInformation;
};

class ObjectUploaderException : public std::exception
{
public:
    ObjectUploaderException(std::string fileName,
                            std::string className,
                            int currentLine,
                            const char *errorTime,
                            std::string information);
    virtual const char *what() const noexcept override;

    virtual ~ObjectUploaderException() {}

protected:
    std::string errorInformation;
};

class CameraBuilderException : public std::exception
{
public:
    CameraBuilderException(std::string fileName,
                           std::string className,
                           int currentLine,
                           const char *errorTime,
                           std::string information);
    virtual const char *what() const noexcept override;

    virtual ~CameraBuilderException() {}

protected:
    std::string errorInformation;
};

class ModelBuilderException : public std::exception
{
public:
    ModelBuilderException(std::string fileName,
                          std::string className,
                          int currentLine,
                          const char *errorTime,
                          std::string information);
    virtual const char *what() const noexcept override;

    virtual ~ModelBuilderException() {}

protected:
    std::string errorInformation;
};

#endif // EXCEPTIONBASE_H
