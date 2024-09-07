#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>
#include <limits>
#include <conio.h>
#include <cstdlib>

using namespace std;

struct User {
    string username;
    string password;
    string email;
    double balance;
};

unordered_map<string, User> users;

void saveUsers() {
    ofstream outFile("users.txt");
    if (!outFile) {
        cerr << "Error opening file for writing.\n";
        return;
    }
    for (const auto &entry : users) {
        const User &user = entry.second;
        outFile << user.username << ' ' << user.password << ' ' << user.email << ' ' << user.balance << "\n";
    }
    outFile.close();
}

void loadUsers() {
    ifstream inFile("users.txt");
    if (!inFile) return;

    User user;
    while (inFile >> user.username >> user.password >> user.email >> user.balance) {
        users[user.username] = user;
    }
    inFile.close();
}

int getValidIntInput() {
    int choice;
    while (true) {
        cin >> choice;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number: ";
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return choice;
        }
    }
}

double getValidDoubleInput() {
    double amount;
    while (true) {
        cin >> amount;
        if (cin.fail() || amount <= 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a positive number: ";
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return amount;
        }
    }
}

void displayCategoryItems(const unordered_map<string, double> &items) {
    int index = 1;
    for (const auto &item : items) {
        cout << index++ << ". " << item.first << " - BDT " << item.second << "\n";
    }
}

bool userExists(const string &username) {
    return users.find(username) != users.end();
}

void signUp() {
    string username, password, email;
    cout << "Enter a username: ";
    cin >> username;

    if (userExists(username)) {
        cout << "User already exists!\n";
        return;
    }

    cout << "Enter a password: ";
    char ch;
    password = "";
    ch = _getch();
    while (ch != 13) {
        password.push_back(ch);
        cout << '*';
        ch = _getch();
    }
    cout << "\n";

    cout << "Enter your email address: ";
    cin >> email;

    User newUser = {username, password, email, 0.0};
    users[username] = newUser;

    ofstream outFile("users.txt", ios::app);
    if (!outFile) {
        cerr << "Error opening file for writing.\n";
        return;
    }
    outFile << username << " " << password << " " << email << " " << 0.0 << "\n";
    outFile.close();

    cout << "Sign up successful!\n";
}

void resetPassword() {
    string username, email, newPassword;
    cout << "Enter username: ";
    cin >> username;
    if (users.find(username) == users.end()) {
        cout << "Username not found.\n";
        return;
    }
    cout << "Enter email address: ";
    cin >> email;
    if (users[username].email != email) {
        cout << "Email address does not match.\n";
        return;
    }

    string gMailCode;
    cout << "Enter the G-mail code: ";
    cin >> gMailCode;

    cout << "Enter new password: ";
    char ch;
    newPassword = "";
    ch = _getch();
    while (ch != 13) {
        if (ch == '\b') {
            if (newPassword.length() > 0) {
                newPassword.pop_back();
                cout << "\b \b";
            }
        } else {
            newPassword.push_back(ch);
            cout << '*';
        }
        ch = _getch();
    }
    cout << "\n";

    users[username].password = newPassword;
    saveUsers();
    cout << "Password reset successfully.\n";
}

bool logIn(User &user) {
    const int maxAttempts = 5;
    int attempts = 0;
    while (attempts < maxAttempts) {
        cout << "Enter username: ";
        cin >> user.username;
        cout << "Enter password: ";
        string password;
        char ch;
        while ((ch = _getch()) != '\r') {
            if (ch == '\b') {
                if (password.length() > 0) {
                    password.pop_back();
                    cout << "\b \b";
                }
            } else {
                password += ch;
                cout << '*';
            }
        }
        cout << "\n";
        if (users.find(user.username) != users.end() && users[user.username].password == password) {
            user = users[user.username];
            return true;
        }
        cout << "\nInvalid username or password. Try again.\n";
        attempts++;
    }
    cout << "\nToo many failed attempts.\n";
    cout << "Your username or password is wrong.\n";
    cout << "Please contact the Admin panel. If you are right.\n";
    cout << "Admin name: Tauhid Musa Rieon\n";
    cout << "Email: tauhidmusarieon01@gmail.com\n";
    cout << "Thanks. Exiting program.\n";
    exit(1);
}

void orderFood(User &user) {
    unordered_map<string, double> selectedMenu;
    int categoryChoice;

    cout << "1. BIRYANI & KHICHURI\n";
    cout << "2. PIZZA\n";
    cout << "3. BURGER\n";
    cout << "4. SNACKS\n";
    cout << "5. DRINKS AND BEVERAGE\n";
    cout << "Enter your choice (1-5): ";
    categoryChoice = getValidIntInput();

    switch (categoryChoice) {
        case 1: selectedMenu = {
            {"Beef Khichuri", 120.0},
            {"Egg Khichuri", 50.0},
            {"Chicken Khichuri", 90.0},
            {"Beef Biryani", 185.0},
            {"Chicken Biryani", 150.0}
        }; break;
        case 2: selectedMenu = {
            {"Chicken Pizza Big", 350.0},
            {"Chicken Pizza Small", 250.0},
            {"Beef Pizza Big", 500.0},
            {"Beef Pizza Small", 350.0},
            {"Vegetable Pizza Big", 300.0},
            {"Vegetable Pizza Small", 200.0}
        }; break;
        case 3: selectedMenu = {
            {"Chicken Burger", 100.0},
            {"Beef Burger", 130.0}
        }; break;
        case 4: selectedMenu = {
            {"France Fry", 100.0},
            {"Chicken Jhal Fry", 150.0},
            {"Egg Noodles", 50.0},
            {"Beef Noodles", 150.0}
        }; break;
        case 5: selectedMenu = {
            {"Lachi", 50.0},
            {"Faluda", 80.0},
            {"Cold Coffee Cream", 60.0},
            {"Cold Coffee Chocolate", 70.0},
            {"Hot Coffee", 50.0},
            {"Mango Juice", 60.0},
            {"Orange Juice", 50.0},
            {"Banana Juice", 50.0},
            {"Lemon Juice", 50.0},
            {"Mojo", 35.0}
        }; break;
        default: cout << "Invalid choice!\n"; return;
    }

    displayCategoryItems(selectedMenu);

    double total = 0.0;
    int itemChoice, quantity;

    while (true) {
        cout << "Enter the item number to order (0 to finish): ";
        itemChoice = getValidIntInput();

        if (itemChoice == 0) break;

        if (itemChoice < 1 || itemChoice > selectedMenu.size()) {
            cout << "Invalid item choice. Try again.\n";
            continue;
        }

        cout << "Enter quantity: ";
        quantity = getValidIntInput();

        auto it = next(selectedMenu.begin(), itemChoice - 1);
        total += it->second * quantity;

        cout << "Added " << it->first << " x " << quantity << " to your order.\n";
    }

    if (total > 0) {
        cout << "Total cost: BDT " << total << "\n";

        if (user.balance >= total) {
            user.balance -= total;
            cout << "Order placed successfully!\n";
            cout << "Remaining balance: BDT " << user.balance << "\n";
            users[user.username].balance = user.balance;
            saveUsers();
        } else {
            cout << "Insufficient balance. Please recharge your account.\n";
        }
    } else {
        cout << "No items ordered.\n";
    }
}

void mainMenu(User &user) {
    int choice;
    do {
        cout << "\n1. Show Menu List\n";
        cout << "2. Order Food\n";
        cout << "3. Check Balance\n";
        cout << "4. Add Balance\n";
        cout << "5. Log Out\n";
        cout << "Enter your choice: ";
        choice = getValidIntInput();

        switch (choice) {
            case 1:
                cout << "\t\t\tMenu List:\n\n";
                cout << "\t\tBIRYANI & KHICHURI\n";
                displayCategoryItems({
                    {"\t\tBeef Khichuri", 120.0},
                    {"\t\tEgg Khichuri", 50.0},
                    {"\t\tChicken Khichuri", 90.0},
                    {"\t\tBeef Biryani", 185.0},
                    {"\t\tChicken Biryani", 150.0}
                });
                cout << "\n\n\t\tPIZZA\n";
                displayCategoryItems({
                    {"\t\tChicken Pizza Big", 350.0},
                    {"\t\tChicken Pizza Small", 250.0},
                    {"\t\tBeef Pizza Big", 500.0},
                    {"\t\tBeef Pizza Small", 350.0},
                    {"\t\tVegetable Pizza Big", 300.0},
                    {"\t\tVegetable Pizza Small", 200.0}
                });
                cout << "\n\n\t\tBURGER\n";
                displayCategoryItems({
                    {"\t\tChicken Burger", 100.0},
                    {"\t\tBeef Burger", 130.0}
                });
                cout << "\n\n\t\tSNACKS\n";
                displayCategoryItems({
                    {"\t\tFrance Fry", 100.0},
                    {"\t\tChicken Jhal Fry", 150.0},
                    {"\t\tEgg Noodles", 50.0},
                    {"\t\tBeef Noodles", 150.0}
                });
                cout << "\n\n\t\tDRINKS AND BEVERAGE\n";
                displayCategoryItems({
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
                orderFood(user);
                break;
            case 3:
                cout << "Your current balance is: BDT " << user.balance << "\n";
                break;
            case 4: {
                cout << "Enter the amount to add to your balance: ";
                double amount = getValidDoubleInput();
                user.balance += amount;
                users[user.username].balance = user.balance;
                saveUsers();
                cout << "Balance added successfully! Current balance: BDT " << user.balance << "\n";
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
    loadUsers();

    int choice;
    User loggedInUser;

    while (true) {
        cout << "1. Log In\n";
        cout << "2. Sign Up\n";
        cout << "3. Reset Password\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        choice = getValidIntInput();

        switch (choice) {
            case 1:
                if (logIn(loggedInUser)) {
                    cout << "Login successful!\n";
                    mainMenu(loggedInUser);
                }
                break;
            case 2: signUp(); break;
            case 3: resetPassword(); break;
            case 4: cout << "Exiting the program.\n"; return 0; break;
            default: cout << "Invalid choice!\n";
        }
    }
    return 0 ;
}
