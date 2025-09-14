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

              int id = 0;
             string name;
             double price;
             int quantity;
             cin.ignore();
             cout<<"Enter Product Name : ";getline(cin,name);
             cout<<"Enter Price : ";cin>>price;
             cout<<"Enter Quantity : ";cin>>quantity;

            Product pro(id,name,price,quantity);

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
             int id_search= 0;
             cout<<"Enter ID for Update :";cin>>id_search;
               if(ProductDAO::productExists(conn , id_search)){
                  int qty;
                  string name;
                  double price;
                  cin.ignore();
                   cout<<"Enter New Product Name : ";getline(cin,name);
                   cout<<"Enter New Product Price : ";cin>>price;
                   cout<<"Enter New Product Quantity : ";cin>>qty;
                   Product upp(id_search , name , price , qty);
                   ProductDAO::updateProduct(conn,upp,id_search);
                 }else{
                   cerr<<"Product Not Found ! "<<endl;
                 }
            break;
          }
          case 4: {
           system("clear");
            cout << "==========================[ Update Products ]==========================\n";
             int id;
             cout<<"Enter ID for Delete : ";cin>>id;
             if(ProductDAO::deleteProduct(conn,id)){
                cout<<"Delete is Successfully ! "<<endl;
              }else{
                 cout<<"Delete is not Success ! "<<endl;
              }
           }break;
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
