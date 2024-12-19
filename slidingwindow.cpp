// // sliding window

#include<iostream>
#include<cstdlib>
#include<thread>
#include<chrono>
using namespace std;

int main()
{
	int totalFrames = 10;
	int windowSize = 3;
	int frame = 1;

	while(frame <= totalFrames)
	{
		int sentFrames = 0;
		for(int i=0; i<windowSize && frame+i; i++)
		{
			cout<<"Sending Frame "<<frame + i<<endl;
			sentFrames++;
		}
		this_thread::sleep_for(chrono::milliseconds(1000));
		// frame(0:lost,1:received)
		int ackReceived = 0;
		for(int i=0; i<sentFrames; i++)
		{
			int ack = rand() % 2;
			if(ack == 1)
			{
				cout<<"Ack Received for Frame "<<frame+i<<endl;
				ackReceived++;
			}
			else
			{
				cout<<"Frame "<<frame + i<<" lost,recending..."<<endl;
			}
		}
		cout<<"------------------------------------------------------"<<endl;

		frame += ackReceived;
	}
	cout<<"All Frames Sent Successfully..."<<endl;
}


// Sending Frame 1
// Sending Frame 2
// Sending Frame 3
// Ack Received for Frame 1
// Frame 2 lost,recending...
// Ack Received for Frame 3
// ------------------------------------------------------
// Sending Frame 3
// Sending Frame 4
// Sending Frame 5
// Ack Received for Frame 3
// Ack Received for Frame 4
// Ack Received for Frame 5
// ------------------------------------------------------
// Sending Frame 6
// Sending Frame 7
// Sending Frame 8
// Frame 6 lost,recending...
// Frame 7 lost,recending...
// Ack Received for Frame 8
// ------------------------------------------------------
// Sending Frame 7
// Sending Frame 8
// Sending Frame 9
// Ack Received for Frame 7
// Frame 8 lost,recending...
// Ack Received for Frame 9
// ------------------------------------------------------
// Sending Frame 9
// Sending Frame 10
// Sending Frame 11
// Frame 9 lost,recending...
// Ack Received for Frame 10
// Ack Received for Frame 11
// ------------------------------------------------------
// All Frames Sent Successfully...










// #include <iostream>
// #include <cstdlib>
// #include <thread>
// #include <chrono>
// using namespace std;

// int main()
// {
//     int totalFrames = 10;
//     int windowSize = 3;
//     int frame = 1;

//     while (frame <= totalFrames)
//     {
//         int sentFrames = 0;
        
//         // Send frames up to the window size or until the total frames are sent
//         for (int i = 0; i < windowSize && frame + i <= totalFrames; i++)
//         {
//             cout << "Sending Frame " << frame + i << endl;
//             sentFrames++;
//         }
        
//         // Sleep for 1 second
//         this_thread::sleep_for(chrono::milliseconds(1000)); // Fixed the typo here
        
//         int ackReceived = 0; // Moved this declaration outside the loop
//         for (int i = 0; i < sentFrames; i++)
//         {
//             int ack = rand() % 2; // Simulating ACK reception
//             if (ack == 1)
//             {
//                 cout << "Ack Received for Frame " << frame + i << endl;
//                 ackReceived++;
//             }
//             else
//             {
//                 cout << "Frame " << frame + i << " lost, resending..." << endl;
//             }
//         }
        
//         cout << "------------------------------------------------------" << endl;

//         // Move the frame pointer forward by the number of ACKs received
//         frame += ackReceived;
//     }
//     cout << "All Frames Sent Successfully..." << endl;

//     return 0; // Added return statement
// }
