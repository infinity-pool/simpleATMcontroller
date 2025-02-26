#ifndef ATM_CONTROLLER_H
#define ATM_CONTROLLER_H
#include "account.h"
#include <vector>
#include <string>

class ATMController {
public:
    ATMController();
    bool InsertCardSelectAccount(int card_id, std::string PIN, int account_id);
    int SeeBalance();
    bool Deposit(int dollars);
    bool Withdraw(int dollars);
    bool TakeoutCard();

private:
    Account account;

    bool IsAccountSelected();
};

#endif