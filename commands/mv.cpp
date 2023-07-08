#include<iostream>
#include<stdio.h>
#include<errno.h>
#include<stdlib.h>

using namespace std;

int main(int argc, char const *argv[])
{
    if((rename(argv[1], argv[2])) == 0)
    {
        cout<<"move successful."<<endl;
    }
    return 0;
}
