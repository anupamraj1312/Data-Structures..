#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node* left;
    node* right;
};
//node* root = NULL;
node* CreateNode(int data)
{
    node* temp = new node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
node* Insert(node* root,int data)
{
    if(root == NULL)
        root = CreateNode(data);
    else if(data <= root->data)
        root->left = Insert(root->left,data);
    else
        root->right = Insert(root->right,data);
    return root;
}
void Print(node* root)
{
    if(root != NULL)
    {
        cout<<"data  is "<<root->data<<endl;
        Print(root->left);
        Print(root->right);
    }
}
bool Search(node* root,int number)
{
    if(root == NULL)
        return false;
    else if(root->data == number)
        return true;
    else if(number < root->data)
        return Search(root->left,number);
    else
        return Search(root->right,number);
}
int FindMin(node* root)
{
    if(root->left == NULL)
        return root->data;
    else
        return FindMin(root->left);
}
int Height(node* root)
{
    int CountLeft=0,CountRight=0;
    if(root == NULL)
        return max(CountLeft,CountRight);
    CountLeft = Height(root->left);
    CountLeft++;
    CountRight = Height(root->right);
    CountRight++;

}
void LevelOrderTraversal(node* root)
{
    queue<node*> q;
    if(root == NULL)
        return;
    q.push(root);
    cout<<"DATA IS ";
    while(!q.empty())
    {
        node* current = q.front();
        cout<<current->data;
        q.pop();
        if(current->left != NULL) q.push(current->left);
        if(current->right != NULL) q.push(current->right);
        cout<<" ";
    }
}
void PreOrderTraversal(node* root)
{
    if(root == NULL)
        return;
    cout<<root->data<<" ";
    PreOrderTraversal(root->left);
    PreOrderTraversal(root->right);
}
void InOrderTraversal(node* root)
{
    if(root == NULL)
        return;
    PreOrderTraversal(root->left);
    cout<<root->data<<" ";
    PreOrderTraversal(root->right);
}
void PostOrderTraversal(node* root)
{
    if(root == NULL)
        return;
    PreOrderTraversal(root->left);
    PreOrderTraversal(root->right);
    cout<<root->data<<" ";
}
node* FindMinRoot(node* root)
{
    while(root->left != NULL)
        root = root->left;
    return root;
}
node* FindMaxRoot(node* root)
{
    while(root->right != NULL)
        root = root->right;
    return root;
}
node* Find(node* root, int data)
{
    if(root->data == data)
        return root;
    else if(root->data > data)
        return Find(root->left,data);
    else
        return Find(root->right,data);
}
node* DeleteNode(node* root,int data)
{
    if(root == NULL)
        return root;
    else if(data < root->data)      //search on left subtree
        root->left = DeleteNode(root->left,data);
    else if(data > root->data)      //search on right subtree
        root->right = DeleteNode(root->right,data);
    else        //found the data
    {
        if(root->left == NULL && root->right == NULL)       //No Child
        {
            delete root;
            root = NULL;
        }
        else if(root->left == NULL)     //one child and left one is empty
        {
            node* temp = root;
            root = root->right;
            delete temp;
        }
        else if(root->right == NULL)
        {
            node* temp = root;
            root = root->left;
            delete temp;
        }
        else        //two children
        {
            node* temp = FindMinRoot(root->right);
            root->data = temp->data;
            root->right = DeleteNode(root->right,temp->data);
        }
    }
    return root;
}
node* InorderSuccessor(node* root,int data)
{
    node* current = Find(root,data);        //pointer to the node for which the successor to find
    if(current == NULL)     //if node not found, we return null
    return NULL;
    if(current->right != NULL)      //now we have two choice if the node have right subtree or not
    {
        return FindMinRoot(current->right);     //if have right subtree then the successor is the minimum value in right subtree
    }
    else        //if current node don't have right node
    {
        node* successor = NULL;
        node* ancestor = root;
        while(ancestor != current)
        {
            if(ancestor->data > current->data)
            {
                successor = ancestor;
                ancestor = ancestor->left;
            }
            else
                ancestor = ancestor->right;
        }
        return successor;
    }
}
node* InorderPredecessor(node* root, int data)
{
    node* current = Find(root,data);
    if(current == NULL)
        return NULL;
    if(current->left != NULL)
        return FindMaxRoot(current->left);
    else
    {
        node* predecessor = NULL;
        node* successor = root;
        while(successor != current)
        {
            if(successor->data < current->data)
            {
                predecessor = successor;
                successor = successor->right;
            }
            else
                successor = successor->left;
        }
        return predecessor;
    }
}
int main()
{
    int i;
    node* root = NULL;
    for(i=10;i>=8;i--)
        root = Insert(root,i);
    for(i=11;i<=12;i++)
        root = Insert(root,i);
    cout<<"ENTER NUMBER TO BE SEARCHED ";
    int data;
    cin>>data;
    if(Search(root,data))
        cout<<"found "<<endl;
    else
        cout<<"nope"<<endl;
    cout<<"MIN IS "<<FindMin(root)<<endl;
    cout<<"HEIGHT IS "<<Height(root)<<endl;
    //root = DeleteNode(root,9);
    LevelOrderTraversal(root);
    cout<<endl;
    PreOrderTraversal(root);
    cout<<endl;
    InOrderTraversal(root);
    cout<<endl;
    PostOrderTraversal(root);
    cout<<endl;
    cout<<"INORDER SUCCESSOR IS "<<(InorderSuccessor(root,10))->data;
    cout<<"INORDER PREDECESSOR IS "<<(InorderPredecessor(root,10))->data;
    return 0;
}
