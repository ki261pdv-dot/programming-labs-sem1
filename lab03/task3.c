#include <stdio.h>

#define MAX_LEN 255

int main(void) {
    char str[MAX_LEN + 1];

    printf("Введіть рядок латиницею: ");
    if (fgets(str, sizeof(str), stdin) == NULL) {
        return 1;
    }

    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == '\n') {
            str[i] = '\0';
            break;
        }
        i++;
    }

    i = 0;
    while (str[i] != '\0') {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - ('a' - 'A');
        }
        i++;
    }

    printf("Результат: %s\n", str);

    return 0;
}