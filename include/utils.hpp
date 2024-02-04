#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <spdlog/spdlog.h>

typedef std::map<std::string, std::string> config_t;

config_t get_config() {
     std::ifstream config_file("config.conf");
     
     if (!config_file.good()) {
          spdlog::warn("config.conf not found, created one.");
          config_t config = {
               {"apikey_discord", ""},
               {"owner", "820243208293580802"}
          };
          
          std::ofstream config_write("config.conf");
          
          if (config_write.is_open()) {
               config_write << "apikey_discord=" << std::endl;
               config_write << "owner=820243208293580802" << std::endl;
               config_write.close();
          }else{
               spdlog::error("Failed to create file config.conf.");
               throw std::exception();
          }
          spdlog::info("config.conf was created, please fill and try again.");
          
          return config;
     }else{
          spdlog::info("Loaded config.conf");
          config_t config;
          std::string line;
          
          while (std::getline(config_file, line)) {
               std::istringstream iss(line);
               std::string key, value;
               
               if (std::getline(iss, key, '=') && std::getline(iss, value)) {
                    if (value == "true" || value == "false") {
                         config[key] = value == "true";
                    }else{
                         config[key] = value;
                    }
               }
          }
          
          return config;
     }
}