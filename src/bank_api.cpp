#include "bank_api.h"

std::vector<Account> BankAPI::getAccounts(int card_id, std::string PIN) {
    if (IsCorrectPIN(card_id, PIN)) {
        std::vector<Account> accounts;
        for (int account_id = 1; account_id <= 10; account_id++) {
            Account account(card_id, account_id, 0);
            accounts.push_back(account);
        }
        return accounts;
    }
    return {};
}

bool BankAPI::IsCorrectPIN(int card_id, std::string PIN) {
    return (PIN == "1234");
}