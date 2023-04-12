#ifndef __PNG_H__
#define __PNG_H__

#include <cstdint>
#include <cmath>

//namespace png{

    typedef unsigned char PNG_Byte;

    #define SIGNATURE_BLOCK_SIZE 8
    #define STANDARD_CHUNK_PART_SIZE 4

    class PNG_Chunk{
            public:
                PNG_Byte Data_length_bytes[STANDARD_CHUNK_PART_SIZE];
                int Data_length;
                PNG_Byte Type_bytes[STANDARD_CHUNK_PART_SIZE];
            };

    //maybe use templates later
    u_int32_t Sum_chunks(PNG_Byte* Data_length_bytes, int Length);
    void Print_values(PNG_Byte* Array, int Length);

//}

#endif