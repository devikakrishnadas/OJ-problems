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

struct v
{
	int a,b,c;
	int r;
};
int main()
{
	int A[10]={0};
	v v1[5];
	int x,n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>x;
		A[x]++;
	}
	if(A[7] || A[5]||A[0])
	{
		cout<<-1<<endl;
		return 0;
	}
	v1[0].r=v1[1].r=v1[2].r=0;	
	if(A[3])
	{
		int p=min(A[1],min(A[3],A[6]));
		A[1]-=p;
		A[3]-=p;
		A[6]-=p;
		v1[0].a=1;
		v1[0].b=3;
		v1[0].c=6;
		v1[0].r=p;
	}
	if(A[6])
	{
		int p=min(A[1],min(A[2],A[6]));
		A[1]-=p;
		A[2]-=p;
		A[6]-=p;
                v1[1].a=1;
                v1[1].b=2;
                v1[1].c=6;
                v1[1].r=p;

	}
	if(A[4])
	{
		int p=min(A[1],min(A[2],A[4]));
		A[1]-=p;
		A[2]-=p;
		A[4]-=p;
                v1[2].a=1;
                v1[2].b=2;
                v1[2].c=4;
                v1[2].r=p;

	}
	for(int i=0;i<=7;i++)
	{
		if(A[i])
		{
			cout<<-1<<endl;
			return 0;
		}
	}
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<v1[i].r;j++)
		{
			cout<<v1[i].a<<" "<<v1[i].b<<" "<<v1[i].c<<endl;
		}
	}
	return 0;
}

