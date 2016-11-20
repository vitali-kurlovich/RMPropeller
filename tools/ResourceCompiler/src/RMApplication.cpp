//
// Created by Vitali Kurlovich on 11/17/16.
//


#include "RMApplication.hpp"

#include <iostream>
#include <iomanip>

//#include <sha1.h>

#include <core/io/RMCoder.hpp>
#include <common/common.hpp>

using namespace rmengine;
using namespace rmengine::hash;
using namespace rmengine::serialize;

RMApplication::RMApplication(const vector<string> &infiles, const string &outdir)
        : _fileNamesList(infiles), _outdir(outdir)
{

}

int RMApplication::run() {
    for (string arg : _fileNamesList) {
       // std::cout << arg << ";" << std::endl;

        std::ifstream is (arg, std::ifstream::binary);
        auto sha = sha1(is);
        is.close();

        std::cout << std::hex
                  << htonl(sha.sha1_20_5[0])
                  << htonl(sha.sha1_20_5[1])
                  << htonl(sha.sha1_20_5[2])
                  << htonl(sha.sha1_20_5[3])
                  << htonl(sha.sha1_20_5[4])

                  << std::endl;


        std::hash<RMSHA1> hashfunc;
        std::cout << std::hex
                  << htonl(hashfunc(sha))
                  << std::endl;



        //RMMemmoryBuffer membuffer;


        std::ofstream os (_outdir, std::ifstream::binary);

        RMCoder coder;
//        uint8 byte(64);
//
//        coder.encode(byte, os);
//        byte = 88;
//        coder.encode(byte, os);
//
//        byte = 68;
//        coder.encode(byte, os);
//
//        int64 byte64(646764534566);
//        coder.encode(byte64, os);
//
//        float fval(43.64446343f);
//        coder.encode(fval, os);

        os.sync_with_stdio();

    }

    return 0;
}

RMSHA1 RMApplication::sha1(ifstream& is) {

    if (is.is_open()) {
        is.seekg(0, is.end);
        size_t length = is.tellg();
        is.seekg(0, is.beg);

        char * buffer = new char [length];
        std::cout << length << " : ";
        // read data as a block:
        is.read (buffer,length);

        auto sha1 = rmengine::hash::RMSHA1::sha1(buffer, length);
        delete[] buffer;
        return sha1;
    }

    return RMSHA1::zero();
}