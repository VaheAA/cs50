#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int size = get_int("Enter a size: ");
    int sequence[size];
    sequence[0] = 1;

    for (int i = 1; i < size; i++)
    {
        sequence[i] = sequence[i - 1] * 2;
    }
}