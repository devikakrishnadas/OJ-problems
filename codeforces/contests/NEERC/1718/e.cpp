#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vc vector<char>
#define vll vector<ll>
#define pb push_back
#define sf scanf
#define ff first
#define M 1000000007
#define ss second
#define pf printf
#define mp make_pair
#define all(V) V.begin(),V.end()

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    int n;
    cin>>n;
    string s;
    cin>>s;
    vi reveal(300,0);
    vi noReveal;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]!='*')
        {
            reveal[s[i]]=1;
        }
        else
        {
            noReveal.pb(i);
        }
    }
    int m;
    cin>>m;
    vector<string>A;
    for(int i=0;i<m;i++)
    {
        string t;
        cin>>t;
        A.pb(t);
    }
    vi hidden(m+1,1);
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<noReveal.size();j++)
        {
            if(reveal[A[i][noReveal[j]]])
            {
//                cout<<"enter"<<endl;
                hidden[i]=0;
            }
        }
    }
//    cout<<"r2"<<endl;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]!='*')
        {
            for(int j=0;j<m;j++)
            {
                if(i<A[j].size() && hidden[j])
                {
                    if(A[j][i]!=s[i])
                    {
                        hidden[j]=0;
                        break;
                    }
                }
            }
        }
    }
    int B[1001][300]={0};
    for(int i=0;i<m;i++)
    {
        if(!hidden[i]) continue;
        for(int j=0;j<noReveal.size();j++)
        {
  //          cout<<A[i][noReveal[j]]<<endl;
            B[i][A[i][noReveal[j]]]++;
        }
    }
//    cout<<"r1"<<endl;
    int cnt=0;
    for(int i='a';i<='z';i++)
    {
        int mi=INT_MAX;
        for(int j=0;j<m;j++)
        {
            if(!hidden[j]) continue;
            mi=min(mi,B[j][i]);
        }
        if(mi!=INT_MAX)
            cnt+=mi;
    }
    cout<<cnt<<endl;
	return 0;
}

