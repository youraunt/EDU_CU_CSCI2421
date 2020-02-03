*******************************************************
*  Name      :	Brice Allen          
*  Student ID:	107452188                 
*  Class     :  CSC 2421           
*  HW#       :  1                
*  Due Date  :  Feb. 3, 2020
*******************************************************


                 Read Me


*******************************************************
*  Description of the program
*******************************************************

The program "2188HW1" takes input form the user, and uses
the data to implement random numbers stored in two vectors.
It then allows the user to guess random integers in the range
they provided. The game allows for three rounds, but will terminate
the current game instance if all integers are matched. The game will
ask if the use would like to play another game.

*******************************************************
*  Source files
*******************************************************

Name:  main.cpp
   Main program.  This is the driver program that calls sub-functions
   to read data from an user, use the data to create two vectors,
   and play the game.

Name:  guess.h
   Contains the definition for the class guess.

Name: guess.cpp
   Defines and implements the guess class for implementing a game object.
   This class provides routines to randomize numbers using a random_device
   to seed a mersenne twister engine.

Name: functions.h
   Contains the prototypes for the matrix program support functions.

Name: functions.cpp
   Includes functions to display a greeting, and handle user input.
   
   
*******************************************************
*  Circumstances of programs
*******************************************************

   The program runs successfully.  
   
   The program was developed and tested on gnu g++ 4.4.2.  It was 
   compiled, run, and tested on gcc csegrid.ucdenver.pvt.


*******************************************************
*  How to build and run the program
*******************************************************

1. Uncompress the homework.  The homework file is compressed.  
   To uncompress it use the following commands 
       % unzip 2188HW1

   Now you should see a directory named homework with the files:
        main.cpp
        guess.h
        guess.cpp
	functions.h
    	functions.cpp
        makefile
        Readme.txt

2. Build the program.

    Change to the directory that contains the file by:
    % cd 2188HW1 

    Compile the program by:
    % make

3. Run the program by:
   % ./2188HW1

4. Delete the obj files, executables, and core dump by
   %./make clean
