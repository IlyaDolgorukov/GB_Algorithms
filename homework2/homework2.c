#include <stdio.h>
#include <math.h>

int isSimple(int n) {
    int last = (int) sqrt(n);
    for (int i = 1; i < last; ++i) {
        if (n % i == 0) {

            return 0;
        }
    }

    return 1;
}

void main(int argc, const char** argv)
{
    int number = 5;
    int is_simple = isSimple(number);
    printf("Number %d is%s simple", number, (is_simple) ? "" : " not");
}
