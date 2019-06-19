#include "cdll.h"
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <algorithm>
int main(int argc, char* argv[]){
    CDLL tweets;
    std::string line;
    std::ifstream open_file;
    open_file.open(argv[1]);
    while(getline (open_file,line)){
        //std::cout<<line<<std::endl;
        int i = 0;
        while(line[i] != '|'){
            i++;
        }
        i++;
        std::string date_time = line.substr(i,19);
        //std::cout<<date_time<<std::endl;
        while(line[i] != '|'){
            i++;
        }
        i++;
        int k = i;
        while(line[k] != '|' and k < line.length()){
          k++;
        }
        std::string tweet_str = line.substr(i,k - i);
        //std::cout << tweet_str << std::endl;

        const char * tweet_char = tweet_str.c_str();
        const char * date_time_char = date_time.c_str();
        tweets.prepend(date_time_char,tweet_char);
    }
    open_file.close();
    std::string command;
    tweets.print_current();

    while(1){
        getline(std::cin, command);
        if (command[0] == 'n'){
            tweets.go_next();
            tweets.print_current();
        }
        else if (command[0] == 'p'){
            tweets.go_prev();
            tweets.print_current();

        }
        else if (command[0] == 'f'){
            tweets.go_first();
            tweets.print_current();
        }
        else if (command[0] == 'l'){
            tweets.go_last();
            tweets.print_current();
        }
        else if (command[0] >= '0' and command[0] <= '9'){
            int skip_amnt = std::stoi(command);
            tweets.skip(skip_amnt);
            tweets.print_current();
        }
        else if (command[0]=='s'){
            std::string command_copy;
            int i = 2;
            if(command.length() == 3)
              command_copy = command[2];
            else{
              while(i <= command.length() - 1){
                command_copy += command[i];
                i++;
              }
            }
            std::transform(command_copy.begin(), command_copy.end(), command_copy.begin(), ::tolower);
            tweets.search(command_copy);
            tweets.print_current();
        }

        else if(command == "q"){
            break;

        }


    }
}
