#include <stdio.h>
#include <stdlib.h>

/**
 * main - Asks the user if they like me
 *
 * Return: Always 0.
 */
int main(void)
{
	char ans, reply;
		int rate = 1;

		printf("Do you like me? (Y/N)\n");
		scanf("%c", &ans);

		if (ans == 'y' || ans == 'Y')
		{
			printf("Oh wow that's great, I like you too!\n");
		}
		else
		{
			printf("that's okay, maybe we could be friends?\n");
		}
		printf("Y/N\n");
		scanf("%c", &reply);

		if (reply == 'y' || reply == 'Y')
		{
			printf("Nice to be your new friend!\n");
		}
		else
		{
			printf("well, okay then...\n");
		}
		printf("I'm a beginner in C programming language,\n");
		printf("Thanks for testing my program, Full code on the repo. BYE :)\n");
		return (0);
}
