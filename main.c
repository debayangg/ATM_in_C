#include <stdio.h>
#include <stdlib.h>

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
            printf("New User identified");
            printf("Enter your name: ");
            scanf("%s",&user.name);
            printf("Enter amount in account:");
            scanf("%d",&user.amount);
            printf("Enter a PIN with a minimum of 8 characters:");
            scanf("%s",&user.pin);
            while(sizeof(user.pin)/sizeof(user.pin[0])<8)
            {
                printf("Please provide a appropriate PIN:");
                scanf("%s",&user.pin);
            }

            
        }
        else{

            printf("Options:");
            printf("1.View your balance");
            printf("2.Withdraw money");
            printf("3.Deposit money");
            printf("4.Change PIN");
            printf("Enter 0 to exit");
            printf("Enter your choice:");
            scanf("%d",choice);
            if(choice==1)
            {
                printf("Balance in your account:%d",user.amount);
            }
            else if(choice==2)
            {
                int amt=0;
                printf("Enter amount to be withdrawn:");
                scanf("%d",amt);
                if(amt>user.amount)
                printf("Your account doesn't have that amount");
                else
                {
                    user.amount-=amt;
                    printf("Current account:%d",user.amount);
                }
            }
            else if(choice==3)
            {
                int amt=0;
                printf("Enter amount to be deposited:");
                scanf("%d",amt);
                user.amount+=amt;
                printf("Current account:%d",user.amount);
            }
            else if(choice==4)
            {
                printf("Provide a new PIN:");
                printf("Enter a PIN with a minimum of 8 characters:");
                scanf("%s",&user.pin);
                while(sizeof(user.pin)/sizeof(user.pin[0])<8)
                {
                    printf("Please provide a appropriate PIN:");
                    scanf("%s",&user.pin);
                }
            }
            else
            {
                printf("Wrong option inputted");
            }
        }
        

    }
    
    return 0;
}