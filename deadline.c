#include	"sas.h"

extern	int	idx;
extern todos	todo[100];
time_t now;
struct tm deadline, deadline2;
double seconds;
int	compareTasks(int i)
{
	time(&now);
	deadline.tm_year = todo[i].D_year - 1900;
	deadline.tm_mon = todo[i].D_month - 1;
	deadline.tm_mday = todo[i].D_day + 1;
	deadline.tm_hour = 0;
	deadline.tm_min = 0;
	deadline.tm_sec = 0;
	time_t deadlineTime = mktime(&deadline);
	seconds = difftime(deadlineTime, now);
	return (seconds);
}

void	deadline_sorting()
{
	for (int i = 0; i < idx - 1; i++)
	{
		for (int j = 0; j < idx - i - 1; j++)
		{
			if (compareTasks(j) > compareTasks(j + 1))
				swap(j, j + 1);
		}
	}
}

void	deadline_3_days()
{
	for (int i = 0; i < idx; i++)
	{
		if ((86400 * 3) >= compareTasks(i))
		{
			if (todo[i].id != -1)
			{
				printf("\e[1;1H\e[2J");
				printf("+----+-----------------+----------------------+--------------+-------------+\n");
				printf("| ID |    Nom de la tâche   |    Description    |  Date d'échéance |    Statut|\n");
				printf("+----+-----------------+----------------------+--------------+-------------+\n");
				printf("| %-2d | %-19s | %-20s | %02d/%02d/%04d | %-15s |\n", todo[i].id, todo[i].title, todo[i].description, todo[i].D_day, todo[i].D_month, todo[i].D_year, todo[i].status);
			}
		}
	}
}

void	remaining()
{
	printf("\n\n\n\t\t\t\tDays Remaining Until Deadline for Each Task:\n\n\n\n");
	time(&now);
	for (int i = 0; i < idx; i++)
	{
		seconds = compareTasks(i);
		int daysRemaining = (int)(seconds / (60 * 60 * 24));
		if (todo[i].id != -1)
			printf(">>>>Task %s: %d days remaining\n\n\n", todo[i].title, daysRemaining);
    }
}
