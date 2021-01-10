#include "common/card.hpp"
#include <combinations.hpp>

#include <algorithm>
#include <array>
#include <iostream>
#include <optional>


std::optional<std::vector<unsigned>> is_flush(const std::array<card, 7> & hand){
    std::array<std::vector<unsigned>,4> arranged_by_symbol{};
    for(auto i:hand){
        switch(i.first){
        case symbols::clubs:
            arranged_by_symbol[0].push_back(i.second);
            break;
        case symbols::spades:
            arranged_by_symbol[1].push_back(i.second);
            break;
        case symbols::diamond:
            arranged_by_symbol[2].push_back(i.second);
            break;
        case symbols::hearts:
            arranged_by_symbol[3].push_back(i.second);
            break;
        }
    }
    for(auto& i:arranged_by_symbol)
    {
        if(i.size()>=5)
        {
            std::sort(i.begin(),i.end(),[](unsigned a,unsigned b){
                return a>b;
            });
            i.erase(i.begin()+5,i.end());
            return i;
        }            
    }
    return std::nullopt;

}
combinations::combinations(std::array<card,7> hand){
    if(auto var=is_flush(hand);var)
    {
        my_comb=combs::flush;
        characteristic_cards=*var;
        std::cout<<"characteristic cards 0:"<<characteristic_cards[0]<<std::endl;
    }
    else{
    }
}