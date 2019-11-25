#include "Flip.h"
#include <cstring>
#include <sstream>

Flip::Flip()
{
	command = new char[strlen("Flip 20")+1];
	strcpy(command, "Flip 20");
}

Flip::Flip(int _value)
{
	std::stringstream sstream;

	switch(_value){
		case 0:
			sstream << "Flip l";
			break;
		case 1:
			sstream << "Flip r";
			break;
		case 2:
			sstream << "Flip f";
			break;
		case 3:
		default:
			sstream << "Flip b";
			break;
	}
	sstream << "Flip " << _value;

	command = new char[strlen(sstream.str().c_str())+1];
	strcpy(command, sstream.str().c_str());
}

double Flip::get_delay()
{ 
	return 2; 
}