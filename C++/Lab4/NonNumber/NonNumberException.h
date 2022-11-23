#pragma once

#include <exception>
#include <string>

class NonNumberException : public std::exception
{
private:
	std::string message;
public:
	NonNumberException() : message("INVALID INPUT: non-integer detected") {}
	NonNumberException(std::string str) : message("INVALID INPUT: non-integer detected" + str) {}
	virtual const char* what() const throw();
};

