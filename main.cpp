#include <fstream>
#include <iostream>
#include <string>

typedef unsigned char PNG_byte;
#define BLOCK_SIZE 8
PNG_byte Correct_signature[BLOCK_SIZE] = {137,80,78,71,13,10,26,10};

int main(int argc, char** argv){

    //Later the filename can be passed as an argument

    std::ifstream File("block.png");

    if(!File){
        std::cerr<<"Error"<<std::endl;
        return -1;
    }

    File.seekg(0,std::ios::end);
    int Size = File.tellg();
    File.seekg(0,std::ios::beg);

    PNG_byte Signature[BLOCK_SIZE];
    //char Signature[BLOCK_SIZE];

    //while (File.get(byte))
    //{s
    //    std::cout << static_cast<int>(static_cast<unsigned char>(byte))<<" ";
    //}

    File.read(reinterpret_cast<char*>(Signature),BLOCK_SIZE);

    //THIS BELOW CAN BE USED AS A FUNCTION TO PRINT ANY BUFFER

    //for(int i=0;i<BLOCK_SIZE;i++){
    //    std::cout<<static_cast<int>(static_cast<unsigned char>(Signature[i]))<<" ";
    //}
    //std::cout<<std::endl;

    if(std::equal(std::begin(Signature),std::end(Signature),std::begin(Correct_signature))){
        std::cout<<"It is a correct PNG file."<<std::endl;
    }

    File.close();

    return 0;
}