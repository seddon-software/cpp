//////////////////////////////////////////////////////////////////////
//
//		Http Server
//
//////////////////////////////////////////////////////////////////////

#include <iostream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <thread>
#include <dirent.h>
#include <fstream>
using namespace std;


void error(const char *msg)
{
	perror(msg);
	exit(1);
}

bool ends_with(std::string const & value, std::string const & ending)
{
    if (ending.size() > value.size()) return false;
    return std::equal(ending.rbegin(), ending.rend(), value.rbegin());
}

string retrieveListOfDataFiles()
{
	stringstream ss;
	DIR *dir;
	struct dirent *entry;
	if ((dir = opendir(".")) != NULL)
	{
		/* print all the files and directories within directory */
		while ((entry = readdir(dir)) != NULL)
		{
			string s(entry->d_name);
			if(ends_with(s, ".exe"))
			{
				cout << s << endl;
				ss << s << endl;
			}
		}
		closedir(dir);
	}
	else
		error("could not open directory");
	return ss.str();
}

string getFileContents(const std::string& path)
{
	ifstream in(path.c_str());
	string contents((istreambuf_iterator<char>(in)),
			istreambuf_iterator<char>());
	return contents;
}

void serveFile(const string& fileName, int newsockfd)
{
	string contents = getFileContents(fileName);
	int bufferSize = contents.length() + 1;
	char* buffer = new char[bufferSize];
	size_t length = contents.copy(buffer, bufferSize, 0);
	buffer[length] = '\0';
	write(newsockfd, buffer, bufferSize);
	delete[] buffer;
}

void clearStructure(struct sockaddr_in address)
{
	bzero((char*) (&address), sizeof(address));
}

string getRequest(int fd)
{
	char buffer[512];
	int n = 512;
	stringstream ss;

	while(n == 512)
	{
		n = read(fd, buffer, 512);
		ss << buffer;
	}
	ss << '\0';
	cout << ss.str() << endl;
	return ss.str();
}

string readRequest(int fd)
{
	string request = getRequest(fd);

	// read data starting with:  GET /<fileName> ....
	stringstream ss;
	ss << request;
	string s;
	char slash;
	ss >> s >> slash >> s;
	cout << s << endl;
	return s;
}

int main(int argc, char *argv[])
{
	cout <<	retrieveListOfDataFiles() << endl;

	int listeningSocketFd, newSocketFd;
	int portNumber;
	socklen_t clientStructLength;
	//char buffer[256];
	struct sockaddr_in serverAddress, clientAddress;

	listeningSocketFd = socket(AF_INET, SOCK_STREAM, 0);
	if (listeningSocketFd < 0)
		error("ERROR opening socket");
	clearStructure(serverAddress);
	portNumber = argc < 2 ? 8080 : atoi(argv[1]);
	serverAddress.sin_family = AF_INET;
	serverAddress.sin_addr.s_addr = INADDR_ANY;
	serverAddress.sin_port = htons(portNumber);

	int rv = ::bind(listeningSocketFd, (struct sockaddr *) &serverAddress,
			sizeof(serverAddress));
	if (rv < 0)
		error("ERROR on binding");
	listen(listeningSocketFd, 5);
	clientStructLength = sizeof(clientAddress);
	newSocketFd = accept(listeningSocketFd, (struct sockaddr *) &clientAddress,
			&clientStructLength);
	if (newSocketFd < 0)
		error("ERROR on accept");

	// create thread to serve file
	std::thread t([newSocketFd]()
	{
		string fileName = readRequest(newSocketFd);
		serveFile(fileName, newSocketFd);
	});
	t.join();
	close(newSocketFd);
	close(listeningSocketFd);
}
