#include <iostream>

#include "png_chunk.h"

int main(int argc, char** argv){

    PNG_Byte A[STANDARD_CHUNK_PART_SIZE] = {0xff,0xff,0xff,0xff};
    //Print_values(A,STANDARD_CHUNK_PART_SIZE);

    //std::cout<<A[3]+A[2]+A[1]*0xff+A[0]<<std::endl;

    std::cout<<static_cast<unsigned int>(A[0]*pow(0x100,0))<<std::endl;
    std::cout<<static_cast<unsigned int>(A[1]*pow(0x100,1))<<std::endl;
    std::cout<<static_cast<unsigned int>(A[2]*pow(0x100,2))<<std::endl;
    std::cout<<static_cast<unsigned int>(A[3]*pow(0x100,3))<<std::endl;

/*
    //Later the filename can be passed as an argument

    std::ifstream File("block.png");

    if(!File){
        std::cerr<<"Error"<<std::endl;
        return -1;
    }

    File.seekg(0,std::ios::end);
    int Size = File.tellg();
    File.seekg(0,std::ios::beg);

    PNG_Byte Signature[SIGNATURE_BLOCK_SIZE];

    //Read moves file pointer by BLOCK_SIZE value
    //Size = Size - BLOCK_SIZE;
    File.read(reinterpret_cast<char*>(Signature),SIGNATURE_BLOCK_SIZE);

    if(std::equal(std::begin(Signature),std::end(Signature),std::begin(Correct_signature))){
        std::cout<<"It is a correct PNG file."<<std::endl;
    }

    PNG_Chunk Image_header_chunk;
    File.read(reinterpret_cast<char*>(Image_header_chunk.Data_length_bytes),STANDARD_CHUNK_PART_SIZE);

    Print_values(Signature,SIGNATURE_BLOCK_SIZE);
    Print_values(Image_header_chunk.Data_length_bytes,STANDARD_CHUNK_PART_SIZE);

    Image_header_chunk.Data_length = Sum_chunks(Image_header_chunk.Data_length_bytes,STANDARD_CHUNK_PART_SIZE);
    std::cout<<Image_header_chunk.Data_length<<std::endl;

    File.close();
    */

    return 0;
}