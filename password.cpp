#include <bits/stdc++.h>
using namespace std;

class password
{
  int a = 0;

public:
  void Set_Pass_W(void)
  {
    int b;
    int p;

    cout << "------------------------------------------------------------------------------" << endl;
    cout << "                     Set password (4 digit)    : ";

    try
    {
      cin >> p;
      if (cin.fail())
      {
        throw runtime_error("Invalid input: Please enter only integers.");
      }
    }
    catch (exception &e)
    {
      cin.clear();
      cin.ignore(INT_MAX, '\n');
      
      cout << "------------------------------------------------------------------------------" << endl;
      cout << "                 " << e.what() << endl;
      cout << "------------------------------------------------------------------------------" << endl;
      return;
    }

    cout << "------------------------------------------------------------------------------" << endl;

  label:

    cout << "                     Verify password (4 digit) : ";

    try
    {
      cin >> b;
      if (cin.fail())
      {
        throw runtime_error("Invalid input: Please enter only integers.");
      }
    }
    catch (exception &e)
    {
      cin.clear();
      cin.ignore(INT_MAX, '\n');
      cout << "------------------------------------------------------------------------------" << endl;
      cout << "                 " << e.what() << endl;
      cout << "------------------------------------------------------------------------------" << endl;
      return;
    }

    cout << "------------------------------------------------------------------------------" << endl;

    if (p == b)
    {
      a = p;
      cout << "                     Password created successfully                             " << endl;
      cout << "------------------------------------------------------------------------------" << endl;
      Pass_W();
    }
    else
    {
      cout << endl;
      cout << "                     WARNING :: Something Wrong.....!                " << endl;
      cout << "------------------------------------------------------------------------------" << endl;
      cout << endl;
      goto label;
    }
  }

  void Pass_W(void)
  {
    int b;
    cout << "------------------------------------------------------------------------------" << endl;
    cout << "                     Enter password (4 digit) : ";

    try
    {
      cin >> b;
      if (cin.fail())
      {
        throw runtime_error("Invalid input: Please enter only integers.");
      }
    }
    catch (exception &e)
    {
      cin.clear();
      cin.ignore(INT_MAX, '\n');
      cout << "------------------------------------------------------------------------------" << endl;
      cout << "                 " << e.what() << endl;
      cout << "------------------------------------------------------------------------------" << endl;
      return;
    }

    cout << "------------------------------------------------------------------------------" << endl;
    if (a == b)
    {
      login();
    }
    else
    {
      cout << "------------------------------------------------------------------------------" << endl;
      cout << "                     WARNING :: Something Wrong.....!                " << endl;
      cout << "------------------------------------------------------------------------------" << endl;
      Pass_W();
    }
  }

  void Ch_Pass_W(void)
  {
    int b;
    cout << endl;
    cout << "------------------------------------------------------------------------------" << endl;
    cout << "                     Enter password (4 digit) : ";

    try
    {
      cin >> b;
      if (cin.fail())
      {
        throw runtime_error("Invalid input: Please enter only integers.");
      }
    }
    catch (exception &e)
    {
      cin.clear();
      cin.ignore(INT_MAX, '\n');
      cout << "------------------------------------------------------------------------------" << endl;
      cout << "                 " << e.what() << endl;
      cout << "------------------------------------------------------------------------------" << endl;
      return;
    }

    cout << "------------------------------------------------------------------------------" << endl;

    if (b == a)
    {
      Set_Pass_W();
    }
    else
    {
      cout << endl;
      cout << "------------------------------------------------------------------------------" << endl;
      cout << "                     WARNING :: Something Wrong.....!                " << endl;
      cout << "------------------------------------------------------------------------------" << endl;
      cout << endl;
    }
  }

  void login()
  {
    cout << "==============================================================================" << endl;
    cout << "                                    Login page                                " << endl;
    cout << "                              Press 1) Change password                        " << endl;
    cout << "                              Press 2) BACK TO HOME                           " << endl;
    cout << "==============================================================================" << endl;

    int x;
    try
    {
      cin >> x;
      if (cin.fail())
      {
        throw runtime_error("Invalid input: Please enter only integers.");
      }
    }
    catch (exception &e)
    {
      cin.clear();
      cin.ignore(INT_MAX, '\n');
      cout << "------------------------------------------------------------------------------" << endl;
      cout << "                 " << e.what() << endl;
      cout << "------------------------------------------------------------------------------" << endl;
      return;
    }

    switch (x)
    {
    case 1:
      Set_Pass_W();
      login();
      break;
    case 2:
      break;
    default:
      cout << "------------------------------------------------------------------------------" << endl;
      cout << "                     WARNING :: PLEASE ENTER A VALID CHARACTER                " << endl;
      cout << "------------------------------------------------------------------------------" << endl;
      login();
      break;
    }
  }
};
