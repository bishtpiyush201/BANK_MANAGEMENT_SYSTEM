#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<fstream>
#include<windows.h>
using namespace std;
class bank
{
private:
    int pass;
    char phone[11];
    float balance;
    string id;
    char fname[100];
    char name[100];

    public:
    void menu();
    void bank_management();
    void new_user();
    void already_user();
    void deposit();
    void withdraw();
    void transfer();
    void user_record();
    void payment();
    void edit();
    void del();
};
void bank::menu()
{
    p:
    system("cls");
    int choice;
    char ch;
    string id, pass;
    cout<<" \n\n\n\t\t\t\t\t\t MAIN MENU "<<endl;
    cout<<" \n 1. BANK MANGEMENT "<<endl;
    //cout<<" 2. ATM MANAGEMENT "<<endl;
    cout<<" 2. EXIT "<<endl;
    cout<<" \n Enter your choice: ";
    cin>>choice;
    switch(choice)
    {
    case 1:
        system("cls");
        cout<< " \n\n\n\t\t\t\t\t\t LOGIN ACCOUNT "<<endl;
        cout<< " ID: ";
        cin>>id;
        cout<< " PASSWORD: ";
        for(int i=1;i<=4;i++)
        {
            ch = getch();
            pass += ch;
            cout<<"*";
        }
        if(id == "abc@gmail.com" && pass == "5815")
        {
            bank_management();
        }
        else
        {
            cout<<"\n \t\t\t\t\t\t YOUR ID PASSWORD IS WRONG... ";
        }
        break;
    case 2:
        exit(0);
        break;

    default:
        cout<< " \t\t\t\t\t\t Invalid value.....Please try again ";
    }
    getch();
    goto p;
}
void bank::bank_management()
{
    p:
    system("cls");
    int choice;
    cout<< " \n\n\n\t\t\t\t\t\t BANK MANAGEMENT SYSTEM "<<endl;
    cout<< " \n 1.  New User "<<endl;
    cout<< " 2.  Already User "<<endl;
    cout<< " 3.  Deposit Option "<<endl;
    cout<< " 4.  Withdraw Option "<<endl;
    cout<< " 5.  Transfer Option "<<endl;
    cout<< " 6.  Search User Record "<<endl;
    cout<< " 7.  Payment Option "<<endl;
    cout<< " 8.  Edit User Record "<<endl;
    cout<< " 9.  Delete User Record "<<endl;
    cout<< " 10. Go Back "<<endl;
    cout<< " \n Enter Your Choice: ";
    cin>>choice;
    switch(choice)
    {
    case 1:
        new_user();
        break;
    case 2:
        already_user();
        break;
    case 3:
        deposit();
        break;
    case 4:
        withdraw();
      break;
    case 5:
        transfer();
      break;
    case 6:
        user_record();
      break;
    case 7:
        payment();
      break;
    case 8:
        edit();
      break;
    case 9:
        del();
      break;
    case 10:
      menu();
    default:
        cout<< " \t\t\t\t\t Invalid value.....Please try again ";
    }
    getch();
    goto p;
}
void bank::new_user()
{
    p:
    system("cls");
    fstream file;
    string i,n,f,ps,ph;
    float b;
    cout<<" \n\n\n\t\t\t\t\t\t ADD NEW USER "<<endl;
    cout<<" \n Id: ";
    cin>>id;
    cout<<" Name: ";
    cin>>name;
    cout<< " Father Name: ";
    cin>>fname;
    cout<< " Password: ";
    cin>>pass;
    cout<< " Phone No.: ";
    cin>>phone;
    cout<< " Current Balance: ";
    cin>>balance;
    file.open("bank.txt",ios::in);
    if(!file)
    {
        file.open("bank.txt",ios::app|ios::out);
        file<<" "<<id<<" "<<name<<" "<<fname<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";
        file.close();
    }
    else
    {
    file>>i>>n>>f>>ps>>ph>>b;
    while(!file.eof())
    {
        if(i == id)
        {
            cout<<" \n User Id Already Exist..."<<endl;
            getch();
            goto p;
        }
        file>>i>>n>>f>>ps>>ph>>b;
    }
    file.close();
    file.open("bank.txt",ios::app|ios::out);
        file<<" "<<id<<" "<<name<<" "<<fname<<" "<<pass<<" "<<phone<<" "<<" "<<balance<<"\n";
        file.close();
    }
        cout<<" \n\n\n\t\t\t\t\t\t New User Added Successfully...";
}
void bank::already_user()
{
    system("cls");
    fstream file;
    string a_id;
    int found=0;
    cout<<" \n\n\n\t\t\t\t\t\t ALREADY USER ACCOUNTS ";
    file.open("bank.txt", ios::in);
    if(!file)
    {
        cout<<" \n\n\n\t\t\t\t\t\t File Opening Error ";
    }
    else
    {
    cout<<"\n\n ID: ";
    cin>>a_id;
    file>>id>>name>>fname>>pass>>phone>>balance;
    while(!file.eof())
    {
        if(a_id == id)
        {
            system("cls");
            cout<< "\n\n\n\t\t\t\t\t ALREADY USER ";
            cout<<"\n\n User ID: "<<id;
            cout<<" \n PASSWORD: "<<pass;
            cout<<" \n BALANCE: "<<balance;
            found++;
        }
        file>>id>>name>>fname>>pass>>phone>>balance;
        }
        file.close();
        if(found == 0)
            cout<< " \n\n\n\t\t\t\t\t\t USER ID NOT FOUND...";
    }
}
void bank::deposit()
{
    fstream file,file1;
    string a_id;
    float dep;
    int found=0;
    system("cls");
    cout<<" \n\n\n\t\t\t\t\t\t DEPOSITE AMOOUNT OPTION ";
    file.open("bank.txt",ios::in);
    if(!file)
    {
        cout<<" \n\n\n\t\t\t\t\t\t File Opening Error ";
    }
    else
    {
    cout<<"\n\n ID: ";
    cin>>a_id;
    file1.open("bank1.txt",ios::app|ios::out);
    file>>id>>name>>fname>>pass>>phone>>balance;
    while(!file.eof())
    {
        if(a_id == id)
        {
        cout<<" \n\n Enter Amount to be Deposit: ";
        cin>>dep;
        balance += dep;
        file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<pass<<" "<<phone<<" "<<" "<<balance<<"\n";
        found++;
        cout<<" \n\t\t\t\t\t\t Amount "<<dep<<" Deposited Successfully...";
        cout<< "\n\n \t\t\t\t\t\t Balance "<< balance;
        }
        else
        {
        file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<pass<<" "<<phone<<" "<<" "<<balance<<"\n";
        }
        file>>id>>name>>fname>>pass>>phone>>balance;
        }
        file.close();
        file1.close();
        remove("bank.txt");
        rename("bank1.txt","bank.txt");
        if(found == 0)
            cout<< " \n\n\n\t\t\t\t\t\t USER ID NOT FOUND...";
    }
}
void bank::withdraw()
{
    fstream file,file1;
    string a_id;
    float with;
    int found=0;
    system("cls");
    cout<<" \n\n\n\t\t\t\t\t\t WITHDRAW AMOOUNT OPTION ";
    file.open("bank.txt",ios::in);
    if(!file)
    {
        cout<<" \n\n\n\t\t\t\t\t\t File Opening Error ";
    }
    else
    {
    cout<<"\n\n ID: ";
    cin>>a_id;
    file1.open("bank1.txt",ios::app|ios::out);
    file>>id>>name>>fname>>pass>>phone>>balance;
    while(!file.eof())
    {
        if(a_id == id)
        {
        cout<<" \n\n Enter Amount to be Withdraw: ";
        cin>>with;
        if(with<= balance)
            {
            balance -= with;
            file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<pass<<" "<<phone<<" "<<" "<<balance<<"\n";
            found++;
            cout<<" \n\n\n\t\t\t\t\t\t Amount "<<with<<"Withdrawal Successfully...";
            cout<< "\n\n \t\t\t\t\t\t Balance "<< balance;
            }
        else
        {
            cout<< " \n\n\n\t\t\t\t\t\t Your Current Balance "<<balance<<" is Less";
        }
        found++;
        }
        else
        {
        file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<pass<<" "<<phone<<" "<<" "<<balance<<"\n";
        }
        file>>id>>name>>fname>>pass>>phone>>balance;
        }
        file.close();
        file1.close();
        remove("bank.txt");
        rename("bank1.txt","bank.txt");
        if(found == 0)
            cout<< " \n\n\n\t\t\t\t\t\t USER ID NOT FOUND...";
    }
}
void bank::transfer()
{
    system("cls");
    fstream file, file1;
    string s_id, r_id;
    int found_sender = 0, found_receiver = 0;
    float amount;
    cout << "\n\n\n\t\t\t\t\t\t PAYMENT TRANSFER OPTION ";
    file.open("bank.txt", ios::in);
    if (!file)
    {
        cout << " \n\n\n\t\t\t\t\t\t File Opening Error ";
        return;
    }
    cout << " \n\n Sender ID: ";
    cin >> s_id;
    cout << " \n Receiver ID: ";
    cin >> r_id;
    cout << " \n Transaction Amount: ";
    cin >> amount;
    while (file >> id >> name >> fname >> pass >> phone >> balance)
    {
        if (s_id == id)
        {
            if (balance < amount)
            {
                cout << " \n\n\n\t\t\t\t\t\t Insufficient funds ";
                file.close();
                return;
            }
            found_sender++;
        }
        else if (r_id == id)
        {
            found_receiver++;
        }
    }
    file.close();
    if (found_sender == 1 && found_receiver == 1)
    {
        file.open("bank.txt", ios::in);
        file1.open("bank1.txt", ios::app | ios::out);
        while (file >> id >> name >> fname >> pass >> phone >> balance)
        {
            if (s_id == id)
            {
                balance -= amount;
            }
            else if (r_id == id)
            {
                balance += amount;
            }
            file1 << id << " " << name << " " << fname << " " << pass << " " << phone << " " << balance << "\n";
        }

        cout << " \n\n\n\t\t\t\t\t\t Transaction Successfully ";
        file.close();
        file1.close();
        remove("bank.txt");
        rename("bank1.txt", "bank.txt");
    }
    else
    {
        cout << " \n\n\n\t\t\t\t\t\t Transaction IDs Not Found or Invalid ";
    }
}
void bank::user_record()
{
    system("cls");
    fstream file;
    string a_id;
    int found=0;
    cout<<" \n\n\n\t\t\t\t\t\t USER RECORD ";
    file.open("bank.txt", ios::in);
    if(!file)
    {
        cout<<" \n\n\n\t\t\t\t\t\t File Opening Error ";
    }
    else
    {
    cout<<"\n\n ID: ";
    cin>>a_id;
    file>>id>>name>>fname>>pass>>phone>>balance;
    while(!file.eof())
    {
        if(a_id == id)
        {
            system("cls");
            cout<< "\n\n\n\t\t\t\t\t USER RECORD ";
            cout<<" \n User ID    : "<<id;
            cout<<" \n NAME       : "<<name;
            cout<<" \n FATHER NAME: "<<fname;
            cout<<" \n PASSWORD   : "<<pass;
            cout<<" \n PHONE      : "<<phone;
            cout<<" \n BALANCE    : "<<balance;
            found++;
        }
        file>>id>>name>>fname>>pass>>phone>>balance;
        }
        file.close();
        if(found == 0)
            cout<< " \n\n\n\t\t\t\t\t\t USER ID NOT FOUND...";
    }
}
void bank::payment(){
        system("cls");
        fstream file, file1;
        int found=0;
        float amount;
        SYSTEMTIME x;
        string a_id,b_name;
        cout<<" \n\n\n\t\t\t\t\t\t BILL PAYMENT OPTION ";
        file.open("bank.txt", ios::in);
        if(!file)
                {
                    cout<<" \n\n\n\t\t\t\t\t\t File Opening Error ";
                }
        else
        {
            cout<<"\n\n Enter ID: ";
            cin>>a_id;
            cout<<"\n Bill Name: ";
            cin>>b_name;
            cout<<"\n Bill Amount: ";
            cin>>amount;
            file1.open("bank1.txt",ios::app|ios::out);
            file>>id>>name>>fname>>pass>>phone>>balance;
            while(!file.eof())
            {
                if(a_id == id && amount <= balance)
                {
                balance -= amount;
                file1 << id << " " << name << " " << fname << " " << pass << " " << phone << " " << balance << "\n";
                found++;
                }
                else
                {
                    file1 << id << " " << name << " " << fname << " " << pass << " " << phone << " " << balance << "/n";
                }
                file>>id>>name>>fname>>pass>>phone>>balance;
            }
            file.close();
            file1.close();
            remove("bank.txt");
            rename("bank1.txt", "bank.txt");

            if(found == 1)
            {
            GetSystemTime(&x);
            file.open("bill.txt",ios::app|ios::out);
            file<<a_id<<" "<<b_name<<" "<<amount<<" "<<x.wDay<<"/"<<x.wMonth<<"/"<<x.wYear;
            file.close();
            cout<< "\n\n\n\t\t\t\t\t\t "<< b_name <<" Bill Payed Successfully ";
            }
            else
            {
                cout<<" \n\n\n\t\t\t\t\t\t Insufficient Amount ";
            }
        }
}
void bank::edit()
{
    system("cls");
    string a_id,n,f,pa,ph;
    int found=0;
    fstream file, file1;
    cout<<" \n\n\n\t\t\t\t\t\t UPDATE USER RECORD ";
    file.open("bank.txt",ios::in);
    if(!file)
    {
        cout<<" \n\n\n\t\t\t\t\t\t File Opening Error";
    }
    else
    {
        cout<<"\n\n Enter the ID: ";
        cin>>a_id;
        file1.open("bank1.txt",ios::app|ios::out);
        file>>id>>name>>fname>>pass>>phone>>balance;
            while(!file.eof())
            {
                if(a_id == id)
                {
                cout<<" Name: ";
                cin>>n;
                cout<< " Father Name: ";
                cin>>f;
                cout<< " Password: ";
                cin>>pa;
                cout<< " Phone No.: ";
                cin>>ph;
                     file1 << id << " " << n << " " << f << " " << pa << " " << ph << " " << balance << "\n";
                     cout<<"\n\n\n\t\t\t\t\t\t Record Updated Successfully " ;
                     found++;
                }
                else
                {
                    file1 << id << " " << name << " " << fname << " " << pass << " " << phone << " " << balance << "\n";
                }
                file>>id>>name>>fname>>pass>>phone>>balance;
            }
            file.close();
            file1.close();
            remove("bank.txt");
            rename("bank1.txt", "bank.txt");
            if(found==0)
                cout<<"\n\n User ID Can't Found ";
    }
}
void bank::del()
{
    system("cls");
    string a_id;
    int found=0;
    fstream file, file1;
    cout<<" \n\n\n\t\t\t\t\t\t DELETE RECORD ";
    file.open("bank.txt",ios::in);
    if(!file)
    {
        cout<<" \n\n\n\t\t\t\t\t\t File Opening Error";
    }
    else
    {
        cout<<"\n\n Enter the ID: ";
        cin>>a_id;
        file1.open("bank1.txt",ios::app|ios::out);
        file>>id>>name>>fname>>pass>>phone>>balance;
            while(!file.eof())
            {
                if(a_id == id)
                {
                    cout<<"\n\n\n\t\t\t\t\t\t Record Deleted Successfully  " ;
                    found++;
                }
                else
                {
                    file1 << id << " " << name << " " << fname << " " << pass << " " << phone << " " << balance << "\n";
                }
                file>>id>>name>>fname>>pass>>phone>>balance;
            }
            file.close();
            file1.close();
            remove("bank.txt");
            rename("bank1.txt", "bank.txt");
            if(found==0)
                cout<<"\n\n User ID Can't Found ";
    }
}
main()
{
    bank obj;
    obj.menu();
}
