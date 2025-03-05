/*
* File: User.cpp
* Author: trung.la
* Date: 03-03-2025
* Description: This is the implementation file of User class
*/

#include "DataStructure/User.h"

User::User(const std::string &userId, const std::string &userName, const std::string &email,
    const std::string &createAt, const std::string &updateAt) noexcept
    : m_userId(userId),
     m_userName(userName),
     m_email(email),
     m_createAt(createAt),
     m_updateAt(updateAt)
{
}

User::User(const std::string &username, std::string &email) noexcept
    : m_userName(username),
    m_email(email)
{
}

std::string User::getUserId() const noexcept
{
    return m_userId;
}

std::string User::getUserName() const noexcept
{
    return m_userName;
}

std::string User::getEmail() const noexcept
{
    return m_email;
}

std::string User::getCreateAt() const noexcept
{
    return m_createAt;
}

std::string User::getUpdateAt() const noexcept
{
    return m_updateAt;
}

void User::setUserName(const std::string &userName)
{
    m_userName = userName;
}

void User::setEmail(const std::string &email)
{
    m_email = email;
}