#include "BallotPaper.h"

using namespace std;

BallotPaper::BallotPaper(vector<int> pre)
{
	this->preferences = pre;
}
void BallotPaper::setPreference(int p, int c)
{
	this->preferences[c] = p;
}
int BallotPaper::getPreference(int n)
{
	return this->preferences[n];
}
