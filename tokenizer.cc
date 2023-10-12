#include "tokenizer.h"
#include <iostream>
#include <map>
using namespace std;

Tokenizer::Tokenizer(std::string ln) {

	//printf("Go to class Tokenizer.\n");
	tempt = ln;
	LenAssignment = tempt.length();
	//cout << LenAssignment;
	// complete the constructor
}
bool Tokenizer::CheckContradictingValue(Token T) {

	map<std::string, std::string>::iterator itr;
	bool find = false;
	for (itr = results.begin(); itr != results.end(); itr++)
	{

		if (itr->first == T.content)
		{
			if (itr->second != T.type)
			{
				return false;
			}
		}
	}
	return true;
}
bool Tokenizer::advanceToken()
{
	//printf("Go to class advanceToken.\n");
	// your code starts here
	std::string FirstPart;
	std::string SecondPart;
	bool HasTVDevider;
	int i = 0;
	while (i < LenAssignment + 1)
	{

		if (tempt[i] != ':' && tempt[i] != ',' && tempt[i] != ' ')
		{

			std::string s(1, tempt[i]);
			FirstPart = FirstPart + s;
			i++;
			if (i == LenAssignment)
			{

				results["Error"] = ": Invalid Input";
			}
		}
		else
		{
			if (tempt[i] == ':')
			{
				HasTVDevider = true;
				i++;
				std::string s(1, tempt[i]);
				SecondPart = SecondPart + s;
				i++;
				resultToken.content = FirstPart;
				resultToken.type = SecondPart;
				if (SecondPart != "1" && SecondPart != "0")
				{

					results["Error"] = ": Invalid Input";
				}

				if (i != LenAssignment)
				{

					if (tempt[i] != ',')
						results["Error"] = ": Invalid Input";
				}
				//cout << FirstPart << FirstPart.length() << "\n";
				mapToken(resultToken);
				FirstPart = "";
				SecondPart = "";
			}
			else if (tempt[i] == ',')
			{

				if (!HasTVDevider)
				{
					//	cout << "No :";
					resultToken.content = "Error";
					resultToken.type = " :Invalid Inpute";
					mapToken(resultToken);
				}
				HasTVDevider = false;
				i++;

			}
			else
			{
				i++;
			}

		}

	}




	//results.insert(FirstPart, SecondPart);

	/*if (results.find("Error"))
		return false;*/
	return true;
}

bool Tokenizer::advanceFormula()
{
	//printf("Go to class advanceformula.\n");
	// your code starts here
	std::string conternt;
	std::string type;
	std::string newFormul;
	cout << tempt << "\n";
	int i = 0;
	while (i < LenAssignment + 1)
	{
		if (tempt[i] != '+' && tempt[i] != '*' && tempt[i] != ' ' &&
			tempt[i] != '-' && tempt[i] != '(' && tempt[i] != ')'
			&& tempt[i] != '0' && tempt[i] != '1')
		{
			std::string s(1, tempt[i]);
			conternt = conternt + s;
			if (type == "")
				type = "nonterminal";
			i++;
		}
		else if (tempt[i] == ' ')
			i++;
		else
		{
			if (conternt != "" && type != "")
			{

				cout << conternt << "\n";
				cout << type << "\n";
				resultToken.content = conternt;
				resultToken.type = type;
				mapToken(resultToken);

				conternt = "";
				type = "";
			}
			std::string s(1, tempt[i]);
			conternt = s;
			type = "terminal";
			i++;
			cout << conternt << "\n";
			cout << type << "\n";
			resultToken.content = conternt;
			resultToken.type = type;
			mapToken(resultToken);
			conternt = "";
			type = "";
			cout << newFormul << "\n";
		}
	}
	return true;
}
bool Tokenizer::hasToken() const {
	return true;
}

bool CheckBooleanVariableTemplate(std::string Line)
{
	int i = 0;
	bool Ok;
	char c = Line[0];
	if (c >= '0' && c <= '9')
	{	
		return false;
	}
	else {
		for (i = 0; i < Line.length() ; i++)
		{
			
			if (!((Line[i] >= '0' && Line[i] <= '9') || (Line[i] >= 'a' && Line[i] <= 'z' || Line[i] >= 'A' && Line[i] <= 'Z') || Line[i]==' '))
			{
				return false;
			}
		}
	}
	return true;
}
bool Tokenizer::mapToken(Token T) {
	map<std::string, std::string>::iterator itr;
	if (T.content.length() > 10)
		results["Error"] = ": Invalid Input";
	else if (!CheckBooleanVariableTemplate(T.content))
	{
		results["Error"] = ": Invalid Input";
	}
	else if (!CheckContradictingValue(T))
	{
		results["Error"] = ": contradicting assignment";
	}
	results[T.content] = T.type;
	return true;
}

// only can be called when hasToken() is true
Token Tokenizer::getToken() {

	Token resultToken;
	// your code starts there
	return resultToken;
}
