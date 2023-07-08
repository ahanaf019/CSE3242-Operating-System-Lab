#include<stdio.h>
#include<iostream>


using namespace std;

int main(int argc, char const *argv[])
{
    int burst[] = { 9, 3, 2, 4, 3, 2 };

    int n = sizeof(burst)/sizeof(burst[0]);

    int wait[n] = {0};
    int tat[n] = {0};

    wait[0] = 0;
    tat[0] = burst[0];
    for(int i = 1; i < n; i++)
    {
        wait[i] = wait[i-1] + burst[i-1];
        tat[i] = wait[i] + burst[i];
    }

    for(int i = 0; i < n; i++)
    {
        cout<<burst[i]<<" "<<wait[i]<<" "<<tat[i]<<endl;
    }

    for(int i = 0; i < n; i++)
    {
        cout<<"P"<<i+1<<":\t";
        for(int j = 0; j < wait[i]; j++)
            cout<<" ";
        cout<<wait[i];
        for(int j = 0; j < burst[i]; j++)
            cout<<"=";
        cout<<wait[i]+burst[i];
        cout<<endl;


    }



    return 0;
}