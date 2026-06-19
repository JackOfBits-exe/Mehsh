#include<iostream>
#include<string>
#include<filesystem>

#define fs std::filesystem

namespace mehsh::cd
{
    std::pair<bool,std::string> handle_home(const std::string& args);

    int execute(const std::string& args);
}