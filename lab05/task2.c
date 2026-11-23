#include <stdio.h>
#include <stdint.h>

void configure_register(uint32_t *reg);
int check_status_flag(const uint32_t *reg, uint8_t bit_pos);
void print_binary(uint32_t reg);

int main(void) {
    uint32_t ctrl_reg = 0x0008000C; // Встановлені біти 2, 3 та 19

    printf("Pochatkovyi stan registra (HEX: 0x%08X):\n", ctrl_reg);
    print_binary(ctrl_reg);

    configure_register(&ctrl_reg);

    printf("\nStan registra pislya modyfikatsii (HEX: 0x%08X):\n", ctrl_reg);
    print_binary(ctrl_reg);

    int bit2 = check_status_flag(&ctrl_reg, 2);
    printf("\nPerevirka statusnoho bita 2: %d\n", bit2);

    return 0;
}

void configure_register(uint32_t *reg) {
    if (reg == NULL) {
        return;
    }

    *reg |= (1U << 7);    // Встановити біт 7 в 1
    *reg &= ~(1U << 3);   // Скинути біт 3 в 0
    *reg ^= (1U << 19);   // Інвертувати біт 19
}

int check_status_flag(const uint32_t *reg, uint8_t bit_pos) {
    if (reg == NULL || bit_pos >= 32) {
        return 0;
    }

    return (int)((*reg >> bit_pos) & 1U);
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
