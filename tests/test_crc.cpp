#include <gtest/gtest.h>

#include "crc.h"

TEST(TEST_crc, Compare_binaries){

    crc::Bin_arr Binary_one = {1,0,0,1,1,0,1,0};
    crc::Bin_arr Binary_two = {1,0,0,1,1,0,1,0};

    EXPECT_TRUE(crc::Compare_binaries(Binary_one,Binary_two,BYTE_SIZE));
}

TEST(TEST_crc, Copy_binary){

    crc::Bin_arr Binary_one = {1,1,1,1,0,0,0,0};
    crc::Bin_arr Binary_two;
    Binary_two.resize(BYTE_SIZE);

    crc::Copy_binary(Binary_one,Binary_two,BYTE_SIZE,0,0);

    EXPECT_TRUE(crc::Compare_binaries(Binary_one,Binary_two,BYTE_SIZE));

    crc::Bin_arr Binary_copy_from_one = {1,1,0,0};
    crc::Bin_arr Binary_copy_to_one = {0,0,0,0,0,0,0,0};
    crc::Bin_arr Binary_compare_with_one = {0,0,0,0,1,1,0,0,};

    crc::Copy_binary(Binary_copy_from_one,Binary_copy_to_one,BYTE_SIZE/2,0,BYTE_SIZE/2);

    EXPECT_TRUE(crc::Compare_binaries(Binary_copy_to_one,Binary_compare_with_one,BYTE_SIZE));

    crc::Bin_arr Binary_copy_from_two = {0,0,1,1,1,1,0,0};
    crc::Bin_arr Binary_copy_to_two = {0,0,0,0};
    crc::Bin_arr Binary_compare_with_two = {1,1,1,1};

    crc::Copy_binary(Binary_copy_from_two,Binary_copy_to_two,BYTE_SIZE/2,BYTE_SIZE/4,0);

    EXPECT_TRUE(crc::Compare_binaries(Binary_copy_to_two,Binary_compare_with_two,BYTE_SIZE/2));
}