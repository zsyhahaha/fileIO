#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

const char * file = "111.txt";

int main()
{
    char ch;
    ifstream fin;
    fin.open(file);

    if(fin.is_open())
    {
        cout<<"Here are the current contents of "<<file<<" : ";
        while (fin.get(ch))
            cout<<ch;
        fin.close();
    }

    ofstream fout(file,ios_base::out | ios_base::app);
    if(!fout.is_open())
    {
        cerr<<"Can't open file : "<<file<<endl;
        exit(EXIT_FAILURE);
    }

    cout<<"\nEnter guest names : ";
    string name;
    while (getline(cin,name) && name.size() > 0)
        fout<<name<<endl;
    fout.close();

    fin.clear();
    fin.open(file);
    if(fin.is_open())
    {
        cout<<"Here are the new contents of "<<file<<" : "<<endl;
        while (fin.get(ch))
            cout<<ch;
        fin.close();
    }
    cout<<"Done";

    return 0;
}