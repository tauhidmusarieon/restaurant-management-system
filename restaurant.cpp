#include <bits/stdc++.h>
using namespace std;

void login();
void signup();
void forgot();
void menu();
void burger();
void payBill();
void addBalance();
bool saveUser(const string &username, const string &password);
bool checkUser(const string &username, string &password);
int bill = 0;
int mainBalance = 100;
void payBill()
{
    int pay_amt;
    cout << "\nYour current bill is : " << bill << endl;
    cout << "Enter the amount : ";
    cin >> pay_amt;
    if (mainBalance >= bill)
    {
        if(pay_amt >= bill)
        {
            cout << "Payment Successfull.\nEnjoy your time" << endl;
            mainBalance-= bill;
            cout << "Your current Balance is : " << mainBalance << endl;
        }
        else
        {
            cout << "Your bill is more than your paid amount ." << endl;
            payBill();
        }
    }
    else
    {
        cout << "Insufficient Balance. Purchase unsuccessful." << endl;
        cout << "Please add : " << bill-mainBalance << " TK" << endl;
        cout << "if you want to 'Add Money' to your account Press 1 or 'Menu' for 0 : ";
        bill = 0;

        int b;
        cin >> b;
        if (b==1)
        {
            addBalance();
        }
        else if (b==0)
        {
            menu();
        }
    }
}
void addBalance()
{
        int add;
        cout << "Enter the amount you want to add : ";
        cin >> add;
        mainBalance+=add;
        cout << "money added successfull." << endl;
        cout << "Your current balance is = " << mainBalance << endl <<endl;
        menu();
}


void burger()
{
        cout<<"\t\t\t\t\t    *------BURGER------*"<<endl;
		cout<<"\t\t\t\tPress '1' Zinger Burger......................TK:299"<<endl;
		cout<<"\t\t\t\tPress '2' Zinger Burger with Cheese..........TK:349"<<endl;
		cout<<"\t\t\t\tPress '3' Chicken Burger.....................TK:220"<<endl;
		cout<<"\t\t\t\tPress '4' Chicken Burger with Cheese.........TK:280"<<endl;
		cout<<"\t\t\t\tPress '5' Tower Burger.......................TK:380"<<endl;
		cout<<"Please select option : ";
		int n; cin >> n;
		if(n==1)
        {
            cout<<"How much quantity do you want : ";
            int a;
            cin >> a ;
            cout<<"You Entered "<< a <<" Zinger burger "<<endl << endl;
            bill+=299*a;
            cout<<"The current bill is: "<< bill <<endl;
            cout<<"If you want to go back to 'Burger' Press '0'\nGoto 'Menu' Press '1'\nGoto 'Pay Bill' press '2'" << endl;
            cout<<"Please select option : ";
            cin >> a ;
            if (a==0)
            {
                burger();
            }
            else if (a==1)
            {
                menu();
            }
            else if (a==2)
            {
                payBill();
            }
        }
        else if (n==2)
        {
            cout<<"How much quantity do you want : ";
            int a;
            cin >> a ;
            cout<<"You Entered "<< a <<" Zinger Burger with Cheese "<<endl << endl;
            bill+=349*a;
            cout<<"The current bill is: "<< bill <<endl;
            cout<<"If you want to go back to 'Burger' Press '0'\nGoto 'Menu' Press '1'\nGoto 'Pay Bill' press '2'" << endl;
            cout<<"Please select option : ";
            cin >> a ;
            if (a==0)
            {
                burger();
            }
            else if (a==1)
            {
                menu();
            }
            else if (a==2)
            {
                payBill();
            }
        }
        else if (n==3)
        {
            cout<<"How much quantity do you want : ";
            int a;
            cin >> a ;
            cout<<"You Entered "<< a <<" Chicken Burger "<<endl << endl;
            bill+=220*a;
            cout<<"The current bill is: "<< bill <<endl;
            cout<<"If you want to go back to 'Burger' Press '0'\nGoto 'Menu' Press '1'\nGoto 'Pay Bill' press '2'" << endl;
            cout<<"Please select option : ";
            cin >> a ;
            if (a==0)
            {
                burger();
            }
            else if (a==1)
            {
                menu();
            }
            else if (a==2)
            {
                payBill();
            }
        }
        else if (n==4)
        {
            cout<<"How much quantity do you want : ";
            int a;
            cin >> a ;
            cout<<"You Entered "<< a <<" Chicken Burger with Cheese"<<endl << endl;
            bill+=280*a;
            cout<<"The current bill is: "<< bill <<endl;
            cout<<"If you want to go back to 'Burger' Press '0'\nGoto 'Menu' Press '1'\nGoto 'Pay Bill' press '2'" << endl;
            cout<<"Please select option : ";
            cin >> a ;
            if (a==0)
            {
                burger();
            }
            else if (a==1)
            {
                menu();
            }
            else if (a==2)
            {
                payBill();
            }
        }
        else if (n==5)
        {
            cout<<"How much quantity do you want : ";
            int a;
            cin >> a ;
            cout<<"You Entered "<< a <<" Tower Burger"<<endl << endl;
            bill+=380*a;
            cout<<"The current bill is: "<< bill <<endl;
            cout<<"If you want to go back to 'Burger' Press '0'\nGoto 'Menu' Press '1'\nGoto 'Pay Bill' press '2'" << endl;
            cout<<"Please select option : ";
            cin >> a ;
            if (a==0)
            {
                burger();
            }
            else if (a==1)
            {
                menu();
            }
            else if (a==2)
            {
                payBill();
            }
        }
        else
        {
            cout << "Invalid choice.\n";
            burger();

        }

}

void menu()
{
    cout <<"\t\t\t\t*------Menu------*" << endl ;
    cout<<"\t\t\t\tPress '1' BURGER"<<endl;
	cout<<"\t\t\t\tPress '2' PARATHA ROLLS"<<endl;
	cout<<"\t\t\t\tPress '3' SHAWARMA"<<endl;
	cout<<"\t\t\t\tPress '4' BIRYANI"<<endl;
	cout<<"\t\t\t\tPress '5' PIZZA"<<endl;
	cout<<"\t\t\t\tPress '6' SALAD"<<endl;
	cout<<"\t\t\t\tPress '7' COLD DRINKS" << endl ;
	cout<<"Please select option : ";
	int ms ;
	cin >> ms;
	if (ms == 1)
    {
        burger();
    }
}


void login()
{
    cout << "\t\t\t\t\tLogin system        " << endl;
    string username1, password1;
    cout << "Enter username: ";
    cin >> username1;
    cout << "Enter password: ";
    cin >> password1;

    string storedPassword;
    if (checkUser(username1, storedPassword) && password1 == storedPassword)
    {
        cout << "Login successful." << endl;
        cout<<"\nAssalam u Alaikum..! "<<username1<<"."<<"\nWhat would you like to order?\n";
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
