#include <bits/stdc++.h>
#include <fstream>
#include <iomanip>
using namespace std;

class menu {
  
  vector<string> Item;
  vector<int> rate;
  vector<int> cost;
  vector<int> quantity;
  int count = 0;
  int C;       // menu number
  int sum = 0; // total bill
  int a;       // quantity
  int Cust_id; 

public:

  menu() {
    loadMenu();
  }

  // Load menu items from file
  void loadMenu() {
    Item.clear();
    rate.clear();
    ifstream in("Data/Menu.txt");
    string name;
    int r;
    while (in >> ws && getline(in, name, ' ')) {
      in >> r;
      Item.push_back(name);
      rate.push_back(r);
    }
    in.close();
  }

  // Save menu items to file
  void saveMenu() {
    ofstream out("Data/Menu.txt", ios::trunc);
    for (int i = 0; i < Item.size(); i++) {
      out << Item[i] << " " << rate[i] << "\n";
    }
    out.close();
  }

  void Card(int id) {
    Cust_id = id;
    cout << endl;
    cout << "==============================================================================" << endl;
    cout << "                                    Hotel Taj                                 " << endl;
    cout << "                          123 Oceanfront Avenue,M.G.Road,                     " << endl;
    cout << "                          Pune-411001 Maharashtra, India                      " << endl;
    cout << "                             GSTIN :- 27ALDPM7712K1ZV                         " << endl;
    cout << "                        ----------------------------------                    " << endl;
    cout << "                         Item              Code  cost(Rs.)                    " << endl;
    cout << "                        ----------------------------------                    " << endl;

    for (int i = 0; i < Item.size(); i++) {
      cout << "                         # " << setw(10) << left << Item[i] 
           << "    (" << i+1 << ")    " << rate[i] << ".00 Rs" << endl;
    }
    if(id!=-1){
    cout << "                         # ORDER      (0)    ########  " << endl;
    cout << "    (Enter respective code number to choose menu and then press ORDER code)   " << endl;
    } else {
    cout << "                         # New Item      (0)    New-Rate  " << endl;
    cout << "                         # Exit         (-1)    XXXXXXXX  " << endl;
    cout << "   (Enter code number to edit menu and then press New Item code to add New)   " << endl;
    } 
    cout << "==============================================================================" << endl;
    cout << endl;
    if(id!=-1){
      inti();
    }
  }

  void bill(void) {
    cout << "Enter Quantity   :";
    cin >> a;
    cout << endl;
    int sum1 = a * rate[C - 1];
    sum += sum1;
    quantity.push_back(a);
    cost.push_back(sum1);
    Item.push_back(Item[C - 1]);
    inti();
  }

  void bill_display(void) {
    cout << "==============================================================================" << endl;
    cout << "                                    Hotel Taj                                 " << endl;
    cout << "                          123 Oceanfront Avenue,M.G.Road,                     " << endl;
    cout << "                          Pune-411001 Maharashtra, India                      " << endl;
    cout << "                             GSTIN :- 27ALDPM7712K1ZV                         " << endl;
    cout << "                        ----------------------------------                    " << endl;
    cout << "                         Item              Qty.  cost(Rs.)                    " << endl;
    cout << "                        ----------------------------------                    " << endl;

    ofstream write("Data/BILL.txt", ios_base::app);
    for (int i = 0; i < count; i++) {
      cout << "                         " << Item[i] << "        " << quantity[i] 
           << "     " << cost[i] << endl;

      write << setw(10) << "#f01" << Cust_id << "      " 
            << setw(11) << Item[i] << "    " 
            << setw(2) << quantity[i] << "        "
            << setw(5) << cost[i] << endl;
    }
    write.close();

    cout << "                        ----------------------------------                    " << endl;
    cout << "                         TOTAL BILL               :" << sum << " Rs.          " << endl;
    cout << "                        ----------------------------------                    " << endl;
    cout << "                         THANK YOU FOR VISITING........!                       " << endl;
    cout << "==============================================================================" << endl;
    cout << endl;
  }

  void inti() {
    cout << "Enter number     :";
    cin >> C;

    if (cin.fail()) {
        cin.clear(); 
        cin.ignore(INT_MAX, '\n'); 
        cout << "------------------------------------------------------------------------------" << endl;
        cout << "                   ERROR :: Invalid input, Please enter a number              " << endl;
        cout << "------------------------------------------------------------------------------" << endl;
        inti();
        return;
    }

    if (C >= 1 && C <= Item.size()) {
      count++;
      bill();
    } else if (C == 0) {
      bill_display();
    } else {
      cout << endl;
      cout << "------------------------------------------------------------------------------" << endl;
      cout << "                     WARNING :: USER NOT FOUND                                " << endl;
      cout << "------------------------------------------------------------------------------" << endl;
      inti();
      cout << endl;
    }
  }

  // Admin option to edit menu
  void editMenu() {
    Card(-1);
    int choice;
    cin >> choice;
    cout << "------------------------------------------------------------------------------" << endl;
    if (cin.fail()) {
        cin.clear(); 
        cin.ignore(INT_MAX, '\n'); 
        cout << "------------------------------------------------------------------------------" << endl;
        cout << "                   ERROR :: Invalid input, Please enter a number              " << endl;
        cout << "------------------------------------------------------------------------------" << endl;
        editMenu();
        return;
    }

    if (choice == 0) {
        string newName; int newRate;
        cout << "Enter new item name: ";
        cin >> ws; getline(cin, newName);
        cout << "Enter rate: ";
        while (!(cin >> newRate)) {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout << "------------------------------------------------------------------------------" << endl;
            cout << "                   ERROR :: Invalid input! Enter numeric rate:                " << endl;
            cout << "------------------------------------------------------------------------------" << endl;
        }
        Item.push_back(newName);
        rate.push_back(newRate);
        saveMenu(); 
        cout << "------------------------------------------------------------------------------" << endl;
        cout << "Menu updated successfully!\n";

    } else if (choice == -1) {
        return;

    } else if (choice > 0 && choice <= Item.size()) {
        cout << "Editing " << Item[choice-1] << "\n";
        cout << "------------------------------------------------------------------------------" << endl;
        cout << "Enter new name (or . to keep same): ";
        string newName; cin >> ws; getline(cin, newName);
        if (newName != ".") Item[choice-1] = newName;

        cout << "Enter new rate: ";
        int newRate;
        while (!(cin >> newRate)) {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout << "------------------------------------------------------------------------------" << endl;
            cout << "                   ERROR :: Invalid input! Enter numeric rate:                " << endl;
            cout << "------------------------------------------------------------------------------" << endl;
        }
        rate[choice-1] = newRate;

        saveMenu();  
        cout << "------------------------------------------------------------------------------" << endl;
        cout << "Menu updated successfully!\n";

    } else {
        cout << "------------------------------------------------------------------------------" << endl;
        cout << "                     WARNING :: CODE NOT FOUND                                " << endl;
        cout << "------------------------------------------------------------------------------" << endl;
        editMenu();
    }
}

};
