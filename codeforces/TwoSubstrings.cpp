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
	string s;
	cin>>s;
	int n=s.length();
	//int A[100023]={0};
	vector<pair<int,char> >A;
	int cnt1=0,cnt2=0;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='A' && s[i+1]=='B')
		{
			cnt1++;
			A.pb(mp(i,'A'));
		}
		else if(s[i]=='B' && s[i+1]=='A')
		{
			cnt2++;
			A.pb(mp(i,'B'));
		}
	}
	//cout<<cnt1<<" "<<cnt2<<endl;
	if(A.size()>2 && (cnt1>1 || cnt2>1) && cnt1 && cnt2 )
	{
		cout<<"YES"<<endl;
	}
	else if(A.size()>=2 && cnt1 && cnt2)
	{
//		cout<<"r1"<<endl;
		int pos;
		bool enter=0;
		if(cnt2==1)
		{
			for(int i=0;i<A.size();i++)
			{
				if(A[i].second=='B')
				{
					pos=A[i].first;
					break;
				}
			}
			//bool enter=0;
			for(int i=0;i<A.size();i++)
			{
	//			cout<<pos<<" "<<A[i].first<<" "<<A[i].second<<endl;
	//			if(A[i].first==pos+1) cout<<"r1"<<endl;
	//			if(A[i].second!=A[pos].second) cout<<"r2"<<endl;
				if( (A[i].first==pos+1 || A[i].first==pos-1) && A[i].second!=A[pos].second)
				{
//					cout<<"ABC"<<endl;
					cout<<"NO"<<endl;
					enter=1;
					break;
				}
			}
			if(cnt1!=1 && !enter)
			{
				cout<<"YES"<<endl;
			}
		}
		
		if(cnt1==1 && !enter)
		{
			for(int i=0;i<A.size();i++)
                        {
                                if(A[i].second=='A')
                                {
                                        pos=A[i].first;
                                        break;
                                }
                        }
                        enter=0;
                        for(int i=0;i<A.size();i++)
                        {
                                if((A[i].first==pos+1 || A[i].first==pos-1)&& A[i].second!=A[pos].second)
                                {
                                        cout<<"NO"<<endl;
                                        enter=1;
                                        break;
                                }
                        }
                        if(!enter)
                        {
                                cout<<"YES"<<endl;
                        }

		}
	}
	else cout<<"NO"<<endl;
	return 0;
}

