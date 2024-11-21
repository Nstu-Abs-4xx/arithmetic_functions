//
//  main.c
//  arifmetic
//
//  Created by Stanislav Klepikov on 01.11.2024.
//

#include <stdio.h>

// Функция для проверки, содержат ли два числа одинаковые цифры
int haveSameDigits(int num1, int num2) {
    int digits1[10] = {0};
    int digits2[10] = {0};
    int i;

    // Подсчет цифр в первом числе
    while (num1 > 0) {
        digits1[num1 % 10]++;
        num1 /= 10;
    }

    // Подсчет цифр во втором числе
    while (num2 > 0) {
        digits2[num2 % 10]++;
        num2 /= 10;
    }

    // Сравнение массивов цифр
    for (i = 0; i < 10; i++) {
        if (digits1[i] != digits2[i]) {
            return 0; // false
        }
    }
    return 1; // true
}

// Основная функция
int main(void) {
    int i, j, isValid;

    for (i = 1; i <= 1000000; i++) { // Диапазон поиска
        isValid = 1; // Предположим, что число подходит

        for (j = 2; j <= 6; j++) {
            if (!haveSameDigits(i, i * j)) {
                isValid = 0; // Если не подходит, установить в false
                break;
            }
        }

        if (isValid) {
            printf("Найдено число: %d\n", i);
            break; // Остановить после нахождения первого подходящего числа
        }
    }

    return 0;
}
