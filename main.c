#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h> //for system("cls") mostly
#include<conio.h> //we need it for getch(void) function and stream single char input otherwise it will not be stream
typedef struct Birhday{

    int year,month,day;
} Date;

typedef struct personal_data {

    char name[25],familyname[25],nickname[25],brithplace[25];
    Date birthday;
    char invitor[25];
} Member;


int year() //check the date input should only be from 0 to 2022 it returns the final correct data
{
    int x;
    scanf("%d",&x);
    while(x>0&&x>2022)
    {
        printf("Error date input");
        scanf("%d",&x);
    }
    return x;
}
int day() //check the date input should only be from 0 to 31 it returns the final correct data
{
    int x;
    scanf("%d",&x);
    while(x<0 && x>32)
    {
        printf("Error date input");
        scanf("%d",&x);
    }

    return x;

}
int month() //check the data input should only be from 1 to 12 it returns the final correct data
{
    int x;
    scanf("%d",&x);
    while(x<0 || x>13)
    {
        printf("Error date input");
        scanf("%d",&x);
    }
    return x;
}

char* check_if_only_chracter_alphabet(char* string) // points to an string as parameter and checks it char by char the returns the good string
{
    int flag =0,x;

    do
    {
        for(x=0;string[x]!='\0';x++){

         if(string[x]>='A' && string[x]<='Z' || string[x]>='a' && string[x]<='z')                 //! check if the string entered is only alphabet
         flag=0;

         else
         {
          flag++;
          printf("\nOnly letters are allowed !");
          scanf("%s",string);
          x=0;
         }
        }

    } while (flag !=0);



}


void create()                                                   //! 1.Creating new member
{
    Member* person=NULL;
    FILE* fptr=NULL;
    char string[25],stream;  //for transfering data
    int i;

    person=(Member*)malloc(sizeof(Member));
    fptr=fopen("Facebook.txt","a");            /*"a" (append mode) search for file if not create one and
                                            if exist strats writing from the last character*/
    if(fptr==NULL){
        printf("\nERROR opening file!");
        exit(1);
    }

    system("cls");

        printf("\nPlease Enter a name :(25)\n");
        scanf("%s",string); check_if_only_chracter_alphabet(string);
        strcpy(person->name,string);

        printf("\nPlease Enter a familyname :(25)\n");
        scanf("%s",string); check_if_only_chracter_alphabet(string);
        strcpy(person->familyname,string);

        printf("\nPlease Enter a nickname:(25)\n");
        scanf("%s",person->nickname);

        printf("\nPlease Enter a birthplace : (25)\n ");
        scanf("%s",string); check_if_only_chracter_alphabet(string);
        strcpy(person->brithplace,string);

        printf("\nPlease Enter birthday YYYY ");
        person->birthday.year = year();
        printf("\nPlease Enter birthday MM ");
        person->birthday.month = month();
        printf("\nPlease Enter birthday DD ");
        person->birthday.day = day();
        printf("\nwho inivted the member to facebook ?: (25)\n ");
        scanf("%s",string); check_if_only_chracter_alphabet(string);
        strcpy(person->invitor,string);

        fprintf(fptr,"%s %s %s %s %d %d %d %s\n",
                                      person->name,
                                      person->familyname,
                                      person->nickname,
                                      person->brithplace,
                                      person->birthday.year,
                                      person->birthday.month,
                                      person->birthday.day,
                                      person->invitor);


        system("cls");
            printf("\n\tData stored successfully !\n");
            getch();
        free(person);
        fclose(fptr);

    }

 void find_member(Member* member,int records){


    int i=0;
    char input[25];
    int match =0;
    int choise;
    int x=0;
    printf("\nFind member by given:\n1.Familyname\n2.nickname\n");
    scanf("%d",&choise);
    switch (choise)
    {
        case 1:
         match =0;
         printf("\nEnter a familyname:\n");
         scanf("%s",input);

            for(i=0;i<records;i++)
            {

             if(strcmp(input,member[i].familyname)==0)
             {
                match++;
                if(match==1)
                printf("(Name)\t(familyname)\t(nickname)\t(birthplace)\t(birthday YYYY MM DD)\t(invitor)\n");//We just compare the user string input and with data we have if it match

                printf("%s\t%s\t\t%s\t\t%s\t\t%d/%d/%d\t\t%s\n",                                              //and we just print it
                member[i].name,
                member[i].familyname,
                member[i].nickname,
                member[i].brithplace,
                member[i].birthday.year,
                member[i].birthday.month,
                member[i].birthday.day,
                member[i].invitor);



             }
           }
           if(match>0)
            {
                printf("\n\tmatch (%d) found!\nEnter a key to proceed",match);
                getch();
            }

            else
            {
              system("cls");
              printf("\nMember did not found !\npress any key to proceed...");
              getch();

            }




        break;

        case 2:
          match =0;
         printf("\nEnter a nickname:\n");
         scanf("%s",input);

            for(i=0;i<records;i++)
            {

             if(strcmp(input,member[i].nickname)==0)
             {
                match++;
                if(match==1)
                printf("(Name)\t(familyname)\t(nickname)\t(birthplace)\t(birthday YYYY MM DD)\t(invitor)\n"); //We just compare the user string input and with data we have if it match
                printf("%s\t%s\t\t%s\t\t%s\t\t%d/%d/%d\t\t%s\n",                                           //and we just print it
             member[i].name,
             member[i].familyname,
             member[i].nickname,
             member[i].brithplace,
             member[i].birthday.year,
             member[i].birthday.month,
             member[i].birthday.day,
             member[i].invitor);
             }
           }

            if(match==0){
              system("cls");
              printf("\nMember did not found !\npress any key to proceed...");
              getch();
            }

            if(match>0)
            {
                printf("\n\tmatch (%d) found!\nEnter a key to proceed",match);
                getch();
            }
         break;

         default:
         printf("\nError!");
         break;

    }

}



void list_all(Member* member,int records){                              //! list all members

    system("cls");
 printf("\n(Name)\t(year)\t(birthplace)\n");
 int i;
 for(i=0;i<records;i++)
 {
    printf("%s\t%d\t%s\n",member[i].name,member[i].birthday.year,member[i].brithplace);
 }

   printf("\n\t Press any key to continue - - - - - \n");
   getch();
}

void delete_member(Member* member,int records)
{
    char input[25];
    printf("\nEnter a Nickname of a member to be deleted: ");
    scanf("%s",input);
    int i=0;
    int flag=-1,match=-1;
    for(i=0;i<records;i++)
     {
        if(strcmp(member[i].nickname,input)==0){
            flag=i;
            match++;
        }
    }
    if(match!=-1)
    {
         FILE* fptr_temp = fopen("temp.txt","w");
         if(fptr_temp==NULL)
    {
        printf("Error opening file");
        exit(1);
    }
        i=0;
        while(i<records)
    {
        if(i==flag)
            i++;
        if(flag==records-1)
            break;
        fprintf(fptr_temp,"%s %s %s %s %d %d %d %s\n",
                                      member[i].name,
                                      member[i].familyname,
                                      member[i].nickname,
                                      member[i].brithplace,
                                      member[i].birthday.year,
                                      member[i].birthday.month,
                                      member[i].birthday.day,
                                      member[i].invitor);
 i++;
 }

       fclose(fptr_temp);
       int check_remove=remove("Facebook.txt");
       int check_rename= rename("temp.txt","Facebook.txt");
       if(check_remove==0 && check_rename==0)
       {
           printf("\nMember with nickname (%s) has been removed successfully from file (Facebook.txt)",input);
           printf("Press any key to proceed !");
           getch();

       }


    }
    else
    {
        printf("Error input\tpress anykey...");
        getch();
    }



}

void search_invitor(Member* member,int records)
{

    char invitor[25];
    printf("\nEnter the invitor's name:\n");
    scanf("%s",invitor);
    int match=0;
    int i;
            for(i=0;i<records;i++)
            {

             if(strcmp(invitor,member[i].invitor)==0)
             {
                match++;
                if(match==1)
                printf("(Name)\t(familyname)\t(nickname)\t(birthplace)\t(birthday YYYY MM DD)\t(invitor)\n");

                printf("%s\t%s\t\t%s\t\t%s\t\t%d/%d/%d\t\t%s\n",
                member[i].name,
                member[i].familyname,
                member[i].nickname,
                member[i].brithplace,
                member[i].birthday.year,
                member[i].birthday.month,
                member[i].birthday.day,
                member[i].invitor);



             }
           }
           if(match==0)
           {
               printf("Could not found!\tpress any key...");
               getch();
           }
           else
           {
               printf("\npress any key..");
               getch();
           }

}

int main(){
    FILE* fptr = fopen("Facebook.txt","r"); //open the file if not make a new file with append mode
     if(fptr== NULL)
         fptr = fopen("Facebook.txt","a+");

        if(fptr==NULL)
        {
            printf("Error opening file!\n"); // stop if error with file
            return 1;
        }

    int menu;
 do{

        fseek(fptr, 0, SEEK_SET);  // setting the file pointer to begging just in case
        int record_counter=0;
        char current;
        current = fgetc(fptr); //setting a buffer that let us know how many member we have by matching to new line in file
        while(current !=EOF)
        {
           if(current == '\n')
           record_counter++;
           current = fgetc(fptr);

           }

        fseek(fptr, 0, SEEK_SET); //setting file pointer to begging because it is now pointing to end of file

        char buffer[150];
        int i=0;
        int check_read=0;
        Member* member = malloc(record_counter*sizeof(Member)); //allocating memory with the help of structure and records
        while(i<record_counter)
 {
  fgets(buffer, sizeof(buffer),fptr);
  check_read = check_read + sscanf(buffer,"%s %s %s %s %d %d %d %s", //Storing data from file to memory
                                      member[i].name,
                                      member[i].familyname,
                                      member[i].nickname,
                                      member[i].brithplace,
                                      &member[i].birthday.year,
                                      &member[i].birthday.month,
                                      &member[i].birthday.day,
                                      member[i].invitor);
 i++;
 }

     system("cls");

     printf("\n  Welcome to FaceBook Application !         Credit:Moein Shahi\n");

     printf("\n\n\n -You can use this menu to proceed-\n\n");          //Menu printing
     printf("1.Enter a new member's data\n");
     printf("2.Find a member in the community\n");
     printf("3.Delete a member from the community\n");
     printf("4.List all the members who are invited by the same person\n");
     printf("5.List all the Community Members\n");
     printf("6.Exit the program !\n");
     scanf("%d",&menu);
   switch(menu)
     {

        case 1:
            create(); //we do not need to pass the file pointer or structure since we will open the file in append mode

        break;

        case 2:

            if(record_counter)
                find_member(member,record_counter); //calling function and passing structures data and number of exist records as argument
                else
                {
                    printf("\nNo records exist\tpress any.."); //if no record exist we cant continue !
                    getch();
                }

        break;

        case 3:
            if(record_counter>0)
            {
                fclose(fptr);                        //we need to close the file in order to make some changes such as removing file
              delete_member(member,record_counter); //passing structure data as argument to work on and number of records

               fptr = fopen("Facebook.txt","r"); // we need to open the file once more because if the user is going to go back to menu
               if(fptr==NULL)                  //the data needs to be red by file
               {
                printf("Error opening file");
                return 1;
               }

            }
            else
                {
                    printf("\nNo records exist\tpress any.."); //if no record exist we cant continue !
                    getch();
                }
        break;

        case 4:
            if(record_counter>0)
            {
                search_invitor(member,record_counter); //passing structure members and number of records to work on
            }
            else
            {
                printf("\nNo records exist\tpress any.."); //if no record exist we cant continue !
                getch();

            }

        break;

        case 5:
            if(record_counter>0)
            list_all(member,record_counter); //we will just make a loop to print the members of structure and we need to know how many times

            else
            {
                printf("\nNo records exist\tpress any.."); //if no record exist we cant continue !
                getch();

            }

        break;

        default:
        printf("Good Bye"); //any integer beside closes the program
        break;

     }
      free(member); //release the dynamic array of structure because we need to update it
    } while(menu != 6);
    fclose(fptr); 


return 0;
}


