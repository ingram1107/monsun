/**
 * @file Agent.cpp
 * @brief Agent Class Interface
 *
 * @class Agent Agent.cpp "Agent.cpp"
 */
#include <Customer.cpp>
#include <LinkedList.cpp>

/**
 * A simple storage for agent information
 */
class Agent : public Person {
  private:
    LinkedList<Customer> customers;
    double salary;

  public:
    Agent() = default;
    /**
     * Construct an Agent object
     *
     * @param ic IC number of the agent
     * @param name Name of the agent
     * @param gender Gender of the agent
     * @param age Age of the agent
     * @param contactNum Contact number of the agent
     * @param customers Customers that the agent is held accountable for,
     * @param salary Salary for the agent
     */
    Agent(long ic, std::string name, char gender, int age,
        std::string contactNum, LinkedList<Customer> customers,
        double salary);
    ~Agent() = default;

    /**
     * Determine whether two of the Agent objects are belong to the same
     * agent
     *
     * @param rhs Agent object at the right hand side
     * @retval true If this Agent object and the right hand side Agent
     *    object are the same
     * @retval false If this Agent object and the right hand side Agent
     *    object are not the same
     */
    bool operator==(const Agent& rhs);
    /**
     * Determine whether two of the Agent objects are not belong to the same
     * agent
     *
     * @param rhs Agent object at the right hand side
     * @retval true If this Agent object and the right hand side Agent
     *    object are not the same
     * @retval false If this Agent object and the right hand side Agent
     *    object are the same
     */
    bool operator!=(const Agent& rhs);
    /**
     * Determine whether this Agent has less priority than the right hand
     * side Agent
     *
     * @param rhs Agent object at the right hand side
     * @retval true If this Agent object has less priority than the right
     *    hand side Agent object
     * @retval false If this Agent object does not have less priority than
     *    the right hand side Agent object
     */
    bool operator<(const Agent& rhs);
    /**
     * Determine whether this Agent has more priority than the right hand
     * side Agent
     *
     * @param rhs Agent object at the right hand side
     * @retval true If this Agent object has more priority than the right
     *    hand side Agent object
     * @retval false If this Agent object does not have more priority than
     *    the right hand side Agent object
     */
    bool operator>(const Agent& rhs);
    /**
     * Output the Agent object as a structured data to the output stream
     *
     * This function will output the Agent object in the format of
     * "Name:IC:Gender:Age:ContactNum:Payment:PaymentDate:Agency:Destination:DepartureDate:".
     * It can be called as follow:
     *
     * @code{.cpp}
     * Agent rhs{...};
     * std::cout << rhs;
     * @endcode
     *
     * @param out output stream such as standard output and file
     * @param rhs Agent object at the right hand side
     * @returns an output stream object
     **/
    friend std::ostream& operator<<(std::ostream& in, Agent const& rhs);
    /**
     * Receive structured data from the input stream and convert it into the
     * Agent object
     *
     * This function will convert the structured data from the input stream
     * into their corresponding data type and stored them into the Agent
     * object specified. It can be called as follow:
     *
     * @code{.cpp}
     * Agent rhs{};
     * std::cin >> rhs;
     * @endcode
     *
     * @param in input stream such as standard input and file
     * @param rhs Agent object at the right hand side
     * @returns an input stream object
     **/
    friend std::istream& operator>>(std::istream& out, Agent& rhs);

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
