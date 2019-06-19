#include <string>
#include <iostream>

class CDLLNode {
        private:
            // these will contain the timestamp and content of the tweet as strings
            std::string time;
            std::string tweet;

            // these are pointers to the next and previous nodes in the CDLL
            CDLLNode *next;
            CDLLNode *prev;


        public:
            CDLLNode(const char *ti, const char *tw);
            ~CDLLNode();

        friend class CDLL;
    };

    class CDLL {
        private:
            // pointer to the head/starting node in the CDLL
            CDLLNode *head;
            // this is a helper pointer that allows objects of this
            // class to always remember the 'current node'
            CDLLNode *current;
            unsigned int len;

        public:
            CDLL();   // default constructor
            // you are expected to destroy the linked list
            ~CDLL();  // default destructor
            //std::string ret_tweet();
            // makes an insertion at the front of the list
            void prepend(const char *time, const char *tweet);
            // makes an insertion at the end of the list
            void append(const char *time, const char *tweet);
            // moves 'current' pointer to the next node (circularly)
            void go_next();
            // moves 'current' pointer to the previous node (circularly)
            void go_prev();
            // moves 'current' pointer to the head/first node
            void go_first();
            // moves 'current' pointer to the last node
            void go_last();
            // moves 'current' pointer n elements ahead (circularly)
            void skip(unsigned int n);
            // prints the contents of the 'current' node
            void print_current();
            void search(std::string sub_com);
    };
//#endif
