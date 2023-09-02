#ifndef __NO_STRING__
#define __NO_STRING__

#include <iostream>

#include <cmath>

#define BYTE_SIZE 8

//char Header[4] = {82,68,72,73};
//char Data[13] = {0,0,0,2,8,13,0,0,0,13,0,0,0};
//char CRC[4] = {253, 137, 115, 43};

//unsigned char Polynomial[5] = {0x1,0x04,0xC1,0x1D,0xB7};

void Print_binary(char* Binary, int Length){
    //for(int i=Length-1;i>=0;i--)
    //    std::cout<<static_cast<int>(Binary[i])<<" ";
    //std::cout<<std::endl;

    for(int i=0;i<Length;i++){
        std::cout<<static_cast<int>(Binary[i]);
        if((i+1)%8==0)
            std::cout<<" ";
    }
    std::cout<<std::endl;

}

//MAYBE IT SHOULD RETURN INDEX INSTEAD OF BOOLEAN, -1 WHEN BINARIES MATCH
bool Compare_binaries(char* Binary_one, char* Binary_two, int Bits){

    for(int i=0 ;i<Bits;i++){
        if(Binary_one[i]!=Binary_two[i])
            return false;
    }

    return true;

}

void Copy_binary(char* From, char* To, int Numbers_of_bits, int Shift_from, int Shift_to){

    for(int i = 0; i<Numbers_of_bits;i++)
        To[i+Shift_to] = From[i+Shift_from];

}

void To_binary(char* Binary, int Number, int Shift){

    if (Number<0 || Number>255){
        std::cerr<<"ERROR"<<std::endl;
        exit(0);
    }

    char Tmp[BYTE_SIZE];
    int Counter = 0;

    while (Number)
    {
        if(Number%2)
            Tmp[Counter] = 1;
        else
            Tmp[Counter] = 0;
        Number=Number/2;
        Counter++;
    }

    for(int i=0;i<Counter;i++){
        Binary[i+Shift] = Tmp[i];
        Tmp[i] = 0;
    }
    for(int j=Counter;j<BYTE_SIZE;j++){
        Binary[j+Shift] = 0;
        Tmp[j] = 0;
    }
}

void To_binary_multiple(char* Binary, int* Numbers, int Len_of_numbers){

    for(int i=0;i<Len_of_numbers;i++){
        To_binary(Binary,Numbers[i],i*BYTE_SIZE);
    }

}

void Add_zeros(char* Data, int Len_of_data, int Number_of_zeros, char* New_data){
    Copy_binary(Data,New_data,Len_of_data,0,Number_of_zeros);

    for(int i=0;i<Number_of_zeros;i++){
        New_data[i] = 0;
    }

}

uint8_t To_decimal(char* Binary, int Shift){
    uint8_t Decimal = 0;

    for(int i = 0;i<BYTE_SIZE;i++){
        Decimal += Binary[i+Shift]*pow(2,i);
    }

    return Decimal;
}

void To_decimal_multiple(){

}

void CRC(char* Data, char* Polyniomal, int Len_data, int Len_poly, char* Remainder, int Len_rem){

    if(Len_rem!=Len_poly-1)
    {
        std::cerr<<"ERROR"<<std::endl;
        exit(0);
    }

    int Length_of_the_loop = Len_data - Len_poly + 1;

    for(int i=0;i<Length_of_the_loop;i++){
        if(Data[i] == 1){
            for(int j=0;j<Len_poly;j++){
                if(Data[i+j]!=Polyniomal[j])
                    Data[i+j] = 1;
                else
                    Data[i+j] = 0;
            }
        }
    }

    for(int k=0;k<Len_rem;k++){
        Remainder[k] = Data[k+Len_data-Len_rem];
    }
    
}

//There should also be reverse bytes function
void Reverse_binary(char* Binary, int Length){

    char Tmp[Length];

    Copy_binary(Binary,Tmp,Length,0,0);

    for(int i=0,j = Length-1;i<Length;i++,j--){
        Binary[i] = Tmp[j];
    }

}


/*
char* CRC(char* Data, char* Polyniomal, int Len_data, int Len_poly){

    int Len_rem = Len_poly - 1;

    char* Remainder = new char(Len_rem);

    int Length_of_the_loop = Len_data - 3;

    for(int i=0;i<Length_of_the_loop;i++){
        if(Data[i] == 1){
            for(int j=0;j<Len_poly;j++){
                if(Data[i+j]!=Polyniomal[j])
                    Data[i+j] = 1;
                else
                    Data[i+j] = 0;
            }
        }
    }

    for(int k=0;k<Len_poly;k++){
        Remainder[k] = Data[k+Len_data-Len_rem];
    }

    return Remainder;
}
*/

void Flip_binary(char* Binary, int Number_of_bits, int Shift){

    for(int i=0;i<Number_of_bits;i++){
        if(Binary[i+Shift]==1)
            Binary[i+Shift] = 0;
        else
            Binary[i+Shift] = 1;
    }
}

#endif