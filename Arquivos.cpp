#include <iostream>
#include <windows.h>


int main(int argc, char** argv) 
{
	
	
	HANDLE ArquivoEscrever = CreateFileA("c:\\Arquivo.txt",GENERIC_WRITE,0,
	NULL,CREATE_NEW,FILE_ATTRIBUTE_NORMAL,NULL);//Cria o arquivo para escrita
	     if(ArquivoEscrever == NULL)
	     {
	     	MessageBoxA(NULL,"CreateFileA","",MB_ICONERROR);
	     	CloseHandle(ArquivoEscrever);
		 }
	DWORD BytesEscritos;
	WriteFile(ArquivoEscrever,"Texto",sizeof("Texto"),&BytesEscritos,0);//Escreve no arquivo criado
	CloseHandle(ArquivoEscrever);//Fecha o arquivo
	
	
	
	HANDLE ArquivoLer = CreateFileA("c:\\Arquivo.txt",GENERIC_READ,0,NULL,
	OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,NULL);//Cria arquivo para leitura
	      if(ArquivoLer == NULL)
	      {
	      	MessageBoxA(NULL,"CreateFileA","",MB_ICONERROR);
		  }
	DWORD BytesLidos;
	DWORD Tamanho = GetFileSize(ArquivoLer,NULL);//Retorna o tamanho do arquivo
	char* Texto = (char*)GlobalAlloc(GPTR,Tamanho*sizeof(char));//Aloca memória de acordo com o tamanho do arquivo 
	ReadFile(ArquivoLer,Texto,Tamanho*sizeof(char)*1024,&BytesLidos,NULL);//Lê os dados do arquivo
	GlobalFree(Texto);//Libera a memória 
	CloseHandle(ArquivoLer);//Fecha o arquivo
	
	return 0;
}
