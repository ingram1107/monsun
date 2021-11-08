/**
 * @file Customer.hpp
 * @brief Customer Object Interface
 *
 * @class Customer Customer.hpp "lib/Customer.hpp"
 */
#pragma once
#include <string>

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
