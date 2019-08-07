#include "Exceptions.h"

NegativeMileageException::NegativeMileageException() : std::exception() { }

NegativeMileageException::NegativeMileageException(const char* incomingMessage) : std::exception(incomingMessage) { }

NegativeMileageException::NegativeMileageException(const char* incomingMessage, int lineNumber) : std::exception(incomingMessage, lineNumber) { }

NegativeMileageException::NegativeMileageException(const std::exception &innerException) : std::exception(innerException) { }

YearBefore1970Exception::YearBefore1970Exception() : std::exception() { }

YearBefore1970Exception::YearBefore1970Exception(const char* incomingMessage) : std::exception(incomingMessage) { }

YearBefore1970Exception::YearBefore1970Exception(const char* incomingMessage, int lineNumber) : std::exception(incomingMessage, lineNumber) { }

YearBefore1970Exception::YearBefore1970Exception(const std::exception &innerException) : std::exception(innerException) { }

InvalidMakeException::InvalidMakeException() : std::exception() { }

InvalidMakeException::InvalidMakeException(const char* incomingMessage) : std::exception(incomingMessage) { }

InvalidMakeException::InvalidMakeException(const char* incomingMessage, int lineNumber) : std::exception(incomingMessage, lineNumber) { }

InvalidMakeException::InvalidMakeException(const std::exception &innerException) : std::exception(innerException) { }

YearAfter2019Exception::YearAfter2019Exception() : std::exception() { }

YearAfter2019Exception::YearAfter2019Exception(const char* incomingMessage) : std::exception(incomingMessage) { }

YearAfter2019Exception::YearAfter2019Exception(const char* incomingMessage, int lineNumber) : std::exception(incomingMessage, lineNumber) { }

YearAfter2019Exception::YearAfter2019Exception(const std::exception &innerException) : std::exception(innerException) { }

InvalidVINException::InvalidVINException() : std::exception() { }

InvalidVINException::InvalidVINException(const char* incomingMessage) : std::exception(incomingMessage) { }

InvalidVINException::InvalidVINException(const char* incomingMessage, int lineNumber) : std::exception(incomingMessage, lineNumber) { }

InvalidVINException::InvalidVINException(const std::exception &innerException) : std::exception(innerException) { }
