#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account {
public:
    Account();
    Account(int card_id, int account_id, int balance);

private:
    int card_id;
    int account_id;
    int balance;
};

#endif