#include <stdio.h>
#include <string.h>

const int BOARD_SIZE = 8;
const int TAKEN_SIZE = 4;
const int taken[4][2] = {
    {2, 3}, {5, 2}, {1, 5}, {3, 6}
};

void decToBin(int n, char *str)
{
    if (n > 0) {
        decToBin(n / 2, str);
        char* ch = n % 2 == 0 ? "0" : "1";
        strcat(str, ch);
    }
}

int powNum(int n, int prev)
{
    if (prev > 0) {
        return n * powNum(n, prev - 1);
    }
    return 1;
}

int powNumImproved(int n, int prev) {
    if (prev > 0) {
        return prev % 2 == 0 
    	   ? powNumImproved(n * n, prev / 2)
    	   : n * powNumImproved(n, prev - 1);
    }
    return 1;
}

int isFree(int x, int y)
{
    int fieldFree = 1;
    for (int i = 0; i < TAKEN_SIZE; ++i) {
        if (taken[i][0] == x && taken[i][1] == y) {
            fieldFree = 0;
            break;
        }
    }
    return fieldFree;
}

int routes(int x, int y)
{
    if ((x == 0 && y == 0) || isFree(x, y) == 0) {
        return 0;
    } else if ((x == 0 && y != 0) || (y == 0 && x != 0)) {
        return 1;
    } else {
        return routes(x, y - 1) + routes(x - 1, y);
    }
}

int main(int argc, const char** argv)
{
    char binStr[] = "";
    decToBin(165, binStr);
    printf("%s\n", binStr);

    printf("%d \n", powNum(8, 4));

    printf("%d \n", powNumImproved(8, 4));

    for (int y = 0; y < BOARD_SIZE; ++y) {
        for (int x = 0; x < BOARD_SIZE; ++x) {
            printf("%5d", routes(x, y));
        }
        printf("\n");
    }

    return 0;
}
