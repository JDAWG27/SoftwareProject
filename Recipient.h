#pragma once
#include <string>
class Recipient
{
private:
	std::string responses[12];
	enum stringinput
	{
		ehi,
		ehowareyou,
		erequest,
		ebye,
		error
	};
public:

	Recipient();
	~Recipient();
	int Randomnum(int, int)const;
	void GenResponse(stringinput)const;
	stringinput CheckInput(std::string)const;
	void execute(std::string)const;
};