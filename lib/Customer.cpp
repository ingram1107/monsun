/**
 * @file Customer.cpp
 * @brief Customer Object Interface
 *
 * @class Customer Customer.cpp "Customer.cpp"
 */

#include <Person.cpp>
#include <cstdio>
#include <iostream>
#include <limits>
#include <string>
#include <regex>

/**
 * A simple storage for customer information
 */
class Customer : public Person {
  private:
    std::string paymentDate, departureDate, agency, dest;
    double payment;

  public:
    Customer() = default;
    /**
     * Construct a Customer object
     *
     * @param ic IC number of the customer
     * @param name Name of the customer
     * @param gender Gender of the customer
     * @param age Age of the customer
     * @param contactNum Contact number of the customer
     * @param payment Amount of money paid for ticket by the customer
     * @param paymentDate Date of the payment received by the company
     * @param departureDate Departure date of travel for the customer
     * @param agency Responsible agent for this customer
     * @param dest Destination of the travel set by the customer
     */
    Customer(long ic, std::string name, char gender, int age,
             std::string contactNum,
             double payment, std::string paymentDate,
             std::string departureDate,
             std::string agency, std::string dest);
    ~Customer() = default;

    /**
     * Determine whether two of the Customer objects are belong to the same
     * customer
     *
     * @param rhs Customer object at the right hand side
     * @retval true If this Customer object and the right hand side Customer
     *    object are the same
     * @retval false If this Customer object and the right hand side Customer
     *    object are not the same
     */
    bool operator==(const Customer& rhs);
    /**
     * Determine whether two of the Customer objects are not belong to the same
     * customer
     *
     * @param rhs Customer object at the right hand side
     * @retval true If this Customer object and the right hand side Customer
     *    object are not the same
     * @retval false If this Customer object and the right hand side Customer
     *    object are the same
     */
    bool operator!=(const Customer& rhs);
    /**
     * Determine whether this customer has less priority than the right hand
     * side customer
     *
     * @param rhs Customer object at the right hand side
     * @retval true If this Customer object has less priority than the right
     *    hand side Customer object
     * @retval false If this Customer object does not have less priority than
     *    the right hand side Customer object
     */
    bool operator<(const Customer& rhs);
    /**
     * Determine whether this customer has more priority than the right hand
     * side customer
     *
     * @param rhs Customer object at the right hand side
     * @retval true If this Customer object has more priority than the right
     *    hand side Customer object
     * @retval false If this Customer object does not have more priority than
     *    the right hand side Customer object
     */
    bool operator>(const Customer& rhs);
    /**
     * Output the Customer object as a structured data to the output stream
     *
     * This function will output the Customer object in the format of
     * "Name:IC:Gender:Age:ContactNum:Payment:PaymentDate:Agency:Destination:DepartureDate:".
     * It can be called as follow:
     *
     * @code{.cpp}
     * Customer rhs{...};
     * std::cout << rhs;
     * @endcode
     *
     * @param out output stream such as standard output and file
     * @param rhs Customer object at the right hand side
     * @returns an output stream object
     **/
    friend std::ostream& operator<<(std::ostream& out, Customer const& rhs);
    /**
     * Receive structured data from the input stream and convert it into the
     * Customer object
     *
     * This function will convert the structured data from the input stream
     * into their corresponding data type and stored them into the Customer
     * object specified. It can be called as follow:
     *
     * @code{.cpp}
     * Customer rhs{};
     * std::cin >> rhs;
     * @endcode
     *
     * @param in input stream such as standard input and file
     * @param rhs Customer object at the right hand side
     * @returns an input stream object
     **/
    friend std::istream& operator>>(std::istream& in, Customer& rhs);

    // TODO: move these functions to a Display class
    /**
     * Display formated customer information
     */
    void display() const;
    /**
     * Iteratively edit customer's information
     */
    void edit();

    void setPaymentDate(std::string paymentDate);
    void setDepartureDate(std::string departureDate);
    void setAgency(std::string agency);
    void setDest(std::string dest);
    void setPayment(double payment);

    std::string getPaymentDate() const;
    std::string getDepartureDate() const;
    std::string getAgency() const;
    std::string getDest() const;
    double getPayment() const;
};

Customer::Customer(long ic, std::string name, char gender, int age,
                   std::string contactNum,
                   double payment, std::string paymentDate,
                   std::string departureDate,
                   std::string agency, std::string dest)
  : Person{ic, name, gender, age, contactNum},
    payment{payment}, paymentDate{paymentDate},
    departureDate{departureDate},
    agency{agency}, dest{dest}
{

}

bool Customer::operator==(const Customer& rhs)
{
  if (this->ic == rhs.getIc() &&
      this->name == rhs.getName() &&
      this->gender == rhs.getGender() &&
      this->age == rhs.getAge() &&
      this->contactNum == rhs.getContactNum() &&
      this->paymentDate == rhs.getPaymentDate() &&
      this->departureDate == rhs.getDepartureDate() &&
      this->agency == rhs.getAgency() &&
      this->dest == rhs.getDest())
    return true;
  return false;
}

bool Customer::operator!=(const Customer& rhs)
{
  if (this->ic !=  rhs.getIc() ||
      this->name !=  rhs.getName() ||
      this->gender !=  rhs.getGender() ||
      this->age !=  rhs.getAge() ||
      this->contactNum !=  rhs.getContactNum() ||
      this->paymentDate !=  rhs.getPaymentDate() ||
      this->departureDate !=  rhs.getDepartureDate() ||
      this->agency !=  rhs.getAgency() ||
      this->dest != rhs.getDest())
    return true;
  return false;
}

bool Customer::operator<(const Customer& rhs)
{
  return this->ic < rhs.ic;
}

bool Customer::operator>(const Customer& rhs)
{
  return this->ic > rhs.ic;
}

std::ostream& operator<<(std::ostream& out, Customer const& rhs)
{
  out << rhs.name << ":";
  out << rhs.ic << ":";
  out << rhs.gender << ":";
  out << rhs.age << ":";
  out << rhs.contactNum << ":";
  out << rhs.payment << ":";
  out << rhs.paymentDate << ":";
  out << rhs.agency << ":";
  out << rhs.dest << ":";
  out << rhs.departureDate << ":";

  return out;
}

std::istream& operator>>(std::istream& in, Customer& rhs)
{
  std::string ic_s, gender_s, age_s, payment_s;

  // store corresponding variables
  std::getline(in, rhs.name, ':');
  std::getline(in, ic_s, ':');
  std::getline(in, gender_s, ':');
  std::getline(in, age_s, ':');
  std::getline(in, rhs.contactNum, ':');
  std::getline(in, payment_s, ':');
  std::getline(in, rhs.paymentDate, ':');
  std::getline(in, rhs.agency, ':');
  std::getline(in, rhs.dest, ':');
  std::getline(in, rhs.departureDate, ':');
  in >> std::ws;

  // convert to suitable types
  rhs.ic = std::stol(ic_s);
  rhs.gender = gender_s[0];
  rhs.age = std::stoi(age_s);
  rhs.payment = std::stod(payment_s);

  return in;
}

void Customer::display() const
{
  std::cout << "Name                 : " << name << std::endl;
  std::cout << "IC                   : " << ic << std::endl;
  std::cout << "Gender               : " << gender << std::endl;
  std::cout << "Age                  : " << age << std::endl;
  std::cout << "Contact Number       : " << contactNum << std::endl;
  std::cout << "Payment              : RM " << payment << std::endl;
  std::cout << "Payment Date         : " << paymentDate << std::endl;
  std::cout << "Responsible Agency   : " << agency << std::endl;
  std::cout << "Destination          : " << dest << std::endl;
  std::cout << "Departure Date       : " << departureDate << std::endl;
}

void Customer::edit()
{
  int ic, age;
  std::string name, contactNum, paymentDate, departureDate, agency, dest;
  double payment;
  char gender;

  std::cin.ignore();
  while (true) {
    std::regex pattern{"^[A-za-z\\s]+$"};
    std::cout << "Name                 : ";
    std::getline(std::cin, name);

    if (!std::regex_match(name, pattern)) {
      std::cerr << "Real name should not contain numbers and special characters!" << std::endl;
    } else break;
  }

  while (true) {
    std::cout << "IC                   : ";
    std::cin >> ic;

    if (!std::cin) {
      std::cerr << "IC should be in digits!" << std::endl;
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } else break;
  }

  while (true) {
    std::cout << "Gender               : ";
    std::cin >> gender;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (isdigit(gender)) {
      std::cerr << "Gender could not be a number!" << std::endl;
    } else if (std::tolower(gender) != 'm' && std::tolower(gender) != 'f' && std::tolower(gender) != 'n') {
      std::cerr << "Gender can only be either (M)ale, (F)emale or (N)on-binary!" << std::endl;
    } else break;
  }

  while (true) {
    std::cout << "Age                  : ";
    std::cin >> age;

    if (!std::cin) {
      std::cerr << "Age should be in number!" << std::endl;
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } else break;
  }

  while (true) {
    std::regex pattern1{"01[0,2-9]-[0-9]{7}"};
    std::regex pattern2{"011-[0-9]{8}"};

    std::cout << "Contact Number       : ";
    std::cin >> contactNum;

    if (!(std::regex_match(contactNum, pattern1)) && !(std::regex_match(contactNum, pattern2))) {
      std::cerr << "Contact number should be in the format of 01X-XXXXXXX!" << std::endl;
    } else break;
  }

  std::cin.ignore();
  while (true) {
    std::regex pattern{"^[A-za-z\\s]+$"};
    std::cout << "Responsible Agency   : ";
    std::getline(std::cin, agency);

    if (!std::regex_match(agency, pattern)) {
      std::cerr << "Agent's real name should not contain numbers and special characters!" << std::endl;
    } else break;
  }

  while (true) {
    std::cout << "Payment              : ";
    std::cin >> payment;

    if (!std::cin) {
      std::cerr << "Payment should be in digits!" << std::endl;
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } else break;
  }

  while (true) {
    unsigned int date, month, year;

    std::cout << "Payment Date         : ";
    if (std::scanf("%2d/%2d/%4d", &date, &month, &year) < 3) {
      std::cerr << "Date should be in format dd/mm/yyyy!" << std::endl;
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } else {
      paymentDate = std::to_string(date) + '/' + std::to_string(month) + '/' + std::to_string(year);
      break;
    }
  }

  std::cin.ignore();
  while (true ) {
    std::regex pattern{"^[A-za-z\\s,]+$"};
    std::cout << "Destination          : ";
    std::getline(std::cin, dest);

    if (!std::regex_match(dest, pattern)) {
      std::cerr << "Destination's name should not contain numbers and special characters except ','!" << std::endl;
    } else break;
  }

  while (true) {
    unsigned int date, month, year;

    std::cout << "Departure Date       : ";
    if (std::scanf("%2d/%2d/%4d", &date, &month, &year) < 3) {
      std::cerr << "Date should be in format dd/mm/yyyy!" << std::endl;
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } else {
      departureDate = std::to_string(date) + '/' + std::to_string(month) + '/' + std::to_string(year);
      break;
    }
  }

  setName(name);
  setIc(ic);
  setGender(gender);
  setAge(age);
  setContactNum(contactNum);
  setAgency(agency);
  setPayment(payment);
  setPaymentDate(paymentDate);
  setDest(dest);
  setDepartureDate(departureDate);
}

void Customer::setPaymentDate(std::string paymentDate)
{
  this->paymentDate = paymentDate;
}
void Customer::setDepartureDate(std::string departureDate)
{
  this->departureDate = departureDate;
}
void Customer::setAgency(std::string agency)
{
  this->agency = agency;
}
void Customer::setDest(std::string dest)
{
  this->dest = dest;
}
void Customer::setPayment(double payment)
{
  this->payment = payment;
}

std::string Customer::getDepartureDate() const
{
  return departureDate;
}
std::string Customer::getPaymentDate() const
{
  return paymentDate;
}
std::string Customer::getAgency() const
{
  return agency;
}
std::string Customer::getDest() const
{
  return dest;
}
double Customer::getPayment() const
{
  return payment;
}
