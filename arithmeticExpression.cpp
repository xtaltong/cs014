#include "arithmeticExpression.h"

using namespace std;

arithmeticExpression::arithmeticExpression(const string & infix_string) {
    root = 0;
	infixExpression = infix_string;
}

void arithmeticExpression::buildTree() {
    string postfix_expression;
    postfix_expression = infix_to_postfix();

    char key_to_insert = 'a';

    stack<TreeNode*> tree_stack;

    for(unsigned x = 0; x < postfix_expression.size(); ++x){
        TreeNode * new_node = new TreeNode(postfix_expression.at(x),key_to_insert++);
        if (postfix_expression.at(x) == '/' || postfix_expression.at(x) == '+' ||
             postfix_expression.at(x) == '-' || postfix_expression.at(x) == '*') {
            new_node->right = tree_stack.top();
            tree_stack.pop();
            new_node->left = tree_stack.top();
            tree_stack.pop();

            tree_stack.push(new_node);
        }
        else {
            tree_stack.push(new_node);
        }
    }
   root = tree_stack.top();
}

void arithmeticExpression::infix() {
    infix(root); 
}

void arithmeticExpression::prefix() {
    prefix(root);
}

void arithmeticExpression::postfix() {
    postfix(root);
}

void arithmeticExpression::visualizeTree(const string & outputFilename) {
    ofstream outFS(outputFilename.c_str());
    if(!outFS.is_open()){
        cout<<"Error opening "<< outputFilename<<endl;
        return;
    }
    outFS << "digraph G {"<< endl;
    visualizeTree(outFS, root);
    outFS << "}";
    outFS.close();
    string jpgFilename = outputFilename.substr(0,outputFilename.size()-4)+".jpg";
    string command = "dot -Tjpg " + outputFilename + " -o " + jpgFilename;
    system(command.c_str());
}

int arithmeticExpression::priority(char op) {
    int priority = 0;
    if(op == '('){
        priority =  3;
    }
    else if(op == '*' || op == '/'){
        priority = 2;
    }
    else if(op == '+' || op == '-'){
        priority = 1;
    }
    return priority;
}

string arithmeticExpression::infix_to_postfix() {
    stack<char> s;
    ostringstream oss;
    char c;
    for(unsigned i = 0; i< infixExpression.size();++i){
        c = infixExpression.at(i);
        if(c == ' '){
            continue;
        }
        if(c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')'){ //c is an operator
            if( c == '('){
                s.push(c);
            }
            else if(c == ')'){
                while(s.top() != '('){
                    oss << s.top();
                    s.pop();
                }
                s.pop();
            }
            else{
                while(!s.empty() && priority(c) <= priority(s.top())){
                    if(s.top() == '('){
                        break;
                    }
                    oss << s.top();
                    s.pop();
                }
                s.push(c);
            }
        }
        else{ //c is an operand
            oss << c;
        }
    }
    while(!s.empty()){
        oss << s.top();
        s.pop();
    }
    return oss.str();
}

void arithmeticExpression::infix(TreeNode * node) {
    if(node) {
        if(node->left) {
        cout << "(";
        }
        infix(node->left);
        cout << node->data;
        infix(node->right);
        if(node->right) {
            cout << ")";
        } 
    }
}

void arithmeticExpression::prefix(TreeNode * node) {
    if(node) {
        cout << node->data;
        prefix(node->left);
        prefix(node->right);
    }
}

void arithmeticExpression::postfix(TreeNode * node) {
    if(node) {
        postfix(node->left);
        postfix(node->right);
        cout << node->data;
    }
}

void arithmeticExpression::visualizeTree(ofstream & out, TreeNode * node) {
    out << node->key << "[label=\"" << node->data << "\"];";
    if(!node) {
        return;
    }
    if(node->left) {
        out << node->key << " -> " << node->left->key << ";" << endl;
        visualizeTree(out, node->left);
    }
    
    if(node->right) {
        out << node->key << " -> " << node->right->key << ";" << endl;
        visualizeTree(out, node->right);
    }
}
