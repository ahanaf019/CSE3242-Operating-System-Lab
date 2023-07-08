#include<iostream>

using namespace std;


int main(int argc, char const *argv[])
{
    // int refs[] = { 7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1 };
    int refs[] = { 5, 0, 1, 3, 2, 4, 1, 0, 5 };
    int frame_size = 4;
    int n = sizeof(refs)/sizeof(refs[0]);

    int page_faults = 0;
    int frames[frame_size];
    int used[frame_size];
    int arrival[frame_size];
    for(int i = 0; i < frame_size; i++)
    {
        frames[i] = -1;
        arrival[i] = -1;
        used[i] = -1;
    }

    for(int i = 0; i < n; i++)
    {
        bool hit = false;
        cout<<refs[i]<<"\t";
        for(int k = 0; k < frame_size; k++)
        {
            if(refs[i] == frames[k])
            {
                cout<<"Hit!!"<<endl;
                hit = true;
                used[k] += 1;
                break;
            }
        }

        if(!hit)
        {
            int least = INT16_MAX;
            int arv = INT16_MAX;
            int k, idx;
            for(k = 0; k < frame_size; k++)
            {
                if(frames[k] == -1)
                {
                    idx = k;
                    break;
                }

                else
                {
                    if(used[k] <= least && arrival[k] < arv)
                    {
                        least = used[k];
                        arv = arrival[k];
                        idx = k;
                    }
                }
            }

            used[idx] = 0;
            arrival[idx] = i;
            frames[idx] = refs[i];
            page_faults += 1;


            for(int k = 0; k < frame_size; k++)
            {
                if(frames[k] != -1)
                    cout<<frames[k]<<" ";
            }
            // cout<<"\t";
            // for(int k = 0; k < frame_size; k++)
            // {
                
            //     cout<<used[k]<<" ";
            // }

            // cout<<"\t";
            // for(int k = 0; k < frame_size; k++)
            // {
                
            //     cout<<arrival[k]<<" ";
            // }
            cout<<endl;
        }
    }
    cout<<"Total Page faults: "<<page_faults<<endl;




    return 0;
}
