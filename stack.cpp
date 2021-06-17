#include<iostream>
using namespace std;

int stack[100];
int top = -1;

void display()
{
    int i;
    for(i=top;i<0;i--)
        cout << stack[i];
}
void push(int sizee, int data)
{

if(top == sizee-1) cout << "Overflow";
else
    {
    top++;
    stack[top] = data;
    }
}

void pop(int sizee)
{
int temp;
top= sizee;

    if(top == sizee-1) cout << "Underflow";
    else
    {
        temp = stack[top];
        top--;
        cout << temp;
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

display();

pop(n);
display();
}
