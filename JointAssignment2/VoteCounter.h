#include "Candidate.h"
#include <vector>
#include <map>
#include <list>
#include <string>

using namespace std;

class VoteCounter
{
    public:
		vector<Candidate> CandidatesInElection;
		list<int> inVec;
		vector<int> outVec;
		map<int, unsigned int> tab;
		int winner;

		void readIn();
		//void readInBallots();
        void runElection();
        void firstRound();
		void readResults();
		int checkWinner();
		void elimateLowest();
		void runnoff(int id);
        void declareWinner(int winner);
};
