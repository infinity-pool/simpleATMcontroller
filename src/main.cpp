#include <iostream>
#include "atm_controller.h"

int main() {
    ATMController atm_controller;

    int card_id;
    std::string PIN;
    std::cin >> card_id >> PIN;
    atm_controller.InsertCardSelectAccount(card_id, PIN);
    
    return 0;
}