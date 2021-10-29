#include "../matrixLib/inlcude/lib.h"

int main(int argc, char *argv[])
{
    cout << "------------------------------\n";
    cout << "Witaj w kalkulatorze macierzy!\n";
    cout << "------------------------------\n\n";
    cout << "Do wyboru masz 11 opcji:\n";
    cout << "Aby zobaczyc jak dziala kazda z nich uruchom program z parametrem 'help'\n\n";
    cout << "Dzialanie - " << argv[1] <<endl<<endl;


    cout << "Jakiego typu zmiennych chcesz uzyc?\n";
    cout << "int - wpisz 'i' | double wpisz 'd'\n";
    string zmienna;
    if(!(cin >> zmienna))
    {
        cout << "\n!Wpisano nieodpowiednia tresc!\n";
        cout << "!Uruchom progam od nowa!\n\n";
        help();
        exit(1);
    }


    if(strcmp(argv[1], "addMatrix") == 0 )
    {
        int wiersze_A, kolumny_A;
        cout << "Wprowadz rozmiar macierzy ktore chcesz dodac (wiersze _ kolumny):\n";

        if(!(cin >> wiersze_A >> kolumny_A))
        {
            cout << "\n!Wpisano nieodpowiednia tresc!\n";
            cout << "!Uruchom progam od nowa!\n\n";
            help();
            exit(1);
        }

        if(zmienna == "i")
        {
            int **A = create(wiersze_A, kolumny_A);
            int **B = create(wiersze_A, kolumny_A);

            cout << "Wprowadz dane do pierwszej macierzy\n";
            enter(A,wiersze_A,kolumny_A);

            cout << "Wprowadz dane do drugiej macierzy\n";
            enter(B,wiersze_A,kolumny_A);

            int **R = addMatrix(A, B, wiersze_A, kolumny_A);
            cout << "Wynik dodawania macierzy A + B: \n";
            disp(R, wiersze_A, kolumny_A);

            del(A, wiersze_A);
            del(B, wiersze_A);
            del(R, wiersze_A);
        }

        else if(zmienna == "d")
        {
            double **A = create_d(wiersze_A, kolumny_A);
            double **B = create_d(wiersze_A, kolumny_A);

            cout << "Wprowadz dane do pierwszej macierzy\n";
            enter(A,wiersze_A,kolumny_A);

            cout << "Wprowadz dane do drugiej macierzy\n";
            enter(B,wiersze_A,kolumny_A);

            double **R = addMatrix(A, B, wiersze_A, kolumny_A);
            cout << "Wynik dodawania macierzy A + B: \n";
            disp(R, wiersze_A, kolumny_A);

            del(A, wiersze_A);
            del(B, wiersze_A);
            del(R, wiersze_A);
        }
    }

    else if(strcmp(argv[1], "subtractMatrix") == 0 )
    {
        int wiersze_A, kolumny_A;

        cout << "Wprowadz rozmiar macierzy ktore chcesz odjac (wiersze _ kolumny):\n";
        if(!(cin >> wiersze_A >> kolumny_A))
        {
            cout << "\n!Wpisano nieodpowiednia tresc!\n";
            cout << "!Uruchom progam od nowa!\n\n";
            help();
            exit(1);
        }

        if(zmienna == "i")
        {
            int **A = create(wiersze_A, kolumny_A);
            int **B = create(wiersze_A, kolumny_A);

            cout << "Wprowadz dane do pierwszej macierzy\n";
            enter(A,wiersze_A,kolumny_A);

            cout << "Wprowadz dane do drugiej macierzy\n";
            enter(B,wiersze_A,kolumny_A);

            int **R = subtractMatrix(A, B, wiersze_A, kolumny_A);
            cout << "Wynik odejmowania macierzy A - B: \n";
            disp(R, wiersze_A, kolumny_A);

            del(A, wiersze_A);
            del(B, wiersze_A);
            del(R, wiersze_A);
        }

        else if(zmienna == "d")
        {
            double **A = create_d(wiersze_A, kolumny_A);
            double **B = create_d(wiersze_A, kolumny_A);

            cout << "Wprowadz dane do pierwszej macierzy\n";
            enter(A,wiersze_A,kolumny_A);

            cout << "Wprowadz dane do drugiej macierzy\n";
            enter(B,wiersze_A,kolumny_A);

            double **R = subtractMatrix(A, B, wiersze_A, kolumny_A);
            cout << "Wynik odejmowania macierzy A - B: \n";
            disp(R, wiersze_A, kolumny_A);

            del(A, wiersze_A);
            del(B, wiersze_A);
            del(R, wiersze_A);
        }
    }

    else if (strcmp(argv[1], "multiplyMatrix") == 0)
    {
        int wiersze_A, kolumny_A, wiersze_B, kolumny_B;

        cout << "Wprowadz rozmiar pierwszej macierzy ktora chcesz pomnozyc (wiersze _ kolumny):\n";
        if(!(cin >> wiersze_A >> kolumny_A))
        {
            cout << "\n!Wpisano nieodpowiednia tresc!\n";
            cout << "!Uruchom progam od nowa!\n\n";
            help();
            exit(1);
        }

        cout << "Wprowadz rozmiar drugiej macierzy ktora chcesz pomnozyc (wiersze _ kolumny):\n";
        if(!(cin >> wiersze_B >> kolumny_B))
        {
            cout << "\n!Wpisano nieodpowiednia tresc!\n";
            cout << "!Uruchom progam od nowa!\n\n";
            help();
            exit(1);
        }

        if (kolumny_A != wiersze_B)
        {
            cout << "\n!Rozmiar kolumn macierzy A i wierszy macierzy B musi byc rowny!\n";
            cout << "!Uruchom progam od nowa!\n\n";
            help();
            exit(1);
        }

        if(zmienna == "i")
        {
        int **A = create(wiersze_A, kolumny_A);
        int **B = create(wiersze_B, kolumny_B);

        cout << "Wprowadz dane do pierwszej macierzy\n";
        enter(A,wiersze_A,kolumny_A);

        cout << "Wprowadz dane do drugiej macierzy\n";
        enter(B,wiersze_B,kolumny_B);

        int **R = multiplyMatrix(A, B, wiersze_A, kolumny_A, kolumny_B);
        cout << "Wynik mnozenia macierzy A x B: \n";
        disp(R, wiersze_A, kolumny_B);

        del(A, wiersze_A);
        del(B, wiersze_B);
        del(R, wiersze_A);
        }

        else if(zmienna == "d")
        {
            double **A = create_d(wiersze_A, kolumny_A);
            double **B = create_d(wiersze_B, kolumny_B);

            cout << "Wprowadz dane do pierwszej macierzy\n";
            enter(A,wiersze_A,kolumny_A);

            cout << "Wprowadz dane do drugiej macierzy\n";
            enter(B,wiersze_B,kolumny_B);

            double **R = multiplyMatrix(A, B, wiersze_A, kolumny_A, kolumny_B);
            cout << "Wynik mnozenia macierzy A x B: \n";
            disp(R, wiersze_A, kolumny_B);

            del(A, wiersze_A);
            del(B, wiersze_B);
            del(R, wiersze_A);
        }

    }

    else if(strcmp(argv[1], "multiplyByScalar") == 0 )
    {
        int wiersze_A, kolumny_A;

        cout << "Wprowadz rozmiar macierzy ktora chcesz pomnozyc przez skalar\n";
        if (!(cin >> wiersze_A >> kolumny_A))
        {
            cout << "\n!Wpisano nieodpowiednia tresc!\n";
            cout << "!Uruchom progam od nowa!\n\n";
            help();
            exit(1);
        }

        if (zmienna == "i")
        {

        int **A = create(wiersze_A, kolumny_A), skal;

        cout << "Wprowadz dane do macierzy\n";
        enter(A,wiersze_A,kolumny_A);

        cout<< "Wprowadz skalar: ";
        if(!(cin >> skal))
        {
            cout << "\n!Wpisano nieodpowiednia tresc!\n";
            cout << "!Uruchom progam od nowa!\n\n";
            help();
            exit(1);
        }

        int **R = multiplyByScalar(A, wiersze_A, kolumny_A, skal);
        cout << "Wynik mnozenia macierzy przez skalar A x s: \n";
        disp(R, wiersze_A, kolumny_A);

        del(A, wiersze_A);
        del(R, wiersze_A);
        }

        else if (zmienna == "d")
        {

            double **A = create_d(wiersze_A, kolumny_A), skal;

            cout << "Wprowadz dane do macierzy\n";
            enter(A,wiersze_A,kolumny_A);

            cout<< "Wprowadz skalar: ";
            if(!(cin >> skal))
            {
                cout << "\n!Wpisano nieodpowiednia tresc!\n";
                cout << "!Uruchom progam od nowa!\n\n";
                help();
                exit(1);
            }

            double **R = multiplyByScalar(A, wiersze_A, kolumny_A, skal);
            cout << "Wynik mnozenia macierzy przez skalar A x s: \n";
            disp(R, wiersze_A, kolumny_A);

            del(A, wiersze_A);
            del(R, wiersze_A);
        }
    }

    else if(strcmp(argv[1], "transpozeMatrix") == 0 )
    {
        int wiersze_A, kolumny_A;

        cout << "Wprowadz rozmiar macierzy ktora ma zostac przetransponowana\n";
        if (!(cin >> wiersze_A >> kolumny_A))
        {
            cout << "\n!Wpisano nieodpowiednia tresc!\n";
            cout << "!Uruchom progam od nowa!\n\n";
            help();
            exit(1);
        }

        if(zmienna == "i")
        {
        int **A = create(wiersze_A, kolumny_A);

        enter(A,wiersze_A,kolumny_A);
        cout << "Wprowadz dane do macierzy\n";

        int **R = transpozeMatrix(A, wiersze_A, kolumny_A);
        cout << "Wynik transpozycji macierzy A: \n";
        disp(R, kolumny_A, wiersze_A);

        del(A, wiersze_A);
        del(R, kolumny_A);
        }

        else if(zmienna == "d")
        {
            double **A = create_d(wiersze_A, kolumny_A);

            cout << "Wprowadz dane do macierzy\n";
            enter(A,wiersze_A,kolumny_A);

            double **R = transpozeMatrix(A, wiersze_A, kolumny_A);
            cout << "Wynik transpozycji macierzy A: \n";
            disp(R, kolumny_A, wiersze_A);

            del(A, wiersze_A);
            del(R, kolumny_A);
        }
    }

    else if(strcmp(argv[1], "powerMatrix") == 0 )
    {
        int wiersze_A, kolumny_A;
        unsigned int poteg;

        cout << "Wprowadz rozmiar macierzy ktora ma zostac spotegowana\n";
        if (!(cin >> wiersze_A >> kolumny_A))
        {
            cout << "\n!Wpisano nieodpowiednia tresc!\n";
            cout << "!Uruchom progam od nowa!\n\n";
            help();
            exit(1);
        }

        if(wiersze_A != kolumny_A)
        {
            cout << "\n!Wiersze i kolumny musza miec jednakowy rozmiar!\n";
            cout << "!Uruchom progam od nowa!\n\n";
            help();
            exit(1);
        }

        if(zmienna == "i")
        {

        int **A = create(wiersze_A, kolumny_A);

        cout << "Wprowadz dane do macierzy\n";
        enter(A,wiersze_A,kolumny_A);

        cout<< "Wprowadz potege do ktorej chcesz podniesc macierz: ";
        cin >> poteg;

        int **R = powerMatrix(A, wiersze_A, poteg);
        cout << "Wynik potegowania macierzy: \n";
        disp(R, wiersze_A, kolumny_A);

        del(A, wiersze_A);
        del(R, wiersze_A);
        }

        else if(zmienna == "d")
        {

            double **A = create_d(wiersze_A, kolumny_A);

            cout << "Wprowadz dane do macierzy\n";
            enter(A,wiersze_A,kolumny_A);

            cout<< "Wprowadz potege do ktorej chcesz podniesc macierz: ";
            cin >> poteg;

            double **R = powerMatrix(A, wiersze_A, poteg);
            cout << "Wynik potegowania macierzy: \n";
            disp(R, wiersze_A, kolumny_A);

            del(A, wiersze_A);
            del(R, wiersze_A);
        }
    }

    else if(strcmp(argv[1], "determinantMatrix") == 0 )
    {
        int wiersze_A, kolumny_A;

        cout << "Wprowadz rozmiar macierzy z ktorej zostanie obliczony wyznacznik\n";
        if (!(cin >> wiersze_A >> kolumny_A))
        {
            cout << "\n!Wpisano nieodpowiednia tresc!\n";
            cout << "!Uruchom progam od nowa!\n\n";
            help();
            exit(1);
        }

        if(wiersze_A != kolumny_A)
        {
            cout << "\n!Wiersze i kolumny musza miec jednakowy rozmiar!\n";
            cout << "!Uruchom progam od nowa!\n\n";
            help();
            exit(1);
        }

        if(zmienna == "i")
        {
        int **A = create(wiersze_A, kolumny_A);

        cout << "Wprowadz dane do macierzy\n";
        enter(A,wiersze_A,wiersze_A);


        int R = determinantMatrix(A, wiersze_A);
        cout << "Wyznacznik macierzy: \n";
        cout << R;

        del(A, wiersze_A);
        }

        else if(zmienna == "d")
        {
            double **A = create_d(wiersze_A, kolumny_A);

            cout << "Wprowadz dane do macierzy\n";
            enter(A,wiersze_A,wiersze_A);


            double R = determinantMatrix(A, wiersze_A);
            cout << "Wyznacznik macierzy: \n";
            cout << R;

            del(A, wiersze_A);
        }
    }

    else if(strcmp(argv[1], "matrixIsDiagonal") == 0 )
    {
        int wiersze_A, kolumny_A;

        cout << "Wprowadz rozmiar macierzy ktora zostanie sprawdzona czy jest diagonalna\n";
        if (!(cin >> wiersze_A >> kolumny_A))
        {
            cout << "\n!Wpisano nieodpowiednia tresc!\n";
            cout << "!Uruchom progam od nowa!\n\n";
            help();
            exit(1);
        }

        if(zmienna == "i")
        {
            int **A = create(wiersze_A, kolumny_A);

            cout << "Wprowadz dane do macierzy\n";
            enter(A, wiersze_A, wiersze_A);

            bool F = matrixIsDiagonal(A, wiersze_A);

            if (F)
                cout << F << " - jest diagonalna.";
            else
                cout << F << " - nie jest diagonalna";


            del(A, wiersze_A);
        }

        else if(zmienna == "d")
        {
            double **A = create_d(wiersze_A, kolumny_A);

            cout << "Wprowadz dane do macierzy\n";
            enter(A, wiersze_A, wiersze_A);

            bool F = matrixIsDiagonal(A, wiersze_A);

            if (F)
                cout << F << " - jest diagonalna.";
            else
                cout << F << " - nie jest diagonalna";


            del(A, wiersze_A);
        }
    }

    else if (strcmp(argv[1], "swap") == 0)
    {
        int wiersze_A, kolumny_A, wiersze_B, kolumny_B,wiersze,kolumny;

        cout << "Wprowadz rozmiar macierzy w ktorej chcesz zamienic dwie liczby miejscami\n";
        if (!(cin >> wiersze >> kolumny))
        {
            cout << "\n!Wpisano nieodpowiednia tresc!\n";
            cout << "!Uruchom progam od nowa!\n\n";
            help();
            exit(1);
        }

        if(zmienna == "i")
        {
        int **A = create(wiersze, kolumny);

        cout << "Wprowadz dane do macierzy\n";
        enter(A, wiersze, kolumny);

        cout << "Wprowadz wiersz i kolumne pierwszej liczby do zmiany:(pamieraj ze indeksy zaczynaja sie od 0)" << endl;
        if (!(cin >> wiersze_A >> kolumny_A))
        {
            cout << "\n!Wpisano nieodpowiednia tresc!\n";
            cout << "!Uruchom progam od nowa!\n\n";
            help();
            exit(1);
        }

        cout << "Wprowadz wiersz i kolumne drugiej liczby do zmiany:(pamietaj ze indeksy zaczynaja sie od 0)" << endl;
        if (!(cin >> wiersze_B >> kolumny_B))
        {
            cout << "\n!Wpisano nieodpowiednia tresc!\n";
            cout << "!Uruchom progam od nowa!\n\n";
            help();
            exit(1);
        }

        swap(A[wiersze_A][kolumny_A], A[wiersze_B][kolumny_B]);
        disp(A, wiersze, kolumny);

        del(A, wiersze);
        }

        if(zmienna == "d")
        {
            double **A = create_d(wiersze, kolumny);

            cout << "Wprowadz dane do macierzy\n";
            enter(A, wiersze, kolumny);

            cout << "Wprowadz wiersz i kolumne pierwszej liczby do zmiany:(pamieraj ze indeksy zaczynaja sie od 0)" << endl;
            if (!(cin >> wiersze_A >> kolumny_A))
            {
                cout << "\n!Wpisano nieodpowiednia tresc!\n";
                cout << "!Uruchom progam od nowa!\n\n";
                help();
                exit(1);
            }

            cout << "Wprowadz wiersz i kolumne drugiej liczby do zmiany:(pamietaj ze indeksy zaczynaja sie od 0)" << endl;
            if (!(cin >> wiersze_B >> kolumny_B))
            {
                cout << "\n!Wpisano nieodpowiednia tresc!\n";
                cout << "!Uruchom progam od nowa!\n\n";
                help();
                exit(1);
            }

            swap(A[wiersze_A][kolumny_A], A[wiersze_B][kolumny_B]);
            disp(A, wiersze, kolumny);

            del(A, wiersze);
        }
    }

    else if (strcmp(argv[1], "sortRow") == 0)
    {
        int wiersze_A, kolumny_A, wiersz;

        cout << "Wprowadz rozmiar macierzy w ktorej chcesz posortowac wybrany wiersz\n";
        if (!(cin >> wiersze_A >> kolumny_A))
        {
            cout << "\n!Wpisano nieodpowiednia tresc!\n";
            cout << "!Uruchom progam od nowa!\n\n";
            help();
            exit(1);
        }

        if(zmienna == "i")
        {
            int **A = create(wiersze_A, kolumny_A);

            cout << "Wprowadz dane do macierzy\n";
            enter(A, wiersze_A, kolumny_A);

            cout << "Wprowadz wiersz do posortowania:(pamietaj ze indeksy zaczynaja sie od 0)" << endl;
            if (!(cin >> wiersz))
            {
                cout << "\n!Wpisano nieodpowiednia tresc!\n";
                cout << "!Uruchom progam od nowa!\n\n";
                help();
                exit(1);
            }

            sortRow(A[wiersz], kolumny_A);
            disp(A, wiersze_A, kolumny_A);

            del(A, wiersze_A);
        }

        else if(zmienna == "d")
        {
            double **A = create_d(wiersze_A, kolumny_A);

            cout << "Wprowadz dane do macierzy\n";
            enter(A, wiersze_A, kolumny_A);

            cout << "Wprowadz wiersz do posortowania:" << endl;
            if (!(cin >> wiersz))
            {
                cout << "\n!Wpisano nieodpowiednia tresc!\n";
                cout << "!Uruchom progam od nowa!\n\n";
                help();
                exit(1);
            }

            sortRow(A[wiersz], kolumny_A);
            disp(A, wiersze_A, kolumny_A);

            del(A, wiersze_A);
        }
    }


    else if (strcmp(argv[1], "sortRowsInMatrix") == 0)
    {
        int wiersze_A, kolumny_A;

        cout << "Wprowadz rozmiar macierzy w ktorej chcesz posortowac wszystkie wiersze\n";
        if (!(cin >> wiersze_A >> kolumny_A))
        {
            cout << "\n!Wpisano nieodpowiednia tresc!\n";
            cout << "!Uruchom progam od nowa!\n\n";
            help();
            exit(1);
        }

        if(zmienna == "i")
        {
            int **A = create(wiersze_A, kolumny_A);

            cout << "Wprowadz dane do macierzy\n";
            enter(A, wiersze_A, kolumny_A);

            cout << "Macierz po posortowaniu:" << endl;

            sortRowsInMatrix(A, wiersze_A, kolumny_A);
            disp(A, wiersze_A, kolumny_A);

            del(A, wiersze_A);
        }

        else if(zmienna == "d")
        {
            double **A = create_d(wiersze_A, kolumny_A);

            cout << "Wprowadz dane do macierzy\n";
            enter(A, wiersze_A, kolumny_A);

            cout << "Macierz po posortowaniu:" << endl;

            sortRowsInMatrix(A, wiersze_A, kolumny_A);
            disp(A, wiersze_A, kolumny_A);

            del(A, wiersze_A);
        }
    }

    else if(strcmp(argv[1], "help") == 0 )
        help();

    else
    {
        cout << "!Wprowadzono bledy parametr uruchamiania!\n";
        help();
    }
return 11;
}