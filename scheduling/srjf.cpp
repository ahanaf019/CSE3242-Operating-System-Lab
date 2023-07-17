#include<iostream>
#include<fstream>

using namespace std;

struct Process{
    int arrival;
    int burst;
    int wait;
    int tat;
    int rt;
    int pid;
};


int main(int argc, char const *argv[])
{
    ifstream cin("input.txt");
    int n;
    cin>>n;
    int burst, arrival;
    Process process[n];

    for(int i = 0; i < n; i++)
    {
        cin>>arrival>>burst;
        Process p;
        p.pid = i+1;
        p.arrival = arrival;
        p.burst = burst;
        p.rt = burst;
        p.wait = 0;
        p.tat = 0;
        process[i] = p;
    }

    int t = 0;
    int finished = 0;

    while (finished != n)
    {
        int small = INT16_MAX;
        int idx = -1;
        for(int i = 0; i < n; i++)
        {
            if(process[i].arrival <= t && process[i].rt < small && process[i].rt > 0)
            {
                small = process[i].rt;
                idx = i;
            }
        }

        cout<<process[idx].pid;


        process[idx].rt -= 1;

        if(process[idx].rt == 0)
        {
            process[idx].wait = t - process[idx].burst;
            process[idx].tat = t;
            finished += 1;
        }

        t += 1;
    }
    

    return 0;
}
