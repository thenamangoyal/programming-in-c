#include <stdio.h>
#include <stdlib.h>

// Counter for recursive calls
int calls =0;

// Prototyping all functions
void merge_sort(char *A[],int l, int r);
void merg(char *A[], int l, int r,int mid);
int strcomp(char *s, char *t);
int ocheck(char s, char t);

int main(int argc, char *argv[])
{

    int i;
    merge_sort(argv,1,argc-1);
    for(i=1; i<argc; i++)
    {
      printf("%s\n",*(argv+i));
    }
    printf("%d\n",calls);
    return 0;
}



void merge_sort(char *A[],int l, int r)
{

    if (r - l < 1)
    {
        return;
    }
    int mid = l + (r-l)/2;
    calls++;
    merge_sort(A,l,mid);
    calls++;
    merge_sort(A,mid+1,r);
    merg(A,l,r,mid);
}

void merg(char *A[], int l, int r,int mid)
{
    int nl = mid - l +1;
    int nr = r - mid;
    char *left[nl];
    char *right[nr];
    int k;
    for (k=l; k<mid+1; k++)
    {
      *(left+(k-l)) = *(A+k);
    }

    for (k=mid+1; k<r+1; k++)
    {
      *(right+(k-mid-1)) = *(A+k);
    }
    k=l;
    int i=0;
    int j=0;
    while(i < nl && j < nr)
    {
      if (strcomp(*(left+i),*(right+j)) <= 0)
        {
	  *(A+k) = *(left+i);
	  i++;
	  k++;
        }
        else
        {
	  *(A+k) = *(right+j);
	    j++;
	    k++;
        }
    }

    while(i < nl)
    {
      *(A+k) = *(left+i);
      i++;
      k++;
    }
    while(j < nr)
    {
      *(A+k) = *(right+j);
      j++;
      k++;
    }

}


int ocheck(char s, char t)
{
  if (s=='\0' && t== '\0'){
    return 0;
  }
  else if (s=='\0' && t!='\0'){
    return -1;
  }
  else if (s!='\0' && t=='\0'){
    return 1;
  }  
  else if (s!='\0' && t!='\0'){

  char order[]=" abcdefghijklmnopqrstuvwxyz0123456789";
    
    int i=0, j=0;

    for (i=0; *(order+i)!=s && *(order+i) != '\0'; i++);
    for (j=0; *(order+j)!=t && *(order+j) != '\0'; j++);

    if (i>j)
    {
        return 1;
    }
    else if (i<j)
    {
        return -1;
    }
    else
    {
        return 0;
    }
  }

}

int strcomp(char *s, char *t)
{
    while(*s==*t)
    {
        if (*s=='\0')
        {
            return 0;
        }
        s++;
        t++;
    }
    return ocheck(*s,*t);
}

