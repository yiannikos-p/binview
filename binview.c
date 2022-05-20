#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	if(argc<4)
	{	
		perror("too few arguments\n");
		return 1;
	}
	int rows=atoi(argv[3]);
	int cols;
	if(argc==4)
	{
		cols=1;
	}
	else
	{
		cols=atoi(argv[4]);
	}
	if(strchr("iudfFgGeEaAoxX", argv[2][strlen(argv[2])-1]) == NULL)
	{
		perror("not a valid format\n");
		return 1;
	}

	FILE *data=fopen(argv[1],"rb");
	if(data==NULL)
	{
		perror("Failed to open file \n");
		return 1;
	}
	//okay now we good no errors

	char buffer[64]="\0";

	double val;
	for(int i=0;i<rows*cols||feof(data)!=0;i++)
	{
		if(i%cols==0&&i!=0)printf("\n");
		fread(&val,sizeof(double),1,data);
		sprintf(buffer,argv[2],val);
		printf("%s",buffer);
	}
	printf("\n");
	return 0;
}
