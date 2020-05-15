#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include "exceptionBase.h"

class MemoryException: public ExceptionBase {
public:
    MemoryException(std::string fileName, std::string className,
                    int currentLine, const char *errorTime,
                    std::string information = "Memory Error"):
        ExceptionBase(fileName, className, currentLine, errorTime, information) {
    };
    virtual const char *what() const noexcept {
        return errorInformation.c_str();
    }
};

class DeletedObjectException: public ExceptionBase {
public:
    DeletedObjectException(std::string fileName, std::string className,
                           int currentLine, const char *errorTime,
                           std::string information = "Object doesn't exsist"):
        ExceptionBase(fileName, className, currentLine, errorTime, information) {
    };
};

class EmptyVectorException: public ExceptionBase {
public:
    EmptyVectorException(std::string fileName, std::string className,
                         int currentLine, const char *errorTime,
                         std::string information = "Work with empty vector"):
        ExceptionBase(fileName, className, currentLine, errorTime, information) {
    };
};

// новый класс ошибки под итератор

class OutOfRangeException: public ExceptionBase {
public:
    OutOfRangeException(std::string fileName, std::string className,
                          int currentLine, const char *errorTime,
                          std::string information = "Index is out of range"):
        ExceptionBase(fileName, className, currentLine, errorTime, information) {
    };
};

class ZeroDivisionException: public ExceptionBase {
public:
    ZeroDivisionException(std::string fileName, std::string className,
                          int currentLine, const char *errorTime,
                          std::string information = "Zero division error"):
        ExceptionBase(fileName, className, currentLine, errorTime, information) {
    };
};

class InvalidCopyArrayPointer: public ExceptionBase {
public:
    InvalidCopyArrayPointer(std::string fileName, std::string className,
                            int currentLine, const char *errorTime,
                            std::string information = "Zero division error"):
        ExceptionBase(fileName, className, currentLine, errorTime, information) {
    };
};

class InvalidVectorsSizes: public ExceptionBase {
public:
    InvalidVectorsSizes(std::string fileName, std::string className,
                            int currentLine, const char *errorTime,
                            std::string information = "Vectors sizes equality error"):
        ExceptionBase(fileName, className, currentLine, errorTime, information) {
    };
};

#endif // EXCEPTIONS_H
