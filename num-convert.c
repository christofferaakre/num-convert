#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

// This program takes a number in binary,
// hex or decimal format and prints it back to you
// in all of those formats, so it's quite useful for
// quickly converting back and forth.

void print_usage();
void int_to_binary_string(int number, char* buffer);
void print_binary_string(char* buffer, int buffer_size);
char get_format(char* input);
int format_number(char* input, char format);

int main(int argc, char* args[])
{
    if (argc != 2)
    {
        print_usage();
        return 1;
    }

    char* input = args[1];
    char format = get_format(input);
    if (format == '\0')
    {
        printf("Please enter an integer in hex, binary, or decimal, for example:\n");
        printf("0x033f2\n");
        printf("1001001b\n");
        printf("1432\n");
        printf("Exiting..\n");
        return 2;
    };

    int number = format_number(input, format);
    int buffer_size = sizeof(int) * 8 + 1;
    char buffer[buffer_size];
    int_to_binary_string(number, buffer);

    printf("Printing %s with format %c\n", input, format);
    printf("Decimal: %d\n", number);
    printf("Hex: %x\n", number);
    printf("Binary: ");
    print_binary_string(buffer, buffer_size);

}

int format_number(char* input, char format)
{
    int number_from_hex;
    sscanf(input, "%x", &number_from_hex);
    switch (format)
    {
        case 'd':
            return atoi(input);
        case 'b':
            return (int) strtol(input, NULL, 2);
        case 'x':
            return number_from_hex;
        default:
            return 0;
    }
}

char get_format(char* input)
{
    char c;
    int i = 0;

    // checking for hex format
    if (input[0] == '0' && (input[1] == 'x' || input[1] == 'X'))
    {
        return 'x';
    }

    // checking for binary format
    char last = input[strlen(input) - 1];
    if (last == 'b' || last == 'B')
    {
        return 'b';
    }

    // checking for decimal format
    bool decimal = true;
    while(true)
    {
        c = input[i];
        if (c == '\0') break;
        if (!isdigit(c))
        {
            decimal = false;
            break;
        }
        i++;
    }

    if (decimal) return 'd';

    // return 0 character if no format
    // was found
    return '\0';

}

void print_binary_string(char* buffer, int buffer_size)
{
    bool padding = true;
    for (int i = 0; i < buffer_size; i++)
    {
        if (padding && buffer[i] == '1')
        {
            padding = false;
        }

        if (!padding)
        {
            printf("%c", buffer[i]);
        }
    }
    printf("\n");
}

void int_to_binary_string(int number, char* buffer)
{
    size_t buffer_size = sizeof(int) * 8;
    for (int i = 0; i < buffer_size; i++)
    {
        bool bit = (number & (1 << i)) == 0 ? 0 : 1;
        buffer[buffer_size - i - 1] = bit ? '1' : '0';
    }

    buffer[buffer_size] = '\0';
}

void print_usage()
{
    printf("Usage: num-convert [number]\n");
    printf("Example: num-convert 1024\n");
    printf("Example: num-convert 100101b\n");
    printf("Example: num-convert 0x0042f\n");
    printf("Exiting..\n");
}
