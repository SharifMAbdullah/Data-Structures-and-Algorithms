#include <bits/stdc++.h>
using namespace std;
int cnt=1;

bool CheckDuplicate(char str[], int start, int curr)
{
    for (int i = start; i < curr; i++)
        if (str[i] == str[curr])
            return 0;
    return 1;
}
void permute(char s[], int left, int right)
{
    if (left >= right) {
        cnt++;
        cout << s << endl;
        return;
    }

    for (int i = left; i < right; i++) {


        bool check = CheckDuplicate(s, left, i);//This function checks if we are permuting a duplicate
        if (check) {
            swap(s[left], s[i]);
            permute(s, left + 1,right);
            swap(s[left], s[i]);
        }
    }
}
int main()
{
    char a[100];
    scanf("%s",a);
    int n = strlen(a);
    permute(a, 0, n);
    cout<<"Total steps: "<<cnt-1<<endl;
}
