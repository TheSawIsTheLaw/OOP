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

MatrixException::MatrixException(std::string fileName,
                                 std::string className,
                                 int currentLine,
                                 const char *errorTime,
                                 std::string information = "Error")
{
    errorInformation = "\nFile: " + fileName + "\nClass: " + className
                       + "\nAt line: " + std::to_string(currentLine) + "\nTime: " + errorTime
                       + "Information about error: " + information;
}

const char *MatrixException::what() const noexcept
{
    return errorInformation.c_str();
}

SceneException::SceneException(std::string fileName,
                               std::string className,
                               int currentLine,
                               const char *errorTime,
                               std::string information = "Error")
{
    errorInformation = "\nFile: " + fileName + "\nClass: " + className
                       + "\nAt line: " + std::to_string(currentLine) + "\nTime: " + errorTime
                       + "Information about error: " + information;
}

const char *SceneException::what() const noexcept
{
    return errorInformation.c_str();
}

SceneUploaderException::SceneUploaderException(std::string fileName,
                                               std::string className,
                                               int currentLine,
                                               const char *errorTime,
                                               std::string information = "Error")
{
    errorInformation = "\nFile: " + fileName + "\nClass: " + className
        + "\nAt line: " + std::to_string(currentLine) + "\nTime: " + errorTime
        + "Information about error: " + information;
}

const char *SceneUploaderException::what() const noexcept
{
    return errorInformation.c_str();
}

ObjectUploaderException::ObjectUploaderException(std::string fileName,
                                                 std::string className,
                                                 int currentLine,
                                                 const char *errorTime,
                                                 std::string information = "Error")
{
    errorInformation = "\nFile: " + fileName + "\nClass: " + className
        + "\nAt line: " + std::to_string(currentLine) + "\nTime: " + errorTime
        + "Information about error: " + information;
}

const char *ObjectUploaderException::what() const noexcept
{
    return errorInformation.c_str();
}

CameraBuilderException::CameraBuilderException(std::string fileName,
                                               std::string className,
                                               int currentLine,
                                               const char *errorTime,
                                               std::string information = "Error")
{
    errorInformation = "\nFile: " + fileName + "\nClass: " + className
        + "\nAt line: " + std::to_string(currentLine) + "\nTime: " + errorTime
        + "Information about error: " + information;
}

const char *CameraBuilderException::what() const noexcept
{
    return errorInformation.c_str();
}

ModelBuilderException::ModelBuilderException(std::string fileName,
                                             std::string className,
                                             int currentLine,
                                             const char *errorTime,
                                             std::string information = "Error")
{
    errorInformation = "\nFile: " + fileName + "\nClass: " + className
        + "\nAt line: " + std::to_string(currentLine) + "\nTime: " + errorTime
        + "Information about error: " + information;
}

const char *ModelBuilderException::what() const noexcept
{
    return errorInformation.c_str();
}
