#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

#define TAM 2

int num_pecas = 32, sx = -1, sy = -1, flag = 0;
char scx = ' ', scy = ' ', texto[30];
char posicoes[7][7] = {'i','i','p','p','p','i','i',//inválida, preenchida, vazia, selecionada ( i, p, v, s )
                       'i','i','p','p','p','i','i',
                       'p','p','p','p','p','p','p',
                       'p','p','p','v','p','p','p',
                       'p','p','p','p','p','p','p',
                       'i','i','p','p','p','i','i',
                       'i','i','p','p','p','i','i'};

void MoveMouse(int x, int y)
{
    if(!flag) sprintf(texto, /*"(%d,%d) - */"%c%c"/*, x, y*/, scx, scy);
    glutPostRedisplay();
}

void DesenhaTexto(char *string)
{
  	glPushMatrix();
        // Posicao no universo onde o texto sera colocado
        glRasterPos2f(-1,12);
        // Exibe caracter a caracter
        while(*string)
             glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,*string++);
	glPopMatrix();
}

void divisas()
{
    glColor3f(0.0, 0.0, 0.0);
    glPushMatrix();//ESQUERDA SUPERIOR DEITADA
        glTranslated(1,9,0);
        glScaled(4.1,0.1,0.1);
        glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();//ESQUERDA INFERIOR DEITADA
        glTranslated(1,3,0);
        glScaled(4.1,0.1,0.1);
        glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();//DIREITA SUPERIOR DEITADA
        glTranslated(11,9,0);
        glScaled(4.1,0.1,0.1);
        glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();//DIREITA INFERIOR DEITADA
        glTranslated(11,3,0);
        glScaled(4.1,0.1,0.1);
        glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();//ESQUERDA SUPERIOR EM PÉ
        glTranslated(3,11,0);
        glRotated(90,0,0,1);
        glScaled(4.1,0.1,0.1);
        glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();//ESQUERDA INFERIOR EM PÉ
        glTranslated(3,1,0);
        glRotated(90,0,0,1);
        glScaled(4.1,0.1,0.1);
        glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();//DIREITA SUPERIOR EM PÉ
        glTranslated(9,11,0);
        glRotated(90,0,0,1);
        glScaled(4.1,0.1,0.1);
        glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();//DIREITA INFERIOR EM PÉ
        glTranslated(9,1,0);
        glRotated(90,0,0,1);
        glScaled(4.1,0.1,0.1);
        glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();//CENTRAL INFERIOR
        glTranslated(6,-1,0);
        glScaled(6.1,0.1,0.1);
        glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();//CENTRAL SUPERIOR
        glTranslated(6,13,0);
        glScaled(6.1,0.1,0.1);
        glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();//CENTRAL ESQUERDA
        glTranslated(-1,6,0);
        glRotated(90,0,0,1);
        glScaled(6.1,0.1,0.1);
        glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();//CENTRAL DIREITA
        glTranslated(13,6,0);
        glRotated(90,0,0,1);
        glScaled(6.1,0.1,0.1);
        glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();//INTERNA CENTRAL-ESQUERDA VERTICAL
        glTranslated(5,6,0);
        glRotated(90,0,0,1);
        glScaled(14,0.05,0.05);
        glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();//INTERNA CENTRAL-DIREITA VERTICAL
        glTranslated(7,6,0);
        glRotated(90,0,0,1);
        glScaled(14,0.05,0.05);
        glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();//INTERNA CENTRAL-INFERIOR HORIZONTAL
        glTranslated(6,5,0);
        glScaled(14,0.05,0.05);
        glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();//INTERNA CENTRAL-SUPERIOR HORIZONTAL
        glTranslated(6,7,0);
        glScaled(14,0.05,0.05);
        glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();//INTERNA ESQUERDA-DIREITA VERTICAL
        glTranslated(3,6,0);
        glRotated(90,0,0,1);
        glScaled(6,0.05,0.05);
        glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();//INTERNA ESQUERDA-ESQUERDA VERTICAL
        glTranslated(1,6,0);
        glRotated(90,0,0,1);
        glScaled(6,0.05,0.05);
        glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();//INTERNA DIREITA-ESQUERDA VERTICAL
        glTranslated(9,6,0);
        glRotated(90,0,0,1);
        glScaled(6,0.05,0.05);
        glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();//INTERNA DIREITA-DIREITA VERTICAL
        glTranslated(11,6,0);
        glRotated(90,0,0,1);
        glScaled(6,0.05,0.05);
        glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();//INTERNA INFERIOR-INFERIOR HORIZONTAL
        glTranslated(6,1,0);
        glScaled(6,0.05,0.05);
        glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();//INTERNA INFERIOR-SUPERIOR HORIZONTAL
        glTranslated(6,3,0);
        glScaled(6,0.05,0.05);
        glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();//INTERNA SUPERIOR-SUPERIOR HORIZONTAL
        glTranslated(6,11,0);
        glScaled(6,0.05,0.05);
        glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();//INTERNA SUPERIOR-INFERIOR HORIZONTAL
        glTranslated(6,9,0);
        glScaled(6,0.05,0.05);
        glutSolidCube(1);
    glPopMatrix();
}

void desenha_pecas(int cx, int cy)
{
    if(posicoes[cx][cy] == 'p' || posicoes[cx][cy] == 's'){
        if(posicoes[cx][cy] == 's') glColor4ub(0,0,127,0.5);
        else glColor4ub(25.5,102,153,0.5);
        glPushMatrix();
            glTranslated(cx* TAM, cy* TAM, 0);
            glutSolidSphere(0.25 * TAM, 16, 16);
        glPopMatrix();
    } else if(posicoes[cx][cy] == 'v'){
        glColor4ub(25.5,102,153,0.5);
        glPushMatrix();
            glTranslated(cx* TAM, cy* TAM, 0);
            glutSolidTorus(0.1,0.5,16,16);
        glPopMatrix();
    }
}

void game_over()
{//VERIFICA SE O JOGO ACABOU E SE GANHOU OU PERDEU
                                                            //PEÇA E PARA ONDE PODE COMER
    if(     posicoes[0][4] == 'p' || posicoes[0][4] == 's'){//A5: BAIXO, DIREITA
        if(posicoes[0][3] == 'p' || posicoes[0][3] == 's'){
            if(posicoes[0][2] == 'v')
                return;
        }
        if(posicoes[1][4] == 'p' || posicoes[1][4] == 's'){
            if(posicoes[2][4] == 'v')
                return;
        }
    }
    if(posicoes[0][3] == 'p' || posicoes[0][3] == 's'){//A4: DIREITA
        if(posicoes[1][3] == 'p' || posicoes[1][3] == 's'){
            if(posicoes[2][3] == 'v')
                return;
        }
    }
    if(posicoes[0][2] == 'p' || posicoes[0][2] == 's'){//A3: CIMA, DIREITA
        if(posicoes[0][3] == 'p' || posicoes[0][3] == 's'){
            if(posicoes[0][4] == 'v')
                return;
        }
        if(posicoes[1][2] == 'p' || posicoes[1][2] == 's'){
            if(posicoes[2][2] == 'v')
                return;
        }
    }
    if(posicoes[1][4] == 'p' || posicoes[1][4] == 's'){//B5: BAIXO, DIREITA
        if(posicoes[1][3] == 'p' || posicoes[1][3] == 's'){
            if(posicoes[1][2] == 'v')
                return;
        }
        if(posicoes[2][4] == 'p' || posicoes[2][4] == 's'){
            if(posicoes[3][4] == 'v')
                return;
        }
    }
    if(posicoes[1][3] == 'p' || posicoes[1][3] == 's'){//B4: DIREITA
        if(posicoes[2][3] == 'p' || posicoes[2][3] == 's'){
            if(posicoes[3][3] == 'v')
                return;
        }
    }
    if(posicoes[1][2] == 'p' || posicoes[1][2] == 's'){//B3: CIMA, DIREITA
        if(posicoes[1][3] == 'p' || posicoes[1][3] == 's'){
            if(posicoes[1][4] == 'v')
                return;
        }
        if(posicoes[2][2] == 'p' || posicoes[2][2] == 's'){
            if(posicoes[3][2] == 'v')
                return;
        }
    }
    if(posicoes[2][6] == 'p' || posicoes[2][6] == 's'){//C7: BAIXO, DIREITA
        if(posicoes[2][5] == 'p' || posicoes[2][5] == 's'){
            if(posicoes[2][4] == 'v')
                return;
        }
        if(posicoes[3][6] == 'p' || posicoes[3][6] == 's'){
            if(posicoes[4][6] == 'v')
                return;
        }
    }
    if(posicoes[2][5] == 'p' || posicoes[2][5] == 's'){//C6: BAIXO, DIREITA
        if(posicoes[2][4] == 'p' || posicoes[2][4] == 's'){
            if(posicoes[2][3] == 'v')
                return;
        }
        if(posicoes[3][5] == 'p' || posicoes[3][5] == 's'){
            if(posicoes[4][5] == 'v')
                return;
        }
    }
    if(posicoes[2][4] == 'p' || posicoes[2][4] == 's'){//C5: CIMA, BAIXO, DIREITA, ESQUERDA*
        if(posicoes[2][5] == 'p' || posicoes[2][5] == 's'){
            if(posicoes[2][6] == 'v')
                return;
        }
        if(posicoes[2][3] == 'p' || posicoes[2][3] == 's'){
            if(posicoes[2][2] == 'v')
                return;
        }
        if(posicoes[3][4] == 'p' || posicoes[3][4] == 's'){
            if(posicoes[4][4] == 'v')
                return;
        }
        if(posicoes[1][4] == 'p' || posicoes[1][4] == 's'){
            if(posicoes[0][4] == 'v')
                return;
        }
    }
    if(posicoes[2][3] == 'p' || posicoes[2][3] == 's'){//C4: CIMA, BAIXO, DIREITA, ESQUERDA*
        if(posicoes[2][4] == 'p' || posicoes[2][4] == 's'){
            if(posicoes[2][5] == 'v')
                return;
        }
        if(posicoes[2][2] == 'p' || posicoes[2][2] == 's'){
            if(posicoes[2][1] == 'v')
                return;
        }
        if(posicoes[3][3] == 'p' || posicoes[3][3] == 's'){
            if(posicoes[4][3] == 'v')
                return;
        }
        if(posicoes[1][3] == 'p' || posicoes[1][3] == 's'){
            if(posicoes[0][3] == 'v')
                return;
        }
    }
    if(posicoes[2][2] == 'p' || posicoes[2][2] == 's'){//C3: CIMA, BAIXO, DIREITA, ESQUERDA*
        if(posicoes[2][3] == 'p' || posicoes[2][3] == 's'){
            if(posicoes[2][4] == 'v')
                return;
        }
        if(posicoes[2][1] == 'p' || posicoes[2][1] == 's'){
            if(posicoes[2][0] == 'v')
                return;
        }
        if(posicoes[3][2] == 'p' || posicoes[3][2] == 's'){
            if(posicoes[4][2] == 'v')
                return;
        }
        if(posicoes[1][2] == 'p' || posicoes[1][2] == 's'){
            if(posicoes[0][2] == 'v')
                return;
        }
    }
    if(posicoes[2][1] == 'p' || posicoes[2][1] == 's'){//C2: CIMA, DIREITA
        if(posicoes[2][2] == 'p' || posicoes[2][2] == 's'){
            if(posicoes[2][3] == 'v')
                return;
        }
        if(posicoes[3][1] == 'p' || posicoes[3][1] == 's'){
            if(posicoes[4][1] == 'v')
                return;
        }
    }
    if(posicoes[2][0] == 'p' || posicoes[2][0] == 's'){//C1: CIMA, DIREITA
        if(posicoes[2][1] == 'p' || posicoes[2][1] == 's'){
            if(posicoes[2][2] == 'v')
                return;
        }
        if(posicoes[3][0] == 'p' || posicoes[3][0] == 's'){
            if(posicoes[4][0] == 'v')
                return;
        }
    }
    if(posicoes[3][6] == 'p' || posicoes[3][6] == 's'){//D7: BAIXO
        if(posicoes[3][5] == 'p' || posicoes[3][5] == 's'){
            if(posicoes[3][4] == 'v')
                return;
        }
    }
    if(posicoes[3][5] == 'p' || posicoes[3][5] == 's'){//D6: BAIXO
        if(posicoes[3][4] == 'p' || posicoes[3][4] == 's'){
            if(posicoes[3][3] == 'v')
                return;
        }
    }
    if(posicoes[3][4] == 'p' || posicoes[3][4] == 's'){//D5: CIMA, BAIXO, DIREITA, ESQUERDA*
        if(posicoes[3][5] == 'p' || posicoes[3][5] == 's'){
            if(posicoes[3][6] == 'v')
                return;
        }
        if(posicoes[3][3] == 'p' || posicoes[3][3] == 's'){
            if(posicoes[3][2] == 'v')
                return;
        }
        if(posicoes[4][4] == 'p' || posicoes[4][4] == 's'){
            if(posicoes[5][4] == 'v')
                return;
        }
        if(posicoes[2][4] == 'p' || posicoes[2][4] == 's'){
            if(posicoes[1][4] == 'v')
                return;
        }
    }
    if(posicoes[3][3] == 'p' || posicoes[3][3] == 's'){//D4: CIMA, BAIXO, DIREITA, ESQUERDA*
        if(posicoes[3][4] == 'p' || posicoes[3][4] == 's'){
            if(posicoes[3][5] == 'v')
                return;
        }
        if(posicoes[3][2] == 'p' || posicoes[3][2] == 's'){
            if(posicoes[3][1] == 'v')
                return;
        }
        if(posicoes[4][3] == 'p' || posicoes[4][3] == 's'){
            if(posicoes[5][3] == 'v')
                return;
        }
        if(posicoes[2][3] == 'p' || posicoes[2][3] == 's'){
            if(posicoes[1][3] == 'v')
                return;
        }
    }
    if(posicoes[3][2] == 'p' || posicoes[3][2] == 's'){//D3: CIMA, BAIXO, DIREITA, ESQUERDA*
        if(posicoes[3][3] == 'p' || posicoes[3][3] == 's'){
            if(posicoes[3][4] == 'v')
                return;
        }
        if(posicoes[3][1] == 'p' || posicoes[3][1] == 's'){
            if(posicoes[3][0] == 'v')
                return;
        }
        if(posicoes[4][2] == 'p' || posicoes[4][2] == 's'){
            if(posicoes[5][2] == 'v')
                return;
        }
        if(posicoes[2][2] == 'p' || posicoes[2][2] == 's'){
            if(posicoes[1][2] == 'v')
                return;
        }
    }
    if(posicoes[3][1] == 'p' || posicoes[3][1] == 's'){//D2: CIMA
        if(posicoes[3][2] == 'p' || posicoes[3][2] == 's'){
            if(posicoes[3][3] == 'v')
                return;
        }
    }
    if(posicoes[3][0] == 'p' || posicoes[3][0] == 's'){//D1: CIMA
        if(posicoes[3][1] == 'p' || posicoes[3][1] == 's'){
            if(posicoes[3][2] == 'v')
                return;
        }
    }
    if(posicoes[4][6] == 'p' || posicoes[4][6] == 's'){//E7: BAIXO, ESQUERDA
        if(posicoes[4][5] == 'p' || posicoes[4][5] == 's'){
            if(posicoes[4][4] == 'v')
                return;
        }
        if(posicoes[3][6] == 'p' || posicoes[3][6] == 's'){
            if(posicoes[2][6] == 'v')
                return;
        }
    }
    if(posicoes[4][5] == 'p' || posicoes[4][5] == 's'){//E6: BAIXO, ESQUERDA
        if(posicoes[4][4] == 'p' || posicoes[4][4] == 's'){
            if(posicoes[4][3] == 'v')
                return;
        }
        if(posicoes[3][5] == 'p' || posicoes[3][5] == 's'){
            if(posicoes[2][5] == 'v')
                return;
        }
    }
    if(posicoes[4][4] == 'p' || posicoes[4][4] == 's'){//E5: CIMA, BAIXO, DIREITA, ESQUERDA*
        if(posicoes[4][5] == 'p' || posicoes[4][5] == 's'){
            if(posicoes[4][6] == 'v')
                return;
        }
        if(posicoes[4][3] == 'p' || posicoes[4][3] == 's'){
            if(posicoes[4][2] == 'v')
                return;
        }
        if(posicoes[5][4] == 'p' || posicoes[5][4] == 's'){
            if(posicoes[6][4] == 'v')
                return;
        }
        if(posicoes[3][4] == 'p' || posicoes[3][4] == 's'){
            if(posicoes[2][4] == 'v')
                return;
        }
    }
    if(posicoes[4][3] == 'p' || posicoes[4][3] == 's'){//E4: CIMA, BAIXO, DIREITA, ESQUERDA*
        if(posicoes[4][4] == 'p' || posicoes[4][4] == 's'){
            if(posicoes[4][5] == 'v')
                return;
        }
        if(posicoes[4][2] == 'p' || posicoes[4][2] == 's'){
            if(posicoes[4][1] == 'v')
                return;
        }
        if(posicoes[5][3] == 'p' || posicoes[5][3] == 's'){
            if(posicoes[6][3] == 'v')
                return;
        }
        if(posicoes[3][3] == 'p' || posicoes[3][3] == 's'){
            if(posicoes[2][3] == 'v')
                return;
        }
    }
    if(posicoes[4][2] == 'p' || posicoes[4][2] == 's'){//E3: CIMA, BAIXO, DIREITA, ESQUERDA*
        if(posicoes[4][3] == 'p' || posicoes[4][3] == 's'){
            if(posicoes[4][4] == 'v')
                return;
        }
        if(posicoes[4][1] == 'p' || posicoes[4][1] == 's'){
            if(posicoes[4][0] == 'v')
                return;
        }
        if(posicoes[5][2] == 'p' || posicoes[5][2] == 's'){
            if(posicoes[6][2] == 'v')
                return;
        }
        if(posicoes[3][2] == 'p' || posicoes[3][2] == 's'){
            if(posicoes[2][2] == 'v')
                return;
        }
    }
    if(posicoes[4][1] == 'p' || posicoes[4][1] == 's'){//E2: CIMA, ESQUERDA
        if(posicoes[4][2] == 'p' || posicoes[4][2] == 's'){
            if(posicoes[4][3] == 'v')
                return;
        }
        if(posicoes[3][1] == 'p' || posicoes[3][1] == 's'){
            if(posicoes[2][1] == 'v')
                return;
        }
    }
    if(posicoes[4][0] == 'p' || posicoes[4][0] == 's'){//E1: CIMA, ESQUERDA
        if(posicoes[4][1] == 'p' || posicoes[4][1] == 's'){
            if(posicoes[4][2] == 'v')
                return;
        }
        if(posicoes[3][0] == 'p' || posicoes[3][0] == 's'){
            if(posicoes[2][0] == 'v')
                return;
        }
    }
    if(posicoes[5][4] == 'p' || posicoes[5][4] == 's'){//F5: BAIXO, ESQUERDA
        if(posicoes[5][3] == 'p' || posicoes[5][3] == 's'){
            if(posicoes[5][2] == 'v')
                return;
        }
        if(posicoes[4][4] == 'p' || posicoes[4][4] == 's'){
            if(posicoes[3][4] == 'v')
                return;
        }
    }
    if(posicoes[5][3] == 'p' || posicoes[5][3] == 's'){//F4: ESQUERDA
        if(posicoes[4][3] == 'p' || posicoes[4][3] == 's'){
            if(posicoes[3][3] == 'v')
                return;
        }
    }
    if(posicoes[5][2] == 'p' || posicoes[5][2] == 's'){//F3: CIMA, ESQUERDA
        if(posicoes[5][3] == 'p' || posicoes[5][3] == 's'){
            if(posicoes[5][4] == 'v')
                return;
        }
        if(posicoes[4][2] == 'p' || posicoes[4][2] == 's'){
            if(posicoes[3][2] == 'v')
                return;
        }
    }
    if(posicoes[6][4] == 'p' || posicoes[6][4] == 's'){//G5: BAIXO, ESQUERDA
        if(posicoes[6][3] == 'p' || posicoes[6][3] == 's'){
            if(posicoes[6][2] == 'v')
                return;
        }
        if(posicoes[5][4] == 'p' || posicoes[5][4] == 's'){
            if(posicoes[4][4] == 'v')
                return;
        }
    }
    if(posicoes[6][3] == 'p' || posicoes[6][3] == 's'){//G4: ESQUERDA
        if(posicoes[5][3] == 'p' || posicoes[5][3] == 's'){
            if(posicoes[4][3] == 'v')
                return;
        }
    }
    if(posicoes[6][2] == 'p' || posicoes[6][2] == 's'){//G3: CIMA, ESQUERDA
        if(posicoes[6][3] == 'p' || posicoes[6][3] == 's'){
            if(posicoes[6][4] == 'v')
                return;
        }
        if(posicoes[5][2] == 'p' || posicoes[5][2] == 's'){
            if(posicoes[4][2] == 'v')
                return;
        }
    }
    flag = 1;// SE CHEGOU AQUI É PORQUE NÃO É POSSÍVEL MAIS NENHUMA JOGADA

    //ACABOU O JOGO
    int i,j,qtd = 0;
    for(i = 0; i < 7; i ++){
        for(j = 0; j < 7; j ++){
            if(posicoes[i][j] == 'p' || posicoes[i][j] == 's'){
                qtd++;//CONTANDO O NUMERO DE PEÇAS NO TABULEIRO
            }
        }
    }
    if(qtd == 1){//VENCEU O JOGO, SÓ TEM UMA PEÇA NO TABULEIRO
        strcpy(texto, "VOCE VENCEU!!");
    }
    else if(qtd > 1){//PERDEU, TEM MAIS DE UMA PEÇA NO TABULEIRO
        strcpy(texto, "VOCE PERDEU");
    }
}

static void Atualiza_tamanho(int Janela_width, int Janela_height)
{
    glViewport(0,0,Janela_width,Janela_height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    //60 = angulo de abertura do campo de visão da câmera
    //1 = aspecto, esticado, largo, normal (1 é normal)
    //1 = near, 10 = far
    gluPerspective(60.0,1.0,1.0,100.0);

    gluLookAt(11.0,-3.0,11.0,// onde a câmera esta
              6.0,6.0,-1.0,  // pra onde ela olha
              -0.5,1.0,0.0); // onde é o pra cima dela
}

static void Atualiza_desenho(void)
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();//inicializa matriz com a matriz identidade
    glClear(GL_COLOR_BUFFER_BIT);//Limpa janela

    game_over();

    glColor4ub(127,0,0,0.5);
    //TABULEIRO
    glPushMatrix();
        glTranslated(3 * TAM, 3 * TAM, -1);
        glScalef(3.5 * TAM,1.5 * TAM,1);
        glutSolidCube(2);
    glPopMatrix();
    glPushMatrix();
        glTranslated(3 * TAM, 3 * TAM, -1);
        glScalef(1.5 * TAM,3.5 * TAM,1);
        glutSolidCube(2);
    glPopMatrix();

    divisas();//desenha as divisas do tabuleiro

    int i,j;
    for(i=0;i<7;i++){
        for(j=0;j<7;j++){
            desenha_pecas(i, j);
        }
    }

    DesenhaTexto(texto);
    glFlush();
}

void Inicializa (void)
{
    glShadeModel (GL_SMOOTH);
    strcpy(texto, /*"(0,0)*/" ");
}
//MAPEAMENTO E LÓGICA DO JOGO
void MoveMouseBotaoPressionado(int x, int y)
{
    if(     x > 154 && x < 185 && y > 171 && y < 202){//A5
        if(posicoes[0][4] == 's'){//TIRAR SELEÇÃO DA PEÇA CLICANDO NA MESMA
            posicoes[0][4] = 'p';
            sx = -1;
            sy = -1;
        }
        else if (posicoes[0][4] == 'p'){//SELECIONAR PEÇA
            scx = 'A';
            scy = '5';
            posicoes[0][4] = 's';
            sx = 0;
            sy = 4;
        }
        else if (posicoes[0][4] == 'v' && sx != -1 && sy != -1){//ALGUMA PEÇA TA SELECIONADA E VAI COMER OUTRA PEÇA E ACABAR NESSA POSIÇÃO
            if(sx == 0 && sy == 2 && posicoes[0][3] == 'p'){//BAIXO
                posicoes[0][2] = 'v';//ORIGEM
                posicoes[0][3] = 'v';//POSIÇÃO DA PEÇA COMIDA
                posicoes[0][4] = 'p';//DESTINO
                sx = -1;
                sy = -1;
            }
            else if(sx == 2 && sy == 4 && posicoes[1][4] == 'p'){//DIREITA
                posicoes[2][4] = 'v';//ORIGEM
                posicoes[1][4] = 'v';//POSIÇÃO DA PEÇA COMIDA
                posicoes[0][4] = 'p';//DESTINO
                sx = -1;
                sy = -1;
            }
        }
     }
    else if(x > 115 && x < 151 && y > 204 && y < 238){//A4
        if(posicoes[0][3] == 's'){
            posicoes[0][3] = 'p';
            sx = -1;
            sy = -1;
        }
        else if (posicoes[0][3] == 'p'){
            scx = 'A';
            scy = '4';
            posicoes[0][3] = 's';
            sx = 0;
            sy = 3;
        }
        else if (posicoes[0][3] == 'v' && sx != -1 && sy != -1){
            if(sx == 2 && sy == 3 && posicoes[1][3] == 'p'){//DIREITA
                posicoes[2][3] = 'v';//ORIGEM
                posicoes[1][3] = 'v';//POSIÇÃO DA PEÇA COMIDA
                posicoes[0][3] = 'p';//DESTINO
                sx = -1;
                sy = -1;
            }
        }
     }
    else if(x >  73 && x < 112 && y > 243 && y < 279){//A3
        if(posicoes[0][2] == 's'){
            posicoes[0][2] = 'p';
            sx = -1;
            sy = -1;
        }
        else if (posicoes[0][2] == 'p'){
            scx = 'A';
            scy = '3';
            posicoes[0][2] = 's';
            sx = 0;
            sy = 2;
        }
        else if (posicoes[0][2] == 'v' && sx != -1 && sy != -1){
            if(sx == 0 && sy == 4 && posicoes[0][3] == 'p'){//CIMA
                posicoes[0][4] = 'v';//ORIGEM
                posicoes[0][3] = 'v';//POSIÇÃO DA PEÇA COMIDA
                posicoes[0][2] = 'p';//DESTINO
                sx = -1;
                sy = -1;
            }
            else if(sx == 2 && sy == 2 && posicoes[1][2] == 'p'){//DIREITA
                posicoes[2][2] = 'v';//ORIGEM
                posicoes[1][2] = 'v';//POSIÇÃO DA PEÇA COMIDA
                posicoes[0][2] = 'p';//DESTINO
                sx = -1;
                sy = -1;
            }
        }
     }
    else if(x > 202 && x < 235 && y > 185 && y < 218){//B5
        if(posicoes[1][4] == 's'){
            posicoes[1][4] = 'p';
            sx = -1;
            sy = -1;
        }
        else if (posicoes[1][4] == 'p'){
            scx = 'B';
            scy = '5';
            posicoes[1][4] = 's';
            sx = 1;
            sy = 4;
        }
        else if (posicoes[1][4] == 'v' && sx != -1 && sy != -1){
            if(sx == 1 && sy == 2 && posicoes[1][3] == 'p'){//BAIXO
                posicoes[1][2] = 'v';//ORIGEM
                posicoes[1][3] = 'v';//POSIÇÃO DA PEÇA COMIDA
                posicoes[1][4] = 'p';//DESTINO
                sx = -1;
                sy = -1;
            }
            else if(sx == 3 && sy == 4 && posicoes[2][4] == 'p'){//DIREITA
                posicoes[3][4] = 'v';//ORIGEM
                posicoes[2][4] = 'v';//POSIÇÃO DA PEÇA COMIDA
                posicoes[1][4] = 'p';//DESTINO
                sx = -1;
                sy = -1;
            }
        }
     }
    else if(x > 167 && x < 202 && y > 220 && y < 256){//B4
        if(posicoes[1][3] == 's'){
            posicoes[1][3] = 'p';
            sx = -1;
            sy = -1;
        }
        else if (posicoes[1][3] == 'p'){
            scx = 'B';
            scy = '4';
            posicoes[1][3] = 's';
            sx = 1;
            sy = 3;
        }
        else if (posicoes[1][3] == 'v' && sx != -1 && sy != -1){
            if(sx == 3 && sy == 3 && posicoes[2][3] == 'p'){//DIREITA
                posicoes[3][3] = 'v';//ORIGEM
                posicoes[2][3] = 'v';//POSIÇÃO DA PEÇA COMIDA
                posicoes[1][3] = 'p';//DESTINO
                sx = -1;
                sy = -1;
            }
        }
     }
    else if(x > 126 && x < 164 && y > 262 && y < 300){//B3
        if(posicoes[1][2] == 's'){
            posicoes[1][2] = 'p';
            sx = -1;
            sy = -1;
        }
        else if (posicoes[1][2] == 'p'){
            scx = 'B';
            scy = '3';
            posicoes[1][2] = 's';
            sx = 1;
            sy = 2;
        }
        else if (posicoes[1][2] == 'v' && sx != -1 && sy != -1){
            if(sx == 1 && sy == 4 && posicoes[1][3] == 'p'){//CIMA
                posicoes[1][4] = 'v';//ORIGEM
                posicoes[1][3] = 'v';//POSIÇÃO DA PEÇA COMIDA
                posicoes[1][2] = 'p';//DESTINO
                sx = -1;
                sy = -1;
            }
            else if(sx == 3 && sy == 2 && posicoes[2][2] == 'p'){//DIREITA
                posicoes[3][2] = 'v';//ORIGEM
                posicoes[2][2] = 'v';//POSIÇÃO DA PEÇA COMIDA
                posicoes[1][2] = 'p';//DESTINO
                sx = -1;
                sy = -1;
            }
        }
     }
    else if(x > 308 && x < 338 && y > 135 && y < 167){//C7
        if(posicoes[2][6] == 's'){
            posicoes[2][6] = 'p';
            sx = -1;
            sy = -1;
        }
        else if (posicoes[2][6] == 'p'){
            scx = 'C';
            scy = '7';
            posicoes[2][6] = 's';
            sx = 2;
            sy = 6;
        }
        else if (posicoes[2][6] == 'v' && sx != -1 && sy != -1){
            if(sx == 2 && sy == 4 && posicoes[2][5] == 'p'){//BAIXO
                posicoes[2][4] = 'v';//ORIGEM
                posicoes[2][5] = 'v';//POSIÇÃO DA PEÇA COMIDA
                posicoes[2][6] = 'p';//DESTINO
                sx = -1;
                sy = -1;
            }
            else if(sx == 4 && sy == 6 && posicoes[3][6] == 'p'){//DIREITA
                posicoes[4][6] = 'v';//ORIGEM
                posicoes[3][6] = 'v';//POSIÇÃO DA PEÇA COMIDA
                posicoes[2][6] = 'p';//DESTINO
                sx = -1;
                sy = -1;
            }
        }
     }
    else if(x > 283 && x < 314 && y > 166 && y < 199){//C6
        if(posicoes[2][5] == 's'){
            posicoes[2][5] = 'p';
            sx = -1;
            sy = -1;
        }
        else if (posicoes[2][5] == 'p'){
            scx = 'C';
            scy = '6';
            posicoes[2][5] = 's';
            sx = 2;
            sy = 5;
        }
        else if (posicoes[2][5] == 'v' && sx != -1 && sy != -1){
            if(sx == 2 && sy == 3 && posicoes[2][4] == 'p'){//BAIXO
                posicoes[2][3] = 'v';//ORIGEM
                posicoes[2][4] = 'v';//POSIÇÃO DA PEÇA COMIDA
                posicoes[2][5] = 'p';//DESTINO
                sx = -1;
                sy = -1;
            }
            else if(sx == 4 && sy == 5 && posicoes[3][5] == 'p'){//DIREITA
                posicoes[4][5] = 'v';//ORIGEM
                posicoes[3][5] = 'v';//POSIÇÃO DA PEÇA COMIDA
                posicoes[2][5] = 'p';//DESTINO
                sx = -1;
                sy = -1;
            }
        }
     }
    else if(x > 253 && x < 288 && y > 201 && y < 233){//C5
        if(posicoes[2][4] == 's'){
            posicoes[2][4] = 'p';
            sx = -1;
            sy = -1;
        }
        else if (posicoes[2][4] == 'p'){
            scx = 'C';
            scy = '5';
            posicoes[2][4] = 's';
            sx = 2;
            sy = 4;
        }
        else if (posicoes[2][4] == 'v' && sx != -1 && sy != -1){
            if(sx == 2 && sy == 6 && posicoes[2][5] == 'p'){//CIMA
                posicoes[2][6] = 'v';//ORIGEM
                posicoes[2][5] = 'v';//POSIÇÃO DA PEÇA COMIDA
                posicoes[2][4] = 'p';//DESTINO
                sx = -1;
                sy = -1;
            }
            else if(sx == 2 && sy == 2 && posicoes[2][3] == 'p'){//BAIXO
                posicoes[2][2] = 'v';//ORIGEM
                posicoes[2][3] = 'v';//POSIÇÃO DA PEÇA COMIDA
                posicoes[2][4] = 'p';//DESTINO
                sx = -1;
                sy = -1;
            }
            else if(sx == 4 && sy == 4 && posicoes[3][4] == 'p'){//DIREITA
                posicoes[4][4] = 'v';//ORIGEM
                posicoes[3][4] = 'v';//POSIÇÃO DA PEÇA COMIDA
                posicoes[2][4] = 'p';//DESTINO
                sx = -1;
                sy = -1;
            }
            else if(sx == 0 && sy == 4 && posicoes[1][4] == 'p'){//ESQUERDA
                posicoes[0][4] = 'v';//ORIGEM
                posicoes[1][4] = 'v';//POSIÇÃO DA PEÇA COMIDA
                posicoes[2][4] = 'p';//DESTINO
                sx = -1;
                sy = -1;
            }
        }
     }
    else if(x > 221 && x < 256 && y > 239 && y < 275){//C4
        if(posicoes[2][3] == 's'){
            posicoes[2][3] = 'p';
            sx = -1;
            sy = -1;
        }
        else if (posicoes[2][3] == 'p'){
            scx = 'C';
            scy = '4';
            posicoes[2][3] = 's';
            sx = 2;
            sy = 3;
        }
        else if (posicoes[2][3] == 'v' && sx != -1 && sy != -1){
            if(sx == 2 && sy == 5 && posicoes[2][4] == 'p'){//CIMA
                posicoes[2][5] = 'v';//ORIGEM
                posicoes[2][4] = 'v';//POSIÇÃO DA PEÇA COMIDA
                posicoes[2][3] = 'p';//DESTINO
                sx = -1;
                sy = -1;
            }
            else if(sx == 2 && sy == 1 && posicoes[2][2] == 'p'){//BAIXO
                posicoes[2][1] = 'v';//ORIGEM
                posicoes[2][2] = 'v';//POSIÇÃO DA PEÇA COMIDA
                posicoes[2][3] = 'p';//DESTINO
                sx = -1;
                sy = -1;
            }
            else if(sx == 4 && sy == 3 && posicoes[3][3] == 'p'){//DIREITA
                posicoes[4][3] = 'v';//ORIGEM
                posicoes[3][3] = 'v';//POSIÇÃO DA PEÇA COMIDA
                posicoes[2][3] = 'p';//DESTINO
                sx = -1;
                sy = -1;
            }
            else if(sx == 0 && sy == 3 && posicoes[1][3] == 'p'){//ESQUERDA
                posicoes[0][3] = 'v';//ORIGEM
                posicoes[1][3] = 'v';//POSIÇÃO DA PEÇA COMIDA
                posicoes[2][3] = 'p';//DESTINO
                sx = -1;
                sy = -1;
            }
        }
     }
    else if(x > 183 && x < 222 && y > 284 && y < 322){//C3
        if(posicoes[2][2] == 's'){
            posicoes[2][2] = 'p';
            sx = -1;
            sy = -1;
        }
        else if (posicoes[2][2] == 'p'){
            scx = 'C';
            scy = '3';
            posicoes[2][2] = 's';
            sx = 2;
            sy = 2;
        }
        else if (posicoes[2][2] == 'v' && sx != -1 && sy != -1){
            if(sx == 2 && sy == 4 && posicoes[2][3] == 'p'){//CIMA
                posicoes[2][4] = 'v';//ORIGEM
                posicoes[2][3] = 'v';//POSIÇÃO DA PEÇA COMIDA
                posicoes[2][2] = 'p';//DESTINO
                sx = -1;
                sy = -1;
            }
            else if(sx == 2 && sy == 0 && posicoes[2][1] == 'p'){//BAIXO
                posicoes[2][0] = 'v';//ORIGEM
                posicoes[2][1] = 'v';//POSIÇÃO DA PEÇA COMIDA
                posicoes[2][2] = 'p';//DESTINO
                sx = -1;
                sy = -1;
            }
            else if(sx == 4 && sy == 2 && posicoes[3][2] == 'p'){//DIREITA
                posicoes[4][2] = 'v';//ORIGEM
                posicoes[3][2] = 'v';//POSIÇÃO DA PEÇA COMIDA
                posicoes[2][2] = 'p';//DESTINO
                sx = -1;
                sy = -1;
            }
            else if(sx == 0 && sy == 2 && posicoes[1][2] == 'p'){//ESQUERDA
                posicoes[0][2] = 'v';//ORIGEM
                posicoes[1][2] = 'v';//POSIÇÃO DA PEÇA COMIDA
                posicoes[2][2] = 'p';//DESTINO
                sx = -1;
                sy = -1;
            }
        }
     }
    else if(x > 137 && x < 181 && y > 335 && y < 377){//C2
        if(posicoes[2][1] == 's'){
            posicoes[2][1] = 'p';
            sx = -1;
            sy = -1;
        }
        else if (posicoes[2][1] == 'p'){
            scx = 'C';
            scy = '2';
            posicoes[2][1] = 's';
            sx = 2;
            sy = 1;
        }
        else if (posicoes[2][1] == 'v' && sx != -1 && sy != -1){
            if(sx == 2 && sy == 3 && posicoes[2][2] == 'p'){//CIMA
                posicoes[2][3] = 'v';//ORIGEM
                posicoes[2][2] = 'v';//POSIÇÃO DA PEÇA COMIDA
                posicoes[2][1] = 'p';//DESTINO
                sx = -1;
                sy = -1;
            }
            else if(sx == 4 && sy == 1 && posicoes[3][1] == 'p'){//DIREITA
                posicoes[4][1] = 'v';//ORIGEM
                posicoes[3][1] = 'v';//POSIÇÃO DA PEÇA COMIDA
                posicoes[2][1] = 'p';//DESTINO
                sx = -1;
                sy = -1;
            }
        }
     }
    else if(x >  83 && x < 132 && y > 397 && y < 444){//C1
        if(posicoes[2][0] == 's'){
            posicoes[2][0] = 'p';
            sx = -1;
            sy = -1;
        }
        else if (posicoes[2][0] == 'p'){
            scx = 'C';
            scy = '1';
            posicoes[2][0] = 's';
            sx = 2;
            sy = 0;
        }
        else if (posicoes[2][0] == 'v' && sx != -1 && sy != -1){
            if(sx == 2 && sy == 2 && posicoes[2][1] == 'p'){//CIMA
                posicoes[2][2] = 'v';//ORIGEM
                posicoes[2][1] = 'v';//POSIÇÃO DA PEÇA COMIDA
                posicoes[2][0] = 'p';//DESTINO
                sx = -1;
                sy = -1;
            }
            else if(sx == 4 && sy == 0 && posicoes[3][0] == 'p'){//DIREITA
                posicoes[4][0] = 'v';//ORIGEM
                posicoes[3][0] = 'v';//POSIÇÃO DA PEÇA COMIDA
                posicoes[2][0] = 'p';//DESTINO
                sx = -1;
                sy = -1;
            }
        }
     }
    else if(x > 358 && x < 390 && y > 148 && y < 180){//D7
        if(posicoes[3][6] == 's'){
            posicoes[3][6] = 'p';
            sx = -1;
            sy = -1;
        }
        else if (posicoes[3][6] == 'p'){
            scx = 'D';
            scy = '7';
            posicoes[3][6] = 's';
            sx = 3;
            sy = 6;
        }
        else if (posicoes[3][6] == 'v' && sx != -1 && sy != -1){
            if(sx == 3 && sy == 4 && posicoes[3][5] == 'p'){//BAIXO
                posicoes[3][4] = 'v';//ORIGEM
                posicoes[3][5] = 'v';//POSIÇÃO DA PEÇA COMIDA
                posicoes[3][6] = 'p';//DESTINO
                sx = -1;
                sy = -1;
            }
        }
     }
    else if(x > 336 && x < 368 && y > 181 && y < 214){//D6
        if(posicoes[3][5] == 's'){
            posicoes[3][5] = 'p';
            sx = -1;
            sy = -1;
        }
        else if (posicoes[3][5] == 'p'){
            scx = 'D';
            scy = '6';
            posicoes[3][5] = 's';
            sx = 3;
            sy = 5;
        }
        else if (posicoes[3][5] == 'v' && sx != -1 && sy != -1){
            if(sx == 3 && sy == 3 && posicoes[3][4] == 'p'){//BAIXO
                posicoes[3][3] = 'v';//ORIGEM
                posicoes[3][4] = 'v';//POSIÇÃO DA PEÇA COMIDA
                posicoes[3][5] = 'p';//DESTINO
                sx = -1;
                sy = -1;
            }
        }
     }
    else if(x > 309 && x < 345 && y > 216 && y < 252){//D5
        if(posicoes[3][4] == 's'){
            posicoes[3][4] = 'p';
            sx = -1;
            sy = -1;
        }
        else if (posicoes[3][4] == 'p'){
            scx = 'D';
            scy = '5';
            posicoes[3][4] = 's';
            sx = 3;
            sy = 4;
        }
        else if (posicoes[3][4] == 'v' && sx != -1 && sy != -1){
            if(sx == 3 && sy == 6 && posicoes[3][5] == 'p'){//CIMA
                posicoes[3][6] = 'v';//ORIGEM
                posicoes[3][5] = 'v';//POSIÇÃO DA PEÇA COMIDA
                posicoes[3][4] = 'p';//DESTINO
                sx = -1;
                sy = -1;
            }
            else if(sx == 3 && sy == 2 && posicoes[3][3] == 'p'){//BAIXO
                posicoes[3][2] = 'v';//ORIGEM
                posicoes[3][3] = 'v';//POSIÇÃO DA PEÇA COMIDA
                posicoes[3][4] = 'p';//DESTINO
                sx = -1;
                sy = -1;
            }
            else if(sx == 5 && sy == 4 && posicoes[4][4] == 'p'){//DIREITA
                posicoes[5][4] = 'v';//ORIGEM
                posicoes[4][4] = 'v';//POSIÇÃO DA PEÇA COMIDA
                posicoes[3][4] = 'p';//DESTINO
                sx = -1;
                sy = -1;
            }
            else if(sx == 1 && sy == 4 && posicoes[2][4] == 'p'){//ESQUERDA
                posicoes[1][4] = 'v';//ORIGEM
                posicoes[2][4] = 'v';//POSIÇÃO DA PEÇA COMIDA
                posicoes[3][4] = 'p';//DESTINO
                sx = -1;
                sy = -1;
            }
        }
     }
    else if(x > 280 && x < 317 && y > 258 && y < 296){//D4
        if (posicoes[3][3] == 's'){
            posicoes[3][3] = 'p';
            sx = -1;
            sy = -1;
        }
        else if (posicoes[3][3] == 'p'){
            scx = 'D';
            scy = '4';
            posicoes[3][3] = 's';
            sx = 3;
            sy = 3;
        }
        else if (posicoes[3][3] == 'v' && sx != -1 && sy != -1){//SE TEM ALGUEM SELECIONADO E ESTÃO CLICANDO EM UMA POSIÇÃO VAZIA
            if(sx == 3 && sy == 5 && posicoes[3][4] == 'p'){//A PEÇA QUE VAI COMER TA VINDO DE CIMA
                posicoes[3][5] = 'v';//ORIGEM FICA VAZIA
                posicoes[3][4] = 'v';//POSIÇÃO DA PEÇA COMIDA FICA VAZIA
                posicoes[3][3] = 'p';//DESTINO FICA PREENCHIDO COM A PEÇA QUE COMEU
                sx = -1;
                sy = -1;
            }
            else if(sx == 3 && sy == 1 && posicoes[3][2] == 'p'){//A PEÇA QUE VAI COMER TA VINDO DE BAIXO
                posicoes[3][1] = 'v';
                posicoes[3][2] = 'v';
                posicoes[3][3] = 'p';
                sx = -1;
                sy = -1;
            }
            else if(sx == 5 && sy == 3 && posicoes[4][3] == 'p'){//A PEÇA QUE VAI COMER TA VINDO DA DIREITA
                posicoes[5][3] = 'v';
                posicoes[4][3] = 'v';
                posicoes[3][3] = 'p';
                sx = -1;
                sy = -1;
            }
            else if(sx == 1 && sy == 3 && posicoes[2][3] == 'p'){//A PEÇA QUE VAI COMER TA VINDO DA ESQUERDA
                posicoes[1][3] = 'v';
                posicoes[2][3] = 'v';
                posicoes[3][3] = 'p';
                sx = -1;
                sy = -1;
            }
        }
     }
    else if(x > 245 && x < 285 && y > 306 && y < 347){//D3
        if(posicoes[3][2] == 's'){
            posicoes[3][2] = 'p';
            sx = -1;
            sy = -1;
        }
        else if (posicoes[3][2] == 'p'){
            scx = 'D';
            scy = '3';
            posicoes[3][2] = 's';
            sx = 3;
            sy = 2;
        }
        else if (posicoes[3][2] == 'v' && sx != -1 && sy != -1){
            if(sx == 3 && sy == 4 && posicoes[3][3] == 'p'){//CIMA
                posicoes[3][4] = 'v';//ORIGEM
                posicoes[3][3] = 'v';//POSIÇÃO DA PEÇA COMIDA
                posicoes[3][2] = 'p';//DESTINO
                sx = -1;
                sy = -1;
            }
            else if(sx == 3 && sy == 0 && posicoes[3][1] == 'p'){//BAIXO
                posicoes[3][0] = 'v';//ORIGEM
                posicoes[3][1] = 'v';//POSIÇÃO DA PEÇA COMIDA
                posicoes[3][2] = 'p';//DESTINO
                sx = -1;
                sy = -1;
            }
            else if(sx == 5 && sy == 2 && posicoes[4][2] == 'p'){//DIREITA
                posicoes[5][2] = 'v';//ORIGEM
                posicoes[4][2] = 'v';//POSIÇÃO DA PEÇA COMIDA
                posicoes[3][2] = 'p';//DESTINO
                sx = -1;
                sy = -1;
            }
            else if(sx == 1 && sy == 2 && posicoes[2][2] == 'p'){//ESQUERDA
                posicoes[1][2] = 'v';//ORIGEM
                posicoes[2][2] = 'v';//POSIÇÃO DA PEÇA COMIDA
                posicoes[3][2] = 'p';//DESTINO
                sx = -1;
                sy = -1;
            }
        }
     }
    else if(x > 203 && x < 247 && y > 362 && y < 407){//D2
        if(posicoes[3][1] == 's'){
            posicoes[3][1] = 'p';
            sx = -1;
            sy = -1;
        }
        else if (posicoes[3][1] == 'p'){
            scx = 'D';
            scy = '2';
            posicoes[3][1] = 's';
            sx = 3;
            sy = 1;
        }
        else if (posicoes[3][1] == 'v' && sx != -1 && sy != -1){
            if(sx == 3 && sy == 3 && posicoes[3][2] == 'p'){//CIMA
                posicoes[3][3] = 'v';//ORIGEM
                posicoes[3][2] = 'v';//POSIÇÃO DA PEÇA COMIDA
                posicoes[3][1] = 'p';//DESTINO
                sx = -1;
                sy = -1;
            }
        }
     }
    else if(x > 153 && x < 203 && y > 430 && y < 480){//D1
        if(posicoes[3][0] == 's'){
            posicoes[3][0] = 'p';
            sx = -1;
            sy = -1;
        }
        else if (posicoes[3][0] == 'p'){
            scx = 'D';
            scy = '1';
            posicoes[3][0] = 's';
            sx = 3;
            sy = 0;
        }
        else if (posicoes[3][0] == 'v' && sx != -1 && sy != -1){
            if(sx == 3 && sy == 2 && posicoes[3][1] == 'p'){//CIMA
                posicoes[3][2] = 'v';//ORIGEM
                posicoes[3][1] = 'v';//POSIÇÃO DA PEÇA COMIDA
                posicoes[3][0] = 'p';//DESTINO
                sx = -1;
                sy = -1;
            }
        }
     }
    else if(x > 412 && x < 445 && y > 161 && y < 195){//E7
        if(posicoes[4][6] == 's'){
            posicoes[4][6] = 'p';
            sx = -1;
            sy = -1;
        }
        else if (posicoes[4][6] == 'p'){
            scx = 'E';
            scy = '7';
            posicoes[4][6] = 's';
            sx = 4;
            sy = 6;
        }
        else if (posicoes[4][6] == 'v' && sx != -1 && sy != -1){
            if(sx == 4 && sy == 4 && posicoes[4][5] == 'p'){//BAIXO
                posicoes[4][4] = 'v';//ORIGEM
                posicoes[4][5] = 'v';//POSIÇÃO DA PEÇA COMIDA
                posicoes[4][6] = 'p';//DESTINO
                sx = -1;
                sy = -1;
            }
            else if(sx == 2 && sy == 6 && posicoes[3][6] == 'p'){//ESQUERDA
                posicoes[2][6] = 'v';//ORIGEM
                posicoes[3][6] = 'v';//POSIÇÃO DA PEÇA COMIDA
                posicoes[4][6] = 'p';//DESTINO
                sx = -1;
                sy = -1;
            }
        }
     }
    else if(x > 393 && x < 427 && y > 196 && y < 230){//E6
        if(posicoes[4][5] == 's'){
            posicoes[4][5] = 'p';
            sx = -1;
            sy = -1;
        }
        else if (posicoes[4][5] == 'p'){
            scx = 'E';
            scy = '6';
            posicoes[4][5] = 's';
            sx = 4;
            sy = 5;
        }
        else if (posicoes[4][5] == 'v' && sx != -1 && sy != -1){
            if(sx == 4 && sy == 3 && posicoes[4][4] == 'p'){//BAIXO
                posicoes[4][3] = 'v';//ORIGEM
                posicoes[4][4] = 'v';//POSIÇÃO DA PEÇA COMIDA
                posicoes[4][5] = 'p';//DESTINO
                sx = -1;
                sy = -1;
            }
            else if(sx == 2 && sy == 5 && posicoes[3][5] == 'p'){//ESQUERDA
                posicoes[2][5] = 'v';//ORIGEM
                posicoes[3][5] = 'v';//POSIÇÃO DA PEÇA COMIDA
                posicoes[4][5] = 'p';//DESTINO
                sx = -1;
                sy = -1;
            }
        }
     }
    else if(x > 370 && x < 406 && y > 235 && y < 270){//E5
        if(posicoes[4][4] == 's'){
            posicoes[4][4] = 'p';
            sx = -1;
            sy = -1;
        }
        else if (posicoes[4][4] == 'p'){
            scx = 'E';
            scy = '5';
            posicoes[4][4] = 's';
            sx = 4;
            sy = 4;
        }
        else if (posicoes[4][4] == 'v' && sx != -1 && sy != -1){
            if(sx == 4 && sy == 6 && posicoes[4][5] == 'p'){//CIMA
                posicoes[4][6] = 'v';//ORIGEM
                posicoes[4][5] = 'v';//POSIÇÃO DA PEÇA COMIDA
                posicoes[4][4] = 'p';//DESTINO
                sx = -1;
                sy = -1;
            }
            else if(sx == 4 && sy == 2 && posicoes[4][3] == 'p'){//BAIXO
                posicoes[4][2] = 'v';//ORIGEM
                posicoes[4][3] = 'v';//POSIÇÃO DA PEÇA COMIDA
                posicoes[4][4] = 'p';//DESTINO
                sx = -1;
                sy = -1;
            }
            else if(sx == 6 && sy == 4 && posicoes[5][4] == 'p'){//DIREITA
                posicoes[6][4] = 'v';//ORIGEM
                posicoes[5][4] = 'v';//POSIÇÃO DA PEÇA COMIDA
                posicoes[4][4] = 'p';//DESTINO
                sx = -1;
                sy = -1;
            }
            else if(sx == 2 && sy == 4 && posicoes[3][4] == 'p'){//ESQUERDA
                posicoes[2][4] = 'v';//ORIGEM
                posicoes[3][4] = 'v';//POSIÇÃO DA PEÇA COMIDA
                posicoes[4][4] = 'p';//DESTINO
                sx = -1;
                sy = -1;
            }
        }
     }
    else if(x > 343 && x < 382 && y > 280 && y < 319){//E4
        if(posicoes[4][3] == 's'){
            posicoes[4][3] = 'p';
            sx = -1;
            sy = -1;
        }
        else if (posicoes[4][3] == 'p'){
            scx = 'E';
            scy = '4';
            posicoes[4][3] = 's';
            sx = 4;
            sy = 3;
        }
        else if (posicoes[4][3] == 'v' && sx != -1 && sy != -1){
            if(sx == 4 && sy == 5 && posicoes[4][4] == 'p'){//CIMA
                posicoes[4][5] = 'v';//ORIGEM
                posicoes[4][4] = 'v';//POSIÇÃO DA PEÇA COMIDA
                posicoes[4][3] = 'p';//DESTINO
                sx = -1;
                sy = -1;
            }
            else if(sx == 4 && sy == 1 && posicoes[4][2] == 'p'){//BAIXO
                posicoes[4][1] = 'v';//ORIGEM
                posicoes[4][2] = 'v';//POSIÇÃO DA PEÇA COMIDA
                posicoes[4][3] = 'p';//DESTINO
                sx = -1;
                sy = -1;
            }
            else if(sx == 6 && sy == 3 && posicoes[5][3] == 'p'){//DIREITA
                posicoes[6][3] = 'v';//ORIGEM
                posicoes[5][3] = 'v';//POSIÇÃO DA PEÇA COMIDA
                posicoes[4][3] = 'p';//DESTINO
                sx = -1;
                sy = -1;
            }
            else if(sx == 2 && sy == 3 && posicoes[3][3] == 'p'){//ESQUERDA
                posicoes[2][3] = 'v';//ORIGEM
                posicoes[3][3] = 'v';//POSIÇÃO DA PEÇA COMIDA
                posicoes[4][3] = 'p';//DESTINO
                sx = -1;
                sy = -1;
            }
        }
     }
    else if(x > 312 && x < 354 && y > 332 && y < 374){//E3
        if(posicoes[4][2] == 's'){
            posicoes[4][2] = 'p';
            sx = -1;
            sy = -1;
        }
        else if (posicoes[4][2] == 'p'){
            scx = 'E';
            scy = '3';
            posicoes[4][2] = 's';
            sx = 4;
            sy = 2;
        }
        else if (posicoes[4][2] == 'v' && sx != -1 && sy != -1){
            if(sx == 4 && sy == 4 && posicoes[4][3] == 'p'){//CIMA
                posicoes[4][4] = 'v';//ORIGEM
                posicoes[4][3] = 'v';//POSIÇÃO DA PEÇA COMIDA
                posicoes[4][2] = 'p';//DESTINO
                sx = -1;
                sy = -1;
            }
            else if(sx == 4 && sy == 0 && posicoes[4][1] == 'p'){//BAIXO
                posicoes[4][0] = 'v';//ORIGEM
                posicoes[4][1] = 'v';//POSIÇÃO DA PEÇA COMIDA
                posicoes[4][2] = 'p';//DESTINO
                sx = -1;
                sy = -1;
            }
            else if(sx == 6 && sy == 2 && posicoes[5][2] == 'p'){//DIREITA
                posicoes[6][2] = 'v';//ORIGEM
                posicoes[5][2] = 'v';//POSIÇÃO DA PEÇA COMIDA
                posicoes[4][2] = 'p';//DESTINO
                sx = -1;
                sy = -1;
            }
            else if(sx == 2 && sy == 2 && posicoes[3][2] == 'p'){//ESQUERDA
                posicoes[2][2] = 'v';//ORIGEM
                posicoes[3][2] = 'v';//POSIÇÃO DA PEÇA COMIDA
                posicoes[4][2] = 'p';//DESTINO
                sx = -1;
                sy = -1;
            }
        }
     }
    else if(x > 276 && x < 321 && y > 393 && y < 440){//E2
        if(posicoes[4][1] == 's'){
            posicoes[4][1] = 'p';
            sx = -1;
            sy = -1;
        }
        else if (posicoes[4][1] == 'p'){
            scx = 'E';
            scy = '2';
            posicoes[4][1] = 's';
            sx = 4;
            sy = 1;
        }
        else if (posicoes[4][1] == 'v' && sx != -1 && sy != -1){
            if(sx == 4 && sy == 3 && posicoes[4][2] == 'p'){//CIMA
                posicoes[4][3] = 'v';//ORIGEM
                posicoes[4][2] = 'v';//POSIÇÃO DA PEÇA COMIDA
                posicoes[4][1] = 'p';//DESTINO
                sx = -1;
                sy = -1;
            }
            else if(sx == 2 && sy == 1 && posicoes[3][1] == 'p'){//ESQUERDA
                posicoes[2][1] = 'v';//ORIGEM
                posicoes[3][1] = 'v';//POSIÇÃO DA PEÇA COMIDA
                posicoes[4][1] = 'p';//DESTINO
                sx = -1;
                sy = -1;
            }
        }
     }
    else if(x > 231 && x < 280 && y > 466 && y < 522){//E1
        if(posicoes[4][0] == 's'){
            posicoes[4][0] = 'p';
            sx = -1;
            sy = -1;
        }
        else if (posicoes[4][0] == 'p'){
            scx = 'E';
            scy = '1';
            posicoes[4][0] = 's';
            sx = 4;
            sy = 0;
        }
        else if (posicoes[4][0] == 'v' && sx != -1 && sy != -1){
            if(sx == 4 && sy == 2 && posicoes[4][1] == 'p'){//CIMA
                posicoes[4][2] = 'v';//ORIGEM
                posicoes[4][1] = 'v';//POSIÇÃO DA PEÇA COMIDA
                posicoes[4][0] = 'p';//DESTINO
                sx = -1;
                sy = -1;
            }
            else if(sx == 2 && sy == 0 && posicoes[3][0] == 'p'){//ESQUERDA
                posicoes[2][0] = 'v';//ORIGEM
                posicoes[3][0] = 'v';//POSIÇÃO DA PEÇA COMIDA
                posicoes[4][0] = 'p';//DESTINO
                sx = -1;
                sy = -1;
            }
        }
     }
    else if(x > 434 && x < 473 && y > 254 && y < 292){//F5
        if(posicoes[5][4] == 's'){
            posicoes[5][4] = 'p';
            sx = -1;
            sy = -1;
        }
        else if (posicoes[5][4] == 'p'){
            scx = 'F';
            scy = '5';
            posicoes[5][4] = 's';
            sx = 5;
            sy = 4;
        }
        else if (posicoes[5][4] == 'v' && sx != -1 && sy != -1){
            if(sx == 5 && sy == 2 && posicoes[5][3] == 'p'){//BAIXO
                posicoes[5][2] = 'v';//ORIGEM
                posicoes[5][3] = 'v';//POSIÇÃO DA PEÇA COMIDA
                posicoes[5][4] = 'p';//DESTINO
                sx = -1;
                sy = -1;
            }
            else if(sx == 3 && sy == 4 && posicoes[4][4] == 'p'){//ESQUERDA
                posicoes[3][4] = 'v';//ORIGEM
                posicoes[4][4] = 'v';//POSIÇÃO DA PEÇA COMIDA
                posicoes[5][4] = 'p';//DESTINO
                sx = -1;
                sy = -1;
            }
        }
     }
    else if(x > 412 && x < 454 && y > 303 && y < 343){//F4
        if(posicoes[5][3] == 's'){
            posicoes[5][3] = 'p';
            sx = -1;
            sy = -1;
        }
        else if (posicoes[5][3] == 'p'){
            scx = 'F';
            scy = '4';
            posicoes[5][3] = 's';
            sx = 5;
            sy = 3;
        }
        else if (posicoes[5][3] == 'v' && sx != -1 && sy != -1){
            if(sx == 3 && sy == 3 && posicoes[4][3] == 'p'){//ESQUERDA
                posicoes[3][3] = 'v';//ORIGEM
                posicoes[4][3] = 'v';//POSIÇÃO DA PEÇA COMIDA
                posicoes[5][3] = 'p';//DESTINO
                sx = -1;
                sy = -1;
            }
        }
     }
    else if(x > 386 && x < 431 && y > 360 && y < 404){//F3
        if(posicoes[5][2] == 's'){
            posicoes[5][2] = 'p';
            sx = -1;
            sy = -1;
        }
        else if (posicoes[5][2] == 'p'){
            scx = 'F';
            scy = '3';
            posicoes[5][2] = 's';
            sx = 5;
            sy = 2;
        }
        else if (posicoes[5][2] == 'v' && sx != -1 && sy != -1){
            if(sx == 5 && sy == 4 && posicoes[5][3] == 'p'){//CIMA
                posicoes[5][4] = 'v';//ORIGEM
                posicoes[5][3] = 'v';//POSIÇÃO DA PEÇA COMIDA
                posicoes[5][2] = 'p';//DESTINO
                sx = -1;
                sy = -1;
            }
            else if(sx == 3 && sy == 2 && posicoes[4][2] == 'p'){//ESQUERDA
                posicoes[3][2] = 'v';//ORIGEM
                posicoes[4][2] = 'v';//POSIÇÃO DA PEÇA COMIDA
                posicoes[5][2] = 'p';//DESTINO
                sx = -1;
                sy = -1;
            }
        }
     }
    else if(x > 505 && x < 547 && y > 275 && y < 315){//G5
        if(posicoes[6][4] == 's'){
            posicoes[6][4] = 'p';
            sx = -1;
            sy = -1;
        }
        else if (posicoes[6][4] == 'p'){
            scx = 'G';
            scy = '5';
            posicoes[6][4] = 's';
            sx = 6;
            sy = 4;
        }
        else if (posicoes[6][4] == 'v' && sx != -1 && sy != -1){
            if(sx == 6 && sy == 2 && posicoes[6][3] == 'p'){//BAIXO
                posicoes[6][2] = 'v';//ORIGEM
                posicoes[6][3] = 'v';//POSIÇÃO DA PEÇA COMIDA
                posicoes[6][4] = 'p';//DESTINO
                sx = -1;
                sy = -1;
            }
            else if(sx == 4 && sy == 4 && posicoes[5][4] == 'p'){//ESQUERDA
                posicoes[4][4] = 'v';//ORIGEM
                posicoes[5][4] = 'v';//POSIÇÃO DA PEÇA COMIDA
                posicoes[6][4] = 'p';//DESTINO
                sx = -1;
                sy = -1;
            }
        }
     }
    else if(x > 488 && x < 533 && y > 329 && y < 370){//G4
        if(posicoes[6][3] == 's'){
            posicoes[6][3] = 'p';
            sx = -1;
            sy = -1;
        }
        else if (posicoes[6][3] == 'p'){
            scx = 'G';
            scy = '4';
            posicoes[6][3] = 's';
            sx = 6;
            sy = 3;
        }
        else if (posicoes[6][3] == 'v' && sx != -1 && sy != -1){
            if(sx == 4 && sy == 3 && posicoes[5][3] == 'p'){//ESQUERDA
                posicoes[4][3] = 'v';//ORIGEM
                posicoes[5][3] = 'v';//POSIÇÃO DA PEÇA COMIDA
                posicoes[6][3] = 'p';//DESTINO
                sx = -1;
                sy = -1;
            }
        }
     }
    else if(x > 467 && x < 516 && y > 390 && y < 437){//G3
        if(posicoes[6][2] == 's'){
            posicoes[6][2] = 'p';
            sx = -1;
            sy = -1;
        }
        else if (posicoes[6][2] == 'p'){
            scx = 'G';
            scy = '3';
            posicoes[6][2] = 's';
            sx = 6;
            sy = 2;
        }
        else if (posicoes[6][2] == 'v' && sx != -1 && sy != -1){
            if(sx == 6 && sy == 4 && posicoes[6][3] == 'p'){//CIMA
                posicoes[6][4] = 'v';//ORIGEM
                posicoes[6][3] = 'v';//POSIÇÃO DA PEÇA COMIDA
                posicoes[6][2] = 'p';//DESTINO
                sx = -1;
                sy = -1;
            }
            else if(sx == 4 && sy == 2 && posicoes[5][2] == 'p'){//ESQUERDA
                posicoes[4][2] = 'v';//ORIGEM
                posicoes[5][2] = 'v';//POSIÇÃO DA PEÇA COMIDA
                posicoes[6][2] = 'p';//DESTINO
                sx = -1;
                sy = -1;
            }
        }
     }
    else if (sx != -1 && sy != -1){//clicou fora do tabuleiro
        posicoes[sx][sy] = 'p';
        sx = -1;
        sy = -1;
     }

    int i,j;
    for(i=0;i<7;i++){
        for(j=0;j<7;j++){
            if(posicoes[i][j] == 's'){
                if(i == sx && j == sy) continue;
                else posicoes[i][j] = 'p';
            }
        }
    }
    if (sx == -1 && sy == -1){
        scx = ' ';
        scy = ' ';
    }

    sprintf(texto, "%c%c*",scx,scy/* (%d,%d)", x, y*/);

    glutPostRedisplay();
}

int main()
{
    //printf("origem: %c\ndestino: %c\ncomida: %c\n",posicoes[1][3],posicoes[3][3],posicoes[2][3]);//b4 d4 c4
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE );
    glutInitWindowPosition(10,10);
    glutInitWindowSize(600,600);
    glutCreateWindow("Resta Um - Ana, Cassio e Carlos M.");
    //registra fun��o callback para tratar evento de redimensionamento de janela
    glutReshapeFunc(Atualiza_tamanho);
    //registra fun��o callback para tratar evento de desenho
    glutDisplayFunc(Atualiza_desenho);
    //seleciona uma peça ao ser clicada o botao direito
    glutMotionFunc(MoveMouseBotaoPressionado);
    //conforme movimenta o mouse, ele atualiza o texto da tela
    glutPassiveMotionFunc(MoveMouse);
    //define a cor de limpeza da janela como sendo a branca
    glClearColor(1,1,1,0);
    //Inicializa o texto que aparece na tela
    Inicializa();
    //Inicia tratamento de eventos
    glutMainLoop();

    return 0;
}
