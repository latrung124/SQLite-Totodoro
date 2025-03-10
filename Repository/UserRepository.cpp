/*
* File: UserRepository.cpp
* Author: trung.la
* Date: 03-03-2025
* Description: This is the implementation file of UserRepository class
*/

#include "Repository/UserRepository.h"

UserRepository::UserRepository(const std::shared_ptr<IDatabaseConnection> &connection)
    : m_connection(connection)
{
}

void UserRepository::createTable()
{
    auto const connection = m_connection.lock();
    if (!connection)
    {
        return;
    }

    const std::string sql = 
            "CREATE TABLE IF NOT EXISTS Users ("
            "user_id TEXT PRIMARY KEY, "
            "email TEXT UNIQUE, "
            "username TEXT UNIQUE NOT NULL, "
            "created_at TEXT DEFAULT CURRENT_TIMESTAMP, "
            "updated_at TEXT DEFAULT CURRENT_TIMESTAMP"
            ")";

    connection->transaction(sql);
}

void UserRepository::insert(const User &user)
{
    const std::string sql =
            "INSERT INTO Users (user_id, email, username, created_at, updated_at) "
            "VALUES ('" + user.getUserId() + "', '" + user.getEmail() + "', '"
            + user.getUserName() + "', '" + user.getCreateAt() + "', '"
            + user.getUpdateAt() + "')";
    
    auto const connection = m_connection.lock();
    if (!connection)
    {
        return;
    }

    connection->transaction(sql);
}

void UserRepository::update(const User &user)
{
}

void UserRepository::remove(const User &user)
{
}

std::vector<User> UserRepository::getAll()
{
    return std::vector<User>();
}

std::optional<User> UserRepository::findById(const std::string &userId)
{
    const std::string sql = "SELECT * FROM Users WHERE user_id = '" + userId + "'";
    auto const connection = m_connection.lock();
    if (!connection)
    {
        return std::nullopt;
    }

    SQLite::Statement query(*connection->getConnection(), sql);
    if (query.executeStep())
    {
        return User(query.getColumn(0).getText(), query.getColumn(1).getText(), query.getColumn(2).getText(), query.getColumn(3).getText(), query.getColumn(4).getText());
    }

    return std::nullopt;
}

std::optional<User> UserRepository::findByUserName(const std::string &userName)
{
    return std::nullopt;
}

std::optional<User> UserRepository::findByEmail(const std::string &email)
{
    return std::nullopt;
}