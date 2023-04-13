#ifndef __PNG_H__
#define __PNG_H__

#include <cstdint>
#include <cmath>

//namespace png{

    typedef unsigned char PNG_byte;

    #define SIGNATURE_BLOCK_SIZE 8
    #define STANDARD_CHUNK_PART_SIZE 4

    class PNG_chunk{
            public:
                PNG_byte Data_length_bytes[STANDARD_CHUNK_PART_SIZE];
                int Data_length;
                PNG_byte Type_bytes[STANDARD_CHUNK_PART_SIZE];
                PNG_byte* Chunk_data;
                PNG_byte CRC_bytes[STANDARD_CHUNK_PART_SIZE];

                PNG_chunk(
                    PNG_byte* Data_length_bytes,
                    int Data_length,
                    PNG_byte* Type,
                    PNG_byte* Chunk_data,
                    PNG_byte* CRC_bytes
                    );

                u_int32_t Sum_chunks(PNG_byte* Data_length_bytes, int Length){u_int32_t Data_length;};
                void Print_values(PNG_byte* Array, int Length);
            };

    //maybe use templates later

//}

#endif