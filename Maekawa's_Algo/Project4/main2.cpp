//Homework 2.2 : min-min, max-min, sufferage
//Author: Kenneth Messner
//Last Modified: 9/18/2019

#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <cmath>

void minMin();
void maxMin();
void sufferage();

void process(int task, int machine, int time);
int findMin(int task[7]);
int findSecondMin(int task[7]);
int findMachine(int task, int machine);

//The below arrays list the computation times for machines [0-7] that type of task.
//All 100's in the below arrays are actually computationally infeasible
int task0[7]{ 13,79,23,71,60,27,2 };
int task1[7]{ 31,13,14,94,60,61,57 };
int task2[7]{ 17,1,100,23,36,8,86 };
int task3[7]{ 19,28,10,4,58,73,40 };
int task4[7]{ 94,75,100,58,100,68,46 };
int task5[7]{ 8,24,3,32,4,94,89 };
int task6[7]{ 10,57,13,1,92,75,29 };
int task7[7]{ 80,17,38,40,66,25,88 };

int main() {
	std::cout << "Homework 2.2 | Ken Messner | min-min, max-min, sufferage.\n\n";

	std::cout << "======================= Executing Algorithm Min-Min =======================\n";
	minMin();
	std::cout << "===========================================================================\n\n";

	std::cout << "\n======================= Executing Algorithm Max-Min =======================\n";
	maxMin();
	std::cout << "===========================================================================\n\n";

	std::cout << "\n====================== Executing Algorithm Sufferage ======================\n";
	sufferage();
	std::cout << "===========================================================================\n\n";
}

void process(int task, int machine, int time) {
	std::cout << "Task | " << task << " | executed on machine | " << machine << " | had a durration of | ";

	if (time < 10) { std::cout << " "; }

	std::cout << time << " | milliseconds.\n";
}

void minMin() {
	std::vector<int> taskMinTimes;

	taskMinTimes.push_back(findMin(task0));
	taskMinTimes.push_back(findMin(task1));
	taskMinTimes.push_back(findMin(task2));
	taskMinTimes.push_back(findMin(task3));
	taskMinTimes.push_back(findMin(task4));
	taskMinTimes.push_back(findMin(task5));
	taskMinTimes.push_back(findMin(task6));
	taskMinTimes.push_back(findMin(task7));

	// for(int i = 0; i < 8; ++i){
	//     std::cout << taskMinTimes[i] << ", ";
	// }

	for (int j = 0; j < 8; ++j) {
		int i, min = 100, minTime = 100;
		for (i = 0; i < taskMinTimes.size(); ++i) {
			//std::cout << " > Task " << i << " has a min time of " << taskMinTimes[i] << ".\n";
			if (taskMinTimes[i] < minTime) {
				min = i;
				minTime = taskMinTimes[i];
				//std::cout << "### Min found: " << min << " with a time of: " << taskMinTimes[i] << ".\n";
			}
		}
		process(min, findMachine(min, taskMinTimes[min]), minTime);
		taskMinTimes[min] = 100;
		// for(int i = 0; i < 8; ++i){
		//     std::cout << taskMinTimes[i] << ", ";
		// }
	}
}

void maxMin() {
	std::vector<int> taskMinTimes;

	taskMinTimes.push_back(findMin(task0));
	taskMinTimes.push_back(findMin(task1));
	taskMinTimes.push_back(findMin(task2));
	taskMinTimes.push_back(findMin(task3));
	taskMinTimes.push_back(findMin(task4));
	taskMinTimes.push_back(findMin(task5));
	taskMinTimes.push_back(findMin(task6));
	taskMinTimes.push_back(findMin(task7));

	// for(int i = 0; i < 8; ++i){
	//     std::cout << taskMinTimes[i] << ", ";
	// }
	// std::cout << ".\n\n";

	for (int j = 0; j < 8; ++j) {
		int i, max = 0, maxTime = 0;
		for (i = 0; i < taskMinTimes.size(); ++i) {
			//std::cout << " > Task " << i << " has a min time of " << taskMinTimes[i] << ".\n";
			if (taskMinTimes[i] > maxTime) {
				max = i;
				maxTime = taskMinTimes[i];
				//std::cout << "### Min found: " << min << " with a time of: " << taskMinTimes[i] << ".\n";
			}
		}
		process(max, findMachine(max, taskMinTimes[max]), maxTime);
		taskMinTimes[max] = 0;
		// for(int i = 0; i < 8; ++i){
		//     std::cout << taskMinTimes[i] << ", ";
		// }
	}
}

void sufferage() {
	std::vector<int> taskMinTimes, taskSecondMinTimes;

	taskMinTimes.push_back(findMin(task0));
	taskMinTimes.push_back(findMin(task1));
	taskMinTimes.push_back(findMin(task2));
	taskMinTimes.push_back(findMin(task3));
	taskMinTimes.push_back(findMin(task4));
	taskMinTimes.push_back(findMin(task5));
	taskMinTimes.push_back(findMin(task6));
	taskMinTimes.push_back(findMin(task7));

	taskSecondMinTimes.push_back(findSecondMin(task0));
	taskSecondMinTimes.push_back(findSecondMin(task1));
	taskSecondMinTimes.push_back(findSecondMin(task2));
	taskSecondMinTimes.push_back(findSecondMin(task3));
	taskSecondMinTimes.push_back(findSecondMin(task4));
	taskSecondMinTimes.push_back(findSecondMin(task5));
	taskSecondMinTimes.push_back(findSecondMin(task6));
	taskSecondMinTimes.push_back(findSecondMin(task7));


	// std::cout << "\n\n";

	// for(int i = 0; i < 8; ++i){
	//     std::cout << taskMinTimes[i] << ", ";
	// }

	// std::cout << "\n\n";

	// for(int i = 0; i < 8; ++i){
	//     std::cout << taskSecondMinTimes[i] << ", ";
	// }

	// std::cout << "\n\n";


	for (int j = 0; j < 8; ++j) {
		int i, max = 0, Time = 0;
		for (i = 0; i < taskMinTimes.size(); ++i) {
			if (taskSecondMinTimes[i] - taskMinTimes[i] > Time && taskSecondMinTimes[i] != 100 && taskMinTimes[i] != 100) {
				max = i;
				Time = taskSecondMinTimes[i] - taskMinTimes[i];
				//std::cout << "New max sufferage found on task " << max << " with a time difference of " << taskSecondMinTimes[i]-taskMinTimes[i] << ".\n";
			}
		}
		process(max, findMachine(max, taskMinTimes[max]), taskMinTimes[max]);
		taskMinTimes[max] = 100;
	}
}

int findMin(int task[7]) {
	int min = task[0];

	for (int i = 0; i < 7; ++i) {
		if (task[i] < min) { min = task[i]; }
	}

	return min;
}

int findMachine(int task, int time) {
	int machine;

	switch (task)
	{
	case 0:
		for (int i = 0; i < 7; ++i) {
			if (task0[i] == time) { machine = i; }
		}
		break;
	case 1:
		for (int i = 0; i < 7; ++i) {
			if (task1[i] == time) { machine = i; }
		}
		break;
	case 2:
		for (int i = 0; i < 7; ++i) {
			if (task2[i] == time) { machine = i; }
		}
		break;
	case 3:
		for (int i = 0; i < 7; ++i) {
			if (task3[i] == time) { machine = i; }
		}
		break;
	case 4:
		for (int i = 0; i < 7; ++i) {
			if (task4[i] == time) { machine = i; }
		}
		break;
	case 5:
		for (int i = 0; i < 7; ++i) {
			if (task5[i] == time) { machine = i; }
		}
		break;
	case 6:
		for (int i = 0; i < 7; ++i) {
			if (task6[i] == time) { machine = i; }
		}
		break;
	case 7:
		for (int i = 0; i < 7; ++i) {
			if (task7[i] == time) { machine = i; }
		}
		break;

	default:
		break;
	}
	return machine;
}

int findSecondMin(int task[7]) {
	int min = 100;
	int secondMin = 100;

	for (int i = 0; i < 7; ++i) {
		if (task[i] < min) {
			min = task[i];
			//std::cout << "New min found, " << min <<".\n";
			if (i == 0) { secondMin = min; }
		}
		if (task[i] < secondMin && task[i] != min) {
			secondMin = task[i];
			//std::cout << "New second-min found, " << secondMin <<".\n";
		}
	}
	//std::cout << "\n";

	return secondMin;
}