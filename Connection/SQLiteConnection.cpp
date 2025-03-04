/*
* File: SQLiteConnection.cpp
* Author: trung.la
* Date: 03-03-2025
* Description: This is the implementation file of SQLiteConnection class
*/

#include <utility>
#include <exception>
#include <iostream>
#include "Connection/SQLiteConnection.h"

SQLiteConnection::SQLiteConnection(const std::string &dbName)
    : m_dbName(dbName), 
    m_db(dbName)
{
}

void SQLiteConnection::query(const std::string &query)
{
    try {
        m_db.exec(query);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}

void SQLiteConnection::transaction(const std::string &query)
{
    try {
        SQLite::Transaction transaction(m_db);
        m_db.exec(query);
        transaction.commit();
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}

SQLite::Database SQLiteConnection::getConnection()
{
    return std::move(m_db);
}