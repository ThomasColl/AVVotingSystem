#include <vector>

using namespace std;

class BallotPaper
{
    public:
		vector<int> preferences;

		BallotPaper(vector<int> pre);
        void setPreference(int p, int c);
        int getPreference(int n);
};
