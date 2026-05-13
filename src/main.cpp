#include <iostream>
#include <string>

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
      if(arg=="echo") std::cout<<"echo is a shell builtin"<<std::endl;
      else if(arg=="exit") std::cout<<"exit is a shell builtin"<<std::endl;
      else std::cout<<arg<<": not found"<<std::endl;
    }
    else std::cout<<command<<": command not found"<<std::endl;

  }
}
