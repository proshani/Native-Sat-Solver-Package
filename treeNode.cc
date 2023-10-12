#include "treeNode.h"
#include <iostream>
#include <string>
#include "StackType.h"
using namespace std;
TreeNode::TreeNode(std::string cntt) : content{ cntt } {}




struct node;

int priority(char);
node* makeNode(char);
void attachOperator(StackType<node*>&, StackType<node*>&);

int evaluateTree(node*);

struct node {
	char info;
	node* left;
	node* right;
};


int priority(char op) {
	if ((op == '+') || (op == '-'))
		return 1;
	if (op == '*')
		return 2;
}


node* makeNode(char info) {
	node* childnode;
	childnode = new node;
	childnode->info = info;
	childnode->left = NULL;
	childnode->right = NULL;
	return childnode;
}


node* operatornode;
void CreateTreeNot(StackType<node*>& treenodes, StackType<node*>& operators)
{
	node* operatornodesubTree = operators.Top();
	operators.Pop();
	operatornodesubTree->right = treenodes.Top();
	operatornode->right = operatornodesubTree;
	//treenodes.Push(operatornodesubTree);
}

void attachOperator(StackType<node*>& treenodes, StackType<node*>& operators, StackType<node*>& Lastoperators) {

	operatornode = Lastoperators.Top();
	operatornode->left = treenodes.Top();
	treenodes.Pop();
	node* Nextoperatornode = operators.Top();
	if (!operators.IsEmpty() && Nextoperatornode->info == '-')
	{
		CreateTreeNot(treenodes, operators);
		//treenodes.Pop();
		//operators.Pop();
	}
	else
	{
		operatornode->right = treenodes.Top();
	}

	treenodes.Pop();
	treenodes.Push(operatornode);
}

int evaluateTree(node* treenode) {
	int x, y, z;
	if ((treenode->info) == '+' || (treenode->info) == '-' || (treenode->info) == '*' || (treenode->info) == '/') {
		if ((treenode->info) == '-')
			y = evaluateTree(treenode->right);
		else
		{
			x = evaluateTree(treenode->left);
			y = evaluateTree(treenode->right);
		}
		if (treenode->info == '+')
		{
			if (x == 1 || y == 1)
				z = 1;
			else
				z = 0;
		}
		else if (treenode->info == '-') {
			if (y == 1)
				z = 0;
			else
				z = 1;
		}
		//z = x - y;
		else if (treenode->info == '*') {
			if (x == 1 && y == 1)
				z = 1;
			else
				z = 0;
			//z = x * y;
		}
		return z;
	}
	else return treenode->info - '0';
}




int TreeNode::getContent() const {
	cout << content;
	string infix; // the infix expression read from the line
	StackType<char> input; // stack for input string
	StackType<node*> operators; // stack for operator pointer addresses
	StackType<node*> treenodes;  // stack for output node pointer addresses
	char temp, again = ' ';
	for (int i = 0; i < content.length(); i++) {
		input.Push(content[i]);
	}
	while (!input.IsEmpty()) {
		temp = input.Top();
		input.Pop();
		//If it is operand, make it into a node, add it to output string.
		if (isdigit(temp))
			treenodes.Push(makeNode(temp));
		//If it is Closing parenthesis, make into node, push it on stack.
		if (temp == ')')
			operators.Push(makeNode(temp));
		//If it is an operator, then
		if ((temp == '+') || (temp == '/') || (temp == '-') || (temp == '*')) {
			bool pushed = false;
			while (!pushed) {
				//If stack is empty, make node and push operator on stack.
				if (operators.IsEmpty()) {
					operators.Push(makeNode(temp));
					pushed = true;
				}
				//If the top of stack is closing parenthesis, make node and push operator on stack.
				else if (operators.Top()->info == ')') {
					operators.Push(makeNode(temp));
					pushed = true;
				}
				//If it has same or higher priority than the top of stack, make node and push operator on stack.
				else {
					operators.Push(makeNode(temp));
					pushed = true;
				}
				
			}
		}
		
		if (temp == '(') {
			while (operators.Top()->info != ')')
			{
				char lastoperators = ' ';
				lastoperators = operators.Top()->info;
				operators.Pop();
				StackType<node*> operatorslast;
				operatorslast.Push(makeNode(lastoperators));
				attachOperator(treenodes, operators, operatorslast);
			}
			operators.Pop(); // ')' is popped and discarded
		}
	}
	//If there is no more input, unstack the remaining operators and perform attachOperator
	while (!operators.IsEmpty()) {
		char lastoperators = ' ';
		lastoperators = operators.Top()->info;
		operators.Pop();
		if (operators.IsEmpty())
		{
			operators.Push(makeNode(lastoperators));
			attachOperator(treenodes, operators, operators);
			operators.Pop();
		}
		else
		{
			StackType<node*> operatorslast;
			operatorslast.Push(makeNode(lastoperators));
			attachOperator(treenodes, operators, operatorslast);
		}
	}

	int answer = evaluateTree(treenodes.Top());
	cout << endl << "Evaluation: " << answer << endl;
	return answer;
}

//TreeNode* TreeNode::getLeftChild() const {
//	// your code starts here
//	return nullptr;
//}
//TreeNode* TreeNode::getRightChild() const {
//	// your code starts here
//	return nullptr;
//}
//
//void TreeNode::updateLeftChild(TreeNode* lChild) {
//	// your code starts here
//}
//
//void TreeNode::updateChildren(TreeNode* lChild, TreeNode* rChild) {
//	// your code starts here
//}
//
//OperatorNode::OperatorNode(std::string cntt) : TreeNode{ cntt } {}
//
//bool OperatorNode::evaluate(const std::map<std::string, bool>& assignment) const {
//	// your code starts here
//	return false;
//}
//
//ConstantNode::ConstantNode(std::string cntt) : TreeNode{ cntt } {}
//
//bool ConstantNode::evaluate(const std::map<std::string, bool>& assignment) const {
//	// your code starts here
//	return false;
//}
//
VariableNode::VariableNode(std::string cntt) : TreeNode{ cntt } {}

bool VariableNode::evaluate(const std::map<std::string, bool>& assignment) const {
	// your code starts here
	return false;
}
//
//TreeNode::~TreeNode() {
//	// your code starts here
//}
 