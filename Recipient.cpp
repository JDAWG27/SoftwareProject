#include "Recipient.h"
#include <string>
#include <iostream>
#include <time.h>
using namespace std;

Recipient::Recipient()
{
	responses[0] = "Not bad, you?";
	responses[1] = "Terrible.";
	responses[2] = "Okay, I guess.";
	responses[3] = "Sure.";
	responses[4] = "Fine.";
	responses[5] = "Nope.";
	responses[6] = "No can do.";
	responses[7] = "Yo.";
	responses[8] = "Hey.";
	responses[9] = "Seeya.";
	responses[10] = "Bye.";
	responses[11] = "Goodbye.";		//preset responses
}

Recipient::~Recipient()
{}

int Recipient::Randomnum(int min, int max)const
{
	srand((unsigned int)time(NULL));
	return (rand() % (max-min+1)+min);		//generates a random number between min and max
}

void Recipient::GenResponse(stringinput euserinput) const
{
	switch(euserinput)
	{
		case ehi:
			cout << responses[Randomnum(7, 8)] << endl;
		break;

		case ehowareyou:
			cout << responses[Randomnum(3, 0)] << endl;
		break;

		case erequest:
			cout << responses[Randomnum(4, 3)] << endl;
		break;

		case ebye:
			cout << responses[Randomnum(3, 9)] << endl;
		break;
		case error:
			cout << "What?";		//generates a response based on the enum euserinput and 
		break;
	}
}

Recipient::stringinput Recipient::CheckInput(string userinput)const
{
	stringinput returnval;
	string userinputcpy = "       ";

	for(int i = 0; i != userinput.size();i++)
		userinput[i] = tolower(userinput[i]);

	if(userinput.size()>6)
		for(int i = 0; i != 7; i++)
			userinputcpy[i] = userinput[i];

	if(userinput == "hello" || (userinput == "hi" || (userinput == "hey")))
		return returnval = ehi;

	else if(userinput == "how are you" || (userinput == "sup" || (userinput == "whats up")))
		return returnval = ehowareyou;

	else if(userinputcpy == "can you" || userinputcpy == "could y")
		return returnval = erequest;

	else if(userinput == "bye" || (userinput == "seeya" || (userinput == "goodbye")))
		return returnval = ebye;
	else
		return returnval = error;		//generates the string to be outputted based on the string userinput
}

void Recipient::execute(string userinput) const
{
	GenResponse(CheckInput(userinput));		//master function
}