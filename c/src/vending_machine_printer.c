
#include <string.h>
#include <stdio.h>
#include "vending_machine_printer.h"


// Concatenate 'str' onto buffer, at end
void add(char* buffer, char* str) {
    sprintf(buffer + strlen(buffer), str);
}

void print_machine(const struct vending_machine* machine, char* buffer) {
    // TODO: print some useful values from the machine

    add(buffer, "VendingMachine\n");
    sprintf(buffer + strlen(buffer), "%-20s%40s\n", "Display:", machine->display);

    // Note: there is a print_coins function below for when all the simple
    // values are printed.
}

void print_coins(char* buffer, const int* coins, int coins_length) {
    add(buffer, "{");
    // TODO: implement
    add(buffer, "}");
}
