#include <stdio.h>

int p[5];  // Philosopher states: 0 = Thinking, 1 = Eating
int ch[5]; // Chopstick states: 0 = Available, 1 = In use

// Function to release chopsticks and mark philosopher as thinking
void signal(int y) {
    int right = (y + 1) % 5; // Right chopstick index
    p[y] = 0;                // Philosopher stops eating
    ch[y] = 0;               // Left chopstick is free
    ch[right] = 0;           // Right chopstick is free
}

// Function to check chopstick availability and handle philosopher actions
void wait(int y) {
    int right = (y + 1) % 5; // Right chopstick index

    // Check if both chopsticks are free
    if (ch[y] == 0 && ch[right] == 0) {
        p[y] = 1;         // Philosopher starts eating
        ch[y] = 1;        // Left chopstick is now in use
        ch[right] = 1;    // Right chopstick is now in use
    } 
    else if (p[y] == 1) { // Philosopher is already eating
        int w;
        printf("Philosopher %d is already eating. Do you want them to stop? (1 = Yes, 0 = No): ", y);
        scanf("%d", &w);
        if (w == 1) {
            signal(y); // Stop the philosopher and release chopsticks
        }
    } 
    else { // Chopsticks are busy
        printf("Chopsticks %d and %d are busy.\n", y, right);
        printf("Philosopher %d waits.\n", y);
    }
}

int main() {
    int continueSimulation; // Variable to control the simulation loop

    // Initialize philosopher and chopstick states
    for (int i = 0; i < 5; i++) {
        p[i] = 0; // All philosophers start thinking
        ch[i] = 0; // All chopsticks are free
    }

    do {
        // Display the status of all philosophers
        for (int i = 0; i < 5; i++) {
            if (p[i] == 0) {
                printf("Philosopher %d: Thinking\n", i);
            } else {
                printf("Philosopher %d: Eating\n", i);
            }
        }

        // Prompt user to choose a philosopher to eat
        int s;
        printf("Which philosopher wants to eat (0-4): ");
        scanf("%d", &s);

        // Handle philosopher eating logic
        wait(s);

        // Ask user if they want to continue the simulation
        printf("\nDo you want to continue? (1 = Yes, 0 = No): ");
        scanf("%d", &continueSimulation);
    } while (continueSimulation == 1);

    return 0;
}
