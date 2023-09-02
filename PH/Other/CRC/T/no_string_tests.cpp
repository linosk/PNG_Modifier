#include <gtest/gtest.h>

#include "no_string.h"

class No_string_test : public testing::Test{

    virtual void SetUp(){

    }

    virtual void TearDown(){

    }

};

TEST(No_string_test, Compare_binaries){

    char Binary_one[BYTE_SIZE] = {1,0,0,1,1,0,1,0};
    char Binary_two[BYTE_SIZE] = {1,0,0,1,1,0,1,0};

    EXPECT_TRUE(Compare_binaries(Binary_one,Binary_two,BYTE_SIZE));
}

TEST(No_string_test, Copy_binary){

    char Binary_one[BYTE_SIZE] = {1,1,1,1,0,0,0,0};
    char Binary_two[BYTE_SIZE];

    Copy_binary(Binary_one,Binary_two,BYTE_SIZE,0,0);

    EXPECT_TRUE(Compare_binaries(Binary_one,Binary_two,BYTE_SIZE));

    char Binary_copy_from_one[BYTE_SIZE/2] = {1,1,0,0};
    char Binary_copy_to_one[BYTE_SIZE] = {0,0,0,0,0,0,0,0};
    char Binary_compare_with_one[BYTE_SIZE] = {0,0,0,0,1,1,0,0,};

    Copy_binary(Binary_copy_from_one,Binary_copy_to_one,BYTE_SIZE/2,0,BYTE_SIZE/2);

    EXPECT_TRUE(Compare_binaries(Binary_copy_to_one,Binary_compare_with_one,BYTE_SIZE));

    char Binary_copy_from_two[BYTE_SIZE] = {0,0,1,1,1,1,0,0};
    char Binary_copy_to_two[BYTE_SIZE/2] = {0,0,0,0};
    char Binary_compare_with_two[BYTE_SIZE/2] = {1,1,1,1};

    Copy_binary(Binary_copy_from_two,Binary_copy_to_two,BYTE_SIZE/2,BYTE_SIZE/4,0);

    EXPECT_TRUE(Compare_binaries(Binary_copy_to_two,Binary_compare_with_two,BYTE_SIZE/2));
}

TEST(No_string_test, To_binary){
    
    int Number_one = 46;
    char Binary_one[BYTE_SIZE] = {0,1,1,1,0,1,0,0};
    char Binary_one_answer[BYTE_SIZE];
    To_binary(Binary_one_answer,Number_one,0);

    EXPECT_TRUE(Compare_binaries(Binary_one,Binary_one_answer,BYTE_SIZE));

    int Number_two = 138;
    char Binary_two[BYTE_SIZE] = {0,1,0,1,0,0,0,1};
    char Binary_two_answer[BYTE_SIZE];
    To_binary(Binary_two_answer,Number_two,0);

    EXPECT_TRUE(Compare_binaries(Binary_two,Binary_two_answer,BYTE_SIZE));

    int Number_three = 242;
    char Binary_three[BYTE_SIZE] = {0,1,0,0,1,1,1,1};
    char Binary_three_answer[BYTE_SIZE];
    To_binary(Binary_three_answer,Number_three,0);
    
    EXPECT_TRUE(Compare_binaries(Binary_three,Binary_three_answer,BYTE_SIZE));
}

TEST(No_string_test, To_binary_multiple){

    int Numbers[3] = {1,11,111};
    char Binary[24];

    To_binary_multiple(Binary,Numbers,3);

    char Compare[24] = {1,0,0,0,0,0,0,0,
                        1,1,0,1,0,0,0,0,
                        1,1,1,1,0,1,1,0};

    EXPECT_TRUE(Compare_binaries(Binary,Compare,24));
}

TEST(No_string_test, Add_zeros){
    char Data[BYTE_SIZE/2] = {1,0,1,0};
    char New_data[BYTE_SIZE];

    Add_zeros(Data,BYTE_SIZE/2,BYTE_SIZE/2,New_data);

    char Compare_with[BYTE_SIZE] = {0,0,0,0,1,0,1,0};

    for(int i=0;i<BYTE_SIZE;i++)
        EXPECT_EQ(Compare_with[i],New_data[i]);

}

TEST(No_string_test, To_decimal){

    char Binary_one[BYTE_SIZE] = {1,0,0,1,0,0,0,0};
    uint8_t Number_one = To_decimal(Binary_one);
    uint8_t Number_one_compare = 9;

    EXPECT_EQ(Number_one,Number_one_compare);

    char Binary_two[BYTE_SIZE] = {0,0,1,1,0,1,0,0};
    uint8_t Number_two = To_decimal(Binary_two);
    uint8_t Number_two_compare = 44;

    EXPECT_EQ(Number_two,Number_two_compare);

    char Binary_three[BYTE_SIZE] = {1,1,1,0,1,1,0,1};
    uint8_t Number_three = To_decimal(Binary_three);
    uint8_t Number_three_compare = 183;

    EXPECT_EQ(Number_three,Number_three_compare);

}

TEST(No_string_test, CRC){

    char Data[12] = {1,0,1,1,0,1,1,1,0,0,0,0};
    char Poly[4] = {1,1,0,1};
    char Rem[3];

    CRC(Data,Poly,12,4,Rem,3);

    char Remainder_compare[] = {0,1,1};

    EXPECT_TRUE(Compare_binaries(Remainder_compare,Rem,3));

}

TEST(No_string_test, Flip_binary){

    char A[4] = {1,0,0,1};
    char B[4] = {0,1,1,0};
    Flip_binary(B,4,0);

    EXPECT_TRUE(Compare_binaries(A,B,4));

    char C[4] = {1,1,0,0};
    char D[4] = {1,0,1,0};
    Flip_binary(D,2,1);

    EXPECT_TRUE(Compare_binaries(C,D,4));
}

TEST(No_string_test, Reverse_binary){

    char A[5] = {0,1,1,0,0};
    char B[5] = {0,0,1,1,0};

    Reverse_binary(A,5);

    EXPECT_TRUE(Compare_binaries(A,B,5));

}

int main(int argc, char** argv){

    testing::InitGoogleTest(&argc,argv);

    return RUN_ALL_TESTS();
}