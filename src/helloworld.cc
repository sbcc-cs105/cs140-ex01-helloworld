#include <iostream>
#include <cs140>

#include "helloworld.h"

std::string edu::sbcc::cs140::HelloWorld::greetWorld() {
    return "Hello, World!";
}

using edu::sbcc::cs140::HelloWorld;

int main(UNUSED(int argc), UNUSED(char *argv[])) {
    std::cout << HelloWorld::greetWorld() << std::endl;
}