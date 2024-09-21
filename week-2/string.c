#include <cs50.h>
#include <stdio.h>
#include <string.h>


int main(void)
{
    string str = get_string("Input: ");
    int length = strlen(str);
    printf("Output: ");

    for (int i = 0, n = strlen(str); i < n; i++)
    {
        printf("%c", str[i]);
    }
    printf("\n");
}
