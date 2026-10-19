#include <stdio.h>
#include <stdlib.h>

int main(void) {
    size_t n = 8 * 1000 * 1000;          // 8 млн
    char *arr = malloc(n * sizeof *arr); // sizeof *arr == 1
    if (!arr) {                          // проверка обязательна
        perror("malloc");
        return 1;
    }

    // пример использования: заполнить и посчитать
    for (size_t i = 0; i < n; i++) arr[i] = (char)(i & 0x7F);
    printf("arr[123] = %d\n", arr[123]);

    free(arr);
    arr = NULL;
    return 0;
}