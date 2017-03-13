#include <stdio.h>
#include <string.h>

void PrintMenu();

typedef struct student {
	int number;
	char chName[30];
	char chYear[30];
	char chGrade[4];
} student;
int main(void)
{
	int nMenu = 0, nSearchMenu = 0, nNumber = 0;
	int i = 0, length = 0;
	char chName[30];
	char chYear[30];
	char chGrade[4];

	char strFileName[255];
	FILE *File;
	
	struct student s[100];


	

	for (;;)
	{
		PrintMenu();
		printf("Select Menu : ");
		scanf("%d", &nMenu);
		switch (nMenu)
		{
		case 1:	// Load
			for (;;)
			{
				printf("Select File\n  >> ");
				scanf("%s", strFileName);
				printf("%s, %d\n", &strFileName, strlen(strFileName));

				File = fopen(strFileName, "r");
				if (File == NULL)
				{
					printf("File is not exist!\n");
				}
				else
					break;
			}
			while (!feof(File))
			{
				fscanf(File, "%d %s %s %s", &s[i].number, &s[i].chName, &s[i].chYear, &s[i].chGrade);
				printf("%d %s %s %s\n", s[i].number, s[i].chName, &s[i].chYear, s[i].chGrade);
				i++;
				length = i;
			}
			fclose(File);
			continue;

		case 2: // Insert
			File = fopen(strFileName, "a+");

			printf("Insert Student Number : ");
			scanf("%d", &s[length].number);
			printf("Insert Student Name : ");
			scanf("%s", &s[length].chName);
			printf("Insert Student Year : ");
			scanf("%s", &s[length].chYear);
			printf("Insert Grade : ");
			scanf("%s", &s[length].chGrade);

			fprintf(File, "\n%d %s %s %s", s[length].number, s[length].chName, &s[length].chYear, s[length].chGrade);
			length++;

			fclose(File);
			continue;
		
		case 3: // Search
			File = fopen(strFileName, "r");

			printf("Seraching by...\n");
			printf("1. Student Number\n");
			printf("2. Student Name\n");
			printf("3. Student Year\n");
			printf("4. Student Grade\n  >>  ");
			scanf("%d", &nSearchMenu);

			switch (nSearchMenu)
			{
			case 1: // Searching by Student number
				printf("Insert Student Number\n  >>  ");
				scanf("%d", &nNumber);
				for (int j = 0; j < length; j++)
				{
					if (nNumber == s[j].number)
					{
						printf("%d %s %s %s\n", s[j].number, s[j].chName, &s[j].chYear, s[j].chGrade);
					}
				}
				break;

			case 2: // Searching by Student Name
				printf("Insert Student Name\n  >>  ");
				scanf("%s", &chName);
				for (int j = 0; j < length; j++)
				{
					if (!strcmp(chName, s[j].chName))
					{
						printf("%d %s %s %s\n", s[j].number, s[j].chName, &s[j].chYear, s[j].chGrade);
					}
				}
				break;

			case 3: // Searching by Student Year
				printf("Insert Student Year\n  >>  ");
				scanf("%s", &chYear);
				for (int j = 0; j < length; j++)
				{
					if (!strcmp(chYear, s[j].chYear))
					{
						printf("%d %s %s %s\n", s[j].number, s[j].chName, &s[j].chYear, s[j].chGrade);
					}
				}
				break;

			case 4: // Searching by Student Grade
				printf("Insert Student Grade\n  >>  ");
				scanf("%s", &chGrade);
				for (int j = 0; j < length; j++)
				{
					if (!strcmp(chGrade, s[j].chGrade))
					{
						printf("%d %s %s %s\n", s[j].number, s[j].chName, &s[j].chYear, s[j].chGrade);
					}
				}
				break;
			}
			 
			fclose(File);

			continue; // case 3: Search

		case 4: // Update
			File = fopen(strFileName, "w");
			printf("Insert Student Number\n  >>  ");
			scanf("%d", &nNumber);
			
			for (int j = 0; j < length; j++)
			{
				if (nNumber == s[j].number)
				{
					printf("Insert Student Number : ");
					scanf("%d", &s[j].number);
					printf("Insert Student Name : ");
					scanf("%s", &s[j].chName);
					printf("Insert Student Year : ");
					scanf("%s", &s[j].chYear);
					printf("Insert Grade : ");
					scanf("%s", &s[j].chGrade);

					for (i = 0; i < length; i++)
					{
						fprintf(File, "\n%d %s %s %s", s[i].number, s[i].chName, &s[i].chYear, s[i].chGrade);
					}
				}
			}
			fclose(File);
			continue;

		case 5:
			File = fopen(strFileName, "w");
			printf("Insert Student Number\n  >>  ");
			scanf("%d", &nNumber);

			for (int j = 0; j < length; j++)
			{
				if (nNumber == s[j].number)
				{
					for (int k = j; k < length; k++)
					{
						s[k].number = s[k + 1].number;
						strcpy(s[k].chName, s[k + 1].chName);
						strcpy(s[k].chYear, s[k + 1].chYear);
						strcpy(s[k].chGrade, s[k + 1].chGrade);
					}
					break;
				}
			}
			length--;
			for (i = 0; i < length; i++)
			{
				fprintf(File, "\n%d %s %s %s", s[i].number, s[i].chName, &s[i].chYear, s[i].chGrade);
			}
			fclose(File);
			continue;

		case 6:
			fclose(File);
			break;
		}
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
