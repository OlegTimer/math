int num[10] = {1, 3, 6, 5, 8, 7, 9, 6, 2, 0};

int main(void)
{
  int i;

   printf("__ Quicksort Hoare ___ \n\n");
  printf(" Arr:        ");
  for(i=0; i<10; i++) printf("%d ", num[i]);
  void qs(int *num, int left, int right);
  qs(num, 0, 9);
  printf("\n Sorted arr: ");
  for(i=0; i<10; i++) printf("%d ", num[i]);
 printf("\n"); system("pause");
  return 0;
}



void qs(int *num, int left, int right)
{
  register int i, j;
  int x, y;

  i = left; j = right;
  x = num[(left+right)/2]; /* comparand select */

  do {
    while((num[i] < x) && (i < right)) i++;
    while((x < num[j]) && (j > left)) j--;

    if(i <= j) {
      y = num[i];
      num[i] = num[j];
      num[j] = y;
      i++; j--;
    }
  } while(i <= j);

  if(left < j) qs(num, left, j);
  if(i < right) qs(num, i, right);
}
