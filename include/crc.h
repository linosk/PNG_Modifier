#ifndef __CRC_H__
#define __CRC_H__

#include <vector>
#include <iostream>

namespace crc{
    
    #define BYTE_SIZE 8

    typedef std::vector<unsigned char> Bin_arr;

    void Print_binary(const Bin_arr Binary);

    bool Compare_binaries(const Bin_arr Binary_one, const Bin_arr Binary_two, int Bits);

    void Copy_binary(const Bin_arr From, Bin_arr &To, int Numbers_of_bits, int Shift_from, int Shift_to);

    //The whole CRC calculation should be turned to hex
    void To_binary(int Number, int Shift, Bin_arr &Binary);

}

#endif