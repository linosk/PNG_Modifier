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

    void To_binary(const int Number, const int Shift, Bin_arr &Binary){
        
        if (Number<0){
            std::cerr<<"ERROR"<<std::endl;
            exit(0);
        }

        int Number_local = Number;

        int Counter = 0 + Shift;

        while (Number_local)
        {
            if(Number_local%2)
                Binary[Counter] = 1;
            else
                Binary[Counter] = 0;
            Number_local=Number_local/2;
            Counter++;
        }

        for(int j=Counter;j<BYTE_SIZE;j++){
            Binary[j+Shift] = 0;
            Binary[j] = 0;
        }

    }

    void Reverse_binary(Bin_arr &Binary){

        Bin_arr Tmp{};
        Tmp.resize(Binary.size());
        crc::Copy_binary(Binary,Tmp,Binary.size(),0,0);

        for(int i=0,j = Binary.size()-1;i<Binary.size();i++,j--){
            Binary[i] = Tmp[j];
        }

    }

    void Add_zeros(Bin_arr &Binary, int Number_of_zeros){

        int Length = Binary.size();
        crc::Reverse_binary(Binary);
        Binary.resize(Length+Number_of_zeros);
        for(int i = Length; i<Length+Number_of_zeros-1 ; i++){
            Binary[i] = 0;
        }
        crc::Reverse_binary(Binary);

    }

    void Flip_binary(Bin_arr &Binary, const int Shift, const int Number_of_bits){

        for(int i = Shift; i<Number_of_bits;i++){
            if(Binary[i]==1)
                Binary[i] = 0;
            else
                Binary[i] = 1;
        }

    }

    Bin_arr CRC(const Bin_arr Data, const Bin_arr Polynomial){

        Bin_arr Remainder{};
        Bin_arr Tmp{};

        int Data_length = Data.size();
        int Polynomial_length = Polynomial.size();
        int Loop_length = Data_length - Polynomial_length + 1;
        int Remainder_length = Polynomial_length - 1;

        Remainder.resize(Remainder_length);
        Tmp.resize(Data_length);

        crc::Copy_binary(Data,Tmp,Data_length,0,0);

        for(int i = 0;i<Loop_length;i++){
            if(Tmp[i] == 1){
                for(int j =0; j<Polynomial_length;j++){
                    if(Tmp[i+j]!=Polynomial[j])
                        Tmp[i+j] = 1;
                    else
                        Tmp[i+j] = 0;
                }
            }
        }

        for(int k = 0;k<Remainder_length;k++){
            Remainder[k] = Tmp[k+Data_length-Remainder_length];
        }

        return Remainder;

    }

    uint8_t To_decimal(const int Shift, const Bin_arr Binary){

        uint8_t Decimal = 0;

        for(int i=0; i<BYTE_SIZE;i++){

            Decimal += Binary[i+Shift]*pow(2,1);

        }

        return Decimal;

    }

}

/*
        if (Number<0){
            std::cerr<<"ERROR"<<std::endl;
            exit(0);
        }

        int Number_local = Number;

        int Counter = 0 + Shift;

        while (Number_local)
        {
            if(Number_local%2)
                Binary[Counter] = 1;
            else
                Binary[Counter] = 0;
            Number_local=Number_local/2;
            Counter++;
        }

        for(int j=Counter;j<BYTE_SIZE;j++){
            Binary[j+Shift] = 0;
            Binary[j] = 0;
        }
*/