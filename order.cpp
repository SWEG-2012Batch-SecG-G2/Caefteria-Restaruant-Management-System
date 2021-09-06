#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
string password = "0000"; //THIS IS THE PASSWORD THAT IS USED TO PROTECT THE ADMINSTRATION OPTIONS(CAN BE CHANGED IN PROGRAM)
string name = "KK";       //THE NAME OF THE CAFETERIA(CAN BE CHANGED IN PROGRAM)

struct stock //STRUCTURE OF THE INVENTORY ITEMS
{
    int id;
    string item_name;
    float amount;
    string unit;
    float cost;
    float w_amount;
};
struct menu //STRUCTURE OF THE MENU CINTENTS
{
    int food_id;
    string food_name;
    float price;
    int g;
};
struct date //DATE DEFINING STRUCTURE
{
    unsigned short int dd, mm, yy;
};
struct employee //EMPLOYEE DESCRIBING STRUCTURE
{
    int id;
    string full_name;
    float salary;
};
struct address //ADDRESS HOLDING STRUCTUR
{
    string city, subcity, town, h_no;
    float amount;
};
struct order_info //STRUCTURE THAT DESCRIBES EVERYTHING ABOUT A SINGL ORDER
{
    date doo;
    employee woo;
    string type;
    address aoo;
    int no;
    int prepaid;
    float total;
};
int num = 0, q, s_num = 0, s_q, o_num = 0, o_q, e_num = 0, e_q; //VARIABLES: THOSE THAT END WITH 'Q' DEFINE THE CURRENT QUANTITY OF THE ENTITY WHILE THOSE THAT END WITH 'NUM' DESCRIBES ITS QUATITY
//STRUCTURES AND ARRAYS USED
order_info *info = new order_info[o_num];
menu **order = new menu *[o_num];
stock **recipe = new stock *[num];
menu *food = new menu[num];
stock *ingridient = new stock[s_num];
employee *waiter = new employee[e_num];
//PROTOTYPES
void introduction();
void home_page();
void catalog();
int gett();
float getf();
void m_aray_add(int);
void m_aray_del(int);
void m_aray_update(int);
void menu_func();
void menu_edit();
void display_menu(int);
void s_aray_add(int);
void s_aray_del(int);
void s_aray_update(int);
void stock_func();
void s_list_edit();
void display_s_list(int, int);
void e_aray_add(int);
void e_aray_del(int);
void e_aray_update(int);
void employee_func();
void display_e_list(int);
void e_list_edit();
void reciepe_func(int);
void o_aray_add(int);
void add_order();
void eoo_func();
void sales_report(int);
void sales_func();
void profit();
void e_sales_report();
void menu_order();
void return_func();
void return_empl();
void intialize();
//FUCTIONS
int main()
{
    system("color f0");
    intialize();
    introduction();
    home_page();
}
void introduction() //FRONT PAGE
{
    cout << endl
         << endl
         << endl
         << endl
         << endl;
    cout << "                        =========================================================================" << endl;
    cout << "                        -------------------------------------------------------------------------" << endl;
    cout << "                        ************* WELCOME TO " << name << " CAFETERIA M A N A G E M E N T **************" << endl;
    cout << "                        -------------------------------------------------------------------------" << endl;
    cout << "                        ***************************   S Y S T E M   *****************************" << endl;
    cout << "                        -------------------------------------------------------------------------" << endl;

    cout << "                        =========================================================================\n\n\n\n\n"
         << endl;
    system("pause");
    system("cls");
}
void home_page() //HOME PAGE: ALLOWS YOU TO CHOOSE BETWEEN PLACING AN ORDER AND ADMINSTRATION
{
    cout << "---------------------------------------------------------------------------------------" << endl;
    cout << "*************   " << name << " C A F T E R I A   M A N A G E M E N T  S Y S T E M   A***************" << endl;
    cout << "---------------------------------------------------------------------------------------" << endl;
    cout << "CHOOSE YOUR PREFFERED ACTION\n";
    cout << "**************************************************************************************\n";
    cout << "*                        A) PLACE AN ORDER                                           *\n";
    cout << "**************************************************************************************\n";
    cout << "**************************************************************************************\n";
    cout << "*                        B) ADMINSTRATION OPTIONS                                    *\n";
    cout << "**************************************************************************************\n";
    char u;
D:
    cin >> u;
    string p, q;
    switch (tolower(u))
    {
    case 'a':
        system("cls");
        add_order();
        break;
    case 'b':
        system("cls");
        cout << "ENTER THE PASSCODE: ";
        cin >> p;
        if (p == password)
        {
            system("cls");
            goto A;
        }
        else
        {
            cout << "WRONG PASSWORD";
            return_func();
        }
        break;
    default:
        cout << "INVALID ENTRY, TRY AGAIN";
        goto D;
    }

A:
    for (int i = 0; i < s_num; i++)
    {
        if (ingridient[i].amount <= ingridient[i].w_amount)
        {
            cout << "**************************************************************************************\n";
            cout << "*            THE VALUE OF " << ingridient[i].item_name << " IS LOW PLEASE REORDER         \n";
            cout << "**************************************************************************************\n";
        }
    }
    cout << "\n\nCHOOSE YOUR PREFFERED ACTION\n";
    cout << "**************************************************************************************\n";
    cout << "*                        A) MENU SETTINGS                                            *\n";
    cout << "**************************************************************************************\n";
    cout << "**************************************************************************************\n";
    cout << "*                        B) INVENTORY SETTINGS                                       *\n";
    cout << "**************************************************************************************\n";
    cout << "**************************************************************************************\n";
    cout << "*                        C) EMPLOYEE SETTINGS                                        *\n";
    cout << "**************************************************************************************\n";
    cout << "**************************************************************************************\n";
    cout << "*                        D) SALES REPORT                                             *\n";
    cout << "**************************************************************************************\n";
    cout << "**************************************************************************************\n";
    cout << "*                        E) CALCULATE MONTHLY PROFIT                                 *\n";
    cout << "**************************************************************************************\n";
    cout << "**************************************************************************************\n";
    cout << "*                        F) CHANGE PASSWORD                                          *\n";
    cout << "**************************************************************************************\n";
    cout << "**************************************************************************************\n";
    cout << "*                        G) CHANGE NAME OF THE CAFETERIA                             *\n";
    cout << "**************************************************************************************\n";
    char v;
E:
    cin >> v;
    switch (tolower(v))
    {
    case 'a':
        system("cls");
        menu_func();
        break;
    case 'b':
        system("cls");
        stock_func();
        break;
    case 'c':
        system("cls");
        employee_func();
        break;
    case 'd':
        system("cls");
        sales_func();
        break;
    case 'e':
        system("cls");
        profit();
        break;
    case 'f':
        system("cls");
        cout << "ENTER THE OLD PASSWORD: ";
        cin >> q;
        if (q == password)
        {
            cout << "ENTER NEW PASSWORD: ";
            cin >> password;
        }
        else
            cout << "WRONG PASSWORD!";
        return_func();
        break;
    case 'g':
        system("cls");
        cout << "ENTER PASSWORD: ";
        cin >> q;
        if (q == password)
        {
            cout << "ENTER NEW NAME OF THE CAFTERIA: ";
            cin >> name;
        }
        else
            cout << "WRONG PASSWORD!";
        return_func();
        break;
    default:
        cout << "INVALID ENTRY, TRY AGAIN";
        goto E;
    }
}
void catalog() //GIVES YOU A QUICK MENU OPTION
{
    cout << "CHOOSE YOUR PREFFERED LOCATION\n";
    cout << "**************************************************************************************\n";
    cout << "*                        H) HOME PAGE                                                *\n";
    cout << "**************************************************************************************\n";
    cout << "**************************************************************************************\n";
    cout << "*                        E) EXIT                                                     *\n";
    cout << "**************************************************************************************\n";
    cout << "**************************************************************************************\n";
    cout << "*                        A) MENU SETTINGS                                            *\n";
    cout << "**************************************************************************************\n";
    cout << "**************************************************************************************\n";
    cout << "*                        B) INVENTORY SETTINGS                                       *\n";
    cout << "**************************************************************************************\n";
    cout << "**************************************************************************************\n";
    cout << "*                        C) EMPLOYEE SETTINGS                                        *\n";
    cout << "**************************************************************************************\n";
    cout << "**************************************************************************************\n";
    cout << "*                        D) SALES REPORT                                             *\n";
    cout << "**************************************************************************************\n";
    cout << "**************************************************************************************\n";
    cout << "*                        F) CALCULATE MONTTHLY PROFIT                                *\n";
    cout << "**************************************************************************************\n";
    char v;
D:
    cin >> v;
    switch (tolower(v))
    {
    case 'h':
        system("cls");
        home_page();
        break;
    case 'e':
        exit(0);
    case 'a':
        system("cls");
        menu_func();
        break;
    case 'b':
        system("cls");
        stock_func();
        break;
    case 'c':
        system("cls");
        employee_func();
        break;
    case 'd':
        system("cls");
        sales_func();
        break;
    case 'f':
        system("cls");
        profit();
        break;
    default:
        cout << "INVALID ENTRY, TRY AGAIN";
        goto D;
    }
}
int gett()
{ //FOR INPUT VALIDATION OF INT
    int choice;
    cin >> choice;
    while (!cin.good())
    {
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        //Invalid input trial
        cout << "INVALID INPUT, TRY AGAIN: ";
        cin >> choice;
    }
    return choice;
}
float getf()
{ //FOR INPUT VALIDATION OF FLOAT
    float choice;
    cin >> choice;
    while (!cin.good())
    {
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        //Invalid input trial
        cout << "INVALID INPUT, TRY AGAIN: ";
        cin >> choice;
    }
    return choice;
}
void m_aray_add(int n) //ADDS SIZE OF THE MENU ARRAY
{
    n = n + num;
    menu *ptr1 = new menu[n];
    stock **ptr2 = new stock *[n];
    for (int i = 0; i < num; i++)
        ptr2[i] = new stock[food[i].g];
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < food[i].g; j++)
            ptr2[i][j] = recipe[i][j];
    }
    for (int i = 0; i < num; i++)
        delete[] recipe[i];

    delete[] recipe;
    recipe = ptr2;
    ptr2 = 0;
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
void m_aray_del(int n) //DELETES MEMBERS FROM THE MENU ARRAY
{
    delete[] recipe[n - 1];
    for (int i = n; i < num; i++)
    {
        food[i].food_id--;
        recipe[i - 1] = recipe[i];
        food[i - 1] = food[i];
    }
    num--;
    recipe[num] = 0;
    delete recipe[num];
    menu *ptr1 = new menu[num];
    for (int i = 0; i < num; i++)
    {
        ptr1[i] = food[i];
    }
    delete[] food;
    food = ptr1;
    ptr1 = 0;
    q = num;
}
void m_aray_update(int n) //UPDATES MEMBERS FROM MENU ARRAY
{
    cout << "CHOOSE YOUR PREFFERED ACTION\n";
    cout << "**************************************************************************************\n";
    cout << "*                        A) UPDATE NAME                                              *\n";
    cout << "**************************************************************************************\n";
    cout << "**************************************************************************************\n";
    cout << "*                        B) UPDATE PRICE                                             *\n";
    cout << "**************************************************************************************\n";
    char v;
D:
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
        food[n - 1].price = getf();
        break;
    default:
        cout << "INVALID ENTRY, TRY AGAIN";
        goto D;
    }
}
void menu_func() //OPTION MENU FOR THE MENU FUNCTIONS
{
    cout << "CHOOSE YOUR PREFFERED ACTION\n";
    cout << "**************************************************************************************\n";
    cout << "*                        A) DISPLAY MENU                                             *\n";
    cout << "**************************************************************************************\n";
    cout << "**************************************************************************************\n";
    cout << "*                        B) EDIT MENU                                                *\n";
    cout << "**************************************************************************************\n";
    char v;

D:
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
    default:
        cout << "INVALID ENTRY, TRY AGAIN";
        goto D;
    }
}
void menu_edit() //ALLOWS US TO EDIT MEMBERS FROM THE MENU ARRAY
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
D:
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
    default:
        cout << "INVALID ENTRY, TRY AGAIN";
        goto D;
    }

A:
    int n;
    cout << "ENTER THE AMOUNT OF CONTENT YOU WISH TO ADD: ";
    n = gett();
    m_aray_add(n);
    for (int i = q; i < (q + n); i++)
    {
        cin.ignore(80, '\n');
        food[i].food_id = i + 1;
        cout << "ENTER THE NAME OF THE FOOD " << food[i].food_id << " : ";
        getline(cin, food[i].food_name);
        cout << "ENTER THE PRICE OF THE FOOD " << food[i].food_id << "  : ";
        food[i].price = getf();
        cout << "ENTER THE NUMBER OF INGRIDIENTS: ";
        food[i].g = gett();
        recipe[i] = new stock[food[i].g];
        display_s_list(3, i);
    }
    return_func();
}
void display_menu(int a) //DISPLAYS MEMBERS FROM THE MENU ARRAY
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
        return_func();
    }
    switch (a)
    {
    case 0:
        return_func();
        break;
    case 1:
        int n;
        cout << "ENTER THE ID OF THE CONTENT YOU WISH TO DELETE: ";
        cin >> n;
        if ((n > 0) && (n <= num))
        {
            m_aray_del(n);
            return_func();
        }
        else
        {
            cout << "ID NOT FOUND";
            return_func();
        }
        break;
    case 2:
        int m;
        cout << "ENTER THE ID OF THE CONTENT YOU WISH TO UPDATE: ";
        cin >> m;
        if ((m > 0) && (m <= num))
        {
            m_aray_update(m);
            return_func();
        }
        else
        {
            cout << "ID NOT FOUND";
            return_func();
        }
        break;
    case 3:
        menu_order();
        break;
    }
}
void s_aray_add(int n) //ADDS SIZE OF THE STOCK ARRAY
{
    n = n + s_num;
    stock *ptr1 = new stock[n];
    for (int i = 0; i < s_num; i++)
    {
        ptr1[i] = ingridient[i];
    }
    delete[] ingridient;
    ingridient = ptr1;
    ptr1 = 0;
    s_q = s_num;
    s_num = n;
}
void s_aray_del(int n) //DELETES MEMBERS FROM THE STOCK ARRAY
{
    for (int i = n; i < s_num; i++)
    {
        ingridient[i].id--;
        ingridient[i - 1] = ingridient[i];
    }
    s_num--;
    stock *ptr1 = new stock[s_num];
    for (int i = 0; i < s_num; i++)
    {
        ptr1[i] = ingridient[i];
    }
    delete[] ingridient;
    ingridient = ptr1;
    ptr1 = 0;
    s_q = s_num;
}
void s_aray_update(int n) //UPDATES MEMBERS FROM STOCK ARRAY
{
    cout << "CHOOSE YOUR PREFFERED ACTION\n";
    cout << "**************************************************************************************\n";
    cout << "*                        A) UPDATE ITEM NAME                                         *\n";
    cout << "**************************************************************************************\n";
    cout << "**************************************************************************************\n";
    cout << "*                        B) UPDATE ITEM QUANTITY AMOUNT                              *\n";
    cout << "**************************************************************************************\n";
    cout << "**************************************************************************************\n";
    cout << "*                        C) UPDATE ITEM PRICE PER UNIT                               *\n";
    cout << "**************************************************************************************\n";
    cout << "**************************************************************************************\n";
    cout << "*                        D) UPDATE UNIT OF MEASUREMENT                               *\n";
    cout << "**************************************************************************************\n";
    char v;
D:
    cin >> v;
    switch (tolower(v))
    {
    case 'a':
        cout << "ENTER UPDATED ITEM NAME: ";
        cin.ignore(80, '\n');
        getline(cin, (ingridient[n - 1].item_name));
        break;
    case 'b':
        cout << "ENTER UPDATED QUANTITY AMOUNT: ";
        ingridient[n - 1].amount = getf();
        break;
    case 'c':
        cout << "ENTER UPDATED PRICE PER UNIT: ";
        ingridient[n - 1].cost = getf();
        break;
    case 'd':
        cout << "ENTER UPDATED UNIT OF MEASUREMENT: ";
        cin.ignore(80, '\n');
        getline(cin, (ingridient[n - 1].unit));
        break;
    default:
        cout << "INVALID ENTRY, TRY AGAIN";
        goto D;
    }
}
void stock_func() //OPTION MENU FOR THE STOCK FUNCTIONS
{
    cout << "CHOOSE YOUR PREFFERED ACTION\n";
    cout << "**************************************************************************************\n";
    cout << "*                        A) DISPLAY INVENTORY LIST                                   *\n";
    cout << "**************************************************************************************\n";
    cout << "**************************************************************************************\n";
    cout << "*                        B) EDIT INVENTORY LIST                                      *\n";
    cout << "**************************************************************************************\n";
    char v;
D:
    cin >> v;
    switch (tolower(v))
    {
    case 'a':
        system("cls");
        display_s_list(0, 0);
        break;
    case 'b':
        system("cls");
        s_list_edit();
        break;
    default:
        cout << "INVALID ENTRY, TRY AGAIN";
        goto D;
    }
}
void s_list_edit() //ALLOWS US TO EDIT MEMBERS FROM THE STOCK ARRAY
{
    cout << "CHOOSE YOUR PREFFERED ACTION\n";
    cout << "**************************************************************************************\n";
    cout << "*                        A) ADD ITEMS TO THE LIST                                    *\n";
    cout << "**************************************************************************************\n";
    cout << "**************************************************************************************\n";
    cout << "*                        B) DELETE ITEMS FROM THE LIST                               *\n";
    cout << "**************************************************************************************\n";
    cout << "**************************************************************************************\n";
    cout << "*                        C) UPDATE THE LIST                                          *\n";
    cout << "**************************************************************************************\n";
    char v;
D:
    cin >> v;
    switch (tolower(v))
    {
    case 'a':
        system("cls");
        goto A;
        break;
    case 'b':
        system("cls");
        display_s_list(1, 0);
        break;
    case 'c':
        system("cls");
        display_s_list(2, 0);
        break;
    default:
        cout << "INVALID ENTRY, TRY AGAIN";
        goto D;
    }

A:
    int n;
    cout << "ENTER THE NUMBER OF ITEMS YOU WISH TO ADD TO THE INVENTORY LIST: ";
    n = gett();
    s_aray_add(n);
    for (int i = s_q; i < (s_q + n); i++)
    {
        cin.ignore(80, '\n');
        ingridient[i].id = i + 1;
        cout << "ENTER NAME OF ITEM " << ingridient[i].id << " : ";
        getline(cin, ingridient[i].item_name);
        cout << "ENTER UNIT OF ITEM " << ingridient[i].id << " : ";
        getline(cin, ingridient[i].unit);
        cout << "ENTER THE AMOUNT OF ITEM " << ingridient[i].id << " (ACCORDING TO THE CHOSEN UNIT) : ";
        ingridient[i].amount = getf();
        cout << "ENTER THE PRICE PER UNIT OF ITEM " << ingridient[i].id << "  : ";
        ingridient[i].cost = getf();
        cout << "ENTER THE \'GET LOW\' WARNING AMOUNT ITEM " << ingridient[i].id << "  : ";
        ingridient[i].w_amount = getf();
    }
    return_func();
}
void display_s_list(int a, int b) //DISPLAYS MEMBERS FROM THE MENU ARRAY
{
    if (s_num != 0)
    {
        cout << "\t\t\t   STOCK\n";
        cout << "______________________________________________________________________\n";
        cout << "......................................................................\n";
        cout << "ID\tITEM NAME\t\tAMOUNT(UNIT)\t\tPRICE PER UNIT\n";
        cout << "......................................................................\n";
        cout << "______________________________________________________________________\n";
        for (int i = 0; i < s_num; i++)
        {
            cout << ingridient[i].id << "\t" << setw(10) << ingridient[i].item_name << "\t\t" << setw(7) << ingridient[i].amount << " (" << ingridient[i].unit << ")"
                 << "\t\t" << setw(14) << ingridient[i].cost;
            cout << endl
                 << "----------------------------------------------------------------------\n";
        }
    }
    else
    {
        cout << "NO DATA HAS BEEN ENTERED";
        return_func();
    }
    switch (a)
    {
    case 0:
        return_func();
        break;
    case 1:
        int n;
        cout << "ENTER THE ID OF THE ITEM YOU WISH TO REMOVE: ";
        cin >> n;
        if ((n > 0) && (n <= s_num))
        {
            s_aray_del(n);
            return_func();
        }
        else
        {
            cout << "ID NOT FOUND";
            return_func();
        }
        break;
    case 2:
        int m;
        cout << "ENTER THE ID OF THE CONTENT YOU WISH TO UPDATE: ";
        cin >> m;
        if ((m > 0) && (m <= s_num))
        {
            s_aray_update(m);
            return_func();
        }
        else
        {
            cout << "ID NOT FOUND";
            return_func();
        }
        break;
    case 3:
        reciepe_func(b);
        break;
    }
}
void e_aray_add(int n) //ADDS SIZE OF THE EMPLOYEE ARRAY
{
    n = n + e_num;
    employee *ptr1 = new employee[n];
    for (int i = 0; i < e_num; i++)
    {
        ptr1[i] = waiter[i];
    }
    delete[] waiter;
    waiter = ptr1;
    ptr1 = 0;
    e_q = e_num;
    e_num = n;
}
void e_aray_del(int n) //DELETES MEMBERS FROM THE EMPLOYEE ARRAY
{
    for (int i = n; i < e_num; i++)
    {
        waiter[i].id--;
        waiter[i - 1] = waiter[i];
    }
    e_num--;
    employee *ptr1 = new employee[e_num];
    for (int i = 0; i < e_num; i++)
    {
        ptr1[i] = waiter[i];
    }
    delete[] waiter;
    waiter = ptr1;
    ptr1 = 0;
    e_q = e_num;
}
void e_aray_update(int n) //UPDATES MEMBERS FROM EMPLOYEE ARRAY
{
    cout << "CHOOSE YOUR PREFFERED ACTION\n";
    cout << "**************************************************************************************\n";
    cout << "*                        A) UPDATE NAME                                              *\n";
    cout << "**************************************************************************************\n";
    cout << "**************************************************************************************\n";
    cout << "*                        B) UPDATE SALARY                                            *\n";
    cout << "**************************************************************************************\n";
    char v;
D:
    cin >> v;
    switch (tolower(v))
    {
    case 'a':
        cout << "ENTER UPDATED NAME: ";
        cin.ignore(80, '\n');
        getline(cin, (waiter[n - 1].full_name));
        break;
    case 'b':
        cout << "ENTER UPDATED SALARY: ";
        waiter[n - 1].salary = getf();
        break;
    default:
        cout << "INVALID ENTRY, TRY AGAIN";
        goto D;
    }
}
void employee_func() //OPTION MENU FOR THE EMPLOYEE FUNCTIONS
{
    cout << "CHOOSE YOUR PREFFERED ACTION\n";
    cout << "**************************************************************************************\n";
    cout << "*                        A) DISPLAY EMPLOYEE LIST                                    *\n";
    cout << "**************************************************************************************\n";
    cout << "**************************************************************************************\n";
    cout << "*                        B) EDIT EMPLOYEE LIST                                       *\n";
    cout << "**************************************************************************************\n";
    char v;
D:
    cin >> v;
    switch (tolower(v))
    {
    case 'a':
        system("cls");
        display_e_list(0);
        break;
    case 'b':
        system("cls");
        e_list_edit();
        break;
    default:
        cout << "INVALID ENTRY, TRY AGAIN";
        goto D;
    }
}
void display_e_list(int a) //DISPLAYS MEMBERS FROM THE MENU ARRAY
{
    if (e_num != 0)
    {
        cout << "___________________________________________________\n";
        cout << "...................................................\n";
        cout << "ID\tFULL NAME\t\tSALARY\n";
        cout << "...................................................\n";
        cout << "___________________________________________________\n";
        for (int i = 0; i < e_num; i++)
        {
            cout << waiter[i].id << "\t" << setw(10) << waiter[i].full_name << "\t\t" << setw(7) << waiter[i].salary << "\t\t";
            cout << endl
                 << "---------------------------------------------------\n";
        }
    }
    else
    {
        cout << "NO DATA HAS BEEN ENTERED";
        return_func();
    }
    switch (a)
    {
    case 0:
        return_func();
        break;
    case 1:
        int n;
        cout << "ENTER THE ID OF THE EMPLOYEE YOU WISH TO REMOVE: ";
        cin >> n;
        if ((n > 0) && (n <= e_num))
        {
            e_aray_del(n);
            return_func();
        }
        else
        {
            cout << "ID NOT FOUND";
            return_func();
        }
        break;
    case 2:
        int m;
        cout << "ENTER THE ID OF THE CONTENT YOU WISH TO UPDATE: ";
        cin >> m;
        if ((m > 0) && (m <= e_num))
        {
            e_aray_update(m);
            return_func();
        }
        else
        {
            cout << "ID NOT FOUND";
            return_func();
        }
        break;
    case 3:
        eoo_func();
        break;
    case 4:
        e_sales_report();
        break;
    }
}
void e_list_edit() //ALLOWS US TO EDIT MEMBERS FROM THE EMPLOYEE ARRAY
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
D:
    cin >> v;
    switch (tolower(v))
    {
    case 'a':
        system("cls");
        goto A;
        break;
    case 'b':
        system("cls");
        display_e_list(1);
        break;
    case 'c':
        system("cls");
        display_e_list(2);
        break;
    default:
        cout << "INVALID ENTRY, TRY AGAIN";
        goto D;
    }

A:
    int n;
    cout << "ENTER THE NUMBER OF MEMBERS YOU WISH TO ADD TO THE EMPLOYEE LIST: ";
    n = gett();
    e_aray_add(n);
    for (int i = e_q; i < (e_q + n); i++)
    {
        cin.ignore(80, '\n');
        waiter[i].id = i + 1;
        cout << "ENTER FULL NAME OF MEMBER " << waiter[i].id << " : ";
        getline(cin, waiter[i].full_name);
        cout << "ENTER THE SALARY OF MEMBER " << waiter[i].id << "  : ";
        waiter[i].salary = getf();
    }
    return_func();
}
void reciepe_func(int i) //ALLOWS US TO ENTER THE CONTENT OF A PARTICULAR FOOD
{
    int m;

    for (int j = 0; j < (food[i].g); j++)
    {
    A:
        cout << "ENTER ID OF INGRIDIENT " << j + 1 << " FROM THE ABOVE LIST : ";
        cin >> m;
        if (m > 0 && m <= s_num)
        {
            recipe[i][j].item_name = ingridient[m - 1].item_name;
            recipe[i][j].unit = ingridient[m - 1].unit;
            recipe[i][j].cost = ingridient[m - 1].cost;
            cout << "ENTER THE AMOUNT INGRIDIENT " << j + 1 << " REQUIRED : ";
            recipe[i][j].amount = getf();
        }
        else
        {
            cout << "ID NOT FOUND\nENTER \'R\' TO TRY AGAIN OR ANY TO RETURN: \n";
            char v;
            cin >> v;
            switch (tolower(v))
            {
            case 'r':
                goto A;
                break;
            default:
                return_func();
                break;
            }
        }
    }
}
void o_aray_add() //ADDS SIZE OF THE ORDER ARRAY
{
    int n = 1 + o_num;
    order_info *ptr1 = new order_info[n];
    menu **ptr2 = new menu *[n];
    for (int i = 0; i < o_num; i++)
        ptr2[i] = new menu[info[i].no];
    for (int i = 0; i < o_num; i++)
    {
        for (int j = 0; j < info[i].no; j++)
            ptr2[i][j] = order[i][j];
    }
    for (int i = 0; i < o_num; i++)
        delete[] order[i];

    delete[] order;
    order = ptr2;
    ptr2 = 0;
    for (int i = 0; i < o_num; i++)
    {
        ptr1[i] = info[i];
    }
    delete[] info;
    info = ptr1;
    ptr1 = 0;
    o_q = o_num;
    o_num = n;
}
void eoo_func() //ALLOWS US TO ADD THE WAITER TAKING THE ORDER
{
    int m;
    cout << "ENTER THE ID OF WAITER TAKING THE ORDER: ";
    cin >> m;
    if (m > 0 && m <= e_num)
    {
        info[o_q].woo.full_name = waiter[m - 1].full_name;
        info[o_q].woo.id = waiter[m - 1].id;
    }
    else
    {
        cout << "NO ID FOUND ";
        return_empl();
    }
}
void menu_order() //THE FUNCTION THAT REGISTERS THE ORDER
{
    cout << endl
         << "HOW MANY FOOD WOULD  YOU LIKE TO ORDER: ";
    info[o_q].no = gett();
    order[o_q] = new menu[info[o_q].no];
    info[o_q].total = 0;
    for (int i = 0; i < info[o_q].no; i++)
    {
        int m;
        cout << "ENTER THE ID OF FOOD " << i + 1 << "OF YOUR ORDER: ";
        m = gett();
        order[o_q][i].food_id = food[m - 1].food_id;
        order[o_q][i].food_name = food[m - 1].food_name;
        order[o_q][i].g = food[m - 1].g;
        order[o_q][i].price = food[m - 1].price;
        info[o_q].total += order[o_q][i].price;
        for (int j = 0; j < food[m - 1].g; j++)
            for (int k = 0; k < s_num; k++)
                if (recipe[i][j].id == ingridient[k].id)
                    ingridient[k].amount -= recipe[i][j].amount;
    }
}
void add_order() //THE FUCTION THAT FACILITATES THE ORDER
{
    int n = 1;
    o_aray_add();
    display_e_list(3);
    system("cls");
    display_menu(3);
    system("cls");
    cout << "CHOOSE THE TYPE OF THE ORDER\n";
    cout << "**************************************************************************************\n";
    cout << "*                        A) INHOUSE ORDER                                            *\n";
    cout << "**************************************************************************************\n";
    cout << "**************************************************************************************\n";
    cout << "*                        B) REMOTE ORDER                                             *\n";
    cout << "**************************************************************************************\n";
    cout << "**************************************************************************************\n";
    cout << "*                        C) PREPAID ORDER                                            *\n";
    cout << "**************************************************************************************\n";
    char v;
D:
    cin >> v;
    switch (tolower(v))
    {
    case 'a':
        info[o_q].type = "IN HOUSE";
        info[o_q].aoo.amount = 0;
        break;
    case 'b':
        info[o_q].type = "REMOTE ORDER";
        cout << "ENTER THE CUSTEMERS LOCATION\nCITY: ";
        cin.ignore(80, '\n');
        getline(cin, info[o_q].aoo.city);
        cout << "SUB-CITY: ";
        getline(cin, info[o_q].aoo.subcity);
        cout << "TOWN: ";
        getline(cin, info[o_q].aoo.town);
        cout << "HOUSE NUMBER: ";
        getline(cin, info[o_q].aoo.h_no);
        cout << "ENTER THE COST OF DELIVERY: ";
        info[o_q].aoo.amount = getf();
        break;
    case 'c':
        info[o_q].type = "PREPAID";
        info[o_q].prepaid = n;
        n++;
        info[o_q].aoo.amount = 0;
        break;
    default:
        cout << "INVALID ENTRY, TRY AGAIN";
        goto D;
    }
    system("cls");
    cout << "ENTER THE DATE/MONTH/YEAR:\n";
    info[o_q].doo.dd = gett();
    info[o_q].doo.mm = gett();
    info[o_q].doo.yy = gett();
    cout << "THE ORDER IS:\n";
    for (int i = 0; i < info[o_q].no; i++)
        cout << order[o_q][i].food_name << endl;
    cout << "DELIVERY: " << info[o_q].aoo.amount << endl;
    cout << "TOTAL(WITHOUT TAX): " << info[o_q].total + info[o_q].aoo.amount << endl;
    cout << "ARE YOU SURE YOU WANT GO AHEAD WITH TRANSACTION(Y/N) : ";
    char u;
    cin >> u;
    float tax = 0.15 * info[o_q].total;
    system("cls");
    if (tolower(u) == 'y')
    {
        cout << "Thank You For Placing The Order  ........" << endl
             << endl;
        cout << "=========================================================================\n"
             << endl;
        cout << "*****************************   REICIPT   *******************************" << endl;
        cout << "-------------------------------------------------------------------------" << endl;
        cout << "FOOD NAME                        "
             << "FOOD PRICE" << endl;
        for (int i = 0; i < o_num; i++)
            for (int j = 0; j < info[i].no; j++)
                cout << order[i][j].food_name << "       " << order[i][j].price;
        cout << "\n-------------------------------------------------------------------------" << endl;
        cout << "\n		  TOTAL PRICE      :   " << info[o_q].total << endl;

        cout << "		  TAX              :    " << tax << endl;

        cout << "-------------------------------------------------------------------------" << endl;

        cout << "		  NET TOTAL        :   " << info[o_q].total + tax << endl;

        cout << "-------------------------------------------------------------------------" << endl;
        cout << "		              PAYMENT  SUMMARY  " << endl;
        cout << "-------------------------------------------------------------------------" << endl;

        cout << "-------------------------------------------------------------------------" << endl;
        cout << "\n\n	   WE ARE EAGERLY LOOKING FORWARD TO SERVE YOU AGAIN\n";
        cout << "\n\t	         HAVE A NICE DAY !                               \n\n";
        cout << "=========================================================================\n"
             << endl;
        return_empl();
    }
    else
        return_empl();
}
void sales_report(int a) //DISPLAY THE SALES REPORT
{
    float total = 0;
    cout << "_______________________________________________________\n";
    cout << ".......................................................\n";
    cout << "NAME OF ITEM SOLD\t\t\tPRICE\n";
    cout << ".......................................................\n";
    cout << "_______________________________________________________\n";
    switch (a)
    {
    case 0:
        for (int i = 0; i < o_num; i++)
            for (int j = 0; j < info[i].no; j++)
            {
                cout << setw(17) << order[i][j].food_name << "\t\t\t" << setw(5) << order[i][j].price << endl;
                total += order[i][j].price;
            }
        if (total != 0)
            cout << "TOTAL\t\t\t\t\t" << setw(5) << total << endl;
        else
            cout << "NO AVAILABLE RECORDS";
        return_func();
        break;
    case 1:
        int d;
        cout << "ENTER THE DATE: ";
        d = gett();
        for (int i = 0; i < o_num; i++)
            if (info[i].doo.dd == d)
                for (int j = 0; j < info[i].no; j++)
                {
                    cout << setw(17) << order[i][j].food_name << "\t\t\t" << setw(5) << order[i][j].price << endl;
                    total += order[i][j].price;
                }
        if (total != 0)
            cout << "TOTAL\t\t\t\t\t" << setw(5) << total << endl;
        else
            cout << "NO AVAILABLE RECORDS";
        return_func();
        break;
    case 2:
        int m;
        cout << "ENTER THE MONTH: ";
        m = gett();
        for (int i = 0; i < o_num; i++)
            if (info[i].doo.mm == m)
                for (int j = 0; j < info[i].no; j++)
                {
                    cout << setw(17) << order[i][j].food_name << "\t\t\t" << setw(5) << order[i][j].price << endl;
                    total += order[i][j].price;
                }
        if (total != 0)
            cout << "TOTAL\t\t\t\t\t" << setw(5) << total << endl;
        else
            cout << "NO AVAILABLE RECORDS";
        return_func();
        break;
    case 3:
        int y;
        cout << "ENTER THE YEAR: ";
        y = gett();
        for (int i = 0; i < o_num; i++)
            if (info[i].doo.yy == y)
                for (int j = 0; j < info[i].no; j++)
                {
                    cout << setw(17) << order[i][j].food_name << "\t\t\t" << setw(5) << order[i][j].price << endl;
                    total += order[i][j].price;
                }
        if (total != 0)
            cout << "TOTAL\t\t\t\t\t" << setw(5) << total << endl;
        else
            cout << "NO AVAILABLE RECORDS";
        return_func();
        break;
    }
}
void e_sales_report() //DISPLAY THE SALES REPORT BASED ON EMPLOYEE CONTRIBUTION
{
    int n, a;
    cout << "ENTER THE ID OF THE WAITER YOU WISH TO EVALUATE: ";
    cin >> n;
    if (n > 0 && n <= e_num)
        goto A;
    else
    {
        cout << "ID NOT FOUND";
        return_func();
    }
A:
    cout << "\n\nCHOOSE YOUR PREFFERED ACTION\n";
    cout << "**************************************************************************************\n";
    cout << "*                        A) TOTAL SALES REPORTS                                      *\n";
    cout << "**************************************************************************************\n";
    cout << "**************************************************************************************\n";
    cout << "*                        B) DAILY SALES REPORT                                       *\n";
    cout << "**************************************************************************************\n";
    cout << "**************************************************************************************\n";
    cout << "*                        C) MONTHLY SALE REPORTS                                     *\n";
    cout << "**************************************************************************************\n";
    cout << "**************************************************************************************\n";
    cout << "*                        D) ANNUAL SALE REPORTS                                      *\n";
    cout << "**************************************************************************************\n";
    char v;
D:
    cin >> v;
    switch (tolower(v))
    {
    case 'a':
        system("cls");
        a = 0;
        break;
    case 'b':
        system("cls");
        a = 1;
        break;
    case 'c':
        system("cls");
        a = 2;
        break;
    case 'd':
        system("cls");
        a = 3;
        break;
    default:
        cout << "INVALID ENTRY, TRY AGAIN";
        goto D;
    }
    float total = 0;
    cout << "_______________________________________________________\n";
    cout << ".......................................................\n";
    cout << "NAME OF ITEM SOLD\t\t\tPRICE\n";
    cout << ".......................................................\n";
    cout << "_______________________________________________________\n";
    switch (a)
    {
    case 0:
        for (int i = 0; i < o_num; i++)
            if (info[i].woo.id == n)
                for (int j = 0; j < info[i].no; j++)
                {
                    cout << setw(17) << order[i][j].food_name << "\t\t\t" << setw(5) << order[i][j].price << endl;
                    total += order[i][j].price;
                }
        if (total != 0)
            cout << "TOTAL\t\t\t\t\t" << setw(5) << total << endl;
        else
            cout << "NO AVAILABLE RECORDS";
        return_func();
        break;
    case 1:
        int d;
        cout << "ENTER THE DATE: ";
        d = gett();
        for (int i = 0; i < o_num; i++)
            if (info[i].doo.dd == d && info[i].woo.id == n)
                for (int j = 0; j < info[i].no; j++)
                {
                    cout << setw(17) << order[i][j].food_name << "\t\t\t" << setw(5) << order[i][j].price << endl;
                    total += order[i][j].price;
                }
        if (total != 0)
            cout << "TOTAL\t\t\t\t\t" << setw(5) << total << endl;
        else
            cout << "NO AVAILABLE RECORDS";
        return_func();
        break;
    case 2:
        int m;
        cout << "ENTER THE MONTH: ";
        m = gett();
        for (int i = 0; i < o_num; i++)
            if (info[i].doo.mm == m && info[i].woo.id == n)
                for (int j = 0; j < info[i].no; j++)
                {
                    cout << setw(17) << order[i][j].food_name << "\t\t\t" << setw(5) << order[i][j].price << endl;
                    total += order[i][j].price;
                }
        if (total != 0)
            cout << "TOTAL\t\t\t\t\t" << setw(5) << total << endl;
        else
            cout << "NO AVAILABLE RECORDS";
        return_func();
        break;
    case 3:
        int y;
        cout << "ENTER THE YEAR: ";
        y = gett();
        for (int i = 0; i < o_num; i++)
            if (info[i].doo.yy == y && info[i].woo.id == n)
                for (int j = 0; j < info[i].no; j++)
                {
                    cout << setw(17) << order[i][j].food_name << "\t\t\t" << setw(5) << order[i][j].price << endl;
                    total += order[i][j].price;
                }
        if (total != 0)
            cout << "TOTAL\t\t\t\t\t" << setw(5) << total << endl;
        else
            cout << "NO AVAILABLE RECORDS";
        return_func();
        break;
    }
}
void sales_func() //GIVES US THE CHOICE TO DECIDE WHAT TYPE OF SALES REPORT WE WANT
{
    cout << "\n\nCHOOSE YOUR PREFFERED ACTION\n";
    cout << "**************************************************************************************\n";
    cout << "*                        A) TOTAL SALES REPORTS                                      *\n";
    cout << "**************************************************************************************\n";
    cout << "**************************************************************************************\n";
    cout << "*                        B) DAILY SALES REPORT                                       *\n";
    cout << "**************************************************************************************\n";
    cout << "**************************************************************************************\n";
    cout << "*                        C) MONTHLY SALE REPORTS                                     *\n";
    cout << "**************************************************************************************\n";
    cout << "**************************************************************************************\n";
    cout << "*                        D) ANNUAL SALE REPORTS                                      *\n";
    cout << "**************************************************************************************\n";
    cout << "**************************************************************************************\n";
    cout << "*                        E) WAITER BASED SALE REPORTS                                *\n";
    cout << "**************************************************************************************\n";
    char v;
D:
    cin >> v;
    switch (tolower(v))
    {
    case 'a':
        system("cls");
        sales_report(0);
        break;
    case 'b':
        system("cls");
        sales_report(1);
        break;
    case 'c':
        system("cls");
        sales_report(2);
        break;
    case 'd':
        system("cls");
        sales_report(3);
        break;
    case 'e':
        system("cls");
        display_e_list(4);
        break;
    default:
        cout << "INVALID ENTRY, TRY AGAIN";
        goto D;
    }
}
void profit() //DISPLAYS THE PROFIT OF THE CAFETERIA
{
    float cost = 0, income = 0, profit, ex_cost;
    for (int i = 0; i < o_num; i++)
        for (int j = 0; j < info[i].no; j++)
            for (int k = 0; k < s_num; k++)
                if (order[i][j].food_id == ingridient[k].id)
                    cost += ingridient[k].cost;
    cout << "ENTER ADDITIONAL COST( RENT,WASTED INGREDIENTS,...) : ";
    ex_cost = getf();
    cost += ex_cost;
    for (int i = 0; i < e_num; i++)
        cost += waiter[i].salary;
    for (int i = 0; i < o_num; i++)
        for (int j = 0; j < info[i].no; j++)
            income += order[i][j].price;
    profit = income - cost;
    cout << "MONTHLY INCOME: " << income;
    cout << "MONTHLY EXPENDAGE: " << cost;
    cout << "MONTHLY PROFIT: " << profit;
}
void return_func() //GIVES US THE OPTION TO RETURN TO LOCATIONS AFTER OPERATION
{
    cout << "\n\n\n\n****************************************************************************************\n";
    cout << "* PRESS \'H\'  RETURN TO HOME PAGE\t \'C\' FOR CATALOG \tAND ANY KEY AND TO EXIT*\n";
    cout << "****************************************************************************************\n";
    char v;
    cin >> v;
    switch (tolower(v))
    {
    case 'h':
        system("cls");
        home_page();
        break;
    case 'c':
        system("cls");
        catalog();
        break;
    default:
        exit(0);
    }
}
void return_empl() //GIVES US THE OPTION TO RETURN TO LOCATIONS AFTER OPERATION TO NON ADMINSTRATION PERSONEL
{
    cout << "\n\n\n\n****************************************************************************************\n";
    cout << "* PRESS \'H\'  RETURN TO HOME PAGE AND ANY KEY AND TO EXIT                             *\n";
    cout << "****************************************************************************************\n";
    char v;
    cin >> v;
    switch (tolower(v))
    {
    case 'h':
        system("cls");
        home_page();
        break;
    default:
        exit(0);
    }
}
void intialize() //INITIALIZED VALUES SO THAT TESTING AND OPERATION ARE EASIER, EACH VALUE CAN OF COURSE BE DELETED IN THE PROGRAM IF REQURED
{
    e_aray_add(5);
    for (int i = 0; i < e_num; i++)
        waiter[i].id = i + 1;
    waiter[0].full_name = "Melat Zerabiruk";
    waiter[0].salary = 5'000;
    waiter[1].full_name = "Yabsera Haile";
    waiter[1].salary = 7'000;
    waiter[2].full_name = "Yayehyrad Sisay";
    waiter[2].salary = 6'500;
    waiter[3].full_name = "Yared Bebasha";
    waiter[3].salary = 5'600;
    waiter[4].full_name = "Yohannes Fekadu";
    waiter[4].salary = 4'800;
    s_aray_add(10);
    for (int i = 0; i < s_num; i++)
        ingridient[i].id = i + 1;
    ingridient[0].item_name = "Meat";
    ingridient[0].amount = 500;
    ingridient[0].unit = "Gram";
    ingridient[0].cost = 0.3;
    ingridient[0].w_amount = 5'000;
    ingridient[1].item_name = "Bread";
    ingridient[1].amount = 300;
    ingridient[1].unit = "Pcs";
    ingridient[1].cost = 3;
    ingridient[1].w_amount = 30;
    ingridient[2].item_name = "Dough";
    ingridient[2].amount = 100'000;
    ingridient[2].unit = "Gram";
    ingridient[2].cost = 0.1;
    ingridient[2].w_amount = 5'000;
    ingridient[3].item_name = "Oil";
    ingridient[3].amount = 100'000;
    ingridient[3].unit = "ML";
    ingridient[3].cost = 0.8;
    ingridient[3].w_amount = 5'000;
    ingridient[4].item_name = "Potatoes";
    ingridient[4].amount = 500'000;
    ingridient[4].unit = "Gram";
    ingridient[4].cost = 0.2;
    ingridient[4].w_amount = 500;
    ingridient[5].item_name = "Tomato Sauce";
    ingridient[5].amount = 200'000;
    ingridient[5].unit = "Gram";
    ingridient[5].cost = 2;
    ingridient[5].w_amount = 5'000;
    ingridient[6].item_name = "Shiro Powder";
    ingridient[6].amount = 100'000;
    ingridient[6].unit = "Gram";
    ingridient[6].cost = 0.8;
    ingridient[6].w_amount = 5'000;
    ingridient[7].item_name = "Onions";
    ingridient[7].amount = 50'000;
    ingridient[7].unit = "Gram";
    ingridient[7].cost = 0.4;
    ingridient[7].w_amount = 5'000;
    ingridient[8].item_name = "Berbere";
    ingridient[8].amount = 100'000;
    ingridient[8].unit = "Gram";
    ingridient[8].cost = 0.9;
    ingridient[8].w_amount = 5'000;
    ingridient[9].item_name = "Tomatoes";
    ingridient[9].amount = 50'000;
    ingridient[9].unit = "Gram";
    ingridient[9].cost = 0.4;
    ingridient[9].w_amount = 5'000;
    m_aray_add(4);
    for (int i = 0; i < num; i++)
    {
        food[i].food_id = i + 1;
        recipe[i] = new stock[2];
        food[i].g = 2;
    }
    food[0].food_name = "Burger";
    food[0].price = 80;
    recipe[0][0].item_name = "Meat";
    recipe[0][0].amount = 100;
    recipe[0][0].unit = "Gram";
    recipe[0][0].cost = 0.3;
    recipe[0][0].id = 1;
    recipe[0][1].item_name = "Bread";
    recipe[0][1].amount = 1;
    recipe[0][1].unit = "Pcs";
    recipe[0][1].cost = 3;
    recipe[0][1].id = 2;
    food[1].food_name = "Shiro Wot";
    food[1].price = 50;
    recipe[1][0].item_name = "Shiro Powder";
    recipe[1][0].amount = 200;
    recipe[1][0].unit = "Gram";
    recipe[1][0].cost = 0.8;
    recipe[1][0].id = 6;
    recipe[1][1].item_name = "Berbere";
    recipe[1][1].amount = 100;
    recipe[1][1].unit = "Gram";
    recipe[1][1].cost = 0.9;
    recipe[1][1].id = 9;
    food[2].food_name = "Pizza";
    food[2].price = 120;
    recipe[2][0].item_name = "Dough";
    recipe[2][0].amount = 500;
    recipe[2][0].unit = "Gram";
    recipe[2][0].cost = 0.1;
    recipe[2][0].id = 3;
    recipe[2][1].item_name = "Tomato Sauce";
    recipe[2][1].amount = 20;
    recipe[2][1].unit = "Gram";
    recipe[2][1].cost = 3;
    recipe[2][1].id = 6;
    food[3].food_name = "French Fries";
    food[3].price = 80;
    recipe[3][0].item_name = "Potatoes";
    recipe[3][0].amount = 100;
    recipe[3][0].unit = "Gram";
    recipe[3][0].cost = 0.2;
    recipe[3][0].id = 5;
    recipe[3][1].item_name = "Oil";
    recipe[3][1].amount = 100;
    recipe[3][1].unit = "ML";
    recipe[3][1].cost = 0.8;
    recipe[3][1].id = 4;
}
