//
// Created by Vitali Kurlovich on 11/17/16.
//

#ifndef RMPROPELLER_RMAPPLICATION_HPP
#define RMPROPELLER_RMAPPLICATION_HPP

#include <string>
#include <vector>
#include <fstream>

#include <core/resorce/sha1/RMSHA1.hpp>

using namespace std;

class RMApplication {

    const vector<string> _fileNamesList;
    const string _outdir{""};
public:
    RMApplication(const vector<string> &infiles, const string &outdir);
    int run();
protected:
    rmengine::hash::RMSHA1 sha1(ifstream& is);


};


#endif //RMPROPELLER_RMAPPLICATION_HPP
