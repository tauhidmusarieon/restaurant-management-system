#include <bits/stdc++.h>
using namespace std;

void login();
void signup();
void forgot();
void search_tickyet_status();
void runTicketSystem();
bool saveUser(const string &username, const string &password);
bool checkUser(const string &username, string &password);

void login()
{
    cout << "       Login system        " << endl;
    string username1, password1;
    cout << "Enter username: ";
    cin >> username1;
    cout << "Enter password: ";
    cin >> password1;

    string storedPassword;
    if (checkUser(username1, storedPassword) && password1 == storedPassword)
    {
        cout << "Login successful." << endl;
        cout<<"\nAssalam u Alaikum..! "<<username1<<"."<<"\nWhat would you like to order?\n\n";
        cout << endl;
        menu();
    }
    else
    {
        int y;
        cout << "Login unsuccessful." << endl;
        cout << "if you are not signup press '1', or See password, press '3': ";

        cin >> y;
        if (y == 3)
        {
            forgot();
        }
        else if (y == 1)
        {
            signup();
        }
        else
        {
            cout << "Invalid choice.\n"
                 << endl;
        }
        cout << endl;
    }
}

void signup()
{
    cout << "Create username and password " << endl;
    cout << "Enter username : ";
    string username, password;
    cin >> username;
    cout << "Enter password : ";
    cin >> password;

    if (saveUser(username, password))
    {
        cout << "Signup successful. Please login...." << endl;
    }
    else
    {
        cout << "Signup failed. Please try again later." << endl;
    }

    cout << endl;
    login();
}

void forgot()
{
    cout << "Enter the username : ";
    string username2;
    cin >> username2;
    string storedPassword;
    int se_key;
    cout << "Enter the Security Key : ";
    cin >> se_key;

    if (se_key == 1010)
    {
        if (checkUser(username2, storedPassword))
        {
            cout << "Your password is: " << storedPassword << endl;
        }
        else
        {
            cout << "Your username or security key is wrong." << endl;
            cout << "Please contact the Admin panel." << endl;
            cout << "Admin name: Tauhid Musa Rieon" << endl;
            cout << "Email: tauhidmusarieon01@gmail.com" << endl;
            cout << "Thanks." << endl;
            cout << endl;
        }
    }
    else
    {
        cout << "Your username or security key is wrong." << endl;
        cout << "Please contact the Admin panel." << endl;
        cout << "Admin name: Tauhid Musa Rieon" << endl;
        cout << "Email: tauhidmusarieon01@gmail.com" << endl;
        cout << "Thanks." << endl;
        cout << endl;
    }
}
bool saveUser(const string &username, const string &password)
{
    ofstream userFile("users.txt", ios::app);
    ofstream passFile("passwords.txt", ios::app);

    if (!userFile.is_open() || !passFile.is_open())
    {
        cerr << "Error opening file for writing." << endl;
        return false;
    }
    userFile << username << endl;
    passFile << password << endl;

    userFile.close();
    passFile.close();

    return true;
}

bool checkUser(const string &username, string &password)
{
    ifstream userFile("users.txt");
    ifstream passFile("passwords.txt");

    if (!userFile.is_open() || !passFile.is_open())
    {
        cerr << "Error opening file for reading." << endl;
        return false;
    }

    string line;
    while (getline(userFile, line))
    {
        if (line == username)
        {
            if (getline(passFile, password))
            {
                userFile.close();
                passFile.close();
                return true;
            }
        }
        else
        {
            getline(passFile, line);
        }
    }
    userFile.close();
    passFile.close();
    return false;
}

int main()
{

    unordered_map<string, string> ump;

    ump["Rieon"] = "1032";
    ump["Abir"] = "1026";
    ump["Sazzad"] = "1005";
    ump["Aronno"] = "1001";
    ump["username"] = "1234";

    int n, payment;
    cout << "\t\tWelcome to the resturent : " << endl;
    cout << "1. Sign up\n2. Login\n3. Exit\nEnter your option : ";
    cin >> n;

    switch (n)
    {
    case 1:
        signup();
        break;
    case 2:
        login();
        break;
    case 3:
        cout << "Exiting the program. thanks!" << endl;
        return 0;
    default:
        cout << "Invalid option. Please choose a valid option." << endl;
    }

    return 0;
}
