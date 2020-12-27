#include <thread>
#include <atomic>
#include <iostream>
#include <variant>
std::atomic<std::variant<int,bool>> x{true}; 
void do_(){
    while(true){
        std::cout<<"lalal"<<std::endl;;
        std::cout<<x.value()<<std::endl;
    }
}

int main(){

    std::thread a(do_);
    a.detach(); 
    while(true){
        std::cout<<"lalal"<<std::endl;
    }
}