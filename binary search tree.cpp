#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node* left;
    node* right;
};

node* createNode(int x)
{
    node *newNode= new node();;
    newNode->data = x;
    newNode->left = NULL;
    newNode->right = NULL;

return newNode;
}

node* findMin(node* root)
{
	while(root->left != NULL) root = root->left;
	return root;
}

node* insertion(node *root, int data)
{
    if(root == NULL)                root = createNode(data);
    else if(data <= root->data)     root->left = insertion(root->left,data);
    else                            root->right = insertion(root->right,data);

return root;
}

node* deleteNode(node* root, int data)
{
    if(root == NULL) return root;
    else if(data < root->data) root->left = deleteNode(root->left,data);
    else if(data > root->data) root->right = deleteNode(root->right,data);
    else
    {
        if(root->left == NULL && root->right == NULL)
        {
            free(root);
            root = NULL;
        }

        else if(root->left == NULL)
        {
            node *temp = root;
            root = root->right;
            free(temp);
        }

        else if(root->right == NULL)
        {
            node *temp = root;
            root = root->left;
            free(temp);
        }

        else
        {
            node *temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right,temp->data);
            free(temp);
        }
    }
return root;
}

bool searchTree(node* root, int data)
{
    if(root == NULL)            return false;
    else if(root->data == data) return true;
    else if(data <= root->data) return searchTree(root->left,data);
    else                        return searchTree(root->right,data);
}

void inorder(node* root)
{
    if(!root) return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

int main()
{
    node* root=NULL;

    int sample[10] = {10,3,50,55,-32,99,44,38,94,100};

        for(int i=0;i<10;i++)
        root=insertion(root,sample[i]);

    inorder(root);
    root = deleteNode(root,-32);
    printf("\nAfter  deletion: \n");
    inorder(root);
}
