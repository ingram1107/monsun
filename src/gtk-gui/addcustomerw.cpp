#include <gtkmm/window.h>
#include <gtkmm/label.h>
#include <gtkmm/entry.h>
#include <gtkmm/box.h>
#include <gtkmm/button.h>
#include <gtkmm/calendar.h>
#include <sigc++/functors/mem_fun.h>

class AddCustomerWindow : public Gtk::Window {
  public:
    AddCustomerWindow();
    ~AddCustomerWindow();

  protected:
    // Signal handlers
    void on_button_saved();

    // Child widgets
    Gtk::Box m_VBox_Main, m_HBox_Name, m_HBox_IC, m_HBox_Gender, m_HBox_Age,
      m_HBox_ContactNum, m_HBox_Agency, m_HBox_Payment, m_HBox_PaymentDate,
      m_HBox_Dest, m_HBox_DepartureDate;

    Gtk::Entry m_Name, m_IC, m_Gender, m_Age, m_ContactNum, m_Agency,
      m_Payment, m_Dest;

    Gtk::Calendar m_PaymentDate, m_DepartureDate;

    Gtk::Button m_Save;
};

AddCustomerWindow::AddCustomerWindow()
  : m_VBox_Main(Gtk::Orientation::VERTICAL, 0),
    m_HBox_Name(Gtk::Orientation::HORIZONTAL, 10),
    m_HBox_IC(Gtk::Orientation::HORIZONTAL, 10),
    m_HBox_Gender(Gtk::Orientation::HORIZONTAL, 10),
    m_HBox_Age(Gtk::Orientation::HORIZONTAL, 10),
    m_HBox_ContactNum(Gtk::Orientation::HORIZONTAL, 10),
    m_HBox_Agency(Gtk::Orientation::HORIZONTAL, 10),
    m_HBox_Payment(Gtk::Orientation::HORIZONTAL, 10),
    m_HBox_PaymentDate(Gtk::Orientation::HORIZONTAL, 10),
    m_HBox_Dest(Gtk::Orientation::HORIZONTAL, 10),
    m_HBox_DepartureDate(Gtk::Orientation::HORIZONTAL, 10),
    m_Save("Save")
{
  set_title("Adding Customer");
  set_child(m_VBox_Main);

  m_VBox_Main.append(m_HBox_Name);
  m_VBox_Main.append(m_HBox_IC);
  m_VBox_Main.append(m_HBox_Gender);
  m_VBox_Main.append(m_HBox_Age);
  m_VBox_Main.append(m_HBox_ContactNum);
  m_VBox_Main.append(m_HBox_Agency);
  m_VBox_Main.append(m_HBox_Payment);
  m_VBox_Main.append(m_HBox_PaymentDate);
  m_VBox_Main.append(m_HBox_Dest);
  m_VBox_Main.append(m_HBox_DepartureDate);

  m_HBox_Name.append(*Gtk::make_managed<Gtk::Label>("Name: ", 0));
  m_HBox_Name.append(m_Name);

  m_HBox_IC.append(*Gtk::make_managed<Gtk::Label>("IC: ", 0));
  m_HBox_IC.append(m_IC);

  m_HBox_Gender.append(*Gtk::make_managed<Gtk::Label>("Gender: ", 0));
  m_HBox_Gender.append(m_Gender);

  m_HBox_Age.append(*Gtk::make_managed<Gtk::Label>("Age: ", 0));
  m_HBox_Age.append(m_Age);

  m_HBox_ContactNum.append(*Gtk::make_managed<Gtk::Label>("Contact Number: ", 0));
  m_HBox_ContactNum.append(m_ContactNum);

  m_HBox_Agency.append(*Gtk::make_managed<Gtk::Label>("Agency: ", 0));
  m_HBox_Agency.append(m_Agency);

  m_HBox_Payment.append(*Gtk::make_managed<Gtk::Label>("Payment: ", 0));
  m_HBox_Payment.append(m_Payment);

  m_HBox_PaymentDate.append(*Gtk::make_managed<Gtk::Label>("Payment Date: ", 0));
  m_HBox_PaymentDate.append(m_PaymentDate);

  m_HBox_Dest.append(*Gtk::make_managed<Gtk::Label>("Destination: ", 0));
  m_HBox_Dest.append(m_Dest);

  m_HBox_DepartureDate.append(*Gtk::make_managed<Gtk::Label>("Departure Date: ", 0));
  m_HBox_DepartureDate.append(m_DepartureDate);

  m_VBox_Main.append(m_Save);
  m_Save.signal_clicked().connect(sigc::mem_fun(*this,
        &AddCustomerWindow::on_button_saved));
  m_Save.set_margin(10);
}

AddCustomerWindow::~AddCustomerWindow()
{

}

void AddCustomerWindow::on_button_saved()
{
  hide();
}
