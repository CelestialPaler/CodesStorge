#include "stdio.h"
#include "malloc.h"

typedef struct {
	unsigned int id;
	unsigned int age;
	unsigned int serialNum;
	unsigned int credits;
	unsigned int grade;
	char firstName[16];
	char secondName[16];
	char major[64];
}Profile;

int main(int args, char ** argv) {
	unsigned int idCounter = 0;
	char endFlag = 'N';
	FILE * fp = fopen("Student Profiles.txt", "w");
	printf("\nPlease enter your infomation as instruction.");
	do {
		fflush(stdin);
		Profile * newProfile = (Profile *)malloc(sizeof(Profile));
		newProfile->id = idCounter++;
		printf("\nYour firstname ?");
		scanf("%s", newProfile->firstName);
		printf("\nYour secondname ?");
		scanf("%s", newProfile->secondName);
		printf("\nYour major ?");
		scanf("%s", newProfile->major);
		printf("\nYour age ?");
		scanf("%d", &newProfile->age);
		printf("\nYour serial number of student`s identification card ?");
		scanf("%d", &newProfile->serialNum);
		printf("\nYour accumulative total of effective credits ?");
		scanf("%d", &newProfile->credits);
		printf("\nYour grade ?");
		scanf("%d", &newProfile->grade);

		printf("\n %d  %s %s %d %d %d %d",
			idCounter,
			newProfile->firstName,
			newProfile->secondName,
			newProfile->age,
			newProfile->serialNum,
			newProfile->credits,
			newProfile->grade);

		fprintf(fp, "%d | %s | %s | %d | %d | %d | %d \n",
			idCounter,
			newProfile->firstName,
			newProfile->secondName,
			newProfile->age,
			newProfile->serialNum,
			newProfile->credits,
			newProfile->grade);

		free(newProfile);
		printf("\nEnd?");
		scanf("%c",&endFlag);
	} while (endFlag == 'Y');

	fclose(fp);
	return 0;
}
