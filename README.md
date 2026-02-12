# 🍔 FoodCort - Console Food Ordering System

![C++](https://img.shields.io/badge/Language-C++-blue.svg)
![IDE](https://img.shields.io/badge/IDE-Visual%20Studio-purple.svg)
![Concepts](https://img.shields.io/badge/Concepts-OOP%20%7C%20File%20Handling-green.svg)

## 📄 Project Overview
**FoodCort** is a fully functional console-based application designed to simulate a real-world food ordering experience. Built as a 3rd-semester final project, this system leverages **Object-Oriented Programming (OOP)** principles to manage user data, menus, and orders efficiently.

It features a robust **File Handling system** that acts as a database, ensuring that user credentials, order history, and ratings are saved permanently even after the program closes.

## ✨ Key Features
The application includes a secure **Login/Sign-Up System** followed by a dynamic main menu with **10 functional options**:

*   **🔐 Authentication:** Secure Sign-Up & Login (Data saved in `.txt` files).
*   **🥗 Vegetarian & Non-Veg Menus:** Filtered display of dishes.
*   **🍱 Combo Meals:** Special bundled offers.
*   **📜 Full Menu Display:** View all available items at once.
*   **🛒 Cart Management:**
    *   Add Items to Order.
    *   Remove Items from Order.
    *   View Current Order.
*   **💳 Checkout System:** Calculates total bill with an integrated Rating system.
*   **🔄 Navigation:** easy exit and return to the main Splash Screen.

## 🛠️ Technical Concepts Used
This project demonstrates proficiency in the following C++ concepts:
1.  **Object-Oriented Programming (OOP):** Usage of Classes, Objects, Inheritance, and Encapsulation.
2.  **File Handling:** Using `fstream` to read/write User Data and Menu details to text files.
3.  **Dynamic Memory Allocation:** Efficiently managing memory using pointers.
4.  **Data Structures:** Organizing menu items and cart data.

## 🚀 How to Run
1.  Clone this repository:
    ```bash
    git clone https://github.com/your-username/FoodCort.git
    ```
2.  Open the project in **Microsoft Visual Studio**.
3.  Ensure the `.txt` files (database files) are in the same directory as the source code (or the debug folder).
4.  Build and Run (`Ctrl + F5`).

## 📂 File Structure
*   `main.cpp` - The entry point of the application.
*   `header.h` - Class declarations and prototypes.
*   `functions.cpp` - Implementation of logic.
*   `users.txt` - Stores registered user credentials.
*   `menu.txt` - Stores food items and prices.

## 👥 Contributors
*   **[Your Name]** - *Backend Logic & File Handling*
*   **Eman Amin** - *OOP Structure & Menu Implementation*

## 📜 License
This project is for educational purposes as part of the Computer Science curriculum.
