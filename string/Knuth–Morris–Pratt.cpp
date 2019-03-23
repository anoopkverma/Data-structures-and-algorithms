#include <bits/stdc++.h>
using namespace std;
int lps[10005];
void find_lps(string pat) {
    int n = pat.length();
    int i=1;
    int len=0;
    while(i<n) {
        if(pat[i]==pat[len]) {
            len++;
            lps[i]=len;
            i++;
        }
        else {
            if(len!=0)
                len = lps[len-1];
            else {
                lps[i]=0;
                i++;
            }
        }
    }
}
void kmp_search(string text, string pat) {
    int i=0, j=0;
    int len_text=text.length();
    int len_pat = pat.length();
    while(i<len_text) {
        if(text[i]==pat[j]) {
            i++;
            j++;
        }
        else {
            if(j!=0) 
                j = lps[j-1];
            else 
                i++;
        }
        if(j==len_pat) {
            cout<<(i-len_pat)<<endl;
            //return (i-len_pat);
        }
    }
    //return -1;
}
    
int main() {
    string text, pat;
    cin>>text>>pat;
    int l=pat.length();
    find_lps(pat);
    for(int i=0;i<l;i++) {
        cout<<lps[i]<<' ';
    }
    cout<<endl;
    kmp_search(text, pat);   
}
