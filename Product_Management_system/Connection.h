#include <iostream>
#include <mysql.h>
using namespace std;

class DBConnection{
    public:
    static MYSQL * connect();
 };
