#include "account.h"

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