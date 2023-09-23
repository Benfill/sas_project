#include	"sas.h"

extern int idx;
extern todos	todo[100];

/**
 * search_by_title
 */

todos	*search_by_title(char title[])
{
	for (int i = 0; i < idx; i++)
	{
		if (strcasecmp(todo[i].title, title) == 0)
			return (&todo[i]);
	}
	return (NULL);
}

/**
 * search - function searchs with the id and returns a struct
 */

todos	*search(int id)
{
	for (int i = 0; i < idx; i++)
	{
		if (todo[i].id == id)
			return (&todo[i]);
	}
	return (NULL);
}

void	search_menu()
{
	char	choice[10];
	int	checker;
	int	id;
	char	title[20];
	todos	*tmp;
	printf("\e[1;1H\e[2J");
here:
	printf("\n\n\n\t\t\t\tSearch for Tasks Menu:\n");
	printf("1. Search for a task by its Identifier\n");
	printf("2. Search for a task by its Title\n\n");
	printf("Please enter your choice (1-2) or '3' to go back: ");
	scanf(" %[^\n]", choice);
	checker = atoi(choice);
	switch(checker)
	{
		case 1:
			printf("Please enter the task Identifier you want to search for: ");
			scanf("%d", &id);
			tmp = search(id);
			if (tmp == NULL)
			{
				printf("\e[1;1H\e[2J");
				printf("Invalid id. try again\n");
				goto here;
			}
			printf("\e[1;1H\e[2J");
			printf("+----+-----------------+----------------------+--------------+-------------+\n");
			printf("| ID |    Nom de la tâche   |    Description    |  Date d'échéance |    Statut|\n");
			printf("+----+-----------------+----------------------+--------------+-------------+\n");
			printf("| %-2d | %-19s | %-20s | %02d/%02d/%04d | %-15s |\n", tmp->id, tmp->title, tmp->description, tmp->D_day, tmp->D_month, tmp->D_year, tmp->status);
			break;
		case 2:
			printf("Please enter the task Title you want to search for: ");
			scanf(" %[^\n]", title);
			tmp = search_by_title(title);
			if (tmp == NULL)
			{
				printf("\e[1;1H\e[2J");
				printf("Invalid title. try again\n");
				goto here;
			}
			printf("\e[1;1H\e[2J");
			printf("+----+-----------------+----------------------+--------------+-------------+\n");
			printf("| ID |    Nom de la tâche   |    Description    |  Date d'échéance |    Statut|\n");
			printf("+----+-----------------+----------------------+--------------+-------------+\n");
			printf("| %-2d | %-19s | %-20s | %02d/%02d/%04d | %-15s |\n", tmp->id, tmp->title, tmp->description, tmp->D_day, tmp->D_month, tmp->D_year, tmp->status);
			break;
		case 3:
			break;
		default:
			printf("Invalid choice. try again!\n");
			goto here;
	 }
}
