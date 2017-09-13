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

int A[1002][1002];
bool compare(int a,int b)
{
	return a<b;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	priority_queue <int> rval,rk1,cval;
	priority_queue<int,vector<int>,greater<int> > ck1;
	//priority_queue<pair<int,char> >A;
	int n,m,k,p;
	vi rk,ck;
        cin>>n>>m>>k>>p;
        int rows[1002]={0};
        int cols[1002]={0};
        for(int i=0;i<n;i++)
        {
                for(int j=0;j<m;j++)
                {
                        cin>>A[i][j];
                        rows[i]+=A[i][j];
                        cols[j]+=A[i][j];
                }
        }	
	
	for(int i=0;i<n;i++)
	{
		rval.push(rows[i]);
		//A.push(mp(rows[i],'r'));
	}
	int i=1,prev=0;
	while((i)<=k)
	{
		int a=rval.top();
		rval.pop();
		rk.pb(a+prev);
		cout<<a<<endl;
		prev=a;
		rval.push(a-m*p);
		i++;
	}
	cout<<endl<<endl;
	for(int j=0;j<m;j++)
	{
		cval.push(cols[j]);
		//A.push(mp(cols[j],'c'));
	}
	i=1;
	prev=0;
	while((i)<=k)
	{
		int a=cval.top();
		cout<<a<<endl;
		cval.pop();
		ck.pb(a);
		cval.push(a-n*p);
		i++;
	}
	sort(all(rk));
	sort(all(ck));
	reverse(all(rk));
	reverse(all(ck));
	
	cout<<endl<<endl;
	int rowsub=0,colsub=0;
	int ans=0;
	for(int i=0;i<n;i++)
	{
		if(i)
		{
			rk[i]+=rk[i-1];
		}
		rk1.push(rk[i]);
	}
	for(int i=0;i<m;i++)
	{
		if(i)
		{
			ck[i]+=ck[i-1];
		}
		ck1.push(ck[i]);
	}
	for(int i=0;i<=k;i++)
	{
		if(rk1.size()==0 || ck1.size()==0)
			break;
		int a=ck1.top();
		int b=rk1.top();
	
		cout<<a<<" "<<b<<" "<<a+b-i*(k-i)*p<<endl;
		if(a+b)
		{
			ans=max(ans,a+b-i*(k-i)*p);
			rk1.pop();
			ck1.pop();
		}
	}
	cout<<ans<<endl;
	return 0;
}

