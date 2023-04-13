#include <iostream>

#include "png_place_holder.h"

int main(int argc, char** argv){

    if (argc!=2){
        std::cout<<"Run ./png_modifier [file.png]"<<std::endl;
        exit(0);
    }

    PNG_place_holder PNG;
    PNG.PNG_get_bytes(argv[1]);

    return 0;
}