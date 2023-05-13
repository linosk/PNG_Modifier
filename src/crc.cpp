#include "crc.h"

namespace crc{

    void Print_binary(const Bin_arr Binary){

        for(int i = 0 ;i<Binary.size();i++){
            std::cout<<static_cast<int>(Binary[i]);
            if((i+1)%8==0)
                std::cout<<" ";
        }
        std::cout<<"\n";

    }

    bool Compare_binaries(const Bin_arr Binary_one, const Bin_arr Binary_two, int Bits){
        for(int i=0 ;i<Bits;i++){
            if(Binary_one[i]!=Binary_two[i])
                return false;
        }

        return true;
    }

    void Copy_binary(const Bin_arr From, Bin_arr &To, int Numbers_of_bits, int Shift_from, int Shift_to){    

        for(int i = 0; i<Numbers_of_bits;i++)
            To[i+Shift_to] = From[i+Shift_from];

    }

    Bin_arr To_binary(int Number, int Shift){
        
        if (Number<0 || Number>255){
            std::cerr<<"ERROR"<<std::endl;
            exit(0);
        }

        Bin_arr Binary{};
        Binary.resize(BYTE_SIZE);
        int Counter = 0;

        while (Number)
        {
            if(Number%2)
                Binary[Counter] = 1;
            else
                Binary[Counter] = 0;
            Number=Number/2;
            Counter++;
        }

        for(int i=0;i<Counter;i++){
            Binary[i+Shift] = Binary[i];
            Binary[i] = 0;
        }
    
        for(int j=Counter;j<BYTE_SIZE;j++){
            Binary[j+Shift] = 0;
            Binary[j] = 0;
        }

        return Binary;

    }

}