#include <stdio.h>
#include <stddef.h>

double sum_above_average(const double *start_ptr, size_t count);

int main(void) {
    double buffer[] = {12.5, 4.0, 18.0, 7.5, 22.0, 8.0};
    size_t n = sizeof(buffer) / sizeof(*buffer);

    printf("Elementy masyvu:\n");
    const double *iter = buffer;
    const double *end_ptr = buffer + n;

    while (iter < end_ptr) {
        ptrdiff_t idx = iter - buffer;
        printf("  [offset %td] = %.2f\n", idx, *iter);
        iter++;
    }

    double result = sum_above_average(buffer, n);
    printf("\nSuma elementiv, bilshykh za serednye aryfmetychne: %.2f\n", result);

    return 0;
}

double sum_above_average(const double *start_ptr, size_t count) {
    if (start_ptr == NULL || count == 0) {
        return 0.0;
    }

    double total_sum = 0.0;
    for (size_t i = 0; i < count; i++) {
        total_sum += *(start_ptr + i);
    }

    double average = total_sum / (double)count;
    printf("\nSerednye aryfmetychne: %.2f\n", average);

    double above_sum = 0.0;
    for (size_t i = 0; i < count; i++) {
        double current_val = *(start_ptr + i);
        if (current_val > average) {
            above_sum += current_val;
        }
    }

    return above_sum;
}
