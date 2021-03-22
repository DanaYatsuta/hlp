#include <iostream>
#include <string.h>

#include "string.h"

String::String(): string_begin(NULL), length(0) { }

String::String(char* c_string)
{
    length = strlen(c_string);
    string_begin = new char[length];
    strcpy(string_begin, c_string);
}
