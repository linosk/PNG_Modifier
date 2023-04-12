#ifndef __PNG_PLACE_HOLDER__
#define __PNG_PLACE_HOLDER__

#include <string>

#include "png_chunk.h"

//This class will consist of every byte of into .png file
class PNG_Place_Holder{
    public:
        PNG_Byte* PNG_File;
        void PNG_Get_Bytes(std::string File_name);
};

#endif //__PNG_PLACE_HOLDER__