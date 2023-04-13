#ifndef __PNG_PLACE_HOLDER__
#define __PNG_PLACE_HOLDER__

#include <string>

#include "png_chunk.h"

//This class will consist of every byte of into .png file
class PNG_place_holder{
    public:
        PNG_byte* PNG_file;
        void PNG_get_bytes(std::string File_name);
        void PNG_get_chunk(PNG_chunk Chunk);
};

#endif //__PNG_PLACE_HOLDER__