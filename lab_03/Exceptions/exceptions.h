#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include "exceptionbase.h"

class MemoryException : public VectorException
{
public:
    MemoryException(std::string fileName,
                    std::string className,
                    int currentLine,
                    const char *errorTime,
                    std::string information = "Memory Error")
        : VectorException(fileName, className, currentLine, errorTime, information) {};
    virtual const char *what() const noexcept { return errorInformation.c_str(); }
};

class DeletedObjectException : public VectorException
{
public:
    DeletedObjectException(std::string fileName,
                           std::string className,
                           int currentLine,
                           const char *errorTime,
                           std::string information = "Object doesn't exsist")
        : VectorException(fileName, className, currentLine, errorTime, information) {};
};

class EmptyVectorException : public VectorException
{
public:
    EmptyVectorException(std::string fileName,
                         std::string className,
                         int currentLine,
                         const char *errorTime,
                         std::string information = "Work with empty vector")
        : VectorException(fileName, className, currentLine, errorTime, information) {};
};

class OutOfRangeException : public VectorException
{
public:
    OutOfRangeException(std::string fileName,
                        std::string className,
                        int currentLine,
                        const char *errorTime,
                        std::string information = "Index is out of range")
        : VectorException(fileName, className, currentLine, errorTime, information) {};
};

class ZeroDivisionException : public VectorException
{
public:
    ZeroDivisionException(std::string fileName,
                          std::string className,
                          int currentLine,
                          const char *errorTime,
                          std::string information = "Zero division error")
        : VectorException(fileName, className, currentLine, errorTime, information) {};
};

class InvalidCopyArrayPointer : public VectorException
{
public:
    InvalidCopyArrayPointer(std::string fileName,
                            std::string className,
                            int currentLine,
                            const char *errorTime,
                            std::string information = "Zero division error")
        : VectorException(fileName, className, currentLine, errorTime, information) {};
};

class InvalidVectorsSizes : public VectorException
{
public:
    InvalidVectorsSizes(std::string fileName,
                        std::string className,
                        int currentLine,
                        const char *errorTime,
                        std::string information = "Vectors sizes equality error")
        : VectorException(fileName, className, currentLine, errorTime, information) {};
};

class InvalidIterator : public VectorException
{
public:
    InvalidIterator(std::string fileName,
                    std::string className,
                    int currentLine,
                    const char *errorTime,
                    std::string information = "Iterator is invalid")
        : VectorException(fileName, className, currentLine, errorTime, information) {};
};

class OutOfRangeIterException : public VectorException
{
public:
    OutOfRangeIterException(std::string fileName,
                            std::string className,
                            int currentLine,
                            const char *errorTime,
                            std::string information = "Iterator is out of vector range")
        : VectorException(fileName, className, currentLine, errorTime, information) {};
};

class InvalidInitializerList : public MatrixException
{
public:
    InvalidInitializerList(std::string fileName,
                           std::string className,
                           int currentLine,
                           const char *errorTime,
                           std::string information = "Invalid initializer list")
        : MatrixException(fileName, className, currentLine, errorTime, information) {};
};

class OutOfRangeMatException : public MatrixException
{
public:
    OutOfRangeMatException(std::string fileName,
                           std::string className,
                           int currentLine,
                           const char *errorTime,
                           std::string information = "Invalid initializer list")
        : MatrixException(fileName, className, currentLine, errorTime, information) {};
};

class InvalidComponentName : public SceneException
{
public:
    InvalidComponentName(std::string fileName,
                         std::string className,
                         int currentLine,
                         const char *errorTime,
                         std::string information = "Invalid component name")
        : SceneException(fileName, className, currentLine, errorTime, information) {};
};

class InvalidComponentIndex : public SceneException
{
public:
    InvalidComponentIndex(std::string fileName,
                          std::string className,
                          int currentLine,
                          const char *errorTime,
                          std::string information = "Invalid component index")
        : SceneException(fileName, className, currentLine, errorTime, information) {};
};

class InvalidCurrentSceneNum : public SceneException
{
public:
    InvalidCurrentSceneNum(std::string fileName,
                           std::string className,
                           int currentLine,
                           const char *errorTime,
                           std::string information = "Invalid current scene number")
        : SceneException(fileName, className, currentLine, errorTime, information) {};
};

class BadFile : public SceneUploaderException
{
public:
    BadFile(std::string fileName,
            std::string className,
            int currentLine,
            const char *errorTime,
            std::string information = "Invalid current scene number")
        : SceneUploaderException(fileName, className, currentLine, errorTime, information) {};
};

class InvalidCamera : public CameraBuilderException
{
public:
    InvalidCamera(std::string fileName,
                  std::string className,
                  int currentLine,
                  const char *errorTime,
                  std::string information = "Invalid Camera")
        : CameraBuilderException(fileName, className, currentLine, errorTime, information) {};
};

class InvalidDotNum : public ModelBuilderException
{
public:
    InvalidDotNum(std::string fileName,
                  std::string className,
                  int currentLine,
                  const char *errorTime,
                  std::string information = "Invalid dot number")
        : ModelBuilderException(fileName, className, currentLine, errorTime, information) {};
};

class InvalidEdgeNum : public ModelBuilderException
{
public:
    InvalidEdgeNum(std::string fileName,
                   std::string className,
                   int currentLine,
                   const char *errorTime,
                   std::string information = "Invalid dot number")
        : ModelBuilderException(fileName, className, currentLine, errorTime, information) {};
};

class InvalidModelData : public ModelBuilderException
{
public:
    InvalidModelData(std::string fileName,
                     std::string className,
                     int currentLine,
                     const char *errorTime,
                     std::string information = "Invalid model file data")
        : ModelBuilderException(fileName, className, currentLine, errorTime, information) {};
};

class ObjectBuildFail : public ModelBuilderException
{
public:
    ObjectBuildFail(std::string fileName,
                    std::string className,
                    int currentLine,
                    const char *errorTime,
                    std::string information = "Duild object fail")
        : ModelBuilderException(fileName, className, currentLine, errorTime, information) {};
};

#endif // EXCEPTIONS_H
