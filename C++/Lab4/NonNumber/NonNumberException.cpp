#include "NonNumberException.h"

const char* NonNumberException::what() const throw ()
{
	return message.c_str();
}

