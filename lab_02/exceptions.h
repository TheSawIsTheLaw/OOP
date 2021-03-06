#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include "exceptionBase.h"

class MemoryException: public VectorException {
public:
    MemoryException(std::string fileName, std::string className,
                    int currentLine, const char *errorTime,
                    std::string information = "Memory Error"):
        VectorException(fileName, className, currentLine, errorTime, information) {
    };
    virtual const char *what() const noexcept {
        return errorInformation.c_str();
    }
};

class DeletedObjectException: public VectorException {
public:
    DeletedObjectException(std::string fileName, std::string className,
                           int currentLine, const char *errorTime,
                           std::string information = "Object doesn't exsist"):
        VectorException(fileName, className, currentLine, errorTime, information) {
    };
};

class EmptyVectorException: public VectorException {
public:
    EmptyVectorException(std::string fileName, std::string className,
                         int currentLine, const char *errorTime,
                         std::string information = "Work with empty vector"):
        VectorException(fileName, className, currentLine, errorTime, information) {
    };
};

//! новый класс ошибки под итератор

class OutOfRangeException: public VectorException {
public:
    OutOfRangeException(std::string fileName, std::string className,
                          int currentLine, const char *errorTime,
                          std::string information = "Index is out of range"):
        VectorException(fileName, className, currentLine, errorTime, information) {
    };
};

class ZeroDivisionException: public VectorException {
public:
    ZeroDivisionException(std::string fileName, std::string className,
                          int currentLine, const char *errorTime,
                          std::string information = "Zero division error"):
        VectorException(fileName, className, currentLine, errorTime, information) {
    };
};

class InvalidCopyArrayPointer: public VectorException {
public:
    InvalidCopyArrayPointer(std::string fileName, std::string className,
                            int currentLine, const char *errorTime,
                            std::string information = "Zero division error"):
        VectorException(fileName, className, currentLine, errorTime, information) {
    };
};

class InvalidVectorsSizes: public VectorException {
public:
    InvalidVectorsSizes(std::string fileName, std::string className,
                            int currentLine, const char *errorTime,
                            std::string information = "Vectors sizes equality error"):
        VectorException(fileName, className, currentLine, errorTime, information) {
    };
};

class InvalidIterator: public VectorException {
public:
    InvalidIterator(std::string fileName, std::string className,
                            int currentLine, const char *errorTime,
                            std::string information = "*Iterator is invalid"):
        VectorException(fileName, className, currentLine, errorTime, information) {
    };
};

#endif // EXCEPTIONS_H
