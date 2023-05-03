#include<iostream>
#include<algorithm>

using namespace std;
const int N=1e6+10;
int q[N];

int n;

void quicksort(int q[],int l,int r)
{
	if(l>=r)return ;

	int i=l-1,j=r+1;
	int mid=q[l+r >> 1];

	while(i<j)
	{
		do i++;while(q[i]<mid);
		do j--;while(q[j]>mid);
		if(i<j)swap(q[i],q[j]);
	}
	quicksort(q,l,j);
	quicksort(q,j+1,r);
}

int main()
{
	cin>>n;

	for(int i=0;i<n;i++)cin>>q[i];

	quicksort(q,0,n-1);

	for(int i=0;i<n;i++)
		cout<<q[i]<<" ";

	return 0;
