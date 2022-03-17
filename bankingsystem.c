#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct user
{
    char phone[50];
    char ac[50];
    char password[50];
    float balance;
};
int main()
{
    struct user usr,usr1;
    FILE *fp;
    char filename[50],phone[50],pword[50];

   int opt,choice;
   char cont = 'y';
   float amount;
                //First Page of the Program
   printf("*********Welcome To The Bank*********\n\n\n");
   printf("\nWhat Do You Want To Do");
   printf("\n1.Register An Account");
   printf("\n 2.Login To Your Account\n");
   printf("\nYour choice:\t");
   scanf("%d",&opt);
    // After receiving the choice of the user
            if(opt==1)
            {
                system("cls");//Clears the Screen
                printf("\nEnter Your Account Number:");
                scanf("%s",usr.ac);//saves the data in ac[50]
                printf("Enter Your Phone Number:");
                scanf("%s",usr.phone);//saves the data in phone[50]
                printf("Enter Your Password:");
                scanf("%s",usr.password);//saves the data in password[50]
usr.balance=0;
    strcpy(filename,usr.phone);//It copies the string pointed by user
    fp=fopen(strcat(filename,".dat"),"w");//fp=filepointer and fopen to open a file for writing or reading
    fwrite(&usr,sizeof(struct user),1,fp);//fwrite to write in the location provided by user
        if (fwrite!=0)
        {
            printf("\n\n Account Succesfully Registered");
        }
        else{
            printf("\n\n Something went wrong");
        }
        fclose(fp);//closing fp
                }

if(opt==2){
    system("cls");
    printf("\n Phone number:\t");
    scanf("%s",&phone);
    printf("Password:\t");
    scanf("%s",&pword);
    strcpy(filename,phone);
        fp= fopen(strcat(filename,".dat"),"r");
        if (fp==NULL)
        {
            printf("Account Number not registered");
        }
        else{
        fread(&usr,sizeof(struct user),1,fp);
        fclose(fp);
        if(!strcmp(pword,usr.password)){
            while (cont=='y')
            {
                system("cls");
                printf("\nPress 1 for balance inquiry");
                printf("\nPress 2 for depositing an cash");
                printf("\nPress 3 for cash withdraw");
                printf("\nPress 4 for online transfer");
                printf("\nPress 5 for Changing Your password");
                printf("\n\n Your choice:");
                scanf("%d",&choice);
                        switch(choice){
                            case 1:
                                    printf("\n Your current balance is Rs%.2f",usr.balance);
                                break;
                        
                            case 2:
                            printf("\n Enter the amount:\t");
                             scanf("%f",&amount);
                            usr.balance +=amount;
                                fp =fopen(filename,"w");
                                fwrite(&usr,sizeof(struct user),1,fp);
                                    if(fwrite!=NULL) printf("\nSuccessfully Deposited");
                                    fclose(fp);


                                break;
                            case 3:
                                printf("\n Enter the amount:\t");
                             scanf("%f",&amount);
                            usr.balance -=amount;
                                fp =fopen(filename,"w");
                                fwrite(&usr,sizeof(struct user),1,fp);
                                    if(fwrite!=NULL) printf("\nYou have withdrawn Rs%.2f",amount);
                                    fclose(fp);
                                break;
                            case 4:
                                printf("\n Please Enter the Phone Number You Want to Transfer The money to:\t");
                                scanf("%s",phone);
                                printf("\n Please Enter the Amount to Transfer");
                                scanf("%f",&amount);
                                 strcpy(filename,phone);
                                    fp=fopen(strcat(filename,".dat"),"r");
                                    if(fp==NULL) printf("Phone number is not registered");
                                    else{
                                         fread(&usr1,sizeof(struct user),1,fp);
                                    fclose(fp);
                                if(amount>usr.balance){
                                    printf("Insufficient Balance");
                                }
                                else{
                                   
                                   
                                    fp=fopen(filename,"w");
                                    usr1.balance +=amount;
                                    fwrite(&usr1,sizeof(struct user),1,fp);
                                    fclose(fp);
                                    if(fwrite !=NULL){
                                        printf("\n You have successfully transfer Rs %.2f to %s",amount,phone);
                                        strcpy(filename,usr.phone);
                                        fp=fopen(strcat(filename,".dat"),"w");
                                        usr.balance -=amount;
                                        fwrite(&usr,sizeof(struct user),1,fp);
                                        fclose(fp);
                                    }

                                }

                        }
                        break;
                        case 5:
        printf("Please enter your new password:\t");
        scanf("%s",pword);
        fp=fopen(filename,"w");
        strcpy(usr.password,pword);
        fwrite(&usr,sizeof(struct user),1,fp);
if(fwrite!=NULL)
{
        printf("\n Password succesfully changed");}

                                    }
                                   
                printf("\nDo you want to continue the transaction[y/n]?");\
                scanf("%s",&cont);

            }
            
        }
        else{
            printf("\n Invalid Account Detail(check your details");
        }
        } 
}
return 0;
}