#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main ( int argc, char** argv )
{
    int mysteriousnumber = 0, eingegebenenummer = 0, schlag = 0, nochmalspielen = 0, schwierigkeit = 2;
    int max = 100;
    const int MIN = 1;

    srand(time(NULL));

    // Sélection de la difficulté

    printf("Wählen Sie einen Schwierigkeitsgrad:\n");
    printf("1 :  von 1 bis  10\n2 : von 1 bis 100\n3 : von 1 bis 1000\n");
    scanf("%d", &schwierigkeit);

    switch(schwierigkeit)
    {
    case 1:
        max = 10;
        break;
    case 2:
        max = 100;
        break;
    case 3:
        max = 1000;
        break;
    default:
        printf("Nicht anerkannt. Ich wähle für Sie Level 2 (zwischen 1 und 100).\n");
        max = 100;
    }

    // Début de la boucle qui permet de faire plusieurs parties
    do
    {
        // Initialisations pour la partie
        schlag = 0;
        mysteriousnumber = (rand() % (max - MIN + 1)) + MIN;

        do
        {
            printf("Wie hoch ist die Zahl ? ");
            scanf("%d", &eingegebenenummer);
            schlag++;

            if (mysteriousnumber > eingegebenenummer)
                printf("Es ist mehr !\n\n");
            else if (mysteriousnumber < eingegebenenummer)
                printf("Das ist weniger. !\n\n");
            else
                printf ("Gut gemacht, Sie haben die Anzahl mystere in  d% Schläge gefunden!!!\n\n", schlag);

        } while (eingegebenenummer != mysteriousnumber);

        // Fin de la partie, on demande si on veut rejouer
        printf("Möchten Sie ein anderes Spiel machen (1 = ja, 0 = nein) ? ");
        scanf("%d", &nochmalspielen);

    } while (nochmalspielen);

}
