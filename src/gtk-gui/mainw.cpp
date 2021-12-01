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
    void on_m_addCustomer_button_clicked();
    void on_m_editCustomer_button_clicked();
    void on_m_deleteCustomer_button_clicked();
    void on_m_displayCustomer_button_clicked();
    void on_m_searchCustomer_button_clicked();
    void on_m_sortCustomer_button_clicked();

    // Chlid Widgets
    Gtk::Grid m_grid;
    Gtk::Button m_addCustomer_button, m_editCustomer_button,
      m_deleteCustomer_button, m_displayCustomer_button,
      m_searchCustomer_button, m_sortCustomer_button;
};

MainWindow::MainWindow()
  : m_addCustomer_button("Add Customer's Information"),
    m_editCustomer_button("Edit Customer's Information"),
    m_deleteCustomer_button("Delete Customer's Information"),
    m_displayCustomer_button("Display Customer's Information"),
    m_searchCustomer_button("Search Customer's Information"),
    m_sortCustomer_button("Sort Customer's Information")
{
  set_title("Monsun");

  m_grid.set_margin(12);
  set_child(m_grid);

  m_grid.attach(m_addCustomer_button, 0, 0);
  m_grid.attach(m_editCustomer_button, 1, 0);
  m_grid.attach(m_deleteCustomer_button, 0, 1);
  m_grid.attach(m_displayCustomer_button, 1, 1);
  m_grid.attach(m_searchCustomer_button, 0, 2);
  m_grid.attach(m_sortCustomer_button, 1, 2);

  m_addCustomer_button.signal_clicked().connect(sigc::mem_fun(*this,
        &MainWindow::on_m_addCustomer_button_clicked));
  m_addCustomer_button.set_margin(10);
  m_editCustomer_button.signal_clicked().connect(sigc::mem_fun(*this,
        &MainWindow::on_m_editCustomer_button_clicked));
  m_editCustomer_button.set_margin(10);
  m_deleteCustomer_button.set_margin(10);
  m_displayCustomer_button.set_margin(10);
  m_searchCustomer_button.set_margin(10);
  m_sortCustomer_button.set_margin(10);
}

MainWindow::~MainWindow()
{

}

void MainWindow::on_m_addCustomer_button_clicked()
{
  auto nw = new AddCustomerWindow();
  nw->show();
}

void MainWindow::on_m_editCustomer_button_clicked()
{
  auto nw = new EditCustomerWindow();
  nw->show();
}

void MainWindow::on_m_deleteCustomer_button_clicked()
{

}

void MainWindow::on_m_displayCustomer_button_clicked()
{

}

void MainWindow::on_m_searchCustomer_button_clicked()
{

}

void MainWindow::on_m_sortCustomer_button_clicked()
{

}
