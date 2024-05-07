class TopVotedCandidate {
private:
    vector<int> owner;
    vector<int> times;
public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        this->times = times;
        int maxCo = 0;
        map<int, int> personsVote;
        for(int i = 0;i < persons.size();i++)
        {
            int per = persons[i];
            personsVote[per]++;
            if(maxCo <= personsVote[per])
            {
                owner.push_back(per);
                maxCo = personsVote[per];
            }
            else
            {
                owner.push_back(owner.back());
            }
        }
    }
    
    int q(int t) {
        int index = upper_bound(times.begin(), times.end(), t) - times.begin()-1;
        return owner[index];
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */
//https://leetcode.cn/problems/online-election/description/