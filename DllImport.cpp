#include <iostream>
#include <windows.h>

/*
 Existem dois modos de importar uma função, um é você importar o arquivo .dll no local onde você importa arquivos
 .lib na sua IDE, outro modo é importar em modo de execução através do nome da dll.
*/

/*
  Primeiro modo, esta função foi declarada na dll que foi criada anteriormente.
*/
extern "C"
#ifdef __cplusplus
{
#endif

void* __declspec(dllimport) Mensagem(void);

#ifdef __cplusplus
}
#endif

/*
  Segundo modo a dll é carregada em modo de execução.
*/

typedef void* (*FUNCDLL)(void);


int main(int argc, char** argv)
{
    //Chama a função
	Mensagem();
		
	HINSTANCE dll = LoadLibrary("DllProjeto.dll");
	FUNCDLL funcdll = (FUNCDLL)GetProcAddress(reinterpret_cast<HMODULE>(dll),"Mensagem");	
	funcdll();
	FreeLibrary(dll);
		
	return 0;
}
