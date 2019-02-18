/*---------------------------------------------------------*/
/*	Author	    : Thennarasu.D	                   */
/*	Date	    : 18Feb2019			           */
/*	Filename    : lseek.c			           */
/*	Description : input_output_regular_file	           */
/*---------------------------------------------------------*/



/* include header file  */
#include "lseek.h"

/* Global variable declaraations  */

/* Function defenition and prototype  */

int main(int argc,char *argv[])
{
	int file_descriptor;
	ssize_t ret_write;
	char str1[] = " Hi i'm thennarasu writing this file ,What are you doing " ;
	off_t ret_lseek;


	if(argc>1)
	{
	/* open a file or creates and opens a new file  */
	/*int open(const char * pathname , int flags , ... mode_t mode)*/
	file_descriptor = open(argv[1], O_CREAT | O_WRONLY,0644);
	perror("open:");

	/* off_t lseek(int fd , off_t offset , int whence) */
	ret_lseek = lseek(file_descriptor,0,SEEK_SET);

	/* write a data to an open file  */
	/* ssize_t write(int fd, void * buffer , size_t count ) */
	ret_write = write(file_descriptor,str1,strlen(str1)+1);
	perror("write");
	}
	else 
	{

	/* open a file or creates and opens a new file  */
	/*int open(const char * pathname , int flags , ... mode_t mode)*/
	file_descriptor = open("./ten",O_CREAT | O_WRONLY,0644);
	perror("open");

	/* off_t lseek(int fd , off_t offset , int whence) */
	ret_lseek = lseek(file_descriptor,0,SEEK_SET);

	/* write a data to an open file  */
	/* ssize_t write(int fd, void * buffer , size_t count ) */
	ret_write = write(file_descriptor,str1,strlen(str1)+1);
	perror("write");
	}

	/* close a file  */
	close(file_descriptor);
	perror("close");
}
