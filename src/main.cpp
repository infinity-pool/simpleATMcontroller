#include <iostream>
#include "atm_controller.h"

int main() {
    ATMController atm_controller;

    int card_id;
    std::string PIN;
    int account_id;
    std::cin >> card_id >> PIN >> account_id;
    atm_controller.InsertCardSelectAccount(card_id, PIN, account_id);
    
    return 0;
}