#ifndef _DLL_H_
#define _DLL_H_


#include <windows.h>


class __declspec(dllexport) DllClass
{
	public:
		DllClass();
		virtual ~DllClass();
};


extern "C"
#ifdef __cplusplus
{
#endif

   //Função para exportação 
   void* __declspec(dllexport) Mensagem(void)
   {
   	 MessageBoxA(NULL,"Função chamada com sucesso !","",0);
   }
   //

#ifdef __cplusplus	
}
#endif

#endif
