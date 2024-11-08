#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//structure definition
typedef struct{
    int id;
    char *name;
    char *content;
}Note;

//function prototype
void list(Note *note);
void add(Note *note);
void del(Note *note);
void sort(Note *note);
void save(Note *note);
int find_note(Note *note,int id);
void id_swap(Note *note,int x);
void name_swap(Note *note,int x);
void content_swap(Note *note,int x);

int note_number=0;  //a global variable to save quantity of notes

//starting main function
int main(void)
{
    int i=0,j=0;
    char comma;
    char input[100];

    //allocate dynamic memory to save 1000000 notes
    Note* note = malloc(10000000*sizeof(Note));

    //open an existed file
    FILE* fptr;
    fptr = fopen("sample_short.txt","r");

    if(fptr!=NULL){
        //file opening succeed
        //keep scanning until the end of file
        while(fscanf(fptr,"%d",&(note+i)->id)!=EOF){
            fscanf(fptr,"%d",&(note+i)->id);  //save integers in note->id
            fscanf(fptr,"%c",&comma);  //save comma after any ID in a character memory

            //allocate dynamic memory to save 50 characters of name
            (note+i)->name = malloc(50*sizeof(char));
            for(j=0;;j++){
                //scan until meeting ',' and save the characters in note->name
                fscanf(fptr,"%c",(note+i)->name+j);
                if(*((note+i)->name+j)==',') break;
            }

            //allocate dynamic memory to save 4096 characters of content
            (note+i)->content = malloc(4096*sizeof(char));
            for(j=0;;j++){
                //scan until the end of line and save the characters in note->content
                fscanf(fptr,"%c",(note+i)->content+j);
                if(*((note+i)->content+j)=='\n') break;
            }

            note_number++;  //the quantity of notes +1
            i++;  //keep scanning next line
        }
    }
    else{
        //file opening failed
        printf("FILE DOES NOT EXIST!");
        return 0;  //end program
    }

    for(;;){
        //let users to input commands
        printf(">");
        scanf(" %s",input);
        while(getchar()!='\n');
        if(strcmp("list",input)==0){
            //if input "list", list all notes on the screen
            list(note);
        }
        else if(strcmp("add",input)==0){
            //if input "add", let the user to add a new note
            add(note);
        }
        else if(strcmp("delete",input)==0){
            //if input "delete", let the user delete note by ID
            del(note);
        }
        else if(strcmp("sort",input)==0){
            //if input "sort", sort all notes by ID
            sort(note);
        }
        else if(strcmp("save",input)==0){
            //if input "save", save all notes in memory to a new file
            save(note);
        }
        else if(strcmp("exit",input)==0){
            //if input "exit", free the dynamic memory, close the file and end program
            free(note);
            fclose(fptr);
            return 0;
        }
        else printf("Not valid command.\n");
    }
}

void list(Note *note)  //list all notes on the screen
{
    int i,j;

    for(i=0;i<note_number;i++){
        printf("%d,",(note+i)->id);  //print id
        for(j=0;(note+i)->name[j]!='\0';j++){
            printf("%c",(note+i)->name[j]);  //print name
        }
        for(j=0;(note+i)->content[j]!='\0';j++){
            printf("%c",(note+i)->content[j]);  //print content
        }
        //start printing a new line
    }
}

void add(Note *note)  //let the user to add a new note
{
    int i;
    char comma;

    //same way to scan note as the main function
    scanf("%d",&(note+note_number)->id);
    scanf("%c",&comma);

    //allocate dynamic memory for the new note
    (note+note_number)->name = malloc(50*sizeof(char));
    (note+note_number)->content = malloc(4096*sizeof(char));

    for(i=0;;i++){
        scanf("%c",(note+note_number)->name+i);
        if(*((note+note_number)->name+i)==',') break;
    }

    for(i=0;;i++){
        scanf("%c",(note+note_number)->content+i);
        if(*((note+note_number)->content+i)=='\n') break;
    }

    note_number++;  //the quantity of notes +1
}

void del(Note *note)  //let the user delete note by ID
{
    int ID,i,j;

    //let user enter the ID which the user wants to remove
    printf("(id)<");
    scanf("%d",&ID);

    i=find_note(note,ID);  //starting from the input note

    if(find_note(note,ID)!=-1){
        //move the id,name,content of the note to the former one
        while(i<note_number-1){
            (note+i)->id=(note+i+1)->id;
            for(j=0;*((note+i+1)->name+j)!='\0';j++){
                *((note+i)->name+j)=*((note+i+1)->name+j);
            }
            *((note+i)->name+j)='\0';  //add '\0' at the end of the string
            for(j=0;*((note+i+1)->content+j)!='\0';j++){
                *((note+i)->content+j)=*((note+i+1)->content+j);
            }
            *((note+i)->content+j)='\0';  //add '\0' at the end of the string
            i++;
        }

        note_number--;  //the quantity of notes -1
    }
    else printf("Note does not exist!\n");  //if the note does not exist
}

void sort(Note *note)  //sort all notes by ID
{
    int i,j;

    //sort the notes by using Bubble Sort
	for(i=0;i<note_number-1;i++){
		for(j=0;j<note_number-1-i;j++){
			if((note+j)->id > (note+j+1)->id){  //the case when the former is bigger than the latter
                id_swap(note,j);  //swap id
                name_swap(note,j);  //swap name
                content_swap(note,j);  //swap content
			}
		}
	}
}

void id_swap(Note *note,int x)  //swap id by using Bubble Sort
{
    int temp;

    temp = (note+x)->id;  //move the former to temp
    (note+x)->id = (note+x+1)->id;  //move the latter to the former
    (note+x+1)->id = temp;  //move temp to the latter
}

void name_swap(Note *note,int x)  //swap name by using Bubble Sort
{
    //allocate dynamic memory
    char *temp = malloc(50*sizeof(char));

    strcpy(temp,(note+x)->name);  //copy the former to temp
    strcpy((note+x)->name,(note+x+1)->name);  //copy the latter to the former
    strcpy((note+x+1)->name,temp);  //copy temp to the latter

    //free the dynamic memory
    free(temp);
}

void content_swap(Note *note,int x)  //swap content by using Bubble Sort
{
    //allocate dynamic memory
    char *temp = malloc(4096*sizeof(char));

    strcpy(temp,(note+x)->content);  //copy the former to temp
    strcpy((note+x)->content,(note+x+1)->content);  //copy the latter to the former
    strcpy((note+x+1)->content,temp);  //copy temp to the latter

    //free the dynamic memory
    free(temp);
}

void save(Note *note)  //save all notes in memory to a new file
{
    int i,j;

    //open a new file named "newnote.txt" to write
    FILE *fptr;
    fptr = fopen("newnote.txt","w");

    if(!fptr){
        printf("File Creation Failed.\n");
    }
    else{
        //same way as list function
        for(i=0;i<note_number;i++){
            fprintf(fptr,"%d,",(note+i)->id);
            for(j=0;(note+i)->name[j]!='\0';j++){
                fprintf(fptr,"%c",(note+i)->name[j]);
            }
            for(j=0;(note+i)->content[j]!='\0';j++){
                fprintf(fptr,"%c",(note+i)->content[j]);
            }
        }
        printf("File Creation Succeed.\n");
    }

    //close the file
    fclose(fptr);
}

int find_note(Note *note,int id)  //find the note number by inputing ID
{
    int i;

    for(i=0;i<note_number;i++){
        if((note+i)->id==id) return i;  //return the number
    }
    return -1;  //if not an existing note, return -1
}
//finished finally...
