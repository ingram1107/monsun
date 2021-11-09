#include <Customer.cpp>
#include <LinkedList.cpp>
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;

static int num=0;//to keep track what is the size of the linked list
LinkedList<Customer> lin{};//declare a linked list

void sortInfo()
{
  int temp_num=num;
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
  int temp_num=num;//temp_num is used locally, just in case not interrupting the correct sequence of num
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
  while(temp_num>0)
  {
    Customer temp = lin.retrieve(temp_num);
    if(temp.getIc()==ic)
    {

      cout<<"\tInformation has been deleted......\n";
      lin.remove(temp_num);
      num--;
      break;
    }
    temp_num--;
  }
  if(temp_num==0)
  {
    cout<<"\n\tThe person is not found\n\n";
    cout<<"*************************************************************************************\n";
  }
}
void searchInfo()
{
  long ic;
  int temp_num=num;
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
  while(temp_num>0)
  {
    Customer temp = lin.retrieve(temp_num);
    if(temp.getIc()==ic)
    {

      cout<<"Matched Customer Information\n";
      temp.display();
      cout<<"\n";
      cout<<"*************************************************************************************\n";
      break;
    }
    temp_num--;
  }
  if(temp_num==0)
  {
    cout<<"\n\tThe person is not found\n\n";
    cout<<"*************************************************************************************\n";
  }

}
bool checkDuplicate(int index)
{
  Customer temp=lin.retrieve(index);
  for(int i=1;i<=num;i++)
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
  int temp_num=num;
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
  while(temp_num>0)
  {
    Customer temp = lin.retrieve(temp_num);
    if(temp.getIc()==ic)
    {
      pass=temp;
      available=true;
      cout<<"Current Customer Information\n";
      temp.display();
      lin.remove(temp_num);
      cout<<"\n";
      cout<<"*************************************************************************************\n";
      cout<<"\n";
      cout<<"*************************************************************************************\n";
      cout<<"Update Customer Information\n";
      cout<<"\n";
      temp.edit();
      lin.insert(temp,temp_num);
      cout<<"*************************************************************************************\n";

      break;
    }
    temp_num--;
  }
  if(temp_num==0)
  {
    cout<<"\n\tThe person is not found\n\n";
    cout<<"*************************************************************************************\n";
  }
  if(checkDuplicate(temp_num)==true && available==true)
  {

    cout<<"\tInformation has been updated......\n\n";
  }
  else if(checkDuplicate(temp_num)==false && available==true)
  {

    lin.remove(temp_num);
    lin.insert(pass,temp_num);
    cout<<"\tFail to edit current information, Please try again\n";
  }


}
void displayInfo()
{
  int temp_num=num;
  cout<<"====================================================================================\n";
  cout<<"|                                                                                  |\n";
  cout<<"|                   ------Traveling Agency Management System------                 |\n";
  cout<<"|                                                                                  |\n";
  cout<<"|     DISPLAY ALL CUSTOMER INFORMATION                                             |\n";
  cout<<"|                                                                                  |\n";
  cout<<"|                                                                                  |\n";
  cout<<"====================================================================================\n";

  while(temp_num>0)
  {

    Customer temp=lin.retrieve(temp_num);
    temp.display();
    cout<<"\n";
    cout<<"*************************************************************************************\n";
    temp_num--;
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
