// Ecemplo disponivel em 

#include <stdlib.h>
#include <iostream>

#include <mysql_connection.h>
#include <mysql_driver.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <dotenv.h>

using namespace std;

int main(void)
{
    dotenv::init();

    cout << endl;
    cout << "Running 'SELECT 'Hello World!' AS _message'..." << endl;

    try
    {
        sql::Driver *driver;
        sql::Connection *con;
        sql::Statement *stmt;
        sql::ResultSet *res;

        driver = get_driver_instance();
        con = driver->connect(std::getenv("DB_HOST"), std::getenv("DB_USER"), std::getenv("DB_PASSWORD"));

        con->setSchema(std::getenv("DB_SCHEMA"));

        stmt = con->createStatement();
        res = stmt->executeQuery("SELECT 'Hello World!' AS _message");
        while (res->next())
        {
            cout << "\t... MySQL replies: ";

            cout << res->getString("_message") << endl;
            cout << "\t... MySQL says it again: ";

            cout << res->getString(1) << endl;
        }
        delete res;
        delete stmt;
        delete con;
    }
    catch (sql::SQLException &e)
    {
        cout << "# ERR: SQLException in " << __FILE__;
        cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
        cout << "# ERR: " << e.what();
        cout << " (MySQL error code: " << e.getErrorCode();
        cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }

    cout << endl;

    return EXIT_SUCCESS;
}