/*** Linked List using memory alocation. This code has educational purpose. ***/
#include<stdio.h>

//Linked List of People
struct Person {
	char name[45];
	int age;
};
typedef struct Person P;

//Nodes list
struct Node {
	P info;
	struct Node *next;
};
typedef struct Node No;

//List pointers to begin and end
struct List {
	No *first, *last;
};

//Function to initialize the list pointers
void initialize(struct List *l) {
	l->first = NULL;
	l->last = NULL;
}

//Inclusion at the end
void insertEnd(struct List *l, P x) {
	No *aux;
	aux = malloc(sizeof(No));
	aux->info = x;
	aux->next = NULL;
	if(l->first == NULL) { //List is empty, then refresh the two pointers
		l->first = aux;
		l->last = aux;
	} else { //List is not empty, then refresh only last pointer
		l->last->next = aux;
		l->last = aux;
	}
}

//Function to display all fields of Person
void displayPerson(P x) {
	printf("\nName: %s", x.name);
	printf("\nAge: %d", x.age);
}

//Function to list all People
void list(struct List l) {
	while(l.first != NULL) {
		displayPerson(l.first->info);
		l.first = l.first->next;
	}
}

//Function to search by name 'p'
void search(struct List l, char p[45]) {
	while(l.first != NULL) {
		if(strcmp(p, l.first->info.name)==0) { //Exact comparison
			displayPerson(l.first->info);
		}
		l.first = l.first->next;
	}
}

//Function to display menu options
int menu() {
	int opt;
	printf("\n1. Insert;\n2. Delete;\n3. Search;\n4. List All;\n5. Exit.\n");
	printf("\nOption: ");
	scanf("%d", &opt);
	return(opt);
}

//Function to read the data from file called 'data.dat' and insert into Linked List (file -> memory)
void loadFile(struct List *l) {
	FILE *f;
	P aux;
	
	f = fopen("data.dat", "r"); 
	
	if(f != NULL) { //Test if file exists
		while(!feof(f)) { //Condition 'end-of-file'
			fread(&aux, sizeof(P), 1, f);
			if(!feof(f)) { //Prevent duplicated reading of the las element
				insertEnd(l, aux);
			}
		}
	}
}

//Function to save Linked List to a file called 'data.dat' (memory -> file)
void saveFile(struct List l) {
	FILE *f;
	
	f = fopen("data.dat", "w");
	
	while(l.first != NULL) { //Condition to end of list
		fwrite(&l.first->info, sizeof(P), 1, f);
		l.first = l.first->next;
	}

}

//Main function with some tests and menu
main() {
	struct List cad;
	P a;
	int opt;
	initialize(&cad);
	loadFile(&cad);
	do {
	
		opt = menu();
		
		switch(opt) {
			case 1:
				printf("\nName: ");
				__fpurge(stdin);
				gets(a.name);
				printf("\nAge: ");
				scanf("%d", &a.age);
				insertEnd(&cad, a);
				break;
			case 2: 
				printf("\nTODO: remove by name function\n"); //TODO List	
				break;
			case 3:
				printf("\nSearch by Name: ");
				__fpurge(stdin);
				gets(a.name);
				search(cad, a.name);
				break;
			case 4:
				list(cad);
				break;
			case 5:
				printf("\nExit ...\n");
				break;
			default:
				printf("\nInvalid Option!\n");
		}
	} while(opt != 5);	
	saveFile(cad);
}

