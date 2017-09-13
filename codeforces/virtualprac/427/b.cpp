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
    ll sum;
    cin>>sum;
    char a[100023]; 
    cin>>a;
    ll n=strlen(a);
    priority_queue<ll>q,p;
    ll cursum=0;
    ll first=a[0]-'0';
    for(int i=0;i<n;i++)
    {
        ll t=a[i]-'0';
        cursum+=t;
        q.push(9-t);
        if(i)
            p.push(9-t);
    }
    if(cursum<sum)
    {
        int cnt=0;
        while(!q.empty() && sum>cursum)
        {
            ll tt=q.top();
            sum=sum-tt;
            q.pop();
            cnt++;
        }
        cout<<cnt<<endl;
    }
    else
    {
        cout<<0<<endl;
    }
	return 0;
}

