# InternGrow_AuthSystem

## 📌 Project Overview
**Secure User Authentication System** is a C++ console application developed as part of the **InternGrow C++ Programming Track (Module 1 – Task 2)**. It allows users to register with a username and password, validates login credentials, and securely stores user data in an external file.

## 🚀 Features

### Core Features
- User Registration with duplicate username detection
- Secure Login with credential verification against stored data
- Input validation (empty fields, minimum password length)
- Credentials stored in an external file (`users.txt`) with basic password encoding
- Menu-driven interface (Register / Login / Exit)

### 🔒 Upgrade Feature — Lockout Mechanism
- Tracks failed login attempts for each user
- After **3 consecutive wrong password attempts**, the account is **temporarily locked** for a fixed duration (60 seconds)
- Displays remaining lockout time if a locked account tries to log in
- Automatically unlocks and resets attempts once the lockout period expires
- Lockout data persists across program runs using a separate file (`lockout.txt`)

## 🛠️ Tech Stack
- **Language:** C++
- **Concepts Used:** File Handling (fstream), Structs, Maps, String Manipulation, Time Functions (ctime), Loops & Conditionals

## ⚙️ How It Works
1. **Registration:** Username and password are checked for validity, then stored in `users.txt` in the format `username,encodedPassword`.
2. **Login:** The system first checks if the account is locked. If not, it verifies the entered credentials against the stored file.
3. **Lockout Logic:** Each failed attempt increases a counter. On reaching 3 failed attempts, a lockout timestamp is set (current time + 60 seconds). Login attempts are blocked until this time passes.

## ▶️ How to Run
1. Compile the program:
g++ Auth_System.cpp -o Auth_System

2. Run the executable:
./Auth_System

3. Choose an option from the menu:
1. Register
2. Login
3. Exit

4. Follow the on-screen prompts to enter your username and password.

## 📸 Sample Output
========== Secure User Authentication System ==========

1. Register
2. Login
3. Exit
Apna choice enter karo: 2
Username enter karo: testuser
Password enter karo: wrongpass
❌ Galat password! Attempt 1 of 3.

🔒 3 consecutive galat attempts ho gaye! Account 60 seconds ke liye lock kar diya gaya hai.

## 🎓 About InternGrow
This project was developed as part of the **InternGrow C++ Programming Track**, a project-based internship program focused on providing hands-on programming experience.

## 👤 Author
Developed by [Your Name] as part of InternGrow Internship — Module 1.
