#include<iostream>
#include<queue>
using namespace std;

class Node  {
    public:
        int data;
        Node * left;
        Node * right;
        Node(int d) {
            this->data = d;
            this->left = NULL;
            this->right = NULL;
        }
};

Node* insertIntoBST(Node * root,int d)   {

    if(root==NULL)  {
        root = new Node(d);
        return root;
    }

    //for inserting in the right subtree
    if(d > root->data)
        root->right = insertIntoBST(root->right,d);
    //for inserting in the left subtree
    else
        root->left = insertIntoBST(root->left,d);

}

void takeInput(Node * &root)  {

    int data;
    cin>>data;

    while(data != -1)   {
        root = insertIntoBST(root,data);
        cin>>data;
    }
    return ;

}

void levelOrder(Node* root) {
        
        queue<Node* > q;
        
        if(root==NULL)
            return ;
        
        Node* temp ;
        temp=root;
        q.push(temp);
        
        while(!q.empty())   {
            
            int len = q.size();   
            // vector<int> level;
            
            for(int i=0;i<len;i++)  {
                temp = q.front();       
                q.pop();
                cout<<temp->data<<" ";
                
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
            cout<<"\n";
        
        }
        
        return ;
    }

int main()  {

    Node* root = NULL;
    cout<<"enter the data streajm to create a BST : \n";
    takeInput(root);

    cout<<"The BST fromed is  :- \n";
    levelOrder(root);

    return 0;
}