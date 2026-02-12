Based on the code and file structure you provided from your repository, here is a professional README.md file tailored specifically for your project.

Since your repository is named TasteTerminal but the internal code refers to FoodCort, I have combined them to make it look professional.

Instructions:

Copy the code block below.

Go to your GitHub repository (TasteTerminal-).

Click on the pencil icon ✏️ on your existing README.md file.

Paste this content in and commit changes.

code
Markdown
download
content_copy
expand_less
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

### 🔐 User Management
*   **Sign Up:** Registers new users and saves credentials (`users.txt`, `userkey.txt`).
*   **Sign In:** Validates credentials against stored records.
*   **Customer Details:** Admin view to retrieve address and contact info (`usercontactInfo.txt`, `address.txt`).

### 🍽️ Dynamic Menu System
*   **Vegetarian Menu:** Reads items from `Veg.txt`.
*   **Non-Vegetarian Menu:** Reads items from `nonveg.txt`.
*   **Combo Deals:** Reads bundles from `comboItems.txt`.
*   **Full Menu Display:** Aggregates all categories.

### 🛒 Order Processing
*   **Add to Cart:** Users can search items by name; the system retrieves IDs and prices automatically.
*   **Remove Item:** Remove specific items from the current order by ID.
*   **View Order:** Live updates of the current bill.
*   **Checkout & Payment:** Calculates total and processes payment (simulated).
*   **Rating System:** Allows users to leave feedback (`Review` class).

## 🛠️ Technical Implementation
This project relies heavily on advanced C++ concepts:

1.  **Object-Oriented Programming (OOP):**
    *   **Inheritance:** `Customer` inherits from `Signin`; `Vegetarion` inherits from `Menu`.
    *   **Polymorphism & Encapsulation:** Used to protect user data (Passwords/Keys).
2.  **File Handling (Database):**
    *   Uses `fstream` (ifstream/ofstream) to manage 7+ text files for data persistence.
3.  **Dynamic Memory Allocation:**
    *   Utilizes pointers (e.g., `int* ids`) to manage item IDs efficiently during runtime.
4.  **Operator Overloading:**
    *   Implemented in the `Order` class (e.g., `currentOrder + selectedItem`) to add items seamlessly.

## 📂 File Structure
```text
TasteTerminal/
├── Source.cpp           # Main entry point and menu loop
├── Foodcort.cpp         # Implementation of class functions
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
