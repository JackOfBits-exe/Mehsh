#include<iostream>
#include<string>
#include<filesystem>

#define fs std::filesystem

namespace mehsh::cd
{
    std::pair<bool,std::string> handle_home(const std::string& args)
    {
        if(args.empty())
        {
            fs::path home_path=getenv("HOME");
            return {true,home_path.string()};
        }
        else if(args[0]=='~')
        {
            fs::path home_path=getenv("HOME");
            fs::path extended_path=args.substr(1);
            return {true,(home_path/extended_path).string()};
        }
        return {false,args};
    }

    int execute(const std::string& args)
    {
        fs::path new_path;
        const auto [is_home,extended_args]=handle_home(args);
        if(is_home) new_path=extended_args;
        else new_path=args;
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