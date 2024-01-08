#include <stdio.h>
struct student{
	int usn;
	char name[50];
	float marks;
};
int main(void){
	struct student stud[5], *ptr;
	for(int i=0; i<5; i++){
		printf("Enter usn name marks: ");
		scanf("%d %s %f", &stud[i].usn, stud[i].name, &stud[i].marks);
	}
	printf("Strudnt records\n");
	for(ptr = stud; ptr<stud+5; ptr++){
		printf("%d %s %f\n", ptr->usn, ptr->name, ptr->marks);
	}
}
