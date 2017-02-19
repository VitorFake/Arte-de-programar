#include <windows.h>
#include <winsock.h>

/*
Este projeto foi criado na IDE DevCpp projeto Win32, com adição da biblioteca

"libwsock32.a"

"Ws2_32.lib" no visual studio 

*/

//Estruturas utilizadas
SOCKADDR_IN sock;
SOCKET socket_s;
WSADATA data;
//
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) 
{
	if(WSAStartup(MAKEWORD(1,1),&data) == SOCKET_ERROR)
	   MessageBoxA(NULL,"WSAStartup","",MB_ICONERROR); 
	socket_s = socket(AF_INET,SOCK_STREAM,0);//Cria uma conexão
	    if(socket_s == SOCKET_ERROR);

	sock.sin_family = AF_INET;//Usando protocolo de internet
	sock.sin_port = htons(27);//Porta para conexão 
	   
	if(bind(socket_s,(SOCKADDR*)&sock,sizeof(sock)) == SOCKET_ERROR)//Associa um endereço local
	    MessageBoxA(NULL,"bind","",MB_ICONERROR);
	listen(socket_s,1);//Coloca a conexão em estado de escuta
	 
	while((socket_s = accept(socket_s,0,0)) == SOCKET_ERROR)//Repete enquanto a conexão não for aceita
	{
	  Sleep(1);	
	} 
	char * Msg = (char*)LocalAlloc(GPTR,1000*sizeof(char));
	send(socket_s,"Mensagem a enviar servidor !",sizeof("Mensagem a enviar servidor !"),0);//Envia uma string pela porta
	recv(socket_s,Msg,1000*sizeof(char),0);//Recebe uma string pela porta 
	MessageBoxA(NULL,Msg,"Mensagem recebida !",MB_OK);
	closesocket(socket_s);//Fecha a conexão
    WSACleanup();
	LocalFree(Msg);
	    
	return 0;
}
