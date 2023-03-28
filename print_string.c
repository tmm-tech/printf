#include main.h
/**
 * print_string - Prints a string
 * @args: A va_list containing the string to print
 * @opts: A printf_options struct containing the options for the string
 *
 * Return: The number of characters printed
 */
int print_string(va_list args, printf_options opts)
{
	char *str = va_arg(args, char *);
	int len, printed = 0;

	if (str == NULL)
		str = "(null)";

	len = _strlen(str);
	if (opts.width > 0 && len < opts.width && !opts.left_align)
		printed += print_padding(' ', opts.width - len);
	printed += _puts(str);
	if (opts.width > 0 && len < opts.width && opts.left_align)
		printed += print_padding(' ', opts.width - len);

	return (printed);
}
