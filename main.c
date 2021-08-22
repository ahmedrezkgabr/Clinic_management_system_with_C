/*
Created By: Ahmed Rezk
E-mail:     ahmedrezkofficial@gmail.com
Mobile:     +201001525033
Date:       Aug 2021
Address:    Mansoura, Egypt
Name:       clinic System by C
Mentors:    -ENG/Alaa Elnagar
			-ENG/Abdelrahman Mosad
Course:     Embedded systems summer training diploma
Institute:  ITI-Information Technology Institute Mansoura Branch
*/

#include <stdio.h>			//including standerd input output
#include <stdlib.h>
#include "STD_TYPES.h"		//including standard types


void add(void);				//prototype of the function that adds a new patient
void edit(void);			//prototype of the function that edits a patient information
void reserve(void);			//prototype of the function that reserve a slot
void cancle(void);			//prototype of the function that cancle a slot
void view_patient(void);	//prototype of the function that view patient information
void view_reserve(void);	//prototype of the function that view slots

//struct defination
typedef struct patient_node
{
	//members
    u8 name[20];
    u32 gender;
    u32 age;
    u32 ID;
	//pou32er that will pou32 to the next node
    struct patient_node *next;
}node;	//name of struct that will be used

//creating a pou32er of type patient_node pou32s to NULL
struct patient_node *head = NULL;
u8 list_length = 0;

u32 Global_u32PassWord;
u8 Global_slots[5] = {0,0,0,0,0};
void main(void)
{

    u8 Local_u8Choice;		//the choice of the mode
    u8 choice;				//the choice of the need
	//taking the mode choice of the mode
	printf("\n");
    printf("Please Entre Your Choice\n");
    printf("1 for admin mode\n");
    printf("2 for user mode\n");
    printf("3 for ending the system\n");
    printf("Your choice: ");
    scanf(" %u",&Local_u8Choice);
	printf("\n");
	
    while(Local_u8Choice != 3)
    {
        switch(Local_u8Choice)
        {
			case 1:				//admin mode
				//taking the password and iterating for 3 times
				printf("\n");
				printf("Welcome to admin mode\n");
				printf("entre password\n");
				for(u8 j = 0; j < 3; j++)
				{
					scanf("%u",&Global_u32PassWord);
					if(Global_u32PassWord == 1234)
					{
						break;
					}
					printf("wrong password try again\n");
				}

				if(Global_u32PassWord != 1234)		//the pasword enterd 3 times wrong
					break;							//will break ot of the while loop

				//taking the choice of wanted action
				printf("\n");
				printf("entre your choice\n");
				printf("1 for adding new patient record\n");
				printf("2 for editing patient record\n");
				printf("3 for reserving a slot\n");
				printf("4 for cancle a slot\n");
				printf("Your choice: ");
				scanf("%u",&choice);
				printf("\n");
				

				switch(choice)
				{
					case 1:
						add();		//calling the function of add
						break;
					case 2:
						edit();		//calling the function of edit
						break;
					case 3:
						reserve();	//calling the function of reserve
						break;
					case 4:
						cancle();	//calling the function of cancle
						break;

				}

				break;

			case 2:				//user mode
				//taking the choice of the action
				printf("\n");
				printf("entre your choice\n");
				printf("1 for viewing information of a patient\n");
				printf("2 for viewing slots\n");
				printf("Your choice: ");
				scanf("%u",&choice);
				printf("\n");
				

				switch(choice)
				{
				case 1:
					view_patient();		//calling the function of the view information
					break;
				case 2:
					view_reserve();		//calling the function of the view slots
					break;
				}
				break;

			
        }
		printf("\n");
		printf("Please Entre Your Choice\n");
		printf("1 for admin mode\n");
		printf("2 for user mode\n");
		printf("3 for ending the system\n");
		printf("Your choice: ");
		scanf(" %u",&Local_u8Choice);
		printf("\n");
    }
}



/*----------Admin Mode Functions----------*/
void add(void)
{
	//this function will check the length of the linked list_length
	//if it is equal to zero the function will add the first node in the list_length
	//if the length is not equal zero the pou32re of the new one will take the head and increase untill the next of it is null
	//then the function will allocate the members
	//the last thing is to increase the length

	//taking the informationS
	u8 Local_name[20];
    u32 Local_gender;
    u32 Local_age;
    u32 Local_ID;
	printf("entre the name: ");
	scanf("%s",Local_name);
	printf("entre the gender '0'for male '1' for female: ");
	scanf("%d",&Local_gender);
	printf("entre the age: ");
	scanf("%d",&Local_age);
	printf("entre the ID: ");
	scanf("%d",&Local_ID);

	if(list_length == 0)
	{
		node *new = (node*) malloc(sizeof(node));
		head = new;
		for(u8 i = 0 ; i < 20 ; i++)
		{
			new -> name[i] = Local_name[i];
		}
		new -> gender = Local_gender;
		new -> age = Local_age;
		new -> ID = Local_ID;
		new -> next = NULL;
	}
	else
	{
		node *new = (node*) malloc(sizeof(node));
		node *last;
		last = head;
		while((last -> next) != NULL)
		{
			last = (last -> next);
		}
		last->next = new; //  انت هنا كنت عامل new = last
		last = last-> next ; // record 1
		for(u8 i = 0 ; i < 20 ; i++)
		{
			last-> name[i] = Local_name[i];
		}
		last -> gender = Local_gender;
		last -> age = Local_age;
		last -> ID = Local_ID;
		last -> next = NULL;
	}
	list_length++;
}

void edit(void)
{
	//this function will take the id from the user
	//then will increase the head pou32er to reach the wanted one
	//then it will take the new values and allocate them
	u32 edit_id;
	printf("entre the id");
	scanf(" %d",&edit_id);
	node *want;
	want = head;
	while((want -> ID) != edit_id)
	{
		want = want -> next;
	}
	u8 Local_name[20];
    u32 Local_gender;
    u32 Local_age;
    u32 Local_ID;
	printf("entre the new values\n");
	printf("entre the name: ");
	scanf("%s",Local_name);
	printf("entre the gender: ");
	scanf("%d",&Local_gender);
	printf("entre the age: ");
	scanf("%d",&Local_age);
	printf("entre the ID: ");
	scanf("%d",&Local_ID);
	for(u8 i = 0 ; i < 20 ; i++)
	{
		want -> name[i] = Local_name[i];
	}
	want -> gender = Local_gender;
	want -> age = Local_age;
	want -> ID = Local_ID;
	printf("the information updated");
}

void reserve(void)
{
	//this function will show the slots that can be used
	//the user will entre the wanted one and then allocate the id in the array of the slots
	//printing the slots number
	printf("0 for 2:00pm\n");
	printf("1 for 2:30pm\n");
	printf("2 for 3:00pm\n");
	printf("3 for 3:30pm\n");
	printf("4 for 4:00pm\n");
	printf("valid slots is\n");
	//printing the valid slots
	for(u8 i = 0; i < 5; i++)
	{
		//valid slots which are equal to zero
		if(Global_slots[i] = 0)	
		{
			printf("%d\n",Global_slots[i]);
		}
	}
	//taking the slot number and the id and make a slot
	u32 slot;
	u32 slot_id;
	printf("entre the number of the slot");
	scanf("%d",&slot);
	printf("entre the id of the patient");
	scanf("%d",&slot_id);
	Global_slots[slot] = slot_id;
	printf("the slot reserved\n");
}

void cancle(void)
{
	//this function will allocate zero to a slot
	//take the slot number and allocate its place with 0 to make it valid to reserving
	u32 slot;
	printf("entre the number of the slot");
	scanf("%u",&slot);
	Global_slots[slot] = 0;
	printf("cancled\n");
}

/*----------User Mode Functions----------*/
void view_patient(void)
{
	//the user will entre the id and then its information will be viewed
	u32 Local_ID;
	printf("entre the id: ");
	scanf("%d",&Local_ID);
	node *want;
	want = head;
	while((want -> ID) != Local_ID)
	{
		want = want -> next;
	}
	printf("the name is %s\n",(want->name));
	printf("the gender is %d\n",(want->gender)); // %d wihout %s
	printf("the age is %d\n",(want->age)); // %d wihout %s
}

void view_reserve(void)
{
	//this functon will show the slots and its IDs
	printf("2:00pm: %u\n",Global_slots[0]);
	printf("2:30pm: %u\n",Global_slots[1]);
	printf("3:00pm: %u\n",Global_slots[2]);
	printf("3:30pm: %u\n",Global_slots[3]);
	printf("4:00pm: %u\n",Global_slots[4]);
}

