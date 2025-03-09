#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_DICE 6

// Roll a single die and return the value (1 to 6)
int roll_die() {
    return (rand() % 6) + 1;
}

// Roll given number of dice
void roll_all_dice(int dice[], int num_dice) {
    for (int i = 0; i < num_dice; i++) {
        dice[i] = roll_die();
    }
}

// Display the rolls for the current round, and shows which dice are selected by player
void display_dice(int dice[], int num_dice, int keep[]) {
    for (int i = 0; i < num_dice; i++) {
        if (keep[i] == 1) {
            printf("Die %d : value = [%d] (selected)\n", i+1, dice[i]);
        }
        else {
            printf("Die %d : value = [%d]\n", i+1, dice[i]);
        }

    }
}

void reset_kept_dice(int keep[]) {
    for (int i = 0; i < NUM_DICE; i++) {
        keep[i] = 0;  // Reset keep status for each die
    }
}

// Checks if there are any scoring combinations from the latest roll
int check_farkle(int dice[], int num_dice) {
    int counts[6];
    int roll_score = 0;

    for (int i = 0; i < 6; i++) {
        counts[i] = 0; // Reset counts
    }
    for (int i = 0; i < num_dice; i++) {
        counts[dice[i] - 1]++;
    }

    roll_score = calculate_score(counts);
    return roll_score;

}

/*
    Validate that the selected dice are valid.
    e.g. the player might have selected a 1 and a 3.
    in this case, the 1 is a scoring die, but the 3 is not.
*/
int is_valid_selection(int dice[], int num_dice, int keep[], int counts[]) {
    int valid = 1;  // Assume valid unless we find an invalid case
    int rolled_full_straight = 0;
    int rolled_partial_straight = 0;

    // The player cannot select a 2, 3, 4, or 6 unless there are 3 or more of them.
    if ((counts[1] > 0 && counts[1] < 3) || (counts[2] > 0 && counts[2] < 3) ||
        (counts[3] > 0 && counts[3] < 3) || (counts[5] > 0 && counts[5] < 3)) {
        valid = 0;
    }


    for (int i = 0; i < 6; i++) {
        if (counts[i] == 1) {
            rolled_partial_straight += 1;
            rolled_full_straight += 1;
        }
    }

    // [1,2,3,4,5,6]
    if (rolled_full_straight == 6) {
        valid = 1;
    }
    // [1,2,3,4,5]
    else if (rolled_partial_straight == 5 && counts[0] == 1) {
        valid = 1;
    }
    // [2,3,4,5,6]
    else if (rolled_partial_straight == 5 && counts[0] == 0) {
        valid = 1;
    }

    // Return the validation result
    return valid;
}


// Check value of current selection, but doesn't change total score.
void preview_score(int counts[], int total_score, int turn_score) {
    int preview_score = 0;
    int rolled_full_straight = 0;
    int rolled_partial_straight = 0;

    if (counts[0] < 3) {
        preview_score += counts[0] * 100; // 1's score 100 each

    }

    if (counts[4] < 3) {
        preview_score += counts[4] * 50;  // 5's score 50 each
    }

    for (int i = 0; i < 6; i++) {

        int three_of_a_kind = (i == 0) ? 1000 : (i + 1) * 100;

        if (counts[i] == 3) {
            preview_score += three_of_a_kind; // e.g. 2 2 2 = 400
        }
        else if (counts[i] == 4) {
            preview_score += three_of_a_kind * 2; // e.g 2 2 2 2 = 800
        }
        else if (counts[i] == 5) {
            preview_score += three_of_a_kind * 4; // e.g. 2 2 2 2 2 = 1600
        }
        else if (counts[i] == 6) {
            preview_score += three_of_a_kind * 8; // e.g. 2 2 2 2 2 2 = 3200
        }

        if (counts[i] == 1) {
            rolled_partial_straight += 1;
            rolled_full_straight += 1;
        }
    }

    // [1,2,3,4,5,6]
    if (rolled_full_straight == 6) {
        preview_score = 1500;
    }
    // [1,2,3,4,5]
    else if (rolled_partial_straight == 5 && counts[0] == 1) {
        preview_score = 500;
    }
    // [2,3,4,5,6]
    else if (rolled_partial_straight == 5 && counts[0] == 0) {
        preview_score = 750;
    }

    printf("\n-----------\n");
    printf("Game Score: %d\n", total_score);
    printf("Turn Score: %d\n", turn_score);
    printf("Your selection is worth: %d\n", preview_score);
}

// Calculate the score based on the dice counts, and modify the value of score variable
int calculate_score(int counts[]) {
    int score = 0;
    int rolled_full_straight = 0;
    int rolled_partial_straight = 0;

    if (counts[0] < 3) {
        score += counts[0] * 100; // 1's score 100 each

    }

    if (counts[4] < 3) {
        score += counts[4] * 50;  // 5's score 50 each
    }

    for (int i = 0; i < 6; i++) {

        int three_of_a_kind = (i == 0) ? 1000 : (i + 1) * 100;

        if (counts[i] == 3) {
            score += three_of_a_kind; // e.g. 2 2 2 = 400
        }
        else if (counts[i] == 4) {
            score += three_of_a_kind * 2; // e.g 2 2 2 2 = 800
        }
        else if (counts[i] == 5) {
            score += three_of_a_kind * 4; // e.g. 2 2 2 2 2 = 1600
        }
        else if (counts[i] == 6) {
            score += three_of_a_kind * 8; // e.g. 2 2 2 2 2 2 = 3200
        }

        if (counts[i] == 1) {
            rolled_partial_straight += 1;
            rolled_full_straight += 1;
        }
    }

    // [1,2,3,4,5,6]
    if (rolled_full_straight == 6) {
        score = 1500;
    }
    // [1,2,3,4,5]
    else if (rolled_partial_straight == 5 && counts[0] == 1) {
        score = 500;
    }
    // [2,3,4,5,6]
    else if (rolled_partial_straight == 5 && counts[0] == 0) {
        score = 750;
    }

    return score;
}


// Handles the player selecting dice for scoring
int player_choice_handler(int dice[], int num_dice, int keep[], int counts[], int total_score, int turn_score, int selected_this_turn) {
    int selected;
    int num_selected = selected_this_turn;
    
    printf("Score: %d\nRound score: %d\nSelect dice to keep (for scoring):\n", total_score, turn_score);

    display_dice(dice, num_dice, keep);

    while (1) {

        printf("\nYou can unselect a die by selecting it again.\nSelect a die by its dice number from 1-6 (not value) or enter 0 to finish selection: ");

        if (scanf_s("%d", &selected) != 1) {

            while (getchar() != '\n'); 
            printf(" * Invalid input! Please enter a number between 0 and 6.\n");
            continue;  
        }

        if (selected == 0) {
            if (!is_valid_selection(dice, num_dice, keep, counts)) {
                printf(" * Invalid selection! Some of your selected dice do not form a valid scoring combination.\n");
                continue;
            }
            break;
        }
        int found = 0;
        // Check if the selected value is valid
        if (selected >= 1 && selected <= 6) {
            if (dice[selected - 1] && !keep[selected - 1]) {
                // If the die is not kept, mark it as kept
                keep[selected - 1] = 1;
                num_selected++;
                found = 1;
            }
            else if (dice[selected - 1] && keep[selected - 1]) {
                // If the die is already kept, unselect it
                keep[selected - 1] = 0;
                num_selected--;
                found = 1;
            }
        }

        // Print the selected dice
        display_dice(dice, num_dice, keep);
            
        for (int i = 0; i < 6; i++) {
            counts[i] = 0; // Reset counts
        }
        for (int i = 0; i < num_dice; i++) {
            if (keep[i]) {
                counts[dice[i] - 1]++;
            }
        }

        preview_score(counts, total_score, turn_score);

        if (!found) {
            printf("Invalid selection. Please enter a valid die value from the roll.\n");
        }

    }

    return num_selected;

}

// Main game loop
int main() {
    srand(time(NULL));

    int dice[NUM_DICE];
    int keep[NUM_DICE] = { 0 };  // Which of the rolled dice are kept (so if keep[i] = 1, then dice[i] is being kept)
    int counts[6];              // Count occurrences of each die value (1-6), used to help with calculating score
    int total_score = 0;
    int turn_score = 0;
    int num_dice = NUM_DICE;
    int score_this_turn;
    int selected_this_turn = 0; // num of dice selected this turn, used to update num_dice
    int possile_points = 0;

    printf("Let's play Farkle! (based on the dice minigame from Kingdom Come Deliverance 2)\n");

    num_dice = NUM_DICE;

    while (total_score < 10000) {

        roll_all_dice(dice, num_dice);

        possile_points = check_farkle(dice, num_dice);

        if (possile_points == 0) {
            display_dice(dice, num_dice, keep);
            printf("Farkle! You didn't roll any scoring combinations.");
        }


        selected_this_turn = player_choice_handler(dice, num_dice, keep, counts, total_score, turn_score, selected_this_turn);

        score_this_turn = calculate_score(counts); 
  
        if (score_this_turn > 0) {
            turn_score += score_this_turn;

            // If no dice could be scored with, it's a farkle (aka BUST! in KCD2)
            if (num_dice == 0) {
                printf("Farkle! (You lose the points for this round).\n");
                turn_score = 0;
            }
            else {
                // Ask the player if they want to continue round or bank the points
                char choice;
                printf("Do you want to continue the round or bank your points? (c to continue, b to bank): ");
                scanf_s(" %c", &choice);

                if (choice == 'b') {
                    total_score += turn_score;
                    printf("\n----------------------\nYou banked %d points this round.\nNew total score: %d\n----------------------\n", turn_score, total_score);
                    turn_score = 0;
                    num_dice = NUM_DICE;
                    selected_this_turn = 0;
                    reset_kept_dice(keep);
                    printf("Starting next round\n");

                }
                else {
                    printf("\nYou chose to continue with this turn.\n");
                    reset_kept_dice(keep); 
                    num_dice = NUM_DICE - selected_this_turn;
                    if (num_dice == 0) {
                        num_dice = NUM_DICE;
                    }

                }
            }
        }
        else {
            printf("You farkled! No points this turn.\n");
        }

        // End the game if the player reaches the target score
        if (total_score >= 10000) {
            printf("\nCongratulations! You won!\n");
            break;
        }

    }

    return 0;
}
