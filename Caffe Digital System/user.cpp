#include "user.h"

using namespace std;

//Function to login as user
int userlogin()
{
   char username[20];
   char password[20];

   cout<<"\nEnter your userid(rollno or staffid): ";      //Asking for username form user
   cin>>username;

   if(strlen(username)<=4 || strlen(username)>=20)      //If username is not of 4 characters or greater than 20
   {
      cout<<"\nInvalid userid out of range\n";
      exit(0);
   }

   cout<<"\nEnter your password: ";      //Asking for password from user
   cin>>password;

   if(strlen(password)>20 || strlen(username)<=4)      //If password is greater than 20 characters or less than 5
   {
      cout<<"\nPassword out of range\n";
      exit(0);
   }

   ifstream credentials;            //Creating object of ifstream class for reading

   credentials.open("files/credentials/userlogin.txt");

   char storedusername[20];      
   char storedpassword[20];
   int flag=0;                 //Flag variable to check if login is successful or not

// Read username and password from the file
   while (credentials>>storedusername>>storedpassword)      //Reading from file (username and password)
   {
      if(strcmp(username,storedusername)==0 && strcmp(password,storedpassword)==0)    //Comparing username and password with database
         {
            flag=1;
            break;   //If username and password matches then break the loop
         }
         
   }
   
   credentials.close();

   return flag;


}

//Function to place order
void placeorder()
{ 
   char Header[30];
    char useritem[20];
   char item[20];
    int userquantity;
   int price;
   int quantity;
   int totalprice;
   int grandtotal = 0;
   char choice;
   ofstream order;
   ifstream stocks;

   // Open files
   stocks.open("files/foodsystem/stocks.txt");
   order.open("files/foodsystem/order.txt", ios::app);

   if(!stocks || !order)
    {
      cout << "Error opening file" << endl;
      exit(1);
   }

      stocks.close(); // Close the file

   do {
      cout << "\nEnter the item you want to order: ";
      cin >> useritem;
      cout << "Enter the quantity: ";
      cin >> userquantity;

      if(userquantity<=0)
      {
         cout<<"\nIs this a joke?Please enter a valid quantity. Now you have to start again.";
         exit(1);
      }


      // Check if the item is in the menu
      stocks.open("files/foodsystem/stocks.txt");
      bool itemFound = false;

      stocks.getline(Header,30,'\n');    //To read the header of the file

      while (stocks >> item >> quantity >> price)   //Reading from file 
       {
         if (strcmp(item, useritem) == 0) 
         {
            itemFound = true;
            break;
         }
      }
      stocks.close();

      if (!itemFound) 
      {
         cout << "Item not found in the menu. Please enter a valid item. Have A look at menu and then come back. Ty" << endl;
         exit(1);
      }

      // Check if the requested quantity is available
      if (userquantity > quantity)
       {
         cout << "Insufficient quantity in stock.Please Check Menu To Ensure if it is available. Have a Look and then come. Ty" << endl;
         exit(1);
      }

      totalprice = price * userquantity;
      grandtotal += totalprice;

      // Update the stock in the menu file
      stocks.open("files/foodsystem/stocks.txt");
      ofstream temp("files/foodsystem/temp.txt");
      stocks.getline(Header,30,'\n');    //To read the header of the file



      temp << Header << "\n"; // Write the header to the temp file


      while (stocks >> item >> quantity >> price) 
      {
         if (strcmp(item, useritem) == 0) 
         {
            quantity -= userquantity;
            // Write order details to the order file WHEN THE ITEM IS FOUND else it is not writting correct things in order file
            order <<"Order: "<< useritem<<" " << userquantity<<" "<<price<<" "<<totalprice << "\n";
         }
         temp << item<<" " <<quantity<<" " << price << "\n";
      }
      stocks.close();
      temp.close();
      remove("files/foodsystem/stocks.txt");
      rename("files/foodsystem/temp.txt", "files/foodsystem/stocks.txt");



      cout << "\nDo you want to order more items (y/n): ";
      cin >> choice;


   } 
   while (choice == 'y');

   cout << "\nYour total bill is: PKR " << grandtotal;
   cout << "\nYour order has been placed successfully";
   cout<<"\nThank You For Ordering. Have A Nice Day!!\n";
   cout<<"\nYour order will be delivered to you within 5-10 minutes.\n";


   order.close();
}


//Function to Shedule Order
void sheduleorder()
{
  char Header[30];
    char useritem[20];
   char item[20];
    int userquantity;
   int price;
   int quantity;
   int totalprice;
   int grandtotal = 0;
   char choice;
   int day;
   int time;
   ofstream order;
   ifstream stocks;

   // Open files
   stocks.open("files/foodsystem/stocks.txt");
   order.open("files/foodsystem/sheduleorder.txt", ios::app);

   if(!stocks || !order)
    {
      cout << "Error opening file" << endl;
      exit(1);
   }

      stocks.close(); // Close the file

      //Displaying the rules for sheduling order
      cout<<"\nShedule Order\n";
      cout<<"\nOrder sheduled cannot be cancelled.\n";
      cout<<"\nYou can shedule your order for any day of the week except weekend.\n";
      cout<<"\nYou can shedule your order from 8:00 am to 7:00 pm.\n";
      cout<<"\nYou can shedule your order for any item of the menu.\n";
      cout<<"\nYou have to pay the bill at the time of order.\n";

      //Taking input from user for day and time with checks
      cout<<"\nEnter the day you want to shedule your order(1 for Monday, 2 For Tuesday and so on): ";
      cin>>day;

      if(day<=0 || day>5)
      {
         cout<<"\nPlease enter a valid day. Now you have to start again.";
         exit(1);
      }

      cout<<"\nUse 24 Hours Format\n";
      cout<<"\nEnter the time you want to shedule your order(8 for 8:00 am, 9 for 9:00 am and so on): ";
      cin>>time;

      if(time<8 || time>19)
      {
         cout<<"\nPlease enter a valid time. Now you have to start again.";
         exit(1);
      }

     //Order Placing.
   do {


      cout << "\nEnter the item you want to order: ";
      cin >> useritem;
      cout << "Enter the quantity: ";
      cin >> userquantity;

      if(userquantity<=0)
      {
         cout<<"\nIs this a joke?Please enter a valid quantity. Now you have to start again.";
         exit(1);
      }


      // Check if the item is in the menu
      stocks.open("files/foodsystem/stocks.txt");
      bool itemFound = false;

      stocks.getline(Header,30,'\n');    //To read the header of the file

      while (stocks >> item >> quantity >> price)   //Reading from file 
       {
         if (strcmp(item, useritem) == 0) 
         {
            itemFound = true;
            break;
         }
      }
      stocks.close();

      if (!itemFound) {
         cout << "Item not found in the menu. Please enter a valid item. Have A look at menu and then come back. Ty" << endl;
         exit(1);
      }

      // Check if the requested quantity is available
      if (userquantity > quantity)
       {
         cout << "Insufficient quantity in stock.Please Check Menu To Ensure if it is available. Have a Look and then come. Ty" << endl;
         exit(1);
      }

      totalprice = price * userquantity;
      grandtotal += totalprice;

      // Update the stock in the menu file
      stocks.open("files/foodsystem/stocks.txt");
      ofstream temp("files/foodsystem/temp.txt");
      stocks.getline(Header,30,'\n');    //To read the header of the file



      temp << Header << "\n"; // Write the header to the temp file


      while (stocks >> item >> quantity >> price) 
      {
         if (strcmp(item, useritem) == 0) 
         {
            quantity -= userquantity;
            // Write order details to the order file WHEN THE ITEM IS FOUND else it is not writting correct things in order file
            order <<"SheduledOrder: "<<time<<" "<<day<<" "<< useritem<<" " << userquantity<<" "<<price<<" "<<totalprice << "\n";
         }
         temp << item<<" " <<quantity<<" " << price << "\n";
      }
      stocks.close();
      temp.close();
      remove("files/foodsystem/stocks.txt");
      rename("files/foodsystem/temp.txt", "files/foodsystem/stocks.txt");



      cout << "\nDo you want to order more items (y/n): ";
      cin >> choice;


   } 
   while (choice == 'y');

   cout <<"\nYour total bill is: PKR " << grandtotal;
   cout <<"\nYour order has been placed successfully";
   cout <<"\nYou have placed order for day"<<day<<" at "<<time<<" hours";
   cout<<"\nThank You For Ordering. Have A Nice Day!!\n";
   cout<<"\nMake sure you are available at the time of delivery.\n";
   
   


   order.close();
}

//Function For Complaints
void complaint()
{
   char complaint[10000];
   char name[20];
   char cattegory[20];
   ofstream comp;
   comp.open("files/caffeesystem/complains.txt", ios::app);

   if(!comp)
    {
      cout << "Error opening file" << endl;
      exit(1);
   }

   cout<<"\nComplaints\n";
   cout<<"\nPlease enter your username: ";          //Taking name of user
   cin>>name;

   cout<<"\nPlease enter the cattegory of your complaint(max 10,000 characters): ";       //Taking cattegory of complaint
   cin>>cattegory;

   cout<<"\nPlease enter your complaint: ";             //Taking complaint
   cin.ignore();
   cin.getline(complaint,10000);

   comp<<"Name: "<<name<<"\n";
   comp<<"Cattegory: "<<cattegory<<"\n";
   comp<<"Complain: "<<complaint<<"\n\n";



   cout<<"\nYour complaint has been registered successfully.\n";
   cout<<"\nThank You.We will review your complaints and take necessary actions.\n";

   comp.close();
}

//Function For Viewing Notifications
void viewnotifications()
{
   char notification[10000];
   ifstream noti;
   noti.open("files/caffeesystem/Notifications.txt");       //Opening file

   if(!noti)
    {
      cout << "Error opening file" << endl;
      exit(1);
   }

   cout<<"\nNotifications\n";

if(noti.eof())             //Checking if file is empty or not
   {
      cout<<"\nNo Notifications\n";
   }

   while(noti.getline(notification,10000))         //Reading from file
   {
      cout<<notification<<"\n";
   }

   noti.close();
}

//Function For Changing Password by entering old password
void changepassword()
{
   char username[20];
   char password[20];
   char newpassword[20];

   cout<<"\nEnter your current username: ";
   cin>>username;

   cout<<"\nEnter your current password: ";
   cin>>password;

   ifstream credentials("files/credentials/userlogin.txt");
   ofstream temp("files/credentials/temp.txt");

   if (!credentials || !temp) 
   {
      cout << "Error opening files!" << endl;
      return;
   }

   char storedusername[20];
   char storedpassword[20];
   int flag = 0;

   // Check if the current username and password match
   while (credentials >> storedusername >> storedpassword) 
   {
      if (strcmp(username, storedusername) == 0 && strcmp(password, storedpassword) == 0)
       {
         flag = 1;
         break;
      }
   }

   credentials.close();

   if (flag)          //If username and password match
    {
        cout << "\nEnter your new password: ";
        cin >> newpassword;

        if(newpassword==password)            //Checking if new password is same as old password
        {
            cout<<"\nNew password cannot be same as old password. Please try again.\n";
            exit(1);
            return;
        }

        if(strlen(newpassword) < 8)          //Checking if new password is atleast 8 characters long
        { 
            cout<<"\nPassword must be atleast 8 characters long. Please try again.\n";
            exit(1);
            return;
        }

        if(strlen(newpassword) > 20)         //Checking if new password is atmost 20 characters long
         {
               cout<<"\nPassword must be atmost 20 characters long. Please try again.\n";
                exit(1);
               return;
         }

        // Updating the username in the file
        credentials.open("files/credentials/userlogin.txt");

        while (credentials >> storedusername >> storedpassword) 
        {
            if (strcmp(username, storedusername) == 0) 
            {
                temp << storedusername << " " << newpassword << "\n";
            } 

            else 
            {
                temp << storedusername << " " << storedpassword << "\n";
            }
        }

        credentials.close();
        temp.close();

        // Rename the temp file to the original file
        remove("files/credentials/userlogin.txt");
        rename("files/credentials/temp.txt", "files/credentials/userlogin.txt");

        cout << "\nPassword changed successfully.\n";
    } 

    else                //If username and password do not match 
    {
        cout << "\nInvalid username or password. Password Change failed.\n";
    }
}

//Function For Changing Password Username
void changeusername()
{
    char username[20];
    char password[20];
    char newusername[20];

    cout<<"\nEnter your current username: ";         
    cin>>username;

    cout<<"\nEnter your current password: ";
    cin>>password;

    ifstream credentials("files/credentials/userlogin.txt");
    ofstream temp("files/credentials/temp.txt");

    if (!credentials || !temp) 
    {
        cout << "Error opening files!" << endl;
        return;
    }

    char storedusername[20];
    char storedpassword[20];
    int flag = 0;

    // Check if the current username and password match
    while (credentials >> storedusername >> storedpassword) 
    {
        if (strcmp(username, storedusername) == 0 && strcmp(password, storedpassword) == 0)
        {
            flag = 1;
            break;
        }
    }

    credentials.close();

    if (flag)          //If username and password match
    {
        cout << "\nEnter your new username: ";
        cin >> newusername;

      if(newusername==username)           //Checking if new username is same as old username
        {
            cout<<"\nNew password cannot be same as old password. Please try again.\n";
             exit(1);
            return;
        }

        if(strlen(newusername) < 4)       //Checking if new username is atleast 5 characters long
        {
            cout<<"\nUsername must be atleast 5 characters long. Please try again.\n";
             exit(1);
            return;
        }

        if(strlen(newusername) > 20)       //Checking if new username is atmost 20 characters long
         {
               cout<<"\nUserename must be atmost 20 characters long. Please try again.\n";
                exit(1);
               return;
         }

        // Updating the username in the file
        credentials.open("files/credentials/userlogin.txt");

        while (credentials >> storedusername >> storedpassword) 
        {
            if (strcmp(username, storedusername) == 0) 
            {
                temp << newusername << " " << storedpassword << "\n";
            } 

            else 
            {
                temp << storedusername << " " << storedpassword << "\n";
            }
        }

        credentials.close();
        temp.close();

        // Rename the temp file to the original file
        remove("files/credentials/userlogin.txt");
        rename("files/credentials/temp.txt", "files/credentials/userlogin.txt");

        cout << "\nUsername changed successfully.\n";
    } 

    else                //If username and password do not match 
    {
        cout << "\nInvalid username or password. Change username failed.\n";
    }
}
