#include<bits/stdc++.h>
using namespace std;
int Evaluate(int a, int b, char c)
{
    if(c == '+')
        return a+b;
    else if(c == '-')
        return a-b;
    else if(c == '*')
        return a*b;
    else if(c == '/')
        return a/b;
    else
        return -1;
}
double EvaluatePostfix(string a)
{
    stack<int> s;
    for(int i=0 ; a[i]!='\0' ; i++)
    {
        if(a[i]==' ')
            continue;

        else if(a[i]>='0'&&a[i]<='9')
            {
                int k = 0;
                while(i<a.length()&&a[i]>='0'&&a[i]<='9')
                {
                    k = (k*10) + (a[i] - '0');
                    i++;
                }
                i--;
                s.push(k);
            }

        else if(a[i]=='+'||a[i]=='-'||a[i]=='*'||a[i]=='/')
        {
            int val2 = s.top();
            s.pop();
            int val1 = s.top();
            s.pop();
            s.push(Evaluate(val1,val2,a[i]));
        }
        else
            continue;
    }
    return s.top();
}
int main()
{
    string a;
    cout<<"ENTER STRING ";
    getline(cin,a);
    cout<<"ANSWER IS "<<EvaluatePostfix(a);
}
