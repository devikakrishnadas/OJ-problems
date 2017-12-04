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
    vi a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    vi b(n+2);
    b[0]=0;
    int ptr=n;
    int cnt=1;
    vi ans;
    ans.pb(1);
    for(int i=0;i<n;i++)
    {
        b[a[i]]=1;
        while(b[ptr]==1)
        {
            ptr--;
            cnt--;
        }
        cnt++;
        ans.pb(cnt);  
    }
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
	return 0;
}

