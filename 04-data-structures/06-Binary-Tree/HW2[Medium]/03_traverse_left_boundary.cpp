#include<iostream>
#include<vector>
#include<cmath>
#include<stack>
#include<assert.h>
using namespace std;


typedef int type;
class BinaryTree{
private:
    type data{ };
    BinaryTree* left{ };
    BinaryTree* right{ };

public:
    BinaryTree(const type &data):
        data(data){
    }
    void print_inOrder() {
        if (left)
            left->print_inOrder();
        cout << data << " ";
        if(right)
            right->print_inOrder();
    }
    void add(const vector<type> &data, const vector<char> &direction){
        assert((int)data.size() == (int)direction.size());
        BinaryTree* current = this;

        for(int i=0; i<(int)data.size(); i++){
            if(direction[i] == 'L'){
                if(!current->left)
                    current->left = new BinaryTree(data[i]);
                else
                    assert(current->left->data == data[i]);
                current = current->left;
            }else{
                if(!current->right)
                    current->right = new BinaryTree(data[i]);
                else
                    assert(current->right->data == data[i]);
                current = current->right;
            }
        }
    }
    void clear_nodes() {
        if(left){
            delete left;
            left = nullptr;
        }
        if(right){
            delete right;
            right = nullptr;
        }
    }
    ~BinaryTree(){
        cout << "Node " << data << " deleted at address " << this << "\n";
        clear_nodes();
    }

    void traverse_left_boundary(){
        cout << data << " ";
        if(left)
            left->traverse_left_boundary();
        else if(right)
            right->traverse_left_boundary();
    }

};


void test1() {
	BinaryTree tree(2);
	tree.add( { 3, 5, 8, 6, 7, 15 }, { 'L', 'L', 'R', 'R', 'L', 'R' });
	tree.add( { 13, 8 }, { 'R', 'L' });
	tree.add( { 13, 7 }, { 'R', 'R' });


	tree.traverse_left_boundary();
	cout << "\n";
}

void test2() {
	BinaryTree tree(1);

	tree.add( { 2 }, { 'L' });
	tree.add( { 3 }, { 'R' });


	tree.add( { 2, 4, 7 }, { 'L', 'L', 'L' });
	tree.add( { 2, 4, 8 }, { 'L', 'L', 'R' });
	tree.add( { 2, 5, 9 }, { 'L', 'R', 'R' });
	tree.add( { 3, 6, 15 }, { 'R', 'R', 'L' });


	tree.add( { 2, 5, 13 }, { 'L', 'R', 'L' });
	tree.add( { 3, 6, 12 }, { 'R', 'R', 'R' });
	tree.add( { 3, 14, 15 }, { 'R', 'L', 'L' });
	tree.add( { 3, 14, 16 }, { 'R', 'L', 'R' });

	tree.traverse_left_boundary();
	cout << "\n";
}

int main() {
    test1();
    test2();

	cout << "bye\n";

	return 0;
}


