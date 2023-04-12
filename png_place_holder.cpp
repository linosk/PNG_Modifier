#include <iostream>
#include <filesystem>
#include <fstream>
//#include <algorithm>
//#include <iterator>

#include "png_place_holder.h"

void PNG_Place_Holder::PNG_Get_Bytes(std::string File_name){
    size_t Size;

    if(std::filesystem::exists(File_name)){
        std::ifstream File(File_name);
        File.seekg(0,std::ios::end);
        Size = File.tellg();
        File.seekg(0,std::ios::beg);
        PNG_File = new PNG_Byte[Size];
        File.read(reinterpret_cast<char*>(PNG_File),Size);
        File.close();

        //for(size_t i = 0;i<Size;i++){
        //    std::cout<<static_cast<int>(static_cast<unsigned char>(PNG_File[i]))<<" ";
        //}
        //std::cout<<std::endl;

        PNG_Byte Signature[SIGNATURE_BLOCK_SIZE] = {137,80,78,71,13,10,26,10};

        if (std::equal(std::begin(CORRECT_PNG_SIGNATURE),std::end(CORRECT_PNG_SIGNATURE),reinterpret_cast<int*>(std::begin(Signature)))){
            std::cout<<"This is a PNG file"<<std::endl;
        }
        else{
            std::cerr<<"This is not a PNG file"<<std::endl;
            delete PNG_File;
            exit(1);
        }
        
    }
    else{
        std::cerr<<"File "+File_name+" does not exist."<<std::endl;
        exit(1);
    }
}

//PNG_Place_Holder::PNG_Place_Holder(){
//
//}