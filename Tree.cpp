#include <iostream>
#include <stdlib.h>

struct Node{
    int data;
    Node *left;
    Node *right;

};
Node *root = NULL;

Node* insert(int value,Node *curr){

    if(curr==NULL){
        Node *temp = (Node *)malloc(sizeof(Node));
        temp->data = value;
        temp->left = NULL;
        temp->right = NULL;
        return temp;

    }
    if(value>curr->data){
        curr->right = insert(value,curr->right);
    } else {
        curr->left = insert(value,curr->left);
    }
    return curr;
}
Node* search(int value, Node*curr){
    if(curr==NULL){
        std::cout << "TREE NOT INITIALIZED!!\n";
        return NULL;
    }
        if(value==curr->data){
            std::cout << "Value Fouund at; "<< curr << "\n";
            return curr;
        }
        if(value > curr->data){
            curr->right = search(value, curr->right);
       } else {
          curr->left = search(value, curr->left);
       }
    return curr;
}
void inOrder(Node *curr){

    if(curr!=NULL){
        
        inOrder(curr->left);
        std::cout << curr->data << " ";
        inOrder(curr->right);
    }
}
void preOrder(Node *curr){

    if(curr!=NULL){
        
        std::cout << curr->data << " ";
        preOrder(curr->left);
        preOrder(curr->right);
    }
}
void postOrder(Node *curr){

    if(curr!=NULL){
        
        postOrder(curr->left);
        postOrder(curr->right);
        std::cout << curr->data << " ";

    }
}
Node *Delete(int value,Node *curr){
    if(curr==NULL){
        std::cout << "TREE NOT INITIALIZED!!\n";
        return NULL;
    }
    if(value==curr->data){
        std::cout << "Found\n";

        // case 1:only child
        if(curr->left==NULL && curr->right==NULL){
            free(curr);
            return NULL;
        }
        // case 2: only 1 child
        else if(curr->left!=NULL && curr->right==NULL){
            Node *temp = curr->left;
            //curr->right = Delete(value,curr->right);
            free(curr);
            return temp;
        }
        // case 3: only right child
        else if(curr->left==NULL && curr->right!=NULL) {
            Node *temp = curr->right;
            //curr->left = Delete(value,curr->left);
            free(curr);
            return temp;
       }
        // case 4:Both child
        else {
            Node *temp = curr->right;
            while(temp->left!=NULL){
            temp = temp->left;
        }
            curr->data = temp->data;
            curr->right = Delete(temp->data,curr->right);
            return curr;
    }     
}
     if(value>curr->data){
        curr->right = Delete(value,curr->right);
    } else {
        curr->left = Delete(value,curr->left);
    }
    return curr;
}
int main(){

    while(true){
        std::cout << "\nSelect 1 to insert: \n";
        std::cout << "Select 2 to search: \n";
        std::cout << "Select 3 to Delete: \n";
        std::cout << "Select 4 to Display(InOrerTraversal): \n";
        std::cout << "Select 5 to Display(PreOrerTraversal): \n";
        std::cout << "Select 6 to Display(PostOrerTraversal): \n";
        std::cout << "Select 7 to Exit: \n";

        int choice;
        std::cout << "Enter your Choice: ";
        std::cin >> choice;

        switch(choice){
            case 1:{int data;
                std::cout << "Enter the value: ";
                std::cin >> data;
                root = insert(data,root);
                break;
            }
            case 2:{int data;
                std::cout << "Enter the value: ";
                std::cin >> data;
                root = search(data,root);
                break;
            }
            case 3:{int data;
                std::cout << "Enter the value: ";
                std::cin >> data;
                root = Delete(data,root);
                break;
            }
            case 4: inOrder(root);
            break;
            case 5: preOrder(root);
            break;
            case 6: postOrder(root);
            break;
            case 7: std::cout << "EXITING!!\n";
            break;
            default: std::cout << "INVALID CHOICE11\n";
        }
        if(choice==7) break;
    }
    return 0;
}
