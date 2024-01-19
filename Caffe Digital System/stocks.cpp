#include "stocks.h"

using namespace std;

//For stock Display by price
void displaybyprice()
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

      cout << "\nTotal number of items: " << count << endl;                //Displaying total number of items

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
       

    // Displaying header
    cout << setw(15) << left << "Item"
         << setw(15) << left << "Quantity"
         << setw(15) << left << "Price Per Item" << endl;

    // Displaying items
    for (int i = 0; i < count; ++i) 
     {
      if(quantities[i] <10 && quantities[i]>0)                //if quantity is less than 10, set color to red
           setcolor(1);

      else if(quantities[i] ==0)           //if quantity is 0, set color to yellow  
        setcolor(2);

      else
           setcolor(3);                    //if quantity is greater than 10, set color to green

      
      cout << setw(15) << left << items[i]
         << setw(15) << left << quantities[i]
         << setw(15) << left << prices[i] << endl;
     }

   // Free the allocated memory
    for (int i = 0; i < count; ++i) 
    {
        delete[] items[i];
    }
    delete[] items;
    delete[] quantities;
    delete[] prices;

    //assigning null to pointer
      items = NULL;
      quantities = NULL;
      prices = NULL;


    display.close(); // Close the file

    //resetting color to default
    setcolor(9);
}

//For stock Display by quantity
void displaybyquantity()
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

      while (display.getline(c, 100, '\n'))
      {
         count++;
      }

      cout << "\nTotal number of items: " << count << endl;

      display.close(); // Close the file

    char** items = new char*[count];
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

      //Using bubble sort to sort the items on basis of quantity
      for (int i = 0; i < count - 1; ++i) 
      {
        for (int j = 0; j < count - i - 1; ++j) 
        {
          if (quantities[j] > quantities[j + 1]) 
          {
            swap(quantities[j], quantities[j + 1]);
            swap(items[j], items[j + 1]);
            swap(prices[j], prices[j + 1]);
          }
        }
      }

      cin.ignore(); //ignore the newline character left in the buffer

    // Displaying header
    cout << setw(15) << left << "Item"
         << setw(15) << left << "Quantity"
         << setw(15) << left << "Price Per Item" << endl;


   // Displaying items 
    for (int i = 0; i < count; ++i) 
    {
      if(quantities[i] <10 && quantities[i]>0)                //if quantity is less than 10, set color to red
           setcolor(1);

      else if(quantities[i] ==0)           //if quantity is 0, set color to yellow  
        setcolor(2);

      else
           setcolor(3);                    //if quantity is greater than 10, set color to green

      cout << setw(15) << left << items[i]
         << setw(15) << left << quantities[i]
         << setw(15) << left << prices[i] << endl;
    }

    //Order more and color code for admin
    for (int i = 0; i < count; ++i) 
    {
      if(quantities[i] <10 && quantities[i]>0)                //if quantity is less than 10, set color to red
      {
           setcolor(1);
           cout<<"\nItem "<<items[i]<<" is running out of stock.It is low\n";
           ordermore();
      }

      else if(quantities[i] ==0)           //if quantity is 0, set color to yellow
      {    
        setcolor(2);
        cout<<"\nItem "<<items[i]<<" is out of stock\n";
        ordermore();
      }

      else
           setcolor(3);                    //if quantity is greater than 10, set color to green 
    }

   // Free the allocated memory
    for (int i = 0; i < count; ++i) 
    {
        delete[] items[i];
    }
    delete[] items;
    delete[] quantities;
    delete[] prices;

    //assigning null to pointer
      items = NULL;
      quantities = NULL;
      prices = NULL;


    display.close(); // Close the file

    setcolor (9);
}

//For stock Display by name
void displaybyname()
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

      while (display.getline(c, 100, '\n'))
      {
         count++;
      }

      cout << "\nTotal number of items: " << count << endl;

      display.close(); // Close the file

    char** items = new char*[count];
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

      //Using bubble sort to sort the items on basis of name
      for (int i = 0; i < count - 1; ++i) 
      {
        for (int j = 0; j < count - i - 1; ++j) 
        {
           if (strcmp(items[j], items[j + 1]) > 0)
          {
            swap(quantities[j], quantities[j + 1]);
            swap(items[j], items[j + 1]);
            swap(prices[j], prices[j + 1]);
          }
        }
      }

      cin.ignore(); //ignore the newline character left in the buffer
       
    // Displaying header
    cout << setw(15) << left << "Item"
         << setw(15) << left << "Quantity"
         << setw(15) << left << "Price Per Item" << endl;


   for (int i = 0; i < count; ++i) 
    { 
      if(quantities[i] <10 && quantities[i]>0)                //if quantity is less than 10, set color to red
           setcolor(1);

      else if(quantities[i] ==0)           //if quantity is 0, set color to yellow  
        setcolor(2);

      else
           setcolor(3);                    //if quantity is greater than 10, set color to green
      
      cout << setw(15) << left << items[i]
         << setw(15) << left << quantities[i]
         << setw(15) << left << prices[i] << endl;
    }

    //Order more and color code
    for (int i = 0; i < count; ++i) 
    {
      if(quantities[i] <10 && quantities[i]>0)                //if quantity is less than 10, set color to red
      {
           setcolor(1);
           cout<<"\nItem "<<items[i]<<" is running out of stock.It is low\n";
          ordermore();
      }

      else if(quantities[i] ==0)           //if quantity is 0, set color to yellow
      {    
        setcolor(2);
        cout<<"\nItem "<<items[i]<<" is out of stock\n";
        ordermore();
      }

      else
           setcolor(3);                    //if quantity is greater than 10, set color to green
    }

   // Free the allocated memory
    for (int i = 0; i < count; ++i) 
    {
        delete[] items[i];
    }
    delete[] items;
    delete[] quantities;
    delete[] prices;

    //assigning null to pointer
      items = NULL;
      quantities = NULL;
      prices = NULL;


    display.close(); // Close the file

    setcolor (9);   //setting color to default
}


//For searching item
void searchitem()
{
     ifstream search;
            search.open("files/foodsystem/stocks.txt");        //Opening file
            char header[30];
            char item[20];
            int price;
            int quantity;
            char searchitem[20];
            int flag=0; 

            search.getline(header,30);                            //Reading header from file

            cin.ignore();                                        //Ignoring newline character left in buffer

            cout<<"\nEnter the item you want to search: ";               //Asking for item to search
            cin>>searchitem;

            while(search>>item>>quantity>>price)                        //Reading from file
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

            }

            else
            {
               cout<<"\nItem not found.We may not have that item currently.\n";
            }
            search.close();

}

//Swap function for sorting items
void swap(int& a, int& b)                    //Swap is used in sorting of items in upper functions
{
  int temp = a;
  a = b;
  b = temp;
}

//Function for admin to search item
int adminsearch()
{
  ifstream search;
  search.open("files/foodsystem/stocks.txt");        //Opening file
  char header[30];
  char item[20];
  int price;
  int quantity;
  char searchitem[20];
  int flag=0; 

  search.getline(header,30);                            //Reading header from file

  cin.ignore();                                        //Ignoring newline character left in buffer

  cout<<"\nEnter the item you want to search: ";               //Asking for item to search
  cin>>searchitem;

  while(search>>item>>quantity>>price)                        //Reading from file
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

  }

 else
 {
   cout<<"\nItem not found.Make Sure to enter correct item name\n";
 }
  search.close();

  return flag;

}

//Function for admin to add item
void addstock()
{
  ofstream add;
  add.open("files/foodsystem/stocks.txt",ios::app);        //Opening file
  char item[20];
  int price;
  int quantity;
  char choice;

  do
  {
    cout<<"\nEnter the item you want to add: ";               //Asking for item to add
    cin>>item;

    cout<<"\nEnter the quantity of item: ";               //Asking for quantity to add
    cin>>quantity;

    //Checking for invalid input
    while(cin.fail())
   {
      cin.clear();
      cin.ignore(100,'\n');
      cout<<"\nInvalid input. Please enter a number: ";
      cin>>quantity;
   }

    if(quantity<=0 || quantity>1000)
    {
      cout<<"\nInvalid quantity.Enter within range 1-1000\n";
      exit(0);
    }
    cout<<"\nEnter the price per item: ";               //Asking for price to add
    cin>>price;

    //Checking for invalid input
    while(cin.fail())
    {
        cin.clear();
        cin.ignore(100,'\n');
        cout<<"\nInvalid input. Please enter a number: ";
        cin>>price;
    }

    if(price<=10 || price>1000)
    {
      cout<<"\nInvalid price.Enter within range 10-1000\n";
      exit(0);
    }


    add<<item<<" "<<quantity<<" "<<price<<endl;           //Adding item to file

    cout<<"\nItems added successfully\n";

    cout<<"\nDo you want to add more items?(y/n): ";               //Asking for choice to add more items
    cin>>choice;

  }
  while(choice=='y'||choice=='Y');



  add.close();

}


//Function for admin to delete item
void deletestock()
{
  ifstream del;
  ofstream temp;
  del.open("files/foodsystem/stocks.txt");        //Opening file
  temp.open("files/foodsystem/temp.txt");        //Opening file
  char header[30];
  char item[20];
  int price;
  int quantity;
  char searchitem[20];
  int flag=0; 

  del.getline(header,30);                            //Reading header from file

  cin.ignore();                                      //Ignoring newline character

  cout<<"\nEnter the item you want to delete: ";               //Asking for item to delete
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

   cout<<"\nAre you sure you want to delete this item?(y/n): ";               //Asking for choice to delete item
    char choice;
    cin>>choice;

    if(choice=='y'||choice=='Y')
    {
      cout<<"\nItem deleted successfully\n";
    }

    else
    {
      cout<<"\nItem not deleted\n";
      exit(0);
    }

  }

 else
 {
  cout<<"\nItem not found.Make Sure to enter correct item name\n";
 }
  del.close();

  del.open("files/foodsystem/stocks.txt");        //Opening file again
  del.getline(header,30);                            //Reading header from file

  temp<<header<<endl;                            //Adding header to file

  while(del>>item>>quantity>>price)                        //Reading from file
  {
   if(strcmp(searchitem,item)!=0)                 //Comparing item with database
    {
    temp<<item<<" "<<quantity<<" "<<price<<endl;           //Adding item to file
   } 
  }

  del.close();
  temp.close();

  remove("files/foodsystem/stocks.txt");        //Deleting old file
  rename("files/foodsystem/temp.txt","files/foodsystem/stocks.txt");        //Renaming temp file to old file

}


//Function for admin to update item
void updatestock()
{
  //We can use the admins search function to search for item and then update it

  ifstream del;
  ofstream temp;
  del.open("files/foodsystem/stocks.txt");        //Opening file
  temp.open("files/foodsystem/temp.txt");        //Opening file
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
  del.open("files/foodsystem/stocks.txt");        //Opening file again

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

  remove("files/foodsystem/stocks.txt");        //Deleting old file
  rename("files/foodsystem/temp.txt","files/foodsystem/stocks.txt");        //Renaming temp file to old file
    
}

//For color using ANSI escape codes
void setcolor(int x)
{
  switch(x)
  {
    case 1:
    {
      cout<<"\033[31m";        //Red
      break;
    }

    case 2:
    {
      cout<<"\033[33m";        //yellow
      break;
    }

    case 3:
    {
      cout<<"\033[32m";        //green
      break;
    }
    case 9:
    {
      cout<<"\033[0m";        //Reset
      break;
    }
}

}

//For ordering more stock
void ordermore()
{
   setcolor(9);
   
   char choice;
   cout<<"\nDo you want to update stock? (y/n): ";          
   cin>>choice;

   if(choice=='y' || choice=='Y')
   {
      cout<<"\n1.Delete stock";                    
      cout<<"\n2.Update stock";

      int choicestock;
      cout<<"\nEnter your choice: ";
      cin>>choicestock;


      switch(choicestock)
      {
         case 1: deletestock();               //Calling function to delete stock if user wants to delete
                 break;
         case 2: updatestock();                //Calling function to update stock if user wants to update this will call function where we can modify stock
                 break;
         default: cout<<"\nInvalid choice\n";
      }

   }


}

//For listing all the stocks in the menu
int stockcount()
{
  ifstream fin;
  fin.open("files/foodsystem/stocks.txt");

  char header[30];
  char item[20];
  int price;
  int quantity;
  int count=0;

  fin.getline(header,30);                            //Reading header from file

  while(fin>>item>>quantity>>price)                        //Reading from file and counting items
      count++;

  fin.close();

  return count;

}

//For listing all the stocks out of stock
int outofstockcount()
{
  ifstream fin;
  fin.open("files/foodsystem/stocks.txt");

  char header[30];
  char item[20];
  int price;
  int quantity;
  int count=0;

  fin.getline(header,30);                            //Reading header from file

  while(fin>>item>>quantity>>price)                        //Reading from file and counting items if quantity is 0
  {
    if(quantity==0)
      count++;
  }

  fin.close();

  return count;
}

//For listing all the stocks low in stock
int lowstockcount()
{
  ifstream fin;
  fin.open("files/foodsystem/stocks.txt");

  char header[30];
  char item[20];
  int price;
  int quantity;
  int count=0;

  fin.getline(header,30);                            //Reading header from file

  while(fin>>item>>quantity>>price)                        //Reading from file and counting items if quantity is less than 10
  {
    if(quantity<=10)
      count++;
  }

  fin.close();

  return count;
}

//For calculating total sales by total number of orders
int totalsales()
{
  ifstream fin;
  fin.open("files/caffeesystem/summary.txt");
  int count=0;

  char header[120];
  char order[120];

  fin.getline(header,120);                            //Reading header from file

  while(fin.getline(order,120,'\n'))                        //Reading from file and counting orders
      count++;

  fin.close();

  fin.open("files/caffeesystem/shedulesummary.txt");

  char header2[120];
  char order2[120];

  fin.getline(header2,120);                            //Reading header from file

  while(fin.getline(order2,120,'\n'))                        //Reading from file and counting sheduled orders
      count++;

  return count;
}


//For comparing stocks in menu with stocks in database
void comparestocks()
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

      while (display.getline(c, 100, '\n'))
      {
         count++;
      }

      cout << "\nTotal number of items: " << count << endl;

      display.close(); // Close the file

    char** items = new char*[count];
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

      //Using bubble sort to sort the items on basis of name alphabetically
      for (int i = 0; i < count - 1; ++i) 
      {
        for (int j = 0; j < count - i - 1; ++j) 
        {
           if (strcmp(items[j], items[j + 1]) > 0)
          {
            swap(quantities[j], quantities[j + 1]);
            swap(items[j], items[j + 1]);
            swap(prices[j], prices[j + 1]);
          }
        }
      }

      cin.ignore(); //ignore the newline character left in the buffer

//Now sorting the database:

    ifstream display2;
    display2.open("files/caffeesystem/overall/database.txt"); // Opening file
    char item2[20];
    int quantity2;
    int price2;

    //count the number of lines in file
      int count2 = 0;
      char c2[100];

      display2.getline(c2, 100, '\n'); //skip header

      while (display2.getline(c2, 100, '\n'))
      {
         count2++;
      }

      cout << "\nTotal number of items: " << count2 << endl;

      display2.close(); // Close the file

    char** items2 = new char*[count2];
    int* quantities2 = new int[count2];
    int* prices2 = new int[count2];

      display2.open("files/caffeesystem/overall/database.txt"); // Opening file again to read from start

      display2.getline(c2, 100, '\n'); //skip header

      // allocate memory for each item and read from file

       for (int i = 0; i < count2; ++i) 
       {
        items2[i] = new char[20];
        display2 >> items2[i] >> quantities2[i] >> prices2[i];
       }

      //Using bubble sort to sort the items on basis of name alphabetically
      for (int i = 0; i < count2 - 1; ++i) 
      {
        for (int j = 0; j < count2 - i - 1; ++j) 
        {
           if (strcmp(items2[j], items2[j + 1]) > 0)
          {
            swap(quantities2[j], quantities2[j + 1]);
            swap(items2[j], items2[j + 1]);
            swap(prices2[j], prices2[j + 1]);
          }
        }
      }


      //Comparing the stocks in menu with stocks in database
      for(int i=0,j=0;i<count;i++,j++)
      {
          if(strcmp(items[i],items2[j])==0)
          { 
            if(quantities[i]!=quantities2[j])                   //If item is present in database and has different stock
            {
              
              cout<<"\n"<<items[i]<<" has different stock in menu and database\n";
              cout<<"Stock in menu: "<<quantities[i]<<"\n";
              cout<<"Stock in database: "<<quantities2[j]<<"\n";
            }
            else                                //If item is present in database and has same stock
            {
              cout<<"\n"<<items[i]<<" has same stock in menu and database\n";
            }

          }
          else                                     //If item is not present in database
          {
            cout<<"\n"<<items[i]<<" is not present in database\n";
          }
      }
      

   // Free the allocated memory for menu
    for (int i = 0; i < count; ++i) 
    {
        delete[] items[i];
    }
    delete[] items;
    delete[] quantities;
    delete[] prices;

    //assigning null to pointer
      items = NULL;
      quantities = NULL;
      prices = NULL;


    display.close(); // Close the file

    // Free the allocated memory for database
    for (int i = 0; i < count2; ++i) 
    {
        delete[] items2[i];
    }
    delete[] items2;
    delete[] quantities2;
    delete[] prices2;

    //assigning null to pointer
      items2 = NULL;
      quantities2 = NULL;
      prices2 = NULL;

    display2.close(); // Close the file

}


//Function for random stock decrease after day
void randomdecrease()
{
  cout<<"\nHere Have a look at summary of Orders\n";
  //for displaying the order history
  orderhistory();

  ifstream display;
    display.open("files/foodsystem/stocks.txt"); // Opening file
    char item[20];
    int quantity;
    int price;

    //count the number of lines in file
      int count = 0;
      char c[100];

      display.getline(c, 100, '\n'); //skip header

      while (display.getline(c, 100, '\n'))
      {
         count++;
      }

      display.close(); // Close the file

    char** items = new char*[count];
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

      //Using bubble sort to sort the items on basis of quantity
      for (int i = 0; i < count - 1; ++i) 
      {
        for (int j = 0; j < count - i - 1; ++j) 
        {
           if (strcmp(items[j], items[j + 1]) > 0)
          {
            swap(quantities[j], quantities[j + 1]);
            swap(items[j], items[j + 1]);
            swap(prices[j], prices[j + 1]);
          }
        }
      }
    
    //Randomly decreasing the stock
    srand(time(0));
    int random = rand() % 10 + 1; 
    int random2 = rand() % 5 + 1;

    for(int i=0;i<count-random2;i++)                 //Decreasing the stock only if it is greater than 10
    {
      if(quantities[i]>10)
      {
        quantities[i]=quantities[i]-random;

      }
    }

//Done so that all stocks are decreased differently
    for(int i=0;i<count;i++)
     {
      if(quantities[i]>10)
      {
        quantities[i]=quantities[i]-random2;

      }
    }



    for(int i=0;i<count;i++)            //Making sure that stock doesn't go below 0
    {
      if(quantities[i]<0)
      {
        quantities[i]=0;
      }
    }

    //Asking admin to order more stock if stock is less than 10
    for(int i=0;i<count;i++)
    {
      if(quantities[i]<10)
      {
        cout<<"\n"<<items[i]<<" has stock less than 10\n";
        cout<<"Please order more stock\n";
        cout<<"\nDo you want to order more stock?(y/n)\n";
        char choice;
        cin>>choice;
        if(choice=='y')
        {
          cout<<"\nHow much stock do you want to order?\n";
          int order;
          cin>>order;
          quantities[i]=quantities[i]+order;
        }
        else
        {
          cout<<"\nOk\n";
        }
      }
    }

    //Writing the new stock in file
    ofstream write;
    write.open("files/foodsystem/stocks.txt");

    write<<c;

    for(int i=0;i<count;i++)
    {
      write<<"\n"<<items[i]<<" "<<quantities[i]<<" "<<prices[i];
    }

    write.close();

    cout<<"\nStocks updated\n";
    cout<<"\nSee you tomorrow\n";

    // Free the allocated memory
    for (int i = 0; i < count; ++i) 
    {
        delete[] items[i];
    }
    delete[] items;
    delete[] quantities;
    delete[] prices;

    //assigning null to pointer
      items = NULL;
      quantities = NULL;
      prices = NULL;

    display.close(); // Close the file



}
