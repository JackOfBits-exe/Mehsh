#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <filesystem>
#include <unistd.h>
#include <unordered_set>

namespace mehsh::common
{
    static const std::unordered_set<std::string> bultins {
        "echo",
        "exit",
        "type",
        "pwd",
    };

    static std::vector<std::string> paths;

    void setup_paths(const std::string& path)
    {
        std::stringstream ss(path);
        std::string current_path;
        while(std::getline(ss,current_path,':'))
        {
            if(std::filesystem::exists(current_path))
            {
                paths.push_back(current_path);
            }
        }
    }

    std::string cmd_path(const std::string& cmd)
    {
        for(const auto& path:paths)
        {
            const std::string full_path=path+'/'+cmd;
            if(std::filesystem::exists(full_path) && std::filesystem::is_regular_file(full_path) && access(full_path.c_str(),X_OK)==0)
            {
                return full_path;
            }
        }
        return "";
    }
}