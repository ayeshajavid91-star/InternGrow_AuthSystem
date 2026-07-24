# 🔐 Secure Auth System

A secure user authentication system featuring **registration, login, and a smart account-lockout mechanism**, built as a robust **C++ console application** and mirrored in an interactive **web demo (Vault Panel)**.

**🔗 Live Demo:** [https://ayeshajavid91-star.github.io/Secure-Auth-System/](https://ayeshajavid91-star.github.io/Secure-Auth-System/)

---

## 📌 Project Overview

This project implements a complete authentication flow — user registration, credential verification, and protection against brute-force login attempts — with data persisted to an external file in the C++ version, and browser-based storage in the web demo.

---

## ✨ Features

### 🔑 Core Features
- User registration with duplicate-username detection
- Secure login with credential verification
- Input validation (empty fields, minimum password length)
- Credentials stored safely with basic password encoding
- Clean, menu-driven interface

### 🔒 Account Lockout System
- Tracks failed login attempts per user
- Account automatically **locks for 60 seconds** after **3 consecutive failed attempts**
- Live countdown display while an account is locked
- Automatically unlocks and resets attempts once the lockout period expires
- Lockout state persists across sessions

### 🌐 Web Demo — "Vault Panel"
- Interactive Login / Register interface with a secure-terminal-inspired design
- Real-time **failed-attempt indicator** (LED-style visual feedback)
- Live lockout countdown timer
- Same 3-attempt / 60-second lockout logic as the C++ version, running entirely client-side

---

## 🛠️ Tech Stack

| Layer | Technology |
|---|---|
| Core Logic | C++ (fstream, structs, maps, ctime) |
| Web Demo | HTML, CSS, JavaScript |
| Storage (C++) | External file (`users.txt`, `lockout.txt`) |
| Storage (Web) | Browser localStorage |

---

## ⚙️ How It Works

1. **Registration** — Username and password are validated, then securely stored.
2. **Login** — The system checks for an active lockout before verifying credentials.
3. **Lockout Logic** — Each failed attempt increments a counter. On the 3rd consecutive failure, the account is locked for 60 seconds; further attempts are blocked until the timer expires.

---

## ▶️ How to Run

### C++ Console Version
```bash
g++ Auth_System.cpp -o Auth_System
./Auth_System
```
Follow the on-screen menu to **Register**, **Login**, or **Exit**.

### Web Demo
No installation needed — try it live:
👉 **[Open Vault Panel](https://ayeshajavid91-star.github.io/Secure-Auth-System/)**

Or run locally:
```bash
git clone https://github.com/ayeshajavid91-star/Secure-Auth-System.git
cd Secure-Auth-System
```
Then open `index.html` in your browser.

---

## 📂 Project Structure

```
Secure-Auth-System/
├── Auth_System.cpp     # C++ console application
├── index.html           # Web demo (Vault Panel)
└── README.md
```

---

## 🏷️ Suggested GitHub Topics

```
cpp
authentication-system
login-system
secure-login
file-handling
password-security
lockout-mechanism
javascript
html-css-javascript
web-app
console-application
programming-project
```

---

## 👤 Author

Developed by **Ayesha Javid**.

---

## 📄 License

**All Rights Reserved.**

This project and its source code are the intellectual property of the author. No part of this repository — including the code, design, or documentation — may be copied, modified, distributed, used, or reproduced in any form without the explicit written permission of the author.

© 2026 Ayesha Javid. Unauthorized use is strictly prohibited.

For permissions or licensing inquiries, contact: **ayeshajavid91@gmail.com**
