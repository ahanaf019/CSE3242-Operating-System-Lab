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
        cin>>req;
        
        int i;
        for(i = 0; i < n; i++ )
        {
            if(holes[i] >= req && occ[i] == -1)
            {
                occ[i] = n-m;
                cout<<"Allocating hole-"<<i+1<<" of size: "<<holes[i]<<endl;
                break;
            }
        }

        if(i >= n)
        {
            cout<<"Allocation failed for request of size: "<<req<<endl;
        }
    }

    for(int i = 0; i < n; i++)
        cout<<occ[i]<<" ";
    cout<<endl;


    return 0;
}
