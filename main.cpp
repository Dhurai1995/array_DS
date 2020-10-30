#include<iostream>
#include<vector>
#include<string>
#include <algorithm>    // std::min_element, std::max_element

using namespace std;

int hourglassSum(std::vector<std::vector<int>>);

int main()
{
	int iIndex = 6, jIndex = 6;
	int finalVal = 0;
	std::vector<std::vector<int>> arr;

	for (int i = 0; i < iIndex; i++)
	{
		std::vector<int> temp;
		for (int j = 0; j < jIndex; j++)
		{
			std::cin >> finalVal;
			temp.push_back(finalVal);
		}
		arr.push_back(temp);
	}


	finalVal = hourglassSum(arr);
}

int hourglassSum(std::vector<std::vector<int>> arr)
{
	std::vector<int> totalVal;
	int topVal = 0, midVal = 0, lowVal = 0;

	for (int i = 0; i < (arr.size()-2); i++)
	{
		for (int j = 0; j < (arr.size() - 2); j++)
		{
			topVal = arr[i][j] + arr[i][j+1] + arr[i][j+2];
			midVal = arr[i+1][j+1];
			lowVal = arr[i+2][j] + arr[i+2][j+1] + arr[i+2][j+2];
			totalVal.push_back(topVal + midVal + lowVal);
		}
	}

	for (int i = 0; i < totalVal.size(); i++)
	{
		std::cout << "\n" << "Total values =" << totalVal[i];
	}

	std::vector<int>::iterator maxElement;
	maxElement = std::max_element(totalVal.begin(), totalVal.end());
	int maxVal = 0;
	maxVal = std::distance(totalVal.begin(), maxElement-1);
	//std::cout << "max values is: " << totalVal[maxVal+1] << '\n';

	return totalVal[maxVal+1];
}

