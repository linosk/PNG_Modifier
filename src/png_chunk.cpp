#include "png_chunk.h"

//How to test this?
void PNG_chunk::PNG_get_chunk(std::vector<PNG_byte> PNG_file, const std::vector<PNG_byte> PNG_chunk_header, std::string PNG_header_name, size_t &Counter){
    //Copying bytes about data length
    PNG_copy(PNG_file,Counter,CHUNK_SIZE,Data_length_bytes);
    Counter+=CHUNK_SIZE;
    PNG_print(Data_length_bytes);
    //

    //Copying bytes about header name and checking if it matches
    PNG_copy(PNG_file,Counter,CHUNK_SIZE,Type_bytes);
    Counter+=CHUNK_SIZE;
    if(!PNG_compare(Type_bytes,0,CHUNK_SIZE,PNG_chunk_header)){
        std::cerr<<PNG_header_name+" header does not match."<<std::endl;
        exit(1);
    }
    PNG_print(Type_bytes);
    //

    //Declaring an array for data
    Data_length = PNG_sum_chunks(Data_length_bytes);
    PNG_copy(PNG_file,Counter,Data_length,Chunk_data);
    Counter+=Data_length;
    PNG_print(Chunk_data);
    //

    //Copying bytes about CRC, later an own implementaion of CRC will be required to change PNG_bytes
    PNG_copy(PNG_file,Counter,CHUNK_SIZE,CRC_bytes);
    Counter+=CHUNK_SIZE;
    PNG_print(CRC_bytes);
    //
}

void PNG_print(const std::vector<PNG_byte> Array){    
    for(uint8_t i = 0; i<Array.size();i++){
        std::cout<<static_cast<unsigned int>(Array[i])<<" ";
    }
    std::cout<<"\n";
}

//Change the std::string File_name to something different
//Write a test
//Maybe templetize it
//bool PNG_compare(PNG_byte* Compare, uint8_t Beg, uint8_t Range, PNG_byte* Compare_to){
bool PNG_compare(const std::vector<PNG_byte> Compare, uint8_t Beg, uint8_t Range, const std::vector<PNG_byte> Compare_to){
    for(uint8_t i = 0; i<Range; i++){
        if(Compare[Beg+i]!=Compare_to[i])
            return false;
    }
    return true;
}

void PNG_copy(const std::vector<PNG_byte> Copy, uint8_t Beg, uint8_t Range, std::vector<PNG_byte> &Copy_to){
    Copy_to.resize(Range);
    for(uint8_t i = 0; i<Range; i++){
        Copy_to[i] = static_cast<unsigned char>(Copy[Beg+i]);
    }
}

u_int32_t PNG_sum_chunks(const std::vector<PNG_byte> Data_length_bytes){
    u_int32_t Data_length = 0x0;
    uint8_t Length = Data_length_bytes.size();
    uint8_t Power = Length - 1;
    for(uint8_t i=0;i<Length;i++){
        Data_length += Data_length_bytes[i]*pow(0x100,Power);
        Power--;
    }

    return Data_length;
}