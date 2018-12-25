#include "Parser.h"
// #include "lexer.h"
int main() {
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