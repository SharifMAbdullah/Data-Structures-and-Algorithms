#include<bits/stdc++.h>
using namespace std;

bool compare(const pair<int,int> &a,const pair<int,int> &b)
{
    return (a.second<b.second);
}

int main()
{
int n,start[100],endd[100];
vector<pair<int,int>> times; //1st element is start, 2nd is finish time

freopen("inputActivitySelector.txt","r",stdin);
scanf("%d",&n);
for(int i=0;i<n;i++)
scanf("%d",&start[i]);
for(int i=0;i<n;i++)
scanf("%d",&endd[i]);

for(int i=0;i<n;i++)
    {
        times.push_back(make_pair(start[i],endd[i]));
    }

sort(times.begin(),times.end(),compare);

cout << "Sorted pairs" << endl;
for(int i=0;i<n;i++)
        cout << times[i].first <<" ";
        cout<<endl;
for(int i=0;i<n;i++)
        cout << times[i].second << " ";
        cout<<endl;

cout << "Greedy choice of activities: " << endl;
for(int j=0;j<n;j++)
    {
    for(int i=0;i<n;i++)
        {
        if(times[i].first - times[j].second == 1 || times[i].first - times[j].second == 0)
            {
            cout << j+1 << " ";
            j = i;
            }
        }
    cout << j+1 << " ";
    }
}
