
#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <cmath>

void minMin();
void maxMin();
void sufferage();

void process(int task, int machine, int time);
int findFirstMinValue(int task[7]);
int findSecondMinValue(int task[7]);
int findMachine(int task, int machine);

//The list below shows the task array for Machine 0 to Machine 7.
// null placed where no task is assigned
int task0[7]{ 13,79,23,71,60,27,2 };
int task1[7]{ 31,13,14,94,60,61,57 };
int task2[7]{ 17,1,'null',23,36,8,86 };
int task3[7]{ 19,28,10,4,58,73,40 };
int task4[7]{ 94,75,'null',58,'null',68,46 };
int task5[7]{ 8,24,3,32,4,94,89 };
int task6[7]{ 10,57,13,1,92,75,29 };
int task7[7]{ 80,17,38,40,66,25,88 };

int main() {
	std::cout << " Min-Min Algorithm: \n";
	minMin();
	std::cout << "\n\n";

	std::cout << " Max-Min Algorithm: \n";
	maxMin();
	std::cout << "\n\n";

	std::cout << " Sufferage Algorithm: \n";
	sufferage();
	std::cout << "\n\n";
}

void minMin() {
	std::vector<int> minTimes;

	minTimes.push_back(findFirstMinValue(task0));
	minTimes.push_back(findFirstMinValue(task1));
	minTimes.push_back(findFirstMinValue(task2));
	minTimes.push_back(findFirstMinValue(task3));
	minTimes.push_back(findFirstMinValue(task4));
	minTimes.push_back(findFirstMinValue(task5));
	minTimes.push_back(findFirstMinValue(task6));
	minTimes.push_back(findFirstMinValue(task7));

	for (int j = 0; j < 8; ++j) {
		int i;
		int min = 100;
		int minTime = 100;
		for (i = 0; i < minTimes.size(); ++i) {			
			if (minTimes[i] < minTime) {
				min = i;
				minTime = minTimes[i];
			}
		}
		//call Process
		process(min, findMachine(min, minTimes[min]), minTime);
		minTimes[min] = 100;
	}
}

void maxMin() {
	std::vector<int> minTimes;

	minTimes.push_back(findFirstMinValue(task0));
	minTimes.push_back(findFirstMinValue(task1));
	minTimes.push_back(findFirstMinValue(task2));
	minTimes.push_back(findFirstMinValue(task3));
	minTimes.push_back(findFirstMinValue(task4));
	minTimes.push_back(findFirstMinValue(task5));
	minTimes.push_back(findFirstMinValue(task6));
	minTimes.push_back(findFirstMinValue(task7));

	for (int j = 0; j < 8; ++j) {
		int i;
		int max = 0;
		int maxTime = 0;
		for (i = 0; i < minTimes.size(); ++i) {
			if (minTimes[i] > maxTime) {
				max = i;
				maxTime = minTimes[i];
			}
		}
		//call Process
		process(max, findMachine(max, minTimes[max]), maxTime);
		minTimes[max] = 0;
	}
}

void sufferage() {
	std::vector<int> minTimes, secondMinTimes;

	minTimes.push_back(findFirstMinValue(task0));
	minTimes.push_back(findFirstMinValue(task1));
	minTimes.push_back(findFirstMinValue(task2));
	minTimes.push_back(findFirstMinValue(task3));
	minTimes.push_back(findFirstMinValue(task4));
	minTimes.push_back(findFirstMinValue(task5));
	minTimes.push_back(findFirstMinValue(task6));
	minTimes.push_back(findFirstMinValue(task7));

	secondMinTimes.push_back(findSecondMinValue(task0));
	secondMinTimes.push_back(findSecondMinValue(task1));
	secondMinTimes.push_back(findSecondMinValue(task2));
	secondMinTimes.push_back(findSecondMinValue(task3));
	secondMinTimes.push_back(findSecondMinValue(task4));
	secondMinTimes.push_back(findSecondMinValue(task5));
	secondMinTimes.push_back(findSecondMinValue(task6));
	secondMinTimes.push_back(findSecondMinValue(task7));

	for (int j = 0; j < 8; ++j) {

		int i;
		int max = 0;
		int Time = 0;
		for (i = 0; i < minTimes.size(); ++i) {
			if (secondMinTimes[i] - minTimes[i] > Time && secondMinTimes[i] != 100 && minTimes[i] != 100) {
				max = i;
				Time = secondMinTimes[i] - minTimes[i];				
			}
		}
		//call Process
		process(max, findMachine(max, minTimes[max]), minTimes[max]);
		minTimes[max] = 100;
	}
}

int findFirstMinValue(int task[7]) {
	int min = task[0];

	for (int i = 0; i < 7; ++i) {
		if (task[i] < min) { min = task[i]; }
	}
	//returns Minimum Value
	return min;
}

int findMachine(int task, int time) {
	int machine;
	if (task == 0) 
	{
		for (int i = 0; i < 7; ++i) {
			if (task0[i] == time && task0[i] != 'null') { machine = i; }
		}
	}
	else if (task == 1)
	{
		for (int i = 0; i < 7; ++i) {
			if (task1[i] == time && task1[i] != 'null') { machine = i; }
		}
	}
	else if (task == 2)
	{
		for (int i = 0; i < 7; ++i) {
			if (task2[i] == time && task2[i] != 'null') { machine = i; }
		}
	}
	else if (task == 3)
	{
		for (int i = 0; i < 7; ++i) {
			if (task3[i] == time && task3[i] != 'null') { machine = i; }
		}
	}
	else if (task == 4)
	{
		for (int i = 0; i < 7; ++i) {
			if (task4[i] == time && task4[i] != 'null') { machine = i; }
		}
	}
	else if (task == 5)
	{
		for (int i = 0; i < 7; ++i) {
			if (task5[i] == time && task5[i] != 'null') { machine = i; }
		}
	}
	else if (task == 6)
	{
		for (int i = 0; i < 7; ++i) {
			if (task6[i] == time && task6[i] != 'null') { machine = i; }
		}
	}
	else if (task == 7)
	{
		for (int i = 0; i < 7; ++i) {
			if (task7[i] == time && task7[i] != 'null') { machine = i; }
		 }
	}
	return machine;
}

int findSecondMinValue(int task[7]) {
	int min = 100;
	int secondMin = 100;

	for (int i = 0; i < 7; ++i) {
		if (task[i] < min) {
			min = task[i];
			if (i == 0) { secondMin = min; }
		}
		if (task[i] < secondMin && task[i] != min) {
			secondMin = task[i];
		}
	}
	return secondMin;
}

void process(int task, int machine, int time) {
	std::cout << "Task: " << task << " Machine: " << machine << " Duration: " << time << " milliseconds \n";
}