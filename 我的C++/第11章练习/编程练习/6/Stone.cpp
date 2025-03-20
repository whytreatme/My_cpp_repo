#include<iostream>
#include"Stonewt.h"

int main()
 {
	using namespace std;
	Stonewt arr[6] = { (257.65),Stonewt(10,12.43),Stonewt(15,3.88)};
	Stonewt as(11, 0.0);
	Stonewt Max, Min;
	double weight = 0.0;
	Max = Min = arr[0];
	
	for (int i = 3; i < 6; i++)
	{
		cout << "Input the element:";
		if (!(cin >> weight))
		{
			cout << "Error!" << endl;
			break;
		}
		else
			arr[i] = weight;
	}

	int num = 0;
	for (int i = 0; i < 6; i++)
	{
		if (arr[i] > Max)
			Max = arr[i];
		if (arr[i] < Min)
			Min = arr[i];
		if (arr[i] >= as)
			num++;
	}

	Max.float_pounds_mode();
	cout << "The Max element: " << Max << endl;
	Min.float_pounds_mode();
	cout << "The Min element: " << Min << endl;
	cout << "There are " << num << " element bigger than or equal to 11 stone" << endl;

	return 0;
}