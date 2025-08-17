#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main() {
    string input = "123 45.6 hello my name";
    stringstream ss(input);

    int a;
    float b;
    string c;

    ss >> a >> b ;

    cout << "Integer: " << a << "\n";
    cout << "Float: " << b << "\n";
    cout << "String: " << c << "\n";
    while(ss>>c) {
        cout << "Next string: " << c << "\n";
    }
    return 0;
}
