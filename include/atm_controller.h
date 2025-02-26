#ifndef ATM_CONTROLLER_H
#define ATM_CONTROLLER_H
#include "account.h"
#include <vector>
#include <string>

class ATMController {
public:
    ATMController();
    void InsertCardSelectAccount(int card_id, std::string PIN);
    void SeeBalance();
    void Deposit(int dollars);
    void Withdraw(int dollars);
    void TakeoutCard();

private:
    Account account;

    bool IsAccountSelected();
};

#endif