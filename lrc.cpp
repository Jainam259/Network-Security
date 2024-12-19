// Lrc 

#include<iostream>
using namespace std;

int main() {
    string data;
    cout << "Enter Data (Only Binary/Even Length): ";
    cin >> data;
    
    int bit;
    cout << "Enter Bit: ";
    cin >> bit; 
    
    int len = data.length() / bit; 

    char dat[len][bit]; 
    
    for(int i = 0; i < len; i++) {
        for(int j = 0; j < bit; j++) {
            dat[i][j] = data[i * bit + j];
        }
    }
    
    for(int i = 0; i < len; i++) {
        for(int j = 0; j < bit; j++) {
            cout<<dat[i][j];
        }
        cout<<endl;
    }
    
    int parity[bit];
    int ch;
    
    cout<<"Enter your Choice(1-Even,2-Odd) = ";
    cin>>ch;
    cout<<"\n";
    
    for(int j=0;j<bit;j++){
        int count=0;
        for(int i=0;i<len;i++){
            if(dat[i][j]=='1')
                count++;
        }
        
        if(ch==1){
            if(count%2==0)
                parity[j]=0;
            else
                parity[j]=1;
        }
        
        if(ch==2){
            if(count%2!=0)
                parity[j]=0;
            else
                parity[j]=1;
        }
    }
    
    cout<<endl<<"Parity: ";
    for(int j=0;j<bit;j++){
        cout<<parity[j];
    }
    cout<<endl;
}


// Output

// 1.Even

// Enter Data (Only Binary/Even Length): 01110111101010010110100110101010
// Enter Bit: 8
// 01110111
// 10101001
// 01101001
// 10101010
// Enter your Choice(1-Even,2-Odd) = 1

// Parity: 00011101


// 2.Odd

// Enter Data (Only Binary/Even Length): 01110111101010010110100110101010
// Enter Bit: 8
// 01110111
// 10101001
// 01101001
// 10101010
// Enter your Choice(1-Even,2-Odd) = 2

// Parity: 11100010











// Mam Code



// #include<bits/stdc++.h>
// #include<iostream>
// #include<string>
// using namespace std;

// string getString(char x)
// {
// 	string s(1,x);
// 	return s;
// }

// int main()
// {
// 	int n,a,i = 0;

// 	cout<<"Enter 0 for Odd\nEnter 1 for Even\n";
// 	cout<<"Enter Your Choice = ";
// 	cin>>n;

// 	string line;
// 	string val[4];
// 	string parity = "";

// 	ifstream f("data.txt");

// 	while(getline(f,line))
// 	{
// 		cout<<line;
// 		val[i] = line;
// 		i++;
// 		cout<<"\n";
// 	}

// 	for(int i=0; i<8; i++)
// 	{
// 		a = 0;
// 		for(int j=0; j<4; j++)
// 		{
// 			int x;
// 			string s = getString(val[j][i]);
// 			stringstream frame(s);
// 			frame >> x;
// 			// cout<<"\n"<<x;
// 			a = a+x;
// 		}
// 		if(n == 1)
// 		{
// 			if(a % 2 == 0)
// 			{
// 				parity.append("0");
// 			}
// 			else
// 			{
// 				parity.append("1");
// 			}
// 		}
// 		else
// 		{
// 			if(a%2 == 0)
// 			{
// 				parity.append("0");
// 			}
// 		}
// 	}
// 	cout<<"\n"<<parity<<" = LRC"<<endl;
// }













