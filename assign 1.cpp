/* QUESTION 1 )  GENERATE ALL POSSIBLE COMBINATION OF N PROPOSITIONAL VARIABLES */

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int k;
    cout<<"Enter n : "; 
    cin>>k;

    int l =1<<k;
    int c=l;
    int* A = new int[l*k];
    for(int j=0;j<k;j++)
    {   bool flag = true;int tf = 0;
        c = c/2;
        for(int i=0;i<l;i++)
        {
            if(flag==true)
            {
                *(A + i*k + j)=0;
                tf++;
            }
            else
            {
                *(A + i*k + j)=1;
                tf++;
            }
            if(tf==c)
            {
                flag= !flag;
                tf = 0;
            }
        }
    }

    cout<<"\nTruth Table : \n";

    for(int i=0;i<l;i++)
    {
        for(int j=0;j<k;j++)
            {
                if(*(A + i*k + j))
                    cout<<" T ";
                else
                    cout<<" F ";
            }
        cout<<"\n";
    }
/*
     for (int i = 0; i < m; i++)
        {
            delete[] A[i];
        }
*/
     delete[] A;
    return 0;
}
