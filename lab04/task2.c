#include <stdio.h>
#include <stdint.h>

uint32_t set_bit(uint32_t reg, uint8_t bit);
uint32_t clear_bit(uint32_t reg, uint8_t bit);
uint32_t toggle_bit(uint32_t reg, uint8_t bit);
uint8_t check_bit(uint32_t reg, uint8_t bit);
void print_binary(uint32_t reg);

int main(void) {
    uint32_t gpio_reg = 0x00004104;

    printf("Pochatkovyi stan registra (HEX: 0x%08X):\n", gpio_reg);
    print_binary(gpio_reg);

    gpio_reg = set_bit(gpio_reg, 4);
    printf("\nPislya vstanovlennya bita 4 (set_bit):\n");
    print_binary(gpio_reg);

    gpio_reg = clear_bit(gpio_reg, 8);
    printf("\nPislya skydannya bita 8 (clear_bit):\n");
    print_binary(gpio_reg);

    gpio_reg = toggle_bit(gpio_reg, 14);
    printf("\nPislya invertuvannya bita 14 (toggle_bit):\n");
    print_binary(gpio_reg);

    uint8_t bit2_state = check_bit(gpio_reg, 2);
    printf("\nStan bita 2 (check_bit): %u\n", bit2_state);

    return 0;
}

uint32_t set_bit(uint32_t reg, uint8_t bit) {
    return reg | (1U << bit);
}

uint32_t clear_bit(uint32_t reg, uint8_t bit) {
    return reg & ~(1U << bit);
}

uint32_t toggle_bit(uint32_t reg, uint8_t bit) {
    return reg ^ (1U << bit);
}

uint8_t check_bit(uint32_t reg, uint8_t bit) {
    return (reg >> bit) & 1U;
}

void print_binary(uint32_t reg) {
    for (int i = 31; i >= 0; i--) {
        printf("%u", (reg >> i) & 1U);
        if (i % 4 == 0 && i != 0) {
            printf(" ");
        }
    }
    printf("\n");
}
