#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int roll_one_die() {
    return (rand() % 6) + 1;  //gives a number 1–6
}

int main() {
    int counts[13] = {0};
    int rolls = 1000000;

    srand(time(0));  //seed random number generator

    for (int i = 0; i < rolls; i++) {
        int die1 = roll_one_die();
        int die2 = roll_one_die();
        int sum = die1 + die2;
        counts[sum]++;
    }

    printf("Sum | Count     | Probability (%%)\n");  //to format printf statement to present the distribution
    printf("----|-----------|----------------\n");

    for (int i = 2; i <= 12; i++) {
        double probability = (counts[i] / (double)rolls) * 100;
        printf("%2d  | %9d | %8.2f%%\n", i, counts[i], probability);
    }

return 0;
}  
