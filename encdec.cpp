#include<iostream>
#include<string>
#include<limits>
using namespace std;

string encrypt(string pt,int n)
{
	string ct = "";
	for(int i=0; i<pt.length(); i++)
	{
		char c = pt[i];
		if(isupper(c))
			c = (c - 'A' + n) % 26 + 'A';
		else if(islower(c))
			c = (c - 'a' + n) % 26 + 'a';
		ct = ct + c;
	}
	return ct;
}

string decrypt(string ct,int n)
{
	string pt = "";
	for(int i=0; i<ct.length(); i++)
	{
		char c = ct[i];
		if(isupper(c))
			c = (c - 'A' - n + 26) % 26 + 'A';
		else if(islower(c))
			c = (c - 'a' - n + 26) % 26 + 'a' ;
		pt += c;
	}
	return pt;
}

int main()
{
	string pt;
	int n;

	cout<<"Enter Plain text:";
	getline(cin,pt);

	cout<<"Enter the Shift Value:";
	cin>>n;

	n = n % 26;

	string dec = encrypt(pt,n);

	cout<<"Decrypted text:"<<dec<<endl;

	string enc = decrypt(dec,n);
	cout<<"Encryptd text:"<<enc<<endl;
}