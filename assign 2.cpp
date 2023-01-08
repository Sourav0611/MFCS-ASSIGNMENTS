/* QUESTION 2 ) GIVEN WELL FORMED FORMULA GENRATE COMBIANTIONS*/

#include <bits/stdc++.h>
using namespace std;


int solve(string& s, vector<int>& v, int m, int n)
{

    if(m-n==3)
    {
        if(s[n-1]=='0' || v[s[n-1]-'a']==0)
            return 1;
        else
            return 0;
    }
    else
    {
        int op1 , op2;
        if(s[m+1]=='0' || s[m+1]=='1')
            op1 = s[m+1]-'0';
        else
            op1 = v[s[m+1]-'a'];

        if(s[n-1]=='0' || s[n-1]=='1')
            op2 = s[n-1]-'0';
        else
            op2 = v[s[n-1]-'a'];

        int t= (m+n)/2;

        if(s[t]=='&')
        {
            if(op1==1 && op2==1)
                return 1;
            else
                return 0;
        }
        if(s[t]=='|')
        {
            if(op1==1 || op2 == 1)
                return 1;
            else
                return 0;
        }
        if(s[t]=='>')
        {
            if(op1==1 && op2 ==0)
                return 0;
            else
                return 1;

        }
        if(s[t]=='^')
        {
            if((op1==1 && op2==0) || (op1==0 && op2==1))
                return 0;
            else
                return 1;
        }

    }

}

int Evaluate(string& s, vector<int>& value)
{
    int sol;
    bool flag=true;
    while(flag)
    {
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==')')
            {
                int j=i-1;
                while(s[j]!='(' && j>=0)
                        j--;
                sol = solve(s,value, j, i);
                s[i] = '0'+sol;
                s.erase(s.begin()+j,s.begin()+i);


                i=0;
            }

        }
        flag= false;

    }

    return s[0]-'0';

}




int main()
{
    int n;char ch;
    string s;
    vector<int> value;
    cout<<"\n Instructions : Negation = '!' Conjuction = '&' Disjunction = '|' Conditional = '>' Biconditional = '^'";
    cout<<"\nHow many variable u want to give: ";
    cin>>n;
    cout<<"\nInput your expression (without any space between them and only two variable can be there in a parenthesis) : ";
    cin>>s;
    cout<<"\nEnter the values of variables ( in 0 - False and 1 - True form)\n";

    for(int i=0;i<n;i++)
    {
        char show = 'a'+i;
        int temp;
        cout<<"\n"<<show<<" = ";
        cin>>temp;
        value.push_back(temp);
    }

    cout<<"\n\n";
   cout<<Evaluate(s,value);

    return 0;

}
