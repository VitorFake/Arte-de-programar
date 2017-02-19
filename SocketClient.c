#include <windows.h>
#include <winsock.h>

/*
Este projeto foi criado na IDE DevCpp projeto Win32, com adição da biblioteca

"libwsock32.a"

"Ws2_32.lib" no visual studio 

*/

SOCKADDR_IN  sock;
SOCKET socket_s;
WSADATA data; 
 
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) 
{
   if(WSAStartup(MAKEWORD(1,1),&data) == SOCKET_ERROR)
      MessageBoxA(NULL,"WSAStartup","",MB_ICONERROR);
   socket_s = socket(AF_INET,SOCK_STREAM,0);//Cria uma conexão
   if(socket_s == SOCKET_ERROR)
      MessageBoxA(NULL,"socket","",MB_ICONERROR);
   sock.sin_addr.s_addr = inet_addr("127.0.0.1");//Ip da conexão 
   sock.sin_family = AF_INET;//Usando protocolo de internet
   sock.sin_port = htons(27);//Porta para conexão
   
   if(connect(socket_s,(SOCKADDR*)&sock,sizeof(sock)) == SOCKET_ERROR)//Conecta ao servidor
      MessageBoxA(NULL,"connect","",MB_ICONERROR);
  
   char *Dados = (char*)LocalAlloc(GPTR,1000*sizeof(char));
   recv(socket_s,Dados,1000*sizeof(char),0);//Recebe uma string pela porta 
   send(socket_s,"Mensagem a enviar cliente !",sizeof("Mensagem a enviar cliente !"),0);//Envia uma string pela porta
   MessageBoxA(NULL,Dados,"Dados Recebidos do servidor !",MB_OK);
   LocalFree(Dados);
   closesocket(socket_s);
   WSACleanup();
}
