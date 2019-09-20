//Homework 2.1: Ans 1) & Ans 2)
#include "NodeRequesting.h"

int main() {
	std::cout << "Enter the number of node:";
	int noOfNodes;
	std::cin >> noOfNodes;
	std::cout << "Number of nodes: "<< noOfNodes<<"\n\n";
	NodeRequesting**nodes;
	nodes = new NodeRequesting * [noOfNodes];
	
	for (int i = 0; i < noOfNodes; i++) {
		NodeRequesting* P = new NodeRequesting(i, 'R', 'F');
		nodes[i] = P;
	}


	int votingSet = floor(sqrt(noOfNodes));
	std::cout << "The number of voting set is " << votingSet << "\n\n";

	int nodeInVotingSet = votingSet;
	std::cout << "The number of node in voting set is " << votingSet << "\n\n";


	std::vector<std::vector<int>> VotingSets;
	std::vector<int> set;

	int votingIndex = 0;
	for (int i = 0; i < noOfNodes; i++)
	{
		if (i % nodeInVotingSet == 0 && i != 0) 
		{ 
			votingIndex = votingIndex + 1; 
			VotingSets.push_back(set); 
			set.clear(); 
		}
		nodes[i]->setVotingSet(votingIndex);

	    std::cout << "Node " << i << " voting set is being set to " << votingIndex << ".\n";
		set.push_back(i);
	}

	VotingSets.push_back(set);

	std::cout << "Voting Sets:\n";
	for (int i = 0; i < votingSet; i++) 
	{
		for (int j = 0; j < nodeInVotingSet; j++) 
		{
			std::cout << "ID: " << VotingSets[i][j] << "\n";
		}
	}

	int process, time = 1;

	std::cout << "\nEnter Process from 1 to "<<noOfNodes<<": ";
	std::cin >> process;
	std::cout << "\n";
	std::cout << "How many milliseconds: ";
	std::cin >> time;
	std::cout << "\n";
	if (time != 0) 
	{
		nodes[process]->setState('W');// W - wanted
		std::cout << "Node " << process << " state set to Wanted.\n";
		nodes[process]->Request(*nodes, noOfNodes);

		nodes[process]->setState('H');// H - Held
		std::cout << "\nProcess " << process << " State changed to Held.\n";
		nodes[process]->Process(time);
	}
	
}