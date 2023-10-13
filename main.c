#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

void *print_rev_number(int number)
{
    int digit;
    if (number == 0)
    {
        return (NULL);
    }
    digit = number % 10;
    print_rev_number(number / 10);
    putchar(digit + '0');
    return (NULL);
}
void *_printf(const char *const string, ...)
{
    int number;
    /* char character; */
    /* char *str;*/
    va_list arg;
    int i = 0;
    int int_flag = 0;
    /* 0 for No Flags, 1 for % flag, 2 for BackSlash (\) */
    int flag_detected = 0;

    va_start(arg, string);
    while (string[i] != '\0')
    {
        /*Detect Format Flag*/
        if (string[i] == '%')
        {
            flag_detected = 1;
            i++;
            continue;
        }
        /* Detect Format Specifier*/
        if (flag_detected == 1)
        {
            switch (string[i])
            {
                case 'd':
                    int_flag = 1;
                    break;
            }
        }
        /*Detected int*/
        if (int_flag == 1)
        {
            number = va_arg(arg, int);
            /*Funtion to print an argument that was just gotten using va_arg*/
            /* putchar(number + '0');*/
            print_rev_number(number);
            i++;
            /* Reset Flags After Printing*/
            flag_detected = 0;
            int_flag = 0;
            continue;
        }
        if (flag_detected == 0)
        {
            putchar(string[i]);
            i++;
            continue;
        }
    }
    putchar('\n');
    va_end(arg);
    return (NULL);
}
int main()
{
    _printf("Hello %d", 52345);
    return (0);
}