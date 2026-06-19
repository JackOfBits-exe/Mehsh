#pragma once

#include<iostream>
#include<string>

namespace mehsh::echo
{
    int execute(const std::string& args)
    {
        std::cout<<args<<std::endl;
        return 0;
    }
}