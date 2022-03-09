#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
#include <limits>
#include<cmath>
#include<type_traits>
#include <concepts>

using namespace std;

template<typename T>
class Draw {
private:
    vector<vector<T> > map;
 
    
    void draw(int x, int y) requires is_same_v<T, char> {
        map[19 - y][x] = '1';
    }

    void draw(int x, int y) requires is_same_v<T, bool> {
        map[19 - y][x] = false;
    }

public:

    template<typename T1 = T> requires is_same_v<T, char>
    Draw() :map(20, vector<char>(20, '0')) {};

    template<typename T1 = T> requires is_same_v<T, bool>
    Draw() :map(20, vector<bool>(20, false)) {};

    void printResult() {
        for (auto row : map)
        {
            for (auto column : row)
            {
                cout << column << ' ';
            }
            cout << endl;
        }
        cout << endl << endl;
    }

    void line(int x0, int y0, int x1, int y1) {
        int flag = 0;
        if (y1 - y0 > x1 - x0 || y1 - y0 < x0 - x1)
        {
            swap(x0, y0);
            swap(x1, y1);
            flag = 1;
        }
        if (x0 > x1)
        {
            swap(x0, x1);
            swap(y0, y1);
        }
        double t = (double)(y1 - y0) / (x1 - x0);
        for (int x = x0; x <= x1; ++x)
        {
            int y = round(y0 + t * (x - x0));
            if (flag)draw(y, x);
            else draw(x, y);
        }
    }
};

int main() {
    Draw<bool> draw;

}
