#include <drogon/drogon.h>
#include "header.hpp"
int main() {
    UserController::getStudentService().caricaDaFile("../studenti.json");
    drogon::app().addListener("0.0.0.0", 8080);   // server su http://localhost:8080
    drogon::app().setDocumentRoot("../views");     // serve index.html
    drogon::app().run();
    UserController::getStudentService().salvaSuFile("../studenti.json");
    return 0;
}
