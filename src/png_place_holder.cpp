#include "png_place_holder.h"

#include <filesystem>
#include <fstream>

PNG_place_holder::PNG_place_holder(std::string File_name){

    PNG_get_bytes(File_name);
    IHDR.PNG_get_chunk(PNG_file,IHDR_header, "IHDR", Pointer);
    Check_CRC(IHDR.Type_bytes,IHDR.Chunk_data,IHDR.CRC_bytes);
    
}

void PNG_place_holder::PNG_get_bytes(std::string File_name){
    // Maybe there should be another check whether the png.file is actually png
    // Remember that std::filesystem requires -std=c++17 and c_cpp_properties.json
    if(std::filesystem::exists(File_name)){
        std::ifstream File(File_name);
        File.seekg(0,std::ios::end);
        Size = File.tellg();
        Pointer = 0;
        File.seekg(0,std::ios::beg);
        //PNG_file = new PNG_byte[Size];
        //File.read(reinterpret_cast<char*>(PNG_file),Size);
        PNG_file.resize(Size);
        File.read((char*)&PNG_file[0],Size);
        File.close();

        if(!PNG_compare(PNG_file,0,BYTE_SIZE,Correct_signature)){
            std::cerr<<File_name+" is not correct .png file, incorrect signature."<<"\n";
            exit(1);
        }

        Pointer+= BYTE_SIZE;

    }

    else{
        std::cerr<<"File "+File_name+" does not exist."<<"\n";
        exit(1);
    }

}

bool PNG_place_holder::Check_CRC(const PNG_array Type_bytes, const PNG_array Chunk_data, const PNG_array CRC_bytes){

    int Data_length = Type_bytes.size() + Chunk_data.size();
    PNG_array Data = PNG_connect(Type_bytes,Chunk_data);

    PNG_print(Data);

    crc::Bin_arr Polyniomal = {1,0,0,0,0,0,1,0,0,1,1,0,0,0,0,0,1,0,0,0,1,1,1,0,1,1,0,1,1,0,1,1,1};
    
    crc::Bin_arr Binary{};
    Binary.resize(Data_length*BYTE_SIZE);
    for(int i =0, j=0;i<Data_length*BYTE_SIZE;i+=BYTE_SIZE,j++){
        std::cout<<static_cast<unsigned int>(Data[i])<<"\n";
        crc::To_binary(Data[j],i,Binary);
    }

    crc::Print_binary(Binary);

}