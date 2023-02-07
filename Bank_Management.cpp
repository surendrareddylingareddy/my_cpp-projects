#include<bits\stdc++.h>
using namespace std;
class Bank_Data{
    public:
    void Bank_Provides();
    void open_account();
    void show_Accounts();
    void Deposit();
    void WithDrawl();
    void Check_Balance();
    void Get_Loan();
    void Loan_Details();
    void Pay_Loan();
    // void Check_Account();
};
void Bank_Data::Bank_Provides(){
    cout<<"\n\t\t\t\tWELCOME TO CITY BANK";
    cout<<"\n\t1. OPEN ACCOUNT";
    cout<<"\n\t2. DISPLAY ACCOUNTS";
    cout<<"\n\t3. DEPOSIT MONEY";
    cout<<"\n\t4. WITHDRAW MONEY";
    cout<<"\n\t5. CHECK BANK BALANCE";
    cout<<"\n\t6. GET LOAN";
    cout<<"\n\t7. LOAN DETAILS";
    cout<<"\n\t8. PAY LOAN";
    cout<<"\n\t9. CHECK ACCOUNT DETAILS";
}
void Bank_Data::open_account(){
    system("cls");
    fstream file;
    int Account_no,Min_deposit;
    string Name, Mother_name;
    string Father_name,phone_no;
    string address;
    file.open("C:\\Users\\suren\\Documents\\Bank_records.txt",ios::out | ios::app);
    if(!file){
        cout<<"\n\n\tFile Opening Error.";
    }
    else{
        cout<<"\n\n\tEnter your Name : ";
        cin>>Name;
        cout<<"\n\tEnter your Mother Name : ";
        cin>>Mother_name;
        cout<<"\n\tEnter your Father Name : ";
        cin>>Father_name;
        cout<<"\n\tEnter your Residential Address : ";
        cin>>address;
        cout<<"\n\tEnter your Phone Number : ";
        cin>>phone_no;
        cout<<"\n\tHow much you want to deposit first ? ";
        cin>>Min_deposit;
        cout<<"\n\tGenerating your Account Number : ";
        cin>>Account_no;

        file<<" "<<Name<<" "<<Account_no<<" "<<Mother_name<<" "<<Father_name<<" "<<Min_deposit<<" "<<phone_no<<" "<<address<<"\n";
        cout<<"\n\tAccount created Successfully";
        file.close();
    }
    return ;
}
void Bank_Data::Deposit(){
    fstream file1,file;
    int account_no,deposit;
    int Account_no,balance;
    string Name,Mother_name,Father_name,phone_no;
    string address;
    file1.open("C:\\Users\\suren\\Documents\\Bank_records_1.txt",ios::out | ios::app);
    file.open("C:\\Users\\suren\\Documents\\Bank_records.txt",ios::in);
    if(!file or !file1){
        cout<<"\n\tFile Opening Error.";
    }
    else{
        cout<<"\n\tEnter your Account Number : ";
        cin>>account_no;
        cout<<"\n\tHow Much do you want to Deposit ? ";
        cin>>deposit;
        file>>Name>>Account_no>>Mother_name>>Father_name>>balance>>phone_no>>address;
        while(!file.eof()){
            if(account_no == Account_no){
                cout<<"\n\tAccount Holder Details :";
                cout<<"\n\t\tName           : "<<Name;
                cout<<"\n\t\tAccount Number : "<<account_no;
                cout<<"\n\t\tPhone          : "<<phone_no<<"\n";
                balance += deposit;
                file1<<" "<<Name<<" "<<Account_no<<" "<<Mother_name<<" "<<Father_name<<" "<<balance<<" "<<phone_no<<" "<<address<<"\n";
            }
            else{
                file1<<" "<<Name<<" "<<Account_no<<" "<<Mother_name<<" "<<Father_name<<" "<<balance<<" "<<phone_no<<" "<<address<<"\n";
            }
            file>>Name>>Account_no>>Mother_name>>Father_name>>balance>>phone_no>>address;
        }
        file1.close();
        file.close();
    }
    remove("C:\\Users\\suren\\Documents\\Bank_records.txt");
    rename("C:\\Users\\suren\\Documents\\Bank_records_1.txt","C:\\Users\\suren\\Documents\\Bank_records.txt");
    return;
}
void Bank_Data::show_Accounts(){
    fstream file;
    int Account_no,balance;
    string Name,Mother_name,Father_name,phone_no;
    string address;
    file.open("C:\\Users\\suren\\Documents\\Bank_records.txt",ios::in);
    if(!file){
        cout<<"\n\tFile Opening Error.";
    }
    else{
        cout<<"\n\t\t\t\t\tACCOUNT DETAILS";
        file>>Name>>Account_no>>Mother_name>>Father_name>>balance>>phone_no>>address;
        while(!file.eof()){
            cout<<"\n\t"<<Name<<"\t\t"<<Account_no<<"\t\t"<<Mother_name<<"\t\t"<<Father_name<<"\t\t"<<balance<<"\t\t"<<phone_no<<"\t\t"<<address;
            file>>Name>>Account_no>>Mother_name>>Father_name>>balance>>phone_no>>address;
        }
        file.close();
    }
    cout<<"\n";
    system("pause");
}
void Bank_Data::Check_Balance(){
    fstream file;
    int acc_no;
    int Account_no,balance;
    string Name,Mother_name,Father_name,phone_no;
    string address;
    file.open("C:\\Users\\suren\\Documents\\Bank_records.txt",ios::in);
    if(!file){
        cout<<"\n\tFile Opening Error.";
    }
    else{
        cout<<"\n\tEnter your account No : ";
        cin>>acc_no;
        file>>Name>>Account_no>>Mother_name>>Father_name>>balance>>phone_no>>address;
        while(!file.eof()){
            if(acc_no==Account_no){
                cout<<"\n\n\tBank Balance Fetching......";
                cout<<"\n\tBalance Amount : "<<balance<<"\n";
                break;
            }
            else{
                file>>Name>>Account_no>>Mother_name>>Father_name>>balance>>phone_no>>address;
            }

        }
        file.close();
    }
    return;
}
void Bank_Data::WithDrawl(){
    fstream file1,file;
    int account_no,withdrawl;
    int Account_no,balance;
    string Name,Mother_name,Father_name,phone_no;
    string address;
    int count = 0;
    file1.open("C:\\Users\\suren\\Documents\\Bank_records_1.txt",ios::out | ios::app);
    file.open("C:\\Users\\suren\\Documents\\Bank_records.txt",ios::in);
    if(!file or !file1){
        cout<<"\n\tFile Opening Error.";
    }
    else{
        cout<<"\n\tEnter your Account Number : ";
        cin>>account_no;
        cout<<"\n\tHow Much do you want to withdrawl ? ";
        cin>>withdrawl;
        file>>Name>>Account_no>>Mother_name>>Father_name>>balance>>phone_no>>address;
        while(!file.eof()){
            if(account_no == Account_no){
                cout<<"\n\tAccount Holder Details :";
                cout<<"\n\t\tName           : "<<Name;
                cout<<"\n\t\tAccount Number : "<<account_no;
                cout<<"\n\t\tPhone          : "<<phone_no<<"\n";
                if(balance >= withdrawl){
                    balance -= withdrawl;
                    count++;
                }
                file1<<" "<<Name<<" "<<Account_no<<" "<<Mother_name<<" "<<Father_name<<" "<<balance<<" "<<phone_no<<" "<<address<<"\n";
            }
            else{
                file1<<" "<<Name<<" "<<Account_no<<" "<<Mother_name<<" "<<Father_name<<" "<<balance<<" "<<phone_no<<" "<<address<<"\n";
            }
            file>>Name>>Account_no>>Mother_name>>Father_name>>balance>>phone_no>>address;
        }
        file1.close();
        file.close();
    }
    if(count){
        cout<<"\n\twithdrawl successfully completed.\n";
    }
    remove("C:\\Users\\suren\\Documents\\Bank_records.txt");
    rename("C:\\Users\\suren\\Documents\\Bank_records_1.txt","C:\\Users\\suren\\Documents\\Bank_records.txt");
    return;
}
void Bank_Data::Get_Loan(){
    fstream file1,file;
    int Account_no,balance;
    string Name,Mother_name,Father_name,phone_no;
    string address;
    int acc_no,loan_amount,time_period;
    int count = 0;
    file.open("C:\\Users\\suren\\Documents\\Bank_records.txt",ios::in);
    file1.open("C:\\Users\\suren\\Documents\\loan.txt",ios::out | ios::app);
    if(!file or !file1){
        cout<<"\n\tFile Opening Error.";
    }
    else{
        cout<<"\n\tEnter your Account Number : ";
        cin>>acc_no;
        file>>Name>>Account_no>>Mother_name>>Father_name>>balance>>phone_no>>address;
        while(!file.eof()){
            if(acc_no == Account_no){
                cout<<"\n\tHow much do you want loan amount ? ";
                cin>>loan_amount;
                cout<<"\n\tIn How many months will you repay the loan ? ";
                cin>>time_period;
                file1<<" "<<Name<<" "<<Account_no<<" "<<balance<<" "<<phone_no<<" "<<loan_amount<<" "<<time_period<<" "<<address<<"\n";
                count++;
                break;
            }
            else{
                file>>Name>>Account_no>>Mother_name>>Father_name>>balance>>phone_no>>address;
            }
        }
        file1.close();
        file.close();
    }
    if(count){
        cout<<"\n\tA Loan amount of Rupee "<<loan_amount<<" is granted.\n";
    }
    else{
        cout<<"\n\tIf you want to apply for loan , you have to create a Bank Account.\n";
    }
    return;
}
void Bank_Data::Loan_Details(){
    fstream file;
    int Account_no,loan_amount,time_period,balance;
    string Name,phone_no,address;
    int acc_no;
    file.open("C:\\Users\\suren\\Documents\\loan.txt",ios::in);
    if(!file){
        cout<<"\n\tFile Opening Error.";
    }
    else{
        cout<<"\n\tEnter your Account Number : ";
        cin>>acc_no;
        file>>Name>>Account_no>>balance>>phone_no>>loan_amount>>time_period>>address;
        while(!file.eof()){
            if(acc_no == Account_no){
                cout<<"\n\tLoan Details for this account is Found.";
                cout<<"\n\t"<<Name<<"\t"<<Account_no<<"\t"<<balance<<"\t"<<phone_no<<"\t"<<loan_amount<<"\t"<<time_period<<"\t"<<address;
                break;
            }
            else{
                file>>Name>>Account_no>>balance>>phone_no>>loan_amount>>time_period>>address;
            }
        }
        file.close();
    }
    return;
}
void Bank_Data::Pay_Loan(){
    fstream file,file1;
    int Account_no,loan_amount,time_period,balance;
    string Name,phone_no,address;
    int acc_no,payment;
    int count = 0;
    file.open("C:\\Users\\suren\\Documents\\loan.txt",ios::in);
    file1.open("C:\\Users\\suren\\Documents\\loan1.txt",ios::out | ios::app);
    if(!file){
        cout<<"\n\tFile Opening Error.";
    }
    else{
        cout<<"\n\tEnter your Account Number : ";
        cin>>acc_no;
        file>>Name>>Account_no>>balance>>phone_no>>loan_amount>>time_period>>address;
        while(!file.eof()){
            if(acc_no == Account_no){
                cout<<"\n\tHow Much do you want to pay ? ";
                cin>>payment;
                if(loan_amount <= payment){
                    loan_amount = 0;
                }
                else{
                    loan_amount -= payment;
                }
                file1<<" "<<Name<<" "<<Account_no<<" "<<balance<<" "<<phone_no<<" "<<loan_amount<<" "<<time_period<<" "<<address<<"\n";
                cout<<"\n\tThe loan amount "<<loan_amount<<" is successfully cleared.";
                cout<<"\n\tBalance Loan Amount : "<<loan_amount;
                count++;
            }
            else{
                file1<<" "<<Name<<" "<<Account_no<<" "<<balance<<" "<<phone_no<<" "<<loan_amount<<" "<<time_period<<" "<<address<<"\n";
            }
            file>>Name>>Account_no>>balance>>phone_no>>loan_amount>>time_period>>address;
        }
        file.close();
        file1.close();
    }
    if(!count){
        cout<<"\n\tinvalid details.\n";
    }
    remove("C:\\Users\\suren\\Documents\\loan.txt");
    rename("C:\\Users\\suren\\Documents\\loan1.txt","C:\\Users\\suren\\Documents\\loan.txt");
    return;
}
void MyBank(){
    int ch;
    Bank_Data b;
    while(1){
        b.Bank_Provides();
        cout<<"\n\n\tEnter Your choice : ";
        cin>>ch;
        switch(ch){
            case 1:
            b.open_account();
            break;
            case 2:
            b.show_Accounts();
            break;
            case 3:
            b.Deposit();
            break;
            case 4:
            b.WithDrawl();
            break;
            case 5:
            b.Check_Balance();
            break;
            case 6:
            b.Get_Loan();
            break;
            case 7:
            b.Loan_Details();
            break;
            case 8:
            b.Pay_Loan();
            break;
            // case 9:
            // b.Check_Account();
            // break;
            case 10:
            exit(0);
            break;
            default :
            cout<<"\n\tInvalid Choice";
        }
    }
    return ;
}
int main() {
    MyBank();
    return 0;
}