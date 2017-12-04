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
    int n,d;
    cin>>n>>d;
    vll a(n),b(n,0);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        b[i]=a[i];
    }
    bool no=0;
    for(int i=1;i<n;i++)
    {
        b[i]+=b[i-1];
        if(b[i]>d)
            no=1;
    }
    if(no)
    {
        cout<<-1<<endl;
        return 0;
    }
    vll canadd(n+1,INT_MAX);
    vll _b(n+1,0);
    for(int i=n-1;i>=0;i--)
    {
        canadd[i]=min(d-a[i],canadd[i+1]);
        _b[i]+=_b[i+1];
    }
    ll ans=0;
    ll valtoadd=0;
    ll cnt=0;
    ll curval=0;
    ll sumlastzero=0;
    for(int i=n-1;i>=0;i--)
    {   
        
        if(b[i]+valtoadd > canadd[i])
        {
            valtoadd=0;
            cnt++;
        }       
        if(b[i]<0 && a[i]==0)
        {
            valtoadd+=abs(b[i]);
        }

    }
    
        if(valtoadd > canadd[0])
        {
            valtoadd=0;
            cnt++;
        }
    cout<<cnt<<endl;
	return 0;
}

