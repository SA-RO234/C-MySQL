#include "ProductDAO.h"
#include <iostream>
using namespace std;
// Insert a Product
bool ProductDAO::insertProduct(MYSQL *conn , Product p){
   string query = "INSERT INTO Product (pro_name, pro_price , pro_quantity) VALUES ('"+p.getName()+"',"+to_string(p.getPrice())+","+to_string(p.getQuantity())+");";
     if(mysql_query(conn , query.c_str())){
        cerr<<"Insert is Failed ! "<<mysql_error(conn)<<endl;
        return false;
      }
      return true;
 }

 // Get all Product
 void ProductDAO::getAllProducts(MYSQL *conn){
     string query = "SELECT * FROM Product";
     if(mysql_query(conn, query.c_str())){
      cerr<<"Select Failed !"<<endl;
       mysql_error(conn);
      }

      MYSQL_RES *res = mysql_store_result(conn);
      MYSQL_ROW row  ;

      while((row = mysql_fetch_row(res))){
           cout << "\t\t"<< row[0]
                << " , " << row[1]
                << " , " << row[2]
                << " , " << row[3] << endl;
           cout << "---------------------------------------\n";
       }
       mysql_free_result(res);
 }
