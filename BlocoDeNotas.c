#include <stdio.h>
#include <Windows.h>
/* Os includes são como importações de bibliotecas */

/* Iniciando um processo filho */
int main(VOID)
{
    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    /* ALOCANDO */

    ZeroMemory(&si, sizeof(si));
    ZeroMemory(&pi, sizeof(pi));
    /* sizeof= tamanho do objeto em bites */
    /* Cria um processo filho*/
    if (!CreateProcessA(NULL, /* UTILIZ A O PROMPT DE COMANDO (aplicativo padrão) */
        "C:\\Windows\\System32\\notepad.exe", /* DIRETÓRIO DO PROGRAMA QUE DESEJA UTILIZAR */
        NULL, /* não herda manipulador do processo*/
        NULL, /* não herda manipulador do thread*/
        FALSE, /* desativa a herança de manipuladores*/
        0, /* sem flags de criação*/
        NULL, /* usa o bloco de ambiente do pai*/
        NULL, /* usa o diretório existente do pai*/
        &si,
        &pi))
    {
        fprintf(stderr, "Create Process Failed");
        return -1;
    }
    /* o pai esperará que o filho seja concluído */
    WaitForSingleObject(pi.hProcess, INFINITE);
    printf("Chil Complete");

    /* fecha manipuladores */
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
}