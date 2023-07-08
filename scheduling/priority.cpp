#include<iostream>

using namespace std;

struct Process{
    int burst;
    int wait;
    int tat;
    int pid;
    int priority;
};

void sort(Process* arr, int n);


int main(int argc, char const *argv[])
{
    int burst[] = { 5, 3, 6, 4, 2 };
    int priority[] = { 2, 1, 4, 3, 5 };

    int n = sizeof(priority)/sizeof(priority[0]);

    Process process[n];
    for(int i = 0; i < n; i++)
    {
        Process p;
        p.burst = burst[i];
        p.pid = i;
        p.wait = 0;
        p.tat = 0;
        p.priority = priority[i];
        process[i] = p;
    }

    sort(process, n);

    process[0].wait = 0;
    process[0].tat = process[0].burst;
    for(int i = 1; i < n; i++)
    {
        process[i].wait = process[i-1].wait + process[i-1].burst;
        process[i].tat = process[i].wait + process[i].burst;
    }

    for(int i = 0; i < n; i++)
    {
        cout<<process[i].pid<<" "<<process[i].priority<<" "<<process[i].burst<<" "<<process[i].wait<<" "<<process[i].tat<<endl;
    }

    for(int i = 0; i < n; i++)
    {
        cout<<"Process"<<process[i].pid<<":\t";
        for(int j = 0; j < process[i].wait; j++)
            cout<<" ";
        cout<<process[i].wait;
        for(int j = 0; j<process[i].burst; j++)
            cout<<"=";
        cout<<process[i].wait+process[i].burst;
        cout<<endl;

    }


    return 0;
}


void sort(Process* arr, int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = i; j < n; j++)
        {
            if(arr[i].priority < arr[j].priority)
            {
                swap(arr[i], arr[j]);
            }
        }
    }
}
