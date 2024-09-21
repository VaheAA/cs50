#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

bool validate_key(string key);
void cipher(string plain_text, string key);

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage: ./substitution KEY\n");
        return 1;
    }
    if (argc > 2)
    {
        printf("Invalid number of arguments\n");
        return 1;
    }

    if (strlen(argv[1]) < 26 || strlen(argv[1]) > 26)
    {
        printf("Key length must be 26 characters long\n");
        return 1;
    }

    bool is_valid = validate_key(argv[1]);

    if (!is_valid)
    {
        printf("Invalid key\n");
        return 1;
    }

    string plain_text = get_string("Plain text: ");
    cipher(plain_text, argv[1]);

    return 0;
}

bool validate_key(string key)
{
    bool is_valid = true;
    int char_count[256] = {0};

    for (int i = 0, length = strlen(key); i < length; i++)
    {
        if (!isalpha(key[i]))
        {
            is_valid = false;
            break;
        }

        char_count[(unsigned char) key[i]]++;

        if (char_count[(unsigned char) key[i]] > 1)
        {
            is_valid = false;
            break;
        }
    }

    return is_valid;
}

void cipher(string plain_text, string key)
{
    printf("ciphertext: ");

    for (int i = 0, len = strlen(plain_text); i < len; i++)
    {
        char current_char = plain_text[i];

        if (isupper(current_char))
        {
            char cipher_char = toupper(key[current_char - 'A']);
            printf("%c", cipher_char);
        }
        else if (islower(current_char))
        {
            char cipher_char = tolower(key[current_char - 'a']);
            printf("%c", cipher_char);
        }
        else
        {
            printf("%c", current_char);
        }
    }

    printf("\n");
}
