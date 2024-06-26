#include <bits/stdc++.h>
using namespace std;

int main()
{

    unordered_map<string, string> ump;

    ump["Rieon"] = "1032";
    ump["Abir"] = "1026";
    ump["Sazzad"] = "1005";
    ump["Aronno"] = "1001";
    ump["username"] = "1234";

    while(true)
    {
        string option;
        cout << "1. Login\n2. Exit\nEnter Option : ";
        cin >> option ;

        if(option == "1")
        {
            string username, password;
            cout << "Enter Username : ";
            cin >> username ;
            cout << "Enter Password : ";
            cin >> password ;

            if(ump.find(username) != ump.end() && ump[username]==password)
            {
                cout << "Login successful" << endl;
            }
            else{
                cout << "Invalid Username or Password" << endl;
            }
        }
        else if(option=="2")
        {
            cout << "Exiting..." << endl;
            return 0;
        }
        else
        {
            cout << "Invalid option, please try again" << endl;

        }
    }



    return 0;
}
