// Foodcort.h
#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

extern int* ids;
extern int countID;

// ================= SIGNIN =================
class Signin {
protected:
    string name;
    string password;
    string contact_Info;
    string address;

public:
    Signin();  // Default constructor
    void setName(string name);
    void setPassword(string password);
    void setContactInfo(string contact_Info);
    void setAddress(string address);

    string getName() const;
    string getPassword() const;
    string getContactInfo() const;
    string getAddress() const;

    void savingData();
    void display() const;
};

// ================= CUSTOMER =================
class Customer : public Signin {
public:
    Customer();
    Customer(const string& username);
    void loadFromFile(const string& username);
};

// ================= LOGIN =================
class logIn {
private:
    string name;
    string password;
    bool login;

public:
    logIn();  // default constructor
    logIn(string name, string password); // parameterized constructor
    void checkfile();
    void display();
    ~logIn();
};

// ================= MENU =================
class Menu {
protected:
    string name;
    int id;
    int price;

public:
    Menu(); // Constructor

    void setName(const string& name);
    void setId(int id);
    void setPrice(int price);

    string getName() const;
    int getId() const;
    int getPrice() const;

    void Veg();
    void Non_Veg();
    void ComboItems();
};

// ================= VEGETARIAN / NON-VEG / COMBO =================
class Vegetarion : public Menu {
public:
    Vegetarion();
};

class Non_Vegetarion : public Menu {
public:
    Non_Vegetarion();
};

class comboDeals : public Menu {
public:
    comboDeals();
};

// ================= ORDER =================
class Order {
private:
    int orderID;
    int customerID;
    Menu menuItems[100];
    int itemCount;
    double totalPrice;

public:
    Order(int orderID, int customerID);
    void addItem(const Menu& item);
    void removeItemById(int removeId);
    void calculateTotal();
    Order& operator+(Menu& item);
    double getTotalPrice() const;
    void displayOrder() const;
};

// ================= PAYMENT =================
class Payment {
private:
    int paymentID;
    int orderID;
    double amount;
    string status;

public:
    Payment(int pid, int oid, double amt);
    void processPayment();
    void refund();
    void displayPayment() const;
};

// ================= REVIEW =================
class Review {
private:
    int rating;
    string comment;

public:
    Review();
    void giveRating(int rate, const string& comm);
    void viewReviews() const;
};