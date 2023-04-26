#include <stdio.h>
#include <inttypes.h>

int main() {

    int64_t size = 4;
    int64_t matrix[4][4] = {
            {1, 2, 3, 4},
            {5, 6, 7, 8},
            {9, 10, 11, 12},
            {13, 14, 15, 16}
    };

//    int64_t matrix[3][3] = {
//            {1, 2, 3},
//            {4, 5, 6},
//            {7, 8, 9}
//    };

    int imax = 0, jmax = 0; // Присвоение значения первого элемента массива
    int imin = 0, jmin = 0;


    for (int i = 0; i < size; i++) // Переключение по строкам
    {
        for (int j = 0; j < size; j++)// Переключение по столбцам
        {
            if (matrix[i][j] > matrix[imax][jmax] ) // Ищем максимальное значение
            {
                imax = i;
                jmax = j;
            };
            if (matrix[i][j] < matrix[imin][jmin] ) // Ищем минимальное значение
            {
                imin = i;
                jmin = j;
            };
        }
    }


    int res = 0;
    for (int i = 0; i < size; ++i) {
        res += matrix[imin][i] * matrix[i][jmax];
    }

    printf("%d", res);

    return 0;
}