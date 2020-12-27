#pragma once 
namespace server{
    template<class ArrayLikeObject>
    class ring{   
    public:
        ring(ArrayLikeObject & arr):arr_(arr),size_{static_cast<unsigned>(arr.size())}
        {}
        using underlying_t=typename decltype(ArrayLikeObject{})::value_type; 
        void set(underlying_t data){
            arr_[active_player]=data;
        }
        underlying_t get(){
            return arr_[active_player];
        }
        void next(){
            active_player++;
            if(active_player==size_)
                active_player=0;
        }
        unsigned get_active_player()
        {
            return active_player;
        }
        private:
        ArrayLikeObject & arr_;
        unsigned active_player{0};
        const unsigned size_;
    };
}
