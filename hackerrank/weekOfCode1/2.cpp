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



int dsum(int n)
{
	int a=0;
	while(n)
	{
		a=a+n%10;
		n=n/10;
	}
	return a;
}

int rev(int n)
{
        int a=0;
        while(n)
        {
                a=a*10+n%10;
                n=n/10;
        }
	
        return a;
}

int main()
{
	int n;
	cin>>n;
	int ans=0;
	int ansum=0;
	for(int i=1;i<=n;i++)
	{
		if(n%i!=0) continue;
		int b=dsum(i);
	
		if(b>ansum)
		{
			ansum=b;
			ans=min(i,rev(i));
		}
	}
	cout<<ans<<endl;
	return 0;
}

