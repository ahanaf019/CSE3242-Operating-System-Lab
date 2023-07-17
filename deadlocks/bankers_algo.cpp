#include<iostream>
#include<fstream>

using namespace std;

bool test_need(int need[], int available[], int m)
{
    for(int i = 0; i < m; i++)
    {
        if(need[i] > available[i])
            return false;
    }
    return true;
}

int main(int argc, char const *argv[])
{
    int n, m;
    
    ifstream cin("banker_input.txt");
    cin>>n>>m;
    

    int available[m];
    int max[n][m];
    int allocation[n][m];
    int need[n][m];
    bool finished[n];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin>>max[i][j];
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
        {
            cin>>allocation[i][j];
            need[i][j] = max[i][j] - allocation[i][j];
        }

    for(int i = 0; i < m; i++)
        cin>>available[i];

    for(int i = 0; i < n; i++)
        finished[i] = false;

    cout<<"done"<<endl;
    
    bool change = true;

    while(change)
    {
        change = false;
        for(int i = 0; i < n; i++)
        {
            if(test_need(need[i], available, m) && !finished[i])
            {
                for(int j = 0; j < m; j++)
                {
                    available[j] += allocation[i][j];
                    change = true;
                }
                finished[i] = true;
                cout<<i<<" "<<endl;
            }
        }
    }





    return 0;
}


