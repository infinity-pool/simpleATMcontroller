#include "atm_controller.h"
#include "bank_api.h"
#include <iostream>

ATMController::ATMController() {
    this->account = Account();
}

bool ATMController::InsertCardSelectAccount(int card_id, std::string PIN, int account_id) {
    if (card_id <= 0) {
        // std::cout << "[FAIL : WRONG CARD ID]" << std::endl;
        return false;
    }
    if (!BankAPI::IsCorrectPIN(card_id, PIN)) {
        // std::cout << "[FAIL : WRONG PIN]" << std::endl;
        return false;
    }
    std::vector<Account> accounts = BankAPI::getAccounts(card_id, PIN);
    for (auto account : accounts) {
        if (account.GetAccountID() == account_id) {
            this->account = account;
            return true;
        }
    }
    // std::cout << "[FAIL : WRONG ACCOUNT ID]" << std::endl;
    return false;
}

int ATMController::SeeBalance() {
    if (!IsAccountSelected()) {
        // std::cout << "[FAIL : INSERT THE CARD AND SELECT ACCOUNT FIRST]" << std::endl;
        return -1;
    }
    return this->account.GetBalance();
}

bool ATMController::Deposit(int dollars) {
    if (!IsAccountSelected()) {
        // std::cout << "[FAIL : INSERT THE CARD AND SELECT ACCOUNT FIRST]" << std::endl;
        return false;
    }
    return this->account.Deposit(dollars);
}

bool ATMController::Withdraw(int dollars) {
    if (!IsAccountSelected()) {
        // std::cout << "[FAIL : INSERT THE CARD AND SELECT ACCOUNT FIRST]" << std::endl;
        return false;
    }
    return this->account.Withdraw(dollars);
}

bool ATMController::TakeoutCard() {
    if (!IsAccountSelected()) {
        // std::cout << "[FAIL : INSERT THE CARD AND SELECT ACCOUNT FIRST]" << std::endl;
        return false;
    }
    this->account = Account();
    return true;
}

bool ATMController::IsAccountSelected() {
    return (this->account.GetCardID() != -1);
}