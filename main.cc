#include <iostream>
#include <string>
#include <map>
#include "parser.h"
#include "treeNode.h"
#include <vector>
using namespace std;


std::string CreateFormula(std::string formulaStr, map<std::string, std::string> assignmentmap)
{
	int i = 0;
	formulaStr.erase(std::remove_if(formulaStr.begin(), formulaStr.end(),
		[](char c) {  // a lambda function
			return (c == ' ' || c == '\n' || c == '\r' ||
				c == '\t' || c == '\v' || c == '\f');
		}),
		formulaStr.end());
	cout << "String s after removing whitespaces: " << formulaStr;

	std::string content = "";
	std::string tempt = formulaStr;
	cout << formulaStr.length() << "\n";
	std::map<std::string, std::string>::iterator it;
	for (it = assignmentmap.begin(); it != assignmentmap.end(); it++)
	{
		content = it->first;
		formulaStr.replace(formulaStr.find(it->first), it->first.length(), it->second);
		cout << formulaStr << "\n";
	}
	//while (i < formulaStr.length())
	//{
	//	cout << i << "\n";
	//	cout << tempt[i] << "\n";

	//	if (tempt[i] != '+' && tempt[i] != '*' && tempt[i] != ' ' &&
	//		tempt[i] != '-' && tempt[i] != '(' && tempt[i] != ')' && tempt[i] != '  ')
	//	{
	//		std::string s(1, tempt[i]);
	//		content = content + s;

	//	}

	//	else
	//	{
	//		if (content != "")
	//		{
	//			std::map<std::string, std::string>::iterator it;
	//			//std::string seconpart; 

	//			/*for (it = assignmentmap.begin(); it != assignmentmap.end(); it++)
	//			{


	//				if (it->first == content)
	//				{
	//					seconpart = it->second;
	//				}

	//			}*/
	//			//it = assignmentmap.find(content);
	//			if (assignmentmap.find(content) != assignmentmap.end()) {
	//				it = assignmentmap.find(content);
	//				cout << i - content.length() << "\n";
	//				cout << content << "\n";
	//				cout << it->second << "\n";
	//				//formulaStr.replace(i - content.length(), content.length(), it->second);
	//				//size_t found = formulaStr.find(content);
	//				formulaStr.replace(formulaStr.find(content), content.length(), it->second);
	//				cout << formulaStr << "7" << i <<"\n";
	//			}
	//			else 
	//				cout << " : Not found" ;

	//			content = "";
	//		}

	//	}
	//	i++;
	//	cout << i;

	//}
	//cout << "exit while";
	//if (content != "")
	//{
	//	std::map<std::string, std::string>::iterator it;
	//	if (assignmentmap.find(content) != assignmentmap.end()) {
	//		it = assignmentmap.find(content);
	//		cout << i - content.length() << "\n";
	//		cout << content << "\n";
	//		cout << it->second << "\n";
	//		
	//		formulaStr.replace(formulaStr.find(content), content.length(), it->second);
	//		cout << formulaStr << "\n";
	//	}
	//	else cout << " : Not found" << endl;

	//	content = "";
	//}



	//treenode.getContent();


	return formulaStr;
}
// a helper function parsing the input into the formula string and the assignment string
std::string parseLine(const std::string& line, std::string& formulaStr, std::string& assignmentStr) {
	//printf("Go to function Assignment Parser.\n");
	std::map<std::string, std::string> mapassignmentresults;

	AssignmentParser parser(assignmentStr);
	mapassignmentresults = parser.parseAssignment();
	bool HasError = false;
	std::string ErrorMessage = "";
	map<std::string, std::string>::iterator itr;
	//cout << "\nThe map assignmet is : \n";
	//cout << "\tKEY\tELEMENT\n";
	for (itr = mapassignmentresults.begin(); itr != mapassignmentresults.end(); ++itr) {
		/*cout << '\t' << itr->first << '\t' << itr->second
			<< '\n';
		cout << itr->first;*/
		if (itr->first == "Error")
		{

			HasError = true;
			ErrorMessage = itr->first + itr->second;

		}
	}
	if (!HasError) {
		std::string finalFormula = CreateFormula(formulaStr, mapassignmentresults);
		//cout << finalFormula;
		VariableNode v(finalFormula);
		int result = v.getContent();
		cout << result;
	}
	if (HasError)
		cout << ErrorMessage;
	return "";
}



int main() {
	//while (true) // continuously asking for new inputs from standard input
	//{
	//  std::string line; // store each input line
	//  std::string formulaStr; // store the formula string
	//  std::string assignmentStr; // store the assignment string
	//  // your code starts here
	//}
	//printf("Hello, World! This is a native C program compiled on the commanddddd line.\n");
	while (true)
	{
		string infix;
		std::string line; // store each input line
		std::string formulaStr; // store the formula string
		std::string assignmentStr; // store the assignment string
		char s[100];
		cout << endl << "Please enter an Infix Mathematical Expression" << endl;
		cin.getline(s, 100);

		char* ps, * pt;
		ps = s;
		pt = s;
		line = s;
		if (line.find(';') != string::npos)
		{
			while ((*ps) != ';') {
				if (*ps == '\0')                                                                         /* No space found till end of line */
				{
					cout << "Error: Invalide Inpute" << "\n";
					//break;
					formulaStr = s;                                                                         /* exit from the program */
				}
				ps++;
			}
			*ps = '\0';
			++ps;

			formulaStr = pt;
			assignmentStr = ps;
			cout << formulaStr << "\n";
			cout << assignmentStr << "\n";

			assignmentStr.erase(std::remove_if(assignmentStr.begin(), assignmentStr.end(),
				[](char c) {  // a lambda function
					return (c == ' ' || c == '\n' || c == '\r' ||
						c == '\t' || c == '\v' || c == '\f');
				}),
				assignmentStr.end());

			std::string result = parseLine(line, formulaStr, assignmentStr);
			//return re//sult;
			cout << result;

		}
		else
			cout << "Error: Invalide Inpute" << "\n";

	}

}




