
#include <iostream>
#include <math.h>
using namespace std;

void hanoi(int n,int d , int a , int b , int c)
{
	if( n == 1 )
	{
		cout<<d<<"\t"<<a<<" \t "<<c<<endl;
	}
	else
	{
		hanoi(n-1 ,d, a , c , b);
		
		cout <<d-n+1<<"\t"<<a<<"\t"<<c<<endl;
		
		hanoi(n-1 ,d,b , a , c);

	}
}

int main()
{
	int n,a,b,c;
	cin>>n;
	cin>>a>>b>>c;
	int m=pow(2,n)-1;
	cout<<m<<endl;

	hanoi(n,n,a,b,c);
	
}


