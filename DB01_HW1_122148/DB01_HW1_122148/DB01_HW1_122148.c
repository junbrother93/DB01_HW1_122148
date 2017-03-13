#include <stdio.h>
#include <string.h>

void PrintMenu();

int main(void)
{
	int nMenu = 0;
	char strFileName[255];
	char str
	FILE *File;



	PrintMenu();
	printf("Select Menu : ");
	scanf("%d", &nMenu);

	switch(nMenu)
	{
	case 1:
		printf("Select File\n  >> ");
		scanf("%s", strFileName);
		printf("%s, %d\n", &strFileName, strlen(strFileName));
		File = fopen(strFileName, "r");
		fscanf(File, "%s"
		break;
	}

	return 0;
}

void PrintMenu()
{
	printf("1. Load\n");
	printf("2. Insert\n");
	printf("3. Search\n");
	printf("4. Update\n");
	printf("5. Delete\n");
	printf("6. Exit\n");
}