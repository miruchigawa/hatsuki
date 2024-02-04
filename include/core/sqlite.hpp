#pragma once
#include <string>
#include <sqlite3.h>

class Sqlite {
public:
     Sqlite();
     ~Sqlite();
     void init(const std::string& file);
     bool execute(const std::string& query);
private:
     sqlite3* db;
};