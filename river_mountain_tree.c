#include <stdio.h>
#include <stdlib.h>

/* 
 *	This program aims to establish a non-profit 
 *	organization that provides education and resources 
 *	to impoverished communities.
 */
 
int main() {
	int num_members = 0;
	char name[50] = "";
	char focus[50] = "";
	
	// Get user input for organization name and focus
	printf("Please enter the name of the organization: ");
	scanf("%s", name);
	fflush(stdin);
	
	printf("Please enter the focus of the organization: ");
	scanf("%s", focus);
	fflush(stdin);
	
	// Establish the organizational structure
	struct org {
		char name[50];
		char focus[50];
		int members;
		struct member {
			char name[50];
			int age;
			char email[50];
		} m[100];
	};

	// Create the organization
	struct org organization;
	strcpy(organization.name, name);
	strcpy(organization.focus, focus);
	organization.members = num_members;

	// Loop until the user is finished adding members
	while (1) {
		// Get the user input for the member
		char memberName[50] = "";
		int memberAge = 0;
		char memberEmail[50] = "";
		
		printf("\nEnter member name (enter \"end\" to finish): ");
		scanf("%s", memberName);
		fflush(stdin);
		
		if (strcmp(memberName, "end") == 0) 
			break;
			
		printf("Enter age: ");
		scanf("%d", &memberAge);
		fflush(stdin);
		
		printf("Enter email: ");
		scanf("%s", memberEmail);
		fflush(stdin);
		
		strcpy(organization.m[num_members].name, memberName);
		organization.m[num_members].age = memberAge;
		strcpy(organization.m[num_members].email, memberEmail);
		
		// Increment the number of members
		num_members++;
		organization.members = num_members;
	
	}
	
	// Print a summary of the organization
	printf("\nOrganization Summary\n\nName: %s\nFocus: %s\nNumber of members: %d\n\n",  organization.name, organization.focus, organization.members);
	
	// Print the details of each member
	for (int i = 0; i < organization.members; i++) {
		printf("Name: %s\nAge: %d\nEmail: %s\n\n", organization.m[i].name, organization.m[i].age, organization.m[i].email);
	}
	
	return 0;
}