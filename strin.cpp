#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main()
{
    string list = "It was a dark and stormy day ";
    istringstream instr(list);
    string word;
    while (instr>>word)
        cout<<word<<endl;
    return 0;
}
