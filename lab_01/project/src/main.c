#include <stdlib.h>
#include <stdio.h>

#include "utils.h"
#include "prime_check.h"

#define ERR_ARGS_COUNT          (-1)
#define ERR_WRONG_FLG           (-2)
#define ERR_STRTOL              (-3)
#define OK                      0

#define MIN_ARGS_COUNT          3
#define POW_CASE_ARGS_COUNT     4
#define BASE                    10

#define TST_FOO_FIX             1
#define TST_FOO_IMPL            2
#define TST_MOD_IMPL            3


int main(int argc, const char** argv) {
    if (argc < MIN_ARGS_COUNT) {
        return ERR_ARGS_COUNT;
    }

    char* end = NULL;
    int test_case = (int) strtol(argv[1], &end, BASE);
    const char* data = argv[2];

    if (*end != '\0') {
        return ERR_STRTOL;
    }

    switch (test_case) {
        case TST_FOO_FIX: {
            size_t res = custom_strlen(data);

            printf("%zu\n", res);
            break;
        }
        case TST_FOO_IMPL: {
            if (argc != POW_CASE_ARGS_COUNT)
                return ERR_ARGS_COUNT;

            int base = (int) strtol(data, &end, BASE);

            if (*end != '\0') {
                return ERR_STRTOL;
            }

            int pow =  (int) strtol(argv[3], &end, BASE);

            if (*end != '\0') {
                return ERR_STRTOL;
            }

            int res = custom_pow(base, pow);

            printf("%i\n", res);
            break;
        }
        case TST_MOD_IMPL: {
            int num = (int) strtol(data, &end, BASE);

            if (*end != '\0') {
                return ERR_STRTOL;
            }

            int res = is_prime(num);

            printf("%d", res);
            break;
        }
        default: {
            return ERR_WRONG_FLG;
        }
    }

    return OK;
}
