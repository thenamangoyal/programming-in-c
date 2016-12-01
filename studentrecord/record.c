#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student
{
  int entry;
  char *name;
  char *mobile;
  double percentage;
  struct student* next;
};

struct student* head;
int lastentry = 0;

void operat(char *Argument);

struct student* find(int entry);
void search(int entry);
void insert(char* name, char* mobile, double percentage);
void delet(int entry);
void modify(int entry, char* name, char* mobile, double percentage);
void print(struct student* student1);
void show();

int getword(char *Argument, char *word, int *lengthread);
char *stringduplicate(char *word);

int checkOperation(char *word);
int checkEntryNo(char *word);
int checkName(char *word);
int checkMobile(char *word);
int checkPercentage(char *word);

int convertEntryNo(char *word);
double convertPercentage (char *word);


int main(int argc, char *argv[])
{
  head = NULL;

  int i;
  for(i=1;i<argc;i++){
    operat(argv[i]);
  }



  return 0;
}

/*The main operation function*/
void operat(char *Argument)
{

  int lengthread = 0;
  char word[strlen(Argument)+1];

  getword( Argument, word, &lengthread);

  int correct = 0;
  int operation;

  operation = checkOperation(word);



  if (operation == 1)
    {

      if (getword( Argument, word, &lengthread) > 0)
        {
	  if (checkEntryNo(word)==1)
            {
	      int entry;
	      entry = convertEntryNo(word);
	      if (getword( Argument, word, &lengthread) == 0)
                {
		  correct = 1;
		  search(entry);
                }

            }

        }



    }
  else if (operation == 2)
    {

      if (getword( Argument, word, &lengthread) > 0)
        {
	  if (checkName(word)==1)
            {
                
	      char *name = stringduplicate(word);
	      if (getword( Argument, word, &lengthread) > 0)
                {
		  if (checkMobile(word)==1)
                    {
		      char *mobile = stringduplicate(word);
		      if (getword( Argument, word, &lengthread) > 0)
                        {
			  if (checkPercentage(word)==1)
                            {
			      double percentage;
			      percentage = convertPercentage(word);

			      if (getword( Argument, word, &lengthread) == 0)
                                {
				  correct = 1;
				  insert(name,mobile,percentage);
                                }

                            }
                        }
                    }
                }

            }

        }
    }
  else if (operation == 3)
    {

      if (getword( Argument, word, &lengthread) > 0)
        {
	  if (checkEntryNo(word)==1)
            {
	      int entry;
	      entry = convertEntryNo(word);
	      if (getword( Argument, word, &lengthread) == 0)
                {
		  correct = 1;
		  delet(entry);
                }

            }

        }
    }
  else if (operation == 4)
    {

      if (getword( Argument, word, &lengthread) > 0)
        {
	  if (checkEntryNo(word)==1)
            {

	      int entry;
	      entry = convertEntryNo(word);
	      if (getword( Argument, word, &lengthread) > 0)
                {
		  if (checkName(word)==1)
                    {
		      char *name= stringduplicate(word);
		      if (getword( Argument, word, &lengthread) > 0)
                        {
			  if (checkMobile(word)==1)
                            {
			      char *mobile = stringduplicate(word);
			      if (getword( Argument, word, &lengthread) > 0)
                                {
				  if (checkPercentage(word)==1)
                                    {
				      double percentage;
				      percentage = convertPercentage(word);

				      if (getword( Argument, word, &lengthread) == 0)
                                        {
					  correct = 1;
					  modify(entry,name,mobile,percentage);
                                        }

                                    }
                                }
                            }
                        }

                    }

                }
            }
        }
    }
  else if (operation == 5)
    {

      if (getword( Argument, word, &lengthread) == 0)
	{
	  correct = 1;
	  show();
	}

    }

  if(correct != 1)
    {
      printf("OPERATION CANNOT BE PERFORMED\n");
    }

}


/* Functions related to structures */

struct student* find(int entry)
{

  struct student* student1 = head;
  while (student1 != NULL)
    {
      if (student1->entry == entry)
        {
	  return student1;
        }
      student1 = student1->next;
    }

  return NULL;


}

void search(int entry)
{
  struct student* student1 = find(entry);
  if (student1 != NULL)
    {
      print(student1);
    }
  else
    {
      printf("NO SUCH RECORD FOUND.\n");
    }
}

void insert(char* name, char* mobile, double percentage)
{
  struct student* student1 = (struct student*)malloc(sizeof(struct student));
  student1->entry = ++lastentry;
  student1->name= name;
  student1->mobile = mobile;
  student1->percentage = percentage;
  student1->next = NULL;

  if (head == NULL)
    {
      head = student1;
    }
  else
    {
      struct student* student2 = head;

      while(student2->next != NULL)
        {
	  student2 = student2->next;
        }

      student2->next = student1;
    }
  printf("RECORD ADDED SUCCESSFULLY.\n");
}


void delet(int entry)
{

  struct student* student1 = find(entry);
  if (student1 != NULL)
    {
      if (student1==head)
        {
	  head = student1->next;
	  free(student1);

        }
      else
        {
	  struct student* student0 = head;
	  while ((student0->next)!=student1)
            {
	      student0 = student0->next;
            }
	  student0->next = student1->next;
	  free(student1);

        }
      printf("RECORD DELETED SUCCESSFULLY.\n");
    }
  else
    {
      printf("NO SUCH RECORD FOUND.\n");
    }
}

void modify(int entry, char* name, char* mobile, double percentage)
{
  struct student* student1 = find(entry);
  if (student1 != NULL)
    {
      student1->name = name;
      student1->mobile = mobile;
      student1->percentage = percentage;
      printf("RECORD MODIFIED SUCCESSFULLY.\n");
    }
  else{
    printf("NO SUCH RECORD FOUND.\n");
  }
}


void print(struct student* student1)
{
  if (student1==NULL)
    {
      return;
    }
  printf("| %d | %s | %s | %.1f |", student1->entry,student1->name,student1->mobile,student1->percentage);
  printf("\n");
}

void show()
{
  if (head!=NULL){


    struct student* student1 = head;

    while(student1 != NULL)
      {
        print(student1);
        student1 = student1->next;
      }

  }
  else{
    printf("NO RECORDS.\n");
  }
}

/* All functions related to extracting input*/


int getword(char *Argument, char *word, int *lengthread)
{
  int count;
  while(*(Argument + *lengthread) == ' ' || *(Argument + *lengthread) == '\n')
    {
      (*lengthread)++;
    };

  for(count=0; *(Argument + *lengthread) != ' ' && *(Argument + *lengthread) !=  '\n' && *(Argument + *lengthread) != '\0' && *(Argument + *lengthread) != EOF; word++)
    {
      *word = *(Argument + *lengthread);
      count++;
      (*lengthread)++;
    }
  *word = '\0';
  return count;
}

char *stringduplicate(char *word){
  char *dup = (char*)malloc(strlen(word)+1);
  if (dup!=NULL){
    strcpy(dup,word);
  }
  return dup;

}

int checkOperation(char *word)
{

  char *p;
  p = word;
  for(; *p!='\0'; p++)
    {
      if (!(*p - '0' >= 0 && *p -  '0' <= 9))
        {
	  return 0;
        }
    }
  int operation;
  for (operation =0; *word != '\0'; word++)
    {
      operation  = 10*operation + (*word - '0');
    }
  return operation;
}

int checkEntryNo(char *word)
{

  for(; *word!='\0'; word++)
    {
      if (!(*word - '0' >= 0 && *word -  '0' <= 9))
        {
	  return 0;
        }
    }

  return 1;
}

int checkName(char *word)
{

  for(; *word!='\0'; word++)
    {
      if ((*word >= 'a' && *word <= 'z') || (*word >= 'A' && *word <= 'Z'))
	;
      else
        {
	  return 0;
        }
    }

  return 1;
}

int checkMobile(char *word)
{

  for(; *word!='\0'; word++)
    {
      if ((*word >= '0') && (*word <= '9'))
	;
      else
        {
	  return 0;
        }
    }

  return 1;
}

int checkPercentage(char *word)
{
  if (*word == '-')
    {
      word++;
    }
  else if (*word == '+')
    {
      word++;
    }

  for (; *word >= '0' && *word <= '9'; word++);
  if (*word == '.')
    {
      word++;
    }
  else if (*word == '\0')
    {
      return 1;
    }
  else
    {
      return 0;
    }

  for (; *word >= '0' && *word <= '9'; word++);

  if (*word == '\0')
    {
      return 1;
    }
  else
    {
      return 0;
    }


}

int convertEntryNo(char *word)
{
  int entry;

  for (entry =0; *word != '\0'; word++)
    {
      entry  = 10*entry + (*word - '0');
    }
  return entry;
}

double convertPercentage(char *word)
{
  double percentage;
  percentage = 0.0;
  int sign = 1;

  if (*word == '-')
    {
      sign = -1;
      word++;
    }
  else if (*word == '+')
    {
      sign = 1;
      word++;
    }

  for (; *word >= '0' && *word <= '9'; word++)
    {
      percentage = percentage*(10.0) + (double)(*word -'0');
    }
  double power = 1.0;
  if (*word == '.')
    {
      word++;

    }


  for (; *word >= '0' && *word <= '9'; word++)
    {
      percentage = percentage*(10.0) + (double)(*word -'0');
      power = power*(10.0);
    }

  percentage = percentage/power;

  percentage = percentage*(double)sign;

  if (*word == '\0')
    {
      return percentage;
    }

}
