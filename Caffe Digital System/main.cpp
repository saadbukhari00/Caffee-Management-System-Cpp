#include "project.h"

using namespace std;

int main ()
{
    int choice,exit=1,adminchoice=0;
    int attempt=0;

    cout<<"\nWelcome to Cafe Digital System\n" ;       //Welcome message

 //Do while loop for login menu to repeat in case of wrong input
do                                   
{
    cout<<"\nLogin To proceed.\n";     //Login menu
    cout<<"----------------------------------";
    cout<<"\n1. Admin";
    cout<<"\n2. Employee";
    cout<<"\n3. User";
    cout<<"\n4. Reviews/Suggestions";
    cout<<"\n99. Exit";

    cout<<"\nEnter your choice: ";                   //Asking for choice from user
    cin>>choice;

   //checks for strings and floats ; for all non numeric input
   while(cin.fail())
   {
      cin.clear();
      cin.ignore(100,'\n');
      cout<<"\nInvalid input. Please enter a number: ";
      cin>>choice;
   }

    switch(choice)
    {   
        //For admin
        case 1:
        {
            
            if(adminlogin()==1)                //If adminlogin function returns 1 then login is successful
            {
                cout<<"\nLogin Successful. Welcome Admin";
                cout<<"\nYou are logged in as admin"<<endl;
                attempt=0;             //Setting attempts to 0 for next login

                cout<<"\nDo you want to see compare the current stocks with the previous day? (1 for yes, 0 for no): ";
                cin>>adminchoice;
                if(adminchoice==1)
                {
                    int admin2choice;                          //User tell what he wants to see
                    cout<<"\nWhat you want to see?\n";
                    cout<<"1. Compare the current stocks with the previous day\n";
                    cout<<"2. See Summary Of Orders Fulfilled\n";

                    cout<<"\nEnter your choice: ";
                    cin>>admin2choice;

                    if(admin2choice==1)             //If user wants to see compare the current stocks with the previous day
                    {
                    comparestocks();
                    }
                    else if(admin2choice==2)             //If user wants to see summary of orders fulfilled
                    {
                        int admin3choice;
                        cout<<"\nSummary Of Orders Fulfilled\n";
                        cout<<"----------------------------------\n";
                        cout<<"Total Orders: "<<stockcount()<<endl;
                        cout<<"Total Orders Fulfilled: "<<stockcount()-outofstockcount()<<endl;
                        cout<<"Total Orders Not Fulfilled: "<<outofstockcount()<<endl;
                        cout<<"Total Orders Fulfilled Partially: "<<lowstockcount()<<endl;
                        cout<<"Total Sales: "<<totalsales()<<endl;

                        cout<<"\nPress 1 to see full details of orders: ";                 //TO display details
                        cin>>admin3choice;

                        if(admin3choice==1)
                        {
                            orderhistory();
                        }
                        else
                        {
                            cout<<"\nInvalid Input\n";
                        }

                    }
                    else
                    {
                        cout<<"\nInvalid Input\n";
                    }
                }
                else
                {
                    cout<<"\nOkay. Moving on.\n";
                }

                displaybyquantity();      //It display the stock at start so thaat admin knows he has to order more or not

                adminmenu();               //Calling adminmenu function to display admin menu
            }
            else                          
            {
                cout<<"\nLogin Failed. Please Try Again\n"<<2-attempt<<" attempts left\n";
                attempt++;              //Incrementing attempt by 1
            }

            if(attempt==3)        //If attempt is 3 then maximum attempts reached
            {
                cout<<"\nMaximum attempts reached. Please contact Univeristy IT office.\n";
                exit=0;             //Setting exit to 0 to exit the loop
            }

            break;
        }

        //For employee
        case 2:
        {

            if(employeelogin()==1)
            {
             cout<<"\nLogin Successful. Welcome";             //If employeelogin function returns 1 then login is successful
             cout<<"\nYou are logged in as Employee"<<endl;
                attempt=0;             //Setting attempts to 0 for next login

                employeemenu();               //Calling employeemenu function to display employee menu  
            }
            else
            {
             cout<<"\nLogin Failed.Try Again \n"<<2-attempt<<" attempts left\n";  
             attempt++;              //Incrementing attempt by 1        
            }

            if(attempt==3)        //If attempt is 3 then maximum attempts reached
            {
                cout<<"\nMaximum attempts reached. Please contact your supervisor.\n";
                exit=0;             //Setting exit to 0 to exit the loop
            }

            break;
        }

        //For user
        case 3:
        {

            if(userlogin()==1)            //If userlogin function returns 1 then login is successful
            {
                cout<<"\nLogin Successful. Welcome";       
                cout<<"\nYou are logged in as user"<<endl;
                cout<<"\n\nYou may have notifcations. Check them in notifications section.Press 6\n";
                attempt=0;             //Setting attempts to 0 for next login

                usermenu();               //Calling usermenu function to display user menu
            }
            else 
            {                         
                cout<<"\nLogin Failed. Please try again\n"<<2-attempt<<" attempts left\n";
                attempt++;              //Incrementing attempt by 1
            }

            if(attempt==3)        //If attempt is 3 then maximum attempts reached
            {
                cout<<"\nMaximum attempts reached. Please contact admin office.\n";
                exit=0;             //Setting exit to 0 to exit the loop
            }
                      
             break;
        }

        case 4:
        {
            char review[10000];                                     //For review and suggestions
            cout<<"\nReviews/Suggestions\n";
            cout<<"----------------------------------";
            cout<<"\nWelcome To Reviews/Suggestions Section\n";
            cout<<"\nOur Reviews are anonymous.\n";
            cout<<"----------------------------------";
            cout<<"\nEnter any Reviews/Suggestions(Max 10000 characters): ";
            cin.ignore();
            cin.getline(review,10000);

            ofstream fout;
            fout.open("files/caffeesystem/reviews.txt",ios::app);       //Opening file in append mode
            fout<<review<<endl;                                          //Writing review to file

            cout<<"\nThank you for your valuable feedback.\n";
            fout.close();                                                //Closing file


        }

        //For exit
        case 99:
        {
            cout<<"\nThank you for using Cafe Digital System";            
            cout<<"\n-----------------------------------------";
            cout<<"\nSee you again. In case of any query contact admin.\n\n";
            exit=0;
            break;
        }

        //Default message for wrong input
        default:
        {
            cout<<"\nInvalid choice. Please try again.\n";             
            break;
        }
    }
}
while(exit!=0);           //Condition for exiting the loop

    return 0;
}