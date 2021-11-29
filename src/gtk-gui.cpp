#include "gtkmm/object.h"
#include <gtkmm.h>

class MainWindow : public Gtk::Window {
  public:
    MainWindow();
    virtual ~MainWindow();

  protected:
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
}

MainWindow::~MainWindow()
{

}
