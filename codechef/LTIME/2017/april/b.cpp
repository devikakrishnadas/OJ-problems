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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		ll n,p;
		cin>>n>>p;
		vll a(n+1);
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		int maxsum=-1;
		int sum=0;
		int prevsum=-1;
		int cnt;
		int j=-1;
		for(int i=0;i<n;i++)
		{
			while(j<n-1)
			{
				j++;
				sum=(sum+a[j])%p;
				if(sum<prevsum)
				{
					break;
				}
				
				if(sum==maxsum)
				{
					cnt++;
					cout<<i<<" "<<j<<" "<<sum<<" "<<cnt<<endl;
					prevsum=sum;
				}
				else if(sum>maxsum)
				{
					//cout<<i<<" "<<j<<" "<<sum<<" "<<cnt<<endl;
					cnt=1;
					maxsum=sum;
					prevsum=sum;
				}
				else
				{
					prevsum=sum;
				}
				
			}
			
			sum=(sum-a[i]+p)%p;
			cout<<sum<<endl;
			if(sum>maxsum)
			{
				maxsum=sum;
				cnt=1;
				prevsum=sum;
			}
			else if(sum==maxsum)
			{
				//cout<<i<<" "<<j<<" "<<sum<<" "<<cnt<<endl;
				//cout<<"aftwr"<<endl;
				cnt++;
				prevsum=sum;
			}
			else
			{
				prevsum=sum;
			}
		}
		
		cout<<maxsum<<" "<<cnt<<endl;
	}
	return 0;
}

