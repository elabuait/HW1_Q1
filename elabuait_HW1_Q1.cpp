#include <iostream>
using namespace std;

struct Check {
    int CheckNum;
    string CheckMemo;
    double CheckAmount;
};
class CheckBook {
public:
    CheckBook();
    CheckBook(double initialbalance);
    void deposit(double amount);
    void displayChecks();
    bool writeCheck(float amount);
    void setBalance(double newBalance);
    void setLastDeposit(double deposit);
    void setNumOfChecks(int num);
    double getBalance() const;
    double getLastDeposit() const;
    int getNumOfChecks() const;
private:
    double balance;
    double lastDeposit;
    int numOfChecks;
    static const int N=5;
    Check array1[N];
    const int checkLimit=N;
};
int main() {
    CheckBook cb1(1000), cb2(500);
    for(int i=0; i<10;i++)
    {
        cb1.writeCheck(150);
        cb2.writeCheck(130);
    }
    cout<<"cb1 check details"<<endl;
    cb1.displayChecks();
    cout<<"cb2 check details"<<endl;
    cb2.displayChecks();
    return 0;
}

CheckBook::CheckBook(): balance(0), numOfChecks(0) {}
CheckBook::CheckBook(double initialbalance): balance(initialbalance), numOfChecks(0){}
void CheckBook::deposit(double amount) {
    balance += amount;
    lastDeposit = amount;
    //cout << "Thank you for your deposit of "<< amount <<". Balance: " << balance << endl;
};
void CheckBook::displayChecks() {
    for (int i = numOfChecks-1; i >=0; i--) {
        cout << "Check Number: " << array1[i].CheckNum << endl;
        cout << "Memo: " << array1[i].CheckMemo << endl;
        cout << "Amount: "<< array1[i].CheckAmount << endl;
    }
}
bool CheckBook::writeCheck(float amount) {
    if (amount <= balance) {
        string memo;
        cout<<"Enter the check details"<<endl;
        cin>>memo;
        array1[numOfChecks].CheckAmount = amount;
        array1[numOfChecks].CheckMemo = memo;
        array1[numOfChecks].CheckNum = numOfChecks+1;
        numOfChecks++;
        balance -= amount;
        return true;
    }
        return false;
};
void CheckBook::setBalance(double newBalance) {
    balance = newBalance;
}
void CheckBook::setNumOfChecks(int num) {
    numOfChecks = num;
}
void CheckBook::setLastDeposit(double deposit) {
    lastDeposit = deposit;
}
double CheckBook::getBalance() const {
    return balance;
}
int CheckBook::getNumOfChecks() const {
    return numOfChecks;
}
double CheckBook::getLastDeposit() const {
    return lastDeposit;
}