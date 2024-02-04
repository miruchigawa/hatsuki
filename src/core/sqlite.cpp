#include "core/sqlite.hpp"
#include <spdlog/spdlog.h>

Sqlite::Sqlite() {}

Sqlite::~Sqlite() {
     sqlite3_close(db);
}

void Sqlite::init(const std::string& file) {
     if (sqlite3_open(file.c_str(), &db) != SQLITE_OK) {
          spdlog::error("Failed to open database.");
          exit(1);
     }
}

bool Sqlite::execute(const std::string& query) {
     char* error_message = nullptr;
     int result = sqlite3_exec(db, query.c_str(), nullptr, nullptr, &error_message);
     
     if (result != SQLITE_OK) {
          spdlog::error("Failed to execute sqlite: {}", error_message);
          free(error_message);
          return false;
     }
     return true;
}