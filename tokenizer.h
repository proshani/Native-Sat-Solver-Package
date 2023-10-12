#ifndef TOKENIZER_H
#define TOKENIZER_H
#include <map>
#include <string>
using namespace std;
struct Token
{
	std::string content;
	std::string type;
};

// a tokenzier breaks a stream of string into tokens
class Tokenizer
{
	// your code starts here


public:
	std::string tempt;
	int LenAssignment = 0;
	std::map<std::string, std::string> results;
	Tokenizer(std::string ln);
	Token resultToken;
	bool advanceToken(); // advance to the next token; return false if no more token exist
	bool advanceFormula();
	bool mapToken(Token T);
	bool CheckContradictingValue(Token T);
	bool hasToken() const; // check whether there is a current token
	Token getToken(); // returns the token being processed

};

#endif
