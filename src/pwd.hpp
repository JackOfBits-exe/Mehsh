#pragma once

#include<iostream>
#include<string>
#include<filesystem>

namespace mehsh::pwd
{
    int execute(const std::string& args)
    {
        std::cout<<std::filesystem::current_path().string()<<std::endl;
        return 0;
    }
}