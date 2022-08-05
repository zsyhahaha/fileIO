#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
using namespace std;

inline void eatline()
{
    while (cin.get() != '\n')
        continue;
}

struct planet
{
    char name[20];
    double population;
    double g;
};

const char * file = "333";

int main()
{
    planet p1;
    cout<<fixed<<right;
    ifstream fin;
    fin.open(file,ios_base::in | ios_base::binary);
    if(fin.is_open())
    {
        cout<<"Here are the current contents of "<<file<<" : "<<endl;
        while (fin.read((char *) & p1, sizeof p1))
        {
            cout<<setw(20)<<p1.name<<" : "
            <<setprecision(0)<<setw(12)<<p1.population
            <<setprecision(2)<<setw(16)<<p1.g<<endl;
        }
        fin.close();
    }

    ofstream fout(file,ios_base::out | ios_base::app | ios_base::binary);
    if(!fout.is_open())
    {
        cerr<<"Can't open "<<file<<" for output"<<endl;
        exit(EXIT_FAILURE);
    }

    cout<<"Enter planet name : ";
    cin.get(p1.name,20);
    while(p1.name[0] != '\0')
    {
        eatline();
        cout<<"Enter planetary population: ";
        while (!(cin>>p1.population))
        {
            cin.clear();
            eatline();
            cout<<"Oops, please enter new population: ";
        }
        eatline();

        cout<<"Enter planet's acceleration of gravity: ";
        while (!(cin>>p1.g))
        {
            cin.clear();
            eatline();
            cout<<"Oops, please enter new gravity: ";
        }
        eatline();

        fout.write((char *) & p1, sizeof(p1));
        cout<<"Enter planet name : ";
        cin.get(p1.name,20);
    }
    fout.close();

    fin.clear();
    fin.open(file,ios_base::in | ios_base::binary);
    if(fin.is_open())
    {
        cout<<"Here are the nwe contents of the file : "<<file<<endl;
        while (fin.read((char *) & p1,sizeof  p1))
        {
            cout<<setw(20)<<p1.name<<" : "
                <<setprecision(0)<<setw(12)<<p1.population
                <<setprecision(2)<<setw(16)<<p1.g<<endl;
        }
        fin.close();
    }
    cout<<"Done";
    return 0;
}