#include <stdio.h>
#include <stdbool.h>

bool is_prime(int n, int *prime_total);

int main(void) {
    int count_inputs;
    int num;
    int total_primes = 0;

    printf("Skilky chysel vy khochete pereviryty? ");
    if (scanf("%d", &count_inputs) != 1 || count_inputs <= 0) {
        printf("Pomylka vvodu.\n");
        return 1;
    }

    for (int i = 0; i < count_inputs; i++) {
        printf("Vvedit tsile chyslo #%d: ", i + 1);
        if (scanf("%d", &num) != 1) {
            printf("Nekorektne znachennya.\n");
            return 1;
        }

        if (is_prime(num, &total_primes)) {
            printf("Chyslo %d ye PROSTYM. ", num);
        } else {
            printf("Chyslo %d NE ye prostym. ", num);
        }
        printf("(Vsyoho prostykh za sesiyu: %d)\n", total_primes);
    }

    return 0;
}

bool is_prime(int n, int *prime_total) {
    static int prime_counter = 0;
    bool result = true;

    if (n <= 1) {
        result = false;
    } else {
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                result = false;
                break;
            }
        }
    }

    if (result) {
        prime_counter++;
    }

    if (prime_total != NULL) {
        *prime_total = prime_counter;
    }

    return result;
}
