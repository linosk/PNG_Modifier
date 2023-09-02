   #include "no_string.h"

int main(int argc, char** argv){
    char Poly[33] = {1,0,0,0,0,0,1,0,0,1,1,0,0,0,0,0,1,0,0,0,1,1,1,0,1,1,0,1,1,0,1,1,1};

    // /int TEST[17] = {82,68,72,73,0,0,0,2,8,13,0,0,0,13,0,0,0};
    int TEST[17] = {73,72,67,82,0,0,0,13,0,0,0,13,8,2,0,0,0};

    char Binary[17*BYTE_SIZE];
    To_binary_multiple(Binary,TEST,17);
    Reverse_binary(Binary,17*BYTE_SIZE);
    Print_binary(Binary,17*BYTE_SIZE);

    char Binary_mod[32+17*BYTE_SIZE];
    Add_zeros(Binary,17*BYTE_SIZE,32,Binary_mod);

    Reverse_binary(Binary_mod,17*BYTE_SIZE+32);
    Print_binary(Binary_mod,17*BYTE_SIZE+32);

    Flip_binary(Binary_mod,32,0);
    Print_binary(Binary_mod,17*BYTE_SIZE+32);

    char Rem[32];

    CRC(Binary_mod,Poly,17*BYTE_SIZE+32,33,Rem,32);
    Print_binary(Rem,4*BYTE_SIZE);

    Flip_binary(Rem,4*BYTE_SIZE,0);
    Print_binary(Rem,4*BYTE_SIZE);

    Reverse_binary(Rem,4*BYTE_SIZE);
    Print_binary(Rem,4*BYTE_SIZE);

    return 0;
}