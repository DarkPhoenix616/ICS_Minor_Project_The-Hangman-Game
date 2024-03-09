#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

int lives=3;
int num_of_correct_guesses;

int return_current_status(char guessed_string[],char *current_status[],char selected_word[],int length);
void print_current_status(char *current_status[],int length);
int final_string(char *current_status[],int length);

int main()
{
    srand(time(0));
    char data[][100]={"You live only once",
                      "The greatest decisions require the strongest wills",
                      "I am batman",
                      "What is hate, if not love perservering",
                      "Practice makes a man perfect",
                      "I am iron man",
                      "Danie",
                      "Caleb"};
    int n=8;
    int selected_index=rand() % n;  //Selecting a random index
    
    
     int length=strlen(data[selected_index]);  //length of the selected word
     char selected_word[length];
     strcpy(selected_word,data[selected_index]);  

     char guessed_string[length]; 
    //  for(int i=0;i<length;i++)
    //   guessed_string[i]='0';

     char *current_status[length];

    for(int i=0;i<length;i++)
     current_status[i]=(char*)malloc(sizeof(char));
     int spaces=0;  //To find the number of spaces

    for(int i=0;i<length;i++)
    {
        if(selected_word[i]==' ')
        {
            *current_status[i]=' ';
            spaces++;
        }
        else 
         *current_status[i]='0';
    }

    int exit=0;//To check if the whole string is correct
     

     num_of_correct_guesses=0;

     while(num_of_correct_guesses<(length-spaces) && lives>0)
      {
        


        printf("\n**************************\n");
        print_current_status(current_status,length);
        printf("Enter a letter or directly predict the sentence!!\nDO NOT REPEAT THE LETTERS ALREADY TYPED!!\nNumber of lives:%d\n",lives);
        
         scanf("%s",guessed_string);
         
         
        int status=return_current_status(guessed_string,current_status,selected_word,length);
        if(status==1)
         {
            printf("Correct");
            if(num_of_correct_guesses==length-spaces)
            {
               printf("\n**************************\n");
               printf("\nCongrats!! You have predicted successfully!!\n");
               return_current_status(guessed_string,current_status,selected_word,length);
               print_current_status(current_status,length);
               break;
            }
             
         }
        else if(status==0)
         printf("WRONG GUESS\n");

        else if(status==2)  //Correctly guessed the word
        {
            printf("\n**************************\n");
               printf("\nCongrats!! You have predicted successfully!!\n");
               return_current_status(guessed_string,current_status,selected_word,length);
               print_current_status(current_status,length);
               break;

        }
        else if(status==3)
         printf("You lose a life!!\n");
        

      
      if(lives==0)
       printf("You lose Bro!");
       
       printf("\n********************\n");
      }
     

     
    for(int i=0;i<length;i++)
     free(current_status[i]);
    
    
    

    return 0;
}
int return_current_status(char guessed_string[],char *current_status[],char selected_word[],int length)
{
    int status=0;
    if(guessed_string[1]==0)     //If a single letter was input by the user
    {
        for(int i=0;i<length;i++)
      {
        if(selected_word[i]==guessed_string[0])
        {
           *current_status[i]=guessed_string[0];
           status=1;
           num_of_correct_guesses++;
           //printf("Number of correct guesses:%d\n",num_of_correct_guesses);
        }
      }
   }

   else           //If the user directly wants to predict the word
   {
    if(strcmp(guessed_string,selected_word)==0)
    {
        for(int i=0;i<length;i++)
         *current_status[i]=guessed_string[i];
        return 2;
    }
    else
     {
        lives--;
        return 3;
        }

   }



   if(status==1)
    return 1;
   else 
    return 0;


   
}
void print_current_status(char *current_status[],int length)
{
    for(int i=0;i<length;i++)
    {
        if(*current_status[i]==' ')
         printf("\n");
        else if(*current_status[i]=='0')
         printf("_ ");
        else
        printf("%c",*current_status[i]);
    }
    printf("\n");
}
