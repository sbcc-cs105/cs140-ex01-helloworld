## Exercise: HelloWorld (8 Points)
Th
```cpp
#ifndef __EDU_SBCC_CS140__HELLOWORLD_H__
#define __EDU_SBCC_CS140__HELLOWORLD_H__

#include <string>

namespace edu { namespace sbcc { namespace cs140 {
class HelloWorld {
public:
	static std::string greetWorld();
};

}}}
#endif // __EDU_SBCC_CS140__HELLOWORLD_H__
```

```cpp
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
```