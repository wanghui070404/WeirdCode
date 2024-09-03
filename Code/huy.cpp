#include <iostream>
using namespace std;
void nhapmang(int A[],int &n,int &p,int &k);
void xoa(int A[],int &n,int p,int k);
void xuat(int A[],int n);
int main()
{
	int A[100],n,p,k;
	nhapmang(A,n,p,k);
	xoa(A,n,p,k);
	xuat(A,n);
}
void nhapmang(int A[],int &n,int &p,int &k)
{
	cin>>n;
	for (int i=0;i<n;i++)
		cin>>A[i];
	cin>>p;
	cin>>k;
}
void xoa(int A[],int &n,int p,int k)
{
	int q=0;
	while (q<k)
	{
		for (int i=p;i<n-1;i++)
			A[i]=A[i+1];
		n--;
		q++;
	}
}

void xuat(int A[],int n)
{
	for(int i=0;i<n;i++)
		cout<<A[i]<<" ";
}
