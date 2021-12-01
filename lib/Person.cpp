/**
 * @file Person.cpp
 * @brief Person Abstract Class Interface
 *
 * @class Person Person.cpp "Person.cpp"
 */
#include <string>

/**
 * An abstract class for a generic person
 */
class Person {
  protected:
    long ic;
    int age;
    std::string name, contactNum;
    char gender;

  public:
    Person() = default;
    /**
     * Construct a Person object
     *
     * Since this class is an abstract class, constructing it outside of the
     * context of its relative classes will generate a compiler error.
     *
     * @param ic IC number of the customer
     * @param name Name of the customer
     * @param gender Gender of the customer
     * @param age Age of the customer
     * @param contactNum Contact number of the customer
     */
    Person(long ic, std::string name, char gender, int age, std::string contactNum);
    ~Person() = default;

    // TODO: move these functions to a Display class
    /**
     * Display formated person information
     */
    virtual void display() const = 0;
    /**
     * Iteratively edit person's information
     */
    virtual void edit() = 0;

    void setIc(long ic);
    void setAge(int age);
    void setName(std::string name);
    void setContactNum(std::string contactNum);
    void setGender(char gender);

    long getIc() const;
    int getAge() const;
    std::string getName() const;
    std::string getContactNum() const;
    char getGender() const;
};

Person::Person(long ic, std::string name, char gender, int age,
               std::string contactNum)
  : ic{ic}, name{name}, gender{gender}, age{age},
    contactNum{contactNum}
{

}

void Person::setIc(long ic)
{
  this->ic = ic;
}
void Person::setAge(int age)
{
  this->age = age;
}
void Person::setName(std::string name)
{
  this->name = name;
}
void Person::setContactNum(std::string contactNum)
{
  this->contactNum = contactNum;
}
void Person::setGender(char gender)
{
  this->gender = gender;
}

long Person::getIc() const
{
  return ic;
}
int Person::getAge() const
{
  return age;
}
std::string Person::getName() const
{
  return name;
}
std::string Person::getContactNum() const
{
  return contactNum;
}
char Person::getGender() const
{
  return gender;
}
