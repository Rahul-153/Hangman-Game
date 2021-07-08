#include "bits/stdc++.h"
using namespace std;
int main()
{
    string arr[] = {"delhi",
                    "jaipur",
                    "agra",
                    "shimla",
                    "jammu",
                    "goa"};
    int correctGuess = 0;
    int wrongGuess = 0;
    srand(time(NULL));
    int n = rand() % 6;
    int stars = arr[n].length();
    char starString[7];
    for (int i = 0; i < stars; i++)
        starString[i] = '*';
    int guess = stars + 3;
    int check = 0;
    while (guess > 1)
    {
        guess = guess - 1;
        cout << "Guess the name of a city in India\n\n";
        cout << "You have " << guess << " chances to make it right\n\n";
        cout << endl;
        for (int i = 0; i < stars; i++)
            cout << starString[i];
        cout << endl;
        char alp;
        cout << "Enter a alphabet you think can match\n";
        cin >> alp;
        int found = arr[n].find(alp);
        if (found != string::npos)
        {
            ++correctGuess;
            starString[found] = alp;
        }
        else
        {
            ++wrongGuess;
        }
        for (int i = 0; i < stars; i++)
        {
            if (starString[i] == arr[n][i])
                check = 1;
            else
                check = 0;
        }
        if (check == 1)
        {
            cout << "You win";
            break;
        }
        system("CLS");
    }
    if (check == 0)
    {
        cout << "Sorry you lose " << endl;
        cout << "The correct word is " << arr[n];
    }
}