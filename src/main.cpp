#include "png_place_holder.h"

#include <iostream>

int main(int argc, char** argv){

    //PNG_chunk P;
    //Use \n instead of std::endl becasues the latter also flushes
    //std::cout<<"A"<<"\n";

    if (argc!=2){
        std::cout<<"Run ./png_modifier [file.png]"<<std::endl;
        exit(0);
    }

    PNG_place_holder PNG;
    PNG.PNG_get_bytes(argv[1]);
    PNG.IHDR.PNG_get_chunk(PNG.PNG_file, PNG.IHDR_header, "IHDR", PNG.Pointer);

    return 0;
}