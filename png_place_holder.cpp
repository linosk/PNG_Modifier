#include <iostream>
#include <filesystem>
#include <fstream>

#include "png_place_holder.h"

void PNG_Place_Holder::PNG_Get_Bytes(std::string File_name){

    size_t Size;

    if(std::filesystem::exists(File_name)){
        // Maybe there should be another check whether the png.file is actually png
        std::ifstream File(File_name);
        File.seekg(0,std::ios::end);
        Size = File.tellg();
        File.seekg(0,std::ios::beg);
        PNG_File = new PNG_Byte[Size];
        File.read(reinterpret_cast<char*>(PNG_File),Size);
        File.close();

        //This should be in header
        PNG_Byte Correct_Signature[SIGNATURE_BLOCK_SIZE] = {137,80,78,71,13,10,26,10};

        //Is loop ok?
        for(uint8_t i = 0; i<SIGNATURE_BLOCK_SIZE; i++){
            if(Correct_Signature[i]!=PNG_File[i]){
                std::cerr<<File_name+" is not correct .png file, incorrect."<<std::endl;
                delete PNG_File;
                exit(1);
            }

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