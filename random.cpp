#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>

using namespace std;

const int LIM = 20;
const char * file = "333";

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

int main()
{
    planet p1;
    cout<<fixed;

    fstream finout;
    finout.open(file,ios_base::in | ios_base::out | ios_base::binary);
    int ct = 0;
    if(finout.is_open())
    {
        finout.seekg(0);
        cout<<"Here are the current contents of the "<<file<<" : "<<endl;
        while (finout.read((char *)&p1,sizeof p1))
        {
            cout<<ct++<<setw(LIM)<<p1.name<<" : "
                <<setprecision(0)<<setw(12)<<p1.population
                <<setprecision(2)<<setw(16)<<p1.g<<endl;
        }
        if(finout.eof())
            finout.clear();
        else
        {
            cerr<<"Error in reading "<<file<<endl;
            exit(EXIT_FAILURE);
        }
    } else
    {
        cerr<<file<<" could not be opened"<<endl;
        exit(EXIT_FAILURE);
    }

    cout<<"Enter the record number you wish to change: ";
    long rec;
    cin>>rec;
    eatline();//***
    if(rec < 0 || rec >= ct)
    {
        cerr<<"Invalid record number "<<endl;
        exit(EXIT_FAILURE);
    }
    streampos place = rec * sizeof p1;
    finout.seekg(place);
    if(finout.fail())
    {
        cout<<"Error on attempted seek "<<endl;
        exit(EXIT_FAILURE);
    }

    finout.read((char *) & p1,sizeof p1);
    cout<<"Your selection: "<<endl;
    cout<<rec<<" : "<<setw(LIM)<<p1.name<<" : "
        <<setprecision(0)<<setw(12)<<p1.population
        <<setprecision(2)<<setw(16)<<p1.g<<endl;
    if(finout.eof())
        finout.clear();

    cout<<"Enter planet name: ";
    cin.get(p1.name,LIM);
    eatline();
    cout<<"Enter planetary population: ";
    while (!(cin>>p1.population))
    {
        cin.clear();
        eatline();
        cout<<"Oops, please reenter population: ";
    }
    eatline();

    cout<<"Enter planet's acceleration of gravity: ";
    while (!(cin>>p1.g))
    {
        cin.clear();
        eatline();
        cout<<"Oops, please reenter gravity: ";
    }
    eatline();

    finout.seekp(place);
    finout.write((char *) &p1,sizeof p1)<<flush;
    if(finout.fail())
    {
        cerr<<"Error on attempted write"<<endl;
        exit(EXIT_FAILURE);
    }

    ct = 0;
    finout.seekg(0);
    cout<<"Here are the new contents of the "<<file<<" : "<<endl;
    while (finout.read((char *)&p1,sizeof p1))
    {
        cout<<ct++<<" : "<<setw(20)<<p1.name<<" : "
            <<setprecision(0)<<setw(12)<<p1.population
            <<setprecision(2)<<setw(16)<<p1.g<<endl;
    }
    finout.close();
    cout<<"Done";
    return 0;

}
