#include <iostream>

#include "png_chunk.h"

PNG_chunk::PNG_chunk(
                    PNG_byte* Data_length_bytes,
                    int Data_length,
                    PNG_byte* Type,
                    PNG_byte* Chunk_data,
                    PNG_byte* CRC_bytes
                    ){
    //function to copy from PNG_file to singular chunks
    Data_length = Sum_chunks(Data_length_bytes, STANDARD_CHUNK_PART_SIZE);
}

u_int32_t Sum_chunks(PNG_byte* Data_length_bytes, int Length){
    u_int32_t Data_length = 0x0;
    uint8_t Power = Length - 1;
    for(uint8_t i=0;i<Length;i++){
        Data_length += Data_length_bytes[i]*pow(0x100,Power);
        Power--;
    }

    return Data_length;
}