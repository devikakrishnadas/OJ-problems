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
int ch[1000][1000]={0};
int change(int coins[100],int n,int val)
{
	if(val==0) 
	{
		return 1;
	}
	if(val<0) return 0;
	if(n<=0) return 0;
	if(ch[n][val]) return ch[n][val];
	ch[n][val-coins[n-1]]= change(coins,n,val-coins[n-1]);
	ch[n-1][val]=change(coins,n-1,val);
	ch[n][val]=ch[n][val-coins[n-1]]+ch[n-1][val];
	return ch[n][val];
}
int main()
{
	int A[1000];
	int n,k;
	cin>>n>>k;
	for(int i=0;i<k;i++)
	{
		cin>>A[i];
	}
	
	cout<<change(A,k,n)<<endl;
	return 0;
}

