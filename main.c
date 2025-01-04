#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Structure to store voter information
typedef struct {
    int voterID;
    char password[20];
    int hasVoted;
} Voter;

// Structure to store candidate information
typedef struct {
    int candidateID;
    char name[50];
    int voteCount;
} Candidate;

#define MAX_VOTERS 100
#define MAX_CANDIDATES 5

Voter voters[MAX_VOTERS];
Candidate candidates[MAX_CANDIDATES];
int voterCount = 0;
int candidateCount = 0;

// Function to register voters
void registerVoter() {
    if (voterCount >= MAX_VOTERS) {
        printf("Maximum voter limit reached.\n");
        return;
    }
    printf("Register a new voter:\n");
    printf("Enter Voter ID: ");
    scanf("%d", &voters[voterCount].voterID);
    printf("Enter Password: ");
    scanf("%s", voters[voterCount].password);
    voters[voterCount].hasVoted = 0;
    voterCount++;
    printf("Voter registered successfully!\n");
}

// Function to add candidates
void addCandidate() {
    if (candidateCount >= MAX_CANDIDATES) {
        printf("Maximum candidate limit reached.\n");
        return;
    }
    printf("Add a new candidate:\n");
    printf("Enter Candidate ID: ");
    scanf("%d", &candidates[candidateCount].candidateID);
    printf("Enter Candidate Name: ");
    scanf("%s", candidates[candidateCount].name);
    candidates[candidateCount].voteCount = 0;
    candidateCount++;
    printf("Candidate added successfully!\n");
}

// Function to cast a vote
void castVote() {
    int voterID;
    char password[20];
    int candidateID;
    
    printf("Enter Voter ID: ");
    scanf("%d", &voterID);
    printf("Enter Password: ");
    scanf("%s", password);
    
    // Find the voter
    int found = 0;
    for (int i = 0; i < voterCount; i++) {
        if (voters[i].voterID == voterID && strcmp(voters[i].password, password) == 0) {
            found = 1;
            if (voters[i].hasVoted) {
                printf("You have already voted!\n");
                return;
            }
            // Allow voting
            printf("Enter Candidate ID to vote for: ");
            scanf("%d", &candidateID);
            
            // Find the candidate
            int candidateFound = 0;
            for (int j = 0; j < candidateCount; j++) {
                if (candidates[j].candidateID == candidateID) {
                    candidates[j].voteCount++;
                    voters[i].hasVoted = 1;
                    candidateFound = 1;
                    printf("Vote cast successfully!\n");
                    break;
                }
            }
            if (!candidateFound) {
                printf("Candidate not found!\n");
            }
            break;
        }
    }
    if (!found) {
        printf("Invalid voter credentials!\n");
    }
}

// Function to display results
void displayResults() {
    printf("\nElection Results:\n");
    for (int i = 0; i < candidateCount; i++) {
        printf("Candidate %s received %d votes.\n", candidates[i].name, candidates[i].voteCount);
    }
}

int main() {
    int choice;
    do {
        printf("\nOnline Voting System:\n");
        printf("1. Register Voter\n");
        printf("2. Add Candidate\n");
        printf("3. Cast Vote\n");
        printf("4. Display Results\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                registerVoter();
                break;
            case 2:
                addCandidate();
                break;
            case 3:
                castVote();
                break;
            case 4:
                displayResults();
                break;
            case 5:
                printf("Exiting the system.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);
    
    return 0;
}
