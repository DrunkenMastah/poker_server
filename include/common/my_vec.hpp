#pragma once 
#include <iostream>
struct data{
    int x;
    int y;
    int z;
    friend std::ostream& operator>>(std::ostream& stream,data d){
        int checksum=x+y+z;
        stream<<d.x<<':'<<d.y<<':'<<d.z<<':'<<checksum;
        return stream;
    }
    bool read(std::istream& stream,data& d){
        //...//checksum=read 4 arithmo
        if(d.x+d.y+d.z==checksum)
            return true;
        else false;
    }
}