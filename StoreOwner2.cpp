#include <bits/stdc++.h> // In this problem, the rent is already decided by the customer
using namespace std;

class Box
{

public:
    int length, breadth, days, rent;

    Box(int length, int breadth, int days, int rent)
    {
        this->length = length;
        this->breadth = breadth;
        this->days = days;
        this->rent = rent;
    }

    void displayBox()
    {
        cout << this->length << " " << this->breadth << " " << this->days << " " << this->rent << endl;
    }
};

class BoxStorage
{

private:
    int storageLength, storageBreadth;
    int totalRentCollected;
    int thresholdRent = 0;
    vector<vector<int>> storage;

    int calculateThreshold(vector<Box> boxesData)
    {
        vector<int> arr;

        for (int i = 0; i < boxesData.size(); i++)
        {
            int val = boxesData[i].length * boxesData[i].breadth * boxesData[i].days;
            int rentPerUnit = boxesData[i].rent / (val);

            arr.push_back(rentPerUnit);
        }

        sort(arr.begin(), arr.end());
        int n = arr.size();

        int threshold = 0; // stores median value

        if (n % 2 == 0)
        {
            threshold = (arr[n / 2 - 1] + arr[n / 2]) / 2;
        }
        else
        {
            threshold = arr[n / 2];
        }

        return threshold;
    }

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
    BoxStorage(int length, int breadth, vector<Box> boxesData)
    {
        this->storageLength = length;
        this->storageBreadth = breadth;
        this->totalRentCollected = 0;

        storage.assign(length, vector<int>(breadth, 0));

        this->thresholdRent = calculateThreshold(boxesData);
        cout << thresholdRent << endl;
    }

    int rent() // returns the rent collected till now
    {
        return totalRentCollected;
    }

    bool isValidBox(Box B, int currentDay) // returns a boolean value, whether to say yes/no to current Box
    {
        int rentPerUnit = B.rent / (B.length * B.breadth * B.days);

        if (rentPerUnit < this->thresholdRent)
        {
            return false;
        }

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
            totalRentCollected += B.rent;

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

    vector<vector<int>> v1 = {{5, 7, 2, 1000}, {3, 5, 1, 1457}, {5, 6, 4, 1535}, {10, 4, 3, 1158}, {12, 23, 1, 2005}}; // boxes data with dimensions - length, breadth, no of days, rent
    vector<vector<int>> v2 = {{2, 5, 3, 2200}, {6, 7, 3, 2001}, {5, 5, 5, 5000}, {15, 4, 2, 1650}, {15, 22, 6, 1767}}; // box queries

    vector<Box> boxesData, boxQueries;

    for (int i = 0; i < v1.size(); i++)
    {
        boxesData.push_back(Box(v1[i][0], v1[i][1], v1[i][2], v1[i][3]));
    }

    for (int i = 0; i < v2.size(); i++)
    {
        boxQueries.push_back(Box(v2[i][0], v2[i][1], v2[i][2], v2[i][3]));
    }

    BoxStorage S = BoxStorage(n, m, boxesData);

    int currentDay = 1;

    for (int i = 0; i < boxQueries.size(); i++)
    {
        bool validBox = S.isValidBox(boxQueries[i], currentDay);

        cout << validBox << " " << S.rent() << endl;
        currentDay++;
    }

    return 0;
}