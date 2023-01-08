/*QUESTION 3 ) CONVERT 1)INFIX TO POSTFIX
                       2)POSTFIX TO INFIX */

#include<bits/stdc++.h>
using namespace std;

bool isOperator(char c)
{
	if(c=='+'||c=='-'||c=='*'||c=='/'||c=='^')
	{
		return true;
	}
	else
	{
		return false;
	}
}

int precedence(char c) 
{ 
    if(c == '^') 
    return 3; 
    else if(c == '*' || c == '/') 
    return 2; 
    else if(c == '+' || c == '-') 
    return 1; 
    else
    return -1; 
} 
bool isOperand(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
        return true;
    }
    else {
        return false;
    }
}
string PostfixToInfix(string postfix)
{
    stack<string> s;
    for (int i = 0; i < postfix.length(); i++) {
        if (isOperand(postfix[i])) {
            string op(1, postfix[i]);
            //string op=postfix[i];
            s.push(op);
        }
        else {
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();
            s.push("(" + op2 + postfix[i] + op1 + ")");
        }
    }

    return s.top();
}
string InfixToPostfix(stack<char> s, string infix)
{
	string postfix;
	for(int i=0;i<infix.length();i++)
	{
		if((infix[i] >= 'a' && infix[i] <= 'z')
		||(infix[i] >= 'A' && infix[i] <= 'Z'))
		{
			postfix+=infix[i];
		}
		else if(infix[i] == '(')
		{
			s.push(infix[i]);
		}
		else if(infix[i] == ')')
		{
			while((s.top()!='(') && (!s.empty()))
			{
				char temp=s.top();
				postfix+=temp;
				s.pop();
			}
			if(s.top()=='(')
			{
				s.pop();
			}
		}
		else if(isOperator(infix[i]))
		{
			if(s.empty())
			{
				s.push(infix[i]);
			}
			else
			{
				if(precedence(infix[i])>precedence(s.top()))
				{
					s.push(infix[i]);
				}	
				else if((precedence(infix[i])==precedence(s.top()))&&(infix[i]=='^'))
				{
					s.push(infix[i]);
				}
				else
				{
					while((!s.empty())&&( precedence(infix[i])<=precedence(s.top())))
					{
						postfix+=s.top();
						s.pop();
					}
					s.push(infix[i]);
				}
			}
		}
	}
	while(!s.empty())
	{
		postfix+=s.top();
		s.pop();
	}
	
	return postfix;
}

int main() 
{  
  int num;
    cout<<"FOR INFIX TO POSTFIX ENTER '1' & FOR POSTFIX TO INFIX ENTER '2' "<<endl;
    cin>>num;
     string infix, postfix;
    if(num==1){
    cout<<"Enter a Infix Expression :"<<endl;
  	cin>>infix;
  	stack <char> stack;
	cout<<"INFIX EXPRESSION: "<<infix<<endl;
  	postfix = InfixToPostfix(stack,infix);
  	cout<<endl<<"POSTFIX EXPRESSION: "<<postfix;
    }
    else if(num==2){
    
    cout << "Enter a POSTFIX Expression :" << endl;
    cin >> postfix;
    cout << "POSTFIX EXPRESSION: " << postfix << endl;
    infix = PostfixToInfix(postfix);
    cout << endl
         << "INFIX EXPRESSION: " << infix;
	}
    else{
    	cout<<"wrong choice";
	}
	return 0;
}
