#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 256

// Function to write details to a file
void write_details(const char *filename, const char *details) {
    int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644); // Open file for writing, create if doesn't exist
    if (fd < 0) {
        perror("open"); // Print error if file can't be opened
        exit(1);
    }
    write(fd, details, strlen(details)); // Write details to the file
    close(fd); // Close the file after writing
}

// Function to read the contents of a file
void read_file(const char *filename) {
    char buffer[BUFFER_SIZE];
    int fd = open(filename, O_RDONLY); // Open file for reading
    if (fd < 0) {
        perror("open"); // Print error if file can't be opened
        exit(1);
    }
    printf("Contents of %s:\n", filename);
    while (read(fd, buffer, sizeof(buffer) - 1) > 0) {
        buffer[BUFFER_SIZE - 1] = '\0'; // Null-terminate the buffer
        printf("%s", buffer); // Print the file contents
    }
    close(fd); // Close the file after reading
}

int main() {
    // Details of yourself and your friend
    const char *my_details = "Name: Anuj Rawat\nAge: 20\nCity: Dehradun \n";
    const char *friend_details = "Name: Vinayak Rawat\nAge: 20\nCity: Dehradun\n";

    // Write details to their respective files
    write_details("my_details.txt", my_details);
    write_details("friend_details.txt", friend_details);

    // Open both files for reading
    FILE *my_file = fopen("my_details.txt", "r");
    FILE *friend_file = fopen("friend_details.txt", "r");

    // Check if both files were successfully opened
    if (!my_file || !friend_file) {
        perror("fopen FAILED!");
        exit(1);
    }

    char my_line[BUFFER_SIZE];
    
    // Read each line from my_details.txt
    while (fgets(my_line, sizeof(my_line), my_file)) {
        rewind(friend_file); // Reset the friend_file pointer to the beginning for each line in my_details.txt
        char friend_line[BUFFER_SIZE];

        // Compare each line from friend_details.txt with the current line from my_details.txt
        while (fgets(friend_line, sizeof(friend_line), friend_file)) {
            if (strcmp(my_line, friend_line) == 0) { // If the lines match
                printf("Matching line: %s", my_line); // Print the matching line
            }
        }
    }

    // Close both files after reading
    fclose(my_file);
    fclose(friend_file);

    return 0;
}
