
# 🍔 TasteTerminal (FoodCort)

![C++](https://img.shields.io/badge/Language-C++-blue.svg?style=for-the-badge&logo=c%2B%2B)
![IDE](https://img.shields.io/badge/IDE-Visual%20Studio-purple.svg?style=for-the-badge&logo=visual-studio)
![Concepts](https://img.shields.io/badge/Concepts-OOP%20%7C%20File%20Handling-green.svg?style=for-the-badge)
![License](https://img.shields.io/badge/License-MIT-yellow.svg?style=for-the-badge)

## 📄 Project Overview
**TasteTerminal** (internally titled *FoodCort*) is a comprehensive **Console-Based Food Ordering Application** developed in C++. 

Built as a 3rd-semester final project, this system mimics a real-world backend for a food delivery service. It moves beyond simple logic by implementing a **persistent database system** using text files, ensuring that User Credentials, Order History, and Reviews are saved permanently.

## ✨ Key Features
The application features a secure entry system and a dynamic dashboard with **10 core functionalities**:

### 🔐 User Management & Security
*   **Sign Up:** Registers new users and securely saves credentials to `users.txt` and `userkey.txt`.
*   **Sign In:** Validates credentials against stored records.
*   **Customer Details:** Admin view to retrieve address and contact info from `usercontactInfo.txt` and `address.txt`.

### 🍽️ Dynamic Menu System
*   **🥗 Vegetarian Dishes:** Loads filtered items from `Veg.txt`.
*   **🍗 Non-Vegetarian Dishes:** Loads filtered items from `nonveg.txt`.
*   **🍱 Combo Deals:** Special bundles loaded from `comboItems.txt`.
*   **📜 Show Full Menu:** Aggregates and displays all available items at once.

### 🛒 Advanced Cart & Checkout
*   **Add Item to Order:** Users search by name; the system uses file streaming to find the ID and Price automatically.
*   **Remove Item:** Users can delete specific items from their active cart using the Item ID.
*   **View Current Order:** Real-time display of selected items and running total.
*   **Checkout & Pay:** Calculates the final bill and processes a simulated payment.
*   **Rating System:** Allows users to leave feedback (1-5 stars) and comments.

## 🛠️ Technical Implementation
This project demonstrates proficiency in advanced C++ concepts:

1.  **Object-Oriented Programming (OOP):**
    *   **Inheritance:** `Customer` inherits from `Signin`; `Vegetarion` and `Non_Vegetarion` inherit from `Menu`.
    *   **Polymorphism & Encapsulation:** Used to protect sensitive data like Passwords.
2.  **File Handling (Database):**
    *   Uses `fstream` (ifstream/ofstream) to read/write to **7 different text files** for data persistence.
3.  **Dynamic Memory Allocation:**
    *   Utilizes pointers (e.g., `int* ids`) to manage item IDs efficiently during runtime.
4.  **Operator Overloading:**
    *   Implemented in the `Order` class (e.g., `currentOrder + selectedItem`) to add items to the cart seamlessly.

## 📂 File Structure
```text
TasteTerminal/
├── Source.cpp           # Main entry point containing the 10-option Menu Loop
├── Foodcort.cpp         # Implementation of class functions (Logic Layer)
├── Foodcort.h           # Header file (Class definitions)
├── users.txt            # Database: Usernames
├── userkey.txt          # Database: Passwords
├── usercontactInfo.txt  # Database: Phone numbers
├── address.txt          # Database: Physical addresses
├── Veg.txt              # Menu Data: Veg items
├── nonveg.txt           # Menu Data: Non-Veg items
├── comboItems.txt       # Menu Data: Combo deals
├── LICENSE              # MIT License
└── README.md            # Project Documentation
🚀 How to Run

Clone the Repository:

code
Bash
download
content_copy
expand_less
git clone https://github.com/Wareesha381/TasteTerminal-.git

Open in Visual Studio:

Open the .sln file or Import the source files.

⚠️ Critical Step:

Ensure all .txt files (Veg.txt, users.txt, etc.) are in the same directory as your source code (Source.cpp) or the compiled executable.

If the program cannot find the files, the menu will appear empty.

Build and Run:

Press Ctrl + F5 to compile and run.

📸 Screenshots

(Add your screenshots here by dragging and dropping them into the GitHub editor)

👥 Contributors

This project was a collaborative effort:

Wareesha Rehman - Backend Logic, File Handling, and Authentication System.

Eman Amin - OOP Structure, Menu Class Implementation, and UI Logic.

📜 License

This project is licensed under the MIT License - see the LICENSE file for details.

code
Code
download
content_copy
expand_less
