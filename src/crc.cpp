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

    void To_binary(int Number, int Shift, Bin_arr &Binary){
        
        if (Number<0){
            std::cerr<<"ERROR"<<std::endl;
            exit(0);
        }

        int Length = BYTE_SIZE + Shift*BYTE_SIZE;
        Binary.resize(Length);
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

        for(int j=Counter;j<BYTE_SIZE;j++){
            Binary[j+Shift] = 0;
            Binary[j] = 0;
        }

    }

}