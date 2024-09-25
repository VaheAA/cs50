#include <cs50.h>
#include <stdio.h>

int collatz(int n);
int main(void)
{

    printf("Steps %i\n: ", collatz(4));
    printf("Steps %i\n: ", collatz(44));
}

int collatz(int n)
{
    if (n == 1)
    {
        return 0;
    }
    if (n % 2 == 0)
    {
        return 1 + collatz(n /2);
    }
    else {
        return 1 + collatz((n * 3) + 1);
    }

}
