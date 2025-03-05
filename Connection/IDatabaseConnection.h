/*
* File: IDatabaseConnection.h
* Author: trung.la
* Date: 03-03-2025
* Description: This is the header file of IDatabaseConnection interface
*/

#ifndef IDATABASECONNECTION_H
#define IDATABASECONNECTION_H

#include <string>
#include <SQLiteCpp/SQLiteCpp.h>

class IDatabaseConnection
{
public:
    virtual ~IDatabaseConnection() = default;
    virtual void query(const std::string &query) = 0;
    virtual void transaction(const std::string &query) = 0;
    virtual SQLite::Database* getConnection() = 0;
};

#endif // IDATABASECONNECTION_H