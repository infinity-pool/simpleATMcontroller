#ifndef ATM_CONTROLLER_H
#define ATM_CONTROLLER_H
#include "account.h"
#include <vector>

class ATMController {
public:
    ATMController();
    void InsertCardSelectAccount(int card_id, int PIN);
    void SeeBalance();
    void Deposit(int dollars);
    void Withdraw(int dollars);
    void TakeoutCard();

private:
    Account account;

    bool IsAccountSelected();
    void SelectAccount();
};

#endif