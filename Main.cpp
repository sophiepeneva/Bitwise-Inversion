# Bitwise-Inversion

#include<iostream>

using namespace std;

int* decToBinary(int num, int& binaryNumLenght)
{
	int dublicate = num;

	//Here I will find how many digits there are in the binary number
	while (dublicate != 0)
	{
		dublicate = dublicate / 2;
		binaryNumLenght++;
	}

	int* binaryNum = new int[binaryNumLenght];
	//I create a counter so I can easily reach every position in the array
	int counter = binaryNumLenght - 1;
	while (num != 0)
	{
		if (num % 2 == 0)binaryNum[counter--] = 0;
		if (num % 2 == 1)binaryNum[counter--] = 1;
		num = num / 2;
	}
	return binaryNum;
}

void bitwiseInversion(int* binaryNum, int binaryNumLenght) 
{
	//bitwise inversion
	for (int i = 0;i < binaryNumLenght;i++)
	{
		if (binaryNum[i] == 0)binaryNum[i] = 1;
		else if (binaryNum[i] == 1)binaryNum[i] = 0;
	}
}

int binaryToDec(int* binaryNum, int binaryNumLenght)
{
	int newNum = 0;

	for (int i = 0;i < binaryNumLenght;i++)
	{
		newNum += binaryNum[i] * pow(2, binaryNumLenght - i - 1);
	}
	return newNum;
}

int main() 
{

	int num;
	do
	{
		cout << "Enter a positive integer" << endl;
		cin >> num;
	} while (num < 0);
	
	int binaryNumLenght = 0;
	int* binaryNum = decToBinary(num, binaryNumLenght);

	bitwiseInversion(binaryNum, binaryNumLenght);

	int newNum = binaryToDec(binaryNum, binaryNumLenght);

	cout<<"Your integer's complement is: " << newNum << endl;
	system("pause");
}
