/*
* File: User.h
* Author: trung.la
* Date: 03-03-2025
* Description: This is the header file of User class
*/

#ifndef USER_H
#define USER_H

#include <string>

class User
{
public:
    User(const std::string &userId, const std::string &userName, const std::string &email,
     const std::string &createAt, const std::string &updateAt) noexcept;
    
    explicit User(const std::string &username, std::string &email) noexcept;

    ~User() = default;

    std::string getUserId() const noexcept;
    std::string getUserName() const noexcept;
    std::string getEmail() const noexcept;
    std::string getCreateAt() const noexcept;
    std::string getUpdateAt() const noexcept;

    void setUserName(const std::string &userName);
    void setEmail(const std::string &email);

private:
    std::string m_userId;
    std::string m_userName;
    std::string m_email;
    std::string m_createAt;
    std::string m_updateAt;
};

#endif // USER_H