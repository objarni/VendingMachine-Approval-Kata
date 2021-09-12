
#include <string.h>
#include <stdio.h>
#include "vending_machine_printer.h"

void
print_machine(const struct vending_machine* machine, char* buffer) {
    buffer += sprintf(buffer, "VendingMachine:\n");
    buffer += sprintf(buffer, "%-20s%30s\n", "Display", machine->display);
    buffer += sprintf(buffer, "%-20s%30d\n", "Balance", machine->balance);
}

void
print_coins(char* buffer, const int* coins, int coins_length) {
    // 4 chars for each coin plus zero termination
    int max_array_size = (coins_length)*4 + 1;
    char current_coin[5];
    char array_contents[max_array_size];
    for (int i = 0; i < coins_length; ++i) {
        snprintf(current_coin, 5, "%2d, ", coins[i]);
        if (i == 0) {
            strncpy(array_contents, current_coin, 5);
        } else {
            strncat(array_contents, current_coin, 5);
        }
    }

    array_contents[max_array_size -1] = '\0';

    sprintf(buffer, "{%s}", array_contents );
}
