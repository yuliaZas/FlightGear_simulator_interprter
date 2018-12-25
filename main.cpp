#include "Parser.h"
#include "Lexer.h"
#include "Expression/ExpressionFactory.h"
#include "Expression/Expression.h"
#include "list"

int main() {
	//check factory
	ExpressionFactory x = ExpressionFactory();
	list < Expression * > list1;
	Expression* c = x.expressionEvaluate("3 * - 10");
	cout<< c->calculate()<<endl;
	list1.push_back(c);
	/*
Expression* c = x.expressionEvaluate(" + -  40");
Expression* c = x.expressionEvaluate("5 - + - 3");
Expression* c = x.expressionEvaluate("5 + - + 3");


	list1.push_back(e0);
	Expression* e1 = x.expressionEvaluate("5 - - 3");
	list1.push_back(e1);
	Expression* e2 = x.expressionEvaluate("3 - + 10");
	list1.push_back(e2);
	Expression* e22 = x.expressionEvaluate("3 + - 10");
	list1.push_back(e22);
	Expression* e3 =
	list1.push_back(e3);
	Expression* e31 = x.expressionEvaluate("3 * + 10");
	list1.push_back(e31);
	Expression* e32 = x.expressionEvaluate("81 / - 9");
	list1.push_back(e32);
	Expression* e33 = x.expressionEvaluate("81 / + 9");
	list1.push_back(e33);
	Expression* f = x.expressionEvaluate(" - ( - 2 + 4)");
	list1.push_back(f);
	Expression* g = x.expressionEvaluate(" - ( - 6 / - 2)");
	list1.push_back(g);
	Expression* h = x.expressionEvaluate(" - ( - 6 * - 2)");
	list1.push_back(h);
	Expression* i = x.expressionEvaluate(" 0.2 * 0.5 ");
	list1.push_back(i);
	Expression* i1 = x.expressionEvaluate(" (0.8 -(0.2 * 0.5) + 0.8 ) / 0.5 ");
	list1.push_back(i1);
	Expression* i2 = x.expressionEvaluate(" 1/3 ");
	list1.push_back(i2);
	Expression* i3 = x.expressionEvaluate(" 1 / 3 / 1 / 4 / 1 / 5");
	list1.push_back(i3);
	Expression* i4 = x.expressionEvaluate(" (1 / 3)* (1 / 4) * (1 / 5) ");
	list1.push_back(i4);
	*/

/*output:
 * 100
 * -40
 * 8
 * 2
 * 8
 * -7
 * -7
 * -30
 * 30
 * -9
 * 9
 * -2
 * -3
 * -12
 * 0.1
 * 3
 * 0.333333
 * 0.166667
 * 0.166667
 * */



    // check git
	vector<string> args;
	//args.insert(args.end(), "var");
	//args.insert(args.end(), "x");
	args.insert(args.end(), "var");
	args.insert(args.end(), "y");
	args.insert(args.end(), "=");
	args.insert(args.end(), "13");
	args.insert(args.end(), "y");
	args.insert(args.end(), "=");
	args.insert(args.end(), "29");
	// check with lexer
	//args.insert(args.end(), "print");
	//args.insert(args.end(), "\"smile\"");
	args.insert(args.end(), "print");
	args.insert(args.end(), "y");
	args.insert(args.end(), "sleep");
	args.insert(args.end(), "5");
	Parser p = Parser(args);
	p.parse();
	return 0;
}