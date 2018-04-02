#ifndef TRIPLET_SUM_H
#define TRIPLET_SUM_H

#include <vector>
#include <algorithm>

using namespace std;

class TripletSum
{
public:
    TripletSum()
    {
    	targetSum     = 0;
    	firstElement  = 0;
    	secondElement = 0;
    	thirdElement  = 0;
    }

    TripletSum(vector<int>& data, int targetSUm)
    {
    	this -> data      = data;
    	this -> targetSum = targetSum;

    	targetSum         = 0;
    	firstElement      = 0;
    	secondElement     = 0;
    	thirdElement      = 0;
    }

    bool checkTargetSum();

    bool checkTargetSum(vector<int>& data, int targetSum)
    {
    	this -> data      = data;
    	this -> targetSum = targetSum;

    	return checkTargetSum();
    }

    void setData(vector<int>& data)
    {
    	this -> data = data;
    }

    void setTargetSum(int targetsum)
    {
    	this -> targetSum = targetsum;
    }

    vector<int> getElements()
    {
    	vector<int> result = {firstElement, secondElement, thirdElement}; 
    	return result;
    }

private:
	vector<int> data;
	int targetSum;
	int firstElement, secondElement, thirdElement;
};
#endif
