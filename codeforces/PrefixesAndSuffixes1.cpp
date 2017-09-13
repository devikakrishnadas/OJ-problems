#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vc vector<char>
#define vll vector<ll>
#define pb push_back
#define sf scanf
#define ff first
#define M 1000000007
#define ss second
#define pf printf
#define mp make_pair
#define all(V) V.begin(),V.end()

using namespace std;

vi arr(200023,0);
void Z(vc A,int n)//Failure function
{
        int l=0,r=0;
        for(int i=1;i<n;)
        {
                int k=r-i;
                if(k<0)
                        k=0;
                while(A[i+k]==A[k] && i+k<n)//Runs until the first mismatch with the prefix
                {

                        k++;
                }
                arr[i]=k;
                l=i;
                r=k+i;
                if(k)
                {
                        r=r-1;
                }
                bool enter=0;
                for(int j=1;j<r-l+1;j++)
                {
                        arr[i+j]=arr[j];
                        if(arr[j]+i+j>=r)
                        {
                                i=i+j;
                                enter=1;
                                break;
                        }
                }
                if(!enter)
                {
                        i=r+1;
                }
        }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin>>s;
	vc A,B;
	vi presuf;
	int n=s.length();
	vi presufpresent(200023,0);
	/* Running the Z Algorithm to compare the string against itself to find the biggest prefix that is also a suffix */
	
	for(int i=0;i<n;i++)
	{
		A.pb(s[i]);
	}
	A.pb('$');
	for(int i=0;i<n;i++)
	{
		A.pb(s[i]);
	}
	
	Z(A,A.size());
	for(int i=n+2;i<A.size();i++)
	{
		if(arr[i]+i==A.size())
		{
			presuf.pb(arr[i]);
			presufpresent[arr[i]]++;
		}
	}
	int val;
	sort(all(presuf));
	reverse(all(presuf));
	if(presuf.size())
		val=presuf[0]; // Stores the length of the biggest pre=suf	
	else val=0;
	if(val==n || val==0)
	{
		cout<<1<<endl;
		cout<<n<<" "<<1<<endl;
		return 0;
	}
//	cout<<val<<endl;
	/*****************************************************************************************************************/



	/* Clearing ans[] */
	
	for(int i=0;i<=A.size();i++)
		arr[i]=0;

	/******************/

	/* Running the Z algorithm to compare the string against the longest pre=suf */
	for(int i=0;i<val;i++)
	{
//		cout<<s[i];
		B.pb(s[i]);
	}
//	cout<<endl;
	B.pb('$');
	for(int i=0;i<n;i++)
	{
//		cout<<s[i];
		B.pb(s[i]);
	}
//	cout<<endl;
	Z(B,B.size());
	vi count(200023);
/*	for(int i=0;i<B.size();i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
*/	for(int i=val+1;i<B.size();i++)
	{
		count[arr[i]]++;
//		if(arr[i])
//			cout<<arr[i]<<" ";
	}
//	cout<<endl;
	vi calc;
	sort(all(presuf));
	reverse(all(presuf));
	int cnt=0;
	vector<pair<int,int> >ans;
//	cout<<count[8]<<endl;
	for(int i=n-1;i>=0;i--)
	{
		cnt=cnt+count[i];
		if(presufpresent[i])
		{
//			cout<<i<<" "<<cnt<<" "<<count[i]<<endl;
			ans.pb(mp(i,cnt));
		}
	}
	ans.pb(mp(n,1));
	sort(all(ans));
	cout<<ans.size()<<endl;
	for(int i=0;i<ans.size();i++)
	{
		cout<<ans[i].ff<<" "<<ans[i].ss<<endl;
	}
	return 0;
}

