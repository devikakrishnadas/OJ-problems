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

int minVal(int x, int y) { return (x > y)? x: y; }

int getMid(int s, int e) {  return s + (e -s)/2;  }

int RMQUtil(int *st, int ss, int se, int qs, int qe, int index)
{
    if (qs <= ss && qe >= se)
        return st[index];
 
    // If segment of this node is outside the given range
    if (se < qs || ss > qe)
        return 0;
 
    // If a part of this segment overlaps with the given range
    int mid = getMid(ss, se);
    return minVal(RMQUtil(st, ss, mid, qs, qe, 2*index+1),
                  RMQUtil(st, mid+1, se, qs, qe, 2*index+2));
}


int RMQ(int *st, int n, int qs, int qe)
{
    // Check for erroneous input values
    if (qs < 0 || qe > n-1 || qs > qe)
    {
        printf("Invalid Input");
        return -1;
    }
 
    return RMQUtil(st, 0, n-1, qs, qe, 0);
}



int constructSTUtil(vi arr, int ss, int se, int *st, int si)
{
    // If there is one element in array, store it in current node of
    // segment tree and return
    if (ss == se)
    {
        st[si] = arr[ss];
        return arr[ss];
    }
 
    // If there are more than one elements, then recur for left and
    // right subtrees and store the minimum of two values in this node
    int mid = getMid(ss, se);
    st[si] =  minVal(constructSTUtil(arr, ss, mid, st, si*2+1),
                     constructSTUtil(arr, mid+1, se, st, si*2+2));
    return st[si];
}


int *constructST(vi arr, int n)
{
    // Allocate memory for segment tree
 
    //Height of segment tree
    int x = (int)(ceil(log2(n))); 
 
    // Maximum size of segment tree
    int max_size = 2*(int)pow(2, x) - 1; 
 
    int *st = new int[max_size]; 
 
    // Fill the allocated memory st
    constructSTUtil(arr, 0, n-1, st, 0);
 
    // Return the constructed segment tree
    return st;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,k,p;
	cin>>n>>k>>p;
	vi a(n);
	for(int i=0;i<n;i++)
		cin>>a[i];
	k=min(n,k);
	vi A;
	int cnt=0;
	int ind=-1;

	for(int i=0;i<k;i++)
	{
		if(a[i]==1)
		{
			cnt++;
		}
	}
	A.pb(cnt);
	//cout<<0<<" "<<cnt<<endl;
	for(int i=0,j=k;i<n-1;i++,j++)
	{
		j=j%n;
		if(a[i]==1)
			cnt--;
		if(a[j]==1) 
			cnt++;
		A.pb(cnt);
		//cout<<i+1<<" "<<cnt<<endl;
	}
	for(int i=0;i<n;i++)
	{
		A.pb(A[i]);
	}
	int rot=0;
	string s;
	cin>>s;
	int *st = constructST(A, 2*n);
	
	for(int i=0;i<p;i++)
	{
		if(s[i]=='?')
		{
			cout<<RMQ(st, 2*n, rot, rot+ (n-k))<<endl;
		}
		else
		{
			rot--;
			rot=(rot+n)%n;
		}
	}
	return 0;
}
