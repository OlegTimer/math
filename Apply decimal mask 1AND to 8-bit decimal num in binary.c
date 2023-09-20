#include <stdio.h>
#define NUMSIZE  8

int main()
{	
int i,n,m;
printf("_ Apply decimal mask 1AND (1&) to 8-bit decimal num in binary _\n\n");
printf("Enter decimal num:  ");
scanf("%d",&n);
printf("Enter decimal mask: ");
scanf("%d",&m);

printf("\n\nIn binary:\n");
printf("Num:  ");
for(i=NUMSIZE;i>=0;i--) { printf("%d",(n>>i)&1); }
printf("\n");
printf("Mask: ");
for(i=NUMSIZE;i>=0;i--) { printf("%d",(m>>i)&1); }
printf("\n");
printf("Res:  ");
for(i=NUMSIZE;i>=0;i--) { printf("%d",((n&m)>>i)&1); }

printf("\n\nby OlegTim     ");
system("pause");
return 0;
}
