/*
FILE: postfix.cpp
CLASS:  CIS 40
INSTRUCTOR: Dan Ross

ASSIGNMENT:  Lab #4  Infix Evaluator
DESCRIPTION: Implements an infix evaluator. Input of the form "12*(34-5)" is
converted into its postfix equivalent "12 34 5-*" by decomposing
the expression into tokens and moving the tokens onto a stack and
a queue. The postfix form and the value of the expression are displayed.
*/

#include <iostream>
#include <queue>
#include <stack>
#include <string>

using namespace std;

// The token type definition
struct Token_type {
	int token;
	int token_type;
};
typedef struct Token_type Token;

stack<Token> st;
queue<Token> qu;

// FUNCTION PROTOTYPES
void get_token(char * str, Token & t);
void print_token(Token *);
int prcdnc(Token t);
Token perform(Token, Token, Token);
void bufferize(char * s, Token t);
void calc_postfix(void);
int get_input(void);

// GLOBAL DATA
string infix_str = ""; //"12+45*(67-89 + 70) / 34";  // for debug
string postfix_str = "";
int ichar = 0;

// pointer to chars in infix_str
int main(void)
{
	// get infix input from user and convert to postfix
	while (get_input() != 1)
		calc_postfix();
	return 0;
}

/*
Gets a string from the user. Returns false if the user enters a null string.
*/
int get_input(void)
{
	// get an infix expression from the user
	cout << "Please enter an infix expression (RETURN to exit):\n";
	cin >> infix_str;
	postfix_str[0] = 0;
	return infix_str.length();
}

/*
Converts a string containing a valid infix expression
into the corresponding postfix expression.  Calculates
and displays the value of the expression.
*/
void calc_postfix(void)
{
	while (!st.empty())
		st.pop();
	while (!qu.empty())
		qu.pop();
	
	Token tmp, t, op1, op2;
	tmp.token = '#'; tmp.token_type = 0; st.push(tmp);
	for (unsigned int i = 0; i < infix_str.length(); i++)
	{
		t.token = infix_str[i];
		if (t.token != '*' && t.token != '/' && t.token != '+' && t.token != '-')
		{
			t.token_type = 1;
			qu.push(t);
		}
		else if (t.token == '(')
		{
			st.push(t);
		}
		else if (t.token == ')')
		{
			tmp = st.top(); st.pop();
			while (tmp.token != '(')
			{
				qu.push(tmp); tmp = st.top(); st.pop();
			}
		}
		else 
		{
			t.token_type = 0;
			while (st.top().token != '#' && prcdnc(t) <= prcdnc(st.top()))
			{
				tmp = st.top(); st.pop(); qu.push(tmp);
			}
			st.push(t);
		}
	}

	// clean out the stack
	while (st.top().token != '#')
	{
		tmp = st.top(); st.pop(); qu.push(tmp);
	}

	// empty stack
	while (!st.empty())
		st.pop();

	while (!qu.empty())
	{
		t = qu.front(); qu.pop();
		print_token(&t);
		postfix_str += t.token;
		if (t.token_type == 1)
		{
			st.push(t);
		}
		else {
			op1 = st.top(); st.pop();
			op2 = st.top(); st.pop();
			Token result = perform(op1, op2, t);
			st.push(result);
		}
	}

	cout << "\nThe infix expression is: " << infix_str << "\n";
	cout << "The postfix expression is: " << postfix_str << "\n";
	printf("The value of the expression is: %d\n\n\n", t.token);

	/*while (!st.empty())
	{
		tmp = st.top(); st.pop();
		cout << tmp.token << " " << tmp.token_type << "\n";
	}
	while (!qu.empty())
	{
		t = qu.front(); qu.pop();
		if (t.token_type = 0)
			st.push(t);
		else {
			op1 = st.top(); st.pop();
			op2 = st.top(); st.pop();
			Token result = perform(op1, op2, t);
			st.push(result);
		}
	}

	// push on a dummy operator having lowest precedence
	// move infix tokens into stack and queue 
	// pop and enqueue the remaining operators
	// EVALUATE POSTFIX EXPRESSION
	// DISPLAY ANSWER
	cout << "\nThe infix expression is: " << infix_str << "\n";
	cout << "\nThe infix expression is: " << postfix_str << "\n";
	printf("The value of the expression is: %d\n\n\n", t.token);*/
}

/*
Converts a token into a string and concatenates the result onto s.
*/
void bufferize(string s, Token t)
{
	string buf;
	if (t.token_type) {
		buf = to_string(t.token);
		s = s + buf;
		s = s + " ";
	}
	else {
		buf[0] = t.token;
		s = s + buf[0];
		s = s + " ";
	}
}

/*
Performs an arithmetic operation on two tokens using
the operator contai
ned in the third token.
*/
Token perform(Token op1, Token op2, Token t)
{
	Token answer;
	switch (t.token) {
	case '*':
		answer.token = op2.token * op1.token;
		break;
	case '/':
		answer.token = op2.token / op1.token;
		break;
	case '+':
		answer.token = op2.token + op1.token;
		break;
	case '-':
		answer.token = op2.token - op1.token;
		break;
	}
	answer.token_type = 1; // just for consistency
	return answer;
}

/*
Returns the precedence of an operator
3) * /
2) + -
1) #
0) (
*/
int prcdnc(Token t) {
	if (t.token_type) return 0;
	switch (t.token) {
	case '*':
	case '/':
		return 3;
	case '-	':
	case '+':
		return 2;
	case '#':
		return 1;
	}
	return 0;
}

/*
A handy debug function.
*/
void print_token(Token * t)
{
	if (t->token_type)
		printf("Token: %d\tType: %d\n", t->token - '0', t->token_type);
	else
		printf("Token: %c\tType: %d\n", t->token, t->token_type);
}

/*
Parses a string into tokens.  Reference parameters are used to
receive the string and return the corresponding token.
*/
void get_token(char * str, Token & t)
{
	//NOTE:
	//Expressions may only contain the chars "0123456789/*-+". No Spaces!

	char buf[2] = { 0,0 }; // a buffer used with atoi

	switch (str[ichar]) {
		case '*':
		case '/':
		case '-':
		case '+':
		case '#':
		case ')':
		case '(':
			// token must be an operator
			t.token = str[ichar];
			t.token_type = 0;
			ichar++;
			return;
	}

	buf[0] = str[ichar];
	t.token = atoi(buf); // token must be an operand
	t.token_type = 1;
	ichar++;
}