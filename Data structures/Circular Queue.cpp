#include<bits/stdc++.h>
using namespace std;
#define N 5
int queuee[N];
int front=-1, rear=-1;

void enqueue(int x)
{
    if(front == -1 && rear == -1)
    {
        front = rear = 0;
        queuee[rear] = x;
    }
    else if( (rear+1)%N == front) printf("Overflow\n");
    else
    {
        rear = (rear+1)%N;
        queuee[rear] = x;
    }
}

void dequeue()
{
    if(front == -1 && rear == -1) printf("Queue empty\n");
    else if(front==rear)
    {
        printf("Deleted %d\n",queuee[front]);
        front = rear = -1;
    }
    else
    {
        printf("Deleted %d\n",queuee[front]);
        front = (front+1)%N;
    }
}

void display()
{
    int i=front;
    if(front == -1 && rear == -1) printf("Queue empty\n");
    else
    {
        while(i!=rear)
        {
            printf("%d ",queuee[i]);
            i = (i+1)%N;
        }
    printf("%d",queuee[rear]);
    }
}

void peek()
{
    if(front == -1 && rear == -1) printf("Queue empty\n");
    else
    {
        printf("The frontmost data is %d",queuee[front]);
    }
}
int main()
{

    enqueue(420);
    enqueue(121);
    enqueue(33);
    enqueue(123);
    enqueue(444);
    dequeue();
    enqueue(911);
    display();
    return 0;
}
