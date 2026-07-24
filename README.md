<div align="center">

<!-- Animated banner -->
<img src="https://capsule-render.vercel.app/api?type=waving&color=gradient&customColorList=2,12,24&height=220&section=header&text=Secure%20Auth%20System&fontSize=42&fontColor=ffffff&animation=twinkling&fontAlignY=35&desc=Login%20%7C%20Lockout%20Defense%20%7C%20Vault%20Panel&descAlignY=55&descSize=18" width="100%"/>

<!-- Typing animation -->
<a href="https://ayeshajavid91-star.github.io/Secure-Auth-System/">
  <img src="https://readme-typing-svg.demolab.com?font=Fira+Code&weight=600&size=24&duration=2500&pause=800&color=00D9A5&center=true&vCenter=true&width=650&lines=%F0%9F%94%90+Register+%2B+Login+with+real+validation;%F0%9F%9A%A8+3+strikes+%E2%86%92+60s+account+lockout;%F0%9F%92%BE+C%2B%2B+file+persistence+%2B+Web+localStorage;%F0%9F%96%A5%EF%B8%8F+Try+the+Vault+Panel+live+demo" alt="Typing SVG" />
</a>

<br/>

<!-- Badges -->
<p>
  <img src="https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white" />
  <img src="https://img.shields.io/badge/JavaScript-F7DF1E?style=for-the-badge&logo=javascript&logoColor=black" />
  <img src="https://img.shields.io/badge/HTML5-E34F26?style=for-the-badge&logo=html5&logoColor=white" />
  <img src="https://img.shields.io/badge/CSS3-1572B6?style=for-the-badge&logo=css3&logoColor=white" />
  <img src="https://img.shields.io/badge/GitHub_Pages-222222?style=for-the-badge&logo=github&logoColor=white" />
</p>

<p>
  <img alt="Repo Size" src="https://img.shields.io/github/repo-size/ayeshajavid91-star/Secure-Auth-System?style=flat-square&color=00D9A5" />
  <img alt="Last Commit" src="https://img.shields.io/github/last-commit/ayeshajavid91-star/Secure-Auth-System?style=flat-square&color=0984e3" />
  <img alt="Issues" src="https://img.shields.io/github/issues/ayeshajavid91-star/Secure-Auth-System?style=flat-square&color=e17055" />
  <img alt="Stars" src="https://img.shields.io/github/stars/ayeshajavid91-star/Secure-Auth-System?style=flat-square&color=fdcb6e" />
  <img alt="License" src="https://img.shields.io/badge/License-All%20Rights%20Reserved-red?style=flat-square" />
</p>

<h3>🔐 A brute-force-resistant authentication engine — console-grade security, browser-grade convenience.</h3>

<a href="https://ayeshajavid91-star.github.io/Secure-Auth-System/">
  <img src="https://img.shields.io/badge/▶%20OPEN%20VAULT%20PANEL-00D9A5?style=for-the-badge&logoColor=white" />
</a>

</div>

<br/>

<img src="https://user-images.githubusercontent.com/74038190/212284100-561aa473-3905-4a80-b561-0d28506553ee.gif" width="100%">

---

## 📚 Table of Contents

| # | Section |
|---|---------|
| 1 | [📌 Project Overview](#-project-overview) |
| 2 | [🎬 Preview](#-preview) |
| 3 | [✨ Features](#-features) |
| 4 | [🔒 Lockout System Deep Dive](#-lockout-system-deep-dive) |
| 5 | [🏗️ Architecture](#️-architecture) |
| 6 | [🛠️ Tech Stack](#️-tech-stack) |
| 7 | [⚙️ How It Works](#️-how-it-works) |
| 8 | [▶️ Installation & Usage](#️-installation--usage) |
| 9 | [📂 Project Structure](#-project-structure) |
| 10 | [🛡️ Security Notes](#️-security-notes) |
| 11 | [🗺️ Roadmap](#️-roadmap) |
| 12 | [👤 Author](#-author) |
| 13 | [📄 License](#-license) |

---

## 📌 Project Overview

This project implements a complete authentication flow — **user registration**, **credential verification**, and **brute-force protection** — available in two flavors:

> 💻 **C++ Console App** — credentials persisted to external files (`users.txt`, `lockout.txt`)
> 🌐 **Web Demo ("Vault Panel")** — same logic, running entirely client-side via `localStorage`

<div align="center">

```mermaid
flowchart LR
    A([👤 User Attempts Login]) --> B{Account Locked?}
    B -->|Yes| C[⏳ Show Countdown Timer]
    C --> B
    B -->|No| D{Credentials Valid?}
    D -->|✅ Yes| E([🔓 Access Granted])
    D -->|❌ No| F[➕ Increment Fail Counter]
    F --> G{3 Consecutive Fails?}
    G -->|No| A
    G -->|Yes| H([🔒 Lock Account for 60s])
    H --> C
```

</div>

---

## 🎬 Preview

<div align="center">

| 🖥️ Vault Panel — Login | 🚨 Lockout Countdown |
|:---:|:---:|
| <img src="https://user-images.githubusercontent.com/74038190/216122041-518ac897-8d92-4c6b-9b3f-ca01dcaf38ee.png" width="380"/> | <img src="https://user-images.githubusercontent.com/74038190/216122041-518ac897-8d92-4c6b-9b3f-ca01dcaf38ee.png" width="380"/> |

*(Swap these placeholders for real screenshots or a screen-recorded GIF of the Vault Panel in `/assets`)*

</div>

---

## ✨ Features

<table>
<tr>
<td width="50%" valign="top">

### 🔑 Core Features

- 📝 User registration with duplicate-username detection
- 🔐 Secure login with credential verification
- ✅ Input validation (empty fields, min password length)
- 🧂 Credentials stored with basic password encoding
- 🖥️ Clean, menu-driven console interface

</td>
<td width="50%" valign="top">

### 🔒 Account Lockout System

- 📊 Tracks failed login attempts per user
- ⛔ Auto-locks for **60 seconds** after **3 consecutive fails**
- ⏱️ Live countdown display while locked
- ♻️ Auto-unlocks & resets attempt counter after expiry
- 💾 Lockout state **persists across sessions**

</td>
</tr>
<tr>
<td colspan="2" valign="top">

### 🌐 Web Demo — "Vault Panel"

- 🖤 Secure-terminal-inspired UI for Login / Register
- 🔴 Real-time **failed-attempt LED indicator**
- ⏳ Live lockout countdown timer, client-side
- 🔁 Identical **3-attempt / 60-second** lockout logic as the C++ core — no server required

</td>
</tr>
</table>

---

## 🔒 Lockout System Deep Dive

<details>
<summary><b>🔍 Click to expand — Lockout state machine</b></summary>

<br/>

```mermaid
stateDiagram-v2
    [*] --> Unlocked
    Unlocked --> Unlocked: Failed attempt (1st / 2nd)
    Unlocked --> Locked: 3rd consecutive failed attempt
    Locked --> Locked: Login attempt blocked, countdown shown
    Locked --> Unlocked: 60s timer expires, counter resets
    Unlocked --> [*]: Successful login
```

| State | Trigger | Behavior |
|:---|:---|:---|
| 🟢 Unlocked | Default / after timer expiry | Login attempts allowed, counter tracked |
| 🟡 Warning | 1–2 failed attempts | User notified of remaining attempts |
| 🔴 Locked | 3rd consecutive failure | All logins blocked, 60s countdown starts |
| 🔓 Reset | Successful login **or** timer expiry | Fail counter reset to 0 |

</details>

<details>
<summary><b>💻 Click to expand — C++ lockout logic sample</b></summary>

<br/>

```cpp
bool attemptLogin(User &user, const string &password) {
    if (isLocked(user)) {
        cout << "🔒 Account locked. Try again in "
             << remainingLockTime(user) << "s\n";
        return false;
    }

    if (verifyPassword(user, password)) {
        user.failedAttempts = 0;   // ✅ reset on success
        return true;
    }

    user.failedAttempts++;
    if (user.failedAttempts >= 3) {
        user.lockUntil = time(nullptr) + 60; // 🔒 lock for 60s
        cout << "🚨 Too many failed attempts. Account locked for 60s.\n";
    }
    return false;
}
```

</details>

---

## 🏗️ Architecture

<div align="center">

```mermaid
graph TD
    subgraph "💻 C++ Console App"
        A1[Auth_System.cpp] --> A2[Register / Login Menu]
        A2 --> A3[Credential Validator]
        A3 --> A4[Lockout Manager]
        A4 --> A5[(users.txt / lockout.txt)]
    end

    subgraph "🌐 Web Demo - Vault Panel"
        B1[index.html] --> B2[Login / Register UI]
        B2 --> B3[Credential Validator - JS]
        B3 --> B4[Lockout Manager - JS]
        B4 --> B5[(Browser localStorage)]
    end

    A4 -.identical 3-attempt / 60s logic.- B4
```

</div>

---

## 🛠️ Tech Stack

<div align="center">

<img src="https://skillicons.dev/icons?i=cpp,js,html,css,git,github" />

</div>

<div align="center">

| Layer | Technology |
|:---|:---|
| 🎮 Core Logic | C++ — `fstream`, `structs`, `maps`, `ctime` |
| 💻 Console App | C++ |
| 🌐 Web Demo | HTML5, CSS3, Vanilla JavaScript |
| 🗄️ Storage (C++) | External files — `users.txt`, `lockout.txt` |
| 🗄️ Storage (Web) | Browser `localStorage` |
| 🚀 Hosting | GitHub Pages |

</div>

---

## ⚙️ How It Works

| Step | Description |
|:---:|:---|
| 1️⃣ | **Registration** — username & password validated, then securely stored |
| 2️⃣ | **Login** — system checks for an active lockout *before* verifying credentials |
| 3️⃣ | **Lockout Logic** — each failed attempt increments a counter; on the 3rd consecutive failure, the account locks for 60 seconds and further attempts are blocked until the timer expires |

---

## ▶️ Installation & Usage

### 💻 C++ Console Version

```bash
g++ Auth_System.cpp -o Auth_System
./Auth_System
```

Follow the on-screen menu to **Register**, **Login**, or **Exit**.

### 🌐 Web Demo

No installation needed — try it live:

<div align="center">

<a href="https://ayeshajavid91-star.github.io/Secure-Auth-System/">
  <img src="https://img.shields.io/badge/👉%20OPEN%20VAULT%20PANEL-00D9A5?style=for-the-badge&logoColor=white" />
</a>

</div>

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
│
├── 💻 Auth_System.cpp     # C++ console application
├── 🌐 index.html          # Web demo (Vault Panel)
├── 🎨 style.css            # Vault Panel styling (if separated)
├── ⚙️ script.js            # Login / lockout logic (if separated)
└── 📘 README.md            # You are here
```

---

## 🛡️ Security Notes

> ⚠️ This project is built for **learning and demonstration purposes**. It is not intended as a production-grade auth system.

- 🧂 Passwords use **basic encoding**, not a cryptographic hashing algorithm like bcrypt/Argon2
- 🗄️ The C++ version stores data in **plain external files**, not an encrypted database
- 🌐 The web demo's `localStorage` is **client-side only** and not a substitute for real server-side auth
- ✅ For production use, pair this logic with salted password hashing, HTTPS, and server-side session management

---

## 🗺️ Roadmap

- [x] Registration + login with validation
- [x] 3-attempt / 60-second lockout mechanism
- [x] Web demo with live countdown & LED indicators
- [ ] Password hashing (bcrypt-style) 🔐
- [ ] Two-factor authentication (2FA) 📲
- [ ] Admin dashboard for account management 🛠️
- [ ] Configurable lockout thresholds ⚙️

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

<div align="center">

**Developed by Ayesha Javid**

<a href="mailto:ayeshajavid91@gmail.com">
  <img src="https://img.shields.io/badge/Email-D14836?style=for-the-badge&logo=gmail&logoColor=white" />
</a>
<a href="https://github.com/ayeshajavid91-star">
  <img src="https://img.shields.io/badge/GitHub-100000?style=for-the-badge&logo=github&logoColor=white" />
</a>

</div>

---

## 📄 License

**All Rights Reserved.**

This project and its source code are the intellectual property of the author. No part of this repository — including the code, design, or documentation — may be copied, modified, distributed, used, or reproduced in any form without the explicit written permission of the author.

© 2026 Ayesha Javid. Unauthorized use is strictly prohibited.

For permissions or licensing inquiries, contact: **ayeshajavid91@gmail.com**

---

<div align="center">

<img src="https://capsule-render.vercel.app/api?type=waving&color=gradient&customColorList=2,12,24&height=120&section=footer" width="100%"/>

⭐ *If you like this project, consider giving it a star!* ⭐

</div>
