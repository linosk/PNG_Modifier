#include "png_chunk.h"

void PNG_chunk::PNG_get_chunk(PNG_byte* PNG_file, PNG_byte* PNG_chunk_header, std::string PNG_header_name, size_t &Counter){
    //TODO
}

void PNG_copy(PNG_byte* Copy, uint8_t Beg, uint8_t Range, PNG_byte* Copy_to){
    for(uint8_t i = 0; i<Range; i++){
        Copy_to[i] = static_cast<unsigned char>(Copy[Beg+i]);
    }
}