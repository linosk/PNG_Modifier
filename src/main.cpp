#include "png_place_holder.h"

#include <iostream>

int main(int argc, char** argv){

    if (argc!=2){
        std::cout<<"Run ./png_modifier [file.png]"<<std::endl;
        exit(0);
    }

    /*
    Program received signal SIGSEGV, Segmentation fault.
    0x0000555555558755 in PNG_copy (Copy=std::vector of length 176, capacity 176 = {...}, Beg=8 '\b', Range=4 '\004', Copy_to=std::vector of length 0, capacity 0)
    at /home/me/Projects/PNG_Modifier/src/png_chunk.cpp:56
    (gdb) n
    */

    PNG_place_holder PNG;
    PNG.PNG_get_bytes(argv[1]);
    PNG.IHDR.PNG_get_chunk(PNG.PNG_file, PNG.IHDR_header, "IHDR", PNG.Pointer);

    return 0;
}