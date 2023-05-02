#include "png_place_holder.h"

#include <filesystem>
#include <fstream>

void PNG_place_holder::PNG_get_bytes(std::string File_name){
    // Maybe there should be another check whether the png.file is actually png
    // Remember that std::filesystem requires -std=c++17 and c_cpp_properties.json
    if(std::filesystem::exists(File_name)){
        std::ifstream File(File_name);
        File.seekg(0,std::ios::end);
        Size = File.tellg();
        Pointer = 0;
        File.seekg(0,std::ios::beg);
        PNG_file = new PNG_byte[Size];
        File.read(reinterpret_cast<char*>(PNG_file),Size);
        File.close();

        if(!PNG_compare(PNG_file,0,BYTE_SIZE,Correct_signature)){
            std::cerr<<File_name+" is not correct .png file, incorrect signature."<<std::endl;
            delete PNG_file;
            exit(1);
        }

        Pointer+= BYTE_SIZE;

    }

    else{
        std::cerr<<"File "+File_name+" does not exist."<<std::endl;
        exit(1);
    }
}