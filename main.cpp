#include <fstream>
#include <iostream>
#include <string>

typedef unsigned char PNG_Byte;
#define SIGNATURE_BLOCK_SIZE 8
#define STANDARD_CHUNK_PART_SIZE 4
PNG_Byte Correct_signature[SIGNATURE_BLOCK_SIZE] = {137,80,78,71,13,10,26,10};

class PNG_Chunk{
    public:
        PNG_Byte Data_length_bytes[STANDARD_CHUNK_PART_SIZE];
        int Data_length;
        PNG_Byte Type_bytes[STANDARD_CHUNK_PART_SIZE];

};

int Sum_chunks(PNG_Byte* Data_length_bytes, int Length){
    int Data_length = 0;
    for(int i=0;i<Length;i++){
        Data_length += Data_length_bytes[i];
    }
    return Data_length;
}

template <typename T>
void Print_values(T Array,int Length){
    for(int i=0;i<Length;i++){
        std::cout<<static_cast<int>(static_cast<unsigned char>(Array[i]))<<" ";
    }
    std::cout<<std::endl;
}

//void Print_values(){
//    
//}

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

    return 0;
}