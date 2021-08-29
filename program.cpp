#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;
struct item
{
    char item_name[30];
    float amount;
};
struct menu
{
    char food_name[30];
    float  price;
    item ingridient[3];
};

int menu_manup()
{
    menu *food= new menu[3];
    int n=3;
    goto C;
    A: cout<<"FOOD NAME\t\t\tPRICE\t\t\tINGRIDEINT";
        for(int i=0;i<n;i++)
            cout<<food[i]->food_name<<"\t\t"<<food[i]->price<<"\t\t"<<food[i]->ingridient;
    cout << "\n\n\n\n**************************************************************************************\n";
    cout << "*                 PRESS \'R\' TO RETURN AND \'E\' TO EXIT                                *\n";
    cout << "**************************************************************************************\n";
    char v;
    cin >> v;
    if (v == 'r' || v == 'R')
    {
        system("cls");
        goto C;
    }
    B:cout << "CHOOSE YOUR PREFFERED ACTION\n";
    cout << "**************************************************************************************\n";
    cout << "*                        A) ADD CONTENT                                              *\n";
    cout << "**************************************************************************************\n";
    cout << "**************************************************************************************\n";
    cout << "*                        B) DELETE CONTENT                                           *\n";
    cout << "**************************************************************************************\n";
    switch (v)
    {
    case 'A':
        system("cls");
        goto BA;
    case 'a':
        system("cls");
        goto BA;
        break;
    case 'B':
        system("cls");
        goto BB;
    case 'b':
        system("cls");
        goto BB;
        break;
    }

    BA:aray()
     
     
     
     
     C:cout << "CHOOSE YOUR PREFFERED ACTION\n";

    cout << "**************************************************************************************\n";
    cout << "*                        A) DISPLAY MENU                                             *\n";
    cout << "**************************************************************************************\n";
    cout << "**************************************************************************************\n";
    cout << "*                        B) EDIT MENU                                                *\n";
    cout << "**************************************************************************************\n";
    switch (v)
    {
    case 'A':
        system("cls");
        goto A;
    case 'a':
        system("cls");
        goto A;
        break;
    case 'B':
        system("cls");
        goto B;
    case 'b':
        system("cls");
        goto B;
        break;
    }
}



int main()
{
     cout<<"Hello World";
}