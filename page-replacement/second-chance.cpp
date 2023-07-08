#include<iostream>

using namespace std;


int main(int argc, char const *argv[])
{
    // int refs[] = { 7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1 };
    int refs[] = { 0, 4, 1, 4, 2, 4, 3, 4, 2, 4, 0, 4, 1, 4, 2, 4, 3, 4 };
    int frame_size = 3;
    int n = sizeof(refs)/sizeof(refs[0]);

    int page_faults = 0;
    int frames[frame_size];
    int chance[frame_size];
    for(int i = 0; i < frame_size; i++)
    {
        frames[i] = -1;
        chance[i] = -1;
    }

    int j = 0;
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
                chance[k] = 1;
                break;
            }
        }

        if(!hit)
        {

            while(true)
            {
                if(frames[j] == -1)
                {
                    frames[j] = refs[i];
                    chance[j] = 0;
                    j = (j+1)%frame_size;
                    break;
                }

                else if(chance[j] == 1)
                {
                    chance[j] = 0;
                    j = (j+1)%frame_size;
                }

                else
                {
                    frames[j] = refs[i];
                    j = (j+1)%frame_size;
                    break;
                }
            }
        
            page_faults += 1;


            for(int k = 0; k < frame_size; k++)
            {
                if(frames[k] != -1)
                    cout<<frames[k]<<" ";
            }
            cout<<"\t";
            for(int k = 0; k < frame_size; k++)
            {
                
                cout<<chance[k]<<" ";
            }

            cout<<endl;
        }
    }
    cout<<"Total Page faults: "<<page_faults<<endl;




    return 0;
}
