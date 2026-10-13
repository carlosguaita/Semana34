#include <stdio.h>
#include <string.h>

float validarFlotanteRango(float min, float max);



int main (int argc, char *argv[]) {

    char nombres[5][20], matSimp[3][20]={"Mat","Len","Prog"}, aprep[3][20];
    float m1[5], m2[5], m3[5], maxminC[3][2];

    int opc, opc1;
    int contE=0;
    float promE=0 , promM[3]={0}, min, max;

    float rMin = 0;

    do
    {
        printf("Seleccione una opcion\n");
        printf("1.Registro estudiante (incluye ingreso de calificaciones)\n");
        printf("2.Mostrar promedios (por materia y estudiante)\n");
        printf("3.Mostrar calificaciones mas alta y mas baja (por materia)\n");
        printf("4.Estudiantes aprobados/reprobados\n");
        printf("5.Salir\n");
        printf(">> ");

        scanf("%d",&opc);

        switch (opc)
        {
        case 1:
            printf("Ingrese los datos del estudiante %d:\n",contE);
            printf("Nombre: ");
            scanf("%s",&nombres[contE]);

            printf("Matematicas: ");
            
            m1[contE] = validarFlotanteRango(1,100);
            
            printf("Lenguaje: ");
            m2[contE] = validarFlotanteRango(0,10);

            printf("Programacion: ");
            m3[contE] = validarFlotanteRango(0,20);

            contE++;
            break;
        case 2:
            printf("#\t\tNombre\t\tMat\t\tLen\t\tProg\t\tPromE\n");
            for (int i = 0; i < contE; i++)
            {
                promE = (m1[i] + m2[i] + m3[i])/3;
                promM[0]+=m1[i];
                promM[1]+=m2[i];
                promM[2]+=m3[i];
                printf("%d\t\t%s\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\n",i,nombres[i],m1[i],m2[i],m3[i],promE);
            }
            promM[0]/=contE;
            promM[1]/=contE;
            promM[2]/=contE;
            printf("\tPromediosM\t\t%.2f\t\t%.2f\t\t%.2f\n",promM[0],promM[1],promM[2]);
            break;

        case 3:

            min = 10;
            max = 0;
            for (int i = 0; i < contE; i++)
            {
                if (m1[i]<=min){
                    min = m1[i];
                }
                if (m1[i]>max){
                    max = m1[i];
                }
            }
            maxminC[0][0]=min;
            maxminC[0][1]=max;

            min = 10;
            max = 0;
            for (int i = 0; i < contE; i++)
            {
                if (m2[i]<=min){
                    min = m2[i];
                }
                if (m2[i]>max){
                    max = m2[i];
                }
            }
            maxminC[1][0]=min;
            maxminC[1][1]=max;

            min = 10;
            max = 0;
            for (int i = 0; i < contE; i++)
            {
                if (m3[i]<=min){
                    min = m3[i];
                }
                if (m3[i]>max){
                    max = m3[i];
                }
            }
            maxminC[2][0]=min;
            maxminC[2][1]=max;

            printf("Mats\t\tMin\t\tMax\n");

            for (int i = 0; i < 3; i++)
            {
                printf("%s\t\t%.2f\t\t%.2f\n",matSimp[i],maxminC[i][0],maxminC[i][1]);
            }
            
            break;
        case 4:
            printf("#\t\tNombre\t\tMatematicas\t\tLenguaje\t\tProgramacion\n");
            for (int i = 0; i < contE; i++)
            {
                if (m1[i]>=6){
                    strcpy(aprep[0],"Aprobado");
                }else{
                    strcpy(aprep[0],"Reprobado");
                }

                if (m2[i]>=6){
                    strcpy(aprep[1],"Aprobado");
                }else{
                    strcpy(aprep[1],"Reprobado");
                }

                if (m3[i]>=6){
                    strcpy(aprep[2],"Aprobado");
                }else{
                    strcpy(aprep[2],"Reprobado");
                }
                
                printf("%d\t\t%s\t\t%s\t\t%s\t\t%s\n",i,nombres[i],aprep[0],aprep[1],aprep[2]);
            }
            break;
        case 5:
            return 0;
        
        default:
            printf("No existe la opcion\n");
            break;
        }
        printf("Desea seleccionar otra opcion 1.Si/2.No: ");
        scanf("%d",&opc1);
    } while (opc1==1);
    



    return 0;
}


float validarFlotanteRango(float min, float max){
    int val = 0;
    float aux = 0;
    do{
        val = scanf("%f",&aux);
        while((getchar())!='\n');
        if (aux < min || aux > max || val != 1)
        {
            printf("Error: Valor ingresado incorrecto\n");
        }
    }while(aux < min || aux > max || val != 1);
    return aux;
}