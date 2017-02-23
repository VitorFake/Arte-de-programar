format PE GUI 4.0

include 'win32w.inc'

section '.text' code readable executable;Seção de texto do executável

  push Chave;Coloca na pilha o parâmetro da função
  push ChaveCaminho;Coloca na pilha o parâmetro da função
  push HKEY_CURRENT_USER;Coloca na pilha o parâmetro da função
  call [RegOpenKeyA];Chama a função
  cmp [Chave],NULL;Compara o valor que contém no endereço
  je Erro;Em caso de igualdade salta para Erro
  push 22;;Coloca na pilha o parâmetro da função
  push ChaveDados;Coloca na pilha o parâmetro da função
  push 1;Coloca na pilha o parâmetro da função
  push 0;Coloca na pilha o parâmetro da função
  push ChaveDados;Coloca na pilha o parâmetro da função
  push [Chave];Coloca na pilha o parâmetro da função
  call [RegSetValueExA];Chama a função que coloca na chave aberta um valor
  push [Chave];Coloca na pilha o parâmetro da função
  call [RegCloseKey];Chama a função que fecha a chave
  push 0;Coloca na pilha o parâmetro da função
  call [ExitProcess];Chama a função que fecha o processo
  ret

Erro:
   invoke MessageBoxA,0,ChaveCaminho,ChaveDados,MB_ICONERROR
   push 0
   call [ExitProcess]
   ret

section '.data' data readable writeable;Seção de dados do executável

Chave dd ?
ChaveCaminho db "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run",0
ChaveDados db "c:\\Iniciar.exe"

section '.idata' import data readable writeable;Seção de importação do executável

library user32,'user32.dll',\
        kernel32,'kernel32.dll',\
        Advapi32.dll,'Advapi32.dll'
import kernel32,\
       ExitProcess,'ExitProcess'
import Advapi32.dll,\
       RegOpenKeyA,'RegOpenKeyA',\
       RegSetValueExA,'RegSetValueExA',\
       RegCloseKey,'RegCloseKey'

import user32,\
       MessageBoxA,'MessageBoxA'







