#include	"sas.h"

extern	int	idx;

void	remaining()
{
	time_t now;
	struct tm deadline;
	time(&now);
	double secondsRemaining;

	printf("\n\n\n\t\t\t\tDays Remaining Until Deadline for Each Task:\n\n\n\n");

	for (int i = 0; i < idx; i++)
	{
		deadline.tm_year = todo[i].D_year - 1900;
		deadline.tm_mon = todo[i].D_month - 1;
		deadline.tm_mday = todo[i].D_day;
		deadline.tm_hour = 0;
		deadline.tm_min = 0;
		deadline.tm_sec = 0;
		time_t deadlineTime = mktime(&deadline);
		secondsRemaining = difftime(deadlineTime, now);
		int daysRemaining = (int)(secondsRemaining / (60 * 60 * 24));
		printf(">>>>Task %s: %d days remaining\n\n\n", todo[i].title, daysRemaining);
    }
}
