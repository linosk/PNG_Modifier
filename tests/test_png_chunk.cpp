#include <gtest/gtest.h>

#include "png_chunk.h"

TEST(Test_PNG_copy,test){
    PNG_byte Array_one[CHUNK_SIZE];
    PNG_byte Array_two[CHUNK_SIZE] = {'a','b','c','d'};
    PNG_byte Array_three[CHUNK_SIZE];
    PNG_byte Array_four[2*CHUNK_SIZE] = {0,0,0,0,97,98,99,100};

    PNG_copy(Array_two,0,CHUNK_SIZE,Array_one);
    PNG_copy(Array_four,CHUNK_SIZE,CHUNK_SIZE,Array_three);

    EXPECT_TRUE(PNG_compare(Array_two,0,CHUNK_SIZE,Array_one));
    EXPECT_TRUE(PNG_compare(Array_four,CHUNK_SIZE,CHUNK_SIZE,Array_three));
}