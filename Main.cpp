#include <iostream>
#include <vector>
#include <string>

#include "dataHub.h"
#include "Recipient.h"
using namespace std;

//TEST Print
void print(vector<string> v)
{
	vector<string>::iterator it;
	for (it = v.begin(); it < v.end(); it++)
	{
		cout << *it << endl;
	}
	
}

void ExecuteCmd(string cmd)
{

}
void main()
{
	Recipient recipient;
	string input;
	cout << "Please enter one of the preset responses;"
			<< endl << "hello, hi, hey," << endl
				<< "how are you, sup, whats up," << endl
					<< "any line that starts with \"can you\" or \"could y\"," << endl
						<< "bye, seeya, goodbye." << endl << endl;
	getline(cin, input);
	recipient.execute(input);
}