#include "BallotPaper.h"
#include <string>
#include <vector>

using namespace std;

class Candidate
{
    public:
        string CandidateName;
        string CandidateParty;
		int CandidateID;
		bool CandidateStatus;
		vector<BallotPaper> CandidateBallots;

        Candidate(string name, string party, int id, vector<BallotPaper> bals);
        void setName(string name);
        void setParty(string party);
		void addBallot(BallotPaper bal);
        string getName();
        string getParty();
};
