#include <iostream>
#include <iomanip>
using namespace std;
void sales_report(int a)
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
        d=gett();
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
        m=gett();
        cout << "ENTER THE MONTH: ";
        cin >> m;
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
        y=gett();
        cout << "ENTER THE YEAR: ";
        cin >> y;
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
void e_sales_report()
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
        d=gett();
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
        m=gett();
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
        y=gett();
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
void sales_func()
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
