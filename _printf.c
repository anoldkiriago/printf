#include <unistd.h>
#include "main.h"
#include <stdarg.h>

typedef void (*conversion_handler)(int, va_list *);

void output_char(int file_descriptor, va_list *args)
{
    char c = va_arg(*args, int);
    write(file_descriptor, &c, 1);
}

void output_string(int file_descriptor, va_list *args)
{
    char *str = va_arg(*args, char*);
    while (*str != '\0') {
        write(file_descriptor, str, 1);
        str++;
    }
}

void output_percent(int file_descriptor, va_list *args)
{
    char c = '%';
    write(file_descriptor, &c, 1);
}

int _printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);
    
    int count = 0;
    
    conversion_handler handlers[256] = { NULL };    
    handlers['c'] = output_char;
    handlers['s'] = output_string;
    handlers['%'] = output_percent;
    
    const char *current_character = format;
    
    while (*current_character != '\0')
    {
        if (*current_character == '%')
	{
            current_character++;
            if (handlers[(unsigned char)(*current_character)])
	    {
                handlers[(unsigned char)(*current_character)](STDOUT_FILENO, &args);
                count++;
	    }
	    else
	    {
                char c = '%';
                write(STDOUT_FILENO, &c, 1);
            }
        }
	else
	{
            write(STDOUT_FILENO, current_character, 1);
            count++;
        }
        
        current_character++;
    }
    
    va_end(args);
    
    return count;
}

int main()
{
    char format[] = "Hello, %s! This is a %c project with faruq. The estimate value of %% is %d.";
    _printf(format, "Arnold", 'C', 400);
    return 0;
}
