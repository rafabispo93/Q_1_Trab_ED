/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this auxlate file, choose Tools | auxlates
 * and open the auxlate in the editor.
 */

/*
 * File:   main.c
 * Author: rafael
 *
 * Created on 24 de Abril de 2017, 13:44
 */


#include<stdio.h>
#include <stdlib.h>
#include<ctype.h>

#define size 40

typedef struct node {
    char value;

    struct node *left;

    struct node *right;

}

tree;
			/*Armazena os elementos da arvore em uma pilha*/
tree *stack[size];

int top;

void main() {

    tree *root;

    char notation[80];
                    /*notation armazena a expressao*/

    tree *create(char notation[150]);

    void inorder(tree *root);

    void preorder(tree *root);

    void postorder(tree *root);


    printf("\n Entre com uma expressao polonesa reversa :\n");

    scanf("%99[^\n]",notation);

    top=-1;			/*inicializa pilha*/

    root=create(notation);

    printf("\n Arvore Criada.....\n");

    printf("\n Em Ordem: \n");

    inorder(root);

    printf("\n Pre-Ordem: \n");

    preorder(root);

    printf("\n Pos-Ordem: \n");

    postorder(root);
}

tree *create(char notation[]) {

    tree *aux;

    int pos;

    char element;

    void push(tree*);

    tree *pop();

    pos=0;

    element=notation[pos];

    while(element!=NULL) {
                                /*cria um no*/

        aux=((tree*)malloc(sizeof(tree)));

        aux->left=aux->right=NULL;

        aux->value=element;

        if(isalpha(element) || isdigit(element)) {
            push(aux);
        }
        else if(element=='+' ||element=='-' || element=='*' || element=='/' || element=='^') {
            aux->right=pop();

            aux->left=pop();

            push(aux);

        }
         else {
            printf("\n Caracter invalido\n");
         }
        pos++;

        element=notation[pos];

    }

     aux=pop();

    return(aux);

}

void push(tree *Node) {

    if(top+1 >= size)
        printf("Pilha Cheia\n");

    top++;

    stack[top]=Node;

}

tree* pop() {

    tree *Node;

    if(top==-1)

    printf("\nPilha Vazia..\n");

    Node =stack[top];

    top--;

    return(Node);

}


void inorder(tree *root) {

    tree *aux;

    aux=root;

    if(aux!=NULL) {
        inorder(aux->left);

        printf("%c",aux->value);

        inorder(aux->right);

    }
}

void preorder(tree *root) {

    tree *aux;

    aux=root;

    if(aux!=NULL) {

        printf("%c",aux->value);

        preorder(aux->left);

        preorder(aux->right);

    }
}

void postorder(tree *root) {

    tree *aux;

    aux=root;

    if(aux!=NULL) {
        postorder(aux->left);

        postorder(aux->right);

        printf("%c",aux->value);

    }
}
