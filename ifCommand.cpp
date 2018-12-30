#include "ifCommand.h"



ifCommand::ifCommand()
{
}


ifCommand::~ifCommand()
{
}

int ifCommand::execute(vector<string> args, int index, map<string, double>* symbolTable, map<string, command*> commandParser, map<string, string> *bindMap)
{
	int indexIndent = 1;
	index++;
	string expression = "";
	vector<string> commands;
	while(args[index] != "{"){
	    expression += args[index];
	    index++;
	    indexIndent++;
	}
	index++;
	indexIndent++;
	ExpressionFactory factory = ExpressionFactory();
	Expression* e = factory.expressionEvaluate(expression);
	double conditionResualt = e->calculate();
	if (conditionResualt){
	    while(args[index] != "}"){
            vector<string>::iterator it = commands.end();
	        commands.insert(it,args[index]);
	        indexIndent++;
	        index++;
	    }
	    Parser parser = Parser(commands);
	    parser.parse();
	}
	return indexIndent;
}
