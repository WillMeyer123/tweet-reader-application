# tweet-reader-application
You will develop a program that will open and read the contents of an input test file. The file name will be provided as a command line argument. Each test file is a text file containing tweets of a news agency. For example, bbchealth.txt is related to BBC health news. Each line contains tweets following the format: tweet id|date and time|tweet. You can assume the separator between fields on each line is always '|'. All test files were downloaded from the Health News in Twitter Data Set.

While reading the contents of the input file line-by-line, your program will be inserting each tweet into a circular doubly linked list. After done reading all tweets, your program will print to the stdout the oldest tweet and then enter a loop waiting for user commands. The user can interact with your program using one of the following commands:

n: prints the next tweet (chronologically) to the stdout
p: prints the previous tweet (chronologically) to the stdout
f: prints the first tweet (oldest) to the stdout
l: prints the last tweet (most recent) to the stdout
<number>: skips tweets circularly and prints the current to the 
s
t
d
o
u
t
s <word>: searches for the next occurrence of the substring word in the following tweets (search is case insensitive and performs a circular traversal in the list)
q: quits the program
You can inspect and run the python script provided as example to get an idea of how your program should work. The output and behavior of your program must match the output of the provided script. The script requires Python2 and can be run by typing the line below. If you want to use Python3, just modify line 12 in the provided script accordingly.

# example of opening the cnnhealth.txt file (you can play with other files as well)
$ python reader.py data/cnnhealth.txt
