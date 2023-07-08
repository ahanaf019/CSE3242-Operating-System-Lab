#include<iostream>

using namespace std;


int main(int argc, char const *argv[])
{
    int holes[] = { 12, 7, 15, 3, 21, 9, 27, 18 };
    int n = sizeof(holes)/sizeof(holes[0]);
    
    int req = 13;
    cout<<"Request for memory of size "<<req<<endl;

    int best = INT16_MAX;
    int best_idx = 0;
    for(int i = 0; i < n; i++)
    {
        if(holes[i] - req > 0 && holes[i] - req < best)
        {
            best = holes[i] - req;
            best_idx = i;
        }
    }

    if(holes[best_idx] < req)
    {
        cout<<"No free holes found of required size"<<endl;
        return 0;
    }

    cout<<"Allocate hole"<<best_idx+1<<" of size "<<holes[best_idx]<<endl;


    return 0;
}
