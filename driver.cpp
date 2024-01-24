// include libraries here (STL not allowed)
#include <iostream>
#include <string>
#include "playlist.h"


int main(int argc, char *argv[]){
    int x;
    x = 6;
    for (int i = 0; x != 15; i++)
    {
        x+=5;
        std::cout << "Iteration number =" << i << std::endl;
    }
    
    std::cout <<"Done:\n";

}