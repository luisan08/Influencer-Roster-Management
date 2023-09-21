/* 
AUTHORS: Luisa Navarrete and Sophia Husain  
DATE: 2/10/2023  
PURPOSE: Implement singly linked list with another class using templates
*/

#include "RandomNum.h"
#include <cstdlib>
#include <ctime>
#include <iomanip>

/***************************************************************************************
 * randomNum: Generates an ID number for each influencer added to the roster between 
 * 100000 and 199999. This number is assigned to each influencer when they are added
 * to the roster. This function uses a for loop to generate a random number between 
 * the bounds selected because without the loop, the rand function uses its own range.                                           
 **************************************************************************************/


int randomNum(){
int lower = 1, upper = 99999; //bounds for random number generation
int base=100000; //base number that will be added to random number
int randomnumber;

    for (int i = 0; i < 5; i++){
        
         randomnumber = (rand() % (upper - lower + 1)) + lower;
       
    } //for loop that generates a random number between the lower and upper bounds
 
    return base + randomnumber; //adds the random number to the base of 100000, creating ID number between 100001 and 199999

}
