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

int B[1000023]={0};

void Z(vc A,int n)//Failure function
{
        vi arr(n,0);
        int l=0,r=0;
        for(int i=1;i<n;)
        {
                int k=r-i;
		if(k<0) k=0;
//                cout<<A[i]<<endl;
//		if(i+k<n)
                while(A[i+k]==A[k] && i+k<n)//Runs until the first mismatch with the prefix
                {
                        k++;
                }
//		else k=0;
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
	int maxz = 0, res = 0;
	for (int i = 1; i < n; i++) {
  	if (arr[i] == n-i && maxz >= n-i) { res = n-i; break; }
  	maxz = max(maxz, arr[i]);
	}
	if(res==0)
	cout<<"Just a legend"<<endl;
	else
	{
		for(int i=0;i<res;i++)
			cout<<A[i];
		cout<<endl;
	}

}


int main()
{
        int n;
        char x,t[1000023];
        vc A;
        cin>>t;
	n=strlen(t);
        for(int i=0;i<n;i++)
        {
                x=t[i];
                A.pb(x);
        }
        Z(A,n);
	return 0;
}

