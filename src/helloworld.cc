/**
 * CS 140 Object-Oriented Programming Using C++
 * CRN: My CRN
 * Assignment: HelloWorld
 *
 * Statement of code ownership: I hereby state that I have written all of this
 * code and I have not copied this code from any other person or source.
 *
 * @author XorMasters
 */

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