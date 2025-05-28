#ifndef LINKEDLISTLIB_H
#define LINKEDLISTLIB_H

// Kieu phan tu
typedef int T;

// Kieu cua cac nut
struct Node
{
    T elem;      // Phan tu
    Node * next; // Con tro toi nut tiep theo
    
    Node(int value){
		elem = value;
		next = NULL;
	}
};

// Kieu danh sach lien ket don
struct List
{
    Node * head; // Con tro toi nut dau danh sach
};

void listInit(List & list)
{
    list.head = NULL;
}

bool listIsEmpty(List & list)
{
    return (list.head == NULL);
}



T listFront(List & list)
{
    return list.head->elem;
}

void listPushFront(List & list, T e)
{
    Node * v = new Node(e);
    v->next = list.head;
    list.head = v;
}

void listPopFront(List & list)
{
    Node * old = list.head;
    list.head = list.head->next;
    delete old;
}

void listDestroy(List & list)
{
    while (!listIsEmpty(list))
        listPopFront(list);
}

int Listgetsize(List & list)
{
	int size = 0;
	Node* tmp = list.head;
	while(tmp != NULL)
	{
		size++;
		tmp = tmp->next;
	}
	return size;
	
}

void Listprint(List & list)
{
	Node* tmp = list.head;
	while(tmp != NULL)
	{
		std::cout<<tmp->elem<<" ";
		tmp = tmp->next;
	}
}

int Listposition(List & list, int e)
{
	int find = 0;
	Node* tmp = list.head;
	while(tmp != NULL)
	{
		find++;
		if(tmp->elem == e){
			break;
		}
		tmp = tmp->next;
	}
	return find;
}

bool Listcheckposition(List & list, int e)
{
	Node* tmp = list.head;
	while(tmp != NULL)
	{
		if(tmp->elem == e){
			break;
		}
		else
			return 0;
		tmp = tmp->next;
	}
	return tmp->elem = e;
}

void Listinsertbefore(List & list, int x, int e)
{
    Node *tmp = list.head;

    // Traverse the list to find the element x
    while (tmp != NULL && tmp->elem != x) {
        tmp = tmp->next;
    }

    // If x is found, insert e before it
    if (tmp != NULL) {
        Node* newNode = new Node(e);

        // Insert before the node tmp
        newNode->next = tmp;
        
        // If x is the first element, adjust head
        if (tmp == list.head) {
            list.head = newNode;
        } else {
            // Otherwise, find the node before tmp
            Node* prev = list.head;
            while (prev->next != tmp) {
                prev = prev->next;
            }
            prev->next = newNode;
        }
    }
}

void Listdeletx(List & list, int x)
{
    // Handle the case where the list is empty
    if (list.head == NULL) {
        std::cout << "List is empty, nothing to delete." << std::endl;
        return;
    }

    // Special case: if x is the first element (head)
    if (list.head->elem == x) {
        Node* temp = list.head;
        list.head = list.head->next;  // Move the head pointer
        delete temp;  // Delete the old head node
        return;
    }

    // General case: search for the element x
    Node* tmp = list.head;
    while (tmp->next != NULL) {
        if (tmp->next->elem == x) {
            Node* toDelete = tmp->next;
            tmp->next = tmp->next->next;  // Bypass the node to delete
            delete toDelete;  // Delete the node
            return;
        }
        tmp = tmp->next;
    }

    // If we reach here, x was not found
    std::cout << "Element " << x << " not found in the list." << std::endl;
}

void Listinsertlast(List & list, T x){
    Node *newNode = new Node(x);
	
	if(list.head == NULL)
		list.head = newNode;
	else{
    	Node* tmp = list.head;
		while(tmp->next != NULL){
			tmp = tmp->next;
		}
		tmp->next = newNode;
	}
}

// YEU CAU THUC HANH
//   Dinh nghia cac ham thuc hien cac viec sau:
//     1. Tra ve kich thuoc cua danh sach
//     2. In cac phan tu trong danh sach len man hinh
//     3. Tra ve phan tu o vi tri k trong danh sach (vi tri bat dau tu 0)
//     4. Kiem tra xem mot gia tri x co mat trong danh sach hay khong
//     5. Chen mot phan tu moi vao truoc x (neu x ton tai trong danh sach)
//     6. Xoa phan tu x (neu x ton tai trong danh sach)
//     7. Chen mot phan tu moi vao cuoi danh sach

// VIET CODE CUA BAN O DAY...


#endif // LINKEDLISTLIB_H