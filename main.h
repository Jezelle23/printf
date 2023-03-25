#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int _printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);

    int num_chars_printed = 0;
    while (*format != '\0') {
        if (*format == '%') {
            format++;
            if (*format == '\0') {
                break;
            }
            if (*format == '%') {
                putchar('%');
                num_chars_printed++;
            } else if (*format == 'c') {
                char c = va_arg(args, int);
                putchar(c);
                num_chars_printed++;
            } else if (*format == 's') {
                char *str = va_arg(args, char *);
                while (*str != '\0') {
                    putchar(*str);
                    str++;
                    num_chars_printed++;
                }
            }
        } else {
            putchar(*format);
            num_chars_printed++;
        }
        format++;
    }

    va_end(args);

    return num_chars_printed;
}
