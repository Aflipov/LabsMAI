#include <stdio.h>
#include <math.h>

int to_dec(int digit_1, int digit_2, int digit_3, int digit_4, int digit_5) {
    int result = digit_1 * pow(5, 4) + digit_2 * pow(5, 3) + digit_3 * pow(5, 2) + digit_4 * pow(5, 1) + digit_5 * pow(5, 0);
    return result;
}

int main() {
    int cnt = 0;

    printf("    Number system:\nfivefold\tdecimal\n");
    for (int d1 = 3; d1 < 6; ++d1) {
        for (int d2 = 3; d2 < 6; ++d2) {
            for (int d3 = 3; d3 < 6; ++d3) {
                for (int d4 = 3; d4 < 6; ++d4) {
                    for (int d5 = 3; d5 < 6; ++d5) {
                        printf(" %d%d%d%d%d\t   =\t", d1, d2, d3, d4, d5);
                        printf(" %d\n", to_dec(d1, d2, d3, d4, d5));
                        ++cnt;
                    }
                }
            }
        }
    }
    printf("\nNumbers found: %d", cnt);
}
