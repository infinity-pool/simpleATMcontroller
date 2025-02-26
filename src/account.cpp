#include "account.h"
#include <iostream>

Account::Account() {
    this->card_id = -1;
    this->account_id = -1;
    this->balance = 0;
}

Account::Account(int card_id, int account_id, int balance) {
    this->card_id = card_id;
    this->account_id = account_id;
    this->balance = balance;
}

int Account::GetCardID() { return this->card_id; }

int Account::GetAccountID() { return this->account_id; }

int Account::GetBalance() { return this->balance; }

bool Account::Deposit(const int dollars) {
    if (dollars <= 0) {
        std::cout << "[FAIL : dollars must be greater than zero]" << std::endl;
        return false;
    }
    this->balance += dollars;
    return true;
}

bool Account::Withdraw(const int dollars) {
    if (dollars <= 0) {
        std::cout << "[FAIL : dollars must be greater than zero]" << std::endl;
        return false;
    }
    if (this->balance < dollars) {
        std::cout << "[FAIL : balance must be greater than dollars]" << std::endl;
        return false;
    }
    this->balance -= dollars;
    return true;
}