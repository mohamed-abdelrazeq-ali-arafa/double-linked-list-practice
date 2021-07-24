#include<iostream>
using namespace std;

struct node {
	int data;
	node* next;
	node* prev;


};
node* head = NULL;
void insertf(int value) {
	node* new_node = new node;
	new_node->data = value;

	if (head == NULL) {

		head = new_node;
		new_node->next = NULL;
		new_node->prev = NULL;


	}
	else {


		node* temp = head;
		new_node->next = temp;
		temp->prev = new_node;
		head = new_node;





	}
}

void insertl( int value) {
	node* new_node = new node;
	new_node->data = value;
	if (head == NULL) {
	
		head = new_node;
		new_node->next = NULL;
		new_node->prev = NULL;
	
	
	}
	else {
		node* temp = head;

		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = new_node;
		new_node->prev = temp;

	}
}
	void display(){
	
		node* temp;
		temp = head;
		while (temp != NULL) {
			cout << temp->data << endl;
			temp = temp->next;

		}

	
	
	
	}



	void remove( int value) {
	
		node* temp = head;
		if (temp->data == value) {
		
			head = temp->next;
		
		}
		else {
			while (temp->data != value) {
				temp = temp->next;

			}
			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;




		}
	
	
	
	
	}
	//function to count
	int count() {
		if (head == NULL)
			return 0;
		int counter = 0;
		node* temp = head;
		while (temp != NULL) {
			counter += 1;
			temp = temp->next;

		}

		return counter;


	}
	//function to print iterative
	void display_iterative() {
		if (head == NULL)
			return;
		node* temp = head;
		while (temp != NULL) {

			cout << temp->data << " ";
			temp = temp->next;
		}

	}
	//print in revers order
	/*void print_r() {
		if (head == NULL) {
			return;
		}
		node* temp = head;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		while (temp != NULL) {
			cout << temp->data ;
			temp = temp->prev;
		}
	}
	*/
		//Print element at middle of linked list
		
		void print_middle() {
			if (head == NULL)
				return;

			int counter = 0;
			node* temp = head;
			while (temp != NULL) {
				counter += 1;
				temp = temp->next;

			}
			int countmiddle = 0;
			node* tempo = head;
			while (tempo != NULL) {
				countmiddle += 1;
				if (countmiddle == counter / 2)
				{
					cout << tempo->data<<endl;
				}
				tempo = tempo->next;

			}


		}
	// Print element at position i in linked list
		void print_atposition(int i) {
			if (i < 0)
				return;
			if (head == NULL) {
				return;
			}

			int wanted_to_print = 0;
			node* tempo = head;
			while (tempo != NULL) {

				if (wanted_to_print == i)
				{
					cout << tempo->data;
				}
				tempo = tempo->next;
				wanted_to_print += 1;
			}



		}
	//Insert element at position i in linked list
		void insert_at_position(int pos, int new_data) {
			node* new_node = new node();
			new_node->data = new_data;
			if (pos == 0) {
				new_node->next = head;
				head = new_node;
				return;

			}
			
				node* temp = head;
				for (int i = 0; i < pos && temp != nullptr; i++) {
					temp = temp->next;
				}

				new_node->prev = temp->prev;
				temp->prev->next = new_node;
				temp->prev = new_node;
				new_node->next = temp;


			
		}
		//Delete element at position i in linked list

		void remove_at_pos(int pos) {
			if (head == nullptr)
				return;

			node* temp = head;
			if (pos == 0) {
				head = temp->next;
				delete (temp);
				return;
			}

			for (int i = 0; i < pos && temp != nullptr; i++)
				temp = temp->next;


			temp->prev->next = temp->next;
			
		     temp->next->prev = temp->prev;
			delete (temp);

		}
		//search
		int  search(int new_data) {
			if (head == NULL) {
				return 0;
			}
			node* temp = head;
			while (temp != NULL) {

				
				if (temp->data == new_data) {

					return new_data;
				}
				temp = temp->next;
			}

			
				 return -1;


		}
int main() {


	insertf(90);
	insertf(80);
	insertf(100);
	insertf(200);
	display();
	cout << "--------" << endl;
	cout << count() << endl;
	//print_r();
	print_middle();
	cout << "--------" << endl;
	insert_at_position(2,60);
	display();
	
    cout << "--------" << endl;
	remove_at_pos(2);
	display();
	cout << "--------" << endl;
	cout<<search(990);


	return 0;
}