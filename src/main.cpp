#include "png_place_holder.h"

#include <iostream>

int main(int argc, char** argv){

    if (argc!=2){
        std::cout<<"Run ./png_modifier [file.png]"<<"\n";
        exit(0);
    }

    PNG_place_holder PNG;
    PNG.PNG_get_bytes(argv[1]);
    PNG.IHDR.PNG_get_chunk(PNG.PNG_file, PNG.IHDR_header, "IHDR", PNG.Pointer);

    crc::Bin_arr A = {1,0,1};
    crc::Print_binary(A);

    crc::Bin_arr Binary_three{};
    crc::Bin_arr Binary_three_compare = {0,0,0,0,1,1,1,1,0,0,0,1,0,0,0,0};
    crc::To_binary(2288,1,Binary_three);

    crc::Print_binary(Binary_three);
    crc::Print_binary(Binary_three_compare);

    return 0;
}