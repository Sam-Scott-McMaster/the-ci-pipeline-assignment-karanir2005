/* CI Pipeline Assignment - a quiz application with questions about C, Git and Linux.
*
* Rushil Karani
* September 29th, 2024
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int num_args, char *args[]) { //main method takes the number of arguments, and the arguments themselves, as parameters.
    if (num_args < 2) {
        printf("Usage: quiz [-#] [<answer>]\n");
        printf("Try 'quiz --help' for more information.\n"); //if number or arguments is <2 (./quiz is the first argument)
                                                             //then print a usage message and return EXIT_FAILURE
        return EXIT_FAILURE;
    }

    if (strcmp(args[1], "--help") == 0) { //if user calls the help function then display the help list and return EXIT_SUCCESS
        printf("Usage: quiz [-#] [<answer>]\n");
        printf("Options:\n");
        printf("  -1    Display question 1\n");
        printf("  -2    Display question 2\n");
        printf("  -3    Display question 3\n");
        printf("  -# \"answer\"    Verify answer to question #\n");
        printf("  --help    Show help message\n");
        return EXIT_SUCCESS;
    }

    if (args[1][0] == '-' && args[1][1] >= '1' && args[1][1] <= '3'){ //checks if syntax is valid and if question number is between 1 and 3
        int q_num = args[1][1]-'0'; //saves the question number (-'0' converts the ASCII values to int value)

        if (num_args==2){ //if arguments are = 2, ie. does not include the answer then display the question requested
            if (q_num == 1){
                printf("What Linux Command Line command is used to display the contents of the current directory?\n");
                //return EXIT_SUCCESS;
            }
            if (q_num == 2){
                printf("Which C function is used to output formatted text?\n");
            }
            if (q_num == 3){
                printf("What Git command is used to check the status of the staging area?\n");
            }
            return EXIT_SUCCESS; //return success
        }
        else if (num_args == 3) { //if arguments are = 3 ie. includes answer then display if answer is correct
            char *answer = args[2];
            
            if (q_num == 1){
                if (strcmp(answer, "ls") == 0){ //using strcmp we check if given answer is correct.
                    printf("Correct!\n");
                }
                else{
                    printf("Wrong! Try again!\n");
                }
            }
            if (q_num == 2){
                if (strcmp(answer, "printf") == 0){
                    printf("Correct!\n");
                }
                else{
                    printf("Wrong! Try again!\n");
                }
            }
            if (q_num == 3){
                if (strcmp(answer, "git status") == 0){
                    printf("Correct!\n");
                }
                else{
                    printf("Wrong! Try again!\n");
                }
            }
            return EXIT_SUCCESS; //return success
        }
        else{ //handles any error cases. ex: "./ quiz $1". Prints usage message
            printf("Usage: quiz [-#] [<answer>]\n");
            printf("Try 'quiz --help' for more information.\n");
            return EXIT_FAILURE; //returns failure
        }
    }
    else { ////handles any error cases. ex: "./ quiz arg1 agr2 agr3". Prints usage message
        printf("Usage: quiz [-#] [<answer>]\n");
        printf("Try 'quiz --help' for more information.\n");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}