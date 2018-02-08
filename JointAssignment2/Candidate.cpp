
#include "Candidate.h"
#include <string>

using namespace std;

Candidate::Candidate(string name, string party, int id, vector<BallotPaper> bals)
{
	this->CandidateID = id;
	this->CandidateName = name;
	this->CandidateParty = party;
	this->CandidateBallots = bals;
	this->CandidateStatus = true;
}
void Candidate::setName(string name)
{
    this->CandidateName = name;
}
void Candidate::setParty(string party)
{
    this->CandidateParty = party;
}
void Candidate::addBallot(BallotPaper bal)
{
	this->CandidateBallots.push_back(bal);
}
string Candidate::getName()
{
    return this->CandidateName;
}
string Candidate::getParty()
{
    return this->CandidateParty;
}
