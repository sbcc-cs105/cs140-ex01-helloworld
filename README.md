## Exercise: HelloWorld (8 Points)

```cpp
#include <iostream>
#include <cs140>

#include "helloworld.h"

std::string HelloWorld::greetWorld() {
	return "Hello, World!";
}

int main(UNUSED(int argc), UNUSED(char *argv[])) {
	std::cout << HelloWorld::greetWorld() << std::endl;
}
```