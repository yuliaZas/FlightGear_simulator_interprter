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
	// extract condition expression
	while(args[index] != "{"){
		std::map<string, double >::iterator symbolIter;
		symbolIter = symbolTable->find(args[index]);
		if(symbolIter != symbolTable->end()){
			expression += std::to_string(symbolIter->second);
		}
		else{
			expression += args[index];
		}
	    index++;
	    indexIndent++;
	}
	index++;
	indexIndent++;
	// calculate condition expression
	ExpressionFactory factory = ExpressionFactory();
	Expression* e = factory.expressionEvaluate(expression);
	double conditionResualt = e->calculate();
	// if the condition is true
	if (conditionResualt){
		// put all the command to execute in a new vector
	    while(args[index] != "}"){
            vector<string>::iterator it = commands.end();
	        commands.insert(it,args[index]);
	        indexIndent++;
	        index++;
	    }
	    // execute the new vector
	    Parser parser = Parser(commands);
	    parser.parse();
	}
	return indexIndent;
}
