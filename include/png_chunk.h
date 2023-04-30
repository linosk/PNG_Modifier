#ifndef __PNG_CHUNK__
#define __PNG_CHUNK__

#include <cstdint>
#include <string>

#define BYTE_SIZE 8
#define CHUNK_SIZE 4

typedef unsigned char PNG_byte;

class PNG_chunk{
    private:
        PNG_byte Data_length_bytes[CHUNK_SIZE];
        uint32_t Data_length;
        PNG_byte Type_bytes[CHUNK_SIZE];
        PNG_byte* Chunk_data;
        PNG_byte CRC_bytes[CHUNK_SIZE];
    public:
        void PNG_get_chunk(PNG_byte* PNG_file, PNG_byte* PNG_chunk_header, std::string PNG_header_name, size_t &Counter);
};

bool PNG_compare(PNG_byte* Compare, uint8_t Beg, uint8_t Range, PNG_byte* Compare_to);

//Copy from one PNG_byte array to the other in given range
void PNG_copy(PNG_byte* Copy, uint8_t Beg, uint8_t Range, PNG_byte* Copy_to);

#endif