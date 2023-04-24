#include <stdio.h>

// Recursively find and print valid point combinations for NFL games.
// index tells which kind of play should be considered for this call, and
// remainder is the number of points that need to be scored
void find(int index, int remainder);

int main()
{
  while(1)
  {
    printf("Enter 0 or 1 to STOP\n");
    printf("Enter the NFL score: ");

    // Get the score and test if it was a success
    int score;
    int success = scanf("%d", &score);
    printf("possible combinations of scoring plays:\n");

    if (success) // The user inputted an int! Crunch the numbers
    {
      find(0, score);
    }

    if (score <= 1) // The user wants to quit
    {
      return 0;
    }
  }
}

void find(int index, int remainder)
{
  // Holds the answer to how many of each kind, as calculated thus far
  // Beyond the index passed, this holds garbage data
  static int answer[5];

  // Holds the numbers of points for the 5 different plays
  static int coeffs[] = {8, 7, 6, 3, 2};
  if (index == 5) return;

  int n; // number of times a score is made with coeffs[index] points
  for (n = 0; n*coeffs[index] < remainder; n++)
  {
    answer[index] = n;
    find(index+1, remainder - n*coeffs[index]);
  }

  if (n*coeffs[index] == remainder) // n perfectly scores all the remaining points
  {
    // Fix the answers array so that all numbers are correct
    answer[index] = n;
    for (int i = index+1; i < 5; i++)
    {
      answer[i] = 0;
    }
    // Print the result that is found
    printf("%d TD + 2 pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n",
        answer[0],
        answer[1],
        answer[2],
        answer[3],
        answer[4]
        );
  }
}
