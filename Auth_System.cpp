/*
    InternGrow C++ Programming Track
    TASK 2: Secure User Authentication System (WITH UPGRADE FEATURE)
    --------------------------------------------------------------------
    Basic Feature:
        - User Registration (Sign Up) with duplicate username check
        - User Login (validation against stored credentials)
        - Credentials securely stored in an external file (users.txt)

    Upgrade Feature:
        - Lockout Mechanism: 3 consecutive wrong password attempts
          se account temporarily lock ho jata hai for a fixed duration.
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <ctime>
using namespace std;

const char* USER_FILE = "users.txt";
const char* LOCKOUT_FILE = "lockout.txt";
const int MAX_ATTEMPTS = 3;
const int LOCKOUT_DURATION = 60; // seconds (demo ke liye 60 sec, aap 300/600 bhi rakh sakte hain)

// ---------- Struct: Lockout info track karne ke liye ----------
struct LockoutInfo {
    int failedAttempts;
    time_t lockoutUntil; // 0 matlab lock nahi hai
};

// ---------- Simple obfuscation (basic security) ----------
// Password ko plain text ke bajaye thora shift kar ke store karta hai
string encodePassword(string pass) {
    for (size_t i = 0; i < pass.size(); i++) {
        pass[i] = pass[i] + 3; // Caesar-cipher jaisa simple shift
    }
    return pass;
}
string decodePassword(string pass) {
    for (size_t i = 0; i < pass.size(); i++) {
        pass[i] = pass[i] - 3;
    }
    return pass;
}

// ---------- Check karna ke username pehle se maujood hai ----------
bool usernameExists(const string &username) {
    ifstream file(USER_FILE);
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string storedUser;
        getline(ss, storedUser, ',');
        if (storedUser == username) {
            file.close();
            return true;
        }
    }
    file.close();
    return false;
}

// ---------- Naya user register karna ----------
void registerUser() {
    string username, password;

    cout << "\n===== Register New User =====\n";
    cout << "Username enter karo: ";
    cin >> username;

    if (username.empty()) {
        cout << "Username khali nahi ho sakta!\n";
        return;
    }

    if (usernameExists(username)) {
        cout << "Ye username pehle se maujood hai! Doosra choose karo.\n";
        return;
    }

    cout << "Password enter karo (min 6 characters): ";
    cin >> password;

    if (password.length() < 6) {
        cout << "Password kam se kam 6 characters ka hona chahiye!\n";
        return;
    }

    // File mein append mode se save karna: username,encodedPassword
    ofstream file(USER_FILE, ios::app);
    file << username << "," << encodePassword(password) << "\n";
    file.close();

    cout << "✅ Registration Successful! Ab aap login kar sakte hain.\n";
}

// ---------- Lockout data ko file se load karna ----------
map<string, LockoutInfo> loadLockoutData() {
    map<string, LockoutInfo> data;
    ifstream file(LOCKOUT_FILE);
    string username;
    int attempts;
    long lockUntil;

    while (file >> username >> attempts >> lockUntil) {
        data[username] = {attempts, (time_t)lockUntil};
    }
    file.close();
    return data;
}

// ---------- Lockout data ko file mein save karna ----------
void saveLockoutData(map<string, LockoutInfo> &data) {
    ofstream file(LOCKOUT_FILE);
    for (map<string, LockoutInfo>::iterator it = data.begin(); it != data.end(); ++it) {
        file << it->first << " " << it->second.failedAttempts
             << " " << (long)it->second.lockoutUntil << "\n";
    }
    file.close();
}

// ---------- User login karna (lockout logic ke saath) ----------
void loginUser() {
    string username, password;

    cout << "\n===== User Login =====\n";
    cout << "Username enter karo: ";
    cin >> username;

    map<string, LockoutInfo> lockoutData = loadLockoutData();
    time_t now = time(0);

    // ----- STEP 1: Check karo account lock to nahi hai -----
    if (lockoutData.find(username) != lockoutData.end()) {
        LockoutInfo &info = lockoutData[username];

        if (info.lockoutUntil > now) {
            int remaining = (int)(info.lockoutUntil - now);
            cout << "🔒 Account lock hai! " << remaining
                 << " seconds baad dobara try karein.\n";
            return;
        }
        else if (info.lockoutUntil != 0 && info.lockoutUntil <= now) {
            // Lockout time khatam ho chuka, attempts reset karo
            info.failedAttempts = 0;
            info.lockoutUntil = 0;
        }
    }

    // ----- STEP 2: Username file mein exist karta hai ya nahi -----
    if (!usernameExists(username)) {
        cout << "❌ Ye username registered nahi hai.\n";
        return;
    }

    cout << "Password enter karo: ";
    cin >> password;

    // ----- STEP 3: Credentials verify karna -----
    ifstream file(USER_FILE);
    string line;
    bool matched = false;

    while (getline(file, line)) {
        stringstream ss(line);
        string storedUser, storedPass;
        getline(ss, storedUser, ',');
        getline(ss, storedPass, ',');

        if (storedUser == username && decodePassword(storedPass) == password) {
            matched = true;
            break;
        }
    }
    file.close();

    if (matched) {
        cout << "✅ Login Successful! Welcome, " << username << ".\n";
        // Successful login par attempts reset ho jate hain
        lockoutData[username] = {0, 0};
        saveLockoutData(lockoutData);
    }
    else {
        // ----- STEP 4: Galat password -> failed attempt count badhana -----
        LockoutInfo &info = lockoutData[username];
        info.failedAttempts++;

        cout << "❌ Galat password! Attempt " << info.failedAttempts
             << " of " << MAX_ATTEMPTS << ".\n";

        if (info.failedAttempts >= MAX_ATTEMPTS) {
            info.lockoutUntil = now + LOCKOUT_DURATION;
            cout << "🔒 3 consecutive galat attempts ho gaye! Account "
                 << LOCKOUT_DURATION << " seconds ke liye lock kar diya gaya hai.\n";
        }

        saveLockoutData(lockoutData);
    }
}

// ---------- MAIN MENU ----------
int main() {
    int choice;

    do {
        cout << "\n========== Secure User Authentication System ==========\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Apna choice enter karo: ";
        cin >> choice;

        // Agar invalid (non-numeric) input aaye to cin ko reset karna
        // taake infinite loop na bane
        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input! Sirf number (1-3) enter karein.\n";
            continue;
        }

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                cout << "Program band ho raha hai. Shukriya!\n";
                break;
            default:
                cout << "Invalid choice! Dobara try karein.\n";
        }

    } while (choice != 3);

    return 0;
}
