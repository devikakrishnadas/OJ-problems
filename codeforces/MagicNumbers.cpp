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

int main()
{
	char A[100];
	cin>>A;
	for(int i=strlen(A)-1;i>=0;i--)
	{
		if(A[i]=='1') continue;
		if(A[i]=='4')
		{
			if(i==0)
			{
				cout<<"NO"<<endl;
				return 0;
			}
			else if(A[i-1]=='1') continue;
			else if(A[i-1]=='4')
			{
				if(i-1==0) 
				{
					cout<<"NO"<<endl;
					return 0;
				}
				else if(A[i-2]=='1') continue;
				else 
				{
					cout<<"NO"<<endl;
					return 0;
				}
			}
			else
			{
				cout<<"NO"<<endl;
				return 0;
			}
	
		}
		else 
		{
			cout<<"NO"<<endl;
			return 0;
		}
	}
	cout<<"YES"<<endl;
	
	return 0;
}

