#pragma once
#include <dpp/dpp.h>
#include "../commands.hpp"

class Nya {
public:
     static void execute(dpp::cluster& client, const dpp::slashcommand_t& event);
     
     static command_t getconf() {
          param_t param = {
               {dpp::command_option(dpp::co_string, "test", "Testo")},
          };
          
          return {
               "nya",
               "🚀 Testo command desu.",
               Nya::execute,
               param,
               true
          };
     }
};