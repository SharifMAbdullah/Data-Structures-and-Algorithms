#include<iostream>
using namespace std;

int stack[100];
int top = -1;

void push(int sizee, int data)
{

if(top == sizee-1) cout << "Overflow";
else
    {
    top++;
    stack[top] = data;
    }
}

int main()
{
int n,i;
int data;
cout << "How many data do you want to insert?\n";
cin >> n;

for(i=0;i<n;i++)
    {

    cout << "Enter data:\n";
    cin >> data;
    push(n , data);
    }
for(i=0;i<n;i++)
    cout << stack[i]);
}
