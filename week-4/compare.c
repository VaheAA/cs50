#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    char *s = get_string("i: ");
    char *t = get_string("j: ");

    printf("%p\n", s);
    printf("%p\n", t);
}
