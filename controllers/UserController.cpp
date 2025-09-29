#include "UserController.h"
#include <json/json.h>

void UserController::registerUser(const drogon::HttpRequestPtr& req,
                                  std::function<void (const drogon::HttpResponsePtr &)> &&callback)
{
    auto json = req->getJsonObject();
    Json::Value result;

    if (!json || !json->isMember("nome") || !json->isMember("cognome")) {
        result["success"] = false;
        result["error"] = "Missing fields";
        callback(drogon::HttpResponse::newHttpJsonResponse(result));
        return;
    }

    std::string nome = (*json)["nome"].asString();
    std::string cognome = (*json)["cognome"].asString();

    bool ok = studentService.addStudent(nome, cognome);
    result["success"] = ok;
    callback(drogon::HttpResponse::newHttpJsonResponse(result));
}

void UserController::loginUser(const drogon::HttpRequestPtr& req,
                               std::function<void (const drogon::HttpResponsePtr &)> &&callback)
{
    auto json = req->getJsonObject();
    Json::Value result;

    if (!json || !json->isMember("nome") || !json->isMember("cognome")) {
        result["success"] = false;
        result["error"] = "Missing fields";
        callback(drogon::HttpResponse::newHttpJsonResponse(result));
        return;
    }

    std::string nome = (*json)["nome"].asString();
    std::string cognome = (*json)["cognome"].asString();

    bool ok = studentService.checkStudent(nome, cognome);
    result["success"] = ok;
    callback(drogon::HttpResponse::newHttpJsonResponse(result));
}
