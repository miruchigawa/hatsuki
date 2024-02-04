#pragma once
#include <vector>
#include <string>
#include <dpp/dpp.h>
#include <functional>
#include <optional>

typedef std::function<void (dpp::cluster&, const dpp::slashcommand_t&)> fn_t;
typedef std::vector<dpp::slashcommand> commands_t;
typedef std::optional<std::vector<dpp::command_option>> param_t;

struct command_t {
     std::string name;
     std::string description;
     fn_t execute;
     param_t param;
     bool sudo;
};

class Commands {
public:
     Commands();
     ~Commands();
     void sync(dpp::cluster& client);
     std::optional<command_t> grab(const std::string& name);
private:
     std::vector<command_t> commands;
};