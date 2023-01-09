#include <iostream>
using namespace std;

#define say std::cout<<

int main(){

    int x = 5;
    float y = 6.3f;
    string z = "a great string";
    bool isCool = false;

    cout << x + y << endl;
    cout << float(x) + y << endl;
    say "the isCool bool is currently " << (isCool ? "true" : "false") << ", change it?\n";
    cout << "1. yes\n2. no\n";
    int change;
    cin >> change;
    isCool = change % 2;

    say "the isCool bool is currently " << (isCool ? "true" : "false") << endl;
}