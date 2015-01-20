#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <boost/tokenizer.hpp>
#include <string>

using namespace std;
using namespace boost;

int main(int argc, char **argv){ //main can take cmd line args



string str = "";		//used to create a new substring for each word
string cmd;
std::getline(std::cin, cmd);
typedef boost::tokenizer <boost::char_separator<char> > Tok;
boost::char_separator<char> sep;
Tok tok(cmd, sep);
	for(Tok::iterator beg=tok.begin(); beg!=tok.end();++beg){
		cout << *beg << endl;

		str.append(*beg);
	}
/*
int pid = fork();	 //creating a process id/child process

	if(pid == -1){
		perror("fork failed");
	}
	else if(pid == 0){	//in the child process if pid = 0
		//do task
	}
	else if(pid > 0) {
		//now in parent 
		
	}
	*/
	cout << str << endl;
//	std::cout << cmd <<std::endl;
	return 0;
}
