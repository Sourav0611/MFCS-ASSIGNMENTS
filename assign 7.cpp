/* QUESTION 7 ) CONVERT GIVEN FORMULA IN PCNF */

#include<bits/stdc++.h>
using namespace std;


int solve(string s, vector<int> v, int m, int n)
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

int Evaluate(string s, vector<int> value)
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


string pcnf(string s,int n)
{
    int m =1<<n;
    int c=m;
    int* A = new int[m*n];
    for(int j=0;j<n;j++)
    {   bool flag = true;int tf = 0;
        c = c/2;
        for(int i=0;i<m;i++)
        {
            if(flag==true)
            {
                *(A + i*n + j)=0;
                tf++;
            }
            else
            {
                *(A + i*n + j)=1;
                tf++;
            }
            if(tf==c)
            {
                flag= !flag;
                tf = 0;
            }
        }
    }
    string ans="";
    for(int i=0;i<m;i++)
    {
        vector<int> val;
        for(int j=0;j<n;j++)
            val.push_back(*(A + i*n + j));


        if(Evaluate(s,val)==0)
        {
            ans +=" (";
            for(int k=0;k<val.size();k++)
            {
                if(val[k]==1)
                {
                    ans.push_back('a'+k);
                    ans +="|";
                }
                else
                {
                    ans +="(!";
                    ans.push_back('a'+k);
                    ans +=")|";
                }
            }
            ans[ans.length()-1]=')';
            ans += " &";
        }
    }
   ans[ans.length()-1]=' ';
    return ans;
}


int main()
{
    int n;char ch;
    string s;
    vector<int> value;
    cout<<"\n Instructions : -> Negation = '!' Conjuction = '&' Disjunction = '|' Conditional = '>' Biconditional = '^'";
    cout<<"\n  -> Expression should have no space and only two variable can be there in a parenthesis()";
    cout<<"\n Don't put | "<<endl;
    cout<<"\n\nHow many variable u want to give: ";
    cin>>n;
    cout<<"\nInput your expression : ";
    cin>>s;

    cout<<"\n\n Pcnf = "<<pcnf(s,n);

    return 0;

}


