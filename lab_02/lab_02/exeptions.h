#ifndef EXEPTIONS_H
#define EXEPTIONS_H

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

class EmptyVectorError: public ExceptionBase {
public:
    EmptyVectorError(std::string fileName, std::string className,
                     int currentLine, const char *errorTime,
                     std::string information = "Work with empty vector"):
        ExceptionBase(fileName, className, currentLine, errorTime, information) {
    };
};

class InvalidIndexException: public ExceptionBase {
public:
    InvalidIndexException(std::string fileName, std::string className,
                          int currentLine, const char *errorTime,
                          std::string information = "Invalid indexing"):
        ExceptionBase(fileName, className, currentLine, errorTime, information) {
    };
};

#endif // EXEPTIONS_H
