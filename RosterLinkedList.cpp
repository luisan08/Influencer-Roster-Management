/* 
AUTHORS: Luisa Navarrete and Sophia Husain  
DATE: 2/10/2023  
PURPOSE: Implement singly linked list with another class using templates
*/

#include "RosterLinkedList.hpp"
#include "RandomNum.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;


/******************************************************************************************************
* addEnd(): It asks the user for the influencer's username, first name, last name, and follower       *
*           count. It then adds the influencer to the roster, and each influencer takes up one node   *
*           in the linked list. When an influencer is added, the program assigns them an ID number    *
*           and it calculates their pay per year based on the number of followers that they have.     *
*           These attributes can be seen when the printList() function is called.                     *
 ******************************************************************************************************/
template<typename E>
void LinkedList<E>::addEnd(){

   string username;
   string first_name;
   string last_name;
   int Follower_count;

    Node<E>* node1 = new Node<E>; //allocating memory for a new node in the linked list

    cout << "Enter the username of the Influencer: " << endl;
    cin >> username;

    cout << "Enter the First name of the Influencer: " << endl;
    cin >> first_name;

    cout << "Enter the Last name of the Influencer: " << endl;
    cin >> last_name;

    cout << "Enter the follower count of the Influencer: " << endl;
    while (!(cin >> Follower_count)){  // if the follower count entered is not an integer, they are asked to enter a number 
      cout << "Error. enter a number: ";
      cin.clear();
      cin.ignore(123, '\n');
      }

    cout<<"------------------------------------------------------";
    cout << endl;

    //uses the setter functions to add the user input to the linked list for the username, first, last, and follower count
    //for the pay per year, the follwoer count is passed to the setter funciton so th at the pay varies based on the number of followers
    //the ID number is generated with the random number generator function
    node1->elem.setUsername(username);
    node1->elem.setFirst_name(first_name);
    node1->elem.setLast_name(last_name);
    node1->elem.setFollower_count(Follower_count);
    node1->elem.setPay_per_year(Follower_count);
    node1->elem.setID_number();

    node1->next = NULL; 
  

  // if the linked list is empty, the new node (node1) is set to the head of the list
    if(head == NULL) {
        head = node1;
    } else {
    
  //temporary node that points to the head of the list. 
    Node<E>* temp = head;
    while(temp->next != NULL)
      temp = temp->next;
    

    temp->next = node1;

   }

}


/******************************************************************************************
* clearList(): Clears the linked list by using a while loop that goes through the         *
*              elements and deallocates the memory that was assigned to the influencers.  *
 *****************************************************************************************/
template <typename E>
void LinkedList<E>::clearList(){
        Node<E>* p; //variable to deallocate space

     while(head!=NULL)
    {
        p = head; //assigned to begining of linkedlist
        head = head->next; //moves to next node
        if(p!=NULL) 
          delete(p); //frees the node 
    }

    cout << "Succesfully cleared the roster" << endl;
    

}


/********************************************************************************************
* printList(): Prints the entire linked list in a format that is easy to read for the       *
*             user in a roster format. Prints each influencer's username, firts name,       *
*             last name, pay per year, ID number, and follower count. The ID number is      *
*             generated at this point in the program, and the user will be given a random   *
*             ID number for each influencer they input into the roster.                     *
 *******************************************************************************************/
template <typename E>
void LinkedList<E>::printList(){

    Node<E>* temp = head; //variable to iterate through the linked list

    //for loop that goes through the linked list until it reaches the end of the list
    // & prints the following information about each influencer stored in the roster
    while(temp!=NULL){
        
        cout << "Influencer: " << temp->elem.getLast_name() << ", " << temp->elem.getFirst_name() << " | ";
        cout << "Username: @" << temp->elem.getUsername() << " | ";
        cout << "Pay: $" << temp->elem.getPay_per_year() << " | ";
        cout << "ID Number: " << temp->elem.getID_number() << " | ";
        cout << "Follower Count: " << temp->elem.getFollower_count();
        temp=temp->next;
    cout << endl; 
    }

}



/********************************************************************************************
 * removeElement(): calls the searchElem() function to ask for the user's name, last        *
 *                   name, and username. Then, it displays the user's information. Once     *
 *                  the user knows which Influencer they wish to remove, it asks them       *
 *                  for the Influencer's ID in order to confirm the removal of the          *
 *                  selected Influencer. Then, the function searches the influencer with    *
 *                  the the ID number entered and deallocates the memory for that element   *
 *                  found.                                                                  *
 *******************************************************************************************/

template <typename E>
void LinkedList<E>::removeElement(){
  
    int id_number; //variable for user's input of id number 
 
    //variable pointers in order to transverse loop
    Node<E> *current, *previous;
    
    //call to function searchElem() to look for influencer(element) to be removed
    LinkedList<E>::searchElem();
    cout << "Enter ID number to confirm removal of influencer: " << endl;
    cin >> id_number; //user's input for ID number

    /* For loop to transverse the linked list:
       - Current points at head and previous points to Null
       - Previous will point to an element before current
     */    
    for(current = head, previous = NULL; current != NULL; previous= current, current = current->next){
      //if statement to find element in the linked list based on ID number entered by the user
      if(current->elem.getID_number() == id_number){
        break;
      }

    }
    
    //if the influencer was not found
    if (current == NULL){
      cout << "Influencer does not exist on our records." << endl;
      
    }
    
    //if the first element is to be removed
    if(previous == NULL){
      head = head->next;
      
    }

    //if other elements are to be removed  
    else{
      previous->next = current->next;
    }
    
        //displaying all the influencer's information
        cout << "Influencer: " << current->elem.getLast_name() << ", " << current->elem.getFirst_name() << " | ";
        cout << "Username: @" << current->elem.getUsername() << " | ";
        cout << "Pay: $" << current->elem.getPay_per_year() << " | ";
        cout << "ID Number: " << current->elem.getID_number() << " | ";
        cout << "Follower Count: " << current->elem.getFollower_count();
        cout << endl;
        cout << "Above influencer removed successfully." << endl << endl;

    //deallocating the memory used for the element found
    delete(current);

}



/******************************************************************************************
* searchElem(): Searches for an influencer when given the username, first name, and last  *
*               name by the user. If two influencers have the same username, first name,  *
*               and last name (if they are on different social media platforms), the      *
*               program prints the list of all users with that information. It displays   *
*               the username, first name, last name, follower count, yearly pay and ID    *
*               number of each influencer.                                                *
 ******************************************************************************************/
template <typename E>
void LinkedList<E>::searchElem(){


    // variables for taking input from the user for the influencer search
    Node<E>* temp;
    int check_influencer = 0; //will be set to 1 if the influencer was found
    string username;
    string first_name;
    string last_name;

    cout << "Enter the username of the Influencer: " << endl;
    cin >> username;

    cout << "Enter the first name of the Influencer: " << endl;
    cin >> first_name;

    cout << "Enter the last name of the Influencer: " << endl;
    cin >> last_name;
    
    cout << endl;

  //for loop to search for the influencer using a temporary pointer that iterates through
  //the linked list and compares the given information with the information stored in the
  //linked list. prints out the information if the influencer was found.

    for (temp = head; temp != NULL; temp = temp->next)
   {
        if((temp->elem.getUsername() == username) && (temp->elem.getFirst_name() == first_name) && (temp->elem.getLast_name() == last_name)){
            check_influencer = 1;
            cout << "Username: " << temp->elem.getUsername() << endl;
            cout << "First name: " << temp->elem.getFirst_name() << endl;
            cout << "Last name: " << temp->elem.getLast_name() << endl;
            cout << "Follower Count: " << temp->elem.getFollower_count() << endl;
            cout << "Infleuncer's Pay: $" << temp->elem.getPay_per_year() << endl;
            cout << "ID Number: " << temp->elem.getID_number() << endl;
            cout << endl;


        }

      cout << endl;
      cout<<"------------------------------------------------------";
      cout << endl;
  
   }


    cout << endl; 

    if(check_influencer == 0){
    cout << "Influencer not found. " << endl;
   }
   
}

/***************************************************************************************
 * main(): Asks the managemnet team(user) to enter the number of the menu options      * 
 *       they desire to use. The main function contains a switch statement, which      *
 *       runs in a loop until terminated. On each case for the switch statement,       *
 *       calls a soecific function in order to perfomr the action required. The,       *
 *       it repeats until the user enters the selection 6, which terminates the        *
 *       program. Finally, the program prints an error message if the user enters an   *
 *       invalid code.                                                                 *
 **************************************************************************************/

int main(){

    //changes the sequence of random generator, each time it produces a different number   
    srand((unsigned)time(NULL));

    int selection; //varible in order to store the user's input based on the menu options
    LinkedList<string> mylist; //initialized  object for LinkedList class
    
    //for loop to keep running for user to enter different selections
    for (;;) {
    
    //display of options that the user can select
    cout<<"==============================================="<<endl;
        cout<<"\tSelect option:"<<endl;
        cout<<"\t1 - Add Influencer Information"<<endl;
        cout<<"\t2 - Delete Influencer"<<endl;
        cout<<"\t3 - Display Influencer Roster"<<endl;
        cout<<"\t4 - Search for Influencer"<<endl;
        cout<<"\t5 - Clear Influencer Roster"<<endl;
        cout<<"\t6 - Exit Program"<<endl;
    cout<<"==============================================="<<endl;
    cout << "Enter selection: ";
    while (!(cin >> selection)) //checks if the user entered an integer
    {
        cout << "Error. enter a number: ";
        cin.clear();
        cin.ignore(123, '\n');
    }
    cout<<"==============================================="<<endl;
    
    //switch statement within loop to call specific function depending on user's input
    switch(selection) {

        case 1: 
            //1st case - calls function from LinkedList class to add a new node (or new Influencer)
            mylist.addEnd();
            break;

        case 2:
           //2nd case - calls function from LinkedList class to remove a specific node (or already existing Influence)
           mylist.removeElement();
           break;

        case 3:
            //3rd case - calls function from LinkedList class to print the roster of elements(Influencers)
            mylist.printList();
            break;

        case 4:
            //4th case - calls function from LinkedList class to search for an specific element or Influencer
            mylist.searchElem();
           break;

        case 5:
            //5th case - clears the entire linked list and deallocates memory from previous nodes
            mylist.clearList();
            break;

        case 6:
            //6th case - exits the program when user enters 6
            cout << "Program Terminated" << endl;
            exit(0);
            break;

		return 0; //ends the loop after each function is called by returning 0; without this, the for loop would continuously print the selection menu
      default:  cout << "Invalid selection." << "\n"; //prints out if a selection from the menu options is not selected

    }
    }

  return 0;
}



 