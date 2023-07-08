#include<iostream>

using namespace std;

struct Process{
    int pid;
    int burst;
    int wait;
    int tat;
    int rt;

};

int main()
{
    int burst[] = {24, 3, 3};
    int q = 4;

    int n = sizeof(burst)/sizeof(burst[0]);

    Process process[n];

    int tb = 0;
    for(int i = 0; i < n; i++)
    {
        Process p;
        p.burst = burst[i];
        p.wait = 0;
        p.tat = 0;
        p.rt = burst[i];
        p.pid = i;
        process[i] = p;
        tb += burst[i];
    }


    int t = 0;

    while(t < tb)
    {

        for(int i = 0; i < n; i++)
        {
            if(process[i].rt <= q && process[i].rt > 0)
            {
                cout<<"Process"<<process[i].pid<<":\t";
                for(int j = 0; j<t; j++)
                    cout<<" ";

                cout<<t;
                for(int j = 0; j<process[i].rt; j++)
                    cout<<"=";

                cout<<t+process[i].rt;
                cout<<endl;

                t += process[i].rt;
                process[i].rt = 0;
                process[i].tat = t;
                process[i].wait = t - process[i].burst;
            }

            else if(process[i].rt > q)
            {
                cout<<"Process"<<process[i].pid<<":\t";
                for(int j = 0; j<t; j++)
                    cout<<" ";
                cout<<t;
                for(int j = 0; j<q; j++)
                    cout<<"=";
                cout<<t+q;
                cout<<endl;

                process[i].rt -= q;
                t += q;
            }
        }
    }

    for(int i = 0; i < n; i++)
    {
        cout<<process[i].pid<<" "<<process[i].burst<<" "<<process[i].wait<<" "<<process[i].tat<<endl;
    }




    return 0;
}