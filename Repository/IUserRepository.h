/*
* File: IUserRepository.h
* Author: trung.la
* Date: 03-03-2025
* Description: This is the header file of IUserRepository interface
*/

#ifndef IUSERREPOSITORY_H
#define IUSERREPOSITORY_H

#include <vector>
#include <optional>
#include <string>

#include "DataStructure/User.h"

class IUserRepository
{
public:
    virtual ~IUserRepository() = default;
    virtual void createTable() = 0;
    virtual void insert(const User& user) = 0;
    virtual void update(const User& user) = 0;
    virtual void remove(const User& user) = 0;
    virtual std::vector<User> getAll() = 0;
    virtual std::optional<User> findById(const std::string& userId) = 0;
    virtual std::optional<User> findByUserName(const std::string& userName) = 0;
    virtual std::optional<User> findByEmail(const std::string& email) = 0;
};

#endif // IUSERREPOSITORY_H