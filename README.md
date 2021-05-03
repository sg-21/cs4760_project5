# Samed Ganibegovic
# Operating Systems CS4760

# Assignment 3: Memory Management
# Due: April 26th 2021

--------------------------------------------------------------------------------------------------------

Brief Description: 

In  this  project  we  will  be  designing  and  implementing  a  memory  management  module  for  our  Operating  System Simulator oss. 
For communication and concurrency protection you can either use semaphores or message queues.
We will be implementing a second-chance FIFO page replacement algorithm.  
That is, assume you have a hardware reference bit that is turned on each time a page is referenced.  (Figure out how the reference bit can be simulated in oss.)  
In addition, you should keep a circular FIFO queue of pages.  
When a page-fault occurs, it will be necessary to swap in that page.  
Normally, the oldest page must be swapped out, unless it has been referenced (the reference bit is 1).  
In that case, reset the bit to 0 and move the head pointer to the next page in the queue.  
Do not forget to consider dirty bit optimization when determining how much time these operations take.

--------------------------------------------------------------------------------------------------------

Invoking the solution:

oss should take in several command line options as follows:

oss -h 
oss [-h] [-n x] [-l f] 

-h          Describe how the project should be run and then, terminate.
-n x        Maximum concurrent child processes
-l f        Specify log file name

--------------------------------------------------------------------------------------------------------

How to run the project: 

First, you will need to type "make" into the command prompt.
This will create the necessary .o files as well as the executable files.
Then, you type ./oss followed by any of the above options. *if no datafile is given, an error message will be prompted*
Now, the program will run as expected.
To clean the project, type "make clean".

--------------------------------------------------------------------------------------------------------

Issues and problems with the program:

The main and biggest issue was that I could not get the project running with the second change FIFO page replacement algorithm.
Instead, I decided to try a different one to at least have something running.
I took an extra day to get a project to compile. 
Besides a few errors here and there with the project, the overall output is still basically alike and working.

--------------------------------------------------------------------------------------------------------

Link to version control:

https://github.com/sg-21/cs4760_project5 
