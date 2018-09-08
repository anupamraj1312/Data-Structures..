#include <bits/stdc++.h>
using namespace std;
class employeee
{
public:
    string name;
    int salary;
    int id;
    int count=0;
    employeee()
    {
        cout<<"\nEnter the name: ";
        cin>>name;
        cout<<"\nEnter the salary: ";
        cin>>salary;
        cout<<"\nEnter the id: ";
        cin>>id;
    }
int searchsal(int k)
{

    if(salary>k)
    {
        cout<<name<<endl;
        count++;
    }
    return count;
}

};
bool compare(employeee e1, employeee e2) {
    if(e1.salary == e2.salary) {
        return e1.id < e2.id;
    }
    return e1.salary < e2.salary;
}
int main()
{
    int c,a;
    cout<<"Enter the total no of employees: ";
    cin>>c;
    employeee e[c];
    for(int i=0; i<c ;i++)
    {
        e[i];
    }
    int k;
    cout<<"Enter the salary above which you want to search: "<<endl;
    cin>>k;
    for(int i=0; i<c ;i++)
    {
        a=e[i].searchsal(k);
    }
    if(a==0)
        cout<<"\nSalary not found."<<endl;
    cout<<"List of employees sorted according to their salaries are : "<<endl;
    sort(e, e + c, compare);
    for(int i=0; i<c ;i++)
    {
        cout<<e[i].name<<endl;
    }
    return 0;
}
