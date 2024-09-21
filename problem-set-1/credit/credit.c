#include <cs50.h>
#include <stdio.h>
#include <string.h>

bool luhn_algorithm(string card_number);
void get_card_type(string card_number);

int main(void)
{
    string card_number = get_string("Number: ");

    bool is_valid_card = luhn_algorithm(card_number);

    if (is_valid_card)
    {
        get_card_type(card_number);
    }
    else
    {
        printf("INVALID\n");
    }
}

bool luhn_algorithm(string card_number)
{
    int sum = 0;
    int length = strlen(card_number);

    for (int i = length - 1, is_second = 0; i >= 0; i--, is_second = !is_second)
    {
        int digit = card_number[i] - '0';

        if (is_second)
        {
            digit *= 2;

            if (digit > 9)
            {
                digit -= 9;
            }
        }
        sum += digit;
    }

    return (sum % 10 == 0);
}

void get_card_type(string card_number)
{
    int length = strlen(card_number);
    char first_char = card_number[0];
    char second_char = card_number[1];

    if (length == 15 && first_char == '3' && (second_char == '4' || second_char == '7'))
    {
        printf("AMEX\n");
    }
    else if (length == 16 && first_char == '5' &&
             (second_char == '1' || second_char == '2' || second_char == '3' ||
              second_char == '4' || second_char == '5'))
    {
        printf("MASTERCARD\n");
    }
    else if ((length == 13 || length == 16) && first_char == '4')
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
