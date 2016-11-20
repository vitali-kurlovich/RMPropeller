#include <iostream>
#include <core/resorce/RMResourceHeader.hpp>

#include "src/RMApplication.hpp"

int main(int argc, char *argv[]) {


    std::vector<std::string> arglist;
    arglist.reserve(argc);

    string outdir = "";
    bool nextisOut = false;
    for (int index = 1; index < argc; ++ index) {

        string arg = std::string(argv[index]);
        if (arg == "-o" || arg == "-O") {
            nextisOut = true;
            continue;
        }

        if (nextisOut) {
            outdir = arg;
            nextisOut = false;
            continue;
        }

        arglist.push_back(arg);
    }

    RMApplication app(arglist, outdir);
    return app.run();
}