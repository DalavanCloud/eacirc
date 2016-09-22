//
// Created by Dusan Klinec on 19.06.16.
//

#include "DataSourceAES.h"
#include <random>
#include <cstring>
#include "../DataGenerators/aes.h"

DataSourceAES::DataSourceAES(unsigned long seed, int Nr_) {
    std::minstd_rand systemGenerator((unsigned int) seed);
    for (unsigned char i = 0; i < 16; i++) {
        m_key[i] = (uint8_t) systemGenerator();
        m_iv[i] = (uint8_t) systemGenerator();
    }
    Nr = Nr_;
}

long long DataSourceAES::getAvailableData() {
    return 9223372036854775807; // 2^63-1
}

void DataSourceAES::read(char *buffer, size_t size) {
    __uint64_t counter = 0;
    const int workingBufferSize = 16;
    uint8_t workingBufferIn[workingBufferSize];

    //counter mode
    for(size_t offset = 0; offset < size; offset += workingBufferSize){
        memcpy(workingBufferIn,&counter,workingBufferSize);
        // Encrypt input buffer.
        AES128_ECB_encrypt(workingBufferIn, m_key, (uint8_t*)(buffer + offset), Nr);
    }
}

std::string DataSourceAES::desc() {
    return "AES";
}

