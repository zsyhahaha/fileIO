#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string filename;

    string savePath = "../";

    cout<<"Enter name of new file: ";
    cin>>filename;

    ofstream fout;
    fout.open(savePath+filename);

    fout<<"For your eyes only"<<endl;
    cout<<"Enter your secret number: ";

    float secret;
    cin>>secret;
    fout<<"your secret number is: "<<secret<<endl;
    fout.close();

    ifstream fin(savePath+filename);
    cout<<"Here are the contents of "<<filename<<": "<<endl;
    char ch;
    while (fin.get(ch))
        cout<<ch;
    cout<<"Done";
    fin.close();
    return 0;
}
