/**
 * @file Customer.cpp
 * @brief Customer Object Interface
 *
 * @class Customer Customer.cpp "Customer.cpp"
 */
#include <cstdio>
#include <iostream>
#include <limits>
#include <string>
#include <regex>

/**
 * Simple storage for customer information
 */
class Customer {
  private:
    long ic;
    int age;
    std::string name, contactNum, paymentDate, departureDate, agency, dest;
    double payment;
    char gender;

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
     * @retval true If this Customer object and the right hand side Customer
     *    object are not the same
     * @retval false If this Customer object and the right hand side Customer
     *    object are the same
     */
    bool operator!=(const Customer& rhs);
    bool operator<(const Customer& rhs);
    bool operator>(const Customer& rhs);
    friend std::ostream& operator<<(std::ostream& in, Customer const& rhs);
    friend std::istream& operator>>(std::istream& out, Customer& rhs);

    /**
     * Display formated customer information
     */
    void display() const;
    /**
     * Iteratively edit customer's information
     */
    void edit();

    void setIc(long ic);
    void setAge(int age);
    void setName(std::string name);
    void setContactNum(std::string contactNum);
    void setPaymentDate(std::string paymentDate);
    void setDepartureDate(std::string departureDate);
    void setAgency(std::string agency);
    void setDest(std::string dest);
    void setPayment(double payment);
    void setGender(char gender);

    long getIc() const;
    int getAge() const;
    std::string getName() const;
    std::string getContactNum() const;
    std::string getPaymentDate() const;
    std::string getDepartureDate() const;
    std::string getAgency() const;
    std::string getDest() const;
    double getPayment() const;
    char getGender() const;
};

Customer::Customer(long ic, std::string name, char gender, int age,
                   std::string contactNum,
                   double payment, std::string paymentDate,
                   std::string departureDate,
                   std::string agency, std::string dest)
  : ic{ic}, name{name}, gender{gender}, age{age},
    contactNum{contactNum},
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
      std::cerr << "Real name should not contain numbers!" << std::endl;
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
    std::smatch match;

    std::cout << "Contact Number       : ";
    std::cin >> contactNum;

    if (!(std::regex_match(contactNum, match, pattern1)) && !(std::regex_match(contactNum, match, pattern2))) {
      std::cerr << "Contact number should be in the format of 01X-XXXXXXX" << std::endl;
    } else break;
  }

  std::cin.ignore();
  while (true) {
    std::regex pattern{"^[A-za-z\\s]+$"};
    std::cout << "Responsible Agency   : ";
    std::getline(std::cin, agency);

    if (!std::regex_match(agency, pattern)) {
      std::cerr << "Agent's real name should not contain numbers!" << std::endl;
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
      std::cerr << "Date should be in format dd/mm/yyyy" << std::endl;
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } else {
      paymentDate = std::to_string(date) + '/' + std::to_string(month) + '/' + std::to_string(year);
      break;
    }
  }

  std::cin.ignore();
  std::cout << "Destination          : ";
  std::getline(std::cin, dest);

  while (true) {
    unsigned int date, month, year;

    std::cout << "Departure Date       : ";
    if (std::scanf("%2d/%2d/%4d", &date, &month, &year) < 3) {
      std::cerr << "Date should be in format dd/mm/yyyy" << std::endl;
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

void Customer::setIc(long ic)
{
  this->ic = ic;
}
void Customer::setAge(int age)
{
  this->age = age;
}
void Customer::setName(std::string name)
{
  this->name = name;
}
void Customer::setContactNum(std::string contactNum)
{
  this->contactNum = contactNum;
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
void Customer::setGender(char gender)
{
  this->gender = gender;
}

long Customer::getIc() const
{
  return ic;
}
int Customer::getAge() const
{
  return age;
}
std::string Customer::getName() const
{
  return name;
}
std::string Customer::getContactNum() const
{
  return contactNum;
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
char Customer::getGender() const
{
  return gender;
}
