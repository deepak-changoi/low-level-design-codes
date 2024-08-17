#include <bits/stdc++.h> // In this problem, we decide the rent ourselves, and not decided by customer
using namespace std;

class Box
{

public:
    int length, breadth, days;

    Box(int length, int breadth, int days)
    {
        this->length = length;
        this->breadth = breadth;
        this->days = days;
    }

    void displayBox()
    {
        cout << this->length << " " << this->breadth << " " << this->days << endl;
    }
};

class BoxStorage
{

private:
    int storageLength, storageBreadth;
    int totalRentCollected;
    vector<vector<int>> storage;

    bool isValidTopLeft(int topLeftX, int topLeftY, int length, int breadth, int currentDay)
    {
        for (int i = topLeftX; i < topLeftX + length; i++)
        {
            for (int j = topLeftY; i < topLeftY + breadth; j++)
            {
                if (storage[i][j] >= currentDay)
                {
                    return false;
                }
            }
        }

        return true;
    }

public:
    BoxStorage(int length, int breadth)
    {
        this->storageLength = length;
        this->storageBreadth = breadth;
        this->totalRentCollected = 0;

        storage.assign(length, vector<int>(breadth, 0));
    }

    int rent() // returns the rent collected till now
    {
        return totalRentCollected;
    }

    bool isValidBox(Box B, int currentDay) // returns a boolean value, whether to say yes/no to current Box
    {
        bool isValid = false;
        int topLeftX = -1;
        int topLeftY = -1;

        for (int i = 0; i + B.length <= this->storageLength; i++)
        {
            for (int j = 0; j + B.breadth <= this->storageBreadth; j++)
            {
                if (isValidTopLeft(i, j, B.length, B.breadth, currentDay))
                {
                    isValid = true;
                    topLeftX = i;
                    topLeftY = j;
                    break;
                }
            }

            if (isValid == true)
            {
                break;
            }
        }

        if (isValid)
        {
            int rent = B.length * B.breadth * B.days;
            totalRentCollected += rent;

            for (int i = topLeftX; i < topLeftX + B.length; i++)
            {
                for (int j = topLeftY; i < topLeftY + B.breadth; j++)
                {
                    storage[i][j] = currentDay + B.days - 1;
                }
            }

            return true;
        }

        return false;
    }
};

int main()
{
    int n, m; // dimensions of storage
    n = 50;
    m = 30;

    BoxStorage S = BoxStorage(n, m);

    int currentDay = 1;

    vector<vector<int>> v = {{5, 7, 2}, {3, 5, 1}, {5, 6, 4}, {10, 4, 3}, {12, 23, 1}}; // boxes with dimensions - length , breadth ,no of days
    vector<Box> boxes;

    for (int i = 0; i < v.size(); i++)
    {
        boxes.push_back(Box(v[i][0], v[i][1], v[i][2]));
    }

    for (int i = 0; i < boxes.size(); i++)
    {
        bool validBox = S.isValidBox(boxes[i], currentDay);

        cout << validBox << " " << S.rent() << endl;
        currentDay++;
    }

    return 0;
}