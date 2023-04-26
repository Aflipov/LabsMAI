#include <stdio.h>
#include <inttypes.h>

int main() {
    // 1  2  9  10
    // 4  3  8  11  ----\  1 2 3 4 5 6 7 8 9 10 11 12 13 14
    // 5  6  7  12  ----/
    // 16 15 14 13

    char isEven = 1;

    int64_t size = 4;

    int64_t matrix[4][4] = {
            {1, 2, 9, 10},
            {4, 3,  8,  11},
            {5, 6,  7,  12},
            {16, 15,  14,  13}
    };

    /*int64_t size = 3;
    int64_t matrix[3][3] = {
            {1, 2, 9},
            {4, 3, 8},
            {5, 6, 7},
    };*/

    int64_t i = 1;
    int64_t a = 0;
    int64_t b = 0;

    printf("%lld ", matrix[a][b]);

    while (i < size) {
        if (isEven == 1) {
            b++;
            for (int j = 0; j < i; ++j)
                printf("%lld ", matrix[a++][b]);

            for (int j = 0; j < i; ++j)
                printf("%lld ", matrix[a][--b]);

            printf("%lld ", matrix[a][b]);
            isEven = 0;
        }

        else {
            a++;
            for (int j = 0; j < i; ++j)
                printf("%lld ", matrix[a][b++]);

            for (int j = 0; j < i; ++j)
                printf("%lld ", matrix[--a][b]);

            printf("%lld ", matrix[a][b]);
            isEven = 1;
        }

        ++i;
    }

    return 0;
}