#include<iostream>
#include<string>
#include<filesystem>

#define fs std::filesystem

namespace mehsh::cd
{
    int execute(const std::string& args)
    {
        fs::path new_path=args;
        if(fs::exists(new_path) && fs::is_directory(new_path))
        {
            fs::current_path(new_path);
            return 0;
        }
        else
        {
            std::cout<<"cd: "<<args<<": No such file or directory"<<std::endl;
            return 1;
        }
    }
}