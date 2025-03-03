/*
* File: UserRepository.h
* Author: trung.la
* Date: 03-03-2025
* Description: This is the header file of UserRepository class
*/

#ifndef USERREPOSITORY_H
#define USERREPOSITORY_H

#include <memory>

#include "Connection/IDatabaseConnection.h"
#include "Repository/IUserRepository.h"

class UserRepository : public IUserRepository
{
public:
    UserRepository(const std::shared_ptr<IDatabaseConnection> &connection);
    ~UserRepository() override = default;

    void createTable() override;
    void insert(const User& user) override;
    void update(const User& user) override;
    void remove(const User& user) override;
    std::vector<User> getAll() override;
    std::optional<User> findById(const std::string& userId) override;
    std::optional<User> findByUserName(const std::string& userName) override;
    std::optional<User> findByEmail(const std::string& email) override;

private:
    std::shared_ptr<IDatabaseConnection> m_connection;
};

#endif // USERREPOSITORY_H