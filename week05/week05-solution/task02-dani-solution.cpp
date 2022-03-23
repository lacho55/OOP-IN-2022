#include <iostream>
#include <cstring>
 
const int MAX_SIZE = 100;
char temp[MAX_SIZE];
 
class BankAccount {
public:
    BankAccount();
 
    BankAccount(const char *name, const char *accountNum, const double balance);
 
    BankAccount(const BankAccount &other);
 
    BankAccount &operator=(const BankAccount &other);
 
    ~BankAccount();
 
    void setName(const char *name);
 
    void setAccountNum(const char *accountNum);
 
    void setBalance(const double balance);
 
    const char *getName() const;
 
    const char *getAccountNum() const;
 
    double getBalance() const;
 
private:
    char *name;
    char *accountNum;
    double balance;
 
    void copy(const char *name, const char *accountNum, const double balance);
 
    void destroy();
};
 
BankAccount::BankAccount()
        : BankAccount("Unknown", "0000", 0) {
 
}
 
BankAccount::BankAccount(const char *name, const char *accountNum, const double balance) {
    this->copy(name, accountNum, balance);
}
 
BankAccount::BankAccount(const BankAccount &other)
        : BankAccount(other.name, other.accountNum, other.balance) {}
 
BankAccount &BankAccount::operator=(const BankAccount &other) {
    if (this != &other) {
        this->destroy();
        this->copy(other.name, other.accountNum, other.balance);
    }
    return *this;
}
 
BankAccount::~BankAccount() {
    this->destroy();
}
 
void BankAccount::setName(const char *name) {
    if (name == nullptr)
        return;
    this->name = new(std::nothrow) char[strlen(name) + 1];
    if (this->name == nullptr) {
        std::cerr << "Error in memory allocation!";
        return;
    }
 
    strcpy(this->name, name);
}
 
void BankAccount::setAccountNum(const char *accountNum) {
    if (accountNum == nullptr)
        return;
    this->accountNum = new(std::nothrow) char[strlen(accountNum) + 1];
    if (this->accountNum == nullptr) {
        std::cerr << "Error in memory allocation!";
        return;
    }
 
    strcpy(this->accountNum, accountNum);
}
 
void BankAccount::setBalance(const double balance) {
    if (balance < 0)
        return;
    this->balance = balance;
}
 
const char *BankAccount::getName() const {
    return this->name;
}
 
const char *BankAccount::getAccountNum() const {
    return this->accountNum;
}
 
double BankAccount::getBalance() const {
    return this->balance;
}
 
void BankAccount::copy(const char *name, const char *accountNum, const double balance) {
    this->setName(name);
    this->setAccountNum(accountNum);
    this->setBalance(balance);
}
 
void BankAccount::destroy() {
    delete[] this->name;
    delete[] this->accountNum;
}
 
int main() {
    BankAccount account1("Name2", "2111", 20);
    BankAccount account2(account1);
    BankAccount account3;
 
    account3 = account2;
 
    std::cout << account3.getName() << ' ' << account3.getAccountNum() << ' ' << account3.getBalance();
}
 
 