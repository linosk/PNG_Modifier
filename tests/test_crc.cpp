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

TEST(TEST_crc, To_binary){

    crc::Bin_arr Binary_two{};
    crc::Bin_arr Binary_two_compare = {1,0,0,1,0,0,1,0};
    Binary_two.resize(Binary_two_compare.size());
    crc::To_binary(73,0,Binary_two);
    EXPECT_TRUE(crc::Compare_binaries(Binary_two,Binary_two_compare,BYTE_SIZE));

    crc::Bin_arr Binary_three{};
    crc::Bin_arr Binary_three_compare = {0,0,0,0,1,1,1,1,0,0,0,1,0,0,0,0};
    Binary_three.resize(Binary_three_compare.size());
    crc::To_binary(2288,0,Binary_three);
    EXPECT_TRUE(crc::Compare_binaries(Binary_three,Binary_three_compare,BYTE_SIZE));

}

TEST(TEST_crc, Reverse_binary){

    crc::Bin_arr Binary_one = {1,0,1,0,0,0,0,0};
    crc::Bin_arr Binary_two = {0,0,0,0,0,1,0,1};

    crc::Reverse_binary(Binary_one);

    EXPECT_TRUE(crc::Compare_binaries(Binary_one,Binary_two,BYTE_SIZE));

}

TEST(TEST_crc, Add_zeros){

    crc::Bin_arr Binary_one = {1,1,1,1,0,0,0,0};
    crc::Bin_arr Binary_two = {0,0,0,0,1,1,1,1,0,0,0,0};

    crc::Add_zeros(Binary_one,BYTE_SIZE/2);

    EXPECT_TRUE(crc::Compare_binaries(Binary_one,Binary_two,BYTE_SIZE+BYTE_SIZE/2));

}

TEST(TEST_crc, Flip_binary){

    crc::Bin_arr Binary_one = {1,1,1,1,0,0,0,0};
    crc::Bin_arr Binary_two = {0,0,0,0,1,1,1,1};

    crc::Bin_arr Binary_three = {0,0,1,1,0,1,1,0};
    crc::Bin_arr Binary_four =  {0,0,0,0,1,0,0,1};

    crc::Flip_binary(Binary_one,0,Binary_one.size());
    crc::Flip_binary(Binary_three,BYTE_SIZE/4,Binary_three.size());

    EXPECT_TRUE(crc::Compare_binaries(Binary_one,Binary_two,BYTE_SIZE));
    EXPECT_TRUE(crc::Compare_binaries(Binary_three,Binary_four,BYTE_SIZE));
}

TEST(TEST_crc, CRC){

    crc::Bin_arr Data = {1,0,1,1,0,1,1,1,0,0,0,0};
    crc::Bin_arr Poly = {1,1,0,1};
    
    crc::Bin_arr Rem = crc::CRC(Data,Poly);
    
    crc::Bin_arr Rem_compare = {0,1,1};
    
    EXPECT_TRUE(crc::Compare_binaries(Rem,Rem_compare,Poly.size()-1));

}