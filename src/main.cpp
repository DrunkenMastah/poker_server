#include <pokerest.hpp>
#include <deck.hpp>

int main() {
  Http::listenAndServe<pokerest>(Pistache::Address("*:9081"));
  deck poker_deck;
  auto a=poker_deck.spit();
  
}
