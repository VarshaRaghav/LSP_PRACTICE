#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>

int main(int argc, char**argv)
{
	 if(argc<3)
	 {
		 printf("Usage Error,%s<File Name to Be Copy><File Name copy path>\n",argv[0]);
		 exit(EXIT_FAILURE);
	 }
	 char* sourcefile;
	 char* destfile;


	 sourcefile= malloc(strlen(argv[1]+1));
	 destfile  = malloc(strlen(argv[2]+1));

	 strcpy(sourcefile,argv[1]);
         strcpy(destfile,argv[2]);

	 int fd= open(sourcefile,O_RDONLY);

	 if(fd<0)
	 {
		 perror("OPEN");
		 free(sourcefile);
		 free(destfile);
		 exit(EXIT_FAILURE);
	 }

	 free(sourcefile);

	/* char buffer[400000]={0};

	 ssize_t count= read(fd,buffer,400000);

	 if(count<0)
         {
		 perror("READ");
		 free(destfile);
		 exit(EXIT_FAILURE);

	 }		 
	 close(fd);
       */
	 int dest_fd = creat(destfile,S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH | S_IWOTH);

	 if(dest_fd<0)
	 {
		 perror("Write");
		 free(destfile);
		 exit(EXIT_FAILURE);
	 }
	 free(destfile);

	 char buffer[BUFSIZ]={0};

	 ssize_t count = 0,write_count=0;

	 while(count=read(fd,buffer,BUFSIZ)>0)
	 {
		 write_count=write(dest_fd,buffer,count);

		 if(write_count<0)

                 {
                 perror("WRITE");
                 exit(EXIT_FAILURE);
                 }

	 }

	 if(write_count<0)
         
	 {
		 perror("READ");
		 exit(EXIT_FAILURE);
	 }
	 close(fd);
	 close(dest_fd);

}
