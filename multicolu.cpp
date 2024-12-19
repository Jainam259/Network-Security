// -------------------------------- Multi Columinar -------------------------------------

#include<iostream>
using namespace std;

string enc(string pt,string key)
{
	int pvalue = pt.size();
	int kvalue = key.size();
	int numRow = (pvalue + kvalue - 1) / kvalue;

	char matrix[numRow][kvalue];

	for(int i=0; i<numRow; i++)
	{
		for(int j=0; j<kvalue; j++)
		{
			int index = i * kvalue + j;

			if(index < pvalue)
				matrix[i][j] = pt[index];
			else
				matrix[i][j] = '0';
		}
	}

	int indices[kvalue];
	for(int i=0; i<kvalue; i++)
	{
		indices[i] = i;
	}

	for(int i=0; i<kvalue-1; i++)
	{
		for(int j=i+1; j<kvalue; j++)
		{
			if(key[indices[i]] > key[indices[j]])
			{
				int temp = indices[i];
				indices[i] = indices[j];
				indices[j] = temp;
			}
		}
	}

	string cipher;

	for(int i=0; i<kvalue; i++)
	{
		int col = indices[i];
		for(int j=0; j<numRow; j++)
		{
			cipher += matrix[j][col];
		}
	}
	return cipher;
}

int main()
{
	string pt,key1,key2;

	cout<<"Enter Plain Text:";
	cin>>pt;

	cout<<"Enter Key1:";
	cin>>key1;

	cout<<"Enter Key2:";
	cin>>key2;

	string dec1 = enc(pt,key1);
	string dec2 = enc(pt,key2);

	cout<<"Cipher1:"<<dec1<<endl;
	cout<<"Cipher2:"<<dec2<<endl;
}




// output

// Enter Plain Text: HELLOWORLD
// Enter Key1: ZEBRA
// Enter Key2: TIGER
// Cipher1: ODLREOLLHW
// Cipher2: LLLREOODHW
