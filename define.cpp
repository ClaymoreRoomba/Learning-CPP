#include <iostream>

#define PI 3.1415926535897932384626
#define test "test"
#define print std::cout <<
#define nl << std::endl
#define out(s) std::cout << s << std::endl;

int main(){
    std::cout << PI << std::endl;
    std::cout << PI + 1 << std::endl;
    std::cout << test << " is being tested\n";
    print test nl;
    print "Easier code" nl;
    out("crazy");
 }