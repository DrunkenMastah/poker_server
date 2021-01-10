#pragma  once
#include <array>
#include <vector>

#include <common/card.hpp>

class combinations{
    public:

    combinations(std::array<card,7> hand);
    friend bool operator< (const combinations &one, const combinations &two);
    friend bool operator==(const combinations &one, const combinations &two);
    friend bool operator> (const combinations &one, const combinations &two);
    friend bool operator<=(const combinations &one, const combinations &two);
    friend bool operator>=(const combinations &one, const combinations &two);
    private:
    enum class combs{
        flush,
        full_house,
        four_of_a_kind,
        straight_flush,
        flush_royal,
    };
    combs my_comb;
    std::vector<unsigned> characteristic_cards;
};