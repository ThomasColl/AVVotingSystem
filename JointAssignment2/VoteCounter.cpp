#include "VoteCounter.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <map>
#include <string>

using namespace std;

void VoteCounter::runElection()
{
	cout << "Ladies and Gentlemen may I welcome you to the first ever Carlow Presidential Election!" << endl;
	cout << "As we know due to a strange administrative anomaly the people of Carlow became a self governing territory";
	cout << " and now we are electing our first President of the Republic of Carlow!" << endl;
	cout << "Now we have an exciting night ahead of us as we being told the polls have finally closed and the counting shall begin.";
	cout << "With that considered lets meet the candidates!" << endl;
	cout << endl << endl;
	readIn();
	firstRound();
	while (checkWinner() == -1)
	{
		readResults();
		elimateLowest();
	}
	
	declareWinner(checkWinner());
}
void VoteCounter::firstRound()
{
	cout << "And the first round results are in:" << endl;
	for (unsigned int i = 0; i < this->CandidatesInElection.size(); i++)
	{
		tab[i] = this->CandidatesInElection[i].CandidateBallots.size();
	}
}
void VoteCounter::readResults()
{
	for (unsigned int i = 0; i < this->inVec.size(); i++)
	{
		cout << this->CandidatesInElection[i].CandidateName << " of " << this->CandidatesInElection[i].CandidateParty;
		cout << " currently has a score of: " << this->CandidatesInElection[i].CandidateBallots.size() << endl;
	}
}
int VoteCounter::checkWinner()
{
	vector<int> theVec{ begin(this->inVec), end(this->inVec) };

	if (this->inVec.size() == 2)
	{
		if (theVec[0] < theVec[1])
		{
			return theVec[0];
		}
		else
		{
			return theVec[1];
		}
	}
	else
	{
		cout << "No candidate has met the requirements for election this round." << endl;
		return -1;
	}

}

void VoteCounter::elimateLowest()
{
	int lowest = this->CandidatesInElection[0].CandidateBallots.size();
	int lowID = 0;
	for (unsigned int i = 0; i < this->tab.size(); i++)
	{
		if (this->CandidatesInElection[i].CandidateBallots.size() < lowest && this->CandidatesInElection[i].CandidateStatus == true)
		{
			lowID = this->CandidatesInElection[i].CandidateID;
			lowest = this->CandidatesInElection[i].CandidateBallots.size();
		}
	}
	runnoff(lowID);
}
void VoteCounter::runnoff(int id)
{
	cout << endl << endl;
	cout << this->CandidatesInElection[id].CandidateName;
	cout << " has scored the lowest and has been eliminated";
	cout << " only scoring " << this->CandidatesInElection[id].CandidateBallots.size() << "." << endl;;
	cout << endl << endl;
	this->CandidatesInElection[id].CandidateStatus = false;

	for (unsigned int i = 0; i < this->CandidatesInElection[id].CandidateBallots.size(); i++)
	{
		for (unsigned int j = 0; j < this->CandidatesInElection[id].CandidateBallots[i].preferences.size(); j++)
		{
			if (this->CandidatesInElection[id].CandidateBallots[i].preferences[j] == id && j + 1 < CandidatesInElection[id].CandidateBallots[i].preferences.size())
			{
				this->CandidatesInElection[this->CandidatesInElection[id].CandidateBallots[i].preferences[j + 1]].addBallot(this->CandidatesInElection[id].CandidateBallots[i]);
				this->outVec.push_back(id);
				this->inVec.remove(id);
			}
		}
	}
}
void VoteCounter::declareWinner(int winner)
{
	cout << "The results are in and we can confirm that there is only two candidates left." << endl;
	cout << "Results are in and CNN can proudly tell you that the first president of the Republoc of Carlow is..... *drum roll*" << endl;
	cout << this->CandidatesInElection[winner].CandidateName << " of " << this->CandidatesInElection[winner].CandidateParty << "!" << endl;
	cout << "They have managed to fight off the fierce competition and secured a net total of ";
	cout << this->CandidatesInElection[winner].CandidateBallots.size() << " votes." << endl;
	cout << "Congratulations Mr/Madam President and thats all from us, goodnight." << endl;
}
void VoteCounter::readIn()
{
	ifstream myfile("election.txt");

	string line;
	vector<BallotPaper> emptyBal;
	int id = 0;
	while (getline(myfile, line) && line != "#")
	{
		size_t pos = line.find("|");

		cout << "Representing " << line.substr(pos + 1, line.length()) << " we have " << line.substr(0, pos) << "!" << endl;
		this->CandidatesInElection.push_back(Candidate::Candidate(line.substr(0, pos), line.substr(pos + 1, line.length()), id, emptyBal));
		this->inVec.push_back(id);
		id++;
	}
	cout << "This means that there is a total of " << this->CandidatesInElection.size() << " candidates" << endl;
	cout << endl << endl;
	int balcount = 0;
	while (getline(myfile, line))
	{
		vector<int> pref;
		for (unsigned int i = 0; i < line.length(); i++)
		{
			pref.push_back(line.at(i) - '0' - 1);
		}
		this->CandidatesInElection[pref[0]].CandidateBallots.push_back(BallotPaper::BallotPaper(pref));
		balcount++;
	}
	cout << "The final tallying has been done and Carlow News Network can confirm that there has been " << balcount;
	cout << " total valid ballots cast this year!" << endl;
	cout << endl << endl;
	myfile.close();
}
