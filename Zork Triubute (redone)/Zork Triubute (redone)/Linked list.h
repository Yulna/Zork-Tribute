#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__


template <class	TYPE>
class List
{
public:
	struct Node
	{
		TYPE data;
		Node* next = nullptr;

		Node(const TYPE& data) : data(data){};
		~Node(){};
	};

	Node* first = nullptr;

public:
	
	List(){};
	~List(){};

	bool empty() const{
		return (first == nullptr);
	}

	unsigned int size() const{
		unsigned int ret = 0;
		Node* temp = first;
		while (temp != nullptr){
			temp = temp->next;
			ret++;
		}
		return ret;
	}

	Node* end()const{
		Node* temp = first;
		if (empty() == false){
			while (temp->next != nullptr)
				temp = temp->next;
		}
		return temp;
	}

	void pushback(const TYPE& data){
		Node* it = end();
		if (it != nullptr){
			it->next = new Node(data);
		}
		else{
			first = new Node(data);
		}
	}
	void pushfront(const TYPE& data){
			Node* temp = first;
			first = new Node(data);
			first->next = temp;
	}


	bool pop_back(){
		if (first!=nullptr){
			Node* temp = first;
			Node* last = temp;
			while (temp->next != nullptr){
				last = temp;
				temp = temp->next;
			}
			if (last->next != nullptr)
				last->next = nullptr;
			else
				first = nullptr;

			delete temp;
			return true;
		}
		return false;
	}

	bool pop_front(){
		if (first != nullptr){
			Node* temp = first;
			first = first->next;
			delete temp;
			return true;
		}
		return false;
	}

	
	
	bool erase(Node* tokill){
	
		if (tokill != nullptr){
			Node* temp = first;
			if (tokill != first){
				while (temp->next != tokill){
					temp = temp->next;
				}
				temp->next = tokill->next;
				delete tokill;
				return true;
			}
			first = first->next;
			delete tokill;
		}
		return false;
	}



	bool insert(Node* afterIns, const TYPE& data){
		Node* newNode = new Node(data);
		if (afterIns != nullptr){
			if (afterIns != first){
				Node* temp = first;
				while (temp->next != afterIns){
					temp = temp->next;
				}
				newNode->next = afterIns;
				temp->next = newNode;
				return true;
			}
			newNode->next = afterIns;
			first = newNode;
			return true;
		}
	}
};


#endif // !__LINKED_LIST_H__
