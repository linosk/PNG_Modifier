#include <gtest/gtest.h>

#include "png_place_holder.h"

//this should be done differently
TEST(Test_PNG_place_holder,PNG_get_bytes){
    PNG_place_holder PNG;
    std::string File_name = "block.png";
    PNG.PNG_get_bytes(File_name);
    
    EXPECT_EQ(PNG.Pointer,BYTE_SIZE);
}