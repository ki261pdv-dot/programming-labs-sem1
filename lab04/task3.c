#include <stdio.h>
#include <stdint.h>

uint16_t pack_telemetry(uint8_t priority, uint8_t fan_speed, uint8_t error_code, uint8_t power);
void unpack_telemetry(uint16_t packet, uint8_t *priority, uint8_t *fan_speed, uint8_t *error_code, uint8_t *power);

int main(void) {
    uint8_t init_priority = 11;    // 0..15 (bity 0..3)
    uint8_t init_fan_speed = 185;  // 0..255 (bity 4..11)
    uint8_t init_error_code = 2;   // 0..3 (bity 12..13)
    uint8_t init_power = 1;        // 0..1 (bit 14)

    printf("Pochatkovi dani:\n");
    printf("  Priorytet:             %u\n", init_priority);
    printf("  Shvydkist ventylyatora:%u\n", init_fan_speed);
    printf("  Kod pomylky:           %u\n", init_error_code);
    printf("  Zhyvlennya:            %u\n", init_power);

    uint16_t packet = pack_telemetry(init_priority, init_fan_speed, init_error_code, init_power);
    printf("\nSformovanyi paket (HEX): 0x%04X\n", packet);

    uint8_t dec_priority, dec_fan_speed, dec_error_code, dec_power;
    unpack_telemetry(packet, &dec_priority, &dec_fan_speed, &dec_error_code, &dec_power);

    printf("\nVidnovleni dani pislya rozpakuvannya:\n");
    printf("  Priorytet:             %u\n", dec_priority);
    printf("  Shvydkist ventylyatora:%u\n", dec_fan_speed);
    printf("  Kod pomylky:           %u\n", dec_error_code);
    printf("  Zhyvlennya:            %u\n", dec_power);

    return 0;
}

uint16_t pack_telemetry(uint8_t priority, uint8_t fan_speed, uint8_t error_code, uint8_t power) {
    uint16_t packet = 0;
    packet |= ((uint16_t)(priority & 0x0F) << 0);
    packet |= ((uint16_t)(fan_speed & 0xFF) << 4);
    packet |= ((uint16_t)(error_code & 0x03) << 12);
    packet |= ((uint16_t)(power & 0x01) << 14);
    return packet;
}

void unpack_telemetry(uint16_t packet, uint8_t *priority, uint8_t *fan_speed, uint8_t *error_code, uint8_t *power) {
    *priority   = (packet >> 0) & 0x0F;
    *fan_speed  = (packet >> 4) & 0xFF;
    *error_code = (packet >> 12) & 0x03;
    *power      = (packet >> 14) & 0x01;
}
