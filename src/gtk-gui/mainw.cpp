#include "addcustomerw.cpp"
#include "editcustomerw.cpp"
#include <gtkmm/applicationwindow.h>
#include <gtkmm/window.h>
#include <gtkmm/grid.h>
#include <gtkmm/button.h>
#include <sigc++/functors/mem_fun.h>

class MainWindow : public Gtk::ApplicationWindow {
  public:
    MainWindow();
    virtual ~MainWindow();

  protected:
    // Signal Handlers
    void onAddCustomerButtonClicked();
    void onEditCustomerButtonClicked();
    void onDeleteCustomerButtonClicked();
    void onDisplayCustomerButtonClicked();
    void onSearchCustomerButtonClicked();
    void onSortCustomerButtonClicked();

    // Chlid Widgets
    Gtk::Grid grid;
    Gtk::Button addCustomerButton, editCustomerButton,
      deleteCustomerButton, displayCustomerButton,
      searchCustomerButton, sortCustomerButton;
};

MainWindow::MainWindow()
  : addCustomerButton("Add Customer's Information"),
    editCustomerButton("Edit Customer's Information"),
    deleteCustomerButton("Delete Customer's Information"),
    displayCustomerButton("Display Customer's Information"),
    searchCustomerButton("Search Customer's Information"),
    sortCustomerButton("Sort Customer's Information")
{
  set_title("Monsun");

  grid.set_margin(12);
  set_child(grid);

  grid.attach(addCustomerButton, 0, 0);
  grid.attach(editCustomerButton, 1, 0);
  grid.attach(deleteCustomerButton, 0, 1);
  grid.attach(displayCustomerButton, 1, 1);
  grid.attach(searchCustomerButton, 0, 2);
  grid.attach(sortCustomerButton, 1, 2);

  addCustomerButton.signal_clicked().connect(sigc::mem_fun(*this,
        &MainWindow::onAddCustomerButtonClicked));
  addCustomerButton.set_margin(10);
  editCustomerButton.signal_clicked().connect(sigc::mem_fun(*this,
        &MainWindow::onEditCustomerButtonClicked));
  editCustomerButton.set_margin(10);
  deleteCustomerButton.set_margin(10);
  displayCustomerButton.set_margin(10);
  searchCustomerButton.set_margin(10);
  sortCustomerButton.set_margin(10);
}

MainWindow::~MainWindow()
{

}

void MainWindow::onAddCustomerButtonClicked()
{
  auto nw = new AddCustomerWindow();
  nw->show();
}

void MainWindow::onEditCustomerButtonClicked()
{
  auto nw = new EditCustomerWindow();
  nw->show();
}

void MainWindow::onDeleteCustomerButtonClicked()
{

}

void MainWindow::onDisplayCustomerButtonClicked()
{

}

void MainWindow::onSearchCustomerButtonClicked()
{

}

void MainWindow::onSortCustomerButtonClicked()
{

}
