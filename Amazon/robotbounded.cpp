#include <bits/stdc++.h>
using namespace std;

bool isRobotBounded(string instructions)
{
    //0 90 180 270
    int x = 0, y = 0;
    int dir = 90;

    for (int i = 0; i < instructions.length(); i++)
    {
        if (instructions[i] == 'G')
        {
            if (int(dir / 90) == 1)
                y += 1;
            else if (int(dir / 90) == 0)
                x += 1;
            else if (int(dir / 90) == 2)
                x -= 1;
            else
                y -= 1;
        }
        else if (instructions[i] == 'L')
        {
            if (dir == 270)
                dir = 0;
            else
                dir += 90;
        }
        else
        {
            if (dir == 0)
                dir = 270;
            else
                dir -= 90;
        }
    }
    if ((x == 0 && y == 0) || dir != 90)
        return true;
    return false;
}

int main()
{
    string input = "GGLLGG";
    cin>>input;
    cout << isRobotBounded(input);
}