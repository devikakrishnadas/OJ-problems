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

int val=6;
vi vis(1001,0);
void in(vi &a)
{
    for(int i=0;i<val;i++) 
    {
        int x;
        cin>>x;
        a.pb(x);
        vis[x]=1;
    }

}

void do2(vi &a, vi&b)
{
    for(int i=0;i<val;i++)
    {
        for(int j=0;j<val;j++)
        {
            vis[b[i]*10+a[j]]=1;
            vis[a[j]*10+b[i]]=1;
        }
    }
}

void do3(vi &a,vi &b,vi &c)
{
    for(int i=0;i<val;i++)
    {
        for(int j=0;j<val;j++)
        {
            for(int k=0;k<val;k++)
            {
                int aa=a[i];
                int bb=b[j];
                int cc=c[k];
                vis[aa*100+bb*10+cc]=1;
                vis[aa*100+cc*10+bb]=1;
                vis[bb*100+aa*10+cc]=1;
                vis[bb*100+cc*10+aa]=1;
                vis[cc*100+aa*10+bb]=1;
                vis[cc*100+bb*10+aa]=1;
            }
        }
    }
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    int n;
    cin>>n;
    vector<vi>a(n);
    for(int i=0;i<n;i++) in(a[i]);

    if(n==2) do2(a[0],a[1]);
    if(n==3) 
    {
        do2(a[0],a[1]);
        do2(a[0],a[2]);
        do2(a[1],a[2]);
        do3(a[0],a[1],a[2]);
    }

    for(int i=1;;i++)
    {
        if(!vis[i])
        {
            cout<<i-1<<endl;
            return 0;
        }
    }

	return 0;
}

