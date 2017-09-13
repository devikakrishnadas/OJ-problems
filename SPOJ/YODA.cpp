#include<bits/stdc++.h>
#include<iostream>
#define ll long long
#define vi vector<int>
#define vc vector<char>
#define vll vector<ll>
#define pb push_back
#define sf scanf
#define mod 36893488147419103183
#define pf printf
#define mp make_pair
#define all(V) V.begin,V.end

using namespace std;

int main()
{
	char A[100023];
	
	while(1)
	{
		gets(A);
		if(feof(stdin)) break;
//		gets(A);
//		cout<<A<<endl;
		int n=strlen(A);
//		cout<<n<<endl;
		int B[300]={0};
		int tot=0;
		for(int i=0;i<n;i++)
		{
			if((A[i]>='A' and A[i]<='Z') )
			{
				B[A[i]-'A']++;tot++;
			}
			else if(A[i]>='a' and A[i]<='z')
			{
				B[A[i]-'a']++;tot++;
			}
		}	
		vll fact(100,1);
		for(int i=2;i<=20;i++)
		{
			fact[i]=fact[i-1]*i;
		}
		ll ans=fact[tot/2];
		int o=0,e=0;
		for(int i=0;i<30;i++)
		{
			if(B[i]%2) o++;
			else e++;
			if(B[i]/2)
			{
				ans=ans/fact[B[i]/2];
			}
		}
		if(o>1)
			cout<<0<<endl;
		else cout<<ans<<endl;
	}
	return 0;
}
