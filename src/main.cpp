#include <iostream>
#include "atm_controller.h"

int main() {
    // ATMController atm_controller;

    // int card_id;
    // std::string PIN;
    // int account_id;
    // std::cout << "Enter 'card_id PIN account_id' : ";
    // std::cin >> card_id >> PIN >> account_id;
    // atm_controller.InsertCardSelectAccount(card_id, PIN, account_id);

    /*
    Code implements the flow below with values that meet the assumptions..
    Insert Card => PIN number => Select Account => See Balance/Deposit/Withdraw
    */
    ATMController atm_controller;

    int card_id = 10;
    std::string PIN = "1234";
    int account_id = 5;

    // 1. Insert card and select account
    atm_controller.InsertCardSelectAccount(card_id, PIN, account_id);
    std::cout << "[After Insert Card and Select Account]" << std::endl;
    std::cout << "- Balance : " << atm_controller.SeeBalance() << std::endl;

    // 2. Deposit 100 dollars into account
    atm_controller.Deposit(100);
    std::cout << "[After Deposit 100 dollars]" << std::endl;
    std::cout << "- Balance : " << atm_controller.SeeBalance() << std::endl;

    // 3. Deposit 50 dollars into account
    atm_controller.Deposit(50);
    std::cout << "[After Deposit 50 dollars]" << std::endl;
    std::cout << "- Balance : " << atm_controller.SeeBalance() << std::endl;

    // 4. WithDraw 200 dollars from account
    atm_controller.Withdraw(200);
    std::cout << "[After Withdraw 200 dollars]" << std::endl;
    std::cout << "- Balance : " << atm_controller.SeeBalance() << std::endl;

    // 5. WithDraw 70 dollars from account
    atm_controller.Withdraw(70);
    std::cout << "[After Withdraw 70 dollars]" << std::endl;
    std::cout << "- Balance : " << atm_controller.SeeBalance() << std::endl;

    // 6. WithDraw 80 dollars from account
    atm_controller.Withdraw(80);
    std::cout << "[After Withdraw 80 dollars]" << std::endl;
    std::cout << "- Balance : " << atm_controller.SeeBalance() << std::endl;
    
    return 0;
}