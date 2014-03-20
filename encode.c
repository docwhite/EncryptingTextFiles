/*
       C language - UNIX style encryption program for ascii textfiles - (c) Eike Falk Anderson, 2013
*/

#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#define PUSAGE fprintf(stderr,"USAGE: %s [source file] [destination file] [key]\n\n",argv[0]) /* predefined error/usage message */


/* compile with gcc encode.c -o encode

   when you run this program it takes three inputs/parameters:
   1. the name of your sourse text file (the ASCII text file you want to encode)
   2. the name of your destination text file (the file that will have the encoded text in it)
   3. the keyword (the "password" for the encoded file)

   example:
   ./encode source.txt dest.txt secret
*/


int main(int argc,char *argv[]) /* argument vector 0 - program-name, argv 1 - source string, argv 2 - dest string, argv 3 - key string */
{
	int counter; /* a counter variable for counting through the characters of the password */
	int input;
	unsigned char letter,lo,hi,rev,inv,enc; /* variables used for the letters of the text during the coding process */
	FILE *sfp=NULL; /* source file pointer */
	FILE *dfp=NULL; /* destination file pointer */

	if((sfp=fopen(argv[1],"r"))==NULL) /* open the text file (sfp) named in argument vector 1 for reading - print error message if this operation fails */
	{
		fprintf(stderr,"UNABLE TO OPEN FILE\n");
		PUSAGE;
		return 1; /* end program with error */
	}
	if((dfp=fopen(argv[2],"w"))==NULL) /* open the text file (dfp) named in argument vector 2 for writing - print error message if this operation fails */
	{
		fprintf(stderr,"UNABLE TO OPEN FILE\n");
		PUSAGE;
		return 1; /* end program with error */
	}
	
	counter=0; /* set the keyword character counter to 0 */
	while((input=fgetc(sfp))!=EOF) /* process the source file by reading in the next letter (as 1 character/byte each) until the file ends, i.e. the EOF (end of file) character is read in */
	{
		if(counter==strlen(argv[3])) counter=0; /* reset if the keyword overflows, i.e. if its end (string length) is reached */
		
		letter=(unsigned char)input;
		/* do something to the read in characters/bytes */ 
		lo=letter<<4;
		hi=letter>>4;
		rev=hi|lo;
		inv=~rev;
		enc=inv^argv[3][counter]; 
		
		counter++; /* increase the counter, i.e. step to the next character of the keyword */
		
		fputc(enc,dfp);           /* write the encoded character to the destination file */	
		fputc(enc,stdout);
	}
	
	fclose(sfp); /* close file sfp */
	fclose(dfp); /* close file dfp */
  
	return 0; /* end with success */
}
