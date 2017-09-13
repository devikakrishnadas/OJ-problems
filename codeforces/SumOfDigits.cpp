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
	char A[100023];
	cin>>A;
	ll b=0;
	for(int i=0;i<strlen(A);i++)
	{
		b=b+ (A[i]-'0');
	}
	int d=0;
	int cnt=0;
	if(strlen(A)==1)
		cnt=0;
	else cnt=1;
	while(b/10)
	{
		cnt++;
		while(b)
		{
			d=d+b%10;
			b=b/10;
		}
		b=d;
		d=0;
	}
	cout<<cnt<<endl;
	return 0;
}

