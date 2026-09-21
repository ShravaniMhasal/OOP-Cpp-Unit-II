#include <iostream>
using namespace std;

class Account {
private:
    // balance is private, so normally NO other class can touch this directly
    double balance;

    // BUT this line breaks that rule on purpose
    // "friend class Auditor" means "I trust Auditor, let it access my private stuff too"
    // this is not inheritance, Auditor is NOT a child of Account, it's just a special exception
    friend class Auditor;

public:
    // constructor - sets the initial balance
    explicit Account(double initialBalance) : balance(initialBalance) {}
};

// Auditor is a completely separate class, has NOTHING to do with inheritance here
class Auditor {
public:
    // because Account made Auditor its "friend", this function CAN access
    // account.balance directly even though balance is private in Account
    // normally this would give an error, but friend fixes that
    void inspect(const Account& account) const {
        cout << "Account Balance: " << account.balance << '\n';
    }
};

int main() {
    Account account(5000.0);
    Auditor auditor;

    // Auditor can peek into Account's private balance because of the friend declaration
    auditor.inspect(account);

    return 0;
}