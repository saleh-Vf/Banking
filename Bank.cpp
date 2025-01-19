#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdlib>

using namespace std;

enum loans_type{
    business = 7000,
    student = 2000,
    mortgage = 5000,
    marriage = 4000,
};

struct Account{
    string name =" " ;
    int national_code;
    string city ="Esfahan";
    int branch_number = 0;
    double account_balance = 2000;
    string account_type = " ";
    int account_point = 150;
    int birth_year = 0;

    void add_loan(loans_type loan){
        int year = 1403 - birth_year;
        if ((loan == 2000 && year<18) || (loan==4000 && year<18))
        {
            cout<<"you are baby for get this loan";
        }
        
        else if ((account_type == "SALARY_ACC" && loan>5000) ||(account_type == "SAVING_ACC" && loan>5000) )
        {
            cout<<" you can get loan less than 5000$"<<endl;
        }else{
            account_balance+=loan;
            cout<<"Loan Application Applied Successfully"<<endl;
        }
        
        
    }
    
}acc;


void checkAccountBalance();
void withdraw(double);
void deposit(double);
void profitCalculation();
void loanRequest();

int main(){
    
    int accout_type = 0;
    string account_balance = " ";
    cout<<"name : ";
    cin>>acc.name;
    cout<<"national code : ";
    cin>>acc.national_code;
    cout<<"city (default = Esfahan) : ";
    cin.ignore();
    getline(cin,acc.city);
    cout<<"branch number : ";
    cin>>acc.branch_number;
    cout<<"balance bank (default = 2000$) : ";
    cin.ignore();
    getline(cin,account_balance);
    (account_balance.empty())?acc.account_balance==2000:acc.account_balance=stod(account_balance);
    cout<<"enter account type (0: SAVING_ACC, 1: SALARY_ACC, 2: NRI ):";
    cin>>accout_type;
    switch (accout_type)
    {
    case 0:
        acc.account_type = "SAVING_ACC";
        break;
    case 1:
        acc.account_type = "SALARY_ACC";
        break;
    case 2:
        acc.account_type = "NRI";
        break;

    }
    cout<<"birth year : ";
    cin>>acc.birth_year;

    // checkAccountBalance();
    // withdraw(1000);
    // deposit(100.5);
    // profitCalculation();
    // loanRequest();
    
}


void checkAccountBalance(){

    if ((acc.account_type == "SAVING_ACC"&& acc.account_balance>1)||(acc.account_type == "SALARY_ACC"&& acc.account_balance>2)||(acc.account_type == "NRI"&& acc.account_balance>2) )
    {   
        if (acc.account_type == "SAVING_ACC")acc.account_balance -= 1;
        else acc.account_balance-=2;

        acc.account_point+=10;
        cout<<"Your bank account balance : "<<acc.account_balance<<endl;
        
    }else cout<<"You are Very Poor"<<endl;
}

void withdraw(double withdraw_volum){
    if(withdraw_volum>10000)cout<<"The Withdrawal Limit is $10000"<<endl;
    else if(withdraw_volum>acc.account_balance) cout<<"Your Account Balance is NOT Enough "<<endl;
    else {
        cout<<"successful"<<endl;
        acc.account_balance-= withdraw_volum;
        acc.account_point+=20;
    }
    
}


void deposit(double deposit_volum){
    if (deposit_volum>1000)
    {
        cout<<"The Deposit Limit is $1000"<<endl;
        acc.account_balance -= acc.account_balance/100;
        checkAccountBalance();
    }
    else {
        cout<<"Deposit was Made Successfully"<<endl;
        acc.account_balance+=deposit_volum;
        acc.account_point+=30;
    }
    
}

void profitCalculation(){
    if (acc.account_type=="SAVING_ACC") cout<<acc.account_balance*0.1<<endl;
    else cout<<acc.account_balance*0.02<<endl;
    
}
void loanRequest(){
    string name =" ";
    int national_code = 0 ;
    int loan_requested = 0;
    int loan_requested_volum = 0;
    cout<<"enter your name : ";
    cin>>name;
    cout<<"enter your national code : ";
    cin>>national_code;
    cout<<"enter loan type (0: business (7000$), 1: student(2000$), 2: mortgage(5000$), 3: marriage(4000$):";
    cin>>loan_requested;

    switch (loan_requested)
    {
    case 0:
        loan_requested_volum = 7000;
        break;
    case 1:
        loan_requested_volum = 2000;
        break;
    case 2:
        loan_requested_volum = 5000;
        break;
    case 3:
        loan_requested_volum = 4000;
        break;
    }


    if (name==acc.name && national_code == acc.national_code )
    {
        if (loan_requested_volum <= acc.account_balance/2)
        {
            if (acc.account_point >=100)
            {
                switch (loan_requested)
                {
                case 0:
                    acc.add_loan(business);
                    break;
                case 1:
                    acc.add_loan(student);
                    break;
                case 2:
                    acc.add_loan(mortgage);
                    break;
                case 3:
                    acc.add_loan(marriage);
                    break;
                

                }
                
            }else cout<<"You don't Have Enough Score"<<endl;
            
        }
        else cout<<"Your Credit is not Enough for This Loan"<<endl;
        
        
    }else cout<<"Account Not Found"<<endl;
}
