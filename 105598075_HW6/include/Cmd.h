#ifndef CMD_H
#define CMD_H

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class Cmd
{
    public:
        Cmd();
        virtual ~Cmd();
        void run();

    protected:

    private:
        //std::string cmd;
};

#endif // CMD_H
