#include "parser.h"
#include "treeNode.h"
#include "tokenizer.h"
using namespace std;
#include <iostream>
FormulaParser::FormulaParser(std::string ln): tknzr {new Tokenizer{ln}} {}

std::map<std::string, std::string> FormulaParser::parseformula() {
	tknzr->advanceFormula();
	std::map<std::string, std::string> mapresults;
	mapresults = tknzr->results;
	//printf("Done Parse Formula \n");
	return mapresults;
}
TreeNode *FormulaParser::parseConjTerm() {
  // your code starts here
  return nullptr;
}

TreeNode *FormulaParser::parseTerm() {
  // your code starts here
  return nullptr;
}

TreeNode *FormulaParser::parseFormula() {
  // your code starts here
  return nullptr;
}

TreeNode * FormulaParser::getTreeRoot() {
  // your code starts here
  return nullptr;
}

FormulaParser::~FormulaParser() {
  // your code starts here
}

AssignmentParser::AssignmentParser(std::string ln): tknzr {new Tokenizer{ln}} {}

std::map<std::string, std::string> AssignmentParser::parseAssignment() {
  std::map<std::string, std::string> mapresults;
  // your code starts here
  tknzr->advanceToken();
  mapresults = tknzr->results;
 // printf("Done.\n");
  return mapresults;  
}


AssignmentParser::~AssignmentParser() {
  // your code starts here
}
