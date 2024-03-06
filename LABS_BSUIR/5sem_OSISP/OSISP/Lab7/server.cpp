// C++ program to create Server 

#include <iostream> 
#include <string.h> 
#include <winsock2.h> 
#include <vector>
#include <set>
#include <algorithm>
#include <string>
#include <sstream>

std::vector<SOCKET*> clients;

using namespace std;

// Function that receive data 
// from client 
DWORD WINAPI serverReceive(LPVOID lpParam)
{
	// Created buffer[] to 
	// receive message 
	char buffer[1024] = { 0 };

	// Created client socket 
	SOCKET client = *(SOCKET*)lpParam;

	// Server executes continuously 
	while (true) {

		// If received buffer gives 
		// error then return -1 
		if (recv(client, buffer, sizeof(buffer), 0)
			== SOCKET_ERROR) {
			cout << "recv function failed with error "
				<< WSAGetLastError() << endl;
			return -1;
		}

		// If Client exits 
		if (strcmp(buffer, "exit") == 0) {
			cout << "Client Disconnected."
				<< endl;
			break;
		}

		std::set<SOCKET*> st{ clients.begin(), clients.end() };
		std::vector<SOCKET*> tmp{ clients.front() };



		int indx;

		if (*tmp.back() == client)
			indx = 0;

		for (int i = 1; i < clients.size(); i++) {
			if (clients[i] == clients[i - 1])
				continue;

			tmp.push_back(clients[i]);

			if (*tmp.back() == client)
				indx = tmp.size() - 1;
		}

		//int i = std::distance(tmp.begin(), std::find(tmp.begin(), tmp.end(), client));

		std::string msg(buffer);

		if (msg.find("to: ") != std::string::npos) {
			std::stringstream ss;
			std::string tmp_m;
			ss << msg;
			ss >> tmp_m;
			int clt;
			ss >> clt;
			ss >> tmp_m;
			msg = msg.substr(msg.find(tmp_m));
			msg = "Client " + std::to_string(indx + 1) + ": " + msg;
			if (clt <= tmp.size() && clt >= 0) {
				send(*tmp[clt - 1],
					msg.c_str(),
					msg.size(), 0);
			}

		}
		else {

			for (auto x : tmp) {
				std::string s(buffer);
				std::string num{ std::to_string(indx + 1) };
				s = "Client " + num + ": " + s;

				if (*x != client) {
					send(*x,
						s.c_str(),
						s.size(), 0);
					cout << "Client: " << s << ' ' << st.size() << endl;

				}
			}
		}
		// Print the message 
		// given by client that 
		// was stored in buffer 


		// Clear buffer message 
		memset(buffer, 0,
			sizeof(buffer));
	}
	return 1;
}

// Function that sends data to client 
DWORD WINAPI serverSend(LPVOID lpParam)
{
	// Created buffer[] to 
	// receive message 
	char buffer[1024] = { 0 };

	// Created client socket 
	SOCKET client = *(SOCKET*)lpParam;

	// Server executes continuously 
	while (true) {

		// Input message server 
		// wants to send to client 
		gets(buffer);

		// If sending failed 
		// return -1 
		//for (auto x:clients)
		if (send(client,
			buffer,
			sizeof(buffer), 0)
			== SOCKET_ERROR) {
			cout << "send failed with error "
				<< WSAGetLastError() << endl;
			return -1;
		}

		// If server exit 
		if (strcmp(buffer, "exit") == 0) {
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
	clients.clear();

	// Data 
	WSADATA WSAData;

	// Created socket server 
	// and client 
	SOCKET server, client, client2;

	// Socket address for server 
	// and client 
	SOCKADDR_IN serverAddr, clientAddr, clientAddr2;

	WSAStartup(MAKEWORD(2, 0), &WSAData);

	// Making server 
	server = socket(AF_INET,
		SOCK_STREAM, 0);

	// If invalid socket created, 
	// return -1 
	if (server == INVALID_SOCKET) {
		cout << "Socket creation failed with error:"
			<< WSAGetLastError() << endl;
		return -1;
	}
	serverAddr.sin_addr.s_addr = INADDR_ANY;
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(5555);

	// If socket error occurred, 
	// return -1 
	if (bind(server,
		(SOCKADDR*)&serverAddr,
		sizeof(serverAddr))
		== SOCKET_ERROR) {
		cout << "Bind function failed with error: "
			<< WSAGetLastError() << endl;
		return -1;
	}

	// Get the request from 
	// server 
	if (listen(server, 0)
		== SOCKET_ERROR) {
		cout << "Listen function failed with error:"
			<< WSAGetLastError() << endl;
		return -1;
	}

	cout << "Listening for incoming connections...." << endl;

	// Create buffer[] 
	char buffer[1024];

	std::vector<SOCKADDR_IN> addrs;
	std::vector<int> sizes;

	addrs.push_back(SOCKADDR_IN());
	sizes.push_back(sizeof(addrs.back()));

	while (true) {
		SOCKET* client = new SOCKET;

		if ((*client = accept(server,
			(SOCKADDR*)&addrs.back(),
			&sizes.back()))
			!= INVALID_SOCKET) {
			clients.push_back(client);
			addrs.push_back(SOCKADDR_IN());
			sizes.push_back(sizeof(addrs.back()));

			cout << "Client connected!" << endl;
			cout << "Now you can use our live chat application."
				<< "Enter \"exit\" to disconnect" << endl;

			// Create variable of 
			// type DWORD 
			DWORD tid;

			clients.push_back(client);

			// Create Thread t1 
			HANDLE t1 = CreateThread(NULL,
				0,
				serverReceive,
				client,
				0,
				&tid);

			// If created thread 
			// is not created 
			if (t1 == NULL) {
				cout << "Thread Creation Error: "
					<< WSAGetLastError() << endl;
			}

			// Create Thread t2 
			/*HANDLE t2 = CreateThread(NULL,
				0,
				serverSend,
				client,
				0,
				&tid);

			// If created thread
			// is not created
			if (t2 == NULL) {
				cout << "Thread Creation Error: "
					<< WSAGetLastError() << endl;
			}*/

			// Received Objects 
			// from client 
			//WaitForSingleObject(t1,
			//	INFINITE);
			//WaitForSingleObject(t2,
			//	INFINITE);

			// Close the socket 
			//closesocket(client);

			// If socket closing 
			// failed. 
			/*if (closesocket(server)
				== SOCKET_ERROR) {
				cout << "Close socket failed with error: "
					<< WSAGetLastError() << endl;
				return -1;
			}
			WSACleanup();*/
		}
	}
}
