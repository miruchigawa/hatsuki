#include <dpp/dpp.h>
#include <iostream>
#include <spdlog/spdlog.h>
#include "utils.hpp"
#include "commands.hpp"


int main() {
    config_t config = get_config();
    dpp::cluster client(config["apikey_discord"]);
    Commands commands;

    client.on_slashcommand([&client, &commands, &config](const dpp::slashcommand_t& event) {
          const std::string& name = event.command.get_command_name();
          auto grab = commands.grab(name);
          
          if (!grab.has_value()) {
               event.reply("Command not found, maybe commands were not synced.");
               return;
          }
          
          command_t& command = grab.value();
          
          if (command.sudo && event.command.usr.id != dpp::snowflake(config["owner"])) {
               event.reply("You are not allowed to execute this command.");
               return;
          }
          
          command.execute(client, event);
          spdlog::info("[/] Executed command /{} by @{} at <{}>.", command.name, event.command.usr.username, event.command.guild_id);
    });

    client.on_ready([&client, &commands](const dpp::ready_t& event) {
          spdlog::info("Client connected as @{}.", client.me.username);
          commands.sync(client);
    });

    try {
        spdlog::info("Connecting to server...");
        client.start(dpp::st_wait);
    } catch (const std::exception& error) {
        spdlog::error("Failed to connect to the server: {}", error.what());
    }
}