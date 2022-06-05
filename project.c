#include <stdio.h>


typedef struct holder_deets{
	char name[20];
	int pin;
	int age;
	long int phone;
	float bal;
}acc_deets;



acc_deets acc_open()
{
	acc_deets x;
	int temp_pin;
	int flag3=1;

	printf("Enter your name\n");
	scanf("%[^\n]s",x.name);
	printf("\nEnter your age\n");
	scanf("%d",&x.age);
	printf("\nEnter your phone number\n");
	scanf("%ld",&x.phone);
	while (flag3==1)
	{
		printf("\nEnter your secret 4-digit pin\n");
		scanf("%d",&x.pin);
		printf("\nConfirm your secret 4-digit pin\n");
		scanf("%d",&temp_pin);
		flag3=0;
		if (x.pin!=temp_pin)
		{
			flag3=1;
			printf("\nPin not matching\n");
		}

	}	
	printf("\nWe request you to make an initial deposit(min 10000rs)\n");
	scanf("%f",&x.bal);
	while (x.bal<10000)
	{
		printf("\nDeposit an amount more than 10000rs\n");
		scanf("%f",&x.bal);
	}

	return x;
}

void deposit(acc_deets *a)
{
	int temp_pin;
	float amount;
	while (1)
	{
		printf("Enter the pin: ");
		scanf("%d",&temp_pin);
		if (a->pin==temp_pin)
		break;
		else
		printf("Pin unmatched \n");
		continue;
	}
	while(1)
	{	printf("Amount to be deposited: ");
		scanf("%f",&amount);
		if(amount>=0)
		{ a->bal=a->bal+amount;
		  break;
		}
		if (amount<0)
		{ printf("Enter a positive amount:\n");
		  continue;
		}
	}
	printf("Amount successfully deposited\n");
	printf("Current balance: %.2f\n",a->bal);
}

void withdraw(acc_deets *a)
{
	int temp_pin;
	float amount;
	while (1)
	{
		printf("Enter the pin: ");
		scanf("%d",&temp_pin);
		if (a->pin==temp_pin)
		break;
		else
		printf("Pin unmatched\n");
		continue;
	}
	while (1)
	{	printf("Enter the amount to be withdrawn: \n");
		scanf ("%f",&amount);
		if (amount>0)
		{ if (a->bal-amount>10000)
		{
			a->bal=a->bal-amount;
			break;
		}
		else
		printf("Minimum balance must be 10000\n");
		continue;
		}
		else
		printf("Enter a positive amount\n");
		continue;
	}
	printf("Amount successfully withdrawn\n");
	printf("%.2f\n",a->bal);
}

int main()
{	
	int flag1=1,flag2=1;
	int action;
	acc_deets x;


	printf("Welcome to PESU Bank\n");
	printf("We request you to open an account with us before proceeding\n");
	x=acc_open(); //the variable x is a struct which has acc_details
					//use this to program the next functions



	while(flag1==1)
	{
		
		printf("\nHow can we help you today?\n");

		printf("Deposit money to your account(1)\t\t");
		printf("Withdraw money from your account(2)\n");
		printf("Change your secret pin(3)\n");
		scanf("%d",&action);

		while (flag2)
		{
			if (action==1 || action==2 || action==3)
			{
				switch (action)
				{
					case 1:
					printf("you have entered %d\n",action);
					deposit(&x);
					break;

					case 2:
					printf("you have entered %d\n",action);
					withdraw(&x);
					break;

					case 3:
					printf("you have entered %d\n",action);
					break;
				}
				flag2=0;
			}


			else
			{
				printf("Enter a valid option\n");
				scanf("%d",&action);
			}
		}

		flag2=1;

		printf("Would you like to exit?(0)\n");
		printf("Back to main menu(1)\n");
		scanf("%d",&flag1);

	}
	printf("Thank you for your time!\n");
	return 0;
}
