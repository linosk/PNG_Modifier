#include <iostream>

#include "png_chunk.h"

//class PNG_Chunk{
//    public:
//        PNG_Byte Data_length_bytes[STANDARD_CHUNK_PART_SIZE];
//        int Data_length;
//        PNG_Byte Type_bytes[STANDARD_CHUNK_PART_SIZE];
//
//};

//PNG_Chunk::PNG_Chunk(){
//    public:
//        PNG_Byte Data_length_bytes[STANDARD_CHUNK_PART_SIZE];
//        int Data_length;
//        PNG_Byte Type_bytes[STANDARD_CHUNK_PART_SIZE];
//}
u_int32_t Sum_chunks(PNG_Byte* Data_length_bytes, int Length){
    u_int32_t Data_length = 0;
    uint8_t Power = 3;

    for(uint8_t i=0;i<Length;i++){
        Data_length += Data_length_bytes[i]*pow(0x100,Power);
        Power--;
    }

    return Data_length;
}

void Print_values(PNG_Byte* Array, int Length){
    for(int i=0;i<Length;i++){
        std::cout<<static_cast<int>(static_cast<unsigned char>(Array[i]))<<" ";
    }
    std::cout<<std::endl;
}