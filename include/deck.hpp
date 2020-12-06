#pragma once

#include <common/enums.hpp>

#include <array>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <iostream>
#include <optional>

class deck
{
    public:
    deck(){
        std::srand((int)std::time(0));
        shuffle();
    }
    using cards=enums::cards;
    std::optional<cards> spit(){
        static unsigned shuffled_index=0;
        std::cout<<shuffled_index<<std::endl;
        auto ret=static_cast<cards>(shuffled_view[shuffled_index]);
        shuffled_index++ ;
        if(shuffled_index>=shuffled_view.size())
            return std::nullopt;
        else
            return ret ;
    }
    private:
    void shuffle(){
        for(unsigned i=0;i<52;++i)
            shuffled_view[i]=i;
        std::random_shuffle(shuffled_view.begin(),shuffled_view.end());
    }
    //unsigned shuffled_index=0;
    std::array<unsigned,52> shuffled_view{};
    std::array<bool,52> deck_{false};
};