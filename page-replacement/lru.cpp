#include<iostream>

using namespace std;


int main(int argc, char const *argv[])
{
    int refs[] = { 7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1 };
    int frame_size = 3;
    int n = sizeof(refs)/sizeof(refs[0]);

    int page_faults = 0;
    int frames[frame_size];
    int used[frame_size];
    for(int i = 0; i < frame_size; i++)
    {
        frames[i] = -1;
        used[i] = 0;
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
                used[k] = i;
                break;
            }
        }

        if(!hit)
        {
            int least = INT16_MAX;
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
                    if(used[k] < least)
                    {
                        least = used[k];
                        idx = k;
                    }
                }
            }

            used[idx] = i;
            frames[idx] = refs[i];
            page_faults += 1;


            for(int k = 0; k < frame_size; k++)
            {
                if(frames[k] != -1)
                    cout<<frames[k]<<" ";
            }
            cout<<"\t";
            for(int k = 0; k < frame_size; k++)
            {
                
                cout<<used[k]<<" ";
            }
            cout<<endl;
        }
    }
    cout<<"Total Page faults: "<<page_faults<<endl;




    return 0;
}
