#ifndef __PNG_PLACE_HOLDER__
#define __PNG_PLACE_HOLDER__

#include "png_chunk.h"
#include "crc.h"

class PNG_place_holder{
    private:
        size_t Size;

    public:

        PNG_place_holder(std::string File_name);

        PNG_array Correct_signature = {137,80,78,71,13,10,26,10};
        PNG_array IHDR_header = {'I','H','D','R'};
        PNG_array PNG_file{};
        size_t Pointer;
        void PNG_get_bytes(std::string File_name);

        //Hash table or linkedlist needed, or just dynamic array of chunks
        PNG_chunk IHDR;
        PNG_chunk n1;
        PNG_chunk n2;
        PNG_chunk n3;
        PNG_chunk n4;
        PNG_chunk n5;

        bool Check_CRC(const PNG_array Type_bytes, const PNG_array Chunk_data, const PNG_array CRC_bytes);
};

#endif