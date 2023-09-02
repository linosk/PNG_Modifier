#include "png_place_holder.h"

#include <filesystem>
#include <fstream>

PNG_place_holder::PNG_place_holder(std::string File_name){

    //http://www.libpng.org/pub/png/spec/1.2/PNG-Chunks.html#C.Critical-chunks
    //https://www.youtube.com/watch?v=XyNWEWUSa5E&list=PLk6CEY9XxSIDZhQURp6d8Sgp-A0yKKDKV&ab_channel=CppNuts

    PNG_get_bytes(File_name);
    std::cout<<"====="<<"\n";
    std::cout<<Pointer<<"\n";
    std::cout<<"====="<<"\n";

    IHDR.PNG_get_chunk(PNG_file,IHDR_header, "IHDR", Pointer);
    // There must be a way to indicate which chunk to CRC check
    if (!Check_CRC(IHDR.Type_bytes,IHDR.Chunk_data,IHDR.CRC_bytes)){
        std::cout<<""<<"\n";
        exit(0);
    }
    std::cout<<"====="<<"\n";
    std::cout<<Pointer<<"\n";
    std::cout<<"====="<<"\n";
    
    n1.PNG_get_chunk(PNG_file,IHDR_header,"n1",Pointer);
    if (!Check_CRC(n1.Type_bytes,n1.Chunk_data,n1.CRC_bytes)){
        std::cout<<""<<"\n";
        exit(0);
    }
    std::cout<<"====="<<"\n";
    std::cout<<Pointer<<"\n";
    std::cout<<"====="<<"\n";

    n2.PNG_get_chunk(PNG_file,IHDR_header,"n2",Pointer);
    if (!Check_CRC(n2.Type_bytes,n2.Chunk_data,n2.CRC_bytes)){
        std::cout<<""<<"\n";
        exit(0);
    }
    std::cout<<"====="<<"\n";
    std::cout<<Pointer<<"\n";
    std::cout<<"====="<<"\n";

    n3.PNG_get_chunk(PNG_file,IHDR_header,"n3",Pointer);
    if (!Check_CRC(n3.Type_bytes,n3.Chunk_data,n3.CRC_bytes)){
        std::cout<<""<<"\n";
        exit(0);
    }
    std::cout<<"====="<<"\n";
    std::cout<<Pointer<<"\n";
    std::cout<<"====="<<"\n";
    
    n4.PNG_get_chunk(PNG_file,IHDR_header,"n4",Pointer);
    if (!Check_CRC(n4.Type_bytes,n4.Chunk_data,n4.CRC_bytes)){
        std::cout<<""<<"\n";
        exit(0);
    }
    std::cout<<"====="<<"\n";
    std::cout<<Pointer<<"\n";
    std::cout<<"====="<<"\n";

    //ISSUE - free(): invalid size Aborted (core dumped)
    n5.PNG_get_chunk(PNG_file,IHDR_header,"n5",Pointer);
    if (!Check_CRC(n5.Type_bytes,n5.Chunk_data,n5.CRC_bytes)){
        std::cout<<""<<"\n";
        exit(0);
    }
    std::cout<<"====="<<"\n";
    std::cout<<Pointer<<"\n";
    std::cout<<"====="<<"\n";

}

void PNG_place_holder::PNG_get_bytes(std::string File_name){
    // Maybe there should be another check whether the png.file is actually png
    // Remember that std::filesystem requires -std=c++17 and c_cpp_properties.json
    if(std::filesystem::exists(File_name)){
        std::ifstream File(File_name);
        File.seekg(0,std::ios::end);
        Size = File.tellg();
        Pointer = 0;
        File.seekg(0,std::ios::beg);
        //PNG_file = new PNG_byte[Size];
        //File.read(reinterpret_cast<char*>(PNG_file),Size);
        PNG_file.resize(Size);
        File.read((char*)&PNG_file[0],Size);
        File.close();

        if(!PNG_compare(PNG_file,0,BYTE_SIZE,Correct_signature)){
            std::cerr<<File_name+" is not correct .png file, incorrect signature."<<"\n";
            exit(1);
        }

        Pointer+= BYTE_SIZE;

    }

    else{
        std::cerr<<"File "+File_name+" does not exist."<<"\n";
        exit(1);
    }

}

//Should atributes be passed as arguments to method?
bool PNG_place_holder::Check_CRC(const PNG_array Type_bytes, const PNG_array Chunk_data, const PNG_array CRC_bytes){

    int Data_length = Type_bytes.size() + Chunk_data.size();
    PNG_array Data = PNG_connect(Type_bytes,Chunk_data);

    crc::Bin_arr Polyniomal = {1,0,0,0,0,0,1,0,0,1,1,0,0,0,0,0,1,0,0,0,1,1,1,0,1,1,0,1,1,0,1,1,1};
    
    crc::Bin_arr Binary{};
    Binary.resize(Data_length*BYTE_SIZE);
    for(int i =0, j=0;i<Data_length*BYTE_SIZE;i+=BYTE_SIZE,j++){
        crc::To_binary(Data[j],i,Binary);
    }

    crc::Reverse_binary(Binary);

    crc::Add_zeros(Binary,4*BYTE_SIZE);
    crc::Reverse_binary(Binary);

    crc::Flip_binary(Binary,0,4*BYTE_SIZE);

    crc::Bin_arr Rem = crc::CRC(Binary,Polyniomal);
    crc::Flip_binary(Rem,0,4*BYTE_SIZE);

    crc::Reverse_binary(Rem);
    crc::Reverse_binary(Rem);

    PNG_array CRC_compare{};
    CRC_compare.resize(CHUNK_SIZE);

    for(int i =0, j=0;i<Data_length*BYTE_SIZE;i+=BYTE_SIZE,j++){
        CRC_compare[j] = crc::To_decimal(i,Rem);
    }

    PNG_reverse_order(CRC_compare);

    return PNG_compare(CRC_bytes,0,CHUNK_SIZE,CRC_compare);

    //Flip_binary has to modified, take look at main.cpp in XD directory, make test for this function and fix test for test_binary - MOSTLY DONE
    //Tests need to be corrected
    //SOMETHING WRONG
    //WRITE MISSING TESTS
    //MAKE THE OOP BETTER -- IMPORTANT
    //READ 0THER C0MMENTS

}