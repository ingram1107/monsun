#include <fstream>
#include <Customer.cpp>
#include <gtest/gtest.h>

TEST(CustomerTest, Getters)
{
  Customer c1{123456789,"Siah",'m',20,"0176226799",4500.50,"25FEB2021","1MAY2021","MR.LEE","PARIS"};

  EXPECT_EQ(123456789, c1.getIc());
  EXPECT_EQ("Siah", c1.getName());
  EXPECT_EQ('m', c1.getGender());
  EXPECT_EQ(20, c1.getAge());
  EXPECT_EQ("0176226799", c1.getContactNum());
  EXPECT_EQ(4500.50, c1.getPayment());
  EXPECT_EQ("25FEB2021", c1.getPaymentDate());
  EXPECT_EQ("1MAY2021", c1.getDepartureDate());
  EXPECT_EQ("MR.LEE", c1.getAgency());
  EXPECT_EQ("PARIS", c1.getDest());
}

TEST(CustomerTest, Setters)
{
  Customer c1{};

  c1.setIc(123456789);
  c1.setName("Siah");
  c1.setGender('m');
  c1.setAge(20);
  c1.setContactNum("0176226799");
  c1.setPayment(4500.50);
  c1.setPaymentDate("25FEB2021");
  c1.setDepartureDate("1MAY2021");
  c1.setAgency("MR.LEE");
  c1.setDest("PARIS");

  EXPECT_EQ(123456789, c1.getIc());
  EXPECT_EQ("Siah", c1.getName());
  EXPECT_EQ('m', c1.getGender());
  EXPECT_EQ(20, c1.getAge());
  EXPECT_EQ("0176226799", c1.getContactNum());
  EXPECT_EQ(4500.50, c1.getPayment());
  EXPECT_EQ("25FEB2021", c1.getPaymentDate());
  EXPECT_EQ("1MAY2021", c1.getDepartureDate());
  EXPECT_EQ("MR.LEE", c1.getAgency());
  EXPECT_EQ("PARIS", c1.getDest());
}

TEST(CustomerTest, IsEqual)
{
  Customer c1{123456789,"Siah",'m',20,"0176226799",4500.50,"25FEB2021","1MAY2021","MR.LEE","PARIS"};
  Customer c2{c1};

  EXPECT_EQ(true, c1 == c2);
}

TEST(CustomerTest, IsNotEqual)
{
  Customer c1{123456789,"Siah",'m',20,"0176226799",4500.50,"25FEB2021","1MAY2021","MR.LEE","PARIS"};
  Customer c2{c1};

  EXPECT_EQ(false, c1 != c2);
}

TEST(CustomerTest, MorePriority)
{
  Customer c1{123456789,"Siah",'m',20,"0176226799",4500.50,"25FEB2021","1MAY2021","MR.LEE","PARIS"};
  Customer c2{234567890, "Loh", 'f', 25, "0127839111", 3519.20, "24FEB2021", "24JUNE2021", "MR.LEE", "ISTABUL"};

  EXPECT_TRUE(c2 > c1);
}

TEST(CustomerTest, LessPriority)
{
  Customer c1{123456789,"Siah",'m',20,"0176226799",4500.50,"25FEB2021","1MAY2021","MR.LEE","PARIS"};
  Customer c2{234567890, "Loh", 'f', 25, "0127839111", 3519.20, "24FEB2021", "24JUNE2021", "MR.LEE", "ISTABUL"};

  EXPECT_TRUE(c1 < c2);
}

// TODO: Integration test for File I/O
