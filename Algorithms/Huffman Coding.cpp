#include<bits/stdc++.h>
using namespace std;

char str[1000];
set<char>chars;
map<char,int>freqs;
map<char,string>enc_list;
map<string,char>dec_list;

struct node
{
          char ch;
          int freq;
          struct node *left,*right;
};
node *priorityQ[1000];

node* new_node(char a,int f,struct node *left_child,struct node *right_child)
{
          struct node *temp=(struct node*)malloc(sizeof(struct node));
          temp->ch=a;
          temp->freq=f;
          temp->left=left_child;
          temp->right=right_child;
          return temp;

}

void encoder(struct node *temp,string s)
{
          if(temp->left==NULL&&temp->right==NULL)
          {
                enc_list[temp->ch]=s;
                dec_list[s]=temp->ch;
                cout<<temp->ch <<" : "<<s<<endl;
                return;
          }
          encoder(temp->left,s+"0");
          encoder(temp->right,s+"1");
}

void decoder(string cur_input)
{
          int i;
          string s;
          for(i=0;cur_input[i]!='\0';i++)
          {
                s.push_back(cur_input[i]);
                    if(dec_list[s]!='\0')
                        {
                            cout<<dec_list[s];
                            s="";
                        }
          }
}

void min_heapify(int n,int root)
{
          int l=root*2+1,r=root*2+2,least=root;
          if(l<n&&priorityQ[least]->freq<priorityQ[l]->freq)least=l;
          if(r<n&&priorityQ[least]->freq<priorityQ[r]->freq)least=r;
          if(priorityQ[least]->freq!=priorityQ[root]->freq)
          {
                    swap(priorityQ[least],priorityQ[root]);
                    min_heapify(n,least);
          }
}
void heap_sort(int n)
{
          int i;
          for(i=n/2-1;i>=0;i--)
                min_heapify(n,i);

          for(i=n-1;i>=0;i--)
          {
                swap(priorityQ[0],priorityQ[i]);
                min_heapify(i,0);
          }
}
void huffman_code()
{
          set<char>::iterator it;
          int i=0,n=chars.size();
          for(it=chars.begin();it!=chars.end();it++)
          {
            priorityQ[i]=new_node(*it,freqs[*it],NULL,NULL);
            i++;
          }
          heap_sort(n);

          while(n!=0)
          {
            struct node *left_child = new node, *right_child = new node;
            left_child=priorityQ[0];
            right_child=priorityQ[1];
            swap(priorityQ[0],priorityQ[n-1]);
            swap(priorityQ[1],priorityQ[n-2]);
            priorityQ[n-2]=new_node('\0',left_child->freq+right_child->freq,left_child,right_child);
            n--;
            heap_sort(n);
          }

          node *root=NULL;
          root=priorityQ[0];
          encoder(root,"");
          string pre_code;
          cout<<"Message using huffman algorithm is:"<<endl;
          for(i=0;str[i]!='\0';i++)
          {
            cout<<enc_list[str[i]];
            pre_code=pre_code+enc_list[str[i]];
          }
          cout<<"\nMessage after decoding is:"<<endl;
          decoder(pre_code);
}
int main()
{
          FILE *file;
          file=fopen("sample.txt","r");
          char a;
          int i=0;
          while((a=fgetc(file))!=EOF)
          {
            str[i]=a;
            freqs[a]++;
            chars.insert(a);
            i++;
          }
          cout<<"\nProvided message is:\n"<<str<<endl;
        huffman_code();
}
