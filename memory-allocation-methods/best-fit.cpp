#include<iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int holes[] = { 7, 12, 8, 3, 11, 15 };

    int n = sizeof(holes)/ sizeof(int);

    int m = n;
    int req;
    int occ[n];
    for(int i = 0; i < n; i++)
        occ[i] = -1;

    while(m--)
    {
        cin>> req;
        int best = INT16_MAX;
        int idx = -1;
        for(int i = 0; i < n; i++)
        {
            int sz = holes[i] - req;
            if(sz >= 0 && sz < best && occ[i] == -1)
            {
                best = sz;
                idx = i;
            }
        }

        if(idx != -1)
        {
            occ[idx] = n - m;
            cout<<"Allocating hole-"<<idx+1<<" of size: "<<holes[idx]<<endl;
        }

        else
        {
            cout<<"Allocation failed for request of size: "<<req<<endl;
        }
    }

    for(int i = 0; i < n; i++)
        cout<<occ[i]<<" ";
    cout<<endl;


    return 0;
}
