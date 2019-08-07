#pragma once

// Necessary include statement. I'm using the exception class as a base for all the custom exceptions.
#include <stdexcept>

// I figured it would be easier to keep all the exceptions in one place so I placed them here.

class NegativeMileageException : public std::exception
{
public:
	NegativeMileageException();
	NegativeMileageException(const char* incomingMessage);
	NegativeMileageException(const char* incomingMessage, int lineNumber);
	NegativeMileageException(const std::exception &incomingInner);
};

class YearBefore1970Exception : public std::exception
{
public:
	YearBefore1970Exception();
	YearBefore1970Exception(const char* incomingMessage);
	YearBefore1970Exception(const char* incomingMessage, int lineNumber);
	YearBefore1970Exception(const std::exception &incomingInner);
};

class InvalidMakeException : public std::exception
{
public:
	InvalidMakeException();
	InvalidMakeException(const char* incomingMessage);
	InvalidMakeException(const char* incomingMessage, int lineNumber);
	InvalidMakeException(const std::exception &incomingInner);
};

class YearAfter2019Exception : public std::exception
{
public:
	YearAfter2019Exception();
	YearAfter2019Exception(const char* incomingMessage);
	YearAfter2019Exception(const char* incomingMessage, int lineNumber);
	YearAfter2019Exception(const std::exception &incomingInner);
};

class InvalidVINException : public std::exception
{
public:
	InvalidVINException();
	InvalidVINException(const char* incomingMessage);
	InvalidVINException(const char* incomingMessage, int lineNumber);
	InvalidVINException(const std::exception &incomingInner);
};