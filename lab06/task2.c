#include <stdio.h>
#include <stdlib.h>

int main(void) {
    size_t capacity = 3;
    size_t count = 0;

    int *buffer = (int *)malloc(capacity * sizeof(int));
    if (buffer == NULL) {
        printf("Pomylka vydilennya pochatkovoho bufera!\n");
        return 1;
    }

    printf("Vvodte tsili chysla (zupynka: chyslo, shcho dilytsya na 10, napryklad 20):\n");
    while (1) {
        int val;
        printf("  Chyslo #%zu: ", count + 1);
        if (scanf("%d", &val) != 1) {
            printf("Pomylka vvodu.\n");
            break;
        }

        if (val % 10 == 0) {
            printf("Vyyavleno terminalne chyslo (%d). Zupynka vvodu.\n", val);
            break;
        }

        if (count == capacity) {
            size_t new_capacity = capacity * 2;
            int *temp = (int *)realloc(buffer, new_capacity * sizeof(int));
            if (temp == NULL) {
                printf("KRYTYCHNA POMYLKA: realloc povernuv NULL! Zvilnyayemo staryi bufer.\n");
                free(buffer);
                buffer = NULL;
                return 1;
            }
            buffer = temp;
            capacity = new_capacity;
            printf("  [INFO] Bufer rozshyreno do %zu elementiv.\n", capacity);
        }

        buffer[count++] = val;
    }

    printf("\nNakopycheno elementiv: %zu (finalna mistkist: %zu)\n", count, capacity);
    printf("Vmist bufera: ");
    for (size_t i = 0; i < count; i++) {
        printf("%d ", buffer[i]);
    }
    printf("\n");

    free(buffer);
    buffer = NULL;

    return 0;
}