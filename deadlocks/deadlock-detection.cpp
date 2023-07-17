#include<iostream>
#include<fstream>

using namespace std;

bool test_req_avl(int request[], int available[], int m)
{
    for(int i = 0; i < m; i++)
    {
        if(request[i] > available[i])
            return false;
    }
    return true;
}

int main(int argc, char const *argv[])
{
    ifstream cin("deadlock-detection-input.txt");

    int m, n;
    cin>>m>>n;

    int request[n][m];
    int allocation[n][m];
    int available[m];
    bool finished[n];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin>>request[i][j];
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin>>allocation[i][j];

    for(int j = 0; j < m; j++)
        cin>>available[j];

    for(int i = 0; i < n; i++)
        finished[i] = false;
    
    bool change = true;

    while (change)
    {
        change = false;

        for(int i = 0; i < n; i++)
        {
            
            if(test_req_avl(request[i], available, m) && !finished[i])
            {
                finished[i] = true;

                for(int j = 0; j < m; j++)
                {
                    available[j] += allocation[i][j]; 
                }
                cout<<i<<endl;
                change = true;
                
            }
            
        }
    }
    

    return 0;
}
