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

ll summ(ll a)
{
    ll sum=a;
    while(a)
    {
        sum=sum+a%10;
        a=a/10;
    }
    return sum;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    ll n;
    cin>>n;
    vi ans;
    for(int i=1;i<=90;i++)
    {
        if(summ(n-i)==n)
        {
           ans.pb(n-i); 
        }
    }
    cout<<ans.size()<<endl;
    if(ans.size()!=0)
    {
        sort(all(ans));
        for(int i=0;i<ans.size();i++)
        {
            cout<<ans[i]<<endl;
        }
    }
    
	return 0;
}

