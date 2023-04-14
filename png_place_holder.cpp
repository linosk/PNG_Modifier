#include <iostream>
#include <filesystem>
#include <fstream>

#include "png_place_holder.h"

void PNG_place_holder::PNG_get_bytes(std::string File_name){

    if(std::filesystem::exists(File_name)){
        // Maybe there should be another check whether the png.file is actually png
        std::ifstream File(File_name);
        File.seekg(0,std::ios::end);
        Size = File.tellg();
        Pointer = 0;
        File.seekg(0,std::ios::beg);
        PNG_file = new PNG_byte[Size];
        File.read(reinterpret_cast<char*>(PNG_file),Size);
        File.close();

        //This should be in header
        PNG_byte Correct_signature[SIGNATURE_BLOCK_SIZE] = {137,80,78,71,13,10,26,10};

        //Is loop ok?
        for(uint8_t i = 0; i<SIGNATURE_BLOCK_SIZE; i++){
            if(Correct_signature[i]!=PNG_file[i]){
                std::cerr<<File_name+" is not correct .png file, incorrect."<<std::endl;
                delete PNG_file;
                exit(1);
            }

        }

        //If program still runs move pointer by the length of signature
        Pointer+= SIGNATURE_BLOCK_SIZE;

    }
    else{
        std::cerr<<"File "+File_name+" does not exist."<<std::endl;
        exit(1);
    }


}

void PNG_place_holder::PNG_assign_bytes(){
    
}


//PNG_Place_Holder::PNG_Place_Holder(){
//
//}