#include<stdio.h>

struct Person {
	char name[45];
	int age;
};
typedef struct Person P;

struct Node {
	P info;
	struct Node *next;
};
typedef struct Node No;

struct List {
	No *first, *last;
};

void initialize(struct List *l) {
	l->first = NULL;
	l->last = NULL;
}

void insertEnd(struct List *l, P x) {
	No *aux;
	aux = malloc(sizeof(No));
	aux->info = x;
	aux->next = NULL;
	if(l->first == NULL) {
		l->first = aux;
		l->last = aux;
	} else {
		l->last->next = aux;
		l->last = aux;
	}
}

void displayPerson(P x) {
	printf("\nName: %s", x.name);
	printf("\nAge: %d", x.age);
}

void list(struct List l) {
	while(l.first != NULL) {
		displayPerson(l.first->info);
		l.first = l.first->next;
	}
}

void search(struct List l, char p[45]) {
	while(l.first != NULL) {
		if(strcmp(p, l.first->info.name)==0) {	
			displayPerson(l.first->info);
		}
		l.first = l.first->next;
	}
}

int menu() {
	int opt;
	printf("\n1. Insert;\n2. Delete;\n3. Search;\n4. List All;\n5. Exit.\n");
	printf("\nOption: ");
	scanf("%d", &opt);
	return(opt);
}

void loadFile(struct List *l) {
	FILE *f;
	P aux;
	
	f = fopen("data.dat", "r");
	
	if(f != NULL) {
		while(!feof(f)) {
			fread(&aux, sizeof(P), 1, f);
			if(!feof(f)) {
				insertEnd(l, aux);
			}
		}
	}
}

void saveFile(struct List l) {
	FILE *f;
	
	f = fopen("data.dat", "w");
	
	while(l.first != NULL) {
		fwrite(&l.first->info, sizeof(P), 1, f);
		l.first = l.first->next;
	}

}

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
				printf("\nTODO: remove by name function\n");	
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

