README

Deon Naltchadjian
0832759
Friday Feb 27, 2015

Simcpu Program
~~~~~~~~~~~~~~

My simcpu program is unfinished. I assumed all flags we needed were from the command line
and as such my program handles them. In the marking scheme, my program only goes up til the
Event processing section, so I'm guessing this submission will be roughly in the 50% range.

To run my program, type "make" and it will compile. I used the lex.c file provided in A1 for the
parsing here, and made slight modifications to it. I also used a queue implementation from
http://www.sanfoundry.com/c-program-priority-queue/
and made slight alterations from it to get it to work here, although I never
end up using it because I didn't get that far.

Anyway, once the program is opened type "./simcpu [-flags] < input.txt" and it will run.
Here's a sample output:

./simcpu -d -v -r 10 < input.txt
detailed: 1, verbose: 1, robin: 10
number of processes: 2, thread switch: 4, process switch: 6
process number: 1, number of threads: 5
thread number: 1, arrival time: 0, number of CPUs: 4
task number: 1, cpu time: 15, io time: 100
task number: 2, cpu time: 18, io time: 120
task number: 3, cpu time: 12, io time: 100
task number: 4, cpu time: 16, io time: 0
thread number: 2, arrival time: 4, number of CPUs: 4
task number: 1, cpu time: 18, io time: 110
task number: 2, cpu time: 15, io time: 80
task number: 3, cpu time: 20, io time: 75
task number: 4, cpu time: 15, io time: 0
thread number: 3, arrival time: 6, number of CPUs: 5
task number: 1, cpu time: 40, io time: 100
task number: 2, cpu time: 20, io time: 70
task number: 3, cpu time: 15, io time: 80
task number: 4, cpu time: 18, io time: 90
task number: 5, cpu time: 50, io time: 0
thread number: 4, arrival time: 8, number of CPUs: 4
task number: 1, cpu time: 25, io time: 60
task number: 2, cpu time: 15, io time: 50
task number: 3, cpu time: 20, io time: 80
task number: 4, cpu time: 18, io time: 0
thread number: 5, arrival time: 18, number of CPUs: 4
task number: 1, cpu time: 8, io time: 60
task number: 2, cpu time: 15, io time: 120
task number: 3, cpu time: 12, io time: 80
task number: 4, cpu time: 10, io time: 0
process number: 2, number of threads: 4
thread number: 1, arrival time: 0, number of CPUs: 4
task number: 1, cpu time: 12, io time: 80
task number: 2, cpu time: 14, io time: 100
task number: 3, cpu time: 10, io time: 120
task number: 4, cpu time: 12, io time: 0
thread number: 2, arrival time: 4, number of CPUs: 4
task number: 1, cpu time: 16, io time: 140
task number: 2, cpu time: 12, io time: 60
task number: 3, cpu time: 20, io time: 90
task number: 4, cpu time: 10, io time: 0
thread number: 3, arrival time: 6, number of CPUs: 5
task number: 1, cpu time: 20, io time: 120
task number: 2, cpu time: 30, io time: 80
task number: 3, cpu time: 24, io time: 60
task number: 4, cpu time: 18, io time: 100
task number: 5, cpu time: 40, io time: 0
thread number: 4, arrival time: 8, number of CPUs: 4
task number: 1, cpu time: 40, io time: 80
task number: 2, cpu time: 12, io time: 120
task number: 3, cpu time: 24, io time: 100
task number: 4, cpu time: 16, io time: 0

I show all the sorted events FROM THE DATA STRUCTURES, NOT THE PARSER, as well as whether the 
flags are proced or not.

Questions
~~~~~~~~~~~~

I. No, I did not make it that far.
II. No, I did not make it that far.
III. No, I did not make it that far.
IV. No, I did not make it that far.


