// JointAssignment2.cpp : Defines the entry point for the console application.
//

#include "VoteCounter.h"
#include <iostream>
#include <list>

using namespace std;

int main()
{
	VoteCounter voter;

	voter.runElection();
	system("pause");
    return 0;
}

