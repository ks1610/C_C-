
// Thuc hanh cay nhi phan tim kiem

#include <iostream>
#include <string>

using namespace std;


// Kieu cua cac nut tren cay (chua thong tin ve mot sinh vien).
struct Node
{
	int maSV;     // Ma sinh vien
	string hoTen; // Ho ten sinh vien
	Node * left;  // Con tro toi nut con trai
	Node * right; // Con tro toi nut con phai
};

// Cay nhi phan tim kiem (chua thong tin sinh vien)
struct SVTree
{
	Node * root; // Con tro toi nut goc cua cay
};

// Ham khoi tao cay (ban dau cay rong)
void treeInit(SVTree & tree);

// Ham huy (xoa het cac nut tren cay)
void treeDestroy(SVTree & tree);

// Kiem tra cay co rong hay khong
bool treeIsEmpty(SVTree & tree);

// Xoa het cac nut tren cay
void treeMakeEmpty(SVTree & tree);

// Xoa rong cay (t la goc cua cay)
void treeMakeEmpty(Node * & t);

// Chen mot sinh vien moi vao cay
void treeInsert(SVTree & tree, int maSV, string hoTen);

// Chen mot sinh vien moi vao cay (t la goc cua cay)
void treeInsert(int maSV, string hoTen, Node * & t);

// Tim sinh vien theo ma SV
Node * treeSearch(SVTree & tree, int maSV);

// Tim sinh vien theo ma SV (t la goc cua cay)
Node * treeSearch(int maSV, Node * t);

void treePostOrderTraveral(Node *& t)
{
    if (t == NULL)
        return;
    
    // Traverse left subtree
    treePostOrderTraveral(t->left);
    
    // Traverse right subtree
    treePostOrderTraveral(t->right);
    
    // Print current node's maSV
    std::cout << t->maSV << " " << t->hoTen<<" -> ";
}

void treePreOrderTraveral(Node *& t)
{
    if (t == NULL)
        return;
    
    // Traverse left subtree
    treePostOrderTraveral(t->right);
    
    // Traverse right subtree
    treePostOrderTraveral(t->left);
    
    // Print current node's maSV
    std::cout << t->maSV << " " << t->hoTen<<" -> ";
}
void treeInOrderTraveral(Node *& t)
{
    if (t == NULL)
        return;
    
    // Traverse left subtree
    treePostOrderTraveral(t->left);

    // Print current node's maSV
    std::cout << t->maSV << " " << t->hoTen<<" -> ";
    
    // Traverse right subtree
    treePostOrderTraveral(t->right);
    
}
/*void PostOrderTraveral(SVTree & tree)
{
	treePostOrderTraveral(tree.root);
}*/

int treeCountNode(Node *& t)
{
	if(t == NULL)
		return 0;
	else 
		return 1 + treeCountNode(t->left) + treeCountNode(t->right);
}

int treeCountLeafNode(Node *& t)
{
	if(t == NULL)
		return 0;
	int isFull = (t->left == NULL && t->right == NULL) ? 1 : 0;
	return isFull + treeCountLeafNode(t->left) + treeCountLeafNode(t->right);
}

int treeCountFullNode(Node *& t)
{
	if(t == NULL)
		return 0;
	int isFull = (t->left != NULL && t->right != NULL) ? 1 : 0;
	return isFull + treeCountFullNode(t->left) + treeCountFullNode(t->right);
}
// YEU CAU THUC HANH
//   1. Khai bao cac ham duyet cay theo thu tu truoc, giua va sau
//   2. Khai bao cac ham dem so nut, so nut la va so nut co du 2 con
//   3. Khai bao ham duyet cay theo thu tu muc (xem bai tap 7 o cuoi bai giang cay va cay nhi phan)
//   4. Khai bao ham in ra cac gia tri tren cay nam trong doan [k1; k2]

// VIET CODE CUA BAN O DAY
// ...

int main()
{
	SVTree tree;
	
	treeInit(tree);
	
	// YEU CAU THUC HANH
	//   1. Viet code chen 7-8 sinh vien vao cay (ve cay sau khi chen ra giay)
	treeInsert(tree, 4, "Nguyen Quoc Tien");
	treeInsert(tree, 5, "Nguyen Quoc Porn");
	treeInsert(tree, 8, "Nguyen Quoc Gay");
	treeInsert(tree, 2, "Tien Gay");
	treeInsert(tree, 6, "Nigga");
	treeInsert(tree, 3, "Tien Porn");
	treeInsert(tree, 9, "Tien Xem Porn");
	/*
						  4
						/  \
					   2	5
					  /		 \
					3		  8			
							 / \
							6   9   			
	*/
	
	//   2. Viet code tim sinh vien theo ma sinh vien:
	//       - Neu tim thay, in ho ten sinh vien len man hinh
	//       - Neu khong tim thay, thong bao khong tim duoc
	Node * found = treeSearch(tree, 6);
	std::cout<<(found ? found->hoTen : "Khong Tim Duoc")<<std::endl;
	
	//   3. Viet code duyet cay theo thu tu truoc, giua va sau
	std::cout<<"Duyet Theo Thu Tu Truoc:"<<std::endl;
	//PostOrderTraveral(tree);
	treePostOrderTraveral(tree.root);
	std::cout<<std::endl;
	std::cout<<"Duyet Theo Thu Tu Sau:"<<std::endl;
	treePreOrderTraveral(tree.root);
	std::cout<<std::endl;
	std::cout<<"Duyet Tu Giua:"<<std::endl;
	treeInOrderTraveral(tree.root);
	std::cout<<std::endl;

	//   4. Viet code dem so nut, so nut la va so nut co du 2 con
	std::cout<<"So Nut Con: "<<treeCountNode(tree.root)<<std::endl;
	std::cout<<"So Nut La Con: "<<treeCountLeafNode(tree.root)<<std::endl;
	std::cout<<"So Nut Con Day Du: "<<treeCountFullNode(tree.root)<<std::endl;
	//treeCountFullNode(tree.root);
	std::cout<<std::endl;

    //   5. Viet code duyet cay theo thu thu muc

    //   6. Viet code in ra cac gia tri tren cay nam trong doan [k1; k2]
    
	//   7. Viet code xoa rong cay
	
	//   8. Viet code kiem tra xem cay da rong hay chua
	
	// VIET CODE CUA BAN O DAY
	// ...
	
	treeDestroy(tree);
	
	return 0;
}

void treeInit(SVTree & tree)
{
	tree.root = NULL;
}

void treeDestroy(SVTree & tree)
{
	treeMakeEmpty(tree);
}

bool treeIsEmpty(SVTree & tree)
{
	return (tree.root == NULL);
}

void treeMakeEmpty(SVTree & tree)
{
	treeMakeEmpty(tree.root);
}

void treeMakeEmpty(Node * & t)
{
	if (t == NULL)           // Cay da rong roi thi thoat ra
		return;
	
	treeMakeEmpty(t->left);  // Xoa rong cay con trai
	treeMakeEmpty(t->right); // Xoa rong cay con phai
	delete t;			     // Xoa nut goc
	t = NULL;                // Khi cay rong thi phai cho t bang NULL
}

void treeInsert(SVTree & tree, int maSV, string hoTen)
{
	treeInsert(maSV, hoTen, tree.root);
}

void treeInsert(int maSV, string hoTen, Node * & t)
{
	if (t == NULL) // Cay dang rong thi nut moi se thanh nut goc
	{
		t = new Node;
		t->maSV = maSV;
		t->hoTen = hoTen;
		t->left = NULL;
		t->right = NULL;
	}
	else if (maSV < t->maSV)
		treeInsert(maSV, hoTen, t->left);
	else if (maSV > t->maSV)
		treeInsert(maSV, hoTen, t->right);
	else
		; // Ma SV da ton tai, khong lam gi ca
}

Node * treeSearch(SVTree & tree, int maSV)
{
	return treeSearch(maSV, tree.root);
}

Node * treeSearch(int maSV, Node * t)
{
	if (t == NULL)
		return NULL;
	
	if (maSV < t->maSV)
		return treeSearch(maSV, t->left);
	else if (maSV > t->maSV)
		return treeSearch(maSV, t->right);
	else
		return t;
}

// YEU CAU THUC HANH
//   1. Dinh nghia cac ham duyet cay theo thu tu truoc, giua va sau
//   2. Dinh nghia cac ham dem so nut, so nut la va so nut co du 2 con
//   3. Dinh nghia ham duyet cay theo thu tu muc
//   4. Dinh nghia ham in ra cac gia tri tren cay nam trong doan [k1; k2]

// VIET CODE CUA BAN O DAY
// ...
