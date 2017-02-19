#include <windows.h>

int __stdcall WinMain(HINSTANCE hinstance, HINSTANCE hInst, LPSTR l_str, int l_int)
{
	
   //retorna o handle da janela de acordo com o nome
   HWND janelaProcesso = FindWindowA(NULL,"Plants vs. Zombies");
   if(janelaProcesso == NULL)
       MessageBoxA(NULL,"FindWindowA","",MB_ICONERROR);
   DWORD idProcesso; 
   //Pega um id de um processo de acordo com um HWND
   GetWindowThreadProcessId(janelaProcesso,&idProcesso);
   //Abre o processo
   HANDLE Processo = OpenProcess(PROCESS_ALL_ACCESS,false,idProcesso);
   DWORD Saida;
   DWORD Valor = 9999;
   //Escreve na memória do processo,0x0000 é o endereço e Valor é valor para colocar na memória
   if(WriteProcessMemory(Processo,(void*)0x1117B5E8,&Valor,sizeof(Valor),NULL) < 0)
   {
     CloseHandle(Processo);                                   
     MessageBoxA(NULL,"WriteProcessMemory","",MB_ICONERROR);
   }
   //Lê um valor na memória do processo , 0x0000 é o endereço e Dados é o valor pego 
   DWORD Dados;
   if(ReadProcessMemory(Processo,(void*)0x1117B5E8,&Dados,sizeof(Dados),NULL) < 0)
   {
     CloseHandle(Processo);                                   
     MessageBoxA(NULL,"ReadProcessMemory","",MB_ICONERROR);
   }
   //Fecha o processo	
   CloseHandle(Processo);

  return 0;
}

