#include "png_chunk.h"

void PNG_chunk::PNG_get_chunk(PNG_byte* PNG_file, PNG_byte* PNG_chunk_header, std::string PNG_header_name, size_t &Counter){
    //TODO
}

//Change the std::string File_name to something different
//Write a test
//Maybe templetize it
bool PNG_compare(PNG_byte* Compare, uint8_t Beg, uint8_t Range, PNG_byte* Compare_to){
    for(uint8_t i = 0; i<Range; i++){
        //if(static_cast<unsigned char>(Compare[Beg+i])!=static_cast<unsigned char>(Compare_to[i]))
        if(Compare[Beg+i]!=Compare_to[i])
            return false;
    }
    return true;
}

void PNG_copy(PNG_byte* Copy, uint8_t Beg, uint8_t Range, PNG_byte* Copy_to){
    for(uint8_t i = 0; i<Range; i++){
        Copy_to[i] = static_cast<unsigned char>(Copy[Beg+i]);
    }
}