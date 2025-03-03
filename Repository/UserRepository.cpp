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
}

void UserRepository::insert(const User &user)
{
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