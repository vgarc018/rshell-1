#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <boost/tokenizer.hpp>
#include <string>
#include <vector>
#include <queue>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

using namespace std;
using namespace boost;
	
bool andflag = false ;
bool orflag = false;
bool exit_flag = false;
bool finishflag = false;
string cmd = "";
string hash = "#";	//hash is for comments
queue<string> more_cmds;
vector<string> command;
//this queue is for cmd, || && etc
int i = 0;		//used as index of argv in main
string nocomment = "";
//	while(exit_flag == false){
	//gets the full command	and returns the string - hash comments
	string get_cmd(){
		cout << "$: ";
		std::getline(std::cin, cmd);
	
		//finds # and removes anything after hash
		size_t found_hash = cmd.find(hash);
		if(found_hash <= cmd.size()){
			cmd = cmd.substr(0, found_hash);
			cout << found_hash << endl;
		}
		return cmd;
	}

int main(int argc, char **argv){

		get_cmd();

		size_t found_and = 0;
		for(int i = 0; i< cmd.size(); i ++){
			if(cmd.at(i) == '&' && cmd.at(i+1) == '&' ){
				andflag = true;
			}
		}

		size_t found_or = 0;
		for(int i = 0; i< cmd.size(); i++){
			if(cmd.at(i) == '|' && cmd.at(i+1) == '|')
				orflag = true;
		}

		//tokenizing the string
		typedef boost::tokenizer <boost::char_separator<char> > Tok;
		boost::char_separator<char> sep(" ");
		Tok tok(cmd, sep);
//		cout << "push a new command" << endl;
		for(Tok::iterator beg=tok.begin(); beg!=tok.end();++beg){
			command.push_back(*beg);	
			cout << *beg <<"     "; 
			cout << command.size()<< endl;
		}
//We now pushed all cmd's connectors and possibly false commands
		while(command.size() > 0){ //do this while line size > 0
			string str = command.front();
			if(str.compare("exit") ==  0) { exit(1);}	

			//checking for && connector
			for(int i = 0; i < command.size(); i++){
				if(command.at(i) == "&&"){cout << "found and" << endl;}
			}
			//checking for or connector
			for(int i = 0; i < command.size(); i++) {
				if(command.at(i) == "||") {cout << "found or" << endl;}
			}
			//checking for semi-colon (;)
			for(int i = 0; i < command.size(); i++) {
				if(command.at(i) == ";") {cout << "found semi-colon" << endl;}
			}

			int pid = fork();
			if(pid == -1) { perror ( "fork failed"); exit(1);}
			else if(pid == 0) {
				if(execvp(command.front().c_str(), argv) !=0 ){
					perror("There's an error in execvp");
					exit(1);	
				}
				cout << "popping command" << endl;
				command.erase(command.begin());
			}
			else if(pid > 0) {
				if(-1 == wait(0)) {
					perror("There was an error in wait");
				}
			}
			command.erase(command.begin());
			cout << endl;
		}	
//	}			
	return 0;
}
