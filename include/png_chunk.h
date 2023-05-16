#ifndef __PNG_CHUNK__
#define __PNG_CHUNK__

#include <vector>
#include <iostream>
#include <cstdint>
#include <string> 
#include <cmath>

#define BYTE_SIZE 8
#define CHUNK_SIZE 4

typedef unsigned char PNG_byte;
typedef std::vector<PNG_byte> PNG_array;

class PNG_chunk{
    public:
        //PNG_byte Data_length_bytes[CHUNK_SIZE];
        //PNG_byte Type_bytes[CHUNK_SIZE];
        //PNG_byte* Chunk_data;
        //PNG_byte CRC_bytes[CHUNK_SIZE];
        PNG_array Data_length_bytes{};
        uint32_t Data_length;
        PNG_array Type_bytes{};
        PNG_array Chunk_data{};
        PNG_array CRC_bytes{};
    //public:
        //void PNG_get_chunk(PNG_byte* PNG_file, PNG_byte* PNG_chunk_header, std::string PNG_header_name, size_t &Counter);
        void PNG_get_chunk(PNG_array PNG_file, const PNG_array PNG_chunk_header, std::string PNG_header_name, size_t &Counter);
};

//void PNG_print(PNG_byte* Array, uint8_t Size);
void PNG_print(const PNG_array Array);

//bool PNG_compare(PNG_byte* Compare, uint8_t Beg, uint8_t Range, PNG_byte* Compare_to);
bool PNG_compare(const PNG_array Compare, uint8_t Beg, uint8_t Range, const PNG_array Compare_to);

//Copy from one PNG_byte array to the other in given range
void PNG_copy(const PNG_array Copy, uint8_t Beg, uint8_t Range, PNG_array &Copy_to);

PNG_array PNG_connect(const PNG_array First, const PNG_array Second);

u_int32_t PNG_sum_chunks(const PNG_array Data_length_bytes);

#endif