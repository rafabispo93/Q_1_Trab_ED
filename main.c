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
#include <string.h>

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
char newNotation[20];
int newCount = 0;

int numbers[20];
char operators[20];
int top2 = 0;
int top3 = 0;
int results[20];
int topR = 0;
int result = 0;

void main() {

    tree *root;

    char notation[80];
                    /*notation armazena a expressao*/

    tree *create(char notation[80]);

    void inorder(tree *root);

    void preorder(tree *root);

    void postorder(tree *root);


    printf("\n Entre com uma expressao polonesa reversa :\n");

    scanf("%99[^\n]",notation);
    printf("%s", &notation);

    top=-1;			/*inicializa pilha*/

    root=create(notation);

    printf("\n Arvore Criada.....\n");

    printf("\n Em Ordem: \n");

    inorder(root);

    printf("\n Pre-Ordem: \n");

    preorder(root);

    printf("\n Pos-Ordem: \n");

    postorder(root); 
    
    int h = calcHeight(root);
    printf("\n Altura: \n%d", h);
    calcPol();
//    buscar(root);

   
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

        aux->left= NULL;
        aux->right=NULL;

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

    if(top+1 >= size) {
        
        printf("Pilha Cheia\n");
    
    }
    else {
        top++;
        stack[top]=Node;
    }
    

}

tree* pop() {

    tree *Node;

    if(top==-1) {
        printf("\nPilha Vazia..\n");
    }
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
        newNotation[newCount] = aux->value;
        newCount++;

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

int calcHeight(tree *root) {
    if (root == NULL) {
        return -1;
    }

    int left = calcHeight(root->left);
    int right = calcHeight(root->right);

    if (left > right) {
        return left + 1;
    } else {
        return right + 1;
    }
}
buscar (tree *r) {
    struct node *busca;
    busca = ((tree*)malloc(sizeof(tree)));
    busca = r;
    while (busca != NULL) {
        printf("\n%c", busca->value);
        printf("\n%c", busca->right->value);
        printf("\n%c", busca->left->value);
        busca =  busca->right;
    }
    while (busca != NULL) {
        printf("\n%c", busca->value);
        printf("\n%c", busca->right->value);
        printf("\n%c", busca->left->value);
        busca =  busca->left;
    }
}

int calcPol () {
    printf("\n Calculo da expressao Polonesa Reversa: \n");
    
    
    for(int t = 0; t < newCount; t++) {
//        printf("%c \n",newNotation[t]);
//        printf("%d \n",newNotation[t] - '0');
        if (isdigit(newNotation[t])) {
            
            numbers[top2] = newNotation[t] - '0';
//            printf("AQUI %d\n",numbers[top2]);
            top2++;
        } else {
            
              operators[top3] = newNotation[t];
              top3++;            
        }
        
        
        
    }
    for (int as = top3; as >= 0; as--){
        if(top2 >=0){
//            printf("%c OPERADOR\n",operators[as]);
                if(operators[as] == '+') {
                    result = numbers[top2 - 2] + numbers[top2 -1];
                    results[topR] =numbers[top2 - 2] + numbers[top2 -1];
                    topR++;
                    top2--;
                    top2--;
                } if (operators[as] == '-') {
                    result = numbers[top2 - 2] - numbers[top2 -1];
                    results[topR] =numbers[top2 - 2] - numbers[top2 -1];
                    topR++;
                    top2--;
                    top2--;
                } else if (operators[as] == '*') {
                    result = numbers[top2 - 2] * numbers[top2 -1];
                    results[topR] =numbers[top2 - 2] * numbers[top2 -1];
                    topR++;
                    top2--;
                    top2--;
                } else if (operators[as] == '/') {
                    result = numbers[top2 - 2] / numbers[top2 -1];
                    results[topR] =numbers[top2 - 2] / numbers[top2 -1];
                    topR++;
                    top2--;
                    top2--;
                }
                    
            
        } else {
//            printf("%d VAlor top2\n", top2);
            if(operators[as] == '+') {
                printf("ENTROU no else +\n");
                result = results[topR - 2] + results[topR - 1];
                printf("%d\n", result);
                topR--;
                topR--;
            } else if (operators[as] == '-') {
                printf("ENTROU no else -\n");
                result = results[topR - 2] - results[topR - 1];
                printf("%d\n", result);
                topR--;
                topR--;
            } else if (operators[as] == '*') {
                printf("ENTROU no else *\n");
                result = results[topR - 2] * results[topR - 1];
                printf("%d\n", result);
                topR--;
                topR--;
            } else if (operators[as] == '/') {
                printf("ENTROU no else / \n");
                result = results[topR - 2] / results[topR - 1];
                printf("%d\n", result);
                topR--;
                topR--;
            }

        }              
    }
    printf("%d", result);
    return result;
}