#include<bits/stdc++.h>
using namespace std;

struct node
{
int data;
node *next;
node *prev;
};

node *head= NULL, *tail=NULL, *newNode;

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
    node *temp = head;

    if (temp == NULL)
    {
		return;
	}

    while(temp->next !=NULL)
    {
    printf("%d ", temp -> data);
    temp = temp -> next;
    }
    printf("%d ",temp->data);
    puts("");
}

void printListBackwards()
{
    node *temp = tail;

    if (temp == NULL)
    {
		return;
	}

    while(temp->prev !=NULL)
    {
    printf("%d ", temp -> data);
    temp = temp -> prev;
    }
printf("%d ",temp->data);
puts("");
}

void insertAtFront(int x)
{
    node *newNode;

    newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data = x;
    newNode->next = NULL;
    newNode->prev = NULL;

    if(head==NULL)
        {
        head = tail = newNode;
        return;
        }

    head->prev = newNode;
    newNode->next = head;
    head = newNode;
}

void insertAtEnd(int x)
{
    node *newNode;

    newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data = x;
    newNode->next = NULL;
    newNode->prev = NULL;

    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

void createNodeNotUsingTail()
{
    node  *temp;

    node *newNode= new node();
    newNode -> next = NULL;
    newNode->prev = NULL;

    int number;
    printf("Enter data:\n");
    scanf("%d",&number);

    newNode -> data = number;

    if(head==NULL)
        {
        head = temp = newNode;
        return;
        }

    else
    {
        temp->next = newNode;
        newNode->prev = temp;
        temp = newNode;
    }

}

void createNodeUsingTail()
{
    node *newNode= new node();
    newNode -> next = NULL;
    newNode->prev = NULL;

    int number;
    printf("Enter data:\n");
    scanf("%d",&number);

    newNode -> data = number;

    if(head==NULL)
        {
        head = tail = newNode;
        return;
        }

    else
    {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

}

void insertAtAGivenPoint(int x, int position)
{
    node  *temp;
    node *newNode= new node();
    int length = lengthOfList();

    if(position > length || position < 0) printf("INVALID");

    else
    {
        temp = head;
        int counter = 0;

        while(counter < position-1)
        {
            temp = temp->next;
            counter++;
        }

        newNode->data = x;
        newNode->prev = temp;
        newNode->next = temp->next;


        temp->next->prev = newNode;
        temp->next = newNode;
    }
}

int main()
{

int n;

// printf("How many data do you want to enter?\n");
// scanf("%d",&n);

// while(n--)
// {
// createNodeUsingTail();
// }

//insertion of new node

insertAtFront(5);
insertAtFront(10);
insertAtEnd(121);
insertAtEnd(510);
insertAtAGivenPoint(420,2);
printList();
printListBackwards();
//int len=lengthOfList();
//printf("%d",len);
}
