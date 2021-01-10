#pragma once

#include <utility>
enum class symbols{
    clubs,
    spades,
    diamond,
    hearts
};
using card=std::pair<symbols,unsigned>;
