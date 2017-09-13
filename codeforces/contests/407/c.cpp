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


ll maxSubArraySum(vll a, int size,int aa)
{
    ll max_so_far = INT_MIN, max_ending_here = 0;
 bool enter=1;
	int tot=0;
    for (int i = 0; i < size; i++)
    {
	if(enter==1)
	{
		if((i%2)==aa)
		{
			continue;
		}
		else
		{
			enter=0;
		}
	}
        max_ending_here = max_ending_here + a[i];
	
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;
 	tot++;
        if (max_ending_here < 0 )
        {
		tot=0;
	    max_ending_here = 0;
	    enter=1;
	}
    }
    return max_so_far;
}

int main()
{
	int n;
	cin>>n;
	vll a(n),b,c;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<n;i++)
	{
		int x=abs(a[i]-a[i-1]);
		if(i%2)
		{
			b.pb(-1*x);
			c.pb(x);
		}
		else
		{
			c.pb(-1*x);
			b.pb(x);
		}
	}
	cout<<max(maxSubArraySum(b,b.size(),0),maxSubArraySum(c,c.size(),1))<<endl;
	return 0;
}

