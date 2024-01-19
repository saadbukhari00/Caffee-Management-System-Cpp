#include "admin.h"

using namespace std;

//Function to login as admin
int adminlogin()
{
   char username[20];
   char password[20];

   cout<<"\nEnter your username: ";      //Asking for username form user
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

   credentials.open("files/credentials/adminlogin.txt");

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

//Function to display order History
void orderhistory()
{
   ifstream processed;
   processed.open("files/caffeesystem/summary.txt");     //Opening file in read mode to read processed orders

   char order[150];      //Variable to store order
   int count=0;          //Variable to count numb

   cout<<"\nNormal Orders\n";
   cout<<"----------------\n";

   while(processed.getline(order,150))      //Reading from file
   {
      cout<<order<<endl;      //Displaying order
      count++;                //Incrementing count
   }

   if(count==1)      //If count is 1 then no orders are processed
   {
      cout<<"\nNo orders processed yet\n";
   }

   processed.close();      //Closing file

   ifstream sheduled;
   sheduled.open("files/caffeesystem/shedulesummary.txt");     //Opening file in read mode to read processed orders

   char sheduledorder[150];      //Variable to store order
   int sheduledcount=0;          //Variable to count numb

   cout<<"\nSheduled Orders\n";
   cout<<"----------------\n";

   while(sheduled.getline(sheduledorder,150))      //Reading from file
   {
      cout<<sheduledorder<<endl;      //Displaying order
      sheduledcount++;                //Incrementing count
   }

   if(sheduledcount==1)      //If count is 1 then no orders are processed
   {
      cout<<"\nNo orders processed yet\n";
   }

   sheduled.close();      //Closing file


}

//Function to reset orders 
void resetorders()
{
   fstream processed;
   char header[200];

   //Get header fromn file
   processed.open("files/caffeesystem/summary.txt", ios::in);
   processed.getline(header,200,'\n');
   processed.close();

//Clears file
   processed.open("files/caffeesystem/summary.txt", ios::trunc);  
   processed.close();

   //Stores header in file
   processed.open("files/caffeesystem/summary.txt", ios::out);
   processed<<header<<endl;
   processed.close();   


   cout<<"\nAll Orders Summary reset successfully\n";

}

//Function to reset shedyuled orders summary
void resetsheduleorders()
{
   fstream processed;
   char header[200];

   //Get header fromn file
   processed.open("files/caffeesystem/shedulesummary.txt", ios::in);
   processed.getline(header,200,'\n');
   processed.close();

//Clears file
   processed.open("files/caffeesystem/shedulesummary.txt", ios::trunc);  
   processed.close();

   //Stores header in file
   processed.open("files/caffeesystem/shedulesummary.txt", ios::out);
   processed<<header<<endl;
   processed.close();   


   cout<<"\nAll SheduledOrders Summary reset successfully\n";

}

//Function to check complaints
void checkcomplaints()
{
   ifstream complaints;
   complaints.open("files/caffeesystem/complains.txt");     //Opening file in read mode to read processed orders

   char complaint[200];      //Variable to store order

      //Check if no complaints are there
      if(complaints.peek()==EOF)
   {
      cout<<"\nNo Complaints yet\n";
      exit(0);
   }

   cout<<"\nComplaints\n";
   cout<<"----------------\n";

   while(complaints.getline(complaint,200))      //Reading from file
   {
      cout<<complaint<<endl;      //Displaying order
   }



   complaints.close();      //Closing file
}

//Function to manage Reviews
void checkreviews()
{
   ifstream reviews;
   reviews.open("files/caffeesystem/reviews.txt");     //Opening file in read mode to read processed orders

   char review[200];      //Variable to store order

      //Check if no complaints are there
      if(reviews.peek()==EOF)
   {
      cout<<"\nNo Reviews yet\n";
      exit(0);
   }

   cout<<"\nReviews\n";
   cout<<"----------------\n";

   while(reviews.getline(review,200))      //Reading from file
   {
      cout<<review<<endl;      //Displaying order
   }

   reviews.close();      //Closing file

}

//Function to display users
void displayusers()
{
   ifstream users;
   users.open("files/credentials/userlogin.txt");     //Opening file in read mode to read processed orders

   char user[20];      //Variable to store order
   char garbage[20];
   int count =0;

   cout<<"\nUsers\n";
   cout<<"----------------\n";
   cout<<"\nFollowing are the users currently Using CDS\n";

   while(users>>user>>garbage)      //Reading from file
   {
      cout<<user<<endl;      //Displaying order
      count++;
   }

   cout<<"\nTotal Users: "<<count<<endl;

   users.close();      //Closing file

}

//Function to display total employees
void displayemployees()
{
   ifstream employees;
   employees.open("files/credentials/employeelogin.txt");     //Opening file in read mode to read processed orders

   char employee[20];      //Variable to store order
   char garbage[20];
   int count =0;

   cout<<"\nEmployees\n";
   cout<<"----------------\n";
   cout<<"\nFollowing are the employees working in caffee\n";

   while(employees>>employee>>garbage)      //Reading from file
   {
      cout<<employee<<endl;      //Displaying order
      count++;
   }

   cout<<"\nTotal Employees: "<<count<<endl;

   employees.close();      //Closing file

}

//Function to Add new employee
void addemployee()
{
   char username[20];
   char password[20];
   char confirm[20];

   cout<<"\nEnter Username: ";
   cin>>username;

   if(strlen(username)>20)
   {
      cout<<"\nUsername should be less than 20 characters\n";
      exit(0);
   }


   cout<<"\nEnter Password: ";
   cin>>password;

   if(strlen(password)>20 || strlen(password)<8)
   {
      cout<<"\nPassword should be in range (8-20) characters\n";
      exit(0);
   }

   cout<<"\nConfirm Password: ";
   cin>>confirm;

   if(strcmp(password,confirm)==0)
   {
      ofstream employee;
      employee.open("files/credentials/employeelogin.txt",ios::app);     //Opening file in read mode to read processed orders

      employee<<username<<" "<<password<<endl;

      cout<<"\nEmployee Added Successfully\n";

      employee.close();      //Closing file
   }
   else
   {
      cout<<"\nPassword and Confirm Password does not match\n";
   }
}

//Function to remove employee
void deleteemployee()
{
   char username[20];
   char user[20];
   char pass[20];

   cout<<"\nEnter Username: ";
   cin>>username;

   ifstream employee;
   employee.open("files/credentials/employeelogin.txt");     //Opening file in read mode to read processed orders

   ofstream temp;
   temp.open("files/credentials/temp.txt",ios::app);     //Opening file in read mode to read processed orders

   cout<<"\nAre you sure you want to remove "<<username<<" from employees list (y/n): ";
   char choice;
   cin>>choice;

if(choice=='y' || choice=='Y')
   {
   cout<<"\nRemoving Employee\n";
   while(employee>>user>>pass)      //Reading from file
   {

   //writes the users to temp file
      if(strcmp(username,user)!=0)
      {
         temp<<user<<" "<<pass<<endl;
      }
   }

   employee.close();      //Closing file
   temp.close();

   remove("files/credentials/employeelogin.txt");
   rename("files/credentials/temp.txt","files/credentials/employeelogin.txt");

   cout<<"\nEmployee Removed Successfully\n";
   }
   else
   {
      cout<<"\nEmployee not removed\n";
   }
}

//Function to update employee name
void updateemployeename()
{
   char username[20];
   char user[20];
   char pass[20];
   char newname[20];

   cout<<"\nEnter Username to be updated: ";
   cin>>username;

   ifstream employee;
   employee.open("files/credentials/employeelogin.txt");     //Opening file in read mode to read usernames

   ofstream temp;
   temp.open("files/credentials/temp.txt",ios::app);     //Opening file in write mode to write usernames

   cout<<"\nEnter New Username: ";
   cin>>newname;

   if(strlen(newname)>20 || strlen(newname)<5)
   {
      cout<<"\nUsername should be in range (5-20) characters\n";
      exit(0);
   }

   cout<<"\nAre you sure you want to update "<<username<<" to "<<newname<<" (y/n): ";
   char choice;
   cin>>choice;

if(choice=='y' || choice=='Y')
   {
   cout<<"\nUpdating Employee Username\n";
   while(employee>>user>>pass)      //Reading from file
   {
      if(strcmp(username,user)==0)
      {
         temp<<newname<<" "<<pass<<endl;
      }
      else
      {
         temp<<user<<" "<<pass<<endl;
      }

   }
   employee.close();      //Closing file
   temp.close();

   remove("files/credentials/employeelogin.txt");
   rename("files/credentials/temp.txt","files/credentials/employeelogin.txt");

   cout<<"\nEmployee Username Updated Successfully\n";
   }
   else
   {
      cout<<"\nEmployee Username not updated.\n";
   }

}

//Function to update employee password
void updateemployeepassword()
{
   char username[20];
   char user[20];
   char pass[20];
   char newpass[20];

   cout<<"\nEnter Username for whom password is to be updated: ";
   cin>>username;

   ifstream employee;
   employee.open("files/credentials/employeelogin.txt");     //Opening file in read mode to read usernames

   ofstream temp;
   temp.open("files/credentials/temp.txt",ios::app);     //Opening file in write mode to write usernames

   cout<<"\nEnter New Password: ";
   cin>>newpass;

   if(strlen(newpass)>20 || strlen(newpass)<8)
   {
      cout<<"\nPassowrd should be in range (8-20) characters\n";
      exit(0);
   }

   cout<<"\nAre you sure you want to update passowrd of "<<username<<" (y/n): ";
   char choice;
   cin>>choice;

if(choice=='y' || choice=='Y')
   {
   cout<<"\nUpdating Employee Password\n";
   while(employee>>user>>pass)      //Reading from file
   {
      if(strcmp(username,user)==0)
      {
         temp<<user<<" "<<newpass<<endl;
      }
      else
      {
         temp<<user<<" "<<pass<<endl;
      }

   }
   employee.close();      //Closing file
   temp.close();

   remove("files/credentials/employeelogin.txt");
   rename("files/credentials/temp.txt","files/credentials/employeelogin.txt");

   cout<<"\nEmployee password Updated Successfully\n";
   }
   else
   {
      cout<<"\nEmployee passowrd not updated.\n";
   }

}

//Function to display admins
void displayadmin()
{
   char admin[20];
   char garbage[20];
   int count=0;

   ifstream admins;
   admins.open("files/credentials/adminlogin.txt");     //Opening file in read mode to read processed orders

   cout<<"\nFollowing are the admins working in caffee\n";

   while(admins>>admin>>garbage)      //Reading from file
   {
      cout<<admin<<endl;      //Displaying order
      count++;
   }

   cout<<"\nTotal Admins: "<<count<<endl;

   admins.close();      //Closing file

}

//Function to add admin
void addadmin()
{
   char username[20];
   char password[20];
   char confirm[20];

   cout<<"\nEnter Admin to be added: ";
   cin>>username;

   if(strlen(username)>20 || strlen(username)<5)
   {
      cout<<"\nUsername should be in range (5-20) characters\n";
      exit(0);
   }

   cout<<"\nEnter Password: ";
   cin>>password;

   if(strlen(password)>20 || strlen(password)<8)
   {
      cout<<"\nPassowrd should be in range (8-20) characters\n";
      exit(0);
   }

   cout<<"\nConfirm Password: ";
   cin>>confirm;

   cout<<"\nEnter OTP for this operation: ";
   int otp;
   cin>>otp;
   
   if(strcmp(password,confirm)==0)
   {
      ofstream admin;
      admin.open("files/credentials/adminlogin.txt",ios::app);     //Opening file in write mode to write processed orders

      admin<<username<<" "<<password<<endl;      //Writing to file

      admin.close();      //Closing file

      cout<<"\nAdmin Added Successfully\n";
      cout<<"\nWelcome "<<username<<endl;
      cout<<"\nUsername: "<<username<<endl;
      cout<<"\nPassword: "<<password<<endl;
   }
   else
   {
      cout<<"\nPassword and Confirm Password does not match\n";
   }

}

//Function to remove admin
void deleteadmin()
{ 
   char username[20];
   char user[20];
   char pass[20];

   cout<<"\nEnter Username for admin to be deleted: ";
   cin>>username;

   ifstream employee;
   employee.open("files/credentials/adminlogin.txt");     //Opening file in read mode to read admins

   ofstream temp;
   temp.open("files/credentials/temp.txt",ios::app);     //Opening file in read mode to write admins back

   cout<<"\nEnter OTP for this operation: "; 
   int otp;
   cin>>otp;

   cout<<"\nAre you sure you want to remove "<<username<<" from admin list (y/n): ";
   char choice;
   cin>>choice;

if(choice=='y' || choice=='Y')
   {
   cout<<"\nRemoving Admin\n";
   while(employee>>user>>pass)      //Reading from file
   {

   //writes the users to temp file
      if(strcmp(username,user)!=0)
      {
         temp<<user<<" "<<pass<<endl;
      }
   }

   employee.close();      //Closing file
   temp.close();

   remove("files/credentials/adminlogin.txt");
   rename("files/credentials/temp.txt","files/credentials/adminlogin.txt");

   cout<<"\nAdmin Removed Successfully\n";
   }
   else
   {
      cout<<"\nAdmin not removed\n";
   }
}

//Function to Check Best Employee on basis of orderes processed
void checkbestemployee()
{
    char head[30];
    fstream employee;
    employee.open("files/caffeesystem/overall/bestemployee.txt"); // Opening file in read mode to read employees

    if (!employee) {
        cout << "Error opening bestemployee.txt\n";
         exit(0);
    }

    employee.getline(head, 50,'\n');      //Reading header line
    int rows = 0;

    // Counting the number of rows in the file
    while (employee.getline(head, 50, '\n'))
    {
      rows++;
    }

   employee.close();      //Closing file
   employee.open("files/caffeesystem/overall/bestemployee.txt"); // Opening file in read mode to read employees

    char** usernames = new char*[rows];
    int* orders = new int[rows];

    employee.getline(head, 50); // Read and discard the header line

    // Reading data into dynamic arrays
    for (int i = 0; i < rows; i++) 
    {
        usernames[i] = new char[20];
        employee >> usernames[i] >> orders[i];
    }

    // Sort the arrays based on the number of orders in descending order
    for (int i = 0; i < rows; i++)
     {
        for (int j = i + 1; j < rows; j++) 
        {
            if (orders[i] < orders[j]) 
            {
                swap(usernames[i], usernames[j]);
                swap(orders[i], orders[j]);
            }
        }
    }

    // Print the sorted data
    for (int i = 0; i < rows; i++)
     {
        cout << "Username: " << usernames[i] << "\n Orders: " << orders[i] << endl;
     }

    // Print the employee with the highest number of orders (first entry after sorting)
    cout << "\nThe best employee is: " << usernames[0] << " with " << orders[0] << " orders." << endl;

    // Free memory
    for (int i = 0; i < rows; i++)
          delete[] usernames[i];

    delete[] usernames;
    delete[] orders;

    employee.close(); // Close the file


}

//Function to register user
void registeruser()
{
   char username[20];
   char password[20];
   char confirm[20];

   cout<<"\nEnter Username: ";
   cin>>username;

   if(strlen(username)>20 || strlen(username)<5)
   {
      cout<<"\nUsername should be in range (5-20) characters\n";
      exit(0);
   }

   cout<<"\nEnter Password: ";
   cin>>password;

   if(strlen(password)>20 || strlen(password)<8)
   {
      cout<<"\nPassowrd should be in range (8-20) characters\n";
      exit(0);
   }

   cout<<"\nConfirm Password: ";
   cin>>confirm;

   if(strcmp(password,confirm)==0)
   {
      ofstream user;
      user.open("files/credentials/userlogin.txt",ios::app);     //Opening file in write mode to write processed orders

      user<<username<<" "<<password<<endl;      //Writing to file

      user.close();      //Closing file

      cout<<"\nUser Registered Successfully\n";
      cout<<"\nUsername: "<<username<<endl;
      cout<<"\nPassword: "<<password<<endl;
   }
   else
   {
      cout<<"\nPassword and Confirm Password does not match\n";
   }

}

//Function to remove user
void deleteuser()
{ 
   char username[20];
   char user[20];
   char pass[20];

   cout<<"\nEnter Username for user to be deleted: ";
   cin>>username;

   ifstream employee;
   employee.open("files/credentials/userlogin.txt");     //Opening file in read mode to read admins

   ofstream temp;
   temp.open("files/credentials/temp.txt",ios::app);     //Opening file in read mode to write admins back

   cout<<"\nAre you sure you want to remove "<<username<<" from user list (y/n): ";
   char choice;
   cin>>choice;

if(choice=='y' || choice=='Y')
   {
   cout<<"\nRemoving User\n";
   while(employee>>user>>pass)      //Reading from file
   {
   //writes the users to temp file
      if(strcmp(username,user)!=0)
      {
         temp<<user<<" "<<pass<<endl;
      }
   }

   employee.close();      //Closing file
   temp.close();

   remove("files/credentials/userlogin.txt");
   rename("files/credentials/temp.txt","files/credentials/userlogin.txt");

   cout<<"\nUser Removed Successfully\n";
   }

   else
   {
      cout<<"\nUser not removed\n";
   }
}

//Function to update username
void updateusername()
{
   char username[20];
   char user[20];
   char pass[20];
   char newname[20];

   cout<<"\nEnter Username to be updated: ";
   cin>>username;

   ifstream employee;
   employee.open("files/credentials/userlogin.txt");     //Opening file in read mode to read usernames

   ofstream temp;
   temp.open("files/credentials/temp.txt",ios::app);     //Opening file in write mode to write usernames

   cout<<"\nEnter New Username: ";
   cin>>newname;

   if(strlen(newname)>20 || strlen(newname)<5)
   {
      cout<<"\nUsername should be in range (5-20) characters\n";
      exit(0);
   }

   cout<<"\nAre you sure you want to update "<<username<<" to "<<newname<<" (y/n): ";
   char choice;
   cin>>choice;

if(choice=='y' || choice=='Y')
   {
   cout<<"\nUpdating Employee Username\n";
   while(employee>>user>>pass)      //Reading from file
   {
      if(strcmp(username,user)==0)
      {
         temp<<newname<<" "<<pass<<endl;
      }
      else
      {
         temp<<user<<" "<<pass<<endl;
      }

   }
   employee.close();      //Closing file
   temp.close();

   remove("files/credentials/userlogin.txt");
   rename("files/credentials/temp.txt","files/credentials/userlogin.txt");

   cout<<"\nUser Username Updated Successfully\n";
   }
   else
   {
      cout<<"\nUser Username not updated.\n";
   }

}

//Function to update password of user
void updateuserpassword()
{
   char username[20];
   char user[20];
   char pass[20];
   char newpass[20];

   cout<<"\nEnter Username to be updated: ";
   cin>>username;

   ifstream employee;
   employee.open("files/credentials/userlogin.txt");     //Opening file in read mode to read usernames

   ofstream temp;
   temp.open("files/credentials/temp.txt",ios::app);     //Opening file in write mode to write usernames

   cout<<"\nEnter New Password: ";
   cin>>newpass;

   if(strlen(newpass)>20 || strlen(newpass)<8)
   {
      cout<<"\nPassword should be in range (8-20) characters\n";
      exit(0);
   }

   cout<<"\nAre you sure you want to update password of" <<username<<" (y/n): ";
   char choice;
   cin>>choice;

if(choice=='y' || choice=='Y')
   {
   cout<<"\nUpdating User Password\n";
   while(employee>>user>>pass)      //Reading from file
   {
      if(strcmp(username,user)==0)
      {
         temp<<user<<" "<<newpass<<endl;
      }
      else
      {
         temp<<user<<" "<<pass<<endl;
      }

   }
   employee.close();      //Closing file
   temp.close();

   remove("files/credentials/userlogin.txt");
   rename("files/credentials/temp.txt","files/credentials/userlogin.txt");

   cout<<"\nUser Password Updated Successfully\n";
   }
   else
   {
      cout<<"\nUser Password not updated.\n";
   }

}


//Function to add notification
void addnotification()
{
   char notification[1000];
   int index;

   cout<<"\nEnter Notification(Max 1000 characters): ";
   cin.ignore();
   cin.getline(notification,1000);

   cout<<"\nEnter Index: ";
   cin>>index;


   ofstream notify;
   notify.open("files/caffeesystem/Notifications.txt",ios::app);     //Opening file in write mode to write notifications

   if (!notify) 
   {
        cout << "\nError opening Notifications.txt\n";
        return;
   }

   notify<<index<<". "<<notification<<endl;      //Writing to file

   notify.close();      //Closing file

   cout<<"\nNotification Added Successfully\n";
}

//Function to remove notification
void deletenotification()
{
   char notify[1000];
   int index;

   cout<<"\nEnter Index of notification to be removed: ";
   cin>>index;

   ifstream notifyfile;
   notifyfile.open("files/caffeesystem/Notifications.txt");     //Opening file in read mode to read notifications

   if(!notifyfile)
   {
      cout<<"\nError opening Notifications.txt\n";
      exit(0);
   }

   ofstream temp("files/caffeesystem/temp.txt", ios::out | ios::trunc);

   if (!temp) 
   {
        cout << "\nError opening temp.txt\n";
        exit(0);
   }

   cout<<"\nAre you sure you want to remove notification "<<index<<" (y/n): ";
   char choice;
   cin>>choice;

if(choice=='y' || choice=='Y')
   {
   cout<<"\nRemoving Notification\n";

    
   while(notifyfile.getline(notify,1000))      //Reading from file
   {
      int notifyindex = notify[0] - '0'; // Convert the character to an integer

      if(notifyindex!=index)
      {
         temp<<notify<<endl;
      }
   }
   notifyfile.close();      //Closing file
   temp.close();

   remove("files/caffeesystem/notifications.txt");
   rename("files/caffeesystem/temp.txt","files/caffeesystem/notifications.txt");

   cout<<"\nNotification Removed Successfully\n";
   }
   else
   {
      cout<<"\nNotification not removed.\n";
   }

}

//Function to View Stocks from Database
void viewdatabase()
{
   char header[100];
   char item[20];
   int quantity;
   int price;

   ifstream database;
   database.open("files/caffeesystem/overall/database.txt");     //Opening file in read mode to read stocks

   if(!database)
   {
      cout<<"\nError opening database.txt\n";
      exit(0);
   }

   database.getline(header,100);

   cout<<"\nAll stocks with total quantity exsisted and  price\n";
   cout<<"\nStocks in Database\n"; 

setcolor(3);
    cout <<setw(15)<<left<<"ItemName"
         <<setw(10)<<left<<"Quantity"
         <<setw(10)<<left<<"Price"
         <<setw(10)<<left <<"TotalPrice"<<endl;


   while(database>>item>>quantity>>price)      //Reading from file
   {
    cout <<setw(15)<<left<<item
         <<setw(10)<<left<<quantity
         <<setw(10)<<left<<price
         <<setw(10)<<left <<price*quantity<<endl;
   }

   database.close();      //Closing file

   setcolor(9);
}

//Function to Add Stocks to Database
void adddatabase()
{
   char item[20];
   int quantity;
   int price;

   cout<<"\nEnter Item Name: ";
   cin>>item;

   cout<<"\nEnter Quantity: ";
   cin>>quantity;

   cout<<"\nEnter Price: ";
   cin>>price;

   ofstream database;
   database.open("files/caffeesystem/overall/database.txt",ios::app);     //Opening file in write mode to write stocks

   if (!database) 
   {
        cout<<"\nError opening database.txt\n";
        return;
   }

   database<<item<<" "<<quantity<<" "<<price<<endl;      //Writing to file

   database.close();      //Closing file

   cout<<"\nStock Added Successfully\n";
}

//Function to Remove Stocks from Database
void deletedatabase()
{
   char header[100];
   char item[20];
   char rmitem[20];
   int quantity;
   int price;

   cout<<"\nEnter Item Name to be removed: ";
   cin>>rmitem;

   ifstream database;
   database.open("files/caffeesystem/overall/database.txt");     //Opening file in read mode to read stocks

   if(!database)
   {
      cout<<"\nError opening database.txt\n";
      exit(0);
   }

   ofstream temp("files/caffeesystem/overall/temp.txt", ios::out | ios::trunc);

   if (!temp) 
   {
        cout<<"\nError opening temp.txt\n";
        exit(0);
   }

   database.getline(header,100); 

   cout<<"\nAre you sure you want to remove "<<rmitem<<" (y/n): ";
   char choice;
   cin>>choice;

   

if(choice=='y' || choice=='Y')
   {  
   cout<<"\nRemoving Stock\n";

   temp<<header;

   while(database>>item>>quantity>>price)      //Reading from file
   {
      if(strcmp(rmitem,item)!=0)
      {
         temp<<item<<" "<<quantity<<" "<<price<<endl;
      }
   }

   database.close();      //Closing file
   temp.close();

   remove("files/caffeesystem/overall/database.txt");
   rename("files/caffeesystem/overall/temp.txt","files/caffeesystem/overall/database.txt");

   cout<<"\nStock Removed Successfully\n";
   }

   else
   {
      cout<<"\nStock not removed.\n";
   }

}

//Function to update stocks in database
void updatedatabase()
{
  //We can use the admins search function to search for item and then update it

  ifstream del;
  ofstream temp;
  del.open("files/caffeesystem/overall/database.txt");        //Opening file
  temp.open("files/caffeesystem/overall/temp.txt");        //Opening file
  char header[30];
  char item[20];
  int price;
  int quantity;
  char searchitem[20];
  int flag=0;

  del.getline(header,30);                            //Reading header from file

  cin.ignore();                                      //Ignoring newline character

  cout<<"\nEnter the item you want to update: ";               //Asking for item to update
  cin>>searchitem;

  while(del>>item>>quantity>>price)                        //Reading from file
  {
   if(strcmp(searchitem,item)==0)                 //Comparing item with database
    {
      flag=1;
      break;                         //If item matches then break the loop
   } 
  }

  if(flag==1)     
    { 
    cout<<"\nItem found\n";                       //If item found then display item
    cout<<"\nItem: "<<item;
    cout<<"\nQuantity: "<<quantity;
    cout<<"\nPrice Per Item: "<<price<<endl; 
    cout<<"\nTotal Price: "<<price*quantity<<"\n";
  
    cout<<"\nSelect what you want to update: \n";
    cout<<"\n1. Item name\n";
    cout<<"\n2. Quantity\n";
    cout<<"\n3. Price\n";

    int choice;
    cout<<"\nEnter your choice: ";
    cin>>choice;

    //Checking for invalid input
    while(cin.fail())
    {
        cin.clear();
        cin.ignore(100,'\n');
        cout<<"\nInvalid input. Please enter a number: ";
        cin>>choice;
    }

    temp<<header<<endl;                            //Adding header to file

    switch(choice)
    {
      case 1:
      {
        cout<<"\nEnter the new item name: ";               //Asking for new item name
        char newitem[20];
        cin>>newitem;

        if(strlen(newitem)>20)
        {
          cout<<"\nItem name too long\n";
          exit(0);
        }

        if(strcmp(newitem,item)==0)
        {
          cout<<"\nItem name same as previous\n";
          exit(0);
        }

        if(strlen(newitem)<3)
        {
          cout<<"\nItem name too small\n";
          exit(0);
        }

        temp<<newitem<<" "<<quantity<<" "<<price<<endl;           //Adding item to file

        cout<<"\nItem updated successfully\n";
        break;
      }

      case 2:
      {
        cout<<"\nEnter the new quantity: ";               //Asking for new quantity
        int newquantity;
        cin>>newquantity;

        //Checking for invalid input
        while(cin.fail())
        {
            cin.clear();
            cin.ignore(100,'\n');
            cout<<"\nInvalid input. Please enter a number: ";
            cin>>newquantity;
        }

        if(newquantity<=0 || newquantity>1000)
        {
          cout<<"\nInvalid quantity.Enter within range 1-1000\n";
          exit(0);
        }

        temp<<item<<" "<<newquantity<<" "<<price<<endl;           //Adding item to file

        cout<<"\nItem updated successfully\n";
        break;
      }

      case 3:
      {
        cout<<"\nEnter the new price: ";               //Asking for new price
        int newprice;
        cin>>newprice;

        //Checking for invalid input
        while(cin.fail())
        {
            cin.clear();
            cin.ignore(100,'\n');
            cout<<"\nInvalid input. Please enter a number: ";
            cin>>newprice;
        }

        if(newprice<=10 || newprice>1000)
        {
          cout<<"\nInvalid price.Enter within range 10-1000\n";
          exit(0);
        }

        temp<<item<<" "<<quantity<<" "<<newprice<<endl;           //Adding item to file

        cout<<"\nItem updated successfully\n";
        break;
      }

      default:
      {
        cout<<"\nInvalid choice\n";
        exit(0);
      }
    }

  //Updating the rest of the file

  del.close();
  del.open("files/caffeesystem/overall/database.txt");        //Opening file again

  del.getline(header,30);                            //Reading header from file


  while(del>>item>>quantity>>price)                        //Reading from file
  {
   if(strcmp(searchitem,item)!=0)                 //Comparing item with database
   {
    temp<<item<<" "<<quantity<<" "<<price<<endl;           //Adding item to file
   } 
  }

  }

  else
  {
    cout<<"\nItem not found.Make Sure to enter correct item name\n";
  }

  del.close();
  temp.close();

  remove("files/caffeesystem/overall/database.txt");        //Deleting old file
  rename("files/caffeesystem/overall/temp.txt","files/caffeesystem/overall/database.txt");        //Renaming temp file to old file
    
}

//Function to add all items in menu
int sumofallitems()
{
   ifstream display;
   display.open("files/foodsystem/stocks.txt"); // Opening file
    char item[20];
    int quantity;
    int price;

      

    //count the number of lines in file
      int count = 0;
      char c[100];

      display.getline(c, 100, '\n'); //skip header

      while (display.getline(c, 100, '\n'))              //For counting number of rows in file
      {
         count++;
      }

      display.close(); // Close the file

    char** items = new char*[count];                             //Using DMA
    int* quantities = new int[count];
    int* prices = new int[count];

      display.open("files/foodsystem/stocks.txt"); // Opening file again to read from start

      display.getline(c, 100, '\n'); //skip header

      // allocate memory for each item and read from file
       for (int i = 0; i < count; ++i) 
       {
        items[i] = new char[20];
        display >> items[i] >> quantities[i] >> prices[i];
       }

      //Using bubble sort to sort the items on basis of price
      for (int i = 0; i < count - 1; ++i) 
      {
        for (int j = 0; j < count - i - 1; ++j) 
        {
          if (prices[j] > prices[j + 1]) 
          {
            swap(quantities[j], quantities[j + 1]);
            swap(items[j], items[j + 1]);
            swap(prices[j], prices[j + 1]);
          }
        }
      }
   //counting total number of items
   int sum=0;
   for(int i=0;i<count;i++)
   {
      sum=sum+quantities[i];
   }

   return sum;
}

//Function for average price of all items
double averageprice()
{
   ifstream display;
   display.open("files/foodsystem/stocks.txt"); // Opening file
    char item[20];
    int quantity;
    int price;

      

    //count the number of lines in file
      int count = 0;
      char c[100];

      display.getline(c, 100, '\n'); //skip header

      while (display.getline(c, 100, '\n'))              //For counting number of rows in file
      {
         count++;
      }


      display.close(); // Close the file

    char** items = new char*[count];                             //Using DMA
    int* quantities = new int[count];
    int* prices = new int[count];

      display.open("files/foodsystem/stocks.txt"); // Opening file again to read from start

      display.getline(c, 100, '\n'); //skip header

      // allocate memory for each item and read from file
       for (int i = 0; i < count; ++i) 
       {
        items[i] = new char[20];
        display >> items[i] >> quantities[i] >> prices[i];
       }

      //Using bubble sort to sort the items on basis of price
      for (int i = 0; i < count - 1; ++i) 
      {
        for (int j = 0; j < count - i - 1; ++j) 
        {
          if (prices[j] > prices[j + 1]) 
          {
            swap(quantities[j], quantities[j + 1]);
            swap(items[j], items[j + 1]);
            swap(prices[j], prices[j + 1]);
          }
        }
      }
   //counting total number of items
   int sum=0;
   for(int i=0;i<count;i++)
   {
      sum=sum+prices[i];
   }

   float avg=(float)sum/count;

   return avg;
}

//Calculate all items price from menu
int totalprice()
{
   ifstream display;
   display.open("files/foodsystem/stocks.txt"); // Opening file
    char item[20];
    int quantity;
    int price;

      

    //count the number of lines in file
      int count = 0;
      char c[100];

      display.getline(c, 100, '\n'); //skip header

      while (display.getline(c, 100, '\n'))              //For counting number of rows in file
      {
         count++;
      }


      display.close(); // Close the file

    char** items = new char*[count];                             //Using DMA
    int* quantities = new int[count];
    int* prices = new int[count];

      display.open("files/foodsystem/stocks.txt"); // Opening file again to read from start

      display.getline(c, 100, '\n'); //skip header

      // allocate memory for each item and read from file
       for (int i = 0; i < count; ++i) 
       {
        items[i] = new char[20];
        display >> items[i] >> quantities[i] >> prices[i];
       }

      //Using bubble sort to sort the items on basis of price
      for (int i = 0; i < count - 1; ++i) 
      {
        for (int j = 0; j < count - i - 1; ++j) 
        {
          if (prices[j] > prices[j + 1]) 
          {
            swap(quantities[j], quantities[j + 1]);
            swap(items[j], items[j + 1]);
            swap(prices[j], prices[j + 1]);
          }
        }
      }
   //counting total number of items
   int sum=0;
   for(int i=0;i<count;i++)
   {
      sum=sum+(prices[i] *quantities[i]);
   }

   return sum;
}











