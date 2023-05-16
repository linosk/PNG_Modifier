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
        crc::To_binary(Data[j],i,Binary);
    }

    std::cout<<"----------------------------"<<"\n";

    crc::Reverse_binary(Binary);
    crc::Print_binary(Binary);

std::cout<<"----------------------------"<<"\n";


    crc::Add_zeros(Binary,4*BYTE_SIZE);
    crc::Reverse_binary(Binary);
    crc::Print_binary(Binary);

std::cout<<"----------------------------"<<"\n";


    crc::Flip_binary(Binary,0,4*BYTE_SIZE);
    crc::Print_binary(Binary);

std::cout<<"----------------------------"<<"\n";

    crc::Bin_arr Rem = crc::CRC(Binary,Polyniomal);
    crc::Print_binary(Rem);
    crc::Flip_binary(Rem,0,4*BYTE_SIZE);
    crc::Print_binary(Rem);

    crc::Reverse_binary(Rem);
    crc::Print_binary(Rem);
    crc::Reverse_binary(Rem);

    PNG_array CRC_compare{};
    CRC_compare.resize(CHUNK_SIZE);

    for(int i =0, j=0;i<Data_length*BYTE_SIZE;i+=BYTE_SIZE,j++){
        crc::To_binary(Data[j],i,Binary);
        CRC_compare[j] = crc::To_decimal(i,Rem);
    }

    PNG_print(CRC_compare);

    //Flip_binary has to modified, take look at main.cpp in XD directory, make test for this function and fix test for test_binary - MOSTLY DONE
    //Tests need to be corrected
    //SOMETHING WRON

}