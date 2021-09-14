
#include <string.h>
#include <stdio.h>
#include "vending_machine_printer.h"

void
print_machine(const struct vending_machine* machine, char* buffer) {
    buffer += sprintf(buffer, "VendingMachine:\n");
    buffer += sprintf(buffer, "%-20s%30s\n", "Display", machine->display);
    buffer += sprintf(buffer, "%-20s%30d\n", "Balance", machine->balance);
    char listBuffer[LINE_LENGTH];
    print_coins(listBuffer, machine->coins, machine->coin_count);
    buffer += sprintf(buffer, "%-20s%30s\n", "Coins", listBuffer);
    print_coins(listBuffer, machine->returns, machine->return_count);
    buffer += sprintf(buffer, "%-20s%30s\n", "Returns", listBuffer);
}

void add(char* buffer, char* str) {
    sprintf(buffer + strlen(buffer), str);
}

void
print_coins(char* buffer, const int* coins, int coins_length) {
    strcpy(buffer, "");
    add(buffer, "{");
    char current_coin[5];
    for (int i = 0; i < coins_length; ++i) {
        sprintf(current_coin, "%d", coins[i]);
        add(buffer, current_coin);
        if(i < coins_length-1)
            add(buffer, ", ");
    }
    add(buffer, "}");
}
