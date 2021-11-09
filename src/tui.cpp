#include <Customer.cpp>
#include <LinkedList.cpp>
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;

LinkedList<Customer> lin{};//declare a linked list

void sortInfo()
{
  int choice;
  bool isAscending;

sortMenu:
  cout<<"====================================================================================\n";
  cout<<"|                                                                                  |\n";
  cout<<"|                   ------Traveling Agency Management System------                 |\n";
  cout<<"|                                                                                  |\n";
  cout<<"|      SORT CUSTOMER INFORMATION                                                   |\n";
  cout<<"|            1. In Descending Order                                                |\n";
  cout<<"|            2. In Ascending Order                                                 |\n";
  cout<<"|                                                                                  |\n";
  cout<<"|                                                                                  |\n";
  cout<<"====================================================================================\n";
  cout<<"Please enter your choice"<<endl;
  cin>>choice;

  switch (choice) {
    case 1:
      isAscending = true;
      break;
    case 2:
      isAscending = false;
      break;
    default:
      cout<<"Please choose one of the valid option(1-2)\n";
#ifdef _WIN32
      system("pause");
      system("cls");
#else
      system("clear");
#endif
      goto sortMenu;
  }

  if (!lin.isEmpty()) {
    lin.sort(isAscending);
    cout<<"\nThe information has been sorted......\n"<<endl;
  } else
    cout<<"There's no customer information stored......\n"<<endl;

}
void deleteInfo()
{
  long ic;
  cout<<"====================================================================================\n";
  cout<<"|                                                                                  |\n";
  cout<<"|                   ------Traveling Agency Management System------                 |\n";
  cout<<"|                                                                                  |\n";
  cout<<"|     DELETE CUSTOMER INFORMATION                                                  |\n";
  cout<<"|                                                                                  |\n";
  cout<<"|                                                                                  |\n";
  cout<<"====================================================================================\n\n";
  cout<<"Enter Customer IC: ";
  cin>>ic;
  cout<<"*************************************************************************************\n";
  for (int i = lin.size; i > 0; i--)
  {
    Customer temp = lin.retrieve(i);
    if(temp.getIc()==ic)
    {

      cout<<"\tInformation has been deleted......\n";
      lin.remove(i);
      break;
    } else if (i - 1 == 0) {
      cout<<"\n\tThe person is not found\n\n";
      cout<<"*************************************************************************************\n";
    }
  }
}

void searchInfo()
{
  long ic;
  cout<<"====================================================================================\n";
  cout<<"|                                                                                  |\n";
  cout<<"|                   ------Traveling Agency Management System------                 |\n";
  cout<<"|                                                                                  |\n";
  cout<<"|     SEARCH SPECIFIC CUSTOMER INFORMATION                                         |\n";
  cout<<"|                                                                                  |\n";
  cout<<"|                                                                                  |\n";
  cout<<"====================================================================================\n\n";
  cout<<"Enter Customer IC: ";
  cin>>ic;
  cout<<"*************************************************************************************\n";
  for (int i = lin.size; i > 0; i--)
  {
    Customer temp = lin.retrieve(i);
    if(temp.getIc()==ic)
    {

      cout<<"Matched Customer Information\n";
      temp.display();
      cout<<"\n";
      cout<<"*************************************************************************************\n";
      break;
    } else if (i - 1 == 0) {
      cout<<"\n\tThe person is not found\n\n";
      cout<<"*************************************************************************************\n";
    }
  }
}

bool checkDuplicate(int index)
{
  Customer temp=lin.retrieve(index);
  for(int i=1;i>=lin.size;i++)
  {
    Customer test = lin.retrieve(i);
    if(i==index)
    {
      continue;
    }
    else if(temp.getIc()==test.getIc())
    {
      return false;
      break;
    }
  }
  return true;
}

void editInfo()
{
  bool available=false;
  long ic;
  Customer pass;
  cout<<"====================================================================================\n";
  cout<<"|                                                                                  |\n";
  cout<<"|                   ------Traveling Agency Management System------                 |\n";
  cout<<"|                                                                                  |\n";
  cout<<"|     EDIT CUSTOMER INFORMATION                                                    |\n";
  cout<<"|                                                                                  |\n";
  cout<<"|                                                                                  |\n";
  cout<<"====================================================================================\n";
  cout<<"Enter customer IC\n";
  cin>>ic;
  cout<<"*************************************************************************************\n";
  for (int i = lin.size; i > 0; i--)
  {
    Customer temp = lin.retrieve(i);
    if(temp.getIc()==ic)
    {
      pass=temp;
      available=true;
      cout<<"Current Customer Information\n";
      temp.display();
      lin.remove(i);
      cout<<"\n";
      cout<<"*************************************************************************************\n";
      cout<<"\n";
      cout<<"*************************************************************************************\n";
      cout<<"Update Customer Information\n";
      cout<<"\n";
      temp.edit();
      lin.insert(temp,i);
      cout<<"*************************************************************************************\n";

      if(checkDuplicate(i)==true && available==true)
      {
        cout<<"\tInformation has been updated......\n\n";
      }
      else if(checkDuplicate(i)==false && available==true)
      {

        lin.remove(i);
        lin.insert(pass, i);
        cout<<"\tFail to edit current information, Please try again\n";
      }
      break;
    }
    else if(i - 1 == 0)
    {
      cout<<"\n\tThe person is not found\n\n";
      cout<<"*************************************************************************************\n";
    }
  }
}

void displayInfo()
{
  cout<<"====================================================================================\n";
  cout<<"|                                                                                  |\n";
  cout<<"|                   ------Traveling Agency Management System------                 |\n";
  cout<<"|                                                                                  |\n";
  cout<<"|     DISPLAY ALL CUSTOMER INFORMATION                                             |\n";
  cout<<"|                                                                                  |\n";
  cout<<"|                                                                                  |\n";
  cout<<"====================================================================================\n";

  for (int i = lin.size; i > 0; i--)
  {
    Customer temp=lin.retrieve(i);
    temp.display();
    cout<<"\n";
    cout<<"*************************************************************************************\n";
  }

}


void addInfo()
{
  Customer newCus;
  char input;
  bool duplicate = false;
  cout<<"====================================================================================\n";
  cout<<"|                                                                                  |\n";
  cout<<"|                   ------Traveling Agency Management System------                 |\n";
  cout<<"|                                                                                  |\n";
  cout<<"|            ADD CUSTOMER INFORMATION                                              |\n";
  cout<<"|                                                                                  |\n";
  cout<<"|                                                                                  |\n";
  cout<<"====================================================================================\n";
  newCus.edit();

  for (int i = lin.size; i > 0; i--)
  {
    Customer temp = lin.retrieve(i);

    if(temp.getIc()==newCus.getIc())
    {
      duplicate=true;
    }
  }

  if(duplicate == true)
  {
    cout<<"\t\nThis IC number already existed\n";
  }
  else
  {
    if(lin.insert(newCus, lin.size + 1))
    {
      std::cout << "\n\tInformation has been added......\n";
    }
    else
    {
      std::cout << "\tPlease Try Again\n";
    }
  }

  cout<<"\nDo you want to add more?(Y/n)\n";
  cin>>input;
  input=toupper(input);
  if(input=='y'||input=='Y') {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
    addInfo();
  }

}
