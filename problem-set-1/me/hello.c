#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt user for their name
    string name = get_string("Your name: ");

    // Print formatted string
    printf("hello, %s\n", name);
}
