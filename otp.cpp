// --------------------------- OTP (Vernam Cipher) ------------------------------------------

#include<iostream>
using namespace std;

int main()
{
	int i,j;
	string m,key,cipher,decrypted;

	cout<<"Enter the Message(Uppercase Letter Only):";
	cin>>m;

	cout<<"Enter the Key(Uppercase Letter Only):";
	cin>>key;

	int mod = key.size();
	j = 0;

	for(i=key.size(); i<m.size(); i++)
	{
		key += key[j%mod];
		j++;
	}

	for(i=0; i<m.size(); i++)
	{
		cipher += (key[i] -'A' + m[i] - 'A') % 26 + 'A';
	}
	cout<<"Encrypted Message:"<<cipher<<endl;

	for(int i=0; i<cipher.size(); i++)
	{
		decrypted += (cipher[i] - key[i] + 26) % 26 + 'A';
	}
	cout<<"Decrypted Message:"<<decrypted<<endl;

	return 1;
}



// OUTPUT

// Enter the Message(Uppercase Letter Only):HELLO
// Enter the Key(Uppercase Letter Only):KEY
// Encrypted Message:RIJVS
// Decrypted Message:HELLO
