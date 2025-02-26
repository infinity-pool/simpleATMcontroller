#include <iostream>
#include <cassert>
#include <string>
#include "atm_controller.h"
#include "bank_api.h"

void testAccount();
void testATMController();

int main() {
    testAccount();
    testATMController();

    return 0;
}

void testAccount() {
    std::cout << "[testAccount() START...]" << std::endl;
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

    std::cout << "[testAccount() SUCCESS]" << std::endl;
}

void testATMController() {
    std::cout << "[testATMController() START...]" << std::endl;

    std::string PINs[] = {"0", "1", "34", "90", "136", "111", "2391", "0000", "9999", "1234"};
    // 1. Test InsertCardSelectAccount()
    for (int card_id = -10; card_id <= 10; card_id++) {
        for (std::string PIN : PINs) {
            for (int account_id = -10; account_id <= 20; account_id++) {
                ATMController atm_controller;
                if (card_id <= 0) // wrong card_id
                    assert(atm_controller.InsertCardSelectAccount(card_id, PIN, account_id) == false);
                else if (PIN != "1234") // wrond PIN
                    assert(atm_controller.InsertCardSelectAccount(card_id, PIN, account_id) == false);
                else if (account_id < 1 || account_id > 10) // wrong account_id
                    assert(atm_controller.InsertCardSelectAccount(card_id, PIN, account_id) == false);
                else // success
                assert(atm_controller.InsertCardSelectAccount(card_id, PIN, account_id) == true);
            }
        }
    }

    // 2. Test before InsertCardSelectAccount()
    ATMController atm_controller2;
    assert(atm_controller2.SeeBalance() == -1);
    for (int dollars = -10; dollars <= 10; dollars++) {
        ATMController atm_controller;
        assert(atm_controller.Deposit(dollars) == false);
        assert(atm_controller.Withdraw(dollars) == false);
    }
    ATMController atm_controller22;
    assert(atm_controller22.TakeoutCard() == false);

    // 3. Test after InsertCardSelectAccount() fail
    ATMController atm_controller3;
    atm_controller3.InsertCardSelectAccount(1, "0000", 1);
    assert(atm_controller3.SeeBalance() == -1);
    for (int dollars = -10; dollars <= 10; dollars++) {
        ATMController atm_controller;
        atm_controller.InsertCardSelectAccount(1, "0000", 1);
        assert(atm_controller.Deposit(dollars) == false);
        assert(atm_controller.Withdraw(dollars) == false);
    }
    ATMController atm_controller33;
    atm_controller33.InsertCardSelectAccount(1, "0000", 1);
    assert(atm_controller33.TakeoutCard() == false);

    // 4. Test after InsertCardSelectAccount() success
    ATMController atm_controller4;
    atm_controller4.InsertCardSelectAccount(1, "1234", 1);
    
    assert(atm_controller4.SeeBalance() == 0); // init SeeBalance()
    
    // 4-1. Test Deposit()
    for (int dollars = -10; dollars <= 10; dollars++) {
        ATMController atm_controller;
        atm_controller.InsertCardSelectAccount(1, "1234", 1);
        if (dollars <= 0)
            assert(atm_controller.Deposit(dollars) == false); // dollars <= 0 : deposit fail
        else
            assert(atm_controller.Deposit(dollars) == true); // dollars > 0 : deposit success
    }

    // 4-2. Test Withdraw with balance == 0
    for (int dollars = -10; dollars <= 10; dollars++) {
        for (int preset_balance = 0; preset_balance <= 20; preset_balance++){
            ATMController atm_controller;
            atm_controller.InsertCardSelectAccount(1, "1234", 1);
            atm_controller.Deposit(preset_balance);
            if (dollars <= 0)
                assert(atm_controller.Withdraw(dollars) == false); // dollars <= 0 : withdraw fail
            else if (atm_controller.SeeBalance() < dollars)
                assert(atm_controller.Withdraw(dollars) == false); // balance < dollars : withdraw fail
            else
                assert(atm_controller.Withdraw(dollars) == true); // withdraw success
        }
    }

    // 5. Test TakeoutCard()
    // 5-1. TakeoutCard() before InsertCardSelectAccount()
    ATMController atm_controller5;
    assert(atm_controller5.TakeoutCard() == false);

    // 5-2. TakeoutCard() after InsertCardSelectAccount() fail
    ATMController atm_controller52;
    atm_controller52.InsertCardSelectAccount(1, "0000", 1);
    assert(atm_controller52.TakeoutCard() == false);

    // 5-3. TakeoutCard() after InsertCardSelectAccount() success
    ATMController atm_controller53;
    atm_controller53.InsertCardSelectAccount(1, "1234", 1);
    assert(atm_controller53.TakeoutCard() == true);

    std::cout << "[testATMController() SUCCESS]" << std::endl;
}