#include <stdio.h>
#include <stdarg.h>

int print_char(va_list args) {
    int c = va_arg(args, int);
    return putchar(c);
}

int print_string(va_list args) {
    char *s = va_arg(args, char*);
    return printf("%s", s);
}

int print_percent(va_list args) {
    return putchar('%');
}

int print_integer(va_list args) {
    int n = va_arg(args, int);
    return printf("%d", n);
}

int print_binary(va_list args) {
    int n = va_arg(args, int);
    return printf("%b", n);
}

int print_reversed(va_list args) {
    char *s = va_arg(args, char*);
    int len = strlen(s);
    for(int i = len-1; i >= 0; i--) {
        putchar(s[i]);
    }
    return len;
}

int rot13(char *s) {
    int len = strlen(s);
    for(int i = 0; i < len; i++) {
        char c = s[i];
        if (c >= 'a' && c <= 'm') {
            c += 13;
        } else if (c >= 'A' && c <= 'M') {
            c += 13;
        } else if (c >= 'n' && c <= 'z') {
            c -= 13;
        } else if (c >= 'N' && c <= 'Z') {
            c -= 13;
        }
        putchar(c);
    }
    return len;
}

int unsigned_integer(va_list args) {
    unsigned int n = va_arg(args, unsigned int);
    return printf("%u", n);
}

int print_octal(va_list args) {
    int n = va_arg(args, int);
    return printf("%o", n);
}

int print_hex(va_list args) {
    int n = va_arg(args, int);
    return printf("%x", n);
}

int print_heX(va_list args) {
    int n = va_arg(args, int);
    return printf("%X", n);
}

int main() {
    printf("%c\n", 'a');
    printf("%s\n", "hello");
    printf("%%\n");
    printf("%d\n", 42);
    printf("%b\n", 42);
    printf("%s\n", "hello");
    printf("%s\n", "hello");
    printf("%u\n", 42);
    printf("%o\n", 42);
    printf("%x\n", 42);
    printf("%X\n", 42);
    return 0;
}
