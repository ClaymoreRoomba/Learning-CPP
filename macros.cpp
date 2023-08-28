#include <iostream>

#define PI 3.14
#define LOG(x) std::cout << x << std::endl
#define VAR_NAME(x) #x

/* Now can change from debug mode to not
function will only be called when in debug mode
DEBUG_MODE can also be defined in preprocessor arguments
in programs such as VS Community (dont have to define in code)
*/
#define DEBUG_MODE 0
#if DEBUG_MODE == 1
#define DEBUG_LOG(x) LOG(x)
#else
#define DEBUG_LOG(x)
#endif

int main(){
    std::cout << PI << std::endl;
    LOG("Hello World!");
    DEBUG_LOG("Debug Statement!");
    int x = 5;
    std::cout << VAR_NAME(x) << " is " << x << std::endl;
}