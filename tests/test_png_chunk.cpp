#include <gtest/gtest.h>

#include "png_chunk.h"

TEST(Test_PNG_chunk,PNG_compare){

    PNG_array Array_one = {'a','b','c','d'};
    PNG_array Array_two = {97,98,99,100};
    PNG_array Array_three = {0,0,0,0,97,98,99,100};

    EXPECT_TRUE(PNG_compare(Array_two,0,CHUNK_SIZE,Array_one));
    EXPECT_TRUE(PNG_compare(Array_three,CHUNK_SIZE,CHUNK_SIZE,Array_one));
}

TEST(Test_PNG_chunk,PNG_copy){
    PNG_array Array_one;
    PNG_array Array_two = {'a','b','c','d'};
    PNG_array Array_three;
    PNG_array Array_four = {0,0,0,0,97,98,99,100};

    PNG_copy(Array_two,0,CHUNK_SIZE,Array_one);
    PNG_copy(Array_four,CHUNK_SIZE,CHUNK_SIZE,Array_three);

    EXPECT_TRUE(PNG_compare(Array_two,0,CHUNK_SIZE,Array_one));
    EXPECT_TRUE(PNG_compare(Array_four,CHUNK_SIZE,CHUNK_SIZE,Array_three));
}

TEST(Test_PNG_chunk,PNG_connect){

    PNG_array Array_one = {'a','b','c'};
    PNG_array Array_two = {'d','e','f','g','h'};
    PNG_array Array_three = {'a','b','c','d','e','f','g','h'};

    PNG_array Array_four = PNG_connect(Array_one,Array_two);

    EXPECT_TRUE(PNG_compare(Array_three,0,BYTE_SIZE,Array_four));

}

TEST(Test_PNG_chunk,PNG_reverse_order){

    PNG_array Array_one = {'a','b','c','d'};
    PNG_array Array_two = {'d','c','b','a'};

    PNG_reverse_order(Array_one);

    EXPECT_TRUE(PNG_compare(Array_one,0,BYTE_SIZE/2,Array_two));

}

TEST(Test_PNG_chunk,PNG_sum_chunks){

    PNG_array Array_one = {0x0,0x0,0x0,0xff};
    int Array_one_length = PNG_sum_chunks(Array_one);

    PNG_array  Array_two = {0x0,0x0,0xff,0xff};
    int Array_two_length = PNG_sum_chunks(Array_two);

    PNG_array  Array_three = {0x0,0xff,0xff,0xff};
    int Array_three_length = PNG_sum_chunks(Array_three);

    PNG_array  Array_four = {0xff,0xff,0xff,0xff};
    int Array_four_length = PNG_sum_chunks(Array_four);

    EXPECT_EQ(Array_one_length,0xff);
    EXPECT_EQ(Array_two_length,0xffff);
    EXPECT_EQ(Array_three_length,0xffffff);
    EXPECT_EQ(Array_four_length,0xffffffff);
}