/*
 * Implement a function which will generate binary numbers from 1 to n in an array
 * of type string by making use of a queue.
 * Input - A positive integer n
 * Sample Input = 3
 * Sample Output = result{"1","10","11"}
 */
#include <iostream>
#include <cstdlib>
#include "Queue.h"
using namespace std;


//Start with Enqueuing 1.
//Dequeue a number from queue and append 0 to it and enqueue it back to queue.
//Perform step 2 but with appending 1 to the original number and enqueue back to queue.
//Queue takes integer values so before enqueueing it make sure to convert string to integer.
//Size of Queue should be 1 more than number because for a single number we're enqueuing two
//variations of it , one with appended 0 while other with 1 being appended.

string *findBin(int n){
    string * result = new string[n];
    myQueue queue(n+1);
    queue.enQueue(1);

    string s1, s2;
    for (int i = 0; i < n; i++){
        result[i] = to_string(queue.deQueue());
        s1 = result[i] + "0";
        s2 = result[i] + "1";
        queue.enQueue(stoi(s1));
        queue.enQueue(stoi(s2));
    }

    return result;
}
/*
int main(){
    auto output = findBin(10);
    for(int i = 0; i < 10; i++)
        std::cout<<output[i] <<"   ";

    return 0;
}
 */

/*
 * Crux of the solution is to generate consecutive binary numbers from previous binary
 * numbers by appending 0 and 1 to each of them.
 * Ex. 10 and 11 can be generated when 0 and 1 are appended to 1
 *     100 and 101 are generated when 0 and 1 are appended to 10
 * As soon as binary number is generated it is enqueued to a queue so that new binary
 * numbers can be generated by appending 0 and 1 when that number will be enqueued.
 * Enqueued numbers are Dequeued in FIFO order so overall resultant array is mathematically correct.
 *
 * On line 24, 1 is enqueued as a starting point. Now to generate a binary number
 * sequence, a number is dequeued from queue and stored in the result array.
 * 0 and 1 are appended to it to produce the next numbers which are then Enqueued to
 * the queue on lines 24-25.
 *
 */