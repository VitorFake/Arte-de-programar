
#include <windows.h>
#include <iostream>
#include <wininet.h>

int __stdcall WinMain(HINSTANCE hinstance, HINSTANCE hInst, LPSTR l_str, int l_show)
{
	
  //Abre o handle 
  HINTERNET internet = InternetOpenA("ftp.SeuSite.com.br",INTERNET_OPEN_TYPE_PRECONFIG,NULL,NULL,0); 
    if(internet == NULL)
        MessageBoxA(NULL,"InternetOpenA","",MB_ICONERROR);
  //Conecta ao seu servidor ftp pela porta 21
  HINTERNET connect = InternetConnectA(internet,"ftp.SeuSite.com.br",21,"Usuário","Senha",
  INTERNET_SERVICE_FTP,INTERNET_FLAG_PASSIVE,0); 
    if(connect == NULL)
       MessageBoxA(NULL,"InternetConnectA","",MB_ICONERROR);    
  //Pega um arquivo do servidor ftp e cria o mesmo em um local do computador, FTP_TRANSFER_TYPE_BINARY é usado quando transferimos um arquivo binário
  //por exemlo um arquivo .exe, também pode ser usado FTP_TRANSFER_TYPE_ASCII para arquivos de texto 
  FtpGetFileA(connect,"ArquivoDoSite.arquivo","c:\\ArquivoDoComputador.arquivo",FALSE,FILE_ATTRIBUTE_NORMAL,FTP_TRANSFER_TYPE_BINARY,0); 
  //Pega um arquivo do computador e o coloca no servidor fpt , FTP_TRANSFER_TYPE_BINARY é usado quando transferimos um arquivo binário
  //por exemlo um arquivo .exe, também pode ser usado FTP_TRANSFER_TYPE_ASCII para arquivos de texto 
  FtpPutFileA(connect,"c:\\ArquivoDoComputador.arquivo","ArquivoDoSite.arquivo",FTP_TRANSFER_TYPE_BINARY,0);
  //Deleta um arquivo do servidor 
  FtpDeleteFileA(connect,"ArquivoDoSite.arquivo");
  //Fecha a conexão 
  InternetCloseHandle(internet);
  InternetCloseHandle(connect);
  return 0;
}

