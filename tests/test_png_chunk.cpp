#include <gtest/gtest.h>

#include "png_chunk.h"

TEST(Test_PNG_chunk,PNG_compare){

    std::vector<PNG_byte> Array_one = {'a','b','c','d'};
    std::vector<PNG_byte> Array_two = {97,98,99,100};
    std::vector<PNG_byte> Array_three = {0,0,0,0,97,98,99,100};

    EXPECT_TRUE(PNG_compare(Array_two,0,CHUNK_SIZE,Array_one));
    EXPECT_TRUE(PNG_compare(Array_three,CHUNK_SIZE,CHUNK_SIZE,Array_one));
}

TEST(Test_PNG_chunk,PNG_copy){
    std::vector<PNG_byte> Array_one;
    std::vector<PNG_byte> Array_two = {'a','b','c','d'};
    std::vector<PNG_byte> Array_three;
    std::vector<PNG_byte> Array_four = {0,0,0,0,97,98,99,100};

    PNG_copy(Array_two,0,CHUNK_SIZE,Array_one);
    PNG_copy(Array_four,CHUNK_SIZE,CHUNK_SIZE,Array_three);

    EXPECT_TRUE(PNG_compare(Array_two,0,CHUNK_SIZE,Array_one));
    EXPECT_TRUE(PNG_compare(Array_four,CHUNK_SIZE,CHUNK_SIZE,Array_three));
}

TEST(Test_PNG_chunk,PNG_sum_chunks){

    std::vector<PNG_byte> Array_one = {0x0,0x0,0x0,0xff};
    int Array_one_length = PNG_sum_chunks(Array_one);

    std::vector<PNG_byte>  Array_two = {0x0,0x0,0xff,0xff};
    int Array_two_length = PNG_sum_chunks(Array_two);

    std::vector<PNG_byte>  Array_three = {0x0,0xff,0xff,0xff};
    int Array_three_length = PNG_sum_chunks(Array_three);

    std::vector<PNG_byte>  Array_four = {0xff,0xff,0xff,0xff};
    int Array_four_length = PNG_sum_chunks(Array_four);

    EXPECT_EQ(Array_one_length,0xff);
    EXPECT_EQ(Array_two_length,0xffff);
    EXPECT_EQ(Array_three_length,0xffffff);
    EXPECT_EQ(Array_four_length,0xffffffff);
}