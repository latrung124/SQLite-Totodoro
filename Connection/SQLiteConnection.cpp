/*
* File: SQLiteConnection.cpp
* Author: trung.la
* Date: 03-03-2025
* Description: This is the implementation file of SQLiteConnection class
*/

#include <utility>
#include "Connection/SQLiteConnection.h"

SQLiteConnection::SQLiteConnection(const std::string &dbName)
    : m_db(dbName)
{
}

void SQLiteConnection::excute(const std::string &query, const std::string &errorMsg)
{
}

SQLite::Database SQLiteConnection::getConnection()
{
    return std::move(m_db);
}