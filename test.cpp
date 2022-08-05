#include<iostream>
using namespace std;
int main()
{
    int a,b;
    while (1)
    {
        cout<<"Please enter a number: ";
        cin>>a;
        cin.clear();
        while (cin.get() != '\n')
            continue;
    }

    //cout << " cin.fail == " << cin.fail() << endl;
    //cin.clear();
    //cin.ignore();
//    cin >> b;
//    cout << "a == " << a << " b == " << b;
//    return 0;
}
