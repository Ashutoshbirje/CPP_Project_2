#include <fstream>
#include <iomanip>
#include <iostream>
#include "Menu.cpp"
#include "password.cpp"
using namespace std;
class Customer{
private:
  string name;
  int age;
  long long int phone;
  string email;
  string address;
  int trooms = 10;
  int brooms = 0;
  
public:
 
  int ID=0;
  void set(){
    ofstream w;
    w.open("INFO.txt", ios_base::app);
    cout << "Enter your name        : ";
    cin >> name;

    cout << "Enter your age         : ";
    cin >> age;

    cout << "Enter your phone number: ";
    cin >> phone;

    cout << "Enter your email       : ";
    cin >> email;

    cout << "Enter your address     : ";
    cin >> address;

    int cnt = 0;
    string s;
    ifstream r("INFO.txt", ios_base::in);
    while (getline(r, s)) {
      cnt++;
    }
    r.close();
    ID = cnt;
    w << setw(10) << "#f01" << cnt << "  " << setw(15) << name << " "
      << setw(10) << age << " " << setw(10) << phone << " " << setw(25) << email
      << " " << setw(25) << address << endl;
  }
  void available_rooms() { 
    cout << "------------------------------------------------------------------------------" << endl;
    cout << "                 Total number of rooms avialable : "<<trooms - brooms << endl; 
    cout << "------------------------------------------------------------------------------" << endl;
    booking_rooms();
  }
  void booking_rooms() {
    int reqrooms;
    cout << "------------------------------------------------------------------------------" << endl;
    cout << "                 Enter number of rooms you want : " ;
    cin >> reqrooms;
    cout << "------------------------------------------------------------------------------" << endl;
    if (reqrooms <= (trooms - brooms)) {
      int days;
      char choose;
    cout << "                 Enter For how many days do you want room? ";
      cin >> days;
    cout << "------------------------------------------------------------------------------" << endl;
    cout << "                 Your total bill is :" << reqrooms * days * 1000 << endl;
    cout << "------------------------------------------------------------------------------" << endl;
      cout << "               Do you Want to confirm booking?(Y/N) " << endl;
      cin >> choose;
    cout << "------------------------------------------------------------------------------" << endl;
      if (choose == 'Y') {
    cout << "                 Congratulations your rooms booking is confirmed              " << endl;
    cout << "------------------------------------------------------------------------------" << endl;
      brooms += reqrooms;
      } 
      else {
    cout << "                 Booking is not confirmed" << endl;
    cout << "------------------------------------------------------------------------------" << endl;
      }
    }
    else {
    cout << "                 Required Number of Rooms are not available" << endl;
    cout << "------------------------------------------------------------------------------" << endl;
    }
  }
};

class PAGE:public Customer{
 char a;
 password p;
 int flag=1;
public:
  void show() {
    cout << "==============================================================================" << endl;
    cout << "                               Welcome to Hotel Taj                           " << endl;
    cout << "                                  A) About                                    " << endl;
    cout << "                                  B) Customer                                 " << endl;
    cout << "                                  C) Help                                     " << endl;
    cout << "                                  D) Setting                                  " << endl;
    cout << "                            (Enter character to move on)                      " << endl;
    cout << "==============================================================================" << endl;
    cin >> a;
    open();
  }
  void About(){
    ifstream inputFile("About.txt");
    string line;
    while (getline(inputFile, line)) {
      cout << line << endl;
    }
    inputFile.close();
    char a;
    cout << "Press any Key : ";
    cin >> a;
    show();
  }
  void Help() {
    ifstream inputFile("Help.txt");
    string line;
    while (getline(inputFile, line)) {
      cout << line << endl;
    }
    inputFile.close();
    char a;
    cout << "Press any Key : ";
    cin >> a;
    show();
  }
  void open() {
    switch (a) {
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
      if(flag==1){
       p.Set_Pass_W();
       flag=0;
      }
      else{
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
  void create(){
       menu s;
       s.Card(ID);
  }
  void info() {
    cout << "==============================================================================" << endl;
    cout << "                    Choose correct option for What do Want?                   " << endl;
    cout << "                              Press 1) Menu Card                              " << endl;
    cout << "                              Press 2) Booking                                " << endl;
    cout << "                              Press 3) BACK TO HOME                           " << endl;
    cout << "==============================================================================" << endl;
  char choice;
  cin >> choice;

  switch (choice) {
  case '1':
    create();
    info();
    break;
  case '2':
    available_rooms();
    info();
    break;
  case '3':
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

int main() {
  PAGE a;
  a.show();
}