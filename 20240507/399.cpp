class Solution {
private:
    double calc(set<string> s,string str2,string str1, map<string,vector<string>>& nextval,map<pair<string, string>,double>& resutl)
    {
        
        if(str1 == str2)
            return 1.0;
        set<string> calced;
        deque<pair<string,double>> used;
        used.push_back(make_pair(str1, 1.0));
        calced.insert(str1);
        int index = 0;
        while(!used.empty())
        {
            auto [str,val] = used.front();
            used.pop_front();
            for(string nstr : nextval[str])
            {
                if(calced.count(nstr) > 0)
                    continue;
                double re = resutl[make_pair(nstr,str)];
                double nval = re * val;
                used.push_back(make_pair(nstr, nval));
                calced.insert(nstr);
                if(nstr == str2)
                    return nval;
            }
        }
        return 0;
    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<set<string>> bc;
        map<string,vector<string>> nextval;
        map<pair<string, string>,double> resutl;
        int n = equations.size();

        for(int i = 0;i < n;i++)
        {
            string& str1 = equations[i][0];
            string& str2 = equations[i][1];
            nextval[str1].emplace_back(str2);
            nextval[str2].emplace_back(str1);
            resutl[make_pair(str1,str2)] = values[i];
            resutl[make_pair(str2,str1)] = 1/values[i];
            vector<int> addj;

            for(int j = 0;j < bc.size();j++)
            {
                if(bc[j].count(str1) > 0 || bc[j].count(str2) > 0)
                {
                    addj.push_back(j);
                }
            }
            set<string> tset;
            tset.insert(str1);
            tset.insert(str2);
            if(addj.size() == 0)
            {
                bc.emplace_back(tset);
            }
            else
            {
                if(addj.size() == 1)
                {
                    int j = addj[0];
                    bc[j].insert(tset.begin(), tset.end());
                }
                else
                {
                    if(addj.size() == 2)
                    {
                        int j1 = addj[0];
                        int j2 = addj[1];
                        bc[j1].insert(tset.begin(), tset.end());
                        bc[j1].insert(bc[j2].begin(), bc[j2].end());
                        bc.erase(bc.begin()+j2);
                    }
                }
            }
        }
        vector<double> ret;
        for(int i = 0;i < queries.size();i++)
        {
            string str1 = queries[i][0];
            string str2 = queries[i][1];
            int index = -1;
            for(int i = 0;i < bc.size();i++)
            {
                if(bc[i].count(str1) > 0 && bc[i].count(str2) > 0)
                {
                    index = i;
                    break;
                }
            }
            if(index >= 0)
            {
                double re = calc(bc[index],str1, str2,nextval, resutl);
                ret.emplace_back(re);
            }
            else
            {
                ret.emplace_back(-1.0);
            }
        }
        return ret;
    }
};
//https://leetcode.cn/problems/evaluate-division/