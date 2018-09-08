#include <iostream>
#include <string>
#include <stack>
using namespace std;
bool IsPair(char a,char b)
{
    if((a == '(') && (b == ')'))
        return true;
    if((a == '[') && (b == ']'))
        return true;
    if((a == '{') && (b == '}'))
        return true;
    else
        return false;
}
bool CheckString(string a)
{
    stack<char> s;
    for(int i=0;i<a[i] != '\0' ;i++)
    {
        if((a[i] == '(') || (a[i] == '{') || (a[i] == '['))
            s.push(a[i]);
        else if((a[i] == ')') || (a[i] == '}') || (a[i] == ']'))
        {
            if(s.empty() || !IsPair(s.top(),a[i]))
                return false;
            else
                s.pop();
        }
    }
    return s.empty()?true:false;
}
int  main()
{
    cout<<"ENTER STRING  ";
    string a;
    //getline(cin,a);
    cin>>a;
    cout<<a<<endl;
    if(CheckString(a))
        cout<<"IT IS BALANCED.";
    else
        cout<<"NOT BALANCED. ";
    return 0;
}
