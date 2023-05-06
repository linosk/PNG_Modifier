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

class PNG_chunk{
    private:
        //PNG_byte Data_length_bytes[CHUNK_SIZE];
        //PNG_byte Type_bytes[CHUNK_SIZE];
        //PNG_byte* Chunk_data;
        //PNG_byte CRC_bytes[CHUNK_SIZE];
        std::vector<PNG_byte> Data_length_bytes{};
        uint32_t Data_length;
        std::vector<PNG_byte> Type_bytes{};
        std::vector<PNG_byte> Chunk_data{};
        std::vector<PNG_byte> CRC_bytes{};
    public:
        //void PNG_get_chunk(PNG_byte* PNG_file, PNG_byte* PNG_chunk_header, std::string PNG_header_name, size_t &Counter);
        void PNG_get_chunk(std::vector<PNG_byte> PNG_file, const std::vector<PNG_byte> PNG_chunk_header, std::string PNG_header_name, size_t &Counter);
};

//void PNG_print(PNG_byte* Array, uint8_t Size);
void PNG_print(const std::vector<PNG_byte> Array);

//bool PNG_compare(PNG_byte* Compare, uint8_t Beg, uint8_t Range, PNG_byte* Compare_to);
bool PNG_compare(const std::vector<PNG_byte> Compare, uint8_t Beg, uint8_t Range, const std::vector<PNG_byte> Compare_to);

//Copy from one PNG_byte array to the other in given range
void PNG_copy(const std::vector<PNG_byte> Copy, uint8_t Beg, uint8_t Range, std::vector<PNG_byte> &Copy_to);

u_int32_t PNG_sum_chunks(const std::vector<PNG_byte> Data_length_bytes);

#endif