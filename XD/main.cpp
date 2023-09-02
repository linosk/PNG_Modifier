#include "no_string.h"

int main(int argc, char** argv){

    /*
    int D[] = {0x49, 0x48, 0x44, 0x52, 0x00, 0x00, 0x00, 0x0d, 0x00, 0x00, 0x00, 0x0d, 0x08, 0x02, 0x00, 0x00, 0x00};
    int E[] = {73, 72, 68, 82, 0, 0, 0, 13, 0, 0, 0, 13, 8, 2, 0, 0, 0 };

    //Print_binary(reinterpret_cast<char*>(D),17);

    for(int i=0;i<17;i++){
        std::cout<<D[i]<<" ";
    }
    std::cout<<std::endl;

    for(int i=0;i<17;i++){
        std::cout<<E[i]<<" ";
    }
    std::cout<<std::endl;
    //To_binary_multiple - NEEDS MORE WORK!!!!!

    //https://crccalc.com/
    */


    char Binary[4*BYTE_SIZE+13*BYTE_SIZE];

    char Header[4] = {82,68,72,73};
    char Data[13] = {0,0,0,2,8,13,0,0,0,13,0,0,0};

    int Combined[17] = {73, 72, 68, 82, 0, 0, 0, 13, 0, 0, 0, 13, 8, 2, 0, 0, 0 };

    char Poly[33] = {1,0,0,0,0,0,1,0,0,1,1,0,0,0,0,0,1,0,0,0,1,1,1,0,1,1,0,1,1,0,1,1,1};

std::cout<<"----------------------------"<<"\n";

    To_binary_multiple(Binary,Combined,17);
    Reverse_binary(Binary,17*BYTE_SIZE);
    Print_binary(Binary,17*BYTE_SIZE);

std::cout<<"----------------------------"<<"\n";


    char Binary_mod[17*BYTE_SIZE+32];
    Add_zeros(Binary,17*BYTE_SIZE,32,Binary_mod);

    Reverse_binary(Binary_mod,17*BYTE_SIZE+32);
    Print_binary(Binary_mod,17*BYTE_SIZE+32);

std::cout<<"----------------------------"<<"\n";


    Flip_binary(Binary_mod,32,0);
    Print_binary(Binary_mod,17*BYTE_SIZE+32);

std::cout<<"----------------------------"<<"\n";


    char Rem[32];

    CRC(Binary_mod,Poly,17*BYTE_SIZE+32,33,Rem,32);
    Print_binary(Rem,4*BYTE_SIZE);

    Flip_binary(Rem,4*BYTE_SIZE,0);
    Print_binary(Rem,4*BYTE_SIZE);

    Reverse_binary(Rem,4*BYTE_SIZE);
    Print_binary(Rem,4*BYTE_SIZE);

    Reverse_binary(Rem,4*BYTE_SIZE);
    unsigned char Array[4];
    unsigned char Tmp[4];

    for(int i=0;i<4;i++){
        Array[i] = To_decimal(Rem,i*BYTE_SIZE);
    }

    Tmp[3] = Array[0];
    Tmp[2] = Array[1];
    Tmp[1] = Array[2];
    Tmp[0] = Array[3];

    for(int i=0;i<4;i++){
        std::cout<<static_cast<int>(Array[i])<<" ";
    }
    std::cout<<std::endl;

    for(int i=0,j = 3;i<4;i++,j--){
        Array[i] = Tmp[j];
    }

    for(int i=0;i<4;i++){
        std::cout<<static_cast<int>(Tmp[i])<<" ";
    }
    std::cout<<std::endl;

    /*
    //Print_binary(Binary,17*BYTE_SIZE);

    char Mod[17*BYTE_SIZE+32];
    Add_zeros(Binary,17*BYTE_SIZE,32,Mod);

    Print_binary(Mod,17*BYTE_SIZE+32);

    //NOW CRC, BUT CTC WOKRS IN REVERSE ORDER THAN BITS ARE STORED IN ARRAYS

    Reverse_binary(Mod,17*BYTE_SIZE+32);

    Print_binary(Mod,17*BYTE_SIZE+32);

    char Rem[32];

    CRC(Mod,Poly,17*BYTE_SIZE+32,33,Rem,32);

    Print_binary(Rem,32);
    Reverse_binary(Rem,32);
    Print_binary(Rem,32);*/
    

    //https://stackoverflow.com/questions/2587766/how-is-a-crc32-checksum-calculated

    /*
    
    char Poly[33] = {1,0,0,0,0,0,1,0,0,1,1,0,0,0,0,0,1,0,0,0,1,1,1,0,1,1,0,1,1,0,1,1,1};

    int TEST[3] = {97,98,99};

    char Binary[3*BYTE_SIZE];
    To_binary_multiple(Binary,TEST,3);
    Reverse_binary(Binary,3*BYTE_SIZE);
    Print_binary(Binary,3*BYTE_SIZE);

    char Binary_mod[32+3*BYTE_SIZE];
    Add_zeros(Binary,3*BYTE_SIZE,32,Binary_mod);

    Reverse_binary(Binary_mod,3*BYTE_SIZE+32);
    Print_binary(Binary_mod,3*BYTE_SIZE+32);

    Flip_binary(Binary_mod,32,0);
    Print_binary(Binary_mod,3*BYTE_SIZE+32);

    char Rem[32];

    CRC(Binary_mod,Poly,3*BYTE_SIZE+32,33,Rem,32);
    Print_binary(Rem,4*BYTE_SIZE);

    Flip_binary(Rem,4*BYTE_SIZE,0);
    Print_binary(Rem,4*BYTE_SIZE);

    Reverse_binary(Rem,4*BYTE_SIZE);
    Print_binary(Rem,4*BYTE_SIZE);

    */

    /*
    char mes[] = {1,1,0,1,0,1,1,0,1,1,0,0,0,0};
    char poly[] = {1,0,0,1,1};
    char rem[] = {0,0,0,0};

    CRC(mes,poly,14,5,rem,4);

    Print_binary(rem,4);
    */
     

    return 0;
}