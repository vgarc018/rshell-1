#include <iostream>
#include <dirent.h>
#include <errno.h>
#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <getopt.h>
#include <vector>
#include <string.h>
#include <boost/tokenizer.hpp>
#include <stdio.h>
#include <time.h>
#include <iomanip>
#include <pwd.h>

using namespace std;

bool dash_a = false;
bool dash_l = false;
bool dash_R = false;
bool directory = false;

struct stat s;      //used for file || direct...
vector<char*> files;
vector<char*> directories;
/*
 *This should program should use opendir/readdir/closedir
 *It will also use error checking on these functions.
*/
void get_flags(int c, char** s){
int opt;
   while((opt = getopt(c, s , "alR")) != -1){
        if(opt == '?') {perror("error in getopt");
            exit(0);
        }
        switch (opt){ //transitions to opt states
            case 'a':
                dash_a = true;
                //cout << "setting case: a " << endl;
                //call dash_a helper to print the -a
            break;
            case 'l':
                dash_l = true;
                cout <<"setting case: l" << endl;
            break;
            case 'R':
                dash_R = true;
                cout << "setting case: R" << endl;
            break;
            default:
                exit(0);
                cout << "in default" << endl;
            break;
        }
    }
}
//this is for the -a flag
void a_flag(){
    int prints = 0;
    const char* dirName = ".";
    DIR* dirp = opendir(dirName);
    dirent* direntp;
    while((direntp = readdir(dirp))){
        string file_name = direntp->d_name;
        cout << file_name <<"   ";
        prints++;
        if(prints % 3 == 0){ cout << endl;}
    }
    closedir(dirp);
    cout << endl;
}

//this is for the -l flag
void l_flag(){
    int l_total = 0;
    struct stat stat_buf;
    const char* dirName = ".";
    DIR* dirp = opendir(dirName);
    dirent* direntp;

    if(stat((direntp->d_name), &stat_buf) == -1) {perror("stat");}
    else{

            cout << ("-");
            cout << ((stat_buf.st_mode & S_IRUSR) ? "r":"-");
            cout << ((stat_buf.st_mode & S_IWUSR) ? "w":"-");
            cout << ((stat_buf.st_mode & S_IXUSR) ? "x":"-");
            cout << ((stat_buf.st_mode & S_IRGRP) ? "x":"-");
            cout << ((stat_buf.st_mode & S_IWGRP) ? "w":"-");
            cout << ((stat_buf.st_mode & S_IXGRP) ? "x":"-");
            cout << ((stat_buf.st_mode & S_IROTH) ? "r":"-");
            cout << ((stat_buf.st_mode & S_IWOTH) ? "w":"-");
            cout << ((stat_buf.st_mode & S_IXOTH) ? "x":"-");
            cout << endl;
    }
    closedir(dirp);
    ////////////////////////////////////////
    ////////////////////////////////////////


   // while((direntp = readdir(dirp))){
     //   if((direntp->d_name != ".") || (direntp->d_name != ".."))
       //     cout << direntp->d_name << endl;
   // }
   // closedir(dirp);

}
int main (int argc, char* argv[]){
    for(int i = 1; i != argc; i++){//for loop skips argv[0] since it's the executable

}
    vector <char*> all_files;
    for(int i =1; i < argc; i++){
        all_files.push_back(argv[i]);

    }
    get_flags(argc, argv);
    if(dash_a == true) {a_flag();}
    if(dash_l == true) {l_flag();}
//    if(dash_R == true) {R_flag();}
    return 0;
}
