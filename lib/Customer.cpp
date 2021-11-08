// Customre.cpp
#include <iostream>
#include <string>
#include "Customer.hpp"

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
  // rhs.ic = std::stol(ic_s);
  rhs.gender = gender_s[0];
  // rhs.age = std::stoi(age_s);
  // rhs.payment = std::stod(payment_s);

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
  std::cout << "Name                 : ";
  std::getline(std::cin, name);
  std::cout << "IC                   : ";
  std::cin >> ic;
  std::cout << "Gender               : ";
  std::cin >> gender;
  std::cout << "Age                  : ";
  std::cin >> age;
  std::cout << "Contact Number       : ";
  std::cin >> contactNum;
  std::cin.ignore();
  std::cout << "Responsible Agency   : ";
  std::getline(std::cin, agency);
  std::cout << "Payment              : ";
  std::cin >> payment;
  std::cout << "Payment Date         : ";
  std::cin >> paymentDate;
  std::cout << "Destination          : ";
  std::cin >> dest;
  std::cout << "Departure Date       : ";
  std::cin >> departureDate;

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
