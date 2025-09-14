#include "ProductClass.h"
#include <mysql.h>
#include <vector>

class ProductDAO{
  public:
    static bool insertProduct(MYSQL *conn , Product p);
    static void getAllProducts(MYSQL *conn);
    static void updateProduct(MYSQL *conn , Product p , int id);
    static bool deleteProduct(MYSQL* conn , int id);
    static bool productExists(MYSQL *conn, int id);
  };
