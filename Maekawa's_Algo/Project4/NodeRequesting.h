
#include <iostream>
#include <string>
#include <time.h>
#include <vector>
#include <thread>
#include <math.h> 
#include <windows.h>
#ifndef NODE_H
#define NODE_H

class NodeRequesting {

public:
	NodeRequesting();
	void Process(int taskTime);
	void Request(NodeRequesting* nodes, int n);
	void GrantAccess(int requestersID);

	NodeRequesting(int newID, char newState, char newVoted) 
	{ 
		Id = newID; state = newState; voted = newVoted; 
	}

	void getID() 
	{ 
		std::cout << Id; 
	}

	void setState(char newState) 
	{ 
		state = newState; 
	}

	char getState() 
	{
		return state; 
	}

	char getVoted() 
	{ 
		return voted; 
	}

	void setVotingSet(int set) 
	{ 
		votingSet = set;
	}
	int getVotingSet() 
	{ 
		return votingSet; 
	}

private:
	int Id;
	char state;
	char voted;

	int votingSet;
	std::vector<int> queue;
};

void NodeRequesting::Process(int taskTime) {
	time_t my_time = time(NULL);
	printf("     %s", ctime(&my_time));

	std::cout << "Node " << Id << " processing task takes " << taskTime << " millisecond.\n";
	Sleep(taskTime);//Thread this section
	my_time = time(NULL);
	printf("     %s", ctime(&my_time));
}

void NodeRequesting::Request(NodeRequesting* nodes, int n) {
	int k = floor(sqrt(n));
	int m = k;

	int row = n / Id;
	std::cout << "Row: " << row;
	for (int i = 0; i < n; i++) {
		if (i / n == row && i != Id) {
			nodes[i].GrantAccess(Id);
			std::cout << " $$ Requesting node " << i << ".\n";
		}
	}

	int column;
	column = Id % (m);
	std::cout << "Column:  "<< column<<"\n";
	for (int i = 0; i < n; i++) {
		if (i % m == column && i != Id) {
			nodes[i].GrantAccess(Id);
			std::cout << " && Requesting node " << i << ".\n";
		}
	}
}

void NodeRequesting::GrantAccess(int RequestersID)
{
	std::cout << " Grant access: " << RequestersID << ".\n";
}

#endif