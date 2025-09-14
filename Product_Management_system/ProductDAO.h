#include "ProductClass.h"
#include <mysql.h>
#include <vector>

class ProductDAO{
  public:
    static bool insertProduct(MYSQL *conn , Product p);
    static void getAllProducts(MYSQL *conn);
    static bool updateProduct(MYSQL *conn , Product p);
    static bool deleteProduct(MYSQL* conn , int id);
  };
