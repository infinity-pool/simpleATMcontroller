#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account {
public:
    Account();
    Account(int card_id, int account_id, int balance);

    int GetCardID();
    int GetAccountID();
    int GetBalance();
    bool Deposit(const int dollars);
    bool Withdraw(const int dollars);

private:
    int card_id;
    int account_id;
    int balance;
};

#endif