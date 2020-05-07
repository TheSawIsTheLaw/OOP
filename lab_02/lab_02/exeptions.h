#ifndef EXEPTIONS_H
#define EXEPTIONS_H

#include "exceptionBase.h"

class MemoryError: public ExceptionBase {
public:
    MemoryError(std::string fileName, std::string className,
                int currentLine, const char *errorTime,
                std::string information = "Memory Error"):
        ExceptionBase(fileName, className, currentLine, errorTime, information) {
    };
    virtual const char *what() const noexcept {
        return errorInformation.c_str();
    }
};

class DeletedObjectError: public ExceptionBase {
public:
    DeletedObjectError(std::string fileName, std::string className,
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

class InvalidIndexError: public ExceptionBase {
public:
    InvalidIndexError(std::string fileName, std::string className,
                          int currentLine, const char *errorTime,
                          std::string information = "Invalid indexing"):
        ExceptionBase(fileName, className, currentLine, errorTime, information) {
    };
};

class ZeroDivisionError: public ExceptionBase {
public:
    ZeroDivisionError(std::string fileName, std::string className,
                      int currentLine, const char *errorTime,
                      std::string information = "Invalid indexing"):
        ExceptionBase(fileName, className, currentLine, errorTime, information) {
    };
};

#endif // EXEPTIONS_H
