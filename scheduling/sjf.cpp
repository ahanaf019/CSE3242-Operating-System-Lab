#include<iostream>

using namespace std;

struct Process{
    public:
    int burst;
    int pid;

    // Process(int burst, int pid)
    // {
    //     this->burst = burst;
    //     this->pid = pid;
    // }
};

void sort(Process* arr, int n);


int main(int argc, char const *argv[])
{
    int burst[] = { 9, 3, 2, 4, 3, 2 };

    int n = sizeof(burst)/sizeof(burst[0]);

    Process process[n];

    for(int i = 0; i < n; i++)
    {
        Process x;
        x.burst = burst[i];
        x.pid = i;
        process[i] = x;
    }

    sort(process, n);

    int wait[n] = {0};
    int tat[n] = {0};

    tat[0] = process[0].burst;
    for(int i = 1; i < n; i++)
    {
        wait[i] = wait[i-1] + process[i-1].burst;
        tat[i] = wait[i] + process[i].burst;
    }

    for(int i = 0; i < n; i++)
    {
        cout<<process[i].pid<<" "<<process[i].burst<<" "<<wait[i]<<" "<<tat[i]<<endl;
    }



    for(int i = 0; i < n; i++)
    {
        cout<<"P"<<process[i].pid<<":\t";
        for(int j = 0; j < wait[i]; j++)
            cout<<" ";
        cout<<wait[i];
        for(int j = 0; j < process[i].burst; j++)
            cout<<"=";
        cout<<wait[i]+process[i].burst;
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
            if(arr[i].burst > arr[j].burst)
            {
                swap(arr[i], arr[j]);
            }
        }
    }
}
