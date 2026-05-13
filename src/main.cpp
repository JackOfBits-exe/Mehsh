#include <iostream>
#include <string>
#include <sstream>
#include <unistd.h>

int main() {
  // Flush after every std::cout / std:cerr
  std::cout << std::unitbuf;
  std::cerr << std::unitbuf;

  while(true)
  {
    std::cout<<"$ ";
  
    std::string command;
    std::getline(std::cin,command);
    if(command=="exit") break;
    else if(command.substr(0,5)=="echo ")
    {
      std::cout<<command.substr(5)<<std::endl;
    }
    else if(command.substr(0,5)=="type ")
    {
      std::string arg=command.substr(5);
      if(arg=="echo " || arg=="exit " || arg=="type ")
      {
        std::cout<<arg<<" is a shell builtin"<<std::endl;
        continue;
      }
      std::string sys_path=std::getenv("PATH");
      std::stringstream ss(sys_path);
      std::string path;
      bool found=false;
      while(std::getline(ss,path,':'))
      {
        std::string full_path=path+'/'+arg;
        if(access(full_path.c_str(),X_OK)==0)
        {
          std::cout<<arg<<" is "<<full_path<<std::endl;
          found=true;
          break;
        }
      }
      if(!found) std::cout<<arg<<": not found"<<std::endl;
    }
    else std::cout<<command<<": command not found"<<std::endl;

  }
}
