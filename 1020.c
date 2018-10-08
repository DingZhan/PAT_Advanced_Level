#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 31
typedef struct Node_
{
    int value;
    struct Node_ *left;
    struct Node_ *right;
}Node;

void BuildTree(int *post, int *in, int N, Node **root)
{
    if(N==0)
        return;
    int pos, i;
    for(i=0; i<N; ++i)
    {
        if(post[N-1]==in[i])
        {
            pos = i;
            break;
        }
    }
    (*root) = (Node*)malloc(sizeof(Node));
    (*root)->value = post[N-1];
    (*root)->left = NULL;
    (*root)->right = NULL;
    BuildTree(post, in, pos, &((*root)->left));
    BuildTree(post+pos, in+pos+1, N-pos-1, &((*root)->right));
}

void LevelVisit(Node *root)
{
    Node *queue[MAX_N], *seed;
    int front=0, rear = 0, bFirst=1;
    queue[rear++] = root;
    while(front!=rear)
    {
        seed = queue[front++];
        if(!bFirst)
            printf(" ");
        printf("%d", seed->value);
        bFirst = 0;
        if(seed->left)
            queue[rear++] = seed->left;
        if(seed->right)
            queue[rear++] = seed->right;
    }

}
int main()
{
    int post[MAX_N], in[MAX_N], N, i;
    Node *root=NULL;
    scanf("%d", &N);
    for(i=0; i<N; ++i)
        scanf("%d", post+i);
    for(i=0; i<N; ++i)
        scanf("%d", in+i);
    BuildTree(post, in, N, &root);
    LevelVisit(root);
    return 0;
}
