#include "../inlcude/lib.h"

void help()
{
    cout << "Mozliwe opcje:(wybierz jedna z nich jako parametr uruchamiania, potem postepuj zgodnie z instrukcjami na akranie)\n";
    cout << "\n   Opcje \t\t\t\t\t| parametr uruchamiania\n";
    cout << "1. Dodawanie macierzy A + B \t\t\t| 'addMatrix'\n";
    cout << "2. Odejmowanie macierzy A - B \t\t\t| 'subtractMatrix'\n";
    cout << "3. Mnozenie dwoch macierzy A x B \t\t| 'multiplyMatrix'\n";
    cout << "4. Mnozenie macierzy przez skalar A x s \t| 'multiplyByScalar'\n";
    cout << "5. Transponowanie macierzy \t\t\t| 'transpozeMatrix'\n";
    cout << "6. Potegowanie macierzy \t\t\t| 'powerMatrix'\n";
    cout << "7. Wyznacznik macierzy \t\t\t\t| 'determinantMatrix'\n";
    cout << "8. Sprawdzanie czy macierz jest diagonalna \t| 'matrixIsDiagonal'\n";
    cout << "9. Zamiana dwoch wartosci miejscami \t\t| 'swap'\n";
    cout << "10.Sortowanie podanego wiersz \t\t\t| 'sortRow'\n";
    cout << "11.Sortowanie wszystkich wierszy \t\t| 'sortRowsInMatrix'\n\n";
    cout << "Przyklad jak wprowadzac dane do macierzy o rozmiarze 2x3:\n\n";
    cout << "Wprowadz rozmiar macierzy ktore chcesz dodac (wiersze _ kolumny):\n";
    cout << "2 3\n";
    cout << "Wprowadz dane do macierzy\n";
    cout << "1 2 3\n";
    cout << "4 5 6\n";
}


int **create(int wiersze, int kolumny)
{
    int **M = new int *[wiersze];

    for (int i = 0; i < wiersze; i++)
        M[i] = new int[kolumny];

    return M;
}

void del(int **M, int wiersze)
{
    for (int i = 0; i < wiersze; i++)
        delete[] M[i];

    delete[] M;
}

void enter(int **M, int wiersze, int kolumny)
{
    for (int i = 0; i < wiersze; i++)
        for (int j = 0; j < kolumny; j++)
            if (!(cin >> M[i][j]))
            {
                cout << "\n!Wpisano nieodpowiednia tresc!\n";
                cout << "!Uruchom progam od nowa!\n\n";
                help();
                exit(1);
            }
}

void disp(int **M, int wiersze, int kolumny)
{
    for (int i = 0; i < wiersze; i++)
    {
        for (int j = 0; j < kolumny; j++)
            cout << setw(6) << M[i][j];

        cout << endl;
    }
}

int **multiplyMatrix(int **A, int **B, int wiersze_A, int kolumny_A, int kolumny_B)
{
    int **M = create(wiersze_A, kolumny_B), pom;

    for (int i = 0; i < wiersze_A; i++)
        for (int j = 0; j < kolumny_B; j++)
        {
            pom = 0;
            for (int k = 0; k < kolumny_A; k++)
                pom += A[i][k] * B[k][j];
            M[i][j] = pom;
        }

    return M;
}

int **addMatrix(int **A, int **B, int wiersze, int kolumny)
{
    int **M = create(wiersze, kolumny);

    for (int i = 0; i < wiersze; i++)
        for (int j = 0; j < kolumny; j++)
            M[i][j] = A[i][j] + B[i][j];

    return M;
}

int **subtractMatrix(int **A, int **B, int wiersze, int kolumny)
{
    int **M = create(wiersze, kolumny);

    for (int i = 0; i < wiersze; i++)
        for (int j = 0; j < kolumny; j++)
            M[i][j] = A[i][j] - B[i][j];

    return M;
}

int **multiplyByScalar(int **A, int wiersze, int kolumny, int skal)
{
    int **M = create(wiersze, kolumny);

    for (int i = 0; i < wiersze; i++)
        for (int j = 0; j < kolumny; j++)
            M[i][j] = A[i][j] * skal;
    return M;
}

int **transpozeMatrix(int **A, int wiersze, int kolumny)
{
    int **M = create(kolumny, wiersze);

    for (int i = 0; i < wiersze; i++)
        for (int j = 0; j < kolumny; j++)
            M[j][i] = A[i][j];
    return M;
}


int **powerMatrix(int **A, int wiersze, unsigned int poteg)
{
    int **M = create(wiersze, wiersze);

    for (int i = 0; i < wiersze; i++)
        for (int j = 0; j < wiersze; j++)
            M[i][j] = pow(A[i][j], poteg);

    return M;
}


int determinantMatrix(int **A, int wiersze)
{
    int **M = create(wiersze, wiersze);
    int det = 0, p, h, k, i, j;

    if (wiersze == 1)
        return A[0][0];


    else if (wiersze == 2)
    {
        det = (A[0][0] * A[1][1] - A[0][1] * A[1][0]);
        return det;
    } else
    {
        for (p = 0; p < wiersze; p++)
        {
            h = 0;
            k = 0;

            for (i = 1; i < wiersze; i++)
            {
                for (j = 0; j < wiersze; j++)
                {
                    if (j == p)
                        continue;

                    M[h][k] = A[i][j];
                    k++;

                    if (k == wiersze - 1)
                    {
                        h++;
                        k = 0;
                    }
                }
            }

            det = det + A[0][p] * pow(-1, p) * determinantMatrix(M, wiersze - 1);
        }
        del(M, wiersze);
        return det;
    }
}


bool matrixIsDiagonal(int **A, int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (j != i && A[i][j] != 0)
                return false;

    return true;
}

void swap(int &a, int &b)
{
    int pom = a;
    a = b;
    b = pom;
}

void sortRow(int *A, int kolumny)
{
    for (int j = 0; j < kolumny - 1; ++j)
        for (int i = 0; i < kolumny - 1; ++i)
            if (A[i] > A[i + 1])
                swap(A[i], A[i + 1]);
}

void sortRowsInMatrix(int **A, int wiersze, int kolumny)
{
    for (int i = 0; i < wiersze; ++i)
        sortRow(A[i], kolumny);
}


/////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////

double **create_d(int wiersze, int kolumny)
{
    double **M = new double *[wiersze];

    for (int i = 0; i < wiersze; i++)
        M[i] = new double[kolumny];

    return M;
}

void del(double **M, int wiersze)
{
    for (int i = 0; i < wiersze; i++)
        delete[] M[i];

    delete[] M;
}

void enter(double **M, int wiersze, int kolumny)
{
    for (int i = 0; i < wiersze; i++)
        for (int j = 0; j < kolumny; j++)
            if (!(cin >> M[i][j]))
            {
                cout << "\n!Wpisano nieodpowiednia tresc!\n";
                cout << "!Uruchom progam od nowa!\n\n";
                help();
                exit(1);
            }
}

void disp(double **M, int wiersze, int kolumny)
{
    for (int i = 0; i < wiersze; i++)
    {
        for (int j = 0; j < kolumny; j++)
            cout << setw(6) << M[i][j];

        cout << endl;
    }
}

double **multiplyMatrix(double **A, double **B, int wiersze_A, int kolumny_A, int kolumny_B)
{
    double **M = create_d(wiersze_A, kolumny_B), pom;

    for (int i = 0; i < wiersze_A; i++)
        for (int j = 0; j < kolumny_B; j++)
        {
            pom = 0.0;
            for (int k = 0; k < kolumny_A; k++)
                pom += A[i][k] * B[k][j];
            M[i][j] = pom;
        }

    return M;
}

double **addMatrix(double **A, double **B, int wiersze, int kolumny)
{
    double **M = create_d(wiersze, kolumny);

    for (int i = 0; i < wiersze; i++)
        for (int j = 0; j < kolumny; j++)
            M[i][j] = A[i][j] + B[i][j];

    return M;
}

double **subtractMatrix(double **A, double **B, int wiersze, int kolumny)
{
    double **M = create_d(wiersze, kolumny);

    for (int i = 0; i < wiersze; i++)
        for (int j = 0; j < kolumny; j++)
            M[i][j] = A[i][j] - B[i][j];

    return M;
}

double **multiplyByScalar(double **A, int wiersze, int kolumny, double skal)
{
    double **M = create_d(wiersze, kolumny);

    for (int i = 0; i < wiersze; i++)
        for (int j = 0; j < kolumny; j++)
            M[i][j] = A[i][j] * skal;
    return M;
}

double **transpozeMatrix(double **A, int wiersze, int kolumny)
{
    double **M = create_d(kolumny, wiersze);

    for (int i = 0; i < wiersze; i++)
        for (int j = 0; j < kolumny; j++)
            M[j][i] = A[i][j];
    return M;
}


double **powerMatrix(double **A, int wiersze, unsigned int poteg)
{
    double **M = create_d(wiersze, wiersze);

    for (int i = 0; i < wiersze; i++)
        for (int j = 0; j < wiersze; j++)
            M[i][j] = pow(A[i][j], poteg);

    return M;
}


double determinantMatrix(double **A, int wiersze)
{
    double **M = create_d(wiersze, wiersze);
    double det = 0.0;
    int p, h, k, i, j;

    if (wiersze == 1)
        return A[0][0];


    else if (wiersze == 2)
    {
        det = (A[0][0] * A[1][1] - A[0][1] * A[1][0]);
        return det;
    } else
    {
        for (p = 0; p < wiersze; p++)
        {
            h = 0;
            k = 0;

            for (i = 1; i < wiersze; i++)
            {
                for (j = 0; j < wiersze; j++)
                {
                    if (j == p)
                        continue;

                    M[h][k] = A[i][j];
                    k++;

                    if (k == wiersze - 1)
                    {
                        h++;
                        k = 0;
                    }
                }
            }

            det = det + A[0][p] * pow(-1, p) * determinantMatrix(M, wiersze - 1);
        }
        del(M, wiersze);
        return det;
    }
}

bool matrixIsDiagonal(double **A, int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (j != i && A[i][j] != 0.0)
                return false;

    return true;
}


void swap(double &a, double &b)
{
    double pom = a;
    a = b;
    b = pom;
}

void sortRow(double *A, int kolumny)
{
    for (int j = 0; j < kolumny - 1; ++j)
        for (int i = 0; i < kolumny - 1; ++i)
            if (A[i] > A[i + 1])
                swap(A[i], A[i + 1]);
}

void sortRowsInMatrix(double **A, int wiersze, int kolumny)
{
    for (int i = 0; i < wiersze; ++i)
        sortRow(A[i], kolumny);
}
