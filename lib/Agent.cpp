#include <Customer.cpp>
#include <LinkedList.cpp>

class Agent : public Person {
  private:
    LinkedList<Customer> customers;
    double salary;

  public:
    Agent() = default;
    Agent(long ic, std::string name, char gender, int age,
          std::string contactNum, LinkedList<Customer> customers,
          double salary);
    ~Agent() = default;
    bool operator==(const Agent& rhs);
    bool operator!=(const Agent& rhs);
    bool operator<(const Agent& rhs);
    bool operator>(const Agent& rhs);
    friend std::ostream& operator<<(std::ostream& in, Customer const& rhs);
    friend std::istream& operator>>(std::istream& out, Customer& rhs);

    // TODO move these functions to a Display class
    void display() const;
    void edit();

    void setCustomers(LinkedList<Customer> customers);
    void setSalary(double salary);
    LinkedList<Customer> getCustomers() const;
    double getSalary() const;
};

Agent::Agent(long ic, std::string name, char gender, int age,
             std::string contactNum, LinkedList<Customer> customers,
             double salary)
  : Person{ic, name, gender, age, contactNum},
    customers{customers},
    salary{salary}
{

}

bool Agent::operator==(const Agent& rhs)
{
  return false;
}

bool Agent::operator!=(const Agent& rhs)
{
  return false;
}

bool Agent::operator<(const Agent& rhs)
{
  return false;
}

bool Agent::operator>(const Agent& rhs)
{
  return false;
}

void Agent::display() const
{

}

void Agent::edit()
{

}

void Agent::setCustomers(LinkedList<Customer> customers)
{
  this->customers = customers;
}
void Agent::setSalary(double salary)
{
  this->salary = salary;
}

LinkedList<Customer> Agent::getCustomers() const
{
  return customers;
}
double Agent::getSalary() const
{
  return salary;
}
