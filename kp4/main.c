#include <stdio.h>
#include <float.h>
#include <math.h>

long double f9(long double x) {
    return sqrtl(logl(1 + x) + 3);           // x^2 - logl(1 + x) - 3 = 0
}

long double f9_der(long double x) {
    return 1 / (2 * (1 + x) * sqrtl(logl(1 + x) + 3));
}

int IsIterationConvergent(
        long double (*der)(long double),
        long double a,
        long double b) {
    int res = 1;
    long double step = (b - a) / 100;
    for (long double x = a; x <= b; x += step) {
        if (der(x) >= 1) {
            res = 0;
        }
    }
    return res;
}

long double IterationsMethod(
        long double (*f)(long double),
        long double a,
        long double b) {
    long double x0 = (a + b) / 2;
    long double x1 = f(x0);
    while (fabsl(x1 - x0) >= LDBL_EPSILON) {
        x0 = x1;
        x1 = f(x0);
    }
    return x1;
}


long double f10(long double x) {
    return 2 * x * sinl(x) - cosl(x);                    // 2 * x * sinl(x) - cosl(x) = 0
}

long double f10_der1(long double x) {
    return 2 * x * cosl(x) + 3 * sinl(x);
}

long double f10_der2(long double x) {
    return 5 * cosl(x) - 2 * x * sinl(x);
}

int IsNewtonConvergent(
        long double (*f)(long double),
        long double (*der1)(long double),
        long double (*der2)(long double),
        long double a,
        long double b) {
    int res = 1;
    long double step = (b - a) / 100;
    for (long double x = a; x <= b; x += step) {
        if (fabsl(f(x) * der2(x)) >= powl(der1(x), 2)) {
            res = 0;
        }
    }
    return res;
}

long double NewtonMethod(
        long double (*f)(long double),
        long double (*der)(long double),
        long double a,
        long double b) {
    long double x0 = (a + b) / 2;
    long double x1 = x0 - f(x0) / der(x0);
    while (fabsl(x1 - x0) >= LDBL_EPSILON) {
        x0 = x1;
        x1 = x0 - f(x0) / der(x0);
    }
    return x1;
}



int main() {
    long double a = 2, b = 3;
    printf("Function 9 (Iterations Method):\n\t\tx^2 - logl(1 + x) - 3 = 0\n");
    if (IsIterationConvergent(f9_der, a, b)) {
        printf("Convergence check:\tOK!\n");

        long double root = IterationsMethod(f9, a, b);
        printf("Approximated root:\t%.10Lf\n", root);

        long double result = root * root - logl(1 + root) - 3;
        printf("Result of inserting root:\t%.10Lf\n\n", result);
    } else {
        printf("Convergence check:\t FAIL!\n\n");
    }


    a = 0.4;
    b = 1;
    printf("Function 10 (Newton Method):\n\t\t2 * x * sinl(x) - cosl(x) = 0\n");
    if (IsNewtonConvergent(f10, f10_der1, f10_der2, a, b)) {
        printf("Convergence check:\tOK!\n");

        long double root = NewtonMethod(f10, f10_der1, a, b);
        printf("Approximated root:\t%.10Lf\n", root);

        long double result = f10(root);
        printf("Result of inserting root:\t%.10Lf\n", result);
    } else {
        printf("Convergence check:\t FAIL!\n\n");
    }
}
