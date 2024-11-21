#include <stdio.h>
#include <string.h>

#define MAX_MOVIES 100

typedef struct {
    char title[100];
    char genre[50];
    char director[100];
    int releaseYear;
    float rating;
} Movie;

void addMovie(Movie movies[], int *count);
void searchByGenre(Movie movies[], int count);
void displayMovies(Movie movies[], int count);

int main() {
    Movie movies[MAX_MOVIES];
    int movieCount = 0;
    int choice;

    do {
        printf("\n--- Movie Management System ---\n");
        printf("1. Add Movie\n");
        printf("2. Search Movies by Genre\n");
        printf("3. Display All Movies\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMovie(movies, &movieCount);
                break;
            case 2:
                searchByGenre(movies, movieCount);
                break;
            case 3:
                displayMovies(movies, movieCount);
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

void addMovie(Movie movies[], int *count) {
    if (*count >= MAX_MOVIES) {
        printf("Cannot add more movies. Maximum limit reached.\n");
        return;
    }

    Movie newMovie;
    printf("Enter movie title: ");
    getchar();
    fgets(newMovie.title, sizeof(newMovie.title), stdin);
    newMovie.title[strcspn(newMovie.title, "\n")] = '\0';
    printf("Enter genre: ");
    fgets(newMovie.genre, sizeof(newMovie.genre), stdin);
    newMovie.genre[strcspn(newMovie.genre, "\n")] = '\0';
    printf("Enter director: ");
    fgets(newMovie.director, sizeof(newMovie.director), stdin);
    newMovie.director[strcspn(newMovie.director, "\n")] = '\0';
    printf("Enter release year: ");
    scanf("%d", &newMovie.releaseYear);
    printf("Enter rating (out of 10): ");
    scanf("%f", &newMovie.rating);

    movies[*count] = newMovie;
    (*count)++;
    printf("Movie added successfully!\n");
}

void searchByGenre(Movie movies[], int count) {
    if (count == 0) {
        printf("No movies available.\n");
        return;
    }

    char genre[50];
    printf("Enter genre to search: ");
    getchar();
    fgets(genre, sizeof(genre), stdin);
    genre[strcspn(genre, "\n")] = '\0';

    printf("\n--- Movies of Genre: %s ---\n", genre);
    for (int i = 0; i < count; i++) {
        if (strcmp(movies[i].genre, genre) == 0) {
            printf("Title: %s\n", movies[i].title);
            printf("Director: %s\n", movies[i].director);
            printf("Release Year: %d\n", movies[i].releaseYear);
            printf("Rating: %.1f\n", movies[i].rating);
            printf("--------------------------\n");
        }
    }
}

void displayMovies(Movie movies[], int count) {
    if (count == 0) {
        printf("No movies available.\n");
        return;
    }

    printf("\n--- All Movies ---\n");
    for (int i = 0; i < count; i++) {
        printf("Title: %s\n", movies[i].title);
        printf("Genre: %s\n", movies[i].genre);
        printf("Director: %s\n", movies[i].director);
        printf("Release Year: %d\n", movies[i].releaseYear);
        printf("Rating: %.1f\n", movies[i].rating);
        printf("--------------------------\n");
    }
}
