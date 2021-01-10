#include "common/card.hpp"
#include <common/game_state.hpp>
#include <combinations.hpp>
#include <deck.hpp>
#include <pokerest.hpp>

#include <thread>
#include <variant>

void edit_variant(unsigned x){
  std::cout<<"I am money"<<std::endl;
}
void edit_variant(server::round_state::player_state x){
  std::cout<<"I am en enum"<<std::endl;
}
int main(int argc,char** argv) {
  auto c=combinations(std::array<card,7>{
    card{symbols::clubs,1},
    card{symbols::diamond,2},
    card{symbols::spades,8},
    card{symbols::hearts,4},
    card{symbols::clubs,5},
    card{symbols::clubs,6},
    card{symbols::clubs,7},
  });
  std::thread a(
    [&](){
      MyServerApp app;
      app.run(argc,argv);
      //Http::listenAndServe<pokerest>(Pistache::Address("*:9081"));
    }
  );
  a.detach();
  // server::round_state::var_type var=server::GlobalRoundState.ring_if_has_played_ammount.get();
  // std::visit([](auto x){edit_variant(x);},var);
  // server::GlobalRoundState.ring_if_has_played_ammount.next();
  // var=server::GlobalRoundState.ring_if_has_played_ammount.get();
  // std::visit([](auto x){edit_variant(x);},var); //sos δυο overloads για την συναρτηση που καλειτai σε visit
  // std::cout<<std::get<0>(server::GlobalRoundState.ring_if_has_played_ammount.get())<<std::endl;
  // server::GlobalRoundState.ring_if_has_played_ammount.next();
  // std::cout<<std::get<1>(server::GlobalRoundState.ring_if_has_played_ammount.get())<<std::endl;
  // server::GlobalRoundState.ring_if_has_played_ammount.next();
  // server::GlobalRoundState.ring_if_has_played_ammount.set(server::round_state::player_state::fold);
  // server::GlobalRoundState.ring_if_has_played_ammount.next();
  // server::GlobalRoundState.ring_if_has_played_ammount.next();
  std::stringstream stream ;
  stream<<server::GlobalRoundState;
  stream>>server::GlobalRoundState;
  std::cout<<server::GlobalRoundState;
  while(true){
    //play
    
  }
  }
