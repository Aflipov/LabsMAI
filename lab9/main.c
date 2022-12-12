#include <stdio.h>
#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))

double abs(double a) {
    if (a >= 0) return a;
    else return -a;
}

double fmod(double a, double b) {
    return a - (int)(a/b) * b;
}

double pow2(double x) {
    return x * x;
}

int sgn(double a) {
    if (a == 0){
        return 0;
    } else {
        return a / abs(a);
    }
}

int check(double i, double j) {
    if (pow2(i - 20) / 100 + pow2(j - 0) / 25 <= 1) return 1;
    else return 0;
}

void output (double i, double j, int k) {
    if (check(i, j)) {
        printf("k = %d: i = %f, j = %f:   HIT\n", k,  i, j);
    } else {
        printf("k = %d: i = %f, j = %f:   MISS\n", k, i, j);
    }
}


int main() {
    double i = -24, j = 4, l = -3, ik = 0, jk = 0, lk = 0;
    for (int k = 1; k < 51; k++) {
        ik = i, jk = j, lk = l;
        i = fmod(abs((ik + k) * (jk + 2 * k) * (lk + 3 * k)), 35);
        j = sgn(max(ik, jk)) * min(fmod((ik + k), 20.0), fmod((jk + lk), 20.0));
        l = jk / 3 - abs(jk - k) * sgn(lk - jk);
        output(i, j, k);
    }
    return 0;
}