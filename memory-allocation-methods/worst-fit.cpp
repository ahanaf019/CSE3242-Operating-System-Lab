#include<iostream>

using namespace std;


int main(int argc, char const *argv[])
{
    int holes[] = { 12, 7, 15, 3, 21, 9, 27, 18 };
    int n = sizeof(holes)/sizeof(holes[0]);
    
    int req = 7;
    cout<<"Request for memory of size "<<req<<endl;

    int large = holes[0];
    int large_idx = 0;
    for(int i = 0; i < n; i++)
    {
        if(holes[i] > large)
        {
            large = holes[i];
            large_idx = i;
        }
    }

    if(holes[large_idx] < req)
    {
        cout<<"No free holes found of required size"<<endl;
        return 0;
    }

    cout<<"Allocate hole"<<large_idx+1<<" of size "<<holes[large_idx]<<endl;


    return 0;
}
