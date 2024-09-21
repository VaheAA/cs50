#include <cs50.h>
#include <stdio.h>

const int ARRAY_SIZE = 3;


float average(int length, int array[]);
int main(void)
{
    int scores[ARRAY_SIZE];

    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        scores[i] = get_int("Your Score: ");
    }


    printf("Average score %f\n", (scores[0] + scores[1] + scores[2]) / average(ARRAY_SIZE, scores));
}


float average(int length, int array[])
{
    int sum = 0;

    for (int i = 0; i < length; i++)
    {
        sum += array[i];
    }

    return sum / (float) length;
}
