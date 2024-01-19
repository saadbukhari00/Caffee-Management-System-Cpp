#include "menu.h"

using namespace std;

//For admin menu
void adminmenu()
{
int adminchoice;



do
{
 cout<<"\n1.Stock Management";
 cout<<"\n2.Orders Management";
 cout<<"\n3.Employee Management";
 cout<<"\n4.User Management";
 cout<<"\n5.Cafe Management";
 cout<<"\n6.Manage Database";
 cout<<"\n99.Logout";

 cout<<"\nEnter your choice: ";                 //Asking for choice from user
 cin>>adminchoice;

 //checks for strings and floats ; for all non numeric input
   while(cin.fail())
   {
      cin.clear();
      cin.ignore(100,'\n');
      cout<<"\nInvalid input. Please enter a number: ";
      cin>>adminchoice;
   }

   switch(adminchoice)
   {
      //For stock management
      case 1: 
      {
         int stockchoice;

         cout<<"\nStock Management\n";
         cout<<"\n1.Display Stock";
         cout<<"\n2.Add Stock";
         cout<<"\n3.Delete Stock";
         cout<<"\n4.Update Stock";
         cout<<"\n5.Search Stock";
         cout<<"\n6.Stock Summary";
         cout<<"\n7.Sum of Items in Menu";
         cout<<"\n8.Average price of  items in menu";
         cout<<"\n9.Total Price of all items in menu";
         cout<<"\n99.Logout";

         cout<<"\n\nEnter your choice: ";                 //Asking for choice from user
         cin>>stockchoice;

         //checks for strings and floats ; for all non numeric input
         while(cin.fail())
         {
            cin.clear();
            cin.ignore(100,'\n');
            cout<<"\nInvalid input. Please enter a number: ";
            cin>>stockchoice;
         }

         if(stockchoice==1)
         {
            int displaychoice;
            cout<<"\nDisplaying Stock\n";
            cout<<"\n1.Display By Name";
            cout<<"\n2.Display By Quantity";
            cout<<"\n3.Display By Price";

            cout<<"\n\nEnter your choice: ";                 //Asking for choice from user
            cin>>displaychoice;

            switch(displaychoice)
            {
               case 1:
               {
                  displaybyname();
                  break;
               }
               case 2:
               {
                  displaybyquantity();
                  break;
               }
               case 3:
               {
                  displaybyprice();
                  break;
               }
               default:
               {
                  cout<<"\nInvalid choice\n";
                  break;
               }
            }


         }
         else if(stockchoice==2)
         {
            addstock();
         }
         else if(stockchoice==3)
         {
            deletestock();
         }
         else if(stockchoice==4)
         {
            updatestock();
         }
         else if(stockchoice==5)
         {
            adminsearch();
         }
         else if(stockchoice==6)
         {
            cout<<"\n1.Check Stock Summary\n";
            cout<<"\n2.Compare Current Stocks With Database\n";

            int summarychoice;
            cout<<"\nEnter your choice: ";                 //Asking for choice from user
            cin>>summarychoice;

            if(summarychoice==1)
           {
            cout<<"\nStock Summary\n";
            cout<<"\nTotal number of items in stock: "<<stockcount()<<endl;
            cout<<"\nTotal number of items out of stock: "<<outofstockcount()<<endl;
            cout<<"\nTotal number of items in stock with quantity less than 10: "<<lowstockcount()<<endl;
            cout<<"\nTotal Sales: "<<totalsales()<<endl;

           }
             else if(summarychoice==2)
             {
               cout<<"\nComparing Current Stocks With Database\n";
               comparestocks();
             }
             
             else
             {
               cout<<"\nInvalid choice\n";
             }
            
         }
         else if(stockchoice==7)
         {
            cout<<"\nTotal Number of all items in menu: "<<sumofallitems()<<endl;
         }
         else if(stockchoice==8)
         {
            cout<<"\nAverage price of items in stock: PKR "<<averageprice()<<endl;
         }
         else if(stockchoice==9)
         {
            cout<<"\nTotal Price of all items in stock: PKR "<<totalprice()<<endl;
         }
         else if(stockchoice==99)
         {
            randomdecrease();
            cout<<"\nLogging out...";
            cout<<"\nLogged out successfully\n";
            break;
         }
         else
         {
            cout<<"\nInvalid choice\n";
            break;
         }
         break;
      }

      //For orders management
      case 2: 
      {
         int orderschoice;

         cout<<"\nOrders Management\n";
         cout<<"\n1.Display Orders";
         cout<<"\n2.Check Sheduled Orders";
         cout<<"\n3.Check Completed Orders Summary";
         cout<<"\n4.Reset Orders";
         cout<<"\n5.Rest Sheduled Orders";
         cout<<"\n99.Logout";

         cout<<"\n\nEnter your choice: ";                 //Asking for choice from user
         cin>>orderschoice;

         //checks for strings and floats ; for all non numeric input
         while(cin.fail())
         {
            cin.clear();
            cin.ignore(100,'\n');
            cout<<"\nInvalid input. Please enter a number: ";
            cin>>orderschoice;
         }

         if(orderschoice==1)
         {
            cout<<"\nDisplaying Orders\n";
            cout<<"\nYou are viewing orders for today\n";
            cout<<"\nYou can process the orders if you want\n";
            takeorder();
         }
         else if(orderschoice==2)
         {
            cout<<"\nDisplaying Sheduled Orders\n";
            cout<<"\nYou are viewing sheduled orders for the week\n";
            cout<<"\nYou can process the orders if you want\n";
            takesheduleorder();

         }
         else if(orderschoice==3)
         {
            orderhistory();
         }
         else if(orderschoice==4)
         {
            resetorders();
         }
         else if(orderschoice==5)
         {
            resetsheduleorders();
         }
         else if(orderschoice==99)
         {
            randomdecrease();
            cout<<"\nLogging out...";
            cout<<"\nLogged out successfully\n";
            break;
         }
         else
         {
            cout<<"\nInvalid choice\n";
            break;
         }
         break;  
      }  
      case 3: 
      {
         cout<<"\nEmployee Management\n";
         cout<<"\n0.Display Employees";
         cout<<"\n1.Add Employee";
         cout<<"\n2.Delete Employee";
         cout<<"\n3.Update Employee Account";
         cout<<"\n4.Manage Admins";
         cout<<"\n5.Search Best Employee";
         cout<<"\n99.Logout";

         int employeechoice;
         cout<<"\n\nEnter your choice: ";                 //Asking for choice from user
         cin>>employeechoice;

         //checks for strings and floats ; for all non numeric input
         while(cin.fail())
         {
            cin.clear();
            cin.ignore(100,'\n');
            cout<<"\nInvalid input. Please enter a number: ";
            cin>>employeechoice;
         }

         if(employeechoice==0)
         {
            displayemployees();
         }
         else if(employeechoice==1)
         {
            addemployee();
         }
         else if(employeechoice==2)
         {
            deleteemployee();
         }
         else if(employeechoice==3)
         {
            cout<<"\nUpdating Employee Account\n";
            cout<<"\n1.Update Name";
            cout<<"\n2.Update Password";
            cout<<"\n99.Logout";

            int updatechoice;
            cout<<"\n\nEnter your choice: ";                 //Asking for choice from user
            cin>>updatechoice;

            //checks for strings and floats ; for all non numeric input
            while(cin.fail())
            {
               cin.clear();
               cin.ignore(100,'\n');
               cout<<"\nInvalid input. Please enter a number: ";
               cin>>updatechoice;
            }

            if(updatechoice==1)
            {
              updateemployeename();
            }
            else if(updatechoice==2)
            {
              updateemployeepassword();
            }
            else if(updatechoice==99)
            {
               cout<<"\nLogging out...";
               cout<<"\nLogged out successfully\n";
               break;
            }
            else
            {
               cout<<"\nInvalid choice\n";
               break;
            }
         }
         else if(employeechoice==4)
         {
            cout<<"\nManaging Admins\n";
            cout<<"\nFeatures are limited due to security reasons\n";
            cout<<"\nYou have to use 2FA for this\n";
            cout<<"\n0.Display Admins";
            cout<<"\n1.Add Admin";
            cout<<"\n2.Delete Admin";
            cout<<"\n99.Logout";

            int adminchoice;
            cout<<"\n\nEnter your choice: ";                 //Asking for choice from user
            cin>>adminchoice;

            //checks for strings and floats ; for all non numeric input
            while(cin.fail())
            {
               cin.clear();
               cin.ignore(100,'\n');
               cout<<"\nInvalid input. Please enter a number: ";
               cin>>adminchoice;
            }

            if(adminchoice==0)
            {
               displayadmin();
            }
            else if(adminchoice==1)
            {
               addadmin();
            }
            else if(adminchoice==2)
            {
               deleteadmin();
            }
            else if(adminchoice==99)
            {
               cout<<"\nLogging out...";
               cout<<"\nLogged out successfully\n";
               break;
            }
            else
            {
               cout<<"\nInvalid choice\n";
               break;
            }
         }
         else if(employeechoice==5)
         {
            checkbestemployee();
         }
         else if(employeechoice==99)
         {
            randomdecrease();
            cout<<"\nLogging out...";
            cout<<"\nLogged out successfully\n";
            break;
         }
         else
         {
            cout<<"\nInvalid choice\n";
            break;
         }
         break;
      }
      case 4: 
      {
         int userchoice;
         cout<<"\nUser Management\n";
         cout<<"\n1.Check List Of Users";
         cout<<"\n2.Register User";
         cout<<"\n3.Delete User";
         cout<<"\n4.Update User Account";
         cout<<"\n99.Logout";

         cout<<"\n\nEnter your choice: ";                 //Asking for choice from user
         cin>>userchoice;

         //checks for strings and floats ; for all non numeric input
         while(cin.fail())
         {
            cin.clear();
            cin.ignore(100,'\n');
            cout<<"\nInvalid input. Please enter a number: ";
            cin>>userchoice;
         }

         if(userchoice==1)
         {
            displayusers();
         }
         else if(userchoice==2)
         {
            registeruser();
         }
         else if(userchoice==3)
         {
            deleteuser();
         }
         else if(userchoice==4)
         {
            cout<<"\nUpdate User Account\n";
            cout<<"\n1.Update Name";
            cout<<"\n2.Update Password";
            cout<<"\n99.Logout";

            int updateuserchoice;
            cout<<"\n\nEnter your choice: ";                 //Asking for choice from user
            cin>>updateuserchoice;

            //checks for strings and floats ; for all non numeric input
            while(cin.fail())
            {
               cin.clear();
               cin.ignore(100,'\n');
               cout<<"\nInvalid input. Please enter a number: ";
               cin>>updateuserchoice;
            }

            if(updateuserchoice==1)
            {
               updateusername();
            }
            else if(updateuserchoice==2)
            {
              updateuserpassword();
            }
            else if(updateuserchoice==99)
            {
               randomdecrease();
               cout<<"\nLogging out...";
               cout<<"\nLogged out successfully\n";
               break;
            }
            else
            {
               cout<<"\nInvalid choice\n";
               break;
            }
         }
         else if(userchoice==99)
         {
            cout<<"\nLogging out...";
            cout<<"\nLogged out successfully\n";
            break;
         }
         else
         {
            cout<<"\nInvalid choice\n";
            break;
         }

         break;
      }
      case 5: 
      {
         int cafechoice;
         cout<<"\nCafe Management\n";
         cout<<"\n1.Check Reviews and Suggestions";
         cout<<"\n2.Manage Notifications";
         cout<<"\n3.Check complaints";
         cout<<"\n4.Check List Of Users";
         cout<<"\n5.Check List Of Employees";

         cout<<"\n\nEnter your choice: ";                 //Asking for choice from user
         cin>>cafechoice;

         //checks for strings and floats ; for all non numeric input
         while(cin.fail())
         {
            cin.clear();
            cin.ignore(100,'\n');
            cout<<"\nInvalid input. Please enter a number: ";
            cin>>cafechoice;
         }

         if(cafechoice==1)
         {
           checkreviews();
         }
         else if(cafechoice==2)
         {
           cout<<"\nManage Notifications\n";
             cout<<"\n1.Add Notification";
               cout<<"\n2.Delete Notification";
               cout<<"\n99.Logout";

               int notificationchoice;
               cout<<"\n\nEnter your choice: ";                 //Asking for choice from user
               cin>>notificationchoice;

               //checks for strings and floats ; for all non numeric input
               while(cin.fail())
               {
                  cin.clear();
                  cin.ignore(100,'\n');
                  cout<<"\nInvalid input. Please enter a number: ";
                  cin>>notificationchoice;
               }

               if(notificationchoice==1)
               {
                  addnotification();
               }
               else if(notificationchoice==2)
               {
                  deletenotification();
               }
               else if(notificationchoice==99)
               {
                  randomdecrease();
                  cout<<"\nLogging out...";
                  cout<<"\nLogged out successfully\n";
                  break;
               }
               else
               {
                  cout<<"\nInvalid choice\n";
                  break;
               }
         }
         else if(cafechoice==3)
         {
            checkcomplaints();
         }
         else if(cafechoice==4)
         {
            displayusers();
         }
         else if(cafechoice==5)
         {
            displayemployees();
         }
         else
         {
            cout<<"\nInvalid choice\n";
            break;
         }

         break;
      }

      case 6:
      {
         cout<<"\nDataBase Management\n";
         cout<<"\n1.View Stock Details";
         cout<<"\n2.Add Stock To Database";
         cout<<"\n3.Delete Stock From Database";
         cout<<"\n4.Update Stock Details";
         cout<<"\n99.Logout";

         int stockchoice;
         cout<<"\n\nEnter your choice: ";                 //Asking for choice from user
         cin>>stockchoice;

         //checks for strings and floats ; for all non numeric input
         while(cin.fail())
         {
            cin.clear();
            cin.ignore(100,'\n');
            cout<<"\nInvalid input. Please enter a number: ";
            cin>>stockchoice;
         }

         if(stockchoice==1)
         {
            viewdatabase();
         }
         else if(stockchoice==2)
         {
            adddatabase();
         }
         else if(stockchoice==3)
         {
            deletedatabase();
         }
         else if(stockchoice==4)
         {
            updatedatabase();
         }
         else if(stockchoice==99)
         {
            randomdecrease();
            cout<<"\nLogging out...";
            cout<<"\nLogged out successfully\n";
            break;
         }
         else
         {
            cout<<"\nInvalid choice\n";
            break;
         }

         break;
      }
      case 99: 
      {
            randomdecrease();
            cout<<"\nLogging out...";
            cout<<"\nLogged out successfully\n";
            break;
      }
      default: 
      {
            cout<<"\nInvalid choice\n";
            break;
      }
   
}

   }
   while(adminchoice!=99);
}


//For employee menu
void employeemenu()
{

int employeechoice;

do
{
 cout<<"\n1.Take Orders";
 cout<<"\n2.Search Items";
 cout<<"\n3.See Shedule Orders";
 cout<<"\n4.Job Summary";
 cout<<"\n99.Logout";

 cout<<"\nEnter your choice: ";                 //Asking for choice from user
 cin>>employeechoice;

    //checks for strings and floats ; for all non numeric input
   while(cin.fail())
   {
      cin.clear();
      cin.ignore(100,'\n');
      cout<<"\nInvalid input. Please enter a number: ";
      cin>>employeechoice;
   }


   switch(employeechoice)
   {
      case 1: 
      {        
         takeorder();               //Calling vieworder function to take order
         break;
      }
      case 2: 
      {
         searchitem();                   //Calling searchitem function to search for item
         break;
      }  
      case 3: 
      {
         takesheduleorder();                    //Calling sheduleorder function to shedule order
         break;
      }
      case 4: 
      {

         cout<<"\nJob Summary\n";    
         summary();                    //Calling summary function to view summary

            break;
      }
      case 99: 
      {
            cout<<"\nLogging out...";
            cout<<"\nLogged out successfully\n";
            break;
      }
      default: 
      {
            cout<<"\nInvalid choice\n";
            break;
      }
   
}

}
while(employeechoice!=99);

}


//For user menu
void usermenu()
{
   int userchoice;


   do
   {
      cout<<"\n1.View Menu";
      cout<<"\n2.Place Order";
      cout<<"\n3.Search for item";
      cout<<"\n4.Shedule Order";
      cout<<"\n5.Complaints";
      cout<<"\n6.Notifications";
      cout<<"\n7.Manage Account";
      cout<<"\n99.Logout";

      cout<<"\nEnter your choice: ";                 //Asking for choice from user
      cin>>userchoice;

   //checks for strings and floats ; for all non numeric input
   while(cin.fail())
   {
      cin.clear();
      cin.ignore(100,'\n');
      cout<<"\nInvalid input. Please enter a number: ";
      cin>>userchoice;
   }

      switch(userchoice)
      {
         case 1: 
         {
            displaybyprice();                      //Calling displaystock function to display stock on basis of price
            break;
         }
         case 2:
         {
            placeorder();                    //Calling placeorder function to place order
            break;
         }
         case 3:
         {
            searchitem();                      //Calling searchitem function to search for item
            break;
         }

         case 4:
         {
            sheduleorder();                    //Calling sheduleorder function to shedule order
            break;
         }

         case 5:
         {
            complaint();                     //Calling complaint function to register complaint
            break;
         }

         case 6:
         {
           viewnotifications();              //Calling viewnotifications function to view notifications
            break;
         }

         case 7:                          //For managing account
         {
            int accountchoice;
            cout<<"\nWelcome To Account Management";
            cout<<"\n1.Change Password";
            cout<<"\n2.Change Username";
            cout<<"\n3.Request for account deletion";

            cout<<"\nEnter your choice: ";
            cin>>accountchoice;

            if(accountchoice==1)
            {
               changepassword();                          //Calling changepassword function to change password
            }
            else if(accountchoice==2)
            {
               changeusername();                      //Calling changeusername function to change username
            }
            else if(accountchoice==3)
               cout<<"\nPlease Contact Admin for account deletion as this feature is not available yet due to security reasons\n";

            else
            {
               cout<<"\nInvalid choice";
            }

            break;
         }
      
         case 99:                                     //For logging out
         {
            cout<<"\nYou have been logged out successfully";
            break;
         }  
         default:                        //For invalid choice  
         {
            cout<<"\nInvalid choice";
            break;
         }
      }
   }while(userchoice!=99);
}



