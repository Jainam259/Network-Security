// VRC

#include<iostream>
using namespace std;

int main()
{
    string data;
    cout<<"Enter Data(Only Binary) = ";
    cin>>data;

    int ch = 1;
    cout<<"Enter Your Choice = ";
    cin>>ch;

    int count = 0;
    for(int i=0; i<data.length(); i++)
    {
        if(data[i] == '1')
            count++;
    }

    if(ch==1)
    {
        if(count%2 == 0)
            data.append("0");
        else
            data.append("1");    
    }
    else if(ch == 2)
    {
        if(count%2 != 0)
            data.append("0");
        else
            data.append("1");
    }
    else
    {
        cout<<"Invalid Choice!";
        return 1;
    }

    cout<<"VRC = "<<data<<endl;
    return 0;
}

// 1. Even Parity Bit Output

// Enter Data(Only Binary) = 1101001
// Enter Your Choice = 1
// VRC = 11010010



// Enter Data(Only Binary) = 1101001
// Enter Your Choice = 2
// VRC = 11010011


// 2.odd paritybit ouput
























// chatgpt code


// #include <iostream>
// #include <string>

// using namespace std;

// // Function to calculate the parity bit
// char calculateParityBit(const string& data) {
//     int count = 0;
//     for (char bit : data) {
//         if (bit == '1') {
//             count++;
//         }
//     }
//     return (count % 2 == 0) ? '0' : '1'; // Return '0' for even count, '1' for odd
// }

// // Function to check received data
// bool checkVRC(const string& receivedData) {
//     // Separate data and parity
//     string data = receivedData.substr(0, receivedData.length() - 1);
//     char receivedParity = receivedData.back();
    
//     char expectedParity = calculateParityBit(data);
    
//     return receivedParity == expectedParity; // Return true if no error
// }

// int main() {
//     string data;

//     cout << "Enter a binary string (e.g., 1011001): ";
//     cin >> data;

//     // Calculate and append the parity bit
//     char parityBit = calculateParityBit(data);
//     string dataWithParity = data + parityBit;

//     cout << "Data with parity bit: " << dataWithParity << endl;

//     // Simulate received data
//     cout << "Enter received data (with parity bit): ";
//     string receivedData;
//     cin >> receivedData;

//     // Check for errors
//     if (checkVRC(receivedData)) {
//         cout << "No errors detected." << endl;
//     } else {
//         cout << "Error detected in the received data." << endl;
//     }

//     return 1;
// }







// Mam Code



// #include<bits/stdc++.h>
// using namespace std;

// string getString(char x)
// {
//     string s(1, x);
//     return s;
// }

// int calculate_vrc(string val)
// {
//     int j=0;
//     int a =0;
//     for(int i=0; i<val.length(); i++)
//     {
//         int x;
//         string s = getString(val[i]);
//         stringstream frame(s);
//         frame >> x;
//         a=a+x;
//     }
//         //cout<<"\n"<<res;
//         return a;
// }

// int main(){
//     int n;

//     cout<<"Enter 0 for ODD\nENTER 1 for EVEN\n";
//     cin>>n;

//     int res;
//     string line;
//     string val[4];
//     ifstream f("datal.txt");
//     int i=0;

//     while(getline(f, line))
//     {
//         cout<<line;
//         val[i]=line;
//         i++;
//         cout<<"\n";
//     }

//     for(int i=0; i<4; i++)
//     {
//         res = calculate_vrc(val[i]);
//         if(n==1)
//         {
//             if(res%2==0)
//             {
//                 val[i].append("0");
//                 cout<<"\n"<<val[i];
//             }
//             else
//             {
//                 val[i].append("1");
//                 cout<<"\n"<<val[i];
//             }
//         }

//         else
//         {
//             if(res%2==0)
//             {
//                 val[i].append("1");
//                 cout<<"\n"<<val[i];
//             }else
//             {
//                 val[i].append("0");
//                 cout<<"\n"<<val[i];
//             }
//         }
//     }
// }








