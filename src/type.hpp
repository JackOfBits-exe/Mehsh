#include<iostream>
#include<string>
#include "common.hpp"

namespace mehsh::type
{
    int execute(const std::string& args)
    {
        if(common::bultins.contains(args))
        {
            std::cout<<args<<" is a shell builtin"<<std::endl;
            return 0;
        }
        std::string prog_path=common::cmd_path(args);
        if(!prog_path.empty())
        {
            std::cout<<args<<" is "<<prog_path<<std::endl;
            return 0;
        }
        else
        {
            std::cout<<args<<": not found"<<std::endl;
            return 1;
        }
    }
}