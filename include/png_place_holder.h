#ifndef __PNG_PLACE_HOLDER__
#define __PNG_PLACE_HOLDER__

#include "png_chunk.h"

class PNG_place_holder{
    private:
        size_t Size;

    public:
        //Maybe change it later to private
        //PNG_byte Correct_signature[BYTE_SIZE] = {137,80,78,71,13,10,26,10};
        //PNG_byte IHDR_header[BYTE_SIZE] = {'I','H','D','R'};
        //PNG_byte* PNG_file;
        //size_t Pointer;
        //void PNG_get_bytes(std::string File_name);
        //PNG_chunk IHDR;

        PNG_array Correct_signature = {137,80,78,71,13,10,26,10};
        PNG_array IHDR_header = {'I','H','D','R'};
        PNG_array PNG_file{};
        size_t Pointer;
        void PNG_get_bytes(std::string File_name);
        PNG_chunk IHDR;

};

#endif