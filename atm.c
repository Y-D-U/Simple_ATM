#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct holder{
		char name[10];
		int balance;
		char account_no[10];
		int pin;		
	};

struct holder holders[10];

void createAccount(struct holder hol[],int *p);
void banking(struct holder hol[], int index);

int main(){
	int cnt=0;
	while (true){
		int choice;
		
		printf("WELCOME TO ABC BANKING \n PRESS 1 TO BANK OR 2 TO CREATE AN ACCOUNT");		
		scanf("%d",&choice);

		
		//printf("%s %d %d %d",acc_no,acc_no=="CREATE",sizeof("CREATE"),sizeof(acc_no));
		if (choice==2){
			printf("HERE! \n");
			createAccount(holders,&cnt);
		}
		else{
		printf("Swipe your card or Enter your 10 digit account number..\n");
		char acc_no[10];
		
		scanf("%s",acc_no);
		int i=0;
		for(;i<10;i++){
			//printf("thos ");
			if (!(strcmp(holders[i].account_no,acc_no))){
				banking(holders,i);
				break;}
		}
		if (i==10) {
			printf("Sorry the account number is wrong, Please try again..\n");
			;}
			
	}
}


}

void banking(struct holder holder[],int index){
	printf("Welcome %s 1 for cash withdrawal 2 for checking balance",holder[index].name);
	int i;
	scanf("%d",&i);
	if(i==1){
		printf("Enter the amount");
		int amt;
		scanf("%d",&amt);
		printf("Enter you pin");
		int pin;
		scanf("%d",&pin);
		int j=0;
		for(;holder[index].pin!=pin && j<=2;j++){
			printf("Wrong pin please enter again %d",j);
			scanf("%d",&pin);
		}
		if (j>=3) printf("Your account is locked you made 3 incorrect attempts");
		else{
		holder[index].balance-=amt;
		printf("Please collect the cash\n");
	}
			}
	else if (i==2){
		printf("Enter you pin");
		int pin;
		scanf("%d",&pin);
		int j=0;
		for(;holder[index].pin!=pin && j<=2;j++){
			printf("Wrong pin please enter again %d attempts left",j);
			scanf("%d",&pin);
		}
		if (j>=3) printf("Your account is locked you made 3 incorrect attempts");
		else printf("your balace is %d",holder[index].balance);

	}
	printf("Thankyou For Banking with us.\n");
}

void createAccount(struct holder holders[],int *cnt){
	printf("Enter the account holder name");
	char name[10];
	scanf("%s",&holders[*cnt].name);
	//holders[0].name=name;
	printf("Set your pin (SHOULD BE 4 DIGIT LONG)");
	scanf("%d",&holders[*cnt].pin);
	for(int i=0;i<10;i++){
		holders[*cnt].account_no[i]=(char) (rand()%10)+48;
	}
	holders[*cnt].balance=0;
	printf("Account created succesfully! Your Account Number is :%s \n",holders[*cnt].account_no);
	*cnt+=1;


}