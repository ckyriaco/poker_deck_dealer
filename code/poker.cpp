#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stdexcept>
#include <limits>
#include <string>
#include <cstdlib>
#include <array>
#include <time.h>
#include <utility>

/*
- Author: Christopher Kyriacou
- Description: This is a program for that shuffles and deals poker cards from a preset poker deck. The shuffling is fully randomized.
- Breakdown: 
	- Coding Language = C++
	- 52 Playing Cards
	- 4 Suites = Hearts, Spades, Clubs, diamonds
	- Face values of Ace, 2-10, Jack, Queen and King.
	- Two required functions from class: shuffle and dealOneCard.
	- Being implemented through the usage of a doubly linked list.
	- Four classes: Node, , stack, doublyLinkedList, and Deck
*/

using namespace std;
//class for nodes for a doubly linked list

class node{
	public:
		int data;
                string suit;
		node* next;
		node* prev;

		//constructor

		node(int value, string s){
			prev=NULL;
			data=value;
            suit = s;
			next=NULL;
		}
};

//doubly linked list class

class doublyLinkedList{
	private:
		node* head;
		node* tail;
		int i;
	public:
		//constructor for doubly linked list object initialization

		doublyLinkedList(){
			head=NULL;
			tail=NULL;
			i = 0;
		}
		node* get_head(){
			return head;
		}
		node* get_tail(){
			return tail;
		}
		int getI(){
			return i;
		}
		//insert at the beginning of the doubly linked list
		
		void insert_at_head(int value, string s){
			node* n = new node(value, s);
			n->next=head;
			if(tail == NULL){
				tail = head;
			}
			if(head!=NULL){
				head->prev=n;
			}
			head=n;
			i++;
		}
		//insert at the end of the doubly linked list

		void insert_at_tail(int value, string s){
			if(head==NULL){
				insert_at_head(value, s);
				return;
			}
			node* n = new node(value, s);
			node* temp;
			if(tail != NULL){
				temp = tail;
				tail->next = n;
				tail = n;
				tail->prev = temp;
			}else{
				temp=head;
				while(temp->next!=NULL){
					temp=temp->next;
				}
				tail=n;
				temp->next=n;
				n->prev=temp;
			}
			i++;
			cout << tail->data;
		}
		//delete the head of the doubly linked list

		node* returnHead(){
			
			node* temp = head;
			
			deletbegin();
			return temp;
		}

		//delete the beginning of the doublylinkedlist.
		void deletbegin(){
			if(head == NULL){
				throw invalid_argument("There is no head to remove!");
			}
			cout << head->data;
			head = head->next;
			i--;
			
		}
		
		
	
		
		//delete the tail of a doubly linked list

		void deletend(){
			if(tail == NULL){
				throw invalid_argument("There is no tail to remove!");
			}
			cout << tail->data;
			tail = tail->prev;
			tail->next = NULL;
			i--;
			
		}

		//delete a node at a specific postion in the doubly linked list

		void deletatpos(int n){
			if(n < 0 || n > (i - 1)){
				throw std::invalid_argument("The index must be positive and not greater than the number of nodes");
			}else if(n == 0){
				deletbegin();
			}else if(n == (i - 1)){
				deletend();
			}else{
				node* x = head;
				int z = 0;
				while (z < n){
					x = x->next;
					z++;
				}
				node **pre, **aft;
				pre = &(x->prev);
				aft = &(x->next);

				(*pre)->next = (*aft);
				(*aft)->prev = (*pre);
				i--;
			}
			
		}

		//Sort the nodes randomly in the doublylinkedlist
		
		void sortNode(){
			int l = i;
			srand(time(0));
			for(int n = 0; n < i-1; n++){
				if(i > 1){
					
					int p; 
					node* y;
					if(n == 0){
						y = head;
						deletbegin();
						if(i <= 2){
							p = 0 + (rand() % (i));
						}else{
							p = 0 + (rand() % (i-1));
						}
						
						insertatpos(p, y->data, y->suit);
					}else if(n == (i - 1)){
						y = tail;
						deletend();
						if(i <= 2){
							p = 0 + (rand() % (i));
						}else{
							p = 0 + (rand() % (i-1));
						}
						
						insertatpos(p, y->data, y->suit);
					}else{
						node* x = head;
						int z = 0;
						while (z < n){
							x = x->next;
							z++;
						}
						y = x;
						node **pre, **aft;
						pre = &(x->prev);
						aft = &(x->next);

						(*pre)->next = (*aft);
						(*aft)->prev = (*pre);
						i--;
						if(i <= 2){
							p = 0 + (rand() % (i));
						}else{
							p = 0 + (rand() % (i-1));
						}
						
						insertatpos(p, y->data, y->suit);
					}
				}else{
					cout<<"\nThere is only one card no need to sort!\n";
				}
			}
			
		}
		//insert at a specific position in the doubly linked list

		void insertatpos(int n, int value, string s){
			if(n < 0 || n > (i - 1)){
				throw std::invalid_argument("The index must be positive and not greater than the number of nodes");
			}else if(n == 0){
				insert_at_head(value, s);
			}else if(n == (i - 1)){
				insert_at_tail(value, s);
			}else{
				node* newNode = new node(value, s);
				node* temp = head;
				for(int z = 0; z < n - 1; z++){
					temp = temp->next;
				}
				newNode->next = temp->next;
				(temp->next)->prev = newNode;
				temp->next = newNode;
				newNode->prev = temp;
				i++;
				
			}
		}
		//display all nodes in the doubly linked list

		void display(){
			node* temp=head;
			cout << "\n";
			while(temp!=NULL){
                if(temp->data > 1 && temp->data < 11){
				    cout<<temp->suit<<" "<<temp->data<<" <-- ";
                }else{
                    if(temp->data == 1){
                        cout<<temp->suit<<" Ace <-- ";
                    }else if(temp->data == 11){
                        cout<<temp->suit<<" Jack <-- ";
                    }else if(temp->data == 12){
                        cout<<temp->suit<<" Queen <-- ";
                    }else{
                        cout<<temp->suit<<" King <-- ";
                    }
                    
                }
				temp=temp->next;
			}
			cout<<"NULL\n"<<endl;
			
		}
		
};

class stack{
	private:
		doublyLinkedList Stack;
		node* stackPointer;
		int ind;
		public:
			
			
			//constructor

			stack(){
				stackPointer = Stack.get_head();
				ind = -1;
			}
			int getInd(){
				return ind;
			}
			node* getStackPointer(){
				return stackPointer;
			}
			doublyLinkedList getStack(){
				return Stack;
			}
			//Add a value to the top of the stack

			void push(int data, string s){
				Stack.insert_at_head(data, s);
				ind++;
				stackPointer = Stack.get_head();
			
			}
			//remove a value from the top of the stack and return the value.
	
			node* pop(){
				if(ind == -1){
					throw invalid_argument("There is nothing to remove from the stack!");
				}else{
					
					node* s = Stack.returnHead();
					
					if(ind == 0){
						ind = -1;
					}else{
						ind--;
					}
					stackPointer = Stack.get_head();
					return s;
				}
			}
			//Utilize the sortNode function from the doublyLinkedList class to sort the cards.

			void sort(){
				Stack.sortNode();
				stackPointer = Stack.get_head();
			}

			//Display the stack.
			void display(){
				cout << "\nStack\n";
				Stack.display();
			}
};


class deck{
	private:
		struct card{
			int face;
			string suit;
		};
		stack d;
		int maxCards = 52;
		int cardsInSuites = 13;
		int nodeCounter = 0;
		int dealCounter = 0;
		struct card suites[52] = {
									{1, "hearts"}, {2, "hearts"},
									{3, "hearts"}, {4, "hearts"},
									{5, "hearts"}, {6, "hearts"},
									{7, "hearts"}, {8, "hearts"},
									{9, "hearts"}, {10, "hearts"},
									{11, "hearts"}, {12, "hearts"},
									{13, "hearts"},{1, "spades"},
									{2, "spades"}, {3, "spades"},
									{4, "spades"}, {5, "spades"},
									{6, "spades"},{7, "spades"},
									{8, "spades"},{9, "spades"},
									{10, "spades"},{11, "spades"},
									{12, "spades"},{13, "spades"},
									{1, "clubs"}, {2, "clubs"},
									{3, "clubs"}, {4, "clubs"},
									{5, "clubs"}, {6, "clubs"},
									{7, "clubs"}, {8, "clubs"},
									{9, "clubs"}, {10, "clubs"},
									{11, "clubs"}, {12, "clubs"},
									{13, "clubs"},{1, "diamonds"},
									{2, "diamonds"}, {3,  "diamonds"},
									{4, "diamonds"},{5,  "diamonds"},
									{6, "clubs"},{7, "clubs"},
									{8, "clubs"}, {9, "clubs"},
									{10, "clubs"}, {11, "clubs"},
									{12, "clubs"}, {13, "clubs"}
															
		};
    public:
		//Constructor

        deck(){
            cout<<"Deck Class Initiated";
			makeDeckNode();
			
        }

		stack get_deck(){
			return d;
		}
		
		int get_cardsInSuites(){
			return cardsInSuites;
		}

		int getDealCounter(){
			return dealCounter;
		}
		int getNodeCounter(){
			return nodeCounter;
		}
		int getMaxCards(){
			return maxCards;
		}
		struct card * getSuites(){
			struct card temp[52];
			for(int i = 0; i < maxCards; i++){
				temp[i] = suites[i];
			}
			return temp;
		}
		//This function creates a doubly linked-list that represents the card deck to be used.
		
        void makeDeckNode(){
			int suitCounter = 0;
			int count = 0;
            for(int i = 0; i < 52; i++){
				d.push(suites[i].face, suites[i].suit);
				nodeCounter++;
			}
			d.display();
        }
		//This function utilizes the doubly linked list sortNode function to shuffle the card deck randomly.

		void shuffle(){
			d.sort();
			d.display();
		}

		//This function deals out cards until the deck is empty only if a deck has been initiated

        node* dealOneCard(){
			if(nodeCounter == 0){
				throw invalid_argument("A deck has not been initiated!");
			}else if(dealCounter < maxCards){
				
				node* card = d.pop();
				
				nodeCounter--;
				dealCounter++;
				return card;
			}else{
				cout<<"There are no cards to pass out!";
			}

        }

		//Display the deck.
		
		void display(){
			d.display();
		}
        
    
};

//Utilizes the above classes to deal up to 52 cards.
void askForCard(){
	deck de;
	string deal;
	int count = de.getDealCounter();
	int max = de.getMaxCards();
	cout << "Enter any key (except for just enter) to shuffle the deck and deal a card and N to exit the deal and shuffle function: ";
	cin >> deal;
	while(deal != "N" && count < max){
		try{
			cout<<"Starting\n";
			if(count < max - 1){
				de.shuffle();
			}else{
				de.display();
			}
			cout<<"dealing\n";
			node* r = de.dealOneCard();
			cout<<"\n"<<r->data<<" "<<r->suit;
		
		}catch(std::invalid_argument& e){
			std::cerr << e.what() << std::endl;
			
		}
		count = de.getDealCounter();
		cout << "\nThe current count is "<<count;
		if(count != max){
			cout << "\nEnter any key (except for just enter) to shuffle the deck deal a card and N to exit the program: ";
			cin >> deal;
		}
	}
	cout<<"\nAll cards have been dealt... Goodbye!!!";
}

//Main method executes the program until user initiates exit protocol (Enters N)

int main(){
	string deal;
	cout << "\nEnter any key (except for just enter) to use the card shuffler and dealer program or N to exit the program: ";
	cin >> deal;
	while(deal != "N"){
		askForCard();
		cout << "\nEnter any key (except for just enter) to use the card shuffler and dealer program or N to exit the program: ";
		cin >> deal;
	}
	return 0;
}
