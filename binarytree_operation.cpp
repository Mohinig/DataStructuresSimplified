#include <iostream>
#include <stdlib.h>
#define SPACE 10
using namespace std;

class TreeNode
{
public:
    int value;
    TreeNode *left;
    TreeNode *right;
    TreeNode()
    {
        value = 0;
        left = NULL;
        right = NULL;
    }
    TreeNode(int v)
    {
        value = v;
        left = NULL;
        right = NULL;
    }
};

class BST
{
public:
    TreeNode *root;
    BST()
    {
        root = NULL;
    }
    bool isempty()
    {
        if (root == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void insertnode(TreeNode *new_node)
    {
        if (root == NULL)
        {
            root = new_node;
            cout << "value inserted as root node!" << endl;
        }
        else
        {
            TreeNode *temp = root;
            while (temp != NULL)
            {
                if (new_node->value == temp->value)
                {
                    cout << "value already exist,"
                         << "insert another value" << endl;
                    return;
                }
                else if ((new_node->value < temp->value) && (temp->left == NULL))
                {
                    temp->left = new_node;
                    cout << "Value Inserted to the left\n";
                    break;
                }
                else if (new_node->value < temp->value)
                {
                    temp = temp->left;
                }
                else if ((new_node->value > temp->value) && (temp->right == NULL))
                {
                    temp->right = new_node;
                    cout << "Value Inserted to the right\n";
                    break;
                }
                else
                {
                    temp = temp->right;
                }
            }
        }
    }
    void print2D(TreeNode *r, int space)
    {
        if (r == NULL)
            return;
        space += SPACE;
        print2D(r->right, space);
        cout << endl;
        for (int i = SPACE; i < space; i++)
            cout << " ";
        cout << r->value << "\n";
        print2D(r->left, space);
    }
    void printpreorder(TreeNode *r) //(root,left,right)
    {
        if (r == NULL)
        {
            return;
        }
        //print data of node
        cout << r->value << " ";
        //then recur on left subtree
        printpreorder(r->left);
        //then recur on right subtree
        printpreorder(r->right);
    }
    void printinorder(TreeNode *r) //(root,left,right)
    {
        if (r == NULL)
        {
            return;
        }
        //then recur on left subtree
        printinorder(r->left);
        //print data of node
        cout << r->value << " ";
        //then recur on right subtree
        printinorder(r->right);
    }
    void printpostorder(TreeNode *r) //(root,left,right)
    {
        if (r == NULL)
        {
            return;
        }
        //then recur on left subtree
        printpostorder(r->left);
        //then recur on right subtree
        printpostorder(r->right);
        //print data of node
        cout << r->value << " ";
    }

    TreeNode *iterativesearch(int val){
        if (root==NULL)
        {
            return root;
        }
        else
        {
            TreeNode * temp = root;
            while (temp!=NULL)
            {
                if (val==temp->value)
                {
                    return temp;
                }
                else if (val<temp->value)
                {
                    temp = temp->left;
                }
                else
                {
                    temp = temp->right;
                }
                
            }
            return NULL;
        }
        
    }
};
int main()
{
    BST obj;
    int option, val;
    do
    {
        cout << "what operation do you want to perform ?" << endl;
        cout << "select the option, " << endl;
        cout << "1. insert node " << endl;
        cout << "2. Search node " << endl;
        cout << "3. delete node " << endl;
        cout << "4. print BST value in 2D " << endl;
        cout << "5. Clear screen " << endl;
        cout << "0. exit code " << endl;
        cin >> option;
        //node n1
        TreeNode *new_node = new TreeNode();
        switch (option)
        {
        case 0:
            break;
        case 1:
            cout << " insert " << endl;
            cout << "enter the value of tree node to insert in BST: ";
            cin >> val;
            new_node->value = val;
            obj.insertnode(new_node);
            cout << endl;
            break;
        case 2:
            cout << " Search " << endl;
            cout<<"Enter the value of tree node to sexrch in BST: ";
            cin>>val;
            new_node = obj.iterativesearch(val);
            if (new_node!= NULL)
            {
                 cout<<"value found "<<endl;
            }
            else
            {
                cout<<"value not found "<<endl;
            }
            
            break;
        case 3:
            cout << " Delete" << endl;
            break;
        case 4:
            cout << " Print & traverse " << endl;
            obj.print2D(obj.root, 5);
            cout << "Pre-order: ";
            obj.printpreorder(obj.root);
            cout << endl;
            cout << "In-order: ";
            obj.printinorder(obj.root);
            cout << endl;
            cout << "post-order: ";
            obj.printpostorder(obj.root);
            cout << endl;
            break;
        case 5:
            //   cout<<" clear screen "<<endl;
            system("clear");
            break;

        default:
            cout << "Enter proper option " << endl;
            break;
        }
    } while (option != 0);

    return 0;
} 
