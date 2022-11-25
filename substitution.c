#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool validation(string key);
void substitution(string text, string key);

int main(int argc, string argv[])
{

    if (argc != 2)//accepting the argument
    {
        printf("one arg\n");
        return 1;
    }
    if (validation(argv[1]))//invoca validação
    {
        string text = get_string("Text: ");
        string chave = argv[1];
        substitution(text, chave);
        return 0;
    }
    return 1;
}
bool validation(string key)//fuction for validating the key
{
    int len = strlen(key);

    if (len != 26)
    {
        printf("Key must contain 26 characters.\n");
        return false;
    }

    for (int i = 0; i < len; i++)
    {

        if ((!isalpha(key[i])))
        {
            printf("Key must only contain alphabetic characters.\n");
            return false;
        }

        for (int j = 0, m = len; j < m; j++)
        {
            for (int k = j + 1, o = len; k < o; k++)
            {
                if (key[j] == key[k] || key[j] + 32 == key[k] + 32 || key[j] - 32 == key[k] - 32)
                {
                    printf("Key must not contain repeated characters.\n");
                    return false;
                }
            }
        }
    }
    return true;
}
void substitution(string text, string key)
{
    printf("ciphertext:");
    for (int i = 0, n = strlen(text); i < n; i++)//percorre o texto
    {
        char letter = text[i]; //letter = letra atual
        int nl = letter;//nl = número correspondente a letra ascii
        if (nl >= 65 && nl <= 90)//Confere maiuscula
        {
            /*codifica texto */
            char converte = toupper(key [nl - 65]);
            printf("%c", converte);
        }
        else if (letter >= 'a' && letter <= 'z')//Confere minuscula
        {
             /*codifica texto */
             char converte = tolower(key [nl - 97]);
             printf("%c", converte);

        }
        else
        {
            printf("%c", letter);

        }
    }
    printf("\n");
}
