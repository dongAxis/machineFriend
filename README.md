# machineFriend

## destination
when we debug some software, we do not know any information of the machine, such as cpuid, rflags, or control register's status.

machineFriend is for solving this problem.

## build code
1. run "cd" command to the project directory;
2. run "python setup.py build", to get the C module, named friend.so
3. copy friend.so and intel.py to the ${DICT}(any directory)
4. write the command: 

		command script import ${DICT}/intel.py
		
## how to use
when we debug software and stop at one of my breakpoints. 
Enter command "rflags" to show all rflags
e.g. 

	(lldb) rflags
	CF = 0   PF = 1   AF = 0   ZF = 0   SF = 0
	TF = 0   LF = 1   DF = 0   OF = 0   LOPL = 0
	NT = 0   RF = 0   VM = 0   AC = 0   VIF = 0
	VIP = 0   ID = 0
	
## Plan
plan to write more command to show machine's status.
We will update it ASAP.

Happy Hacking
Axis