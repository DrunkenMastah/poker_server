#pragma once

#include <game_state.hpp>
class server{
  
std::variant<state_of_table, error_state> get_view(unsigned player) {
  if (player < number_of_players) { 
    return current_round.state_of_table;
  } else
    return error_state::player_out_of_bounds;
}
private:
  server::round_state  current_round; 
};
