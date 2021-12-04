#include <gtkmm/window.h>
#include <gtkmm/label.h>
#include <gtkmm/entry.h>
#include <gtkmm/box.h>
#include <gtkmm/button.h>
#include <gtkmm/calendar.h>
#include <sigc++/functors/mem_fun.h>

class EditCustomerWindow : public Gtk::Window {
  public:
    EditCustomerWindow();
    ~EditCustomerWindow();

  protected:
    // Signal handlers
    void onButtonSaved();

    // Child widgets
    Gtk::Box mainVBox, nameHBox, icHBox, genderHBox, ageHBox,
      contactNumHBox, agencyHBox, paymentHBox, paymentDateHBox,
      destHBox, departureDateHBox;

    Gtk::Entry name, ic, gender, age, contactNum, agency,
      payment, dest;

    Gtk::Calendar paymentDate, departureDate;

    Gtk::Button saveButton;
};

EditCustomerWindow::EditCustomerWindow()
  : mainVBox(Gtk::Orientation::VERTICAL, 0),
    nameHBox(Gtk::Orientation::HORIZONTAL, 10),
    icHBox(Gtk::Orientation::HORIZONTAL, 10),
    genderHBox(Gtk::Orientation::HORIZONTAL, 10),
    ageHBox(Gtk::Orientation::HORIZONTAL, 10),
    contactNumHBox(Gtk::Orientation::HORIZONTAL, 10),
    agencyHBox(Gtk::Orientation::HORIZONTAL, 10),
    paymentHBox(Gtk::Orientation::HORIZONTAL, 10),
    paymentDateHBox(Gtk::Orientation::HORIZONTAL, 10),
    destHBox(Gtk::Orientation::HORIZONTAL, 10),
    departureDateHBox(Gtk::Orientation::HORIZONTAL, 10),
    saveButton("Save")
{
  set_title("Adding Customer");
  set_child(mainVBox);

  mainVBox.append(nameHBox);
  mainVBox.append(icHBox);
  mainVBox.append(genderHBox);
  mainVBox.append(ageHBox);
  mainVBox.append(contactNumHBox);
  mainVBox.append(agencyHBox);
  mainVBox.append(paymentHBox);
  mainVBox.append(paymentDateHBox);
  mainVBox.append(destHBox);
  mainVBox.append(departureDateHBox);

  nameHBox.append(*Gtk::make_managed<Gtk::Label>("Name: ", 0));
  nameHBox.append(name);

  icHBox.append(*Gtk::make_managed<Gtk::Label>("IC: ", 0));
  icHBox.append(ic);

  genderHBox.append(*Gtk::make_managed<Gtk::Label>("Gender: ", 0));
  genderHBox.append(gender);

  ageHBox.append(*Gtk::make_managed<Gtk::Label>("Age: ", 0));
  ageHBox.append(age);

  contactNumHBox.append(*Gtk::make_managed<Gtk::Label>("Contact Number: ", 0));
  contactNumHBox.append(contactNum);

  agencyHBox.append(*Gtk::make_managed<Gtk::Label>("Agency: ", 0));
  agencyHBox.append(agency);

  paymentHBox.append(*Gtk::make_managed<Gtk::Label>("Payment: ", 0));
  paymentHBox.append(payment);

  paymentDateHBox.append(*Gtk::make_managed<Gtk::Label>("Payment Date: ", 0));
  paymentDateHBox.append(paymentDate);

  destHBox.append(*Gtk::make_managed<Gtk::Label>("Destination: ", 0));
  destHBox.append(dest);

  departureDateHBox.append(*Gtk::make_managed<Gtk::Label>("Departure Date: ", 0));
  departureDateHBox.append(departureDate);

  mainVBox.append(saveButton);
  saveButton.signal_clicked().connect(sigc::mem_fun(*this,
        &EditCustomerWindow::onButtonSaved));
  saveButton.set_margin(10);
}

EditCustomerWindow::~EditCustomerWindow()
{

}

void EditCustomerWindow::onButtonSaved()
{
  hide();
}
