#include "main.h"

/**
 * rot13 - Encodes a string using rot13.
 * @s: The string to encode.
 *
 * Return: The encoded string.
 */
char *rot13(char *s)
{
    char *str = s;
    int i;

    while (*str)
    {
        for (i = 0; (*str >= 'a' && *str <= 'm') ||
                    (*str >= 'A' && *str <= 'M'); i++)
            *str += 13;
        for (i = 0; (*str >= 'n' && *str <= 'z') ||
                    (*str >= 'N' && *str <= 'Z'); i++)
            *str -= 13;
        str++;
    }

    return (s);
}

/**
 * print_rot13string - Prints a string in rot13.
 * @types: A va_list of the arguments to print.
 * @buffer: A buffer to store the printed string.
 * @flags: Flags for the string format.
 * @width: Minimum width of the printed string.
 * @precision: Maximum number of characters to print.
 * @size: The size of the string.
 *
 * Return: The number of bytes printed.
 */
int print_rot13string(va_list types, char buffer[],
                      int flags, int width, int precision, int size)
{
    char *str = va_arg(types, char *);
    int len = 0;

    UNUSED(flags);
    UNUSED(width);
    UNUSED(precision);
    UNUSED(size);

    if (str == NULL)
        str = "(null)";

    str = rot13(str);

    while (*str)
    {
        if (len >= BUFF_SIZE)
        {
            write(1, buffer, len);
            len = 0;
        }
        buffer[len] = *str;
        len++;
        str++;
    }

    return (len);
}

/**
 * fmt_arr - Array of struct fmt.
 *
 * @fmt: The format.
 * @fn: The function associated.
 */
fmt_t fmt_arr[] = {
    {'c', print_char},
    {'s', print_string},
    {'%', print_percent},
    {'d', print_int},
    {'i', print_int},
    {'b', print_binary},
    {'u', print_unsigned},
    {'o', print_octal},
    {'x', print_hexadecimal},
    {'X', print_hexa_upper},
    {'p', print_pointer},
    {'r', print_reverse},
    {'R', print_rot13string},
    {'\0', NULL},
};
