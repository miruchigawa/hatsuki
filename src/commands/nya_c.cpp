#include "commands/nya_c.hpp"

void Nya::execute(dpp::cluster& client, const dpp::slashcommand_t& event) {
     event.reply("Nya!");
}