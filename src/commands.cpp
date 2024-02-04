#include "commands.hpp"
#include "commands/nya_c.hpp"
#include <spdlog/spdlog.h>

Commands::Commands() {
     commands = {
          Nya::getconf(),
     };
}

Commands::~Commands() {}

void Commands::sync(dpp::cluster& client) {
     commands_t commands_list;
     
     /** Store vector commands into commands_list **/
     for (const auto& command : commands) {
          dpp::slashcommand cmd(command.name, command.description, client.me.id);
          
          if (command.param.has_value()) {
               for (const auto& param : command.param.value()) {
                    cmd.add_option(param);
               }
          }
          
          commands_list.push_back(cmd);
          spdlog::info("[/] Loaded command {}.", command.name);
     }
     
     /** Delete old slash commands **/
     spdlog::info("Removing old commands.");
     client.global_bulk_command_delete();
     //client.guild_bulk_command_delete(940091596752425000);
     
     /** Registering all commands to server **/
     int total = sizeof(commands_list) / sizeof(commands_t);
     spdlog::info("Registering all commands. Total: {}", total);
     client.global_bulk_command_create(commands_list);
     spdlog::info("Sucessfuly syncing commands.");
}

std::optional<command_t> Commands::grab(const std::string& name) {
     for (const auto& command : commands) {
          if (command.name == name) return command;
     }
     return std::nullopt;
}