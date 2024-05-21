class Robot {
private:
    int width = 0;
    int height = 0;
    int zc = 0;
    int x = 0;//现在的横坐标
    int y = 0;//现在的纵坐标
    int direction = 0;//0右，1上，2左边，3下
    vector<string> dires = {"East", "North","West","South"};
    bool first = true;
public:
    Robot(int width, int height) {
        this->width = width;
        this->height = height;
        x = 0;
        y = 0;
        direction = 0;
        zc = 4 + (width-2)*2 + (height-2)*2;
        first = true;
    }
    
    void step(int num) {
        if(first)//第一次调用
        {
            direction = 3;
            first = false;
        }
        num = num%zc;
        if(num == 0)
            return ;
        if(direction == 0)//往右
        {
            if(x+num < width)
            {
                x += num;
                num = 0;
            }
            else
            {
                num -= width - x-1;
                x = width-1;
                direction = (direction+1)%4;
                step(num);
            }
            return;
        }
        if(direction == 1)//往上
        {
            if(y+num < height)
            {
                y += num;
                num = 0;
            }
            else
            {
                num -= height - y-1;
                y = height-1;
                direction = (direction+1)%4;
                step(num);
            }
            return;
        }
        if(direction == 2)//往左
        {
            if(x-num >= 0)
            {
                x -= num;
                num = 0;
            }
            else
            {
                num -= x;
                x = 0;
                direction = (direction+1)%4;
                step(num);
            }
            return;
        }
        if(direction == 3)//往下
        {
            if(y-num >= 0)
            {
                y -= num;
                num = 0;
            }
            else
            {
                num -= y;
                y = 0;
                direction = (direction+1)%4;
                step(num);
            }
            return;
        }
    }
    
    vector<int> getPos() {
        return {x, y};
    }
    
    string getDir() {
        return dires[direction];
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */
//https://leetcode.cn/problems/walking-robot-simulation-ii/