#include	"sas.h"

/**
 * statistic_menu - function desplay the statistic menu
 */

extern int idx;
extern todos	todo[100];
int	total = 0, complete = 0, incomplet = 0;

void	completed()
{
	for (int i = 0; i < idx; i++)
	{
		if (todo[i].id != -1)
		{
			if (strcmp(todo[i].status, "Done") == 0)
				complete++;
			else
					incomplet++;
		}
	}
}


void	statistic_menu()
{
	int	choice;
	char	checker[10];

	printf("\e[1;1H\e[2J");
here:
	printf("Statistics Menu:\n\n\n");
	printf("1. Display the total number of tasks\n");
	printf("2. Display the number of completed and incomplete tasks\n");
	printf("3. Display the number of days remaining until the deadline for each task\n\n");
	printf("Please enter your choice (1-3) or '0' to go back: ");
	scanf(" %[^\n]", checker);
	choice = atoi(checker);
	switch (choice)
	{
		case 1:
			printf("\n\n\t\tThe total number of task is:   %d\n\n\n", idx - total);
			break;
		case 2:
			completed();
			printf("Complted: %d\nIncomplete: %d\n\n\n", complete, incomplet);
			break;
		case 3:
			remaining();
		case 4:
			break;
		default:
			printf("\n\n\n\t\t\t\tInvalid choice. Please try again...\n\n\n");
			goto here;
	}
}
