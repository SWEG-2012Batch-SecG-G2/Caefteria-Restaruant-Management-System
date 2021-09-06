#include<iostream>
#include<iomanip>
#include<string>
using namespace std;
struct stock
{   int id;
    string item_name;
    float amount;
    string unit;
    float cost;
};
struct menu
{   int food_id;
    string food_name;
    float price;
    int g;
};
int num=0,q,s_num=0,s_q;
stock **recipe=new stock*[num];
menu *food=new menu[num];
void home_page();
void display_menu(int);
void menu_edit();
void return_func();
stock *ingridient=new stock[s_num];
void intialize();
void display_s_list(int,int);
void s_list_edit();
void catalog();
void reciepe_func(int);
void m_aray_add(int n)
{
    n=n+num;
    menu *ptr1=new menu[n];
    stock **ptr2=new stock*[n];
     for(int i=0;i<num;i++)
     ptr2[i]=new stock[food[i].g];
    for(int i=0;i<num;i++)
    {  for(int j=0;j<food[i].g;j++)
        ptr2[i][j]=recipe[i][j];
    }
    for(int i=0;i<num;i++)
        delete []recipe[i];

    delete []recipe;
    recipe=ptr2;
    ptr2=0;
    for(int i=0;i<num;i++)
    {
        ptr1[i]=food[i];
    }
    delete []food;
    food=ptr1;
    ptr1=0;
    q=num;
    num=n;
}
void s_aray_add(int n)
{   n=n+s_num;
    stock *ptr1=new stock[n];
    for(int i=0;i<s_num;i++)
    {
        ptr1[i]=ingridient[i];
    }
    delete []ingridient;
    ingridient=ptr1;
    ptr1=0;
    s_q=s_num;
    s_num=n;
}
void m_aray_del(int n)
{
    delete []recipe[n-1];
    for(int i=n;i<num;i++)
    {   food[i].food_id--;
        recipe[i-1]=recipe[i];
        food[i-1]=food[i];
    }
      num--;
    recipe[num]=0;
    delete recipe[num];
   menu *ptr1=new menu[num];
    for(int i=0;i<num;i++)
    {
        ptr1[i]=food[i];
    }
    delete []food;
    food=ptr1;
    ptr1=0;
    q=num;
}
void s_aray_del(int n)
{
    for(int i=n;i<s_num;i++)
    {   ingridient[i].id--;
        ingridient[i-1]=ingridient[i];
    }
     s_num--;
    stock *ptr1=new stock[s_num];
    for(int i=0;i<s_num;i++)
    {
        ptr1[i]=ingridient[i];
    }
    delete []ingridient;
    ingridient=ptr1;
    ptr1=0;
    s_q=s_num;
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
    cin>>v;
    switch (tolower(v))
    {
        case 'a':cout<<"ENTER UPDATED NAME: ";
        cin.ignore (80, '\n');
        getline(cin,(food[n-1].food_name));
        break;
        case 'b':cout<<"ENTER UPDATED PRICE: ";
        cin>>food[n-1].price;
        break;

    }
}
void s_aray_update(int n)
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
    cin>>v;
    switch (tolower(v))
    {
        case 'a':cout<<"ENTER UPDATED ITEM NAME: ";
        cin.ignore (80, '\n');
        getline(cin,(ingridient[n-1].item_name));
        break;
        case 'b':cout<<"ENTER UPDATED QUANTITY AMOUNT: ";
        cin>>ingridient[n-1].amount;
        break;
        case 'c':cout<<"ENTER UPDATED PRICE PER UNIT: ";
        cin>>ingridient[n-1].cost;
        break;
        case 'd':cout<<"ENTER UPDATED UNIT OF MEASUREMENT: ";
        cin.ignore (80, '\n');
        getline(cin,(ingridient[n-1].unit));
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
    cin>>v;
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
      cout<<num;
     return_func();
        break;
    }
}
void stock_func()
{
    cout << "CHOOSE YOUR PREFFERED ACTION\n";
    cout << "**************************************************************************************\n";
    cout << "*                        A) DISPLAY INVENTORY LIST                                   *\n";
    cout << "**************************************************************************************\n";
    cout << "**************************************************************************************\n";
    cout << "*                        B) EDIT INVENTORY LIST                                      *\n";
    cout << "**************************************************************************************\n";
    char v;
    cin>>v;
    switch (tolower(v))
    {
    case 'a':
        system("cls");
       display_s_list(0,0);
        break;
    case 'b':
        system("cls");
      s_list_edit();
        break;
    }
}
void display_menu(int a)
{  if(num!=0)
   {
    cout<<"\t\t\t\t\t\t    MENU\n";
    cout<<"________________________________________________________________________________________________________________________\n";
    cout<<"........................................................................................................................\n";
    cout<<"ID\tFOOD NAME\t\tFOOD PRICE\t\tCONTENTS\n";
    cout<<"........................................................................................................................\n";
    cout<<"________________________________________________________________________________________________________________________\n";
    for(int i=0;i<num;i++)
        {cout<<food[i].food_id<<"\t"<<setw(10)<<food[i].food_name<<"\t\t"<<setw(10)<<food[i].price<<"\t\t";
         for(int j=0;j<food[i].g;j++)
         cout<<recipe[i][j].item_name<<" ("<<recipe[i][j].amount<<") , ";
   cout<<endl<<"------------------------------------------------------------------------------------------------------------------------\n";

        }
    }
    else
     {cout<<"NO DATA HAS BEEN ENTERED";
       return_func();
     }
     switch(a)
     {
         case 0:  return_func();break;
         case 1:
            int n;
            cout<<"ENTER THE ID OF THE CONTENT YOU WISH TO DELETE: ";
            cin>>n;
            if((n>0)&&(n<=num))
           {
               m_aray_del(n);
               return_func();
           }
            else
            {
                cout<<"ID NOT FOUND";
                return_func();
            }
            break;
         case 2:
            int m;
            cout<<"ENTER THE ID OF THE CONTENT YOU WISH TO UPDATE: ";
            cin>>m;
            if((m>0)&&(m<=num))
           {
               m_aray_update(m);
              return_func();
           }
            else
            {
                cout<<"ID NOT FOUND";
               return_func();
            }
            break;
     }

}
void display_s_list(int a,int b)
{  if(s_num!=0)
   {cout<<"\t\t\t   STOCK\n";
    cout<<"______________________________________________________________________\n";
    cout<<"......................................................................\n";
    cout<<"ID\tITEM NAME\t\tAMOUNT(UNIT)\t\tPRICE PER UNIT\n";
    cout<<"......................................................................\n";
    cout<<"______________________________________________________________________\n";
    for(int i=0;i<s_num;i++)
        {cout<<ingridient[i].id<<"\t"<<setw(10)<<ingridient[i].item_name<<"\t\t"<<setw(7)<<ingridient[i].amount<<" ("<<ingridient[i].unit<<")"<<"\t\t"<<setw(14)<<ingridient[i].cost;
         cout<<endl<<"----------------------------------------------------------------------\n";
        }
    }
    else
     {cout<<"NO DATA HAS BEEN ENTERED";
      return_func();
     }
     switch(a)
     {
         case 0:  return_func();break;
         case 1:
            int n;
            cout<<"ENTER THE ID OF THE ITEM YOU WISH TO REMOVE: ";
            cin>>n;
            if((n>0)&&(n<=s_num))
           {
               s_aray_del(n);
               return_func();
           }
            else
            {
                cout<<"ID NOT FOUND";
                return_func();
            }
            break;
            case 2:
            int m;
            cout<<"ENTER THE ID OF THE CONTENT YOU WISH TO UPDATE: ";
            cin>>m;
            if((m>0)&&(m<=s_num))
           {
               s_aray_update(m);
               return_func();
           }
            else
            {
                cout<<"ID NOT FOUND";
                return_func();
            }
            break;
            case 3: reciepe_func(b);break;
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
    cin>>v;
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

    A: int n;
    cout<<"ENTER THE AMOUNT OF CONTENT YOU WISH TO ADD: ";
    cin>>n;
    m_aray_add(n);
    for(int i=q;i<(q+n);i++)
    {
    cin.ignore (80, '\n');
    food[i].food_id=i+1;
    cout<<"ENTER THE NAME OF THE FOOD "<<food[i].food_id<<" : ";
    getline(cin,food[i].food_name);
    cout<<"ENTER THE PRICE OF THE FOOD "<<food[i].food_id<<"  : ";
     cin>>food[i].price;
     cout<<"ENTER THE NUMBER OF INGRIDIENTS: ";
     cin>>food[i].g;
     recipe[i]=new stock[food[i].g];
     display_s_list(3,i);
    }
   return_func();
}
void reciepe_func(int i)
{   int m;

   for(int j=0;j<(food[i].g);j++)
       { A:cout<<"ENTER ID OF INGRIDIENT "<<j+1<<" FROM THE ABOVE LIST : ";cin>>m;
         if(m>0&&m<=s_num)
         {recipe[i][j].item_name=ingridient[m-1].item_name;
          recipe[i][j].unit=ingridient[m-1].unit;
          recipe[i][j].cost=ingridient[m-1].cost;
         cout<<"ENTER THE AMOUNT INGRIDIENT "<<j+1<<" REQUIRED : ";cin>>recipe[i][j].amount;
       }
         else
            {
                cout<<"ID NOT FOUND\nENTER \'R\' TO TRY AGAIN OR ANY TO RETURN: \n";
                char v;
                cin>>v;
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
}}
void s_list_edit()
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
    cin>>v;
    switch (tolower(v))
    {
    case 'a':
        system("cls");
        goto A;
        break;
    case 'b':
        system("cls");
        display_s_list(1,0);
        break;
    case 'c':
        system("cls");
        display_s_list(2,0);
        break;}

    A: int n;
    cout<<"ENTER THE NUMBER OF ITEMS YOU WISH TO ADD TO THE INVENTORY LIST: ";
    cin>>n;
    s_aray_add(n);
    for(int i=s_q;i<(s_q+n);i++)
    {
    cin.ignore (80, '\n');
    ingridient[i].id=i+1;
    cout<<"ENTER NAME OF ITEM "<<ingridient[i].id<<" : ";
    getline(cin,ingridient[i].item_name);
    cout<<"ENTER UNIT OF ITEM "<<ingridient[i].id<<" : ";
    getline(cin,ingridient[i].unit);
    cout<<"ENTER THE AMOUNT OF ITEM "<<ingridient[i].id<<" (ACCORDING TO THE CHOSEN UNIT) : ";
    cin>>ingridient[i].amount;
    cout<<"ENTER THE PRICE PER UNIT OF ITEM "<<ingridient[i].id<<"  : ";
    cin>>ingridient[i].cost;
    }
    return_func();
}
void return_func()
{
   cout << "\n\n\n\n****************************************************************************************\n";
    cout << "* PRESS \'H\'  RETURN TO HOME PAGE\t \'C\' FOR CATALOG \tAND ANY KEY AND TO EXIT*\n";
    cout << "****************************************************************************************\n";
    char v;
    cin >> v;
    switch (tolower(v))
    {
       case 'h': system("cls");
        home_page();break;
       case 'c': system("cls");
        catalog();break;
        default:exit(0);
    }


}
void intialize()
{
    s_aray_add(10);
    for(int i=0;i<s_num;i++)
        ingridient[i].id=i+1;
    ingridient[0].item_name="MEAT";
    ingridient[0].amount=50'000;
    ingridient[0].unit="Gram";
    ingridient[0].cost=0.3;
    ingridient[1].item_name="BREAD";
    ingridient[1].amount=300;
    ingridient[1].unit="Pcs";
    ingridient[1].cost=3;
    ingridient[2].item_name="DOUGH";
    ingridient[2].amount=100'000;
    ingridient[2].unit="Gram";
    ingridient[2].cost=0.1;
    ingridient[3].item_name="Oil";
    ingridient[3].amount=100'000;
    ingridient[3].unit="ML";
    ingridient[3].cost=0.8;
    ingridient[4].item_name="Potatoes";
    ingridient[4].amount=50,000;
    ingridient[4].unit="Gram";
    ingridient[4].cost=0.2;
    ingridient[5].item_name="Tomato Sauce";
    ingridient[5].amount=200'000;
    ingridient[5].unit="Gram";
    ingridient[5].cost=2;
    ingridient[6].item_name="Shiro Powder";
    ingridient[6].amount=100'000;
    ingridient[6].unit="Gram";
    ingridient[6].cost=0.8;
    ingridient[7].item_name="Onions";
    ingridient[7].amount=50'000;
    ingridient[7].unit="Gram";
    ingridient[7].cost=0.4;
    ingridient[8].item_name="Berbere";
    ingridient[8].amount=100'000;
    ingridient[8].unit="Gram";
    ingridient[8].cost=0.9;
    ingridient[9].item_name="Tomatoes";
    ingridient[9].amount=50'000;
    ingridient[9].unit="Gram";
    ingridient[9].cost=0.4;
}
void catalog()
{   cout << "CHOOSE YOUR PREFFERED LOCATION\n";
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
    char v;
    cin >> v;
    switch (tolower(v))
    {
       case 'h': system("cls");
        home_page();break;
       case 'e':exit(0);
         case 'a': system("cls");
        menu_func();break;
        case 'b': system("cls");
        stock_func();break;
    }

}
void home_page()
{
     cout << "CHOOSE YOUR PREFFERED ACTION\n";
    cout << "**************************************************************************************\n";
    cout << "*                        A) MENU SETTINGS                                            *\n";
    cout << "**************************************************************************************\n";
    cout << "**************************************************************************************\n";
    cout << "*                        B) INVENTORY SETTINGS                                       *\n";
    cout << "**************************************************************************************\n";
    char v;
    cin>>v;
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
    }
}
int main()
{
     system("color f0");
      intialize();
      home_page();
}




