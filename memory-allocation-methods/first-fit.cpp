#include<iostream>

using namespace std;


int main(int argc, char const *argv[])
{
    int holes[] = { 12, 7, 15, 3, 21, 9, 27, 18 };
    int n = sizeof(holes)/sizeof(holes[0]);
    
    int req = 37;
    cout<<"Request for memory of size "<<req<<endl;
    for(int i = 0; i < n; i++)
    {
        if(holes[i] >= req)
        {
            cout<<"Allocate hole"<<i+1<<" of size "<<holes[i]<<endl;
            break;
        }
    }
    cout<<"No free holes found of required size"<<endl;


    return 0;
}
