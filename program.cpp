#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
struct ingridient
{
    string item_name;
    float amount;
};
struct menu
{
    int food_id;
    string food_name;
    float price;
    int g;
};
int num = 0, q, la = 0;
ingridient **recipe = new ingridient *[la];
menu *food = new menu[num];
void display_menu(int);
void menu_edit();
int m_loop_func();
void m_aray_add(int n)
{
    if (n == -1)
    {
        n = n + num;
        num = n;
    }
    else
        n = n + num;
    menu *ptr1 = new menu[n];
    for (int i = 0; i < num; i++)
    {
        ptr1[i] = food[i];
    }
    delete[] food;
    food = ptr1;
    ptr1 = 0;
    q = num;
    num = n;
}
void r_aray_add(int n)
{
    n = n + la;
    ingridient **ptr1 = new ingridient *[n];
    for (int i = 0; i < la; i++)
        ptr1[i] = new ingridient[food[i].g];
    for (int i = 0; i < la; i++)
    {
        for (int j = 0; j < food[i].g; j++)
            ptr1[i][j] = recipe[i][j];
    }
    for (int i = 0; i < la; i++) //edit when combine
        delete[] recipe[i];

    delete[] recipe;
    recipe = ptr1;
    ptr1 = 0;
    la = n;
}
void m_aray_del(int n)
{
    delete[] recipe[n - 1];
    for (int i = n; i < num; i++)
    {
        food[i].food_id--;
        recipe[i - 1] = recipe[i];
        food[i - 1] = food[i];
    }
    la = num - 1;
    recipe[la] = 0;
    delete recipe[num - 1];
    m_aray_add(-1);
}
void m_aray_update(int n)
{
    cout << "CHOOSE YOUR PREFFERED ACTION\n";
    cout << "**************************************************************************************\n";
    cout << "*                        A) UPDATE NAME                                              *\n";
    cout << "**************************************************************************************\n";
    cout << "**************************************************************************************\n";
    cout << "*                        B) UPDATE PRICE                                             *\n";
    cout << "**************************************************************************************\n";
    char v;
    cin >> v;
    switch (tolower(v))
    {
    case 'a':
        cout << "ENTER UPDATED NAME: ";
        cin.ignore(80, '\n');
        getline(cin, (food[n - 1].food_name));
        break;
    case 'b':
        cout << "ENTER UPDATED PRICE: ";
        cin >> food[n - 1].price;
        break;
    }
}
void menu_func()
{
    cout << "CHOOSE YOUR PREFFERED ACTION\n";
    cout << "**************************************************************************************\n";
    cout << "*                        A) DISPLAY MENU                                             *\n";
    cout << "**************************************************************************************\n";
    cout << "**************************************************************************************\n";
    cout << "*                        B) EDIT MENU                                                *\n";
    cout << "**************************************************************************************\n";
    char v;
    cin >> v;
    switch (tolower(v))
    {
    case 'a':
        system("cls");
        display_menu(0);
        break;
    case 'b':
        system("cls");
        menu_edit();
        break;
    case 'c':
        system("cls");
        cout << num;
        m_loop_func();
        break;
    }
}

void display_menu(int a)
{
    if (num != 0)
    {
        cout << "\t\t\t\t\t\t    MENU\n";
        cout << "________________________________________________________________________________________________________________________\n";
        cout << "........................................................................................................................\n";
        cout << "ID\tFOOD NAME\t\tFOOD PRICE\t\tCONTENTS\n";
        cout << "........................................................................................................................\n";
        cout << "________________________________________________________________________________________________________________________\n";
        for (int i = 0; i < num; i++)
        {
            cout << food[i].food_id << "\t" << setw(10) << food[i].food_name << "\t\t" << setw(10) << food[i].price << "\t\t";
            for (int j = 0; j < food[i].g; j++)
                cout << recipe[i][j].item_name << " (" << recipe[i][j].amount << ") , ";
            cout << endl
                 << "------------------------------------------------------------------------------------------------------------------------\n";
        }
    }
    else
    {
        cout << "NO DATA HAS BEEN ENTERED";
        m_loop_func();
    }
    switch (a)
    {
    case 0:
        m_loop_func();
        break;
    case 1:
        int n;
        cout << "ENTER THE ID OF THE CONTENT YOU WISH TO DELETE: ";
        cin >> n;
        if ((n > 0) && (n <= num))
        {
            m_aray_del(n);
            m_loop_func();
        }
        else
        {
            cout << "ID NOT FOUND";
            m_loop_func();
        }
        break;
    case 2:
        int m;
        cout << "ENTER THE ID OF THE CONTENT YOU WISH TO UPDATE: ";
        cin >> m;
        if ((m > 0) && (m <= num))
        {
            m_aray_update(m);
            m_loop_func();
        }
        else
        {
            cout << "ID NOT FOUND";
            m_loop_func();
        }
        break;
    }
}

void menu_edit()
{
    cout << "CHOOSE YOUR PREFFERED ACTION\n";
    cout << "**************************************************************************************\n";
    cout << "*                        A) ADD CONTENT                                              *\n";
    cout << "**************************************************************************************\n";
    cout << "**************************************************************************************\n";
    cout << "*                        B) DELETE CONTENT                                           *\n";
    cout << "**************************************************************************************\n";
    cout << "**************************************************************************************\n";
    cout << "*                        C) UPDATE CONTENT                                           *\n";
    cout << "**************************************************************************************\n";
    char v;
    cin >> v;
    switch (tolower(v))
    {
    case 'a':
        system("cls");
        goto A;
        break;
    case 'b':
        system("cls");
        display_menu(1);
        break;
    case 'c':
        system("cls");
        display_menu(2);
        break;
    }

A:
    int n;
    cout << "ENTER THE AMOUNT OF CONTENT YOU WISH TO ADD: ";
    cin >> n;
    m_aray_add(n);
    r_aray_add(n);
    for (int i = q; i < (q + n); i++)
    {
        cin.ignore(80, '\n');
        food[i].food_id = i + 1;
        cout << "ENTER THE NAME OF THE FOOD " << food[i].food_id << " : ";
        getline(cin, food[i].food_name);
        cout << "ENTER THE PRICE OF THE FOOD " << food[i].food_id << "  : ";
        cin >> food[i].price;
        cout << "ENTER THE NUMBER OF INGRIDIENTS: ";
        cin >> food[i].g;

        recipe[i] = new ingridient[food[i].g];
        for (int j = 0; j < (food[i].g); j++)
        {
            cout << "ENTER INGRIDIENTS " << j + 1 << " : ";
            cin >> recipe[i][j].item_name;
            cout << "ENTER INGRIDIENTS AMOUNT " << j + 1 << " : ";
            cin >> recipe[i][j].amount;
        }
    }
    m_loop_func();
}
int m_loop_func()
{
    cout << "\n\n\n\n**************************************************************************************\n";
    cout << "*                 PRESS \'R\'  RETURN TO ANY KEY AND TO EXIT                             *\n";
    cout << "**************************************************************************************\n";
    char v;
    cin >> v;
    if (tolower(v) == 'r')
    {
        system("cls");
        menu_func();
    }
    else
        exit(0);
}

int main()
{
    system("color f0");
    menu_func();
}
