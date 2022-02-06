#include<stdio.h>
#include<stdlib.h>

struct node
{
int data;
struct node *next;
};

struct node *head= NULL;

void printList()
{
    struct node *temp;
    temp = head;

    while(temp -> next !=0)
    {
    printf("%d ", temp -> data);
    temp = temp -> next;
    }

    printf("%d",temp->data);
}




void insertAtStart(int x)
{
    struct node *temp;

    temp = (struct node*) malloc(sizeof(struct node));

    temp ->data = x;
    temp -> next = head;
    head = temp;
}

int main()
{

//head=0;
//int n;
//
//printf("How many data do you want to enter?\n");
//scanf("%d",&n);
//
//while(n--)
//    {
//    newNode= (struct node *) malloc(sizeof(struct node));
//
//    int number;
//    printf("Enter data:\n");
//    scanf("%d",& number);
//
//    newNode -> data = number;
//    newNode -> next = 0;
//
//    if(head==0) head=temp=newNode;
//
//        else
//        {
//        temp->next = newNode;
//        temp= newNode;
//        }
//    }
//temp = head;

//insertion of new node

insertAtStart(5);
insertAtStart(10);
printList();


}
