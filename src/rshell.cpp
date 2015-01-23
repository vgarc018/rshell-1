#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <boost/tokenizer.hpp>
#include <string>
#include <vector>
#include <queue>

using namespace std;
using namespace boost;

bool exit_flag = false;
string exiting = "exit";
string str = "";		//used to create a new substring for each word

int num_of_args = 0;
queue <string> commands;
void andcmd(const char* s) {
	
}
queue <string> line;
int i = 0;		//used as index of argv in main
int main(int argc, char **argv){ //main can take cmd line args
string nocomment = "";
	while(exit_flag == false){
			
		cout << "$: ";
		string cmd;	
		std::getline(std::cin, cmd);
		
		str = "";

		typedef boost::tokenizer <boost::char_separator<char> > Tok;
		boost::char_separator<char> sep;
		Tok tok(cmd, sep);
		for(Tok::iterator beg=tok.begin(); beg!=tok.end();++beg){
			cout << *beg << endl;
			str.append(*beg);
		
		}
			if(str.compare("exit") == 0) { exit_flag = true;}	
			str = "";
			
			
		}
			
//	cout <<&str << endl;
	return 0;
}
