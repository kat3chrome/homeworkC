#include <stdlib.h>
#include <stdio.h>
#include "set.h"

typedef struct Node Node;

struct Set
{
    Node* root;
};

struct Node
{
    int value;
    int height;
    Node* leftChild;
    Node* rightChild;
};

int getHeightOfCurrentNode(Node* node)
{
    return node != NULL ? node->height : -1;
}

int getBalanceFactorOfCurrentNode(Node* node)
{
    return getHeightOfCurrentNode(node->rightChild) - getHeightOfCurrentNode(node->leftChild);
}

int max(int firstValue, int secondValue)
{
    return firstValue > secondValue ? firstValue : secondValue;
}

void updateHeight(Node* node)
{
    if (node == NULL)
    {
        return;
    }

    node->height = max(getHeightOfCurrentNode(node->leftChild), getHeightOfCurrentNode(node->rightChild)) + 1;
}

Set* createSet()
{
    Set* set = malloc(sizeof(Set));
    set->root = NULL;

    return set;
}

Node* createNode(int value)
{
    Node* element = malloc(sizeof(Node));
    element->value = value;
    element->height = 0;
    element->leftChild = NULL;
    element->rightChild = NULL;

    return element;
}

bool isInTheSet(int value, Set* set)
{
   if (set == NULL)
   {
       return false;
   }

    Node* current = set->root;
    while (current != NULL)
    {
        if (current->value > value)
        {
            current = current->leftChild;
        }
        else if (current->value < value)
        {
            current = current->rightChild;
        }
        else
        {
            return true;
        }
    }

    return false;
}

Node* rotateRight(Node* root)
{
    if (root == NULL)
    {
        return NULL;
    }

    Node* pivot = root->leftChild;
    root->leftChild = pivot->rightChild;
    pivot->rightChild = root;
    updateHeight(root);
    updateHeight(pivot);

    return pivot;
}

Node* rotateLeft(Node* root)
{
    if (root == NULL)
    {
        return NULL;
    }

    Node* pivot = root->rightChild;
    root->rightChild = pivot->leftChild;
    pivot->leftChild = root;
    updateHeight(root);
    updateHeight(pivot);

    return pivot;
}

Node* balance(Node* root)
{
    updateHeight(root);

    if (getBalanceFactorOfCurrentNode(root) == -2)
    {
        if (getBalanceFactorOfCurrentNode(root->leftChild) > 0)
        {
            root->leftChild = rotateLeft(root->leftChild);
        }

        return rotateRight(root);
    }

    if (getBalanceFactorOfCurrentNode(root) == 2)
    {
        if (getBalanceFactorOfCurrentNode(root->rightChild) < 0)
        {
            root->rightChild = rotateRight(root->rightChild);
        }

        return rotateLeft(root);
    }

    return root;
}

Node* addElementInSubtree(int value, Node* root)
{
    if (root == NULL)
    {
        return createNode(value);
    }

    if (value < root->value)
    {
        root->leftChild = addElementInSubtree(value, root->leftChild);
    }
    else if (value > root->value)
    {
        root->rightChild = addElementInSubtree(value, root->rightChild);
    }

    return balance(root);
}

void addElement(int value, Set* set)
{
    if (set == NULL)
    {
        return;
    }
    else if (!isInTheSet(value, set))
    {
        set->root = addElementInSubtree(value, set->root);
    }
}

Node* getMinimumNodeFromRightSubtree(Node* root)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->leftChild != NULL)
    {
        return getMinimumNodeFromRightSubtree(root->leftChild);
    }

    return root;
}

Node* removeMinimumNodeFromRightSubtree(Node* root)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->leftChild == NULL)
    {
        return root->rightChild;
    }

    root->leftChild = removeMinimumNodeFromRightSubtree(root->leftChild);
    return balance(root);
}

Node* removeElementFromSubtree(int value, Node* root)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (value < root->value)
    {
        root->leftChild = removeElementFromSubtree(value, root->leftChild);
    }
    else if (value > root->value)
    {
        root->rightChild = removeElementFromSubtree(value, root->rightChild);
    }
    else
    {
        Node* leftChild = root->leftChild;
        Node* rightChild = root->rightChild;

        if (rightChild == NULL)
        {
            free(root);
            return leftChild;
        }

        Node* minimum = getMinimumNodeFromRightSubtree(rightChild);
        minimum->rightChild = removeMinimumNodeFromRightSubtree(rightChild);
        minimum->leftChild = leftChild;
        free(root);
        return balance(minimum);
    }

    return balance(root);
}

void removeElement(int value, Set* set)
{
    if (set == NULL)
    {
        return;
    }
    else if (isInTheSet(value, set))
    {
        set->root = removeElementFromSubtree(value, set->root);
    }
}

void deleteSubtree(Node* root)
{
    if (root == NULL)
    {
        return;
    }

    deleteSubtree(root->leftChild);
    deleteSubtree(root->rightChild);
    free(root);
}

void removeSet(Set* set)
{
    if (set == NULL)
    {
        return;
    }

    deleteSubtree(set->root);
    free(set);
}

void printSubtreeInAscendingOrder(Node* root)
{
    if (root == NULL)
    {
        return;
    }

    if (root->leftChild == NULL && root->rightChild == NULL)
    {
        printf("%d ", root->value);
        return;
    }

    printSubtreeInAscendingOrder(root->leftChild);
    printf("%d ", root->value);
    printSubtreeInAscendingOrder(root->rightChild);
}

void printInAscendingOrder(Set* set)
{
    if (set == NULL)
    {
        return;
    }

    printSubtreeInAscendingOrder(set->root);
}

void printSubtreeInDescendingOrder(Node* root)
{
    if (root == NULL)
    {
        return;
    }

    if (root->leftChild == NULL && root->rightChild == NULL)
    {
        printf("%d ", root->value);
        return;
    }

    printSubtreeInDescendingOrder(root->rightChild);
    printf("%d ", root->value);
    printSubtreeInDescendingOrder(root->leftChild);
}

void printInDescendingOrder(Set* set)
{
    if (set == NULL)
    {
        return;
    }

    printSubtreeInDescendingOrder(set->root);
}

void printSubtree(Node* root)
{
    if (root == NULL)
    {
        printf("NULL ");
        return;
    }

    printf("( %d ", root->value);
    printSubtree(root->leftChild);
    printSubtree(root->rightChild);
    printf(") ");
}

void printSet(Set* set)
{
    if (set == NULL)
    {
        return;
    }

    printSubtree(set->root);
}