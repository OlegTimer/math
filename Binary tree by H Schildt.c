#include <stdlib.h>
#include <stdio.h>

struct tree {
  char info;
  struct tree *left;
  struct tree *right;
};

struct tree *root; /* root */
struct tree *stree(struct tree *root,
                   struct tree *r, char info);
void print_tree(struct tree *root, int l);

int main(void)
{
printf("__ Binary tree by H Schildt __\n\n"); 	
  char s[80];
  root = NULL;  /* root init */
int stop =1;
  do {
    printf("Enter char (or -1 to draw tree): ");
    gets(s);
   stop  =atoi(s);
    root = stree(root, root, *s);
  } while(stop!=-1);

print_tree(root, 0);

printf("\n"); system("pause");
  return 0;
}

struct tree *stree(
  struct tree *root,
  struct tree *r,
  char info)
{

  if(!r) {
    r = (struct tree *) malloc(sizeof(struct tree));
    if(!r) {
      printf("Err mem\n");
      exit(0);
    }
    r->left = NULL;
    r->right = NULL;
    r->info = info;
    if(!root) return r; /* first entry */
    if(info < root->info) root->left = r;
    else root->right = r;
    return r;
  }

  if(info < r->info)
    stree(r, r->left, info);
  else
    stree(r, r->right, info);

  return root;
}


void print_tree(struct tree *r, int l)
{
  int i;

  if(r == NULL) return;

 print_tree(r->right, l+1);
  for(i=0; i<l; ++i) printf(" ");
  printf("%c\n", r->info);
  print_tree(r->left, l+1);
}
