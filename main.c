#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

#define title_size 51
#define content_size 513
#define LOGFILE "logbook.txt"

typedef struct{
    uint32_t id;
    char title[title_size];
    char content[content_size];
    char date[20];
}logentry;


int add_entry(void)
{  
    logentry entry;

    uint32_t last_id = 0;

    FILE *file_check = fopen(LOGFILE, "r");
    if(file_check != NULL)
    {
    char line[600];
    while(fgets(line, sizeof(line), file_check) !=NULL) {
        uint32_t id_tmp;
        if (sscanf(line,"%" PRIu32 "|%*[^|]%*[^\n]", &id_tmp) == 1) {
           last_id = id_tmp;
                }
    }
        fclose(file_check);
    }
    entry.id = last_id +1;

    printf("title : ");
    scanf("%50[^\n]", entry.title);
    getchar();
    printf("content : ");
    scanf("%512[^\n]", entry.content);
    getchar();
    printf("entry: %"PRIu32"\ntitle: %s\ncontent: %s\n",
            entry.id, entry.title, entry.content);

    FILE *file = fopen("logbook.txt", "a");

    if (file != NULL){
        fprintf(file,"%"PRIu32"|%s|%s\n", entry.id, entry.title, entry.content);
        fclose(file);
        printf("log saved\n");
    }else {
    perror("error savign file");
    return 1;
    }
    printf("press any key to continue...");
    getchar();
    return 0;
}

int read_entries(void)
{   
    char line[600];
    int c;
    FILE *file = fopen(LOGFILE, "r");
    
    if(file == NULL){
    perror("Error opening file");
    return 1;
    }

    while (fgets(line,sizeof(line) , file) != NULL){
    printf("%s", line);
       }
    fclose(file);
    return 0;
    }


int main(void)
{
    uint32_t choice;

    do{
        printf("\n---Menu---\n");
        printf(" 1 - Add entry\n");
        printf("2 - Show entries\n");
        printf("3 - Quit\n");
        scanf("%"PRIu32"",&choice);
        while (getchar() != '\n');
        switch (choice) {
            case 1 : 
                add_entry();
                break;
            case 2 : 
                read_entries();
                break;
            case 3 : 
                printf("Exiting...\n");
                break;
            default :
                printf("Invalid choice, try again.\n");
        
        }
    }while(choice != 3);
    
    return 0; 
}
