// C++ program to create client 

#include <iostream> 
#include <string.h> 
#include <winsock2.h> 
using namespace std;

// Function that receive data from server 
DWORD WINAPI clientReceive(LPVOID lpParam)
{
	// Created buffer[] to 
	// receive message 
	char buffer[1024] = { 0 };

	// Created server socket 
	SOCKET server = *(SOCKET*)lpParam;

	// Client executes continuously 
	while (true) {

		// If received buffer gives 
		// error then return -1 
		if (recv(server, buffer,
			sizeof(buffer), 0)
			== SOCKET_ERROR) {
			cout << "recv function failed with error: "
				<< WSAGetLastError()
				<< endl;
			return -1;
		}

		// If Server exits 
		if (strcmp(buffer, "exit") == 0) {
			cout << "Server disconnected."
				<< endl;
			return 1;
		}

		// Print the message 
		// given by server that 
		// was stored in buffer 
		cout << buffer << endl;

		// Clear buffer message 
		memset(buffer, 0, sizeof(buffer));
	}
	return 1;
}

// Function that sends data to server 
DWORD WINAPI clientSend(LPVOID lpParam)
{
	// Created buffer[] to 
	// receive message 
	char buffer[1024] = { 0 };

	// Created server socket 
	SOCKET server = *(SOCKET*)lpParam;

	// Client executes continuously 
	while (true) {

		// Input message client 
		// wants to send to server 
		gets(buffer);

		// If sending failed 
		// return -1 
		if (send(server,
			buffer,
			sizeof(buffer), 0)
			== SOCKET_ERROR) {
			cout << "send failed with error: "
				<< WSAGetLastError() << endl;
			return -1;
		}

		// If client exit 
		if (strcmp(buffer, "exit")
			== 0) {
			cout << "Thank you for using the application"
				<< endl;
			break;
		}
	}
	return 1;
}

// Driver Code 
int main()
{
	// Input data 
	WSADATA WSAData;

	// Created socket server 
	SOCKET server;
	SOCKADDR_IN addr;

	WSAStartup(MAKEWORD(2, 0), &WSAData);

	// If invalid socket created, 
	// return -1 
	if ((server = socket(AF_INET,
		SOCK_STREAM, 0))
		== INVALID_SOCKET) {
		cout << "Socket creation failed with error: "
			<< WSAGetLastError() << endl;
		return -1;
	}

	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	addr.sin_family = AF_INET;
	addr.sin_port = htons(5555);

	// If connection failed 
	if (connect(server,
		(SOCKADDR*)&addr,
		sizeof(addr))
		== SOCKET_ERROR) {
		cout << "Server connection failed with error: "
			<< WSAGetLastError() << endl;
		return -1;
	}

	// If connection established 
	cout << "Connected to server!"
		<< endl;
	cout << "Now you can use our live chat application."
		<< " Enter \"exit\" to disconnect"
		<< endl;
	DWORD tid;

	// Create Thread t1 
	HANDLE t1 = CreateThread(NULL,
		0,
		clientReceive,
		&server,
		0, &tid);

	// If created thread 
	// is not created 
	if (t1 == NULL)
		cout << "Thread creation error: "
		<< GetLastError();

	// Create Thread t2 
	HANDLE t2 = CreateThread(NULL,
		0,
		clientSend,
		&server,
		0, &tid);

	// If created thread 
	// is not created 
	if (t2 == NULL)
		cout << "Thread creation error: "
		<< GetLastError();

	// Received Objects 
	// from client 
	WaitForSingleObject(t1, INFINITE);
	WaitForSingleObject(t2, INFINITE);

	// Socket closed 
	closesocket(server);
	WSACleanup();
}
