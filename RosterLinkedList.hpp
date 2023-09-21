/* 
AUTHORS: Luisa Navarrete and Sophia Husain  
DATE: 2/10/2023  
PURPOSE: Implement singly linked list with another class using templates
*/

#ifndef ROSTERLinkedList_H
#define ROSTERLinkedList_H
#include <string>

using namespace std;

//call function to randomNum() to generate the ID's for each element
int randomNum();

//forward declaration of template for Node class
template <typename E> 
class Node;

//influencer class - holds data like name, last name, username, ID, amount of follers, and the pay.
class Influencer
{
private:
    string Username;
    string First_name;
    string Last_name;
    int ID_number;
    int Follower_count;
    int Pay_per_year;
   

public:

    //modifiers - class methods to change the specific data outside of the class
     //setters functions - set the private varaibles from the input outside the class
     void setUsername(string username){Username = username;}
     void setFirst_name(string first_name) {First_name = first_name;}
     void setLast_name(string last_name) {Last_name = last_name;}

     //setters - calls on randomNum() function to generate the ID number
     void setID_number() {ID_number = randomNum();} 
     
     //setters - accepts followers_count varaible to calculate pay; it is calculated by multiplying each follower by 0.1(cent), then 12(months)
     void setPay_per_year(int pay_per_year) {Pay_per_year = ((Follower_count*0.1)*12);}
     void setFollower_count(int follower_count) {Follower_count = follower_count;}
         

    //getters - class methods that return the updated information outside of class
    string getUsername() { return Username; }
    string getFirst_name() { return First_name; }
    string getLast_name() { return Last_name; }
    int getID_number() { return ID_number; }
    int getFollower_count() { return Follower_count; }
    int getPay_per_year() { return Pay_per_year; }
 
};

//forward declaration 
template <typename E> 
class LinkedList;

template <typename E> //template for node element
class Node { 
    private:
    Influencer elem; // linked list element value as Influencer data type
    Node<E>* next; // pointer to next elemenet in the list
    friend class LinkedList<E>; // provide LinkedList access to private members
};



template <typename E>
class LinkedList{ //a singly linked list
private:
        Node<E>* head; //pointer varaible that will represent head of linked list
        
public:
        //constructor
        LinkedList(){
           head = NULL; //setting head to Null
        } 
    
    //declaration pf public methods for LinkedList class 
    void addEnd();
    void clearList();
    void printList();
    void removeElement();
    void searchElem();

};


#endif