#include <stdio.h>
#include <string.h>
typedef struct{
    int teamId;
    char teamName[100];
    char teamCity[100];
    double teamBudget;
    int teamScore;
} team;
int getNumberofTeams(char inputFile[]){
    FILE *file_name;
    file_name = fopen(inputFile, "r");
    if (file_name == NULL){
        printf("Error with opening File\n");
    }
    int n = 1;
    char c = fgetc(file_name);
    while(c != EOF){
        if(c == '\n'){
            n++;
        }
        c = fgetc(file_name);
    }
    fclose(file_name);
    return n;
}

int init(team list[], char inputFile[]){
    FILE *file_name;
    file_name = fopen(inputFile, "r");
    if(file_name == NULL){
        printf("Error with opening File\n");
    }
    int n;
    fscanf(file_name, "%i", &n);
    for(int i = 0; i < n; i++){
        fscanf(file_name, "%i %s %s %lf %i", &list[i].teamId, &list[i].teamName, &list[i].teamCity, &list[i].teamBudget, &list[i].teamScore);

    }
    fclose(file_name);
    return 0;
}
int printsScoreBoard(team list[], int n){
    printf("Printing the Scoreboard\n");
    for(int i = 0; i < n-2; i ++){
        printf("%i %s %s %0.2lf %i\n", list[i].teamId, list[i].teamName, list[i].teamCity, list[i].teamBudget, list[i].teamScore);
    }
    return 0;
}
int writeTheChampion(team list[], int n){
    printf("The champion is\n");
    int max = 0;
    int max_index = 0;
    for(int i = 0; i < n; i ++){
        if(max < list[i].teamScore){
            max = list[i].teamScore;
            max_index = i;
        }
    }
    printf("%i %s %s %0.2lf %i\n", list[max_index].teamId, list[max_index].teamName, list[max_index].teamCity, list[max_index].teamBudget, list[max_index].teamScore);
    return 0;
}
int processGames(char inputFile[], team list[], int n){
    FILE *file_name_1;
    file_name_1 = fopen(inputFile, "r");
    if(file_name_1 == NULL){
        printf("Error with opening File\n");
    }
    int team_id_1, team_id_2, res, score;
    int n_1 = getNumberofTeams(inputFile);
    for(int i = 0; i < n_1; i++){
        fscanf(file_name_1, "%i %i %i %i", &team_id_1, &team_id_2, &res, &score);
        if(res == 1){
            for(int j = 0; j < n; j++){
                if(team_id_1 == list[j].teamId){
                    list[j].teamScore = list[j].teamScore + score;
                }
            }
        }
        if(res == 2){
            for(int j = 0; j < n; j++){
                if(team_id_2 == list[j].teamId){
                    list[j].teamScore = list[j].teamScore + score;
                }
            }
        }
        if(res == 0){
            int id_1, id_2;
            for(int j = 0; j < n; j++){
                if(team_id_2 == list[j].teamId){
                    id_2 = j;
                }
            }
            for(int j = 0; j < n; j++){
                if(team_id_1 == list[j].teamId){
                    id_1 = j;
                }
            }
            list[id_1].teamScore = list[id_1].teamScore + score;
            list[id_2].teamScore = list[id_2].teamScore + score;
        }
    }
    fclose(file_name_1);
    return 0;
}
int main(){
    char inputFile[100];
    strcpy(inputFile,"input.txt");
    int n = getNumberofTeams(inputFile);
    team list[n];
    init(list, inputFile);
    printsScoreBoard(list, n);
    writeTheChampion(list, n);
    printf("\n\n");
    strcpy(inputFile, "games.txt");
    processGames(inputFile, list, n);
    printsScoreBoard(list, n);
    writeTheChampion(list, n);
    return 0;
}