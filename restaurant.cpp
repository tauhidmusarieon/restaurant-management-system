#include <bits/stdc++.h>
using namespace std;

void login();
void signup();
void forgot();
void search_tickyet_status();
void runTicketSystem();
string username, username1, username2, password, password1;
void login()
{
    cout << "       Login system        " << endl;
    cout << "Enter username: ";
    cin >> username1;
    cout << "Enter password: ";
    cin >> password1;

    if (username == username1 && password == password1)
    {
        cout << "Login successful." << endl;
        cout << endl;
        //runTicketSystem();
    }
    else
    {
        int y;
        cout << "Login unsuccessful." << endl;
        cout << "if you are not signup press '1', or forgot password, press '3': ";

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
    cin >> username;
    cout << "Enter password : ";
    cin >> password;
    cout << endl;
    login();
}

void forgot()
{
    cout << "Enter the username : ";
    cin >> username2;
    if (username == username2)
    {
        signup();
    }
    else
    {
        cout << "Your username is wrong." << endl;
        cout << "Please contact the Admin panel." << endl;
        cout << "Admin name: Tauhid Musa Rieon" << endl;
        cout << "Email: tauhidmusarieon01@gmail.com" << endl;
        cout << "Thanks." << endl;
        cout << endl;
    }
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
