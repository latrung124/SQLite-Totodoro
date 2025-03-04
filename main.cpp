#include <iostream>
#include <exception>
#include <string>
#include <memory>

#include "Connection/SQLiteConnection.h"
#include "Repository/UserRepository.h"

void example()
{
    try {
        SQLite::Database db(std::string(SOURCE_DIR) + "/example.db3");

        SQLite::Statement query(db, "SELECT * FROM test");
        while (query.executeStep()) {
            std::cout << "id: " << query.getColumn(0) << ", val: " << query.getColumn(1) << std::endl;
        }
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        SQLite::Database db(std::string(SOURCE_DIR) + "/transaction.db3", SQLite::OPEN_READWRITE | SQLite::OPEN_CREATE);
        db.exec("DROP TABLE IF EXISTS test");

        SQLite::Transaction transaction(db);
        db.exec("CREATE TABLE test (id INTEGER PRIMARY KEY, val TEXT)");

        int nb = db.exec("INSERT INTO test VALUES (1, \"test\")");
        std::cout << "INSERT INTO test VALUES (1, \"test\") returned " << nb << std::endl;

        transaction.commit();
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        SQLite::Database db(std::string(SOURCE_DIR) + "/transaction.db3", SQLite::OPEN_READWRITE | SQLite::OPEN_CREATE);
        SQLite::Statement query(db, "SELECT * FROM test");
        while (query.executeStep()) {
            std::cout << "id: " << query.getColumn(0) << ", val: " << query.getColumn(1) << std::endl;
        }
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

}
int main() {
    std::cout << "Hello, World!" << std::endl;
    std::string path = std::string(SOURCE_DIR) + "/Users.db";
    try {
        std::shared_ptr<IDatabaseConnection> connection = std::make_shared<SQLiteConnection>(path);
        UserRepository userRepository(connection);
        userRepository.createTable();
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}