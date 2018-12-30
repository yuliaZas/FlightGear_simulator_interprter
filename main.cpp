#include "Parser.h"
#include "Lexer.h"
#include "Expression/ExpressionFactory.h"
#include <fstream>
#include <iostream>
#include <stdio.h>

int main(int argc, char *argv[]) {

	// check there are enough parameters
	if (argc < 2){
		cout << "Too few arguments" << endl;
		return 0;
	}
	// initialize lexer
	Lexer* lexer = new Lexer();
	// get file name from commandline arguments
	string fileName = argv[1];
	string line;
	ifstream file;
	file.open(fileName, ios::in);
	// make sure the file opened correctly
	if(!file){
		cout <<"file does not exist" << endl;
		return 0;
	}
	// read file one line each time until the end
	while(!file.eof())
	{
		getline(file, line);
		// pass the line to the lexer
		lexer->read(line);
	}
	vector<string> *args;
	// get the tokens from the lexer
	args = lexer->getVec();
	Parser p = Parser(*args);
	try {
	// parse the tokens
		p.parse();
	}	catch(...)	{

	}
	pthread_exit(nullptr);
}