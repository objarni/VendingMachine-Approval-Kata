#include <gtest/gtest.h>
#include "ApprovalTests.hpp"

using namespace std;

extern "C"
{
#include "vending_machine_printer.h"
#include "vending_machine.h"
#include "coin.h"
#include "VendingMachineTest.h"
}

void add(char* buffer, char* str) {
    sprintf(buffer + strlen(buffer), str);
}

void addState(char *buf, vending_machine *machine) {
    char machineState[MAX_PRINT_LENGTH];
    print_machine(machine, machineState);
    add(buf, machineState); add(buf, "\n");
}

void addInsertCoinAction(char *buf, vending_machine *machine, char *coin_name) {
    // Action
    insert_coin(machine, coin_with_name(coin_name));

    // Print action
    char actionLine[MAX_PRINT_LENGTH];
    sprintf(actionLine, "User action: INSERT COIN '%s'\n\n", coin_name);
    add(buf, actionLine);

    // Print state
    addState(buf, machine);
}


TEST_F(VendingMachineTest, InsertCoins) {
    char toVerify[MAX_PRINT_LENGTH];

    addState(toVerify, machine);

    addInsertCoinAction(toVerify, machine, "nickel");
    addInsertCoinAction(toVerify, machine, "dime");
    addInsertCoinAction(toVerify, machine, "quarter");
    addInsertCoinAction(toVerify, machine, "penny");

    ApprovalTests::Approvals::verify(string(toVerify));
}

/* Target code equivalent
    string toApprove = printer->print();

    toApprove += insertCoin("nickel");
    toApprove += printer->print();

    toApprove += insertCoin("dime");
    toApprove += printer->print();

    toApprove += insertCoin("quarter");
    toApprove += printer->print();

    toApprove += insertCoin("penny");
    toApprove += printer->print();

    ApprovalTests::Approvals::verify(toApprove);
*/
