#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    //check if the input matches a name of a candidate by comparing the input to argv [1-n]
    for (int x = 0; x < candidate_count; x++)
    {
        //compare the name given to the list of candidates
        int result = strcmp(name, candidates[x].name);
        if (result == 0)
        {
            //add 1 vote to the vote count of the candidate with name and stop counting
            candidates[x].votes++;
            return true;
        }
    }
    //otherwise, return false
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    int highVote = 0;
    //if the number of votes is higher than the current highVote, make highVote the new higher number
    for (int y = 0; y < candidate_count; y++)
    {
        if (candidates[y].votes > highVote)
        {
            highVote = candidates[y].votes;
        }
    }
    //if a candidate has the same number of votes as the highVote, print their name
    for (int z = 0; z < candidate_count; z++)
    {
        if (candidates[z].votes == highVote)
        {
            printf("%s\n", candidates[z].name);
        }
    }
    return;
}

