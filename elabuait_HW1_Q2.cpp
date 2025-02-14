#include <iostream>
using namespace std;

class Check {
    public:
    Check();
    void setCheckNum(int newCheckNum);
    void setCheckMemo(string newCheckMemo);
    void setCheckAmount(double newCheckAmount);
    void setNumber(int newNumber);
    int getCheckNum() const;
    string getCheckMemo() const;
    double getCheckAmount() const;
    static int getNumber();

private:
    int CheckNum;
    string CheckMemo;
    double CheckAmount;
    static int number;
};
class CheckBook {
public:
    CheckBook();
    CheckBook(double initialDeposit);
    const int checkLimit = N;
    bool writeCheck(float amount);
    void displayChecks();
    void setallChecks(int checksRecord);
    int getallChecks() const;
    void deposit(double amount);
private:
    double balance;
    double lastDeposit;
    int numOfChecks;
    static int allChecks;
    static const int N=5;
    Check array1[N];
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
    cout<<cb1.getallChecks()<<endl;
    cout<<cb2.getallChecks()<<endl;
    return 0;
}
Check::Check(): CheckNum(0), CheckMemo(""), CheckAmount(0) {
    number++;
}
CheckBook::CheckBook() : balance(0), numOfChecks(0), lastDeposit(0) {}
CheckBook::CheckBook(double initialDeposit) : balance(initialDeposit), numOfChecks(0), lastDeposit(0) {}
int Check::number = 0;
int CheckBook::allChecks = 0;
void Check::setCheckNum(int newCheckNum) {
    CheckNum = newCheckNum;
}
void Check::setCheckMemo(string newCheckMemo) {
    CheckMemo = newCheckMemo;
}
void Check::setCheckAmount(double newCheckAmount) {
    CheckAmount = newCheckAmount;
}
void CheckBook::setallChecks(int checksRecord) {
    allChecks = checksRecord;
}
void Check::setNumber(int newNumber) {
    number = newNumber;
}
int Check::getCheckNum() const {
    return CheckNum;
}
string Check::getCheckMemo() const {
    return CheckMemo;
}
double Check::getCheckAmount() const {
    return CheckAmount;
}
int CheckBook::getallChecks() const {
    return allChecks;
}
int Check::getNumber() {
    return number;
}
void CheckBook::deposit(double amount) {
    balance += amount;
    lastDeposit = amount;
    cout << "Deposited: " << amount << ", Current Balance: " << balance << endl;
}
void CheckBook::displayChecks() {
    for (int i = numOfChecks-1; i >=0; i--) {
        cout << "Check Number: " << array1[i].getCheckNum() << endl;
        cout << "Memo: " << array1[i].getCheckMemo() << endl;
        cout << "Amount: "<< array1[i].getCheckAmount() << endl;
    }
}
bool CheckBook::writeCheck(float amount) {
    if (numOfChecks < checkLimit && allChecks < 10 && balance >= amount) {
        string memo;
        cout<<"Enter the check details"<<endl;
        cin>>memo;
        array1[numOfChecks].setCheckNum(numOfChecks);
        array1[numOfChecks].setCheckMemo(memo);
        array1[numOfChecks].setCheckAmount(amount);
        balance -= amount;
        numOfChecks++;
        allChecks++;
        return true;
    }
    return false;
}


