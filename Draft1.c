#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

int lives=8;
int num_of_correct_guesses;


int select_choice();
int return_current_status(char guessed_string[],char *current_status[],char selected_word[],int length);
void print_current_status(char *current_status[],int length);
void display_hangman(int result);
//int final_string(char *current_status[],int length);

int main()
{
    system("clear"); //To clear the terminal on Unix/Linux/Mac //Use: system("cls") for Windows
    srand(time(0));
    char data[][500]={"You couldn't live with your own failure, and where does that get you? Back to me",
                      "The hardest choices require the strongest wills",
                      "I am deadpool",
                      "What is hate, if not love persevering",
                      "I am iron man", //Marvel Quotes
                      "One small step for man, one giant leap for mankind",
                      "Be the change that you wish to see in the world",
                      "Live as if you were to die tomorrow. Learn as if you were to live forever",
                      "The future depends on what you do today",
                      "Dream, dream, dream. Dreams transform into thoughts and thoughts result in action", //Famous quotes
                      "Avengers",
                      "Joker",
                      "Interstellar",
                      "Avatar",
                      "The dark knight", //Famous movies
                      "Introduction to computer science",
                      "Introduction to electrical engineering",
                      "Introduction to bioengineering",
                      "Engineering realization",
                      "Mathematics" //Graded sem 2 Courses
                      };
    int n=23;
    int selected_index;
    printf("\n#*#*#*#*#*#*#*#*#*#*#*#*\n\n");
    display_hangman(lives);  //Displaying the podium for hanging
    //int selected_index=rand() % n;  //Selecting a random index
    int choice=select_choice();
    if(choice==1)
     selected_index=rand()%5;
    else if(choice==2)
     selected_index=rand()%5+5;
    else if(choice==3)
     selected_index=rand()%5+10;
    else if(choice==4)
     selected_index=rand()%5+15;
    else
     {
        printf("Wrong Choice");
        return 0;
        
     }
    
     int length=strlen(data[selected_index]);  //length of the selected word
     
     char selected_word[500];
     strcpy(selected_word,data[selected_index]);  
    
    int num,x=0;
    char player1[100],player2[100];
    printf("Enter the number of players: ");
    scanf("%d",&num);
    int life[num];
    
    while(x<num)
    {
        printf("\nPlayer%d\n",(x+1));
        lives=8;
        char guessed_string[length]; 

     char *current_status[length];

    for(int i=0;i<length;i++)      //Allocating memory to the current_status pointer
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
      fgetc(stdin);
     while(num_of_correct_guesses<(length-spaces) && lives>0)
      {
        
        display_hangman(lives);
        
        //printf("%d",length);
        printf("\n**************************\n");
        print_current_status(current_status,length);
        
        printf("Enter a letter or directly predict the sentence!!\n!!!DO NOT REPEAT THE LETTERS ALREADY TYPED!!! (Don't be a Dumbass)\nNumber of lives:%d\n",lives);
        
         //scanf("%s",guessed_string);
         //printf("What%s",selected_word);
          
         fgets(guessed_string,length+1,stdin);

         if(guessed_string[1]=='\n')
          guessed_string[1]=0;   //Zero can be inserted to a string to represent NULL
      
        
        if(strcmp("quit\n",guessed_string)==0)
        {
            printf("You Quit!!!\n");
            printf("The correct answer was: %s\n",selected_word);
            display_hangman(0);
            lives=0;
            break;
        }
         
        
        int status=return_current_status(guessed_string,current_status,selected_word,length);
        if(status==1)
         {
            printf("Correct");
            if(num_of_correct_guesses==length-spaces) //To check if the control has reached the end of the iteration
            {
               printf("\n**************************\n");
               printf("\nCongrats!! You have predicted successfully!!\n");
               return_current_status(guessed_string,current_status,selected_word,length);
               print_current_status(current_status,length);
               printf("\n********************\n");
               break;
            }
             
         }
        else if(status==0)   //letter we typed is not there in the string
         {
            printf("WRONG GUESS\nYou lose a life!!");
            lives--;
            }

        else if(status==2)  //Correctly guessed the Sentence
        {
            printf("\n**************************\n");
               printf("\nCongrats!! You have predicted successfully!!\n");
               return_current_status(guessed_string,current_status,selected_word,length);
               print_current_status(current_status,length);
            printf("\n********************\n");
               break;

        }
        else if(status==3)
         printf("You lose a life!!\n");
        

      
      if(lives==0)
      {
         printf("You lose because you ran out of lives\nThe correct answer was: %s\n",selected_word);
         display_hangman(lives);  //DEAD!!
      }
       
       
       printf("\n********************\n");

       
       if(status==3)     //If a wrong string was typed when we predicted the entire string, we get some extra characters in the input buffer
        {
            printf("You predicted the Wrong String!!! Click Enter to continue");
            while ((getchar()) != '\n');//In order to get rid of those characters
        }

       printf("\n********************\n");
      }
     

     
    for(int i=0;i<length;i++)  //Freeing the memory which was allocated to the current_status
     free(current_status[i]);
    
    
    printf("\nNumber of lives left: %d\n",lives);
    life[x]=lives;
     x++;

    }
    int dupe[num];
    for(int i=0;i<num;i++)
     dupe[i]=life[i];
    
    int winner,y,temp,z;
    for(int i=0;i<num;i++)
    {
        winner=life[i];
        for(int j=i+1;j<num;j++)
        {
           if(life[j]>winner)
           {
            winner=life[j];
            y=j;
           }

        }
        temp=life[i];
        life[i]=life[y];
        life[y]=temp;
        
    }
    printf("!! LEADERBOARD !!\n");
    for(int i=0;i<num;i++)
    {
        for(int j=0;j<num;j++)
        {
            if(life[i]==dupe[j])
            {
              z=j;
              break;
            }
        }
        printf("%d. Player%d Lives: %d\n",(i+1),z+1,life[i]);
    }

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
int select_choice()
{
    
    printf("\nWelcome to Danie's Hangman Game\n");
    printf("Choose a Category to play the Game.\n1. Marvel Quotes\n2. Famous Quotes\n3. Famous Movies\n4. Graded Sem 2 Courses\nChoice: ");
    int choice;
    scanf("%d",&choice);
    printf("\n#*#*#*#*#*#*#*#*#*#*#*#*\n");
    fgetc(stdin);  //To remove extra \n from the input stream which may mess with the code!!
    return choice;

}
void display_hangman(int result)   //Displaying the hanged man
{
    if(result==8)
     printf("   ___________________\n   |\n   |\n   |\n   |\n   |\n   |\n   |\n   |________________________");
    if(result==7)
     printf("   ___________________\n   |          |\n   |\n   |\n   |\n   |\n   |\n   |\n   |________________________");
    if(result==6)
     printf("   ___________________\n   |          |\n   |          |\n   |\n   |\n   |\n   |\n   |\n   |________________________"); 
    if(result==5)
     printf("   ___________________\n   |          |\n   |          |\n   |          O\n   |\n   |\n   |\n   |\n   |________________________"); 
    if(result==4)
     printf("   ___________________\n   |          |\n   |          |\n   |          O\n   |          |\n   |          |\n   |\n   |\n   |________________________"); 
    if(result==3)
     printf("   ___________________\n   |          |\n   |          |\n   |          O\n   |         /|\n   |          |\n   |\n   |\n   |________________________"); 
    if(result==2)
     printf("   ___________________\n   |          |\n   |          |\n   |          O\n   |         /|\\\n   |          |\n   |\n   |\n   |________________________"); 
    if(result==1)
     printf("   ___________________\n   |          |\n   |          |\n   |          O\n   |         /|\\\n   |          |\n   |         / \n   |\n   |________________________"); 
    if(result==0)
     printf("   ___________________\n   |          |\n   |          |\n   |          O\n   |         /|\\\n   |          |\n   |         / \\\n   |\n   |________________________");

}
