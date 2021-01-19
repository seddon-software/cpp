#include <iostream>
#include <vector>
#include <list>
#include <memory>
using namespace std;

class Resource
{
public:
	Resource()
	{
		words = {"The", "rain", "in", "Spain", "falls", "mainly", "in", "the", "plane"};
		cout << "Resource created" << endl;
	}
	~Resource()
	{
		cout << "Resource destroyed" << endl;
	}
	bool pop()
	{
		if(words.size() == 0)
		{
			return true;
		}
		else
		{
			cout << words.front() << endl;
			words.pop_front();
			return false;
		}
	}
private:
	list<string> words;
};

class Client
{
public:
	Client(const string& name): name(name){}
	void receive(shared_ptr<Resource>& resource)
	{
		this->resource = resource;
	}
	void consume()
	{
		if(resource)
		{
			if(resource->pop())
			{
				resource.reset();
				cout << name << " releasing resouce" << endl;
			}
		}
	}
private:
	const string name;
	shared_ptr<Resource> resource;
};

class Server
{
public:
	void send()
	{
		shared_ptr<Resource> resource(new Resource());
		for(auto pClient:pClients)
		{
			Client& client = *pClient;
			client.receive(resource);
		}
	}
	void registration(Client& client)
	{
		pClients.push_back(&client);
	}
private:
	vector<Client*> pClients;
};


int main()
{
	Server server;
	Client client1("Client 1");
	Client client2("Client 2");
	Client client3("Client 3");
	server.registration(client1);
	server.registration(client2);
	server.registration(client3);
	server.send();
	client1.consume();
	client2.consume();
	client1.consume();
	client3.consume();
	client3.consume();
	client2.consume();
	client1.consume();
	client3.consume();
	client3.consume();
	client1.consume();
	client3.consume();
	client3.consume();
	client2.consume();
}
