#ifndef __PNG_PLACE_HOLDER__
#define __PNG_PLACE_HOLDER__

#include <string>
#include <algorithm>

#include "png_chunk.h"

//This class will consist of every byte of into .png file
class PNG_place_holder{
    private:
        PNG_byte* PNG_file;
        size_t Size;
        size_t Pointer;

    public:
        void PNG_get_bytes(std::string File_name);
        void PNG_compare();
        void PNG_copy();

        PNG_chunk IHDR;
        PNG_chunk PLTE;
        PNG_chunk IDAT;
        PNG_chunk IEND;

        void PNG_assign_bytes();
};

#endif //__PNG_PLACE_HOLDER__