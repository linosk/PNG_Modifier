#ifndef __CRC_H__
#define __CRC_H__

#include <vector>
#include <iostream>
#include <cmath>

namespace crc{
    
    #define BYTE_SIZE 8

    typedef std::vector<unsigned char> Bin_arr;

    void Print_binary(const Bin_arr Binary);

    bool Compare_binaries(const Bin_arr Binary_one, const Bin_arr Binary_two, int Bits);

    void Copy_binary(const Bin_arr From, Bin_arr &To, int Numbers_of_bits, int Shift_from, int Shift_to);

    //The whole CRC calculation may be turned to hex
    void To_binary(const int Number, const int Shift, Bin_arr &Binary);

    void Reverse_binary(Bin_arr &Binary);

    //void Add_zeros(char* Data, int Len_of_data, int Number_of_zeros, char* New_data);
    void Add_zeros(Bin_arr &Binary, int Number_of_zeros);

    void Flip_binary(Bin_arr &Binary, const int Shift, const int Number_of_bits);

    Bin_arr CRC(const Bin_arr Data, const Bin_arr Polynomial);

    //IT NEEEDS A TEST
    uint8_t To_decimal(const int Shift, const Bin_arr Binary);

}

#endif