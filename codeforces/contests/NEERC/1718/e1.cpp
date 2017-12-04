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
    int m;
    cin>>m;
    vector<string>A;
    vi reveal(200,0);
    vi noreveal;
    for(int i=0;i<m;i++)
    {
        string t;
        cin>>t;
        A.pb(t);
    }
    // Check if given strings match with the revealed positions of the main string
    vi pwd(m+1,1);
    
    for(int j=0;j<n;j++)
    {
        if(s[j]=='*') 
        {
            continue;
        }
        reveal[s[j]]++;
        for(int i=0;i<m;i++)
        {
            if(!pwd[i]) continue;
            if(A[i][j]!=s[j])
            {
                pwd[i]=0;
            }
        }
    }
    // Check if there are words which have a revealed letter at a non revealed position
    
    for(int i=0;i<m;i++)
    {
        if(pwd[i]==0) continue;
        for(int j=0;j<n;j++)
        {
            if(s[j]=='*')
            {
                if(reveal[A[i][j]])
                {
                    pwd[i]=0;
                    break;
                }
            }
        }
    }
    
    // count the remaining letters common in every string in a non reveal position
    int cnt[1001][300]={0};
    int tm=m;
    for(int i=0;i<m;i++)
    {
        if(pwd[i]==0)
        {
            tm--;
            continue;
        }

        for(int j=0;j<n;j++)
        {
            if(s[j]=='*')
            {
                cnt[i][A[i][j]]++;
            }
        }
    }
    int ans=0;
//    cout<<tm<<endl;
    for(int i='a';i<='z';i++)
    {
        int count=0;
        for(int j=0;j<m;j++)
        {
            if(cnt[j][i]) count++;
        }
        if(count==tm)
            ans++;
    }
    cout<<ans<<endl;
	return 0;
}

