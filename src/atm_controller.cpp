#include "atm_controller.h"
#include "bank_api.h"
#include <iostream>

ATMController::ATMController() {
    this->account = Account();
}

void ATMController::InsertCardSelectAccount(int card_id, std::string PIN) {
    if (card_id <= 0) {
        std::cout << "[WRONG CARD ID]" << std::endl;
        return;
    }
    std::vector<Account> accounts = BankAPI::getAccounts(card_id, PIN);
    if (accounts.size() != 0) {
        std::cout << "[ACCOUNTS]" << std::endl;
        for (auto account : accounts) {
            std::cout << account.getAccountID() << std::endl;
        }
        std::cout << "[SELECT AN ACCOUNT] : ";
        int account_id;
        std::cin >> account_id;
        for (auto account : accounts) {
            if (account.getAccountID() == account_id) {
                this->account = account;
                std::cout << "[SUCCESS : (CARD ID : " << card_id << ", ACCOUNT_ID : " << this->account.getAccountID() << "]" << std::endl;
                return;
            }
        }
        std::cout << "[WRONG ACCOUNT SELECTION]" << std::endl;
    } else {
        std::cout << "[WRONG PIN]" << std::endl;
    }
}

void ATMController::SeeBalance() {
    if (!IsAccountSelected()) {
        std::cout << "[ERROR : INSERT THE CARD AND SELECT ACCOUNT FIRST]" << std::endl;
    }
}

void ATMController::Deposit(int dollars) {
    if (!IsAccountSelected()) {
        std::cout << "[ERROR : INSERT THE CARD AND SELECT ACCOUNT FIRST]" << std::endl;
    }
}

void ATMController::Withdraw(int dollars) {
    if (!IsAccountSelected()) {
        std::cout << "[ERROR : INSERT THE CARD AND SELECT ACCOUNT FIRST]" << std::endl;
    }
}

void ATMController::TakeoutCard() {
    this->account = Account();
}

bool ATMController::IsAccountSelected() {
    return (this->account.getCardID() != -1);
}