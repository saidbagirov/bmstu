#include <stdio.h>
#include <string.h>
int input(FILE *fin, char str[1300][100], int date[1300], int civilization[1300], int *i)
{
    fin = fopen("in.txt", "r");
    if (!fin)
    {
        return 1;
    }
    int *i = 0;
    do
    {
        fgets(str[*i], 100, fin);
        fscanf(fin, "%d", &date[*i]);
        fscanf(fin, "%d", &civilization[*i]);
        i++;
    } while (str[*i] != NULL);
    if ( feof (fin) == 0)
    {
        return 1;
    } 
    fclose(fin);
    return 0;
}
int output(char result[5][100], FILE *fout)
{
    fout = fopen("out.txt", "w");
    for (int i = 0; i < 5; i++)
        fprintf(fout, "%s\n", result[i]);
    fclose(fout);
    return 0;
}
int process(FILE *fin, FILE *fout)
{
    char str[1300][100];
    int date[1300];
    char result[5][100];
    int civilization[1300];
    int i = 0;
    if (input(fin, str, date, civilization, &i) == 1)
        return 1;
    for (int j = 1; j < i; j++)
    {
        if (str[i] < str[i - 1])
        {
            char tmp;
            strncpy(tmp, str[i], strlen(str[i]));
            strncpy(str[i], str[i - 1], strlen(str[i - 1]));
            strncpy(str[i - 1], tmp, strlen(tmp));
        }
    }
    for (int l = 0; l < 5; l++)
    {
        strncpy(result[i], str[i], strlen(str[i]));
    }
    output(result, fout);
    return 0;
} 
int main()
{
    FILE *fint;
    FILE *fout;
    if (process(fin, fout) == 1)
        return 1;
    return 0;
}