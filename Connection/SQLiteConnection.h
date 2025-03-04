/*
* File: SQLiteConnection.h
* Author: trung.la
* Date: 03-03-2025
* Description: This is the header file of SQLiteConnection class
*/

#ifndef SQLITECONNECTION_H
#define SQLITECONNECTION_H

#include "Connection/IDatabaseConnection.h"

class SQLiteConnection : public IDatabaseConnection
{
public:
    SQLiteConnection(const std::string &dbName);
    SQLiteConnection() = delete;
    ~SQLiteConnection() override = default;

    void query(const std::string &query) override;
    void transaction(const std::string &query) override;
    SQLite::Database getConnection() override;

private:
    SQLite::Database m_db; //db connection
    std::string m_dbName; //db name
};

#endif // SQLITECONNECTION_H