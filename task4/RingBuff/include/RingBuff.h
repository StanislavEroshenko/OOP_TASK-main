#pragma once
#include <ostream>

struct Node
    {
        int value = NULL;
        Node* next;
    };
    Node* head;
    Node* tmp;
	
class List 
{
public:
	List();

	void init(int length);

	void Print(std::ostream& os);

	void add(char x);};
