#include <gtest/gtest.h>

#include "png_chunk.h"

TEST(Test_Sum_chunks, Subtest){

    PNG_Byte Array_one[STANDARD_CHUNK_PART_SIZE] = {0x0,0x0,0x0,0xff};
    int Array_one_length = Sum_chunks(Array_one,STANDARD_CHUNK_PART_SIZE);

    PNG_Byte Array_two[STANDARD_CHUNK_PART_SIZE] = {0x0,0x0,0xff,0xff};
    int Array_two_length = Sum_chunks(Array_two,STANDARD_CHUNK_PART_SIZE);

    PNG_Byte Array_three[STANDARD_CHUNK_PART_SIZE] = {0x0,0xff,0xff,0xff};
    int Array_three_length = Sum_chunks(Array_three,STANDARD_CHUNK_PART_SIZE);

    PNG_Byte Array_four[STANDARD_CHUNK_PART_SIZE] = {0xff,0xff,0xff,0xff};
    int Array_four_length = Sum_chunks(Array_four,STANDARD_CHUNK_PART_SIZE);

    EXPECT_EQ(Array_one_length,0xff);
    EXPECT_EQ(Array_two_length,0xffff);
    EXPECT_EQ(Array_three_length,0xffffff);
    ASSERT_EQ(Array_four_length,0xffffffff);
}

int main(int argc, char** argv){

    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}