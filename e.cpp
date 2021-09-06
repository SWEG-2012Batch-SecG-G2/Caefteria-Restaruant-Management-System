#include<iostream>
#include<iomanip>
#include<string>
using namespace std;
struct employee
{   int id;
    string full_name;
    float salary;
};

int num=0,quant;
employee *waiter=new employee[num];
void displaylist(int);
void editlist();
int loop();
void aray_add(int n)
{   n=n+num;
    employee *ptr=new employee[n];
    for(int i=0;i<num;i++)
    {
        ptr[i]=waiter[i];
    }
    delete []waiter;
    waiter=ptr;
    ptr=0;
    quant=num;
    num=n;
}
void aray_del(int n)
{
    for(int i=n;i<num;i++)
    {   waiter[i].id--;
        waiter[i-1]=waiter[i];
    }
     num--;
    employee *ptr=new employee[num];
    for(int i=0;i<num;i++)
    {
        ptr[i]=waiter[i];
    }
    delete []waiter;
    waiter=ptr;
    ptr=0;
    quant=num;
}
void aray_update(int n)
{
    cout << "CHOOSE YOUR PREFFERED ACTION\n";
    cout << "**************************************************************************************\n";
    cout << "*                        A) UPDATE NAME                                              *\n";
    cout << "**************************************************************************************\n";
    cout << "**************************************************************************************\n";
    cout << "*                        B) UPDATE SALARY                                            *\n";
    cout << "**************************************************************************************\n";
    char v;
    cin>>v;
    switch (tolower(v))
    {
        case 'a':cout<<"ENTER UPDATED NAME: ";
        cin.ignore (80, '\n');
        getline(cin,(waiter[n-1].full_name));
        break;
        case 'b':cout<<"ENTER UPDATED SALARY: ";
        cin>>waiter[n-1].salary;
        break;

    }
}
void employee_func()
{
    cout << "CHOOSE YOUR PREFFERED ACTION\n";
    cout << "**************************************************************************************\n";
    cout << "*                        A) DISPLAY EMPLOYEE LIST                                    *\n";
    cout << "**************************************************************************************\n";
    cout << "**************************************************************************************\n";
    cout << "*                        B) EDIT EMPLOYEE LIST                                       *\n";
    cout << "**************************************************************************************\n";
    char v;
    cin>>v;
    switch (tolower(v))
    {
    case 'a':
        system("cls");
       displaylist(0);
        break;
    case 'b':
        system("cls");
      editlist();
        break;
    }
}

void displaylist(int a)
{  if(num!=0)
   {
    cout<<"___________________________________________________\n";
    cout<<"...................................................\n";
    cout<<"ID\tFULL NAME\t\tSALARY\n";
    cout<<"...................................................\n";
    cout<<"___________________________________________________\n";
    for(int i=0;i<num;i++)
        {cout<<waiter[i].id<<"\t"<<setw(10)<<waiter[i].full_name<<"\t\t"<<setw(7)<<waiter[i].salary<<"\t\t";
        cout<<endl<<"---------------------------------------------------\n";
        }
    }
    else
     {cout<<"NO DATA HAS BEEN ENTERED";
       loop();
     }
     switch(a)
     {
         case 0:  loop();break;
         case 1:
            int n;
            cout<<"ENTER THE ID OF THE EMPLOYEE YOU WISH TO REMOVE: ";
            cin>>n;
            if((n>0)&&(n<=num))
           {
               aray_del(n);
               loop();
           }
            else
            {
                cout<<"ID NOT FOUND";
                loop();
            }
            break;
            case 2:
            int m;
            cout<<"ENTER THE ID OF THE CONTENT YOU WISH TO UPDATE: ";
            cin>>m;
            if((m>0)&&(m<=num))
           {
               aray_update(m);
               loop();
           }
            else
            {
                cout<<"ID NOT FOUND";
                loop();
            }
            break;
     }
}

void editlist()
{
    cout << "CHOOSE YOUR PREFFERED ACTION\n";
    cout << "**************************************************************************************\n";
    cout << "*                        A) ADD EMPLOYEE                                             *\n";
    cout << "**************************************************************************************\n";
    cout << "**************************************************************************************\n";
    cout << "*                        B) DELETE EMPLOYEE                                          *\n";
    cout << "**************************************************************************************\n";
    cout << "**************************************************************************************\n";
    cout << "*                        C) UPDATE EMPLOYEE LIST                                     *\n";
    cout << "**************************************************************************************\n";
    char v;
    cin>>v;
    switch (tolower(v))
    {
    case 'a':
        system("cls");
        goto A;
        break;
    case 'b':
        system("cls");
        displaylist(1);
        break;
    case 'c':
        system("cls");
        displaylist(2);
        break;}

    A: int n;
    cout<<"ENTER THE NUMBER OF MEMBERS YOU WISH TO ADD TO THE EMPLOYEE LIST: ";
    cin>>n;
    aray_add(n);
    for(int i=quant;i<(quant+n);i++)
    {
    cin.ignore (80, '\n');
    waiter[i].id=i+1;
    cout<<"ENTER FULL NAME OF MEMBER "<<waiter[i].id<<" : ";
    getline(cin,waiter[i].full_name);
    cout<<"ENTER THE SALARY OF MEMBER "<<waiter[i].id<<"  : ";cin>>waiter[i].salary;
    }
    loop();
}
int loop()
{
   cout << "\n\n\n\n**************************************************************************************\n";
    cout << "*                 PRESS \'R\'  RETURN TO ANY KEY AND TO EXIT                             *\n";
    cout << "**************************************************************************************\n";
    char v;
    cin >> v;
    if (tolower(v) == 'r')
    {
        system("cls");
        employee_func();
    }
    else
     exit(0);
}

int main()
{
     system("color f0");
      employee_func();
}

