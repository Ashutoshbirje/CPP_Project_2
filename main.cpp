#include <bits/stdc++.h>
#include "Menu.cpp"
#include "password.cpp"
#include <regex>
using namespace std;
class Customer
{
private:
  string name, phone, email, address;
  int age;

public:
  int ID = 0;
  void set()
  {
    try
    {
      cin.ignore();
      cout << "Enter your name        : ";
      getline(cin, name);
      if (!regex_match(name, regex("^[A-Za-z ]+$")))
      {
        throw runtime_error("Invalid Name: Only alphabets value allowed.");
      }

      string ageStr;
      cout << "Enter your age         : ";
      getline(cin, ageStr);
      if (!regex_match(ageStr, regex("^\\d{1,3}$")))
      {
        throw runtime_error("Invalid Age: Only digits allowed (1-3 digits).");
      }
      age = stoi(ageStr); // convert to int

      cout << "Enter your phone number: ";
      cin >> phone;
      if (!regex_match(phone, regex("^\\d{10}$")))
      {
        throw runtime_error("Invalid Phone: Must be exactly 10 digits.");
      }

      cout << "Enter your email       : ";
      cin >> email;
      if (!regex_match(email, regex("^[\\w.-]+@[\\w.-]+\\.\\w+$")))
      {
        throw runtime_error("Invalid Email: Format is incorrect.");
      }

      cout << "Enter your address     : ";
      cin.ignore();
      getline(cin, address);

      // Count existing records
      int cnt = 1;
      string s;
      ifstream r("Data/INFO.txt", ios_base::in);
      while (getline(r, s))
      {
        cnt++;
      }
      r.close();
      ID = cnt;

      ofstream w("Data/INFO.txt", ios_base::app);
      w << setw(10) << "#f01" << cnt << "  " << setw(15) << name << " "
        << setw(10) << age << " " << setw(10) << phone << " "
        << setw(25) << email << " " << setw(25) << address << endl;
    }
    catch (const exception &e)
    {
      cout << endl;
      cout << "------------------------------------------------------------------------------" << endl;
      cerr << "                   " << e.what() << endl;
      cout << "------------------------------------------------------------------------------" << endl;
      cout << "                           :: PLEASE TRY AGAIN ::                             " << endl;
      cout << "------------------------------------------------------------------------------" << endl;
      set();
    }
  }
};

class PAGE : public Customer
{
  char choice;
  password p;
  int flag = 1;

public:
  void show()
  {
    cout << "==============================================================================" << endl;
    cout << "                               Welcome to Hotel Taj                           " << endl;
    cout << "                                  A) About                                    " << endl;
    cout << "                                  B) Customer                                 " << endl;
    cout << "                                  C) Help                                     " << endl;
    cout << "                                  D) Setting                                  " << endl;
    cout << "                            (Enter character to move on)                      " << endl;
    cout << "==============================================================================" << endl;
    cin >> choice;
    open();
  }
 
  void open()
  {
    switch (choice)
    {
    case 'A':
      About();
      break;
    case 'B':
      set();
      info();
      break;
    case 'C':
      Help();
      break;
    case 'D':
      if (flag == 1)
      {
        p.Set_Pass_W();
        flag = 0;
      }
      else
      {
        p.Pass_W();
      }
      show();
      break;
    default:
      cout << "------------------------------------------------------------------------------" << endl;
      cout << "                     WARNING :: PLEASE ENTER A VALID CHARACTER                " << endl;
      cout << "------------------------------------------------------------------------------" << endl;
      show();
      break;
    }
  }

  void About()
  {
    ifstream inputFile("Data/About.txt");
    string line;
    while (getline(inputFile, line))
    {
      cout << line << endl;
    }
    inputFile.close();
    char ch;
    cout << "Press any Key : ";
    cin >> ch;
    show();
  }

  void Help()
  {
    ifstream inputFile("Data/Help.txt");
    string line;
    while (getline(inputFile, line))
    {
      cout << line << endl;
    }
    inputFile.close();
    char ch;
    cout << "Press any Key : ";
    cin >> ch;
    show();
  }

  void create()
  {
    menu s;
    s.Card(ID);
  }

  void info()
  {
    cout << "==============================================================================" << endl;
    cout << "                    Choose correct option for What do Want?                   " << endl;
    cout << "                              Press 1) Menu Card                              " << endl;
    cout << "                              Press 2) BACK TO HOME                           " << endl;
    cout << "==============================================================================" << endl;
    char choice1;
    cin >> choice1;

    switch (choice1)
    {
    case '1':
      create();
      info();
      break;
    case '2':
      show();
      break;
    default:
      cout << "------------------------------------------------------------------------------" << endl;
      cout << "                     WARNING :: PLEASE ENTER A VALID CHARACTER                " << endl;
      cout << "------------------------------------------------------------------------------" << endl;
      info();
      break;
    }
  }

};

int main()
{
  PAGE obj;
  obj.show();
}