#ifndef		SAS
#define		SAS
#include	<stdio.h>
#include	<unistd.h>
#include	<string.h>
#include	<time.h>
#include	<stdlib.h>

/**
 * todos - struct of todo list elements
 */

typedef	struct {
	int	id, D_day, D_month, D_year;
	char	title[50], description[100], status[10];
}todos;

//array of struct 
todos	todo[100];

//function swaps two structs
void	swap(int i, int j);

//alpha sorting
void	alpha_sort();

//adding the tasks
void	add_task(int);

//displaying the menu
void	display_menu();

//function searches with ID
todos	*search(int id);


//function removes task
void	remove_task(int id);

//function search by title
todos	*search_by_title(char title[]);

//function search by id
todos	*search(int id);

//function display search menu
void	search_menu();

//function modifies tasks
void	modif(int choice, int id);

//function display modification menu
void	modif_menu();

//function handle statistics side
void	statistic_menu();

//function prints the remaining days for each task
void	remaining();

//function sorts by deadline
void	deadline_sorting();

//function display tasks in 3 days or less
void	deadline_3_days();

#endif
