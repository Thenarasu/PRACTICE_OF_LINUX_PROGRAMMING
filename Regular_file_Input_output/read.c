/*----------------------------------------------------*/
/*	Author	    : Thennarasu.D		      */
/*	Date	    : 18Feb2019			      */
/*	Filename    : read.c			      */
/*	Description : read a regular_file	      */
/*----------------------------------------------------*/



/* include header file  */
#include "file.h"

/* Global variable declaraations  */

/* Function defenition and prototype  */

int main(int argc,char *argv[])
{
	int file_descriptor;
	ssize_t ret_read;
	char str1[200] ;



	if(argc>1)
	{
	/* open a file or creates and opens a new file  */
	/*int open(const char * pathname , int flags , ... mode_t mode)*/
	file_descriptor = open(argv[1],O_RDONLY,0644);
	perror("open:");

	/* read a data to an open file  */
	/* ssize_t read(int fd, void * buffer , size_t count ) */
	ret_read = read(file_descriptor,str1,25);
	perror("read");
	str1[26] = '\0';
	printf("%s\n",str1);
	}
	else 
	{

	/* open a file or creates and opens a new file  */
	/*int open(const char * pathname , int flags , ... mode_t mode)*/
	file_descriptor = open("./ten",O_RDONLY,0644);
	perror("open");

	/* read a data to an open file  */
	/* ssize_t read(int fd, void * buffer , size_t count ) */
	ret_read = read(file_descriptor,str1,25);
	str1[26] = '\0';
	perror("read");
	printf("%s",str1);
	}

	/* close a file  */
	close(file_descriptor);
	perror("close");
}
