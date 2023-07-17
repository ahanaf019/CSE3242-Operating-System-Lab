#include<iostream>
#include<stdio.h>
#include<string.h>
#include<fstream>

using namespace std;


int main(int argc, char const *argv[])
{

    if(strcmp(argv[1], "-create") == 0)
    {
        printf("Creating %s\n", argv[2]);
        FILE *f = fopen(argv[2], "w");
        fclose(f);
        printf("Successfully created file.\n");
        return 0;
    }

    if(strcmp(argv[1], "-del") == 0)
    {
        remove(argv[2]);
        printf("Successfully deleted %s.\n", argv[2]);
        return 0;
    }

    if(strcmp(argv[1], "-move") == 0)
    {
        rename(argv[2], argv[3]);
        printf("Successfully moved \"%s\" to \"%s\".\n", argv[2], argv[3]);
        return 0;
    }

    if(strcmp(argv[1], "-copy") == 0)
    {
        ifstream in(argv[2], ios::binary);
        ofstream out(argv[3], ios::binary);

        string line;
        while (getline(in, line))
        {
            out << line<<'\n';
        }
        cout<<"Coppied successfully.\n";
    }



    

    
    return 0;
}
