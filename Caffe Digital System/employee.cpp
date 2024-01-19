#include "employee.h"

using namespace std;

//Function to login as employee
int employeelogin()
{
   char username[20];
   char password[20];

   cout<<"\nEnter your employeeid: ";      //Asking for username form user
   cin>>username;

   if(strlen(username)<=4 || strlen(username)>=20)      //If username is not of 4 characters or greater than 20
   {
      cout<<"\nInvalid employeeid out of range\n";
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

   credentials.open("files/credentials/employeelogin.txt");

   char storedusername[20];      
   char storedpassword[20];
   int flag=0;                 //Flag variable to check if login is successful or not

// Read username and password from the file
   while (credentials>>storedusername>>storedpassword)      
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


//Function to display current orders
void takeorder()
{
   fstream processed;
   processed.open("files/caffeesystem/summary.txt", ios::app);     //Opening file in append mode to store processed orders
   ifstream order;
   order.open("files/foodsystem/order.txt");        //Opening file in read mode to read current orders
   char header[100];
   char orderstore[10];
   char itemname[20];
   int quantity;
   int itemprice;
   char employee[20];

   if(!order)      //If file does not exist
   {
      cout<<"\nNo orders yet\n";
      exit(0);
   }

   if(!processed)      //If file does not exist
   {
      cout<<"\nFile not opened ERROR.\n";
      exit(0);
   }

   order.getline(header,100,'\n');                            //Reading header from file

   //Check if file is empty
   if(order.peek()==EOF)
   {
      cout<<"\nNo orders yet\n";
      exit(0);
   }



   cout<<"\nCurrent Orders\n";
   cout<<header<<endl;

   while(order>> orderstore >>itemname >> quantity >> itemprice)                     //Reading from file
   {
      cout<<orderstore<<itemname<<" "<<quantity<<" "<<itemprice<<endl;                       //Displaying order
   }

      cout<<"\nEnter employee username who processed the order: ";
      cin>>employee;

      processbestemployee(employee, 20);      //Calling function to process best employee

      cin.ignore();

      order.close();        //Closing file to read again

      order.open("files/foodsystem/order.txt");        //Opening file in read mode to read current orders

      order.getline(header,100,'\n');                            //Reading header from file
      

   while(order>> orderstore >>itemname >> quantity >> itemprice)                     //Reading from file
   {

      processed<<"Processed By: "<<employee<<" "<<orderstore<<" "<<itemname<<" "<<quantity<<" "<<itemprice<<endl;                       //Storing order in processed orders file
   
   }

   
      order.close();
      processed.close();

      cout<<"\nDo you want a Receipt(y/n): ";
      char choice;
      cin>>choice;

      if (choice=='y' || choice=='Y')
      {
         generatereceipt();
      }
      else 
      {
         cout<<"\nNo receipt is generated\n";
      }




      ofstream clearfile("files/foodsystem/order.txt", ios::trunc);

      clearfile.close();

      order.seekg(0, ios::beg);      //Setting pointer to beginning of file
      
      ofstream writeheader("files/foodsystem/order.txt", ios::app);
      writeheader<<header<<endl;      //Writing header in file again

      writeheader.close();

      cout<<"\nAll orders are processed by "<<employee<<endl;

}

//Function to process shedule orders
void takesheduleorder()
{
   fstream processed;
   processed.open("files/caffeesystem/shedulesummary.txt", ios::app);     //Opening file in append mode to store processed orders
   ifstream order;
   order.open("files/foodsystem/sheduleorder.txt");        //Opening file in read mode to read current orders
   char header[100];
   char orderstore[120];
   char employee[20];

   if(!order)      //If file does not exist
   {
      cout<<"\nNo orders yet\n";
      exit(0);
   }

   if(!processed)      //If file does not exist
   {
      cout<<"\nFile not opened ERROR.\n";
      exit(0);
   }

   order.getline(header,100);                            //Reading header from file


// Check if file is empty
  if(order.peek()==EOF)
   {
      cout<<"\nNo orders yet\n";
      exit(0);
   }

   cout<<"\nCurrent Orders\n";
   cout<<header<<endl;

   while(order.getline(orderstore,120,'\n'))                     //Reading from file
   {
      cout<<orderstore<<endl;                       //Displaying order
   }

    cout<<"\nDo you want to process the order(y/n): ";
      char choice;
      cin>>choice;

   if (choice=='y' || choice=='Y')
   {

      cout<<"\nEnter employee username who processed the order: ";
      cin>>employee;

      processbestemployee(employee, 20);      //Calling function to process best employee

      cin.ignore();

      order.close();        //Closing file to read again

      order.open("files/foodsystem/sheduleorder.txt");        //Opening file in read mode to read current orders

      order.getline(header,100,'\n');                            //Reading header from file

   while(order.getline(orderstore,100,'\n'))                     //Reading from file
   {

      processed<<"Processed By: "<<employee<<" "<<orderstore<<endl;                       //Storing order in processed orders file
   
   }

   
      order.close();
      processed.close();

      ofstream clearfile("files/foodsystem/sheduleorder.txt", ios::trunc);

      order.seekg(0, ios::beg);

      ofstream writeheader("files/foodsystem/sheduleorder.txt", ios::app);
      writeheader<<header<<endl;      //Writing header in file again

      cout<<"\nAll orders are processed by "<<employee<<endl;

      clearfile.close();    
}
else 
{
   cout<<"\nNo orders are processed\n";
   order.close();
   processed.close();
}

}


//Funtion for Summary of employee
void summary()
{  
   cout<<"\nSummary\n";
   cout<<"-----------------------\n";
   cout<<"\nMonthly Summary\n";
         //Using random function to generate random number
         srand(time(0));
         int totalorders=rand()%100;               //Generating random number between 0 to 100 for total orders
         int totalsales=rand()%10000;              //Generating random number between 0 to 10000 for total sales
         int totalcomplaints=rand()%10;            //Generating random number between 0 to 10 for total complaints
         int totalsuggestions=rand()%10;           //Generating random number between 0 to 10 for total suggestions
         int dailyworkinghours=rand()%10;               //Generating random number between 0 to 10 for working hours
         int totalworkinghours=dailyworkinghours*30;    //Calculating total working hours
         int totalwages=totalworkinghours*1000;          //Calculating total wages

            cout<<"\nJob Summary\n";
            cout<<"-----------------------\n";
      

            cout<<"\nTotal Orders: "<<totalorders;            //Displaying total orders
            cout<<"\nTotal Sales: "<<totalsales;              //Displaying total sales
            cout<<"\nTotal Complaints: "<<totalcomplaints;    //Displaying total complaints
            cout<<"\nTotal Suggestions: "<<totalsuggestions;  //Displaying total suggestions
            cout<<"\nTotal Working Hours: "<<totalworkinghours;  //Displaying total working hours
            cout<<"\nTotal Estimated Wages: Pkr "<<totalwages;              //Displaying total wages

}

//Function to generate receipt
void generatereceipt()
{
   char itemname[20];
   int quantity;
   int itemprice;
   int totalprice=0;
   ifstream processed;
   processed.open("files/foodsystem/order.txt");     //Opening file in append mode to store processed orders
   char header[100];
   char orderstore[100];

   if(!processed)      //If file does not exist
   {
      cout<<"\nFile not opened ERROR.\n";
      exit(0);
   }

   processed.getline(header,100,'\n');                           //Reading header from file

    time_t now = time(0);
    char* dt = ctime(&now);

    srand(time(0));

    cout << "\nReceipt\n";
    cout<<"\nOrder Number: "<<rand()%1000<<endl;      //Generating random number between 0 to 1000 for order number
    cout << "---------------------------------------------------------------------\n";
    cout << "Order Summary\n";
   cout << "Date and Time: " << dt;
    cout << "---------------------------------------------------------------------\n";
    cout << setw(20) << "Item Name" << setw(10) << "Quantity" << setw(10) << "Price" << setw(10) << "Tax(16%)" << setw(10) << "Total" << endl;
    cout << "---------------------------------------------------------------------\n";

    while (processed >> orderstore >> itemname >> quantity >> itemprice) 
    {
        const float taxRate = 0.16;
        float tax = taxRate * (quantity * itemprice);
        float totalWithTax = (quantity * itemprice) + tax;

        cout << setw(20) << itemname << setw(10) << quantity << setw(10) << itemprice << setw(10) << tax << setw(10) << totalWithTax << endl;

        totalprice += totalWithTax;
    }

    processed.close();

    cout << "\nGrand Total: PKR " << totalprice << endl;
      cout << "---------------------------------------------------------------------\n";

}

void processbestemployee(char name[] , int size)
{
   fstream employee;
   employee.open("files/caffeesystem/overall/bestemployee.txt", ios::in);    //Opening file in read mode to read best employee

   char header[60];
   int orders;
   char employeename[20];

   if(!employee)      //If file does not exist
   {
      cout<<"\nFile not opened ERROR.\n";
      exit(0);
   }
   
   employee.getline(header,60,'\n');                           //Reading header from file

   while (employee >> employeename >> orders)        //for checking the orders
   {
      if(strcmp(employeename,name)==0)
      {
         orders++;
      }
   }

   employee.close();


   //If employee is delivering first order
   if(orders==0)
   {
      employee.open("files/caffeesystem/overall/bestemployee.txt", ios::app);    
      employee<<name<<" "<<orders+1<<endl;
      employee.close();
   }
   else
   {
         employee.open("files/caffeesystem/overall/bestemployee.txt", ios::in);

         employee.getline(header,60,'\n');                           //Reading header from file

         ofstream temp("files/caffeesystem/overall/temp.txt", ios::app);

         temp<<header;  //Writing header from file

         while (employee >> employeename >> orders) 
         {
           
            if(strcmp(employeename,name)==0)
            {
               orders++;
               temp<<employeename<<" "<<orders<<endl;
            }
            else
            {
               temp<<employeename<<" "<<orders<<endl;
            }
         }

         employee.close();
         temp.close();

         remove("files/caffeesystem/overall/bestemployee.txt");
         rename("files/caffeesystem/overall/temp.txt","files/caffeesystem/overall/bestemployee.txt");
   }

}
