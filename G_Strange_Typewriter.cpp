#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
int usedKey=0;
vector<int> eraser;

void computeLPSArray(string& pat, int M, int* lps)
{
    int len = 0;
    lps[0] = 0;
    int i = 1;
    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0) {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void KMPSearch(string& pat, string& txt)
{
    int M = pat.size();
    int N = txt.size();
    int lps[M];
    computeLPSArray(pat, M, lps);

    int i = 0;
    int j = 0;
    while (i < N) {
        if (pat[j] == txt[i]) {
            j++;
            i++;
        }
        if (j == M) {
            usedKey++;
            eraser.push_back(i-j);
            j = lps[j - 1];
        }


        else if (i<N && pat[j] != txt[i]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
}

bool cmp(const string& a, const string& b)
{
    return (a.size() > b.size());
}
void solve(int l,int t){
    int n;
    cin>>n;
    string str,temp;
    vector<string > s;

    for(int i=0;i<n;i++) {
        cin>>temp;
        s.push_back(temp);
    }
    cin>>str;
    sort(s.begin(),s.end(),cmp);
    for(int i=0;i<s.size();i++){
        KMPSearch(s[i],str);
        for(int j=0;j<eraser.size();j++){

           // str.erase(str.begin()+eraser[j],str.begin()+eraser[j]+s[i].size());
            str.replace(eraser[j],s[i].size(),s[i].size(),'*');
            //cout<<eraser[j]<<str<<" "<<str.size()<<endl;
            //cout<<s[i]<<" "<<eraser[j]<<endl;
        }
        eraser.clear();

    }
    bool flag=false;
    for(int i=0;i<str.size();i++)
        if(str[i]!='*') flag=true;
    if(flag) cout<<"Case "<<l-t<<":"<<"Impossible"<<endl;
    else cout<<"Case "<<l-t<<":"<<usedKey<<endl;

    usedKey=0;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

    int t;

    cin>>t;
    int l=t;
    while(t--)
    {
        solve(l,t);
    }

}
