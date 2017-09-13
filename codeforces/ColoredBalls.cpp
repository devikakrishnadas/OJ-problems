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
	int n;
	cin>>n;
	vi A(n);
	for(int i=0;i<n;i++)
	{
		cin>>A[i];
	}
	sort(A.begin(),A.begin()+n);
	int val=A[0];
	while(sqrt(val))
	{
		int n1=0,n_1=0;
		bool no=0;
		int cnt=0;
		for(int i=0;i<n;i++)
		{
			
			if(A[i]%(val+1)==0 or A[i]%(val+1)==val or A[i]%val==0 or A[i]%val==1)
			{
				if(A[i]%(val+1)==0)
				{
					cnt+=(A[i]/(val+1));
				}
				else if(A[i]%(val+1)==val )//|| A[i]%val==0)
				{
					cnt+=((A[i]/(val+1))+1);
				}
				else if(A[i]%val==0)
				{
					cnt+=(A[i]/val);
				}
				else if(A[i]%val==1)
				{
					cnt+=(A[i]/val);
				}
			}	
			else
			{
				no=1;
				break;
			}
			
		}
		if(!no) 
		{
//			cout<<val<<endl;
			cout<<cnt<<endl;
			return 0;
		}
		val--;
	}
	int val;
	for(int i=1;i<=sqrt(A[0];i++)
	{
		int k1=A[0]%i;
		int k2=A[0]/i;
		if(abs(k1-k2)>1)
			continue;
		for(int j=1;j<n;i++)
		{
			
		}
	}
	return 0;
}

