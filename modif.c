#include	"sas.h"

extern int		idx;
extern todos	todo[100];

/**
 * modif - function modifies a task by its id
 */

void	modif(int choice, int id)
{
	int	checker;
	char	status[5], incorrect = 'n';
	todos	*modif;

	if (incorrect != 'n')
	{
		r_there:
		printf("Please enter the ID of the task you want to modify: ");
		scanf(" %[^\n]", status);
		id = atoi(status);
	}
	if (id == 0)
	{
		printf("Invalid ID. Please try again. \n\n\n");
		goto r_there;
	}
	modif = search(id);
	if (modif->id == -1)
	{
		printf("The task has been Deleted ):\n");
		return;
	}
	if (modif == NULL)
	{
		printf("Task not found or incorrect ID. Please make sure you have entered the correct task ID and try again.\n\n\n");
		goto r_there;
	}
	if (choice == 1)
	{
		printf("Please enter the new description for the task: ");
		scanf(" %[^\n]", modif->description);
	}
	else if (choice == 2)
	{
		here2:
		printf("Please enter the new status for the task\n\n");
		printf("[1] 'To do'\n[2] 'In progress'\n[3] 'Completed'\nChoose the status: ");
		scanf(" %[^\n]", status);
		checker = atoi(status);
		switch(checker)
		{
			case 1:
				strcpy(modif->status, "To do");
				break;
			case 2:
				strcpy(modif->status, "Doing");
				break;
			case 3:
				strcpy(modif->status, "Done");
				break;
			default:
				printf("\e[1;1H\e[2J");
				printf("Invalid choice, Try againi\n\n\n");
				goto here2;
		}
	}
	else if (choice == 3)
	{
		right_there2:
		printf("Please enter the  Date (Day/Month/Year, e.g., 20/09/2023): ");
		scanf("%d/%d/%d", &modif->D_day, &modif->D_month, &modif->D_year);
		if (modif->D_day > 30 || modif->D_day == 0)
		{
			printf("Invalid Date, Try again\n\n\n");
			goto right_there2;
		}
		else if (modif->D_month > 12 || modif->D_month == 0)
		{
			printf("Invalid Date, Try again\n\n");
			goto right_there2;
		}
		else if (modif->D_year < 2023 || modif->D_year == 0)
		{
			printf("Invalid Date, Try again\n\n");
			goto right_there2;
		}
		else if (modif->D_year == 2023 && (modif->D_month < 9 || (modif->D_month == 9 && modif->D_day < 22)))
		{
			printf("Invalid Date, Try again\n\n");
			goto right_there2;
		}
	}
	printf("\n\n\n\t\t\tTask modified successfully!\n\n");
}

/**
 * modif_menu - function display the modification menu
 */

void	modif_menu()
{
	int	choice;
	char	checker[10];
	printf("\e[1;1H\e[2J");
	r_there:
	printf("\n\n\n\t\t\tModify a Task Menu:\n\n\n");
	printf("1. Modify the description of a task\n");
	printf("2. Modify the status of a taske\n");
	printf("3. Modify the deadline of a task\n\n");
	printf("\t\t\tPlease enter your choice (1-3) or '4' to go back: ");
	scanf(" %[^\n]", checker);
	choice = atoi(checker);
	switch(choice)
	{
		case 1:
			printf("Please enter the ID of the task you want to modify: ");
			scanf(" %[^\n]", checker);
			modif(1, atoi(checker));
			break;
		case 2:
			printf("Please enter the ID of the task you want to modify: ");
			scanf(" %[^\n]", checker);
			modif(2, atoi(checker));
			break;
		case 3:
			printf("Please enter the ID of the task you want to modify: ");
			scanf(" %[^\n]", checker);
			modif(3, atoi(checker));
			break;
		case 4:
			printf("\e[1;1H\e[2J");
			break;
		default:
			printf("\e[1;1H\e[2J");
			printf("Invalid choice. Please try again.\n\n\n");
			goto r_there;
	}
}
