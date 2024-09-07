#include <bits/stdc++.h>
#include <conio.h>

using namespace std;

struct U {
    string usr;
    string pwd;
    string email;
    double bal;
};

unordered_map<string, U> uMap;

void saveU() {
    ofstream outFile("users.txt");
    if (!outFile) {
        cerr << "Error opening file for writing.\n";
        return;
    }
    for (const auto &entry : uMap) {
        const U &u = entry.second;
        outFile << u.usr << ' ' << u.pwd << ' ' << u.email << ' ' << u.bal << "\n";
    }
    outFile.close();
}

void loadU() {
    ifstream inFile("users.txt");
    if (!inFile) return;

    U u;
    while (inFile >> u.usr >> u.pwd >> u.email >> u.bal) {
        uMap[u.usr] = u;
    }
    inFile.close();
}

int getIntInput() {
    int ch;
    while (true) {
        cin >> ch;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Enter a number: ";
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return ch;
        }
    }
}

double getDblInput() {
    double amt;
    while (true) {
        cin >> amt;
        if (cin.fail() || amt <= 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Enter a positive number: ";
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return amt;
        }
    }
}

void showItems(const unordered_map<string, double> &items) {
    int idx = 1;
    for (const auto &item : items) {
        cout << idx++ << ". " << item.first << " - BDT " << item.second << "\n";
    }
}

bool userExists(const string &usr) {
    return uMap.find(usr) != uMap.end();
}

void signUp() {
    string usr, pwd, email;
    cout << "Enter a username: ";
    cin >> usr;

    if (userExists(usr)) {
        cout << "User already exists!\n";
        return;
    }

    cout << "Enter a password: ";
    char ch;
    pwd = "";
    ch = _getch();
    while (ch != 13) {
        pwd.push_back(ch);
        cout << '*';
        ch = _getch();
    }
    cout << "\n";

    cout << "Enter email address: ";
    cin >> email;

    U newU = {usr, pwd, email, 0.0};
    uMap[usr] = newU;

    ofstream outFile("users.txt", ios::app);
    if (!outFile) {
        cerr << "Error opening file for writing.\n";
        return;
    }
    outFile << usr << " " << pwd << " " << email << " " << 0.0 << "\n";
    outFile.close();

    cout << "Sign up successful!\n";
}

void resetPwd() {
    string usr, email, newPwd;
    cout << "Enter username: ";
    cin >> usr;
    if (uMap.find(usr) == uMap.end()) {
        cout << "Username not found.\n";
        return;
    }
    cout << "Enter email: ";
    cin >> email;
    if (uMap[usr].email != email) {
        cout << "Email doesn't match.\n";
        return;
    }

    string gMailCode;
    cout << "Enter Gmail code: ";
    cin >> gMailCode;

    cout << "Enter new password: ";
    char ch;
    newPwd = "";
    ch = _getch();
    while (ch != 13) {
        if (ch == '\b') {
            if (newPwd.length() > 0) {
                newPwd.pop_back();
                cout << "\b \b";
            }
        } else {
            newPwd.push_back(ch);
            cout << '*';
        }
        ch = _getch();
    }
    cout << "\n";

    uMap[usr].pwd = newPwd;
    saveU();
    cout << "Password reset successfully.\n";
}

bool logIn(U &u) {
    const int maxAttempts = 5;
    int attempts = 0;
    while (attempts < maxAttempts) {
        cout << "Enter username: ";
        cin >> u.usr;
        cout << "Enter password: ";
        string pwd;
        char ch;
        while ((ch = _getch()) != '\r') {
            if (ch == '\b') {
                if (pwd.length() > 0) {
                    pwd.pop_back();
                    cout << "\b \b";
                }
            } else {
                pwd += ch;
                cout << '*';
            }
        }
        cout << "\n";
        if (uMap.find(u.usr) != uMap.end() && uMap[u.usr].pwd == pwd) {
            u = uMap[u.usr];
            return true;
        }
        cout << "Invalid username or password. Try again.\n";
        attempts++;
    }
    cout << "\nToo many failed attempts.\n";
    cout << "Your username or password is wrong.\n";
    cout << "Please contact the Admin panel. If you are right.\n";
    cout << "Admin name: Tauhid Musa Rieon\n";
    cout << "Email: tauhidmusarieon01@gmail.com\n";
    cout << "Thanks. Exiting program.\n";
    exit(0);
}

void order(U &u) {
    unordered_map<string, double> menu;
    int catChoice;

    cout << "1. BIRYANI & KHICHURI\n";
    cout << "2. PIZZA\n";
    cout << "3. BURGER\n";
    cout << "4. SNACKS\n";
    cout << "5. DRINKS\n";
    cout << "Enter choice (1-5): ";
    catChoice = getIntInput();

    switch (catChoice) {
        case 1: menu = {
            {"Beef Khichuri", 120.0},
            {"Egg Khichuri", 50.0},
            {"Chicken Khichuri", 90.0},
            {"Beef Biryani", 185.0},
            {"Chicken Biryani", 150.0}
        }; break;
        case 2: menu = {
            {"Chicken Pizza Big", 350.0},
            {"Chicken Pizza Small", 250.0},
            {"Beef Pizza Big", 500.0},
            {"Beef Pizza Small", 350.0},
            {"Veg Pizza Big", 300.0},
            {"Veg Pizza Small", 200.0}
        }; break;
        case 3: menu = {
            {"Chicken Burger", 100.0},
            {"Beef Burger", 130.0}
        }; break;
        case 4: menu = {
            {"Fries", 100.0},
            {"Chicken Jhal Fry", 150.0},
            {"Egg Noodles", 50.0},
            {"Beef Noodles", 150.0}
        }; break;
        case 5: menu = {
            {"Lachi", 50.0},
            {"Faluda", 80.0},
            {"Cold Coffee", 60.0},
            {"Hot Coffee", 50.0},
            {"Mango Juice", 60.0}
        }; break;
        default: cout << "Invalid choice!\n"; return;
    }

    showItems(menu);

    double total = 0.0;
    int itemChoice, qty;

    while (true) {
        cout << "Enter item number (0 to finish): ";
        itemChoice = getIntInput();

        if (itemChoice == 0) break;

        if (itemChoice < 1 || itemChoice > menu.size()) {
            cout << "Invalid item choice. Try again.\n";
            continue;
        }

        cout << "Enter quantity: ";
        qty = getIntInput();

        auto it = next(menu.begin(), itemChoice - 1);
        total += it->second * qty;

        cout << "Added " << it->first << " x " << qty << " to order.\n";
    }

    if (total > 0) {
        cout << "Total: BDT " << total << "\n";

        if (u.bal >= total) {
            u.bal -= total;
            cout << "Order placed successfully!\n";
            cout << "Remaining balance: BDT " << u.bal << "\n";
            uMap[u.usr].bal = u.bal;
            saveU();
        } else {
            cout << "Insufficient balance.\n";
        }
    } else {
        cout << "No items ordered.\n";
    }
}

void mainMenu(U &usr) {
    int choice;
    do {
        cout << "\n1. Show Menu List\n";
        cout << "2. Order Food\n";
        cout << "3. Check Balance\n";
        cout << "4. Add Balance\n";
        cout << "5. Log Out\n";
        cout << "Enter your choice: ";
        choice = getIntInput();

        switch (choice) {
            case 1:
                cout << "\t\t\tMenu List:\n\n";
                cout << "\t\tBIRYANI & KHICHURI\n";
                showItems({
                    {"\t\tBeef Khichuri", 120.0},
                    {"\t\tEgg Khichuri", 50.0},
                    {"\t\tChicken Khichuri", 90.0},
                    {"\t\tBeef Biryani", 185.0},
                    {"\t\tChicken Biryani", 150.0}
                });
                cout << "\n\n\t\tPIZZA\n";
                showItems({
                    {"\t\tChicken Pizza Big", 350.0},
                    {"\t\tChicken Pizza Small", 250.0},
                    {"\t\tBeef Pizza Big", 500.0},
                    {"\t\tBeef Pizza Small", 350.0},
                    {"\t\tVegetable Pizza Big", 300.0},
                    {"\t\tVegetable Pizza Small", 200.0}
                });
                cout << "\n\n\t\tBURGER\n";
                showItems({
                    {"\t\tChicken Burger", 100.0},
                    {"\t\tBeef Burger", 130.0}
                });
                cout << "\n\n\t\tSNACKS\n";
                showItems({
                    {"\t\tFrance Fry", 100.0},
                    {"\t\tChicken Jhal Fry", 150.0},
                    {"\t\tEgg Noodles", 50.0},
                    {"\t\tBeef Noodles", 150.0}
                });
                cout << "\n\n\t\tDRINKS AND BEVERAGE\n";
                showItems({
                    {"\t\tLachi", 50.0},
                    {"\t\tFaluda", 80.0},
                    {"\t\tCold Coffee Cream", 60.0},
                    {"\t\tCold Coffee Chocolate", 70.0},
                    {"\t\tHot Coffee", 50.0},
                    {"\t\tMango Juice", 60.0},
                    {"\t\tOrange Juice", 50.0},
                    {"\t\tBanana Juice", 50.0},
                    {"\t\tLemon Juice", 50.0},
                    {"\t\tMojo", 35.0}
                });
                break;
            case 2:
                order(usr);
                break;
            case 3:
                cout << "Your current balance is: BDT " << usr.bal << "\n";
                break;
            case 4: {
                cout << "Enter the amount to add to your balance: ";
                double amt = getDblInput();
                usr.bal += amt;
                uMap[usr.usr].bal = usr.bal;
                saveU();
                cout << "Balance added successfully! Current balance: BDT " << usr.bal << "\n";
            } break;
            case 5:
                cout << "Logging out...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 5);
}


int main() {
    loadU();

    int choice;
    U loggedU;

    while (true) {
        cout << "1. Log In\n";
        cout << "2. Sign Up\n";
        cout << "3. Reset Password\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        choice = getIntInput();

        switch (choice) {
            case 1:
                if (logIn(loggedU)) {
                    cout << "Login successful!\n";
                    mainMenu(loggedU);
                }
                break;
            case 2: signUp(); break;
            case 3: resetPwd(); break;
            case 4: cout << "Exiting...\n"; return 0;
            default: cout << "Invalid choice!\n";
        }
    }
}
