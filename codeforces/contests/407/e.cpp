#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vc vector<char>
#define vll vector<ll>
#define pb push_back
#define sf scanf
#define pf printf
#define mp make_pair
#define all(V) V.begin(),V.end()

using namespace std;

//int ch[1000][10000]={0};
//ans=INT_MAX;
int aval;
int ac;
int ans=INT_MAX;
void change(vi coins,int n,int val,int c)
{
//	cout<<val<<endl;
        if(val==0)
        {
		if(c==ac)
			ans=min(ans,c);
                return ;
        }
        if(val<0) return ;
        if(n<=0) return ;
        change(coins,n,val-coins[n-1],c+1);
        change(coins,n-1,val,c);
        //ch[n][val]=ch[n][val-coins[n-1]]+ch[n-1][val];
        //return ch[n][val];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,k;
	cin>>n>>k;
	vi a(k+1);
	for(int i=0;i<k;i++) cin>>a[i];
	for(int i=1;;i++)
	{
		aval=n*i;
		ac=i;
		cout<<i<<endl;
		change(a,k,n*i,0);
		if(ans!=INT_MAX)
		{
			cout<<ans<<endl;
			break;
		}
	}
	return 0;
}
