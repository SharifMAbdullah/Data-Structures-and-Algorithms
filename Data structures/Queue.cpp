#include <bits/stdc++.h>
using namespace std;
#define N 5
#define SHOW printf("Current Queue: ")
int queuee[N];
int front = -1, rear = -1;

void enqueue(int x)
{
    if(rear == N-1) printf("Overflow\n");
    else if(front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
        queuee[rear] = x;
    }
    else
    {
        rear++;
        queuee[rear] = x;
    }
}

void dequeue()
{
    if(front == -1 && rear == -1) printf("Queue empty\n");
    else if(front==rear) front = rear = -1;
    else
    {
        printf("Deleted %d\n",queuee[front]);
        front++;
    }
}

void display()
{
    int i=front;
    if(front == -1 && rear == -1) printf("Queue empty\n");
    else
    {
        while(i<rear+1)
        {
            printf("%d ",queuee[i]);
            i++;
        }
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
    SHOW; display();
    dequeue();
    SHOW; display();
    puts("");
    peek();
    puts("");
    dequeue();
    dequeue();
    return 0;
}
