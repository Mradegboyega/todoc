#include <stdio.h>

#define Max_Task 100

struct Todo
{
    char description[100];
    int isCompleted;
};

int getUsersChoice();

int main(void)
{
    struct Todo todos[Max_Task];
    int numTodos = 0; // Initialize the count of tasks

    int choice;

    do {
        choice = getUsersChoice();

        switch (choice)
        {
            case 1:
                if (numTodos == 0) {
                    printf("No task available\n");
                } else {
                    for (int i = 0; i < numTodos; i++) {
                        printf("%d. %s [%s]\n", i + 1, todos[i].description, todos[i].isCompleted ? "completed" : "not completed");
                    }
                }
                break;

            case 2:
                if (numTodos < Max_Task)
                {
                    printf("Enter a description: ");
                    scanf(" %[^\n]", todos[numTodos].description); // Added space before %[^\n]
                    todos[numTodos].isCompleted = 0;
                    numTodos++;
                } else {
                    printf("Task list is full.\n");
                }
                break;

            case 3: 
                printf("Enter the index of the task to mark as completed: ");
                int markIndex;
                scanf("%d", &markIndex);
                if (markIndex >= 1 && markIndex <= numTodos) 
                {
                    todos[markIndex - 1].isCompleted = 1;
                    printf("Task marked completed\n");
                } else {
                    printf("Invalid index\n");
                }
                break;

            case 4:
                int deleteIndex;
                printf("Enter index of task to delete: ");
                scanf("%d", &deleteIndex);
                if (deleteIndex >= 1 && deleteIndex <= numTodos) {
                    for (int i = deleteIndex - 1; i < numTodos - 1; i++) {
                        todos[i] = todos[i + 1];
                    } 
                    numTodos--;
                    printf("Task deleted\n");
                } else {
                    printf("Invalid Index\n");
                }
                break;

            case 5:
                printf("Exiting the program\n");
                break;

            default:
                printf("Invalid choice. Kindly enter a valid choice\n");
                break;
        }
    } while (choice != 5);

    return 0;
}

int getUsersChoice() {
    int choice;
    printf("\nMenu:\n");
    printf("1. Show tasks\n");
    printf("2. Add task\n");
    printf("3. Mark task as completed\n");
    printf("4. Delete task\n");
    printf("5. Quit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}
