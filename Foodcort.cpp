#include "Foodcort.h"

// GLOBAL VARIABLES
int* ids = new int[100];
int countID = 0;

// ================= SIGNIN =================
Signin::Signin() {
    name = "Unknown";
    password = "Unknown";
    contact_Info = "Unknown";
    address = "Unknown";
}

void Signin::setName(string name) { this->name = name; }
void Signin::setPassword(string password) { this->password = password; }
void Signin::setContactInfo(string contact_Info) { this->contact_Info = contact_Info; }
void Signin::setAddress(string address) { this->address = address; }

string Signin::getName() const { return name; }
string Signin::getPassword() const { return password; }
string Signin::getContactInfo() const { return contact_Info; }
string Signin::getAddress() const { return address; }

void Signin::savingData() {
    ofstream users("users.txt", ios::app);
    ofstream userKey("userkey.txt", ios::app);
    ofstream usercInfo("usercontactInfo.txt", ios::app);
    ofstream userAddress("address.txt", ios::app);

    if (!users || !userKey || !usercInfo || !userAddress) {
        cout << "Error opening file!" << endl;
        return;
    }

    users << name << endl;
    userKey << password << endl;
    usercInfo << contact_Info << endl;
    userAddress << address << endl;

    users.close();
    userKey.close();
    usercInfo.close();
    userAddress.close();
}

void Signin::display() const {
    cout << "Name: " << name << endl;
    cout << "Password: " << password << endl;
    cout << "Address: " << address << endl;
    cout << "Contact Number: " << contact_Info << endl;
}

// ================= CUSTOMER =================
Customer::Customer() {}

Customer::Customer(const string& username) {
    loadFromFile(username);
}

void Customer::loadFromFile(const string& username) {
    ifstream userFile("users.txt");
    ifstream passFile("userkey.txt");
    ifstream contactFile("usercontactInfo.txt");
    ifstream addressFile("address.txt");

    if (!userFile || !passFile || !contactFile || !addressFile) {
        cout << "Error opening files!" << endl;
        return;
    }

    string nameLine, passLine, contactLine, addressLine;
    bool found = false;

    while (getline(userFile, nameLine) && getline(passFile, passLine) &&
        getline(contactFile, contactLine) && getline(addressFile, addressLine)) {

        if (!nameLine.empty() && nameLine.back() == '\r') nameLine.pop_back();
        if (!passLine.empty() && passLine.back() == '\r') passLine.pop_back();
        if (!contactLine.empty() && contactLine.back() == '\r') contactLine.pop_back();
        if (!addressLine.empty() && addressLine.back() == '\r') addressLine.pop_back();

        if (nameLine == username) {
            setName(nameLine);
            setPassword(passLine);
            setContactInfo(contactLine);
            setAddress(addressLine);
            found = true;
            break;
        }
    }

    if (!found) cout << "User not found!" << endl;

    userFile.close();
    passFile.close();
    contactFile.close();
    addressFile.close();
}

// ================= LOGIN =================
logIn::logIn() {
    name = "Unknown";
    password = "Unknown";
    login = false;
}

logIn::logIn(string name, string password) {
    this->name = name;
    this->password = password;
    login = false;
}

void logIn::checkfile() {
    ifstream userfile("users.txt");
    ifstream passkeyfile("userkey.txt");

    if (!userfile || !passkeyfile) {
        cout << "There is an issue, Try Again Later" << endl;
        return;
    }

    string savedUser, savedPass;
    bool found = false;
    login = false;

    while (getline(userfile, savedUser) && getline(passkeyfile, savedPass)) {
        if (savedUser == name) {
            found = true;
            if (savedPass == password) {
                cout << "Logged In Successfully!" << endl;
                login = true;
            }
            else {
                cout << "Incorrect Password" << endl;
            }
            break;
        }
    }

    if (!found) cout << "Incorrect Username" << endl;
}

void logIn::display() {
    if (login) {
        cout << "UserName: " << name << endl;
        cout << "Password: " << password << endl;
    }
    else {
        cout << "Invalid credentials" << endl;
    }
}

logIn::~logIn() {}

// ================= MENU =================
Menu::Menu() {
    name = "Unknown";
    id = 0;
    price = 0;
}

void Menu::setName(const string& name) { this->name = name; }
void Menu::setId(int id) { this->id = id; }
void Menu::setPrice(int price) { this->price = price; }

string Menu::getName() const { return name; }
int Menu::getId() const { return id; }
int Menu::getPrice() const { return price; }

void Menu::Veg() {
    ifstream vegFood("Veg.txt");
    if (!vegFood) { cout << "Vegetarian Food File isn't opening!" << endl; return; }

    cout << "\nId\tName\tPrice\n\n";
    int i = 0;
    while (vegFood >> id >> price) {
        vegFood.ignore();
        getline(vegFood, name);
        ids[i] = id;
        cout << id << "\t" << name << "\t" << price << " Rs\n";
        i++;
        countID++;
    }
    vegFood.close();
}

void Menu::Non_Veg() {
    ifstream nonvegfile("nonveg.txt");
    if (!nonvegfile) { cout << "Non-Vegetarian Food File isn't opening!" << endl; return; }

    cout << "\nId\tName\tPrice\n\n";
    while (nonvegfile >> id >> price) {
        nonvegfile.ignore();
        getline(nonvegfile, name);
        ids[countID] = id;
        cout << id << "\t" << name << "\t" << price << " Rs\n";
        countID++;
    }
    nonvegfile.close();
}

void Menu::ComboItems() {
    ifstream comboItemsfile("comboItems.txt");
    if (!comboItemsfile) { cout << "Deals are not available!" << endl; return; }

    cout << "\nId\tName\tPrice\n\n";
    while (comboItemsfile >> id >> price) {
        comboItemsfile.ignore();
        getline(comboItemsfile, name);
        ids[countID] = id;
        cout << id << "\t" << name << "\t" << price << " Rs\n";
        countID++;
    }
    comboItemsfile.close();
}

// ================= VEGETARIAN / NON-VEG / COMBO =================
Vegetarion::Vegetarion() { Veg(); }
Non_Vegetarion::Non_Vegetarion() { Non_Veg(); }
comboDeals::comboDeals() { ComboItems(); }

// ================= ORDER =================
Order::Order(int orderID, int customerID) {
    this->orderID = orderID;
    this->customerID = customerID;
    this->totalPrice = 0.0;
    this->itemCount = 0;
}

void Order::addItem(const Menu& item) {
    if (itemCount < 100) {
        menuItems[itemCount] = item;
        itemCount++;
        calculateTotal();
    }
    else {
        cout << "Cannot add more items. Order is full." << endl;
    }
}

void Order::removeItemById(int removeId) {
    bool found = false;
    for (int i = 0; i < itemCount; i++) {
        if (menuItems[i].getId() == removeId) {
            for (int j = i; j < itemCount - 1; j++) menuItems[j] = menuItems[j + 1];
            itemCount--;
            calculateTotal();
            found = true;
            cout << "Item with ID " << removeId << " removed successfully." << endl;
            break;
        }
    }
    if (!found) cout << "Item ID not found in order." << endl;
}

void Order::calculateTotal() {
    totalPrice = 0.0;
    for (int i = 0; i < itemCount; i++) totalPrice += menuItems[i].getPrice();
}

Order& Order::operator+(Menu& item) {
    addItem(item);
    return *this;
}

double Order::getTotalPrice() const { return totalPrice; }

void Order::displayOrder() const {
    cout << "Order ID: " << orderID << "\nCustomer ID: " << customerID << "\nMenu Items:\n";
    for (int i = 0; i < itemCount; i++)
        cout << menuItems[i].getId() << " - " << menuItems[i].getName()
        << " - " << menuItems[i].getPrice() << " Rs\n";
    cout << "Total Price: " << totalPrice << " Rs\n";
}

// ================= PAYMENT =================
Payment::Payment(int pid, int oid, double amt) {
    paymentID = pid;
    orderID = oid;
    amount = amt;
    status = "Pending";
}

void Payment::processPayment() {
    status = "Paid";
    cout << "Payment Successful!" << endl;
}

void Payment::refund() {
    if (status == "Paid") {
        status = "Refunded";
        cout << "Payment Refunded Successfully!" << endl;
    }
    else {
        cout << "Refund not possible!" << endl;
    }
}

void Payment::displayPayment() const {
    cout << "Payment ID: " << paymentID << "\nOrder ID: " << orderID
        << "\nAmount: " << amount << " Rs\nStatus: " << status << endl;
}

// ================= REVIEW =================
Review::Review() {
    rating = 0;
    comment = "No Review";
}

void Review::giveRating(int rate, const string& comm) {
    rating = rate;
    comment = comm;
    cout << "Thank you for your feedback!" << endl;
}

void Review::viewReviews() const {
    cout << "\n--- Review Details ---\nRating: " << rating << "/5\nComment: " << comment << endl;
}