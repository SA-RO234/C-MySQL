#include "Connection.h"
#include "ProductClass.h"
#include "ProductDAO.h"
#include "Display.h"
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    MYSQL *conn = DBConnection::connect();
     if (!conn) return 1;  // connection failed

    int menu = 0;
    string status;

    while (true) {
        Display::showMenu();
        cout << "\n\t Choose One Menu Above : "; cin >> menu;

        switch (menu) {
        case 1:{
            system("clear");
            cout << "==========================[ Create Product ]==========================\n";

              int id;
             string name;
             double price;
             int quantity;

             cout<<"Enter Product ID : ";cin>>id; cin.ignore();
             cout<<"Enter Product Name : ";getline(cin,name);
             cout<<"Enter Price : ";cin>>price;
             cout<<"Enter Quantity : ";cin>>quantity;

            Product pro(id, name,price , quantity);

            if (ProductDAO::insertProduct(conn, pro)) {
                cout << "Insert is Successful!\n";
            } else {
                cerr << "Insert Failed!\n";
            }
            break;
         }
        case 2:{
            system("clear");
            cout << "==========================[ Show All Products ]==========================\n";
            {
                 ProductDAO::getAllProducts(conn);

            }break;
           }
         case 3:{
           system("clear");
            cout << "==========================[ Update Products ]==========================\n";

          break;}
        default:
            cout << "Invalid choice!\n";
        }

        cout << "Continue or not [Yes/No]: ";
        cin >> status;
        transform(status.begin(), status.end(), status.begin(), ::toupper);
        if (status == "NO") break;
    }

   mysql_close(conn);

    return 0;
}
