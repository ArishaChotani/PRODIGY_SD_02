// guessing_game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<time.h>

using namespace std;

int generatenumber() {
    int num;
    srand(time(NULL));
    num = rand();
    return num;
}
int generatenumber2(int u,int l) {
    int num;
    srand(time(NULL));
    num = (rand()%(u-l+1))+l;
    return num;
}
void hint(int n) {
    int lower, upper = 0;
    if (n < 100) {
        lower = 100 - n;
        upper = 100 + n;
    }
    else if (n > 100) {
        lower = n - 100;
        upper = n + 100;
    }
    cout << "Your number is between " << lower << " and " << upper <<endl;
}
int main()
{
   
    int attempts = 0;
    int guess, range, u, l;

    cout << "Welcome to the Number Guessing Game!\n";
    cout << "Try to guess the number, would you like to add a range ?.\n";
    cout << "enter 1 to add a range : ";
    cin >> range;
    int n;
    if (range == 1) {
        cout << " enter upper and lower : :";
        cin >> u >> l;
        n = generatenumber2(u, l);

    }
    else {
        n = generatenumber();
    }
    
    bool guessedCorrectly = false;
    char h;

    do {
        cout << "Enter your guess: ";
        cin >> guess;
        attempts++;
        
        if (guess < n) {
            cout << "Too low! Try guessing higher.\n";
            
        }
        else if (guess > n) {
            cout << "Too high! Try guessing lower.\n";
        }
        else {
            guessedCorrectly = true;
        }
        if (attempts > 2) {
            cout << "\nPress h for a hint (range) or I to know difference between your guess and correct answer\n\n";
            cin >> h;
            if (h == 'h') {
                hint(n);
            }
            else if (h == 'i') {
                cout << "hint : " << guess - n;
            }
        }
    } while (!guessedCorrectly);

    cout << "Congratulations! You guessed the number " << n << " correctly.\n";
    cout << "Number of attempts: " << attempts << endl;

    return 0;

}
