#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Registration Function
void registerUser()
{
    string username, password;
    string fileUser, filePass;
    bool exists = false;

    cout << "\n===== USER REGISTRATION =====\n";

    cout << "Enter Username: ";
    cin >> username;

    cout << "Enter Password: ";
    cin >> password;

    ifstream readFile("users.txt");

    while (readFile >> fileUser >> filePass)
    {
        if (fileUser == username)
        {
            exists = true;
            break;
        }
    }

    readFile.close();

    if (exists)
    {
        cout << "Username already exists! Try another username.\n";
        return;
    }

    ofstream writeFile("users.txt", ios::app);
    writeFile << username << " " << password << endl;
    writeFile.close();

    cout << "Registration Successful!\n";
}

// Login Function
void loginUser()
{
    string username, password;
    string fileUser, filePass;
    bool found = false;

    cout << "\n===== USER LOGIN =====\n";

    cout << "Enter Username: ";
    cin >> username;

    cout << "Enter Password: ";
    cin >> password;

    ifstream readFile("users.txt");

    while (readFile >> fileUser >> filePass)
    {
        if (fileUser == username && filePass == password)
        {
            found = true;
            break;
        }
    }

    readFile.close();

    if (found)
    {
        cout << "Login Successful! Welcome " << username << endl;
    }
    else
    {
        cout << "Invalid Username or Password!\n";
    }
}

int main()
{
    int choice;

    do
    {
        cout << "\n=================================\n";
        cout << " LOGIN & REGISTRATION SYSTEM\n";
        cout << "=================================\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            registerUser();
            break;

        case 2:
            loginUser();
            break;

        case 3:
            cout << "Thank You!\n";
            break;

        default:
            cout << "Invalid Choice!\n";
        }

    } while (choice != 3);

    return 0;
}
