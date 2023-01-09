#include <iostream>
using namespace std;

//can be declared first so that it can be used (line 11)
float sum(float x, float y);

//default parameter, if no argument is provided for y, it will default to 5
void print(int x, int y = 5){

    cout << "The input number was " << x << endl;
    cout << "When added with " << y << " it is " << sum(x,y) << endl;

}

//overloaded function, will choose which function based off of parameter provided
//If string is provided, this bottom func will be executed
void print(string str){
    cout << str << endl;
}

//function body defined later
float sum(float x, float y){
    return (x + y);
}

int main(){

    print(10);
    print(10, 10);

    print("cool string");

}