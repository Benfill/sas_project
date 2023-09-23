#include	"sas.h"

int idx = 0;

/**
 * swap - function swaps struct a to struct b and vice versa
 */

void	swap(int i, int j)
{
	todos swp = todo[i];
	todo[i] = todo[j];
	todo[j] = swp;
}

/**
 * alpha_sort - function sorts the list alphabetically
 */

void	alpha_sort()
{
	for (int i = 0; i < idx - 1; i++)
	{
		for (int j = 0; j < idx - i - 1; j++)
		{
			if (strcasecmp(todo[j].title, todo[j + 1].title) > 0)
				swap(j, j + 1);
		}
	}
}

/**
 * main - program manage a ToDo list
 */

int	main()
{
	int	choice, n = 1;
	char	checker[10];

	printf("\e[1;1H\e[2J");
	while (1)
	{
		printf("\n\n\n\t\t\t\tBienvenue au Gestion de Tâches ToDo\n\n");
		printf("1. Add a new task\n");
		printf("2. Add multiple new tasks\n");
		printf("3. Display all tasks\n");
		printf("4. Modify a task\n");
		printf("5. Delete a task\n");
		printf("6. Search for tasks\n");
		printf("7. View statistics\n");
		printf("\t\t\tPlease enter your choice (1-7) or '8' to exit: ");
		scanf(" %[^\n]", checker);
		choice = atoi(checker);
		switch(choice)
		{
			case 1:
				add_task(1);
				break;
			case 2:
				printf("Please enter how many tasks you want to add: ");
				scanf("%d", &n);
				add_task(n);
				break;
			case 3:
				if (idx == 0)
				{
					printf("\e[1;1H\e[2J");
					printf("\n\n\n\t\t\t\tThe list is empty add new tasks\n");
				}
				else
					display_menu();
				break;
			case 4:
				if (idx == 0)
				{
					printf("\e[1;1H\e[2J");
					printf("\n\n\n\t\t\t\tThe list is empty add new tasks\n");
				}
				else
					modif_menu();
				break;
			case 5:
				if (idx == 0)
				{
					printf("\e[1;1H\e[2J");
					printf("\n\n\n\t\t\t\tThe list is empty add new tasks\n");
				}
				else
				{
					printf("Please enter the ID of the task you want to remove: ");
					scanf("%d", &choice);
					if (search(choice) == NULL)
						printf("Invalid ID try again\n");
					else
						remove_task(choice);
				}
				break;
			case 6:
				if (idx == 0)
				{
					printf("\e[1;1H\e[2J");
					printf("\n\n\n\t\t\t\tThe list is empty add new tasks\n");
				}
				else
					search_menu();
				break;
			case 7:
				if (idx == 0)
				{
					printf("\e[1;1H\e[2J");
					printf("\n\n\n\t\t\t\tThe list is empty add new tasks\n");
				}
				else
					statistic_menu();
				break;
			case 8:
				printf("\e[1;1H\e[2J");
				printf("\n\n\n\t\t---------------Exiting the program. Thank you for using ToDo Task Management!---------------\n");
				sleep(3);
				printf("\e[1;1H\e[2J");
				return (0);
			default:
				printf("\e[1;1H\e[2J");
				printf("\n\n\n\t\t\t\tInvalid choice. Please try again...\n\n\n");
				sleep(2);
		}
	}
}
