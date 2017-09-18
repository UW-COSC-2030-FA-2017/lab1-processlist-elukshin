//Emily Lukshin
//Lab 1

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <string>
using std::string;

#include <fstream>
using std::ifstream;


//function to retrieve file names
string promptUser()
{
	string name;
	cout << "Enter the name of a file: ";
	cin >> name;
	return name;
}

int main()
{
    //variables to store information
	double count = 0;
	double first;
	double sec;
	double last = 0;
	double last2;
	ifstream file;

    //open the file name returned from the promptUser function
	file.open(promptUser());

    //if opening the file failed, error message is printed, file is closed and program exits
	if (file.fail() == true) {
		cout << "An error occured while opening the file." << endl;
		file.close();
		return 0;
	}
	else {
        // if there were no problems opening the file:
        // while not at the of the file, the count of the numbers in the file is tested
        // and every time the loop is ran, count is increased by one
			while (!file.eof())
			{
                // if the count is zero, then no numbers have been read in yet.
                //the first number is therefore read in and since it is the only number
                //it is the first, second, second last and last number in the file
				if (count == 0) {
					file >> first;
					sec = first;
					last2 = first;
					last = first;
				}
                // if the count is one, only one number is read in and the second number
                //in the file is next to be read in. since only two numbers have been read
                //in the first number is the first, but the second is the second,
                //second to last and last number
				if (count == 1) {
					file >> sec;
                    last2 = sec;
                    last = sec;
                    
					}
                // if the count is greater than 1, the number that last was holding is moved
                //to second last, because that number is no longer the last, the new number
                //to read is the last number. the cycle continues until there are no more numbers,
                //and last is set as the last number while second last is set as the number last
                //was previously set at
				if (count > 1) {
					last2 = last;
					file >> last;
				}
				count++;
			}
		}
    //file is closed, it is no longer needed
	file.close();

    //values of the numbers from the first file are printed
	cout << "There are " << count << " numbers in File 1" << endl;
	cout << "The first two numbers of File 1 are: " << first << " and " << sec << endl;
	cout << "The last two numbers of File 1 are: " << last2 << " and " << last << endl << endl;

	count = 0;
    //second file is opened and the previous cycle of finding the numbers is executed
	file.open(promptUser());

	if (file.fail() == true) {
		cout << "An error occured while opening the file." << endl;
		file.close();
		return 0;
	}
	else {
		while (!file.eof())
		{
			if (count == 0) {
				file >> first;
				sec = first;
				last2 = first;
				last = first;
			}
			if (count == 1) {
				file >> sec;
			}
			if (count > 1) {
				last2 = last;
				file >> last;;
			}
			count++;
		}
	}

	file.close();
    //values of the numbers from the second file are printed
	cout << "There are " << count << " numbers in File 2" << endl;
	cout << "The first two numbers of File 2 are " << first << " and " << sec << endl;
	cout << "The last two numbers of File 2 are " << last2 << " and " << last << endl << endl;

	return 0;
}

