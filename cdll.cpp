#include <string>
#include <iostream>
#include "cdll.h"
#include <string.h>
#include <algorithm>

CDLLNode::CDLLNode(const char *ti, const char *tw){
    this->time=ti;
    this->tweet=tw;
}
CDLLNode::~CDLLNode(){

}

CDLL::CDLL(){
    current = NULL;
    head = NULL;
    len = 0;
}
// default destructor
CDLL::~CDLL(){
    CDLLNode *d = head;
    CDLLNode *s = head;
    if ( head != NULL ) {
        do {
            head = head->next;
            //head -> prev=d;
            delete d;
            d = head;
        } while (head->next != s);
    }
}

// makes an insertion at the front of the list
void CDLL::prepend(const char *time, const char *tweet){
    CDLLNode * newnode = new CDLLNode(time,tweet);
    len++;
    if (head == NULL){
        head = newnode;
        current = newnode;
        newnode -> next = newnode;
        newnode -> prev = newnode;

    }
    else{
        CDLLNode * temp = head -> prev; //storing tail
        head-> prev = newnode;
        newnode -> prev = temp;
        temp -> next = newnode;
        newnode -> next = head;
        head = newnode;
        current = newnode;
        //std::cout << head -> tweet << std::endl;
        //std::cout << head ->prev -> tweet << std::endl;
    }


}
 // makes an insertion at the end of the list
void CDLL::append(const char *time, const char *tweet){
    len++;
    CDLLNode * newnode = new CDLLNode(time,tweet);
    //std::cout << "IVE BEEN CALLED" << std::endl;
    if (head ==NULL){
        head = newnode;
        current = newnode;
        newnode->next=newnode;
        newnode->prev=newnode;

    }
    else{
        CDLLNode * temp = head -> prev; //storing tail
        head-> prev = newnode;
        newnode -> prev = temp;
        temp -> next = newnode;
        newnode -> next = head;


    }


}

// moves 'current' pointer to the next node (circularly)
void CDLL::go_next(){
    current = current->next;

}
// moves 'current' pointer to the previous node (circularly)
void CDLL::go_prev(){
    current = current -> prev;

}
// moves 'current' pointer to the head/first node
void CDLL::go_first(){
    current = head;
}
// moves 'current' pointer to the last node
void CDLL::go_last(){
    current = head -> prev;
}
// moves 'current' pointer n elements ahead (circularly)
void CDLL::skip(unsigned int n){
    for(unsigned int i = 0; i<n; i++){
        this->go_next();
    }
}
// prints the contents of the 'current' node
void CDLL::print_current(){
    std::cout<<current -> time << "    " << current -> tweet << std::endl;
}

void CDLL::search(std::string sub_com){
    std::string current_tweet = current -> next -> tweet;
    std::transform(current_tweet.begin(), current_tweet.end(), current_tweet.begin(), ::tolower);
    int i = 0;
    while (i<len){
        go_next();
        std::string current_tweet = current -> tweet;
        std::transform(current_tweet.begin(), current_tweet.end(), current_tweet.begin(), ::tolower);
        std::size_t found = current_tweet.find(sub_com);
        if(found != std::string::npos){
          break;
        }
        else {

          i++;
        }
    }

}
