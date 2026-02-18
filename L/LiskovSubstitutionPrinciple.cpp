
#include<iostream>
#include<vector>
using namespace std;

class DepositOnlyAccount 
{
    public:
    virtual void deposit(double amount) = 0;
};

class WithdrawableAccount : public DepositOnlyAccount
{
    public: 
    virtual void withdraw(double amount) = 0;
};

class SavingsAccount : public WithdrawableAccount
{
    private:
    double balance;

    public:
    SavingsAccount()
    {
        balance = 0;
    }

    void deposit (double amount)
    {
        balance += amount;
        cout<<"Deposited "<<balance<<" in your account. New Balance is "<<balance<<endl;
    }
    void withdraw (double amount)
    {
        if(balance >= amount)
        {
            balance -= amount;
            cout<<"Withdrawn "<<amount<<" from your savings account. New Balance is: "<<balance<<endl;
        }
        else
        {
            cout<<"Insufficient balance in Savings Account "<<endl;
        }
    }
};

class CurrentAccount : public WithdrawableAccount
{
    private:
    double balance;

    public:
    CurrentAccount()
    {
        balance = 0;
    }

    void deposit (double amount)
    {
        balance += amount;
        cout<<"Deposited "<<balance<<" in your account. New Balance is "<<balance<<endl;
    }
    void withdraw (double amount)
    {
        if(balance >= amount)
        {
            balance -= amount;
            cout<<"Withdrawn "<<amount<<" from your Current account. New Balance is: "<<balance<<endl;
        }
        else
        {
            cout<<"Insufficient balance in Current Account "<<endl;
        }
    }
};

class FixedAccount : public DepositOnlyAccount
{
    private:
    double balance;

    public:
    FixedAccount()
    {
        balance = 0;
    }

    void deposit(double amount)
    {
        balance += amount;
        cout<<"Deposited "<<amount<<" in your Fixed Account. New Balance is: "<<balance<<endl;
    }
};

class BankClient 
{
    private:
    vector<DepositOnlyAccount*>DepositableAccount;
    vector<WithdrawableAccount*>WithdrawOnlyAccount;

    public:
    BankClient(vector<DepositOnlyAccount*>DepositableAccount,vector<WithdrawableAccount*>WithdrawOnlyAccount)
    {
        this->DepositableAccount = DepositableAccount;
        this->WithdrawOnlyAccount = WithdrawOnlyAccount;
    }

    void ProcessTransaction ()
    {
        for(WithdrawableAccount* acc : WithdrawOnlyAccount)
        {
            acc->deposit(1000); 
            acc->withdraw(500);
        }
        for(DepositOnlyAccount* acc : DepositableAccount)
        {
            acc->deposit(5000);
        }
    }
};

int main ()
{
    vector<WithdrawableAccount*> withdrawableAccount;
    vector<DepositOnlyAccount*> depositableAccount;
    withdrawableAccount.push_back(new SavingsAccount());
    withdrawableAccount.push_back(new CurrentAccount());
    depositableAccount.push_back(new FixedAccount());

    BankClient* client = new BankClient(depositableAccount,withdrawableAccount);
    client->ProcessTransaction();


}
