#include <gl/glut.h>
#include <gl/glu.h>
#include <stdlib.h>
#include <iostream>
#include <windows.h>


/*

  Foi adicionada a biblioteca glut.a
  
  Qualquer dúvida envie inbox no facebook !

*/


//Variáveis de uso interno 
float CuboRx = 0.0f, CuboRy = 0.0f, CuboRz = 0.0f;
float CubosX[100];
float CubosY[100];
int CubosR[100];
int CubosG[100];
int CubosB[100];
int Tipo[100];
float CamX = 0.0f, CamY = 0.0f, CamZ = -60.0f;
int XTela = 0;
int YTela = 0;
//



//Luzes e materiais de obejtos usados
void LuzesEMateriais(void)
{
      float luz_ambient  []  = { 0.0f, 0.0f, 0.0f, 1.0f };
      float luz_diffuse  []  = { 1.0f, 1.0f, 1.0f, 1.0f };
      float luz_specular []  = { 1.0f, 1.0f, 1.0f, 1.0f };
      float luz_pos      []  = { 2.0f, 5.0f, 5.0f, 0.0f };

      float material_ambient [] = { 0.7f, 0.7f, 0.7f, 1.0f };
      float material_diffuse [] = { 0.8f, 0.8f, 0.8f, 1.0f };
      float material_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
      float material_brilho  [] = { 100.0f };
   
    //funções de controle da luz zero    
    glLightfv(GL_LIGHT0, GL_AMBIENT,  luz_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  luz_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, luz_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, luz_pos);
    
    //Funções de controle do material
    glMaterialfv(GL_FRONT, GL_AMBIENT,   material_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   material_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  material_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, material_brilho);   
}
//



//Câmera
void Camera(int x, int y)
{    
  glMatrixMode(GL_PROJECTION);//Especifica a matriz de coordenadas 
  glLoadIdentity();//Carrega a matriz   
  //Usando câmera perspectiva
  gluPerspective(65.0f,(float)x/y,1.0f,4000.0f);
  glMatrixMode(GL_MODELVIEW);                     
  glLoadIdentity();   
  glTranslatef(CamX,CamY,CamZ);//Função de trasnlação de objetos
}
//


//Callback de redesenho
void Redesenhar(int x, int y)
{  
   XTela = x;
   YTela = y;  
   glViewport(0,0,x,y);//Seta a viewport na janela
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   Camera(x,y);    
}
//


//Callback de desenho
void Desenhar(void)
{
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);//Limpa os buffers passados como parâmetro
   glClearColor(1.0f,1.0f,1.0f,1.0f);//Limpa a tela com a cor passada como parâmetro 
   
 for(int i = 0; i < 50; ++i)
 {
   glPushMatrix();//Coloca os itens seguintes na pilha 
     glColor3f((float)CubosR[i]/255,(float)CubosG[i]/255,(float)CubosB[i]/255);
     glTranslatef(CubosX[i],CubosY[i],20.0f);
     glRotatef(CuboRx,1.0f,0.0f,0.0f);//Rotaciona o objeto em x
     glRotatef(CuboRy,0.0f,1.0f,0.0f);//Rotaciona o objeto em y
     glRotatef(CuboRz,0.0f,0.0f,1.0f);//Rotaciona o objeto em z
     
     if(Tipo[i] == 0)
     {
       glutSolidCube(4.0f);//Função pronta da glut q desenha um cubo
     }
     else if(Tipo[i] == 1)
     {
        glutWireCube(4.0f);//Função pronta da glut q desenha um cubo modo linhas 
     }
     else if(Tipo[i] == 2)
     {
        glutSolidTeapot(4.0f);//Função pronta da glut q desenha um bule de chá  
     }
     else
     {
        glutWireTeapot(4.0f);//Função pronta da glut q desenha um bule de chá modo linhas    
     }
     
   glPopMatrix();//Tira da pilha os itens
 }  
 
   CuboRx+= 1.0f;
   CuboRy+= 1.0f;
   CuboRz+= 1.0f;
   
   LuzesEMateriais();
   
   glutSwapBuffers();//Função interna glut q redesenha os contextos da janela
}
//


void TempoOcioso(void)
{
    glutPostRedisplay();
}


//Teclas capturadas
void Teclas(unsigned char teclas, int x, int y)
{
    switch (teclas) 
    {
           
      case VK_ESCAPE:
           exit(0);
      break;
      
      case 'w':
        CamZ += 2.0f;
        Camera(XTela,YTela);
      break;
      
      case 's':
        CamZ -= 2.0f;
        Camera(XTela,YTela);
      break;
      
      case 'a':
        CamX += 2.0f;
        Camera(XTela,YTela);
      break;
      
      case 'd':
        CamX -= 2.0f;
        Camera(XTela,YTela);
      break;
      
      case 'x':
           for(int i = 0; i < 100; ++i)
           {
               CubosX[i] = (float)(rand()%40)-20;
               CubosY[i] = (float)(rand()%40)-20;        
           }
      break;
      
      case 'c':
           for(int i = 0; i < 50; ++i)
             { 
               CubosR[i] = rand()%255;
               CubosG[i] = rand()%255;
               CubosB[i] = rand()%255;      
             }  
      break;
      
    }

    glutPostRedisplay();
}
//

void MousePos(int x, int y)
{
         
}


//Chamada uma vez ao iniciar para setar as configurações opengl
void Inicializando(void)
{
   for(int i = 0; i < 50; ++i)
   { 
     CubosR[i] = rand()%255;
     CubosG[i] = rand()%255;
     CubosB[i] = rand()%255;
     CubosX[i] = (float)(rand()%40)-20;
     CubosY[i] = (float)(rand()%40)-20; 
     Tipo[i] = rand()%4; 
   }  
       
       
    glClearColor(1.0f,1.0f,1.0f,1.0f);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);//Habilita as faces traseiras
    glEnable(GL_DEPTH_TEST);//Habilita o buffer de profundidade
    glDepthFunc(GL_LESS); 
    glEnable(GL_LIGHT0);//Habilita a luz de número 0
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
    LuzesEMateriais();       
}
//


void GerenciaMouse(int button, int state, int x, int y)
{
}



int main(int argc, char *argv[])
{
    MessageBoxA(NULL,"x - Criar novas posições\nc - Criar novas cores\n"
    "w s d a - mover a câmera","",MB_OK);
    srand(time(NULL));//Números randômicos
    glutInit(&argc, argv);
    glutInitWindowSize(700,500);
    glutInitWindowPosition(100,100);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Arte de programar");
    glutReshapeFunc(Redesenhar);
    glutDisplayFunc(Desenhar);
    glutKeyboardFunc(Teclas);
    glutIdleFunc(TempoOcioso);
    glutPassiveMotionFunc(MousePos);
    glutMouseFunc(GerenciaMouse);
    Inicializando();
    glutMainLoop();   
    return 0;
}

