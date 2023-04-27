#include <iostream>
#include <string>
#include <map>

using namespace std;

class Account {
        string name, mobile, pin;
        double balance;
    public:
        Account(string name="", string mobile="", string pin="", double balance=0.0) {
            this->name = name;
            this->mobile = mobile;
            this->pin = pin;
            this->balance = balance;
        }
        string getName() const {
            return name;
        }
        string getMobile() const {
            return mobile;
        }
        string getPin() const {
            return pin;
        }
        void setName(string name) {
            this->name = name;
        }
        void setMobile(string mobile) {
            this->mobile = mobile;
        }
        void setPin(string pin) {
            this->pin = pin;
        }
        double getBalance() const {
            return balance;
        }
        void deposit(double amount) {
            this->balance += amount;
        }
        bool withdraw(double amount) {
            if (amount > balance) {
                return false;
            }
            balance -= amount;
            return true;
        }
};
map<string,Account> accounts;
bool isAccountValid(string accountNumber,string pin){
    if(accounts.count(accountNumber)==0 ||accounts[accountNumber].getPin()!=pin){
        cout<<"*****Invalid Account Number or pin ***********"<<endl;
        return false;
    }
    return true;
}
void createAccount(){
    string name,mobile,pin;
    cout<<"Enter the name :";
    cin>>name;
    cout<<"Enter the mobile number :";
    cin>>mobile;
    cout<<"Enter the 4 digit number:";
    cin>>pin;
    string accountNumber=to_string(accounts.size()+1);
    accountNumber=string(6-accountNumber.length(),'0')+accountNumber;
    accounts[accountNumber]=Account(name,mobile,pin,0.0);
    cout<<"Your account number is created .i.e :"<< accountNumber<<endl;
}
void showAccountDetails(string accountNumber,string pin){
if(isAccountValid(accountNumber,pin)){
    Account account=accounts[accountNumber];
    cout<<"Name:"<<account.getName() <<endl;
    cout<<"Mobile:"<<account.getMobile() <<endl;
    cout<<"Balance:"<<account.getBalance() <<endl;
}
}
void deposit(string accountNumber,string pin){
    if(isAccountValid(accountNumber,pin)){
        double amount;
        cout<<"Enter the amount to be added : ";
        cin>>amount;
        Account& account=accounts[accountNumber];
        account.deposit(amount);
        cout<<"Your account deposit of :"<<amount<<"is successful and your current balance is"<<account.getBalance() <<endl; 
    }
}

void withdraw(string accountNumber,string pin){
    if(isAccountValid(accountNumber,pin)){
        double amount;
        cout<<"Enter the amount you want to withdraw:"<<endl;
        cin>>amount;
        Account& account=accounts[accountNumber];
        if(account.withdraw(amount)){
            cout<<"Your withdrawal of "<<amount<<"is successful and your current balance is"<<account.getBalance() <<endl; 
        }
        else {
            cout<<"Insufficient Balance"<<endl;
        }
    }
}
    int main() {
    string accountNumber, pin;
    int choice;
    while (true) {
        cout << "Enter account number: ";
        cin >> accountNumber;
        cout << "Enter pin: ";
        cin >> pin;

        cout << "\n1. Create account\n";
        cout << "2. Show account details\n";
        cout << "3. Deposit\n";
        cout << "4. Withdraw\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                showAccountDetails(accountNumber, pin);
                break;
            case 3:
                deposit(accountNumber, pin);
                break;
            case 4:
                withdraw(accountNumber, pin);
                break;
            case 5:
                cout << "Exiting...";
                exit(0);
                break;
            default:
                cout << "Invalid choice";
                break;
        }
    }
    return 0;
}
    



