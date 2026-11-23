#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    const char *sample_words[] = {
        "Microcontroller",
        "Pointer",
        "DynamicHeap",
        "Sanitizer"
    };
    size_t n = sizeof(sample_words) / sizeof(sample_words[0]);

    char **words = (char **)malloc(n * sizeof(char *));
    if (words == NULL) {
        printf("Pomylka vydilennya masyvu pokazhchykiv!\n");
        return 1;
    }

    for (size_t i = 0; i < n; i++) {
        size_t len = strlen(sample_words[i]) + 1;
        words[i] = (char *)malloc(len * sizeof(char));
        if (words[i] == NULL) {
            printf("Pomylka vydilennya pam'yati pid slovo #%zu!\n", i);
            for (size_t j = 0; j < i; j++) {
                free(words[j]);
                words[j] = NULL;
            }
            free(words);
            words = NULL;
            return 1;
        }
        strcpy(words[i], sample_words[i]);
    }

    printf("Dynamichnyi masyv sliv u kupi:\n");
    for (size_t i = 0; i < n; i++) {
        printf("  [%zu] %s (dovzhyna: %zu)\n", i, words[i], strlen(words[i]));
    }

    for (size_t i = 0; i < n; i++) {
        free(words[i]);
        words[i] = NULL;
    }
    free(words);
    words = NULL;

    printf("\nUsyu pam'yat uspishno zvilneno.\n");
    return 0;
}