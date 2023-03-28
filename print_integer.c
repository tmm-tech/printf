#include main.h
/**
 * print_int - Prints an integer
 * @args: A va_list containing the integer to print
 * @buffer: The buffer where the output is being stored
 * @flags: A struct containing information on the flags
 * @width: The field width
 * @precision: The precision
 *
 * Return: The number of characters printed
 */
int print_int(va_list args, char *buffer, flags_t flags,
                 int width, int precision)
{
        long int n = get_integer_argument(args, flags);
        int is_negative = n < 0;
        unsigned long int num = (is_negative) ? -n : n;
        char sign = (is_negative) ? '-' : '+';
        char *prefix = (is_negative) ? "-" : "+";
        int prefix_len = (is_negative) ? 1 : 1;
        char *str = NULL;
        int len = 0;

        if (flags.precision == 0 && n == 0)
                return (apply_width(buffer, ' ', width));

        str = ulltoa_base(num, 10, is_negative, 0);
        if (str == NULL)
                return (-1);
        len = strlen(str);

        if (is_negative || flags.space || flags.plus)
                width--;

        if (precision > len - prefix_len)
                prefix_len = 0;
        else
                precision = len - prefix_len;

        width -= prefix_len + precision;

        if (!flags.minus && !flags.zero)
                apply_width(buffer, ' ', width);

        if (is_negative || flags.space || flags.plus)
                apply_buffer(buffer, sign);

        apply_buffer(buffer, prefix, prefix_len);

        if (flags.zero)
                apply_width(buffer, '0', width);
        else
                apply_width(buffer, ' ', width);

        apply_precision(buffer, '0', precision);
        apply_buffer(buffer, str, len);

        if (flags.minus)
                apply_width(buffer, ' ', width);

        free(str);
        return (width + prefix_len + precision + len);
}
