#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    printf("Vvedit rozmir masyvu N: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Pomylka: nekorektnyi rozmir masyvu.\n");
        return 1;
    }

    float *arr = (float *)malloc((size_t)n * sizeof(float));
    if (arr == NULL) {
        printf("KRYTYCHNA POMYLKA: defitsyt RAM (malloc povernuv NULL)!\n");
        return 1;
    }

    printf("Vvedit %d diysnykh chysel:\n", n);
    for (int i = 0; i < n; i++) {
        printf("  arr[%d] = ", i);
        if (scanf("%f", &arr[i]) != 1) {
            printf("Pomylka vvodu danykh.\n");
            free(arr);
            arr = NULL;
            return 1;
        }
    }

    float min_val = arr[0];
    float max_val = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min_val) {
            min_val = arr[i];
        }
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }

    printf("\nMaksymalnyi element: %.2f\n", max_val);
    printf("Minimalnyi element:  %.2f\n", min_val);
    printf("Riznytsya (max - min): %.2f\n", max_val - min_val);

    free(arr);
    arr = NULL;

    return 0;
}
