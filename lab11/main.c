#include <stdio.h>
#include <assert.h>
#include <string.h>

typedef enum State {
    START,    // переводим число в десятичную си и выводим на экран
    IS_FINAL,    // проверяем на последнее число, удовлетворяющее устловию (44444)
    INCREASE,    // увеличиваем число
    STOP    // останавливаем программу
} State;

int Base5to10(int a) {
    int k = 1;
    int a10 = 0;
    while (a) {
        a10 += k * (a % 10);
        k *= 5;
        a /= 10;
    }
    return a10;
}

void Test() {
    assert(Base5to10(1234) == 194);
    assert(Base5to10(100) == 25);
    assert(Base5to10(414) == 109);
    assert(Base5to10(11211) == 806);
}

void main_function(int n) {
    int max_length = n;
    char tape[max_length];
    memset(tape, '3', max_length); // лента, на которой будет выполнятся программа
    int length;    // индекс текущей ячейки на ленте
    int is_final_flag;
    int dec_munber;

    State state = START;

    while (state != STOP) {
        switch (state) {
            case START:
                length = 0;
                int in_number = 0;
                while (length != max_length) {
                    in_number = in_number * 10 + tape[length] - '0';
                    length++;
                }
                printf("%d (base 5)", in_number);
                dec_munber = Base5to10(in_number);
                printf(" = %d (base 10)\n", dec_munber);

            case IS_FINAL:
                is_final_flag = 1;
                length = 0;
                while (length != max_length) {
                    if (tape[length] != '4') {
                        is_final_flag = 0;
                        break;
                    }
                    ++length;
                }
                if (is_final_flag == 1) {
                    state = STOP;
                    break;
                }
                state = INCREASE;

            case INCREASE:
                length = max_length;
                while (length != 0) {
                    length--;
                    if (tape[length] == '3') {
                        tape[length] = '4';
                        state = START;
                        break;
                    } else {
                        tape[length] = '3';
                    }
                }

            default:
                break;
        }
    }
    printf("\n");
}

int main() {

    Test();

    for (int i = 1; i <= 8; ++i) {
        printf("For %d length:\n", i);
        main_function(i);
    }

    return 1;
}