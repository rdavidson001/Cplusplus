import re
import string

#I decided to make a function that prints characters and symbols to make the list look a little more appealing to the eye.
def CharSize(number, symbol):
	print(symbol * number)
	

#For my readlist, I ended up making 2 different lists; myList[] would only have each item occuring once, and countOccur[] that would only focus on counting the number of times each product occured. 
#ALong with that, I made sure to use split and strip to remove the white space. After which, I printed out the list followed by the occurences of each one.
def readList(file):
    with open(file, 'r') as read:
        myList = []
        countOccur = []
    
        for i in read:
            line_stripped = i.strip()
            line_split = line_stripped.split()
            countOccur.append(line_split)
            if line_split not in myList:
                myList.append(line_split)
    myList = [i[0] for i in myList]
    countOccur = [i[0] for i in countOccur]
    
    print(myList)
    for i in myList:
        CharSize(45, "-")
        print("There was", countOccur.count(i), " occurence(s) of ", i)
    CharSize(45, "-")
    
    return 0
   # with this function, I did the same as the previous funcion in order to create the same list. when the user inputs the product they are looking for, the program itterates over the list to see if there was any match, and if there was, itll look at 
   # the countoccur list to check how many times it was labeled.
def findItem(file):
    product = input("What Item are you looking for? Please type in exact item name   \n")
    read = open(file, "r")
    myList = []
    countOccur = []
    
    for i in read:
        line_stripped = i.strip()
        line_split = line_stripped.split()
        
        countOccur.append(line_split)
        if line_split not in myList:
            myList.append(line_split)
    myList = [i[0] for i in myList]
    countOccur = [i[0] for i in countOccur]
    read.close()

    for i in myList:
        if i == product:
            CharSize(45,"-")
            print(countOccur.count(i), product, "Have been purchased")
            CharSize(45, "-")
            break

    return 0
    # this one wwas tricky for me, mainly for the writing out file. I conintued to get an error where I could not pass an integer through, so I had pass it through as a string in order to write the entire thing to the file.
def createFile(file):
    fileName = open(file, 'r')
    placeHolder = []
    myListList = []
    for i in fileName:
        placeHolder.append(i.strip())
        if i.strip() not in myListList:
            myListList.append(i.strip())
    CharSize(15, "*")
    print("The following are the number of each product sold")
    CharSize(15, "*")
    with open("frequency.txt","w") as outFile:
        for i in myListList:
            outFile.write(i)
            outFile.write(" ")
            outFile.write("%s\n" % str(placeHolder.count(i)))
       
            
    

    return 0
    
   
    
 
    





    
