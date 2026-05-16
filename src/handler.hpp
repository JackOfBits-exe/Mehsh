#pragma once

#include <iostream>
#include <string>
#include <unordered_map>
#include <functional>
#include "common.hpp"
#include "echo.hpp"
#include "exit.hpp"
#include "type.hpp"
#include "pwd.hpp"
#include <cstdlib>

namespace mehsh
{
    static std::unordered_map<std::string,std::function<int (const std::string&)>> cmd_mp
    {
        {"echo",&echo::execute},
        {"exit",&exit::execute},
        {"type",&type::execute},
        {"pwd",&pwd::execute},
    };

    std::pair<std::string,std::string> extract_args(const std::string & command)
    {
        auto idx=command.find(' ');
        if(idx==std::string::npos)
        {
            return {command,""};
        }
        const std::string cmd=command.substr(0,idx);
        const std::string args=command.substr(idx+1);
        return {cmd,args};
    }

    int execute(const std::string & command)
    {
        const auto [cmd,args]=extract_args(command);
        if(cmd_mp.contains(cmd))
        {
            return cmd_mp[cmd](args);
        }
        else if(!common::cmd_path(cmd).empty())
        {
            return std::system(command.c_str());
        }
        else
        {
            std::cout<<cmd<<": command not found"<<std::endl;
            return 1;
        }

    }


    void repl()
    {
        while(true)
        {
            std::cout<<"$ ";
        
            std::string command;
            std::getline(std::cin,command);

            int exit_code=execute(command);
            if(exit_code==-1)
            {
                break;
            }
        }
    }
}