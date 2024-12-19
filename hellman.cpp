// Hellman Algorithm

#include<iostream>
using namespace std;

int power(int a,int b,int mod)
{
	int result = 1;
	for(int i=0; i<b; i++)
	{
		result = (result * a) % mod;
	}
	return result;
}

int main()
{
	int p,g;

	cout<<"Enter Prime = ";
	cin>>p;

	cout<<"Enter G = ";
	cin>>g;

	int a,b;
	cout<<"Enter User A Private Key = ";
	cin>>a;

	cout<<"Enter User B Private Key = ";
	cin>>b;

	int A = power(g,a,p);
	int B = power(g,b,p);

	cout<<"Private Key of A = "<<A<<endl;
	cout<<"Private Key of B = "<<B<<endl;

	int secretA = power(B,a,p);
	int secretB = power(A,b,p);

	cout<<"Secret Key of User A = "<<secretA<<endl;
	cout<<"Secret Key of User B = "<<secretB<<endl;
}




// Enter Prime = 23
// Enter G = 5
// Enter User A Private Key = 6
// Enter User B Private Key = 15
// Private Key of A = 8
// Private Key of B = 19
// Secret Key of User A = 2
// Secret Key of User B = 2


