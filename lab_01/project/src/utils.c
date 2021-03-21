#include "utils.h"

size_t custom_strlen(const char* str) {
    int len = 0;

    for (; *str != '\0'; str++, len++) {
    }

    return len;
}

int custom_pow(const int base, const int power) {
    return pow(base, power);
}
