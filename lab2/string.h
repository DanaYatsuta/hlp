#ifndef STRING_H_INCLUDED
#define STRING_H_INCLUDED

class String
{
private:
    char* string_begin;
    int length;

public:
    String();
    String(char*);
    String(const String&);
    ~String();

    String& operator=(String& other);
};

#endif // STRING_H_INCLUDED
