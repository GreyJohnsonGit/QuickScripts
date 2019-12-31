#include <stdio.h>
#include <string.h>

#define OUTFILE "out.csv"
#define INFILE "Surveys.csv"
#define MAX_AREA_LENGTH 10
#define MAX_SURVEY_DIGITS 10
#define NUMBER_OF_QUESTIONS 21

struct row_t {
    char area[MAX_AREA_LENGTH + 1];
    char survey_ID[MAX_SURVEY_DIGITS + 1];
    char responses[NUMBER_OF_QUESTIONS];
};

int main() {

    FILE* inFile = fopen(INFILE, "r");
    FILE* outFile = fopen(OUTFILE, "a");

    char* exercises[NUMBER_OF_QUESTIONS] = {
                                            "0 – Greg & Steve Message",
                                            "1 – Followership", "1 – Followership", "1 – Followership",
                                            "2 – Identifying High Risk", "2 – Identifying High Risk",
                                            "3 – Task Switching", "3 – Task Switching", "3 – Task Switching", "3 – Task Switching",
                                            "4 – Lapses & Slips", "4 – Lapses & Slips", "4 – Lapses & Slips",
                                            "5 – Mindfulness", "5 – Mindfulness", "5 – Mindfulness", "5 – Mindfulness", "5 – Mindfulness", "5 – Mindfulness",
                                            "6 – Complacency Test", "6 – Complacency Test"};
    char* questions[NUMBER_OF_QUESTIONS] = {
                                            "1 – Positive Change",
                                            "1 – Concepts Understood",
                                            "2 – Effective & Helpful",
                                            "3 – Help Coworkers",
                                            "1 – Identify Personal Risks",
                                            "2 – Workshop Helpful to Others",
                                            "1 – Concepts Understood",
                                            "2 – Workshop Helpful to Others",
                                            "3 – Reconsider Multitasking",
                                            "4 – Conscious Effort to be Present",
                                            "1 – Concepts Understood",
                                            "2 – Better Able to Deal with Slips & Lapses",
                                            "3 – Need More Help",
                                            "1 – Breathing Concept Interesting",
                                            "2 – High Risks and Mindfulness Makes Sense",
                                            "3 – Mindfulness Will be Useful to Me",
                                            "4 – Will Use Breathing in Future",
                                            "5 – Mindfulness Could Help Industry",
                                            "6 – Mindfulness can be Shared at Home",
                                            "1 – Recognize Complacent Tasks",
                                            "3 – Better Able to Overcome Complacency"};
    
    char line[64];
    char* curLoc = line;
    char* endLoc = NULL;
    struct row_t row;
    while(fgets(line, 64, inFile) != NULL) {
        curLoc = line;
        endLoc = strchr(curLoc, ',');
        strncpy(row.area, curLoc, (endLoc - curLoc));
        row.area[endLoc-curLoc] = '\0';

        curLoc = endLoc + 1;
        endLoc = strchr(curLoc, ',');
        strncpy(row.survey_ID, curLoc, (endLoc - curLoc));

        curLoc = endLoc + 1;
        for(int i = 0; i < NUMBER_OF_QUESTIONS; i++) {
            row.responses[i] = curLoc[i*2];
            fprintf(outFile, "%s,%s,%s,%s,%c\n", row.area, row.survey_ID, exercises[i], questions[i], row.responses[i]);
        }
    }
    return 1;
}
