//Program that makes a bar chart out of inputted sales values and saves it to a file
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	string fileName = "BarChart.txt";						//file that will be outputted to
	string output = "SALES BAR CHART\n(Each * = $100)";		//the string that holds the bar chart

	//I wanted to use an array to store the values of each location, but we haven't gotten there yet
	//thus I'm evaluating and saving the values to an output string as we go.
	for (int storeNum = 1; storeNum <= 5; storeNum++)
	{
		double storeVal;		//temporary variable that holds the sales value inputted by user

		//Ask user for sales
		cout << "Enter today's sales for store " << storeNum << ": ";
		cin >> storeVal;

		//Verify the input is greater than zero
		while (storeVal < 0)
		{
			cout << "Error: Please provide a number greater than zero.";
			cout << "\nEnter today's sales for store " << storeNum << ": ";
			cin >> storeVal;
		}

		//Formatting a string to contain the bar chart
		output += "\nStore ";
		//the only method acknowledged by the book so far to convert from int to char
		//48 is where the first number appears on the ascii chart
		output += static_cast<char>(storeNum + 48);
		output += ": ";

		//Adds one asterisk per $100 of sales
		for (int asteriskNum = floor(storeVal / 100); asteriskNum > 0; asteriskNum--)
			output += '*';
	}

	//Print the bar chart
	cout << "\n" << output;

	//Open a new file to save the bar chart to
	ofstream outputFile;
	outputFile.open(fileName);
	outputFile << output;
	outputFile.close();

	cout << "\n\nSaved to " << fileName
		<< "\nProgram by Spencer Curtis";
	return 0;
}