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

vi b(1000111,0);
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
        b[a[i]]=1;
    }
    const int tot = 1000000;
    int cnt=0;
    vi ans;
    for(int i=1;i<=tot;i++)
    {
        if(b[i] and !b[tot-i+1])
        {
            ans.pb(tot-i+1);
            b[tot-i+1]=1;
        }
        else if(i<=tot/2 and b[i] and b[tot-i+1])
            cnt++;
    }
    int j=1;
    while(cnt--)
    {
        while(b[j] or b[tot-j+1]) 
            j++;
        ans.pb(j);
        ans.pb(tot-j+1);
        b[j]=1;
        b[tot-j+1]=1;
        j++;
    }
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
	return 0;
}

