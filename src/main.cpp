#include "png_place_holder.h"

#include <iostream>

int main(int argc, char** argv){

    if (argc!=2){
        std::cout<<"Run ./png_modifier [file.png]"<<"\n";
        exit(0);
    }

    PNG_place_holder PNG(argv[1]);

    return 0;
}