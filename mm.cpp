#include<iostream>
#include<iomanip>
#include<string.h>
using namespace std;
// program for delivery
struct customer
{
      char customer_name[100];

      char address[100];
      char phone_no[15];};
      char food[15];//to chec food ordering func
int  q;//to check food quant
int c ;
int cst=0;
customer *custm=new customer[cst];
void customer_add(int c)
{   c=c+cst;
    customer *ptr=new customer[c];
    for(int i=0;i<cst;i++)
    {
        ptr[i]=custm[i];
    }
    delete []custm;
    custm=ptr;
    ptr=0;
    cst=c;}
    void custm_menu_edit();
    void display_customer_info();
     int loop_func();
     void place_order2();
/////////////////////////////////
void customer_Order()
{
      char choice;

      cout << endl ;
      cout<<"                    -------------------------------------------------------------------------"<<endl;
      cout<<"                                 		ENTER   CUSTOMER   DETAILS : "<<endl;
      cout<<"                    -------------------------------------------------------------------------"<<endl;
      cout<<"                                   PRESS [1] CREATE CUSTOMER DETAIL"<<endl;
      cout<<"                                   PRESS [2] DISPLAY CUSTOMERS DETAILS"<<endl;
      cout<<"                                   PRESS [3] BACK TO MAIN MENU"<<endl;
      cout<<"                     -------------------------------------------------------------------------"<<endl;
      cin>>choice;
      switch(choice)
      {
            case '1':
                  custm_menu_edit();
                  break;
            case '2':
                  display_customer_info();
                  break;
            case '3':
              //    mainMenu();
                  break;

            default:
                  cout<<"Please enter valid option"<<endl;
      }
}

/////////////////////////////////////////////////////////////////////////////////
void custm_menu_edit()
{
    cout << "CHOOSE YOUR PREFFERED ACTION\n";
    cout << "**************************************************************************************\n";
    cout << "*                        A) ADD CUSTOMER INFO                                        *\n";
    cout << "**************************************************************************************\n";
    cout << "**************************************************************************************\n";
    cout << "*                        B) DELETE CUSTOMER INfO                                     *\n";
    cout << "**************************************************************************************\n";

    char v;
    cin>>v;
    switch (tolower(v))
    {
    case 'a':
        system("cls");
        int n;
    cout<<"Enter the amount of customers you wish to add  ";
    cin>>n;
    customer_add(n);
    for(int i=0;i<n;i++)
    {
            cout<<"Name of customer"<<i+1<<" : ";cin>>custm[i].customer_name;
            cout<<"Address of customer "<<i+1<<" : ";cin>>custm[i].address;
            cout<<"Phone no of customer "<<i+1<<"  : ";cin>>custm[i].phone_no;
            place_order2();
        }
        loop_func();
        break;
    case 'b':
        system("cls");
         char del_name[20];
         char x;
    cout<<"what ing do u want to delete: ";
    cin>>del_name;
   /* for(int i=0;i<n;i++)
    {     if (custm[i].name == del_name){
            }
        }}
        loop_func();
        break;*/
        }}

/////////////////////////////////////////////////////////
void display_customer_info()
{  if(cst!=0)
   {
    cout<<"\t------------------------------------------------------------------------------------------------------\n";
    cout<<"\t------------------------------------------------------------------------------------------------------\n";
    cout<<"\tCUSTOMER NAME\t\tCUSTOMER ADDRESS\t\tCUSTOMER PHONE_NO \t FOOD NAME \t AMOUNT\n " ;
    cout<<"\t------------------------------------------------------------------------------------------------------\n";
    cout<<"\t------------------------------------------------------------------------------------------------------\n";
    for(int i=0;i<cst;i++)
    {cout<<"\t"<<custm[i].customer_name<<"\t\t"<<setw(10)<<custm[i].address<<"\t\t"<<setw(17) <<custm[i].phone_no; for (int i = 0 ; i<15 ; i++){cout <<setw(11) << food[i];}cout <<setw(7)<<q << endl;}
     cout<<"\t------------------------------------------------------------------------------------------------------\n";
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
         customer_Order();

    }
    else
     exit(0);}
int main(){
customer_Order();
 }

////////////////////////////////////////

void place_order2()
{
      //functional when food system is created;
      char pr1[15];
       int c=0;
      float total=0,ttaxt=0;
      int q1;
      char choice='Y';
      int v=0;
            do
            {

            cout<<"========================================================================"<<endl;
            cout<<"                             PLACE YOUR ORDER                           "<<endl;
            cout<<"========================================================================"<<endl;
                  cout<<"ENTER THE FOOD NAME: "<<endl;
                  cin>>pr1;
                  //////////// FOOD NAME IN THE ARRAY
                  if(pr1 == pr1)
                  {
                        cout<<"Enter the Quantity:"<<endl;
                        cin>>q1;
                        for (int i = 0 ; i<15 ;i++){
                        strcpy(food , pr1);}
                        q =q1;
                  }
                  else
                  {
                        cout<<"FOOD IS NOT IN THE LIST"<<endl;
                  }
                  cout<<"DO YOU WANT TO ORDER AGAIN? (Yes[ y or Y ] or NO [n or N])"<<endl;
                  cin>>choice;
            }while(choice=='y' || choice=='Y');

            cout<<"Thank You For Placing The Order  ........"<<endl<<endl;
            cout<<"========================================================================\n"<<endl;
            cout<<"*****************************   INVOICE   ******************************"<<endl;
            cout<<"------------------------------------------------------------------------"<<endl;
            cout<<"FOOD NAME"<<setw(5)<<"FOOD PRICE"<<setw(5)<<"Amount"<<endl;
            for(int i=0;i<cst;i++)
            {
                   /////////////details
             }

             cout<<"\n-------------------------------------------------------------------------"<<endl;
             cout<<"\n		  TOTAL AMOUNT     :   "/*<<<<"BIRR"*/<<endl;
             cout<<"\n		  TOTAL PRICE      :   "/*<<weight * value<<"BIRR"*/<<endl;

             cout<<"		  TAX              :    "/*<< "+" << // tax <<"%"*/<<endl;


             cout<<"-------------------------------------------------------------------------"<<endl;

             cout<<"		  NET TOTAL        :   "/*<<//(total price *tax) <<"birr"*/<< endl;

             cout<<"-------------------------------------------------------------------------"<<endl;
             cout<<"		   P A Y M E N T  S U M M A R Y  "<<endl;
             cout<<"-------------------------------------------------------------------------"<<endl;

             cout<<"-------------------------------------------------------------------------"<<endl;
             cout<<"\n\n	   WE ARE EAGERLY LOOKING FORWARD TO SERVE YOU AGAIN\n";
             cout<<"\n			    HAVE A NICE DAY !                               \n\n";
             cout<<"=========================================================================\n"<<endl;

}
