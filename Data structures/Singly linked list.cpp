#include<bits/stdc++.h>
using namespace std;

struct node
{
int data;
node *next;
};

node *head= NULL, newNode;

int lengthOfList()
{
    int counter=0;
    node *temp=head;

    while(temp!=NULL)
    {
        counter++;
        temp = temp->next;
    }

return counter;
}

void printList()
{
    node *temp;
    temp = head;

    while(temp !=NULL)
    {
    printf("%d ", temp -> data);
    temp = temp -> next;
    }


}

void insertAtFront(int x)
{
    node *temp;

    temp = (struct node*) malloc(sizeof(struct node));

    temp -> data = x;
    temp -> next = head;
    head = temp;
}

void insertAtEnd(int x)
{
    node *newNode= new node();
    node *temp;

    newNode->next = NULL;
    temp = head;

    while(temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->data = x;
}

void createNode()
{
    node  *temp;
    node *newNode= new node();

    int number;
    printf("Enter data:\n");
    scanf("%d",&number);

    newNode -> data = number;
    newNode -> next = NULL;

    if(head==NULL)
        {
        head=newNode;
        return;
        }

    temp=head;

    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;

}

void insertAtAGivenPoint(int x, int position)
{
    node  *temp;
    node *newNode= new node();
    int length = lengthOfList();

    if(position > length) printf("INVALID");

    else
    {
        temp = head;
        int counter = 1;

        while(counter < position-1)
        {
            temp = temp->next;
            counter++;
        }

        newNode->next = temp->next;
        temp->next = newNode;
        newNode->data = x;
    }
}

int main()
{

int n;

printf("How many data do you want to enter?\n");
scanf("%d",&n);

while(n--)
{
createNode();
}

//insertion of new node

insertAtFront(5);
insertAtFront(10);
insertAtEnd(121);
insertAtAGivenPoint(444,3);
printList();
int len=lengthOfList();
printf("%d",len);
}
