#include<bits/stdc++.h>
using namespace std;

bool compare(const pair<int,int> &a,const pair<int,int> &b)
{
    return (a.second>b.second);
}

int main()
{
vector<pair<float,float>> priority;
int n,W;
float w[100],b[100];
float value[100];

freopen("inputFSack.txt","r",stdin);
scanf("%d%d",&n,&W);
for(int i=0;i<n;i++) scanf("%f",&w[i]);
for(int i=0;i<n;i++) scanf("%f",&b[i]);
for(int i=0;i<n;i++) value[i] = b[i]/w[i]; //value = price of per ml
for(int i=0;i<n;i++) priority.push_back(make_pair(w[i],value[i])); //pair of weight of items and their values

sort(priority.begin(),priority.end(),compare);
int maxx = 0, i = 0;
float remW=0.0,weight=0.0; //weight = what weight has been filled
while(weight<W && i<n)
    {
    remW = W-weight;
    weight += priority[i].first;
    maxx += min(priority[i].second * priority[i].first , remW*priority[i].second);
    i++;
    }
printf("The most profit that can be gained is %d",maxx);
}
