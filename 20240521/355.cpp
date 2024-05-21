class Twitter {
private:
    int time = 0;
    map<int, vector<pair<int, int>>> userTwitters;//用户发送的一系列twi的id
    map<int, unordered_set<int>> userFollowers;//用户关注的人的id
public:
    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        userTwitters[userId].emplace_back(time, tweetId);
        time++;
    }
    
    vector<int> getNewsFeed(int userId) {//twi time越大，则时间越近
        vector<pair<int, int>> ret;//维护一个最大为10的最大数组
        if(userTwitters.count(userId) > 0)
        {
            if(userTwitters[userId].size() <= 10)
            {
                ret.insert(ret.end(), userTwitters[userId].begin(), userTwitters[userId].end());
            }
            else
            {
                ret.insert(ret.end(), userTwitters[userId].end()-10, userTwitters[userId].end());
            }
            sort(ret.begin(), ret.end(), [](const pair<int,int>& a,const pair<int,int>& b){
                return a.first > b.first;
            });
        }

        for(int user: userFollowers[userId])//遍历关注的人发的twi
        {
            if(userTwitters.count(user) > 0)
            {
                if(userTwitters[user].size() <= 10)
                {
                    ret.insert(ret.end(), userTwitters[user].begin(), userTwitters[user].end());
                }
                else
                {
                    ret.insert(ret.end(), userTwitters[user].end()-10, userTwitters[user].end());
                }
                sort(ret.begin(), ret.end(), [](const pair<int,int>& a,const pair<int,int>& b){
                    return a.first > b.first;
                });
                if(ret.size() > 10)
                {
                    ret = vector<pair<int,int>>(ret.begin(), ret.begin()+10);
                }
            }
        }
        vector<int> realRet;
        for(auto [t, v]:ret)
        {
            realRet.emplace_back(v);
        }
        return realRet;
    }
    
    void follow(int followerId, int followeeId) {
        userFollowers[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        userFollowers[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
//https://leetcode.cn/problems/design-twitter/description/