#pragma once
#include <drogon/HttpController.h>
#include "../header.hpp"
#include <vector>

class StudentService {
public:
    bool addStudent(const std::string &nome, const std::string &cognome) {
        for (auto &s : studenti) {
            if (s.getNome() == nome && s.getCognome() == cognome) {
                return false; // già registrato
            }
        }
        studenti.emplace_back(nome, cognome);
        return true;
    }

    bool checkStudent(const std::string &nome, const std::string &cognome) {
        for (auto &s : studenti) {
            if (s.getNome() == nome && s.getCognome() == cognome) {
                return true;
            }
        }
        return false;
    }

private:
    std::vector<studente> studenti;
};

class UserController : public drogon::HttpController<UserController> {
public:
    METHOD_LIST_BEGIN
    ADD_METHOD_TO(UserController::registerUser, "/register", drogon::Post);
    ADD_METHOD_TO(UserController::loginUser, "/login", drogon::Post);
    METHOD_LIST_END

    void registerUser(const drogon::HttpRequestPtr& req,
                      std::function<void (const drogon::HttpResponsePtr &)> &&callback);

    void loginUser(const drogon::HttpRequestPtr& req,
                   std::function<void (const drogon::HttpResponsePtr &)> &&callback);

private:
    StudentService studentService;
};
