#include <iostream>
#include <string>
#include "handler.hpp"
#include "common.hpp"

int main() {
  // Flush after every std::cout / std:cerr
  std::cout << std::unitbuf;
  std::cerr << std::unitbuf;


  std::string path=getenv("PATH");
  mehsh::common::setup_paths(path);

  mehsh::repl();
}
