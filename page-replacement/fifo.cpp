#include<iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int refs[] = { 7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1 };
    int frame_size = 3;
    int n = sizeof(refs)/sizeof(refs[0]);

    int page_faults = 0;
    int frames[frame_size];
    for(int i = 0; i < frame_size; i++)
    {
        frames[i] = -1;
    }

    int j = 0;
    for(int i = 0; i < n; i++)
    {
        cout<<refs[i]<<"\t";
        bool hit = false;
        for(int k = 0; k < frame_size; k++)
        {
            if(frames[k] == refs[i])
            {
                hit = true;
                cout<<"Hit!!"<<endl;
                break;
            }
        }

        if(!hit)
        {
            frames[j] = refs[i];
            j = (j+1)%frame_size;
            page_faults += 1;

            for(int k = 0; k < frame_size; k++)
            {
                if(frames[k] != -1)
                    cout<<frames[k]<<" ";
            }
            cout<<endl;
        }
    }
    
    cout<<"Total Page faults: "<<page_faults<<endl;

    return 0;
}
