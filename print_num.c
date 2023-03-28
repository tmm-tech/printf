#include main.h
/**
 * print_int- prints an integer
 * @l: va_list of arguments from _printf
 * @f: pointer to the struct flags determining
 * if a flag is passed to _printf
 * Return: number of char printed
 */
void print_int(va_list args, int is_unsigned, int width, int precision, int zero_pad, int left_align) {
    int num = get_int_arg(args);
    print_num(num, 10, is_unsigned, width, precision, zero_pad, left_align);
}

void print_num(int num, int base, int is_unsigned, int width, int precision, int zero_pad, int left_align) {
    char buffer[32]; // max number of digits for 64-bit int in binary
    char* prefix = "";
    char* digits = "0123456789ABCDEF";
    int num_digits = 0;
    int is_negative = 0;
    int i;

    // handle negative numbers
    if (!is_unsigned && num < 0) {
        is_negative = 1;
        num = -num;
    }

    // handle special case of 0
    if (num == 0) {
        buffer[num_digits++] = '0';
    }
    else {
        // convert number to requested base
        while (num != 0) {
            buffer[num_digits++] = digits[num % base];
            num /= base;
        }
    }

    // handle prefix for hex and octal formats
    if (base == 16) {
        prefix = "0x";
    }
    else if (base == 8) {
        prefix = "0";
    }

    // handle precision
    if (precision > num_digits) {
        precision -= num_digits;
    }
    else {
        precision = 0;
    }

    // handle width
    if (width > num_digits + precision + is_negative + strlen(prefix)) {
        width -= num_digits + precision + is_negative + strlen(prefix);
    }
    else {
        width = 0;
    }

    // print prefix for hex and octal formats
    if (strlen(prefix) > 0) {
        complete(prefix);
    }

    // print negative sign if necessary
    if (is_negative) {
        complete("-");
    }

    // print leading zero padding or spaces
    if (zero_pad) {
        // zero padding
        for (i = 0; i < width; i++) {
            complete("0");
        }
    }
    else if (left_align) {
        // left align
        for (i = 0; i < num_digits; i++) {
            complete(&buffer[num_digits - i - 1]);
        }
        for (i = 0; i < precision; i++) {
            complete("0");
        }
        for (i = 0; i < width; i++) {
            complete(" ");
        }
    }
    else {
        // right align
        for (i = 0; i < width; i++) {
            complete(" ");
        }
        for (i = 0; i < precision; i++) {
            complete("0");
        }
        for (i = 0; i < num_digits; i++) {
            complete(&buffer[num_digits - i - 1]);
        }
    }
}
