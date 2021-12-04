#include <iostream>
#include <fstream>
#include <monsun.h>

#ifdef ENABLE_TUI
#include "tui.cpp"
#elif defined(ENABLE_GUI)
#include "gtk-gui/mainw.cpp"
#include <gtkmm/application.h>
#endif

using namespace std;

int main(int argc, char* argv[])
{
#ifdef ENABLE_TUI
  std::ifstream finCustomer{"customer.dat", std::ios::in};
  Customer tempCus;

  if (finCustomer.peek() == std::ifstream::traits_type::eof()) {
  } else {
    while (finCustomer >> tempCus) {
      int size = 0;
      lin.insert(tempCus, ++size);

      if (finCustomer.eof()) {
        break;
      }
    }
  }

  finCustomer.close();

  int choice,rchoice=0;
  while(rchoice==0)
  {
menu:
    cout<<"============================================================================\n";
    cout<<"|                   ------Traveling Agency Management System-------        |\n";
    cout<<"|                                                                          |\n";
    cout<<"|   Main Menu                                                              |\n";
    cout<<"|       1. Add Customer Information                                        |\n";
    cout<<"|       2. Edit Customer Information                                       |\n";
    cout<<"|       3. Delete Customer Information                                     |\n";
    cout<<"|       4. Display All Customer Information                                |\n";
    cout<<"|       5. Search for specific customer information                        |\n";
    cout<<"|       6. Sort Customer Information                                       |\n";
    cout<<"|       7. Exit the System                                                 |\n";
    cout<<"|                                                                          |\n";
    cout<<"============================================================================\n";

    cout<<"Please enter your choice"<<endl;
    cin>>choice;
    switch(choice)
    {
      case 1:
#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif
        addInfo();
        break;

      case 2:
#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif
        editInfo();
        break;
      case 3:
#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif
        deleteInfo();
        break;
      case 4:
#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif
        displayInfo();
        break;
      case 5:
#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif
        searchInfo();
        break;
      case 6:
#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif
        sortInfo();
        break;
      case 7:
        {
          std::ofstream foutCustomer{"customer.dat", std::ios::trunc};

          if (!foutCustomer) {
            cerr << "customer.dat: File does not exists" << endl;
            exit(1);
          }

          while (!lin.isEmpty()) {
            tempCus = lin.retrieve(1);
            foutCustomer << tempCus << '\n';
            lin.remove(1);
          }

          foutCustomer.close();
        }
        exit(0);
        break;
      default:
        cout<<"Please choose one of the valid option(1-5)\n";
#ifdef _WIN32
        system("pause");
        system("cls");
#else
        system("clear");
#endif
        goto menu;
    }
    cout<<"Press 0 to go back to main menu\n";
    cin>>rchoice;

    while(rchoice!=0)
    {
      cout<<"Please Try Again\n";
      cin>>rchoice;

    }
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
  }

  return 0;
#elif defined (ENABLE_GUI)
  auto app = Gtk::Application::create("org.gtkmm.example");

  return app->make_window_and_run<MainWindow>(argc, argv);
#endif
}
