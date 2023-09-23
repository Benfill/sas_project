#include	"sas.h"

extern int idx, total;
extern todos	todo[100];

/**
 * add_task - functions adds new tasks to the list
 */
void	add_task(int n)
{
	char	status[10];
	int	checker;
	for (int i = idx; i < n + idx; i++)
	{
		todo[i].id = i + 1;
		printf("\n\n\nPlease enter the details of the task:\n");
		printf("Title: ");
		scanf(" %[^\n]", todo[i].title);
		printf("Description: ");
		scanf(" %[^\n]", todo[i].description);
		here:
		printf("[1] 'To do'\n[2] 'In progress'\n[3] 'Completed'\nChoose the status: ");
		scanf(" %[^\n]", status);
		checker = atoi(status);
		switch(checker)
		{
			case 1:
				strcpy(todo[i].status, "To do");
				break;
			case 2:
				strcpy(todo[i].status, "Doing");
				break;
			case 3:
				strcpy(todo[i].status, "Done");
				break;
			default:
				printf("\e[1;1H\e[2J");
				printf("Invalid choice, Try againi\n\n\n");
				goto here;
		}

		right_there:
		printf("Please enter the  Date (Day/Month/Year, e.g., 20/09/2023): ");
		scanf("%d/%d/%d", &todo[i].D_day, &todo[i].D_month, &todo[i].D_year);
		if (todo[i].D_day > 30 || todo[i].D_day == 0)
		{
			printf("Invalid Date, Try again\n\n\n");
			goto right_there;
		}
		else if (todo[i].D_month > 12 || todo[i].D_month == 0)
		{
			printf("Invalid Date, Try again\n\n");
			goto right_there;
		}
		else if (todo[i].D_year < 2023 || todo[i].D_year == 0)
		{
			printf("Invalid Date, Try again\n\n");
			goto right_there;
		}
		else if (todo[i].D_year == 2023 && (todo[i].D_month < 9 || (todo[i].D_month == 9 && todo[i].D_day < 22)))
		{
			printf("Invalid Date, Try again\n\n");
			goto right_there;
		}
		printf("\n\n\n\t\t\tTask added successfully!\n\n");
	}
	idx += n;
}

/**
 * display - function shows the list of todolist
 */

void	display()
{
	printf("\e[1;1H\e[2J");
	printf("+----+-----------------+----------------------+--------------+-------------+\n");
	printf("| ID |    Nom de la tâche   |    Description    |  Date d'échéance |     Statut|\n");
	printf("+----+-----------------+----------------------+--------------+-------------+\n");
	for (int i = 0; i < idx; i++)
	{
		if (todo[i].id == -1)
			continue;
		printf("| %-2d | %-19s | %-20s | %02d/%02d/%04d | %-15s |\n", todo[i].id, todo[i].title, todo[i].description, todo[i].D_day, todo[i].D_month, todo[i].D_year, todo[i].status);
	}
}

/**
 * display_menu - function show the menu for the user to choose how to sort the list
 */

void	display_menu()
{
	int	choice;
	char	checker[10];
	printf("\e[1;1H\e[2J");
	printf("\n\n\n\t\t\tDisplay Menu\n\n\n");
	printf("1. Sort tasks alphabetically\n");
	printf("2. Sort tasks by deadline\n");
	printf("3. Display tasks with a deadline within the next 3 days or less\n\n");
	there:
	printf("\t\t\tPlease enter your choice (1-3) or '4' to go back: ");
	scanf(" %[^\n]", checker);
	choice = atoi(checker);
	switch(choice)
	{
		case 1:
			alpha_sort();
			display();
			break;
		case 2:
			deadline_sorting();
			display();
			break;
		case 3:
			deadline_3_days();
			break;
		case 4:
			printf("\e[1;1H\e[2J");
			break;
		default:
			printf("\e[1;1H\e[2J");
			printf("Invalid choice. Please try again.\n\n\n");
			goto there;
	}
}

void	remove_task(int id)
{
	todos	*rm;
	char	checker;
	rm = search(id);
here:
	printf("Are you sure you want to delete this task? (Y/N): ");
	scanf(" %c", &checker);
	if (checker == 'Y' || checker == 'y')
	{
		rm->id = -1;
		total++;
		printf("Task deleted successfully.\n");
	}
	else if (checker == 'N' || checker == 'n')
		return;
	else
	{
		printf("incorrect choice\n\n\n\n");
		goto here;
	}
}
