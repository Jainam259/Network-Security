// ----------------------- simple columinar ---------------------------------


#include<iostream>
using namespace std;

string enc1(string pt,string key)
{
	int pvalue = pt.length();
	int kvalue = key.length();
	int numRow = (pvalue + kvalue - 1) / kvalue;

	char matrix[numRow][kvalue];

	for(int i=0; i<numRow; i++)
	{
		for(int j=0; j<kvalue; j++)
		{
			int index = i*kvalue+j;
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
	string pt,key;

	cout<<"Enter Text:";
	cin>>pt;

	cout<<"Enter Key:";
	cin>>key;

	string ct = enc1(pt,key);

	cout<<"Cipher:"<<ct<<endl;
}

// output

// Enter Text:HELLO
// Enter Key:ZEBRA
// Cipher:OLELH