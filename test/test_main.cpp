#include <iostream>
#include <cassert>
#include "atm_controller.h"

void testAccount();
void testATMController();

int main() {
    std::cout << "[testAccount START!]" << std::endl;
    testAccount();
    
    return 0;
}

void testAccount() {
    Account dummy_account;

    // 1. For dummy account
    // 1-1. Get method test
    assert(dummy_account.GetCardID() == -1);
    assert(dummy_account.GetAccountID() == -1);
    assert(dummy_account.GetBalance() == 0);

    // 2. For normal account
    // 2-1. Get method test
    Account normal_account1(1, 1, -10);
    Account normal_account2(2, 2, 0);
    Account normal_account3(3, 3, 10);

    assert(normal_account1.GetCardID() == 1);
    assert(normal_account2.GetCardID() == 2);
    assert(normal_account3.GetCardID() == 3);

    assert(normal_account1.GetAccountID() == 1);
    assert(normal_account2.GetAccountID() == 2);
    assert(normal_account3.GetAccountID() == 3);

    assert(normal_account1.GetBalance() == -10);
    assert(normal_account2.GetBalance() == 0);
    assert(normal_account3.GetBalance() == 10);

    // 2-2. Deposit test
    for (int dollars = -100; dollars <= 0; dollars++) { // Wrong dollars input
        Account normal_account(1, 1, 0);
        assert(dummy_account.Deposit(dollars) == false);
    }
    for (int dollars = 1; dollars <= 100; dollars++) { // deposit success
        Account normal_account(1, 1, 0);
        assert(dummy_account.Deposit(dollars) == true);
    }

    // 2-3. Withdraw test
    for (int dollars = -100; dollars <= 0; dollars++) { // Wrong dollars input
        Account normal_account(1, 1, 0);
        assert(dummy_account.Withdraw(dollars) == false);
    }
    for (int dollars = 90; dollars <= 110; dollars++) { // dollars near balance
        Account normal_account(1, 1, 100);
        assert(normal_account.Withdraw(dollars) == (dollars > 100) ? false : true);
    }

    std::cout << "[testAccount SUCCESS]" << std::endl;
}

void testATMController() {
    ATMController atm_controller;
}