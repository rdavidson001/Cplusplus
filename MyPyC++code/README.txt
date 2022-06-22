This project uses Python and C++ to take in a text document that includes a list of items, and outputs a few different things
base on the list. First, it ouputs the number of times each item is listed in the text file. Second, it outputs a copy of the list,
except with each item only listed once, with a number of how many times it showed up on the previous list.Lastly, the program uses
Python to transcribe the text document, re-write it into a different text document(Which lists each item once, with the number of occurences from the original list)
, and then passes it back to C++, which then uses the newly created text docutement to output a list of all items, followed by 
'*'s to represent occurences of that item. 
During this project, I believe I am most proud of the Python functions that I created that creates 2 different lists in order
to output a new list with each occurenece and prints out the number of times each occurence happens. the 2 different lists both 
have a specific job; one counts how many occurences of each item in the original list, while the other one uses a for loop to 
create a new list that only has each item occuring once. 
I could definitley enhance my program in a few different ways. The main concern is the opening/closing of the files that
my program opens and reads from. There are a few occurences that I forgot to close the file that I had previoulsy opened. 
From the project, I learned a new skill in the form of using Python and C++ in tangeant, playing off of both strengths of both
computer languages. 
This Program, as it stands, is not the most adaptable. The .txt files that are used are already within the program, and named
specifically within the code. I AM able to replace the .txt files with a variable, and allow the user to input their own
.txt file so that any user-created list could be used. 