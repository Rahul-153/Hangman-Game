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
    string test;
    test = arr[n];
    int stars = arr[n].length();
    int size = stars;
    string starString;
    for (int i = 0; i < stars; i++)
        starString += '*';
    int guess = stars + 3;
    int check;
    while (guess > 1)
    {
        check = 0;
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
        int found = test.find(alp);
        for (int i = 0; i < arr[n].length(); i++)
            if (alp == test[i])
            {
                test[i] = '*';
                if (found != string::npos)
                {
                    ++correctGuess;
                    starString[i] = alp;
                    --size;
                }
                else
                {
                    ++wrongGuess;
                }
            }
        for (int i = 0; i < stars; i++)
        {
            if (starString[i] != arr[n][i])
            {
                check = 1;
                break;
            }
        }
        if (check == 0)
        {
            cout << "You win";
            break;
        }
        if (!(guess >= size))
        {
            check = 1;
            break;
        }
        system("CLS");
    }
    if (check == 1)
    {
        cout << "Sorry you lose " << endl;
        cout << "The correct word is " << arr[n];
    }
}