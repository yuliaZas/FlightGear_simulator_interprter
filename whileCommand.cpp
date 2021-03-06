#include "whileCommand.h"



whileCommand::whileCommand()
{
}


whileCommand::~whileCommand()
{
}

int whileCommand::execute(vector<string> args, int index, map<string, double>* symbolTable, map<string, command*> commandParser, map<string, string> *bindMap)
{
	double conditionResualt;
	int indexIndent = 1;
	index++;
	string expression = "";
	vector<string> commands;

	// extract the condition expression
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
	ExpressionFactory factory = ExpressionFactory();
	Expression* e = factory.expressionEvaluate(expression);

	// extract the command to do if the condition is true
	while(args[index] != "}"){
		vector<string>::iterator it = commands.end();
		commands.insert(it,args[index]);
		indexIndent++;
		index++;
	}
	// initialize parser with the command vector
	Parser parser = Parser(commands);
	// calculate the condition expression
	conditionResualt = e->calculate();
	while (conditionResualt){
		// execute the commandds
		parser.parse();
		// calculate the condition expression again
		conditionResualt = e->calculate();
	}

	return indexIndent;
}
