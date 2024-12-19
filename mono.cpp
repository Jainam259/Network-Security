// Monoalphabetic ceaser cipher

#include<iostream>
using namespace std;

int main()
{
	string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string key = "QWERTYUIOPASDFGHJKLZXCVBNM";

	string txt,cip,pt;

	cout<<"Enter Plain Text(Uppercase Letter Only):";
	getline(cin,txt);

	for(int i=0; i<txt.length(); i++)
	{
		int index = alpha.find(txt[i]);
		cip += key.at(index);
	}
	cout<<"Cipher:"<<cip<<endl;

	for(int i=0; i<cip.length(); i++)
	{
		int index = key.find(cip[i]);
		pt += alpha.at(index); 
	}
	cout<<"Plain:"<<pt<<endl;
}



// OUTPUT

// Enter Plain Text (Uppercase Letters Only): HELLO
// Cipher: ITSSG
// Plain: HELLO




