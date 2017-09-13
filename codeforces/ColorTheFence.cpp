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

int A[20][100023]={0};
vi fans(10,0);
map<int,int>VAL;
int func(vi coins,int n,int val,vector<int>&tans)
{
	
	if(val==0)
	{
		
		int fansc=0,tansc=0;
		for(int i=1;i<10;i++)
		{
			fansc+=fans[i];
			tansc+=tans[i];
		//	cout<<tans[i]<<" ";
		}
//		cout<<endl;
		//cout<<tansc<<"TANSC"<<endl;
		if(fansc==tansc)
		{
			for(int i=9;i>=1;i--)
			{
				if(tans[i]==fans[i]) continue;
				
				if(tans[i]>fans[i])
				{
					for(int j=9;j>=1;j--)
					{
						fans[j]=tans[j];
					}
				
				}
				break;
			}
		}
		else if(tansc>fansc)
		{
			for(int j=9;j>=1;j--)
                        {
                                fans[j]=tans[j];
                        }
		}
		//cout<<"I"<<endl;
		return 1;
	}
	if(val<0) return 0;
	if(n<=1) return 0;
	if(A[n][val]) return A[n][val];
	tans[VAL[coins[n-1]]]++;
	if(val-coins[n-1]>=0)
	{
		A[n][val-coins[n-1]]=func(coins,n,val-coins[n-1],tans);	
			
	}
	//cout<<A[6][1]<<" "<<A[6][2]<<" "<<A[6][3]<<" "<<A[6][4]<<" "<<A[6][5]<<endl;
	tans[VAL[coins[n-1]]]--;
	//cout<<tans[1]<<endl;
	A[n-1][val]=func(coins,n-1,val,tans);
	//tans[n-1]++;
	//A[n][val-coins[n-1]]=func(coins,n,val-coins[n-1],tans);
	A[n][val]=A[n-1][val];
	if(val-coins[n-1]>=0)
		A[n][val]+=A[n][val-coins[n-1]];
	if(coins[n-1]==1 && val==5)
	{
	//	cout<<A[n][val]<<"*****"<<endl;
	}	
//	cout<<n<<" "<<val<<" "<<A[n][val]<<endl;
	return A[n][val];
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	vi a(100023,0);
	vi b;
	int x;
	for(int i=1;i<10;i++)
	{
		cin>>x;
		a[x]++;
		VAL[x]=i;
		if(a[x]==1)
			b.pb(x);
		
	}
	
	//cout<<a[9]<<"***"<<endl;
	//cout<<"r1"<<endl;
	vi tans(100,0);
	func(b,b.size(),n,tans);
	bool enter=0;
	for(int i=9;i>=1;i--)
	{
		while(fans[i])
		{
			enter=1;
			cout<<i;
			fans[i]--;
		}
	}
	
	if(!enter) cout<<-1<<endl;
	else cout<<endl;
	return 0;
}

