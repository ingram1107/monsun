#include <string>

class Person {
  protected:
    long ic;
    int age;
    std::string name, contactNum;
    char gender;

  public:
    Person() = default;
    Person(long ic, std::string name, char gender, int age, std::string contactNum);
    ~Person() = default;

    // TODO: move these functions to a Display class
    virtual void display() const = 0;
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
