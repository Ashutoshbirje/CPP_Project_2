#include <bits/stdc++.h>
using namespace std;

class password {
  int a = 0;
public:

  void Set_Pass_W(void) {
    int b;
    int p;
    
    cout << "------------------------------------------------------------------------------" << endl;
    cout << "                     Set passward (4 digit)    : ";
    cin >> p;
    cout << "------------------------------------------------------------------------------" << endl;
    
  label:

    cout << "                     Verify passward (4 digit) : ";
    cin >> b;
    cout << "------------------------------------------------------------------------------" << endl;
    if (p == b) {
      a = p;

    cout<<  "                     Password created successfully                             " <<endl;
    cout << "------------------------------------------------------------------------------" << endl;
      Pass_W();
    } 
    else {
      cout << endl;
      cout << "                     WARNING :: Something Wrong.....!                " << endl;
      cout << "------------------------------------------------------------------------------" << endl;
      cout << endl;
      goto label;
    }
  }
  void Pass_W(void) {
    int b;
    cout << "------------------------------------------------------------------------------" << endl;
    cout << "                     Enter passward (4 digit) : ";
    cin >> b;
    cout << "------------------------------------------------------------------------------" << endl;
    if (a == b) {
      login();
    } 
    else {
      cout << "------------------------------------------------------------------------------" << endl;
      cout << "                     WARNING :: Something Wrong.....!                " << endl;
      cout << "------------------------------------------------------------------------------" << endl;
      Pass_W();
    }
  }

  void Ch_Pass_W(void) {
    int b, c, d;
    cout << endl;
    cout << "------------------------------------------------------------------------------" << endl;
    cout << "                     Enter passward (4 digit) : ";
    cin >> b;
    cout << "------------------------------------------------------------------------------" << endl;
    if (b == a) {
      Set_Pass_W();
    } 
    else {
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
  cin>>x;
  switch(x){
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