#ifndef BANK_API_H
#define BANK_API_H
#include <string>
#include <vector>
#include "account.h"

class BankAPI {
public:
    static std::vector<Account> getAccounts(int card_id, std::string PIN);

private:
    static bool IsCorrectPIN(int card_id, std::string PIN);
};

#endif