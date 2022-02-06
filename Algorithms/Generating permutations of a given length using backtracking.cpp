#include <bits/stdc++.h>
using namespace std;
set<string> duplicate;

void comb(int start, string ch, int size, int choice, string ans){

    if(ans.size() == choice && duplicate.count(ans)==0){
        cout <<ans << endl;
        duplicate.insert(ans);
    }
    else{
        // combination made
        for(int i = start; i<=size; i++){
            // add letters to ans for making new combination each time
            ans += ch[i];
            comb(i+1,ch,size,choice,ans);
            // backtracking
            ans.pop_back();
        }
    }
}

int main(){

    string s, ans="";
    cout << "Enter the string: ";
    cin >> s;

    int n = s.size();
    int k;
    cout << "Enter the value of k: ";
    cin >> k;

    comb(0,s,n-1,k,ans);

    cout << "Total Number of Combination: " << duplicate.size() << endl;
}
