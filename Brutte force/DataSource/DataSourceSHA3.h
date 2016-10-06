//
// Created by Dusan Klinec on 27.06.16.
//

#ifndef BRUTTE_FORCE_DATASOURCESHA3_H
#define BRUTTE_FORCE_DATASOURCESHA3_H

#include "DataSource.h"
#include "../DataGenerators/sha3/Sha3Interface.h"

#define SHA3_MD6 1
#define SHA3_TANGLE 2
#define SHA3_KECCAK 3

#define SHA3_DEFAULT_HASH_INIT -999

class DataSourceSHA3 : public DataSource {
public:
    DataSourceSHA3(unsigned long seed, int hash, int rounds, unsigned outputSize = 16, int hash_init = SHA3_DEFAULT_HASH_INIT);
    ~DataSourceSHA3();

    virtual long long getAvailableData() override;
    virtual void read(char *buffer, size_t size) override;
    virtual std::string desc() override;

protected:
    int m_hashFunction;
    int m_outputSize;
    long long m_counter;
    int m_rounds;
    int m_hash_init;
    Sha3Interface * m_sha3;
private:
};


#endif //BRUTTE_FORCE_DATASOURCESHA3_H
