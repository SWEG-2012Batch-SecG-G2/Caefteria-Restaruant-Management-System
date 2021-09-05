//program for the storage part
#include <iostream>
#include <iomanip>
using namespace std;
 struct ingridient{
   char name[20];
   float price;
   float weight;
};
int n;
int num=0;
ingridient *ing=new ingridient[num];
int order();
int war();
int loop_func();
void  menu_function();
void mainMenu();
int Login();
void array_add(int n)
{   n=n+num;
    ingridient *ptr=new ingridient[n];
    for(int i=0;i<num;i++)
    {
        ptr[i]=ing[i];
    }
    delete []ing;
    ing=ptr;
    ptr=0;
    num=n;
}
void array_sub(ingridient  ing[],int n)////////not working ;
{
    int j;
    ingridient *ptr=new ingridient[j];
    for(int i=0;i<j;i++)
    {
        ptr[i]=ing[i];
    }
    delete ing;
    ing=ptr;
    ptr=0;
    j++;
}
void display_menu()
{  if(num!=0)
   {
    cout<<"------------------------------------------------------------------------------------------------------\n";
    cout<<"------------------------------------------------------------------------------------------------------\n";
    cout<<"\tingreidient Name\t\tingr Price\t\tweight\n";
    cout<<"------------------------------------------------------------------------------------------------------\n";
    cout<<"------------------------------------------------------------------------------------------------------\n";
    for(int i=0;i<num;i++)
        {cout<<"\t"<<setw(10)<<ing[i].name<<"\t\t"<<setw(10)<<ing[i].price<<"\t\t"<<ing[i].weight<< endl;}
     cout<<"------------------------------------------------------------------------------------------------------\n";
    }
    else
     cout<<"NO DATA HAS BEEN ENTERED";
        loop_func();
}
int loop_func()
{
   cout << "\n\n\n\n**************************************************************************************\n";
    cout << "*                 PRESS \'R\'  RETURN TO ANY KEY AND TO EXIT                             *\n";
    cout << "**************************************************************************************\n";
    char v;
    cin >> v;
    if (tolower(v) == 'r')
    {
        system("cls");
         menu_function();

    }
    else
     exit(0);//DOESN'T ALWAYS EXIT AS COMMANDED
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
    char v;
    cin>>v;
    switch (tolower(v))
    {
    case 'a':
        system("cls");
        int n;
    cout<<"Enter the amount of items you wish to add: ";
    cin>>n;
    array_add(n);
    for(int i=0;i<n;i++)
    {
            cout<<"Name of Ingredient "<<i+1<<" : ";cin>>ing[i].name;
            cout<<"Quantity of Ingredient "<<i+1<<" : ";cin>>ing[i].weight;
            cout<<"Enter the Price of Food "<<i+1<<"  : ";cin>>ing[i].price;
        }
        loop_func();
        break;
    case 'b':
        system("cls");
         char del_name[20];
         char x;
    cout<<"what ing do u want to delete: ";
    cin>>del_name;
    for(int i=0;i<n;i++)
    {     if (ing[i].name == del_name){
            cout<<"Name of Ingredient "<<i+1<<" : "<<ing[i].name;
            cout<<"Quantity of Ingredient "<<i+1<<" : " <<ing[i].weight;
            cout<<"Price"<<i+1<<"  : " << ing[i].price;
            cout << "are u sure u want to delete it press y for yes and n for no";
            cin >>x;
              if(x=='y'){ array_sub(ing, i);}
        }}
        loop_func();
        break;
        }}
void menu_function()
{
    cout<<endl;
    cout<<"---------------------------------------------------------------------------------------"<<endl;
    cout<<"****************   CAFTERIA  M A N A G E M E N T  S Y S T E M ********************"<<endl;
    cout<<"---------------------------------------------------------------------------------------"<<endl;
    cout<<endl;
    cout << "CHOOSE YOUR PREFFERED ACTION\n";
    cout << "**************************************************************************************\n";
    cout << "*                        A) DIsplay INGRIDIENTS INFO                                 *\n";
    cout << "**************************************************************************************\n";
    cout << "**************************************************************************************\n";
    cout << "*                        B) EDIT INGRIDINT INFO                                      *\n";
    cout << "**************************************************************************************\n";
    cout << "**************************************************************************************\n";
    cout << "*                        C) BACK TO MAIN MENU                                        *\n";
    cout << "**************************************************************************************\n";
    char v;
    cin>>v;
    switch (tolower(v))
    {
    case 'a':
        system("cls");
       display_menu();
        break;
    case 'b':
        system("cls");
      menu_edit();
        break;
    case 'c':
     system("cls");
      mainMenu();
    }
}
int getchoice(){//For Input validation
    int choice;
    cin>>choice;
    while(!cin.good()){
        cin.clear();
        cin.ignore(INT_MAX,'\n');
        //Invalid input trial
        cout<<"\t\tInavlid input. Try again: ";
        cin>>choice;
    }
    return choice;
}

///////////////////////////////////////////////////////////// not finished
/*int order(){
    char x[6][20];
    int y;

for( int i = 0 ;i<n;i++){

    if(  [i].name == x){
    ing[i].weight = ing[i].weight-y;
    cout << ing[i].weight;
    }}
}*/
int war(){
    for (int i = 0 ; i<n;i++){
    if (ing[i].weight < 5 ){
    cout <<"shortage in stock"<< endl ;
    cout <<"name\t" << "weight in kg \t" <<"price\t" << endl;
    cout<<ing[i].name<<"\t"<<ing[i].weight<<setw(12)<<"\t"<<ing[i].price<<endl;
    }

}}
/////////////////////////////////////////////////////ORDERING PART FUNCTIONAL WHEN FOOD OPTION IS CREATED
/*void place_order()
{
      food pinter array [50];//functional when food system is created;
      int c=0,pr1=0;
      float total=0,ttaxt=0;
      int q1;
      char ch='Y';
      int v=0;
            do
            {

            cout<<"========================================================================"<<endl;
            cout<<"                             PLACE YOUR ORDER                           "<<endl;
            cout<<"========================================================================"<<endl;
                  cout<<"ENTER THE FOOD NAME: "<<endl;
                  cin>>pr1;
                  //////////// FOOD NAME IN THE ARRAY
                  if(// food name == ptr1)
                  {
                        cout<<"Enter the Quantity:"<<endl;
                        cin>>q1;
                        food[v].=pr1;
                        v++;
                  }
                  else
                  {
                        cout<<"FOOD IS NOT IN THE LIST"<<endl;
                  }
                  cout<<"DO YOU WANT TO ORDER AGAIN? (Yes[ y or Y ] or NO [n or N])"<<endl;
                  cin>>ch;
            }while(ch=='y' || ch=='Y');

            cout<<"Thank You For Placing The Order  ........"<<endl<<endl;
            cout<<"========================================================================\n"<<endl;
            cout<<"*****************************   INVOICE   ******************************"<<endl;
            cout<<"------------------------------------------------------------------------"<<endl;
            cout<<"FOOD NAME"<<setw()<<"FOOD PRICE"<<setw()<<"Amount"<<endl;
            for(int i=0;i<num;i++)
            {
                   /////////////details
             }

             cout<<"\n-------------------------------------------------------------------------"<<endl;
             cout<<"\n		  TOTAL AMOUNT     :   "<<//<<"BIRR"<<endl;
             cout<<"\n		  TOTAL PRICE      :   "<<//weight * value<<"BIRR"<<endl;

             cout<<"		  TAX              :    "<< "+" << // tax <<"%"<<endl;


             cout<<"-------------------------------------------------------------------------"<<endl;

             cout<<"		  NET TOTAL        :   "<<//(total price *tax) <<"birr"<< endl;

             cout<<"-------------------------------------------------------------------------"<<endl;
             cout<<"		   P A Y M E N T  S U M M A R Y  "<<endl;
             cout<<"-------------------------------------------------------------------------"<<endl;

             cout<<"-------------------------------------------------------------------------"<<endl;
             cout<<"\n\n	   WE ARE EAGERLY LOOKING FORWARD TO SERVE YOU AGAIN\n";
             cout<<"\n			    HAVE A NICE DAY !                               \n\n";
             cout<<"=========================================================================\n"<<endl;

}*/
void introduction()
{
      cout<<endl<<endl<<endl<<endl<<endl;
      cout<<"                        ========================================================================="<<endl;
      cout<<"                        -------------------------------------------------------------------------"<<endl;
      cout<<"                        ************* WELCOME TO XYY CAFETERIA M A N A G E M E N T **************"<<endl;
      cout<<"                        -------------------------------------------------------------------------"<<endl;
      cout<<"                        ***************************   S Y S T E M   *****************************"<<endl;
      cout<<"                        -------------------------------------------------------------------------"<<endl;

      cout<<"                        ========================================================================="<<endl;
       system("pause");
       system("cls");
}
////////////////////////////////////////////////////////////////////////////////////
void mainMenu(){
     char choice;
      do
      {
            cout<<endl;
            cout<<"----------------------------------------------------------------------------------"<<endl;
            cout<<"*************************   CAFETERIA  MANAGEMENT  SYSTEM   **********************"<<endl;
            cout<<"----------------------------------------------------------------------------------"<<endl;
            cout<<endl;
            cout<<"==================================   MAIN MENU   ================================="<<endl;
            cout<<"PRESS [1] ORDER"<<endl;
            cout<<"PRESS [2] ADMINISTRATOR MODE"<<endl;
            cout<<"PRESS [3] EXIT"<<endl;
            cout<<"=================================================================================="<<endl;
            cout<<"Please Select Your Option (1-3) "<<endl;
            cin>>choice;
            switch(choice)
            {
                  case '1':
                         // create;
                        break;
                  case '2':
                        Login();
                        break;
                  case '3':
                        exit(0);
                  default :
                        cout<<"Please enter valid option"<<endl;
            }
      }while(choice!='3');
    }
void administratormenu()
{
      char choice;
      do
      {
            cout<<endl;
            cout<<"===================================   ADMINISTRATOR MENU   =============================="<<endl;
            cout<<"1. EMPLOYEE ADD"<<endl;
            cout<<"2. PRODUCTS ADD"<<endl;
            cout<<"3. BACK TO MAIN MENU"<<endl;
            cout<<"=========================================================================================="<<endl;
            cout<<"Please Select Your Option (1-3) "<<endl;
            cin>>choice;
                  switch(choice)
                  {
                        case '1':
                              ///////////create a function
                              break;
                        case '2':
                             menu_function();
                              break;
                        case '3':
                              mainMenu();
                              break;
                        default :
                              cout<<"Please enter valid option"<<endl;
                  }
      }while(choice !='3');
}
////////////////////////////////////////////////////////////////

int Login()
{
    string a = "abc" ,b="123";//////////to check pass and user name;
    cout<<endl;
    cout<<"-------------------------------------------------------------------------"<<endl;
    cout<<"******************   CAFETERIA  MANAGEMENT  SYSTEM   ********************"<<endl;
    cout<<"-------------------------------------------------------------------------"<<endl;
    cout<<endl;
    cout<<"1.LOGIN"<<endl;
    cout<<"2.EXIT"<<endl;
    string s,p;
      int x;
      cin>>x;
      while (x==1)
      {
                  cout<<"ENTER YOUR USERNAME"<<endl;
                  cin>>s;
                  cout<<"ENTER YOUR PASSWORD"<<endl;
                  cin>>p;
                  if (s !=a || p !=b ){
                    system("cls");
                    cout << "WRONG USERNAME OR PASSWORD"<< endl;
                    system("pause");////pause
                    system("cls");

                  }
                  else {
                  administratormenu();
                  break; } }}
int main(){
    introduction();
    mainMenu();
}


