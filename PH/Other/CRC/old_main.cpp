#include <iostream>

#include <string>

#include <algorithm>

#include <cmath>

#include <cstring>

#define HEX_LENGTH 16

/*
73 72 68 82 
0 0 0 13 0 0 0 13 8 2 0 0 0 
253 137 115 43
FD 89 73 2B
*/

char A[4] = {73, 72, 68, 82};
char B[13] = {0,0,0,13,0,0,0,13,8,2,0,0,0}; 

//char table_base[HEX_LENGTH] = {0x0,0x1,0x2,0x3,0x4,0x5,0x6,0x7,0x8,0x9,0xA,0xB,0xC,0xD,0xE,0xF};

unsigned char bits_base[HEX_LENGTH][HEX_LENGTH/4] = 
{
    {'0','0','0','0'},
    {'0','0','0','1'},
    {'0','0','1','0'},
    {'0','0','1','1'},
    {'0','1','0','0'},
    {'0','1','0','1'},
    {'0','1','1','0'},
    {'0','1','1','1'},
    {'1','0','0','0'},
    {'1','0','0','1'},
    {'1','0','1','0'},
    {'1','0','1','1'},
    {'1','1','0','0'},
    {'1','1','0','1'},
    {'1','1','1','0'},
    {'1','1','1','1'}
};

//char table_flip[HEX_LENGTH] = {0xF,0xE,0xD,0xC,0xB,0xA,0x9,0x8,0x7,0x6,0x5,0x4,0x3,0x2,0x1,0x0};

char bits_flip[HEX_LENGTH][HEX_LENGTH/4] = 
{
    {'1','1','1','1'},
    {'1','1','1','0'},
    {'1','1','0','1'},
    {'1','1','0','0'},
    {'1','0','1','1'},
    {'1','0','1','0'},
    {'1','0','0','1'},
    {'1','0','0','0'},
    {'0','1','1','1'},
    {'0','1','1','0'},
    {'0','1','0','1'},
    {'0','1','0','0'},
    {'0','0','1','1'},
    {'0','0','1','0'},
    {'0','0','0','1'},
    {'0','0','0','0'}
};

std::string to_binary(uint8_t number){
    std::string binary = "";

    while (number)
    {
        if(number%2)
            binary += '1';
        else
            binary += '0';
        number=number/2;
    }

    if(binary.length()!=8)
    {
        //std::cout<<binary.length()<<std::endl;
        int Val = 8 - binary.length();
        for(int i=0;i<Val;i++)
            binary+='0';
    }

    std::reverse(binary.begin(),binary.end());

    return binary;
}

void append_with_zeros(std::string &Str, uint8_t Zeros){
    for(int i=0;i<Zeros;i++){
        Str+='0';
    }
}

uint8_t to_decimal(std::string string){
    uint8_t number = 0;

    std::reverse(string.begin(),string.end());

    for(int i = string.length()-1;i>=0;i--){
        if(string[i]=='1')
            number+=pow(2,i);
    }

    return number;
}

//CHECK
std::string CRC(std::string Data, std::string Polyniomal){
    std::string Remainder = "";

    int Length = Data.length();
    //Length of data - 3 is experminatal achieved value
    int Length_for_loop = Length - 3;
    std::cout<<Length<<std::endl;
    int Remainder_length = Polyniomal.length() - 1;
    std::cout<<Remainder_length<<std::endl;
    std::string Copy;
    std::strcpy(Copy,Data);

    for(int i=0;i<Length_for_loop;i++){
        if (Copy[i] = '1'){
            for(int j=0;j<Polyniomal.length();j++){
                    if(Copy[i+j]!=Polyniomal[j])
                        Copy[i+j] = '1';
                    else
                        Copy[i+j] = '0';
                }
            }
        }

    int xd;
    for(int k=0;k<Remainder_length;k++){
        xd = k + Length - Remainder_length;
        std::cout<<xd<<" ";
        std::cout<<Copy[xd];
        Remainder+= Copy[k+Length-Remainder_length];
    }

    return Remainder;
}

std::string Prepare(char* A, char* B, int Len_A, int Len_B){

    std::string New = "";

    for(int i=0;i<Len_A;i++){
        New+=to_binary(static_cast<int>(A[i]));
    }

    for(int i=0;i<Len_B;i++){
        New+=to_binary(static_cast<int>(B[i]));
    }

    append_with_zeros(New,32);

    //https://stackoverflow.com/questions/2587766/how-is-a-crc32-checksum-calculated

    return New;
}

void Flip(char* A,int Len_A, int How_many){

    if (How_many>Len_A)
        std::cerr<<"ERROR"<<std::endl;
        
    else{
        for(int i=0;i<How_many;i++){
            if(A[i] == '0')
                A[i] = '1';
            else
                A[i] = '0';
        }
    }
}

int main(int argc, char** argv){

    std::string str = to_binary(10);

    std::cout<<str<<std::endl;
    //std::cout<<str.length()<<std::endl;

    uint8_t number = to_decimal(str);
    //std::cout<<static_cast<int>(number)<<std::endl;

    std::string We = Prepare(A,B,4,13);
    int We_length = We.length();
    char We_char[We_length];
    std::strcpy(We_char,We.c_str());

    int ddd = 40;

    //for(int i=0;i<ddd;i++)
    //    std::cout<<We_char[i]<<" ";
    //std::cout<<std::endl;

    Flip(We_char,We_length,32);

    //for(int i=0;i<ddd;i++)
    //    std::cout<<We_char[i]<<" ";
    //std::cout<<std::endl;

    std::string Data(We_char,We_length);

    std::string Poly = "100000100110000010001110110110111";

    std::cout<<Data.length()<<std::endl;
    std::cout<<Poly.length()<<std::endl;

    std::string REM = CRC(We_char,Poly);

    //char strd[3] = {'1','0','1'};
    //std::string strd = "101";
    //char strf[3];
    //std::strcpy(strf,strd.c_str());
//
    //std::cout<<strf<<std::endl;
    //Flip(strf,3,2);
    //std::cout<<strf<<std::endl;

    //std::string A = "101101110000";
    //std::string B = "1101";
    //std::string rem = CRC(A,B);
    //std::cout<<rem<<std::endl;
//
    //std::cout<<B<<std::endl;
    //append_with_zeros(B,10);
    //std::cout<<B<<std::endl;

    return 0;
}