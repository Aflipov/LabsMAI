#include<stdio.h>
#include<math.h>
int cycle(int x) {
    int a, degree = 0, result = 0;
    do
    {
        a = x % 10;
        x /= 10;
        if (a % 2 != 0)
        {
            result += pow(10, degree) * a;
            degree++;
        }
    }
    while (x>0);

    return result;
}

int main() {
    int x, m;
    scanf("%d", &x);
    printf("%d", cycle(x));
    return 0;
}