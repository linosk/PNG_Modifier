#ifndef __CRC_H__
#define __CRC_H__

#include <png_chunk.h>

namespace crc{
    
    typedef std::vector<PNG_byte> Bin_arr;

    void Print_binary(const Bin_arr Binary);

    bool Compare_binaries(const Bin_arr Binary_one, const Bin_arr Binary_two, int Bits);

    void Copy_binary(const Bin_arr From, Bin_arr &To, int Numbers_of_bits, int Shift_from, int Shift_to);

    //The whole CRC calculation should be turned to hex
    Bin_arr To_binary(int Number, int Shift);

}

#endif