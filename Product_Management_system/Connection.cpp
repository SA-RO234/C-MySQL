#include "Connection.h"
#define DB "ProductDB"
#define HOST "127.0.0.1"
#define PORT 3306
#define USER "root"
#define PASS ""


using namespace std;

 MYSQL* DBConnection::connect(){
      MYSQL *conn = mysql_init(NULL);
      if(!conn){
         cerr<<"MYSQL initialization failed !"<<endl;
         return NULL;
      }

      if(!mysql_real_connect(conn, HOST , USER ,PASS , DB,PORT , 0 , NULL)){
          cerr<<"Connect to database is failed !"<<mysql_error(conn)<<endl;
          return NULL;
       }

       cout<<"Connect to Database is Successfully !"<<endl;

       return conn;
    }

