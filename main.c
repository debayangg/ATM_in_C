#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct acc_holder
{
    int amount;
    char name[100];
    char pin[100];
};

int main()
{
    int choice=1;
    struct acc_holder user;
    user.amount=-1;

    while(choice>=1)
    {
        if(user.amount<0)
        {
            printf("New User identified\n");
            printf("Enter your name:\n");
            scanf("%[^\n]",&user.name);
            printf("Enter amount in account:\n");
            scanf("%d",&user.amount);
            printf("Enter a PIN with a minimum of 8 characters:\n");
            getchar();
            scanf("%[^\n]",&user.pin);

            while(strlen(user.pin)<8)
            {
                printf("Please provide a appropriate PIN:\n");
                getchar();
                scanf("%[^\n]",&user.pin);
            }

            
        }

        else
        {

            printf("Options:\n");
            printf("1.View your balance\n");
            printf("2.Withdraw money\n");
            printf("3.Deposit money\n");
            printf("4.Change PIN\n");
            printf("Enter 0 to exit\n");
            printf("Enter your choice:\n");
            scanf("%d",&choice);
            if(choice==1)
            {
                printf("Balance in your account:%d\n",user.amount);
            }
            else if(choice==2)
            {
                int amt=0;
                printf("Enter amount to be withdrawn:\n");
                scanf("%d",&amt);
                if(amt>user.amount)
                printf("Your account doesn't have that amount\n");
                else
                {
                    user.amount-=amt;
                    printf("Current account:%d\n",user.amount);
                }
            }
            else if(choice==3)
            {
                int amt=0;
                printf("Enter amount to be deposited:\n");
                scanf("%d",&amt);
                user.amount+=amt;
                printf("Current account:%d\n",user.amount);
            }
            else if(choice==4)
            {
                printf("Provide a new PIN:\n");
                printf("Enter a PIN with a minimum of 8 characters:\n");
                getchar();
                scanf("%[^\n]",&user.pin);
                while(strlen(user.pin)<8)
                {
                    printf("Please provide a appropriate PIN:\n");
                    getchar();
                    scanf("%[^\n]",&user.pin);
                }
            }
            else if(choice==0)
            {}
            else
            {
                printf("Wrong option inputted\n");
            }
        }
        

    }
    
    return 0;
}
