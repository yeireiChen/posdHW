#ifndef CMD_H
#define CMD_H

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <Media.h>

class Cmd
{
    public:
        Cmd();
        virtual ~Cmd();
        void run();

    protected:

    private:
        //std::string cmd;
        std::map<std::string,Media*> names;
};

#endif // CMD_H
