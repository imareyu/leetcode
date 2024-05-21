class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_set<string> suppliesSet(supplies.begin(), supplies.end());
        unordered_set<int> madeRecipes;//已经制作的菜品的下标
        int newMade = 1;
        int n = recipes.size();
        vector<string> ret;

        while(newMade > 0)
        {
            newMade = 0;

            for(int i = 0;i < n;i++)
            {
                if(madeRecipes.count(i) == 0)//没制作过
                {
                    bool canMake = true;
                    for(string& str:ingredients[i])
                    {
                        if(suppliesSet.count(str) == 0)
                        {//没有这种原材料，制作不了
                            canMake = false;
                            break;
                        }
                    }
                    if(canMake)
                    {
                        madeRecipes.insert(i);
                        suppliesSet.insert(recipes[i]);//制作出来，可以作为原材料
                        newMade++;
                        ret.emplace_back(recipes[i]);
                    }
                }
            }
        }
        return ret;
    }
};