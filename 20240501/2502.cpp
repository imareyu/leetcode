class Allocator {
private:
    vector<int> data;
    int dataSize = 0;
    int unused = 0;
public:
    Allocator(int n) {
        data.resize(n);
        for(auto& it:data)
            it = 0;
        dataSize = n;
        unused = n;
    }
    
    int allocate(int size, int mID) {
        if(size > dataSize || size > unused)
            return -1;
        int start = 0;
        while(start < dataSize)
        {
            if(data[start] != 0)
            {
                start++;
                continue;
            }
            int right = start + size-1;
            if(right >= dataSize)
                return -1;
            while(right > start)
            {
                if(data[right] != 0)
                {
                    break;
                }
                right--;
            }
            if(data[right] != 0)
            {
                start = right+1;
            }
            else
            {
                right = start + size-1;
                while(right >= start)
                {
                    data[right] = mID;
                    right--;
                }
                unused -= size;
                return start;
            }
        }
        return -1;
    }
    
    int free(int mID) {
        int ret = 0;
        for(int i = 0;i < dataSize;i++)
        {
            if(data[i] == mID)
            {
                data[i] = 0;
                ret++;
            }
        }
        unused += ret;
        return ret;
    }
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->free(mID);
 */
//https://leetcode.cn/problems/design-memory-allocator/description/