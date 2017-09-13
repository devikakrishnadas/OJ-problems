#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vc vector<char>
#define vll vector<ll>
#define pb push_back
#define sf scanf
#define pf printf
#define mp make_pair
#define all(V) V.begin,V.end

using namespace std;


int A[1000][1000]={0};
int l[1000][1000]={0};
int r[1000][1000]={0};
int u[1000][1000]={0};
int d[1000][1000]={0};


int main()
{
	//cout<<0<<endl;
	int n,m;
	cin>>n>>m;
	//cout<<1<<endl;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>A[i][j];
			
		}
	}

	//cout<<2<<endl;
	//left
//	cout<<endl;
	for(int i=0;i<n;i++)
        {
                for(int j=0;j<m;j++)
                {
			l[i][j]=A[i][j];
			if(j)
			{
				l[i][j]+=l[i][j-1];
			}
//			cout<<l[i][j]<<" ";
                }
//		cout<<endl;
        }
//	cout<<endl;
	//cout<<3<<endl;
	//right
	for(int i=0;i<n;i++)
        {
                for(int j=m-1;j>=0;j--)
                {
			r[i][j]=A[i][j];
			if(j<m-1)
			{
				r[i][j]+=r[i][j+1];
			}
//			cout<<r[i][j]<<" ";
                }
//		cout<<endl;
        }
//	cout<<endl;
	//cout<<4<<endl;
	//up
	for(int i=n-1;i>=0;i--)
        {
                for(int j=0;j<m;j++)
                {
			u[i][j]=A[i][j];
			if(i<n-1)
				u[i][j]+=u[i+1][j];
//			cout<<u[i][j]<<" ";
                }
//		cout<<endl;
        }
//	cout<<endl;
	//cout<<5<<endl;
	//down
	for(int i=0;i<n;i++)
        {
                for(int j=0;j<m;j++)
                {
			d[i][j]=A[i][j];
			if(i)
			{
				d[i][j]+=d[i-1][j];
			}
//			cout<<d[i][j]<<" ";
                }
//		cout<<endl;
        }
//	cout<<endl;
	//cout<<6<<endl;
	ll ans=0;
	for(int i=0;i<n;i++)
        {

                for(int j=0;j<m;j++)
                {
			// cout<<u[i][j]<<'*'<<d[i][j]<<'*'<<l[i][j]<<'*'<<r[i][j]<<" ";
//			cout<<A[i][j]<<" ";
			if(A[i][j])
				continue;
			//ans=ans+u[i][j]+d[i][j]+l[i][j]+r[i][j];
			
			if(l[i][j]) ans++;
			if(r[i][j]) ans++;
			if(d[i][j]) ans++;
			if(u[i][j]) ans++;
                }
	
        }
	cout<<ans<<endl;

	return 0;
}

