 #include <stdio.h>

int main(){
    int i=1, j, op, fileira, assento, tipoIngresso, continuar, k=0;
    int ing1_int=0, ing1_meia=0; float total_1=0.0;                 // SALA 01
    int ing2_int=0, ing2_meia=0; float total_2=0.0;                 // SALA 02
    int ing3_int=0, ing3_meia=0; float total_3=0.0;                 // SALA 03
    int ing_intTotal=0, ing_meiaTotal=0; float totalGeral =0.0;     //SALAS GERAL
    int assentos[3];
    int sala1[5][10], sala2[6][11], sala3[8][9]; float valorSalas[3];

    // ******  G    E   R   E   N   T   E   *******

    for(i=0;i<3;i++){
        printf("Digite o valor da sala [%d]: ", i+1);
        scanf("%f", &valorSalas[i]);
    }

    system("cls");

    // ****** C     L   I   E   N   T   E    *******
    assentos[0] = 50, assentos[1] = 66, assentos[2] = 72;
    while(i=1){
        printf("\n\nQual sala voce gostaria de comprar o[s] ingresso[s]? \n[0] PARA CANCELAR\n[1] SALA 01 com Ingressos de R$%.2f\n[2] SALA 02 com Ingressos de R$%.2f\n[3] SALA 03 com Ingressos de R$%.2f\n "
               , valorSalas[0], valorSalas[1], valorSalas[2]);
        scanf("%d", &op);
        if(op==1 && assentos[0]==0) {printf("A Sala 01 nao possui mais assentos disponiveis :"); continue; }     //Impede a SALA 01 de ser escolhida caso ela nao tenha mais assentos
        if(op==2 && assentos[1]==0) {printf("A Sala 02 nao possui mais assentos disponiveis :"); continue; }     //Impede a SALA 02 de ser escolhida caso ela nao tenha mais assentos
        if(op==3 && assentos[2]==0) {printf("A Sala 02 nao possui mais assentos disponiveis :"); continue; }     //Impede a SALA 03 de ser escolhida caso ela nao tenha mais assentos
        if(assentos[0]==0 && assentos[1]==0 && assentos[2]==0) {printf("O Cinema nao possui mais assentos disponiveis =(("); break; } //Impede o cliente de escolher qualquer sala caso nao tenha mais assentos em todas as salas

        //C A   N   C   E   L
        if(op==0) break;

        //S A   L   A   01
        else if (op==1){
            system("cls");
            while(op==1){
                //MOSTRAR ASSENTOS
                for(i=0;i<5;i++){
                    printf("\n");
                    printf("%d  }\t", i+1);
                    for(j=0;j<10;j++){
                        if(sala1[i][j]!= 1) printf("| %d | ", j+1);
                        else printf("| X | ");
                    }
                }
                printf("\nAssentos Disponiveis: %d", assentos[0]);       //Quantidade de Assentos Disponiveis

                printf("\nQual fileira: ");                             //Escolha de fileira
                scanf("%d", &fileira);
                if(fileira>5 || fileira<1){printf("Fileira nao existe\n\n"); continue;}

                printf("\nQual assento: ");                             //Escolha de Assento
                scanf("%d", &assento);
                if(assento>10 || assento<1){printf("Assento nao existe\n\n"); continue;}
                else{
                    if(sala1[fileira-1][assento-1] == 1) {printf("Assento ja ocupado"); continue;}
                    else sala1[fileira-1][assento-1] = 1;
                }


                printf("\nIngresso eh inteira [1] ou meia [2]: ");
                scanf("%d", &tipoIngresso);

                if(tipoIngresso == 1){
                        ing1_int++, ing_intTotal++; //Quantidade Ingressos Inteiros Sala 01 e Geral
                        total_1 += valorSalas[0],totalGeral += valorSalas[0];   //Total Faturado Ingressos Inteiros Sala 01 e Geral
                }
                if(tipoIngresso == 2) {
                        ing1_meia++, ing_meiaTotal++;   //Quantidade Ingressos Meia Sala 01 e Geral
                        total_1 +=(valorSalas[0]/2), (totalGeral += valorSalas[0]/2);  //Total Faturado Ingressos Meia Sala 01 e Geral
                }

                k++;  //Quantidade de ingressos TOTAL
                assentos[0]--; //Diminui a quantidade de assentos SALA 01

                //Continuar compra sala 01
                printf("\nComprar mais um ingresso[1] - SIM e [2] - NAO: ");
                scanf("%d", &continuar);
                if(continuar==1) op = 1;
                else if(continuar==2) op=0;
                if(assentos[0]==0) {printf("Nao temos mais assentos disponiveis =("); break;}    //*********************
            }

        }

        //S A   L   A   02
        else if(op==2) {
            system("cls");
            while(op==2){
                //MOSTRAR ASSENTOS
                for(i=0;i<6;i++){
                    printf("\n");
                    printf("%d  }\t", i+1);
                    for(j=0;j<11;j++){
                        if(sala2[i][j]!= -1) printf("| %d | ", j+1);
                        else printf("| X | ");
                    }
                }

                printf("\nAssentos Disponiveis: %d", assentos[1]);       //Quantidade de Assentos Disponiveis

                printf("\nQual fileira: ");                             //Escolha de fileira
                scanf("%d", &fileira);
                if(fileira>6 || fileira<1){printf("Fileira nao existe\n\n"); continue;}

                printf("\nQual assento: ");                             //Escolha de Assento
                scanf("%d", &assento);
                if(assento>11 || assento<1){printf("Assento nao existe\n\n"); continue;}
                else{
                    if(sala2[fileira-1][assento-1] == -1) {printf("Assento ja ocupado"); continue;}
                    else sala2[fileira-1][assento-1] = -1;
                }

                printf("\nIngresso eh inteiro [1] ou meia [2]: ");
                scanf("%d", &tipoIngresso);

                if(tipoIngresso == 1) {
                    ing2_int++, ing_intTotal++; //Quantidade de Ingressos Inteiros Sala 02 e Geral
                    total_2 += valorSalas[1], totalGeral += valorSalas[1];  //Total Faturado Ingressos Inteiros Sala 02 e Geral
                }
                if(tipoIngresso == 2) {
                    ing2_meia++, ing_meiaTotal++;   //Quantidade de Ingressos Meia Sala 02 e Geral
                    total_2 += (valorSalas[1]/2), totalGeral += (valorSalas[1]/2);  //Total Faturado Ingressos Meia Sala 02 e Geral
                }

                k++;
                assentos[1]--; //Diminui a quantidade de assentos SALA 02

                //Continuar compra sala 02
                printf("\nComprar mais um ingresso [1] - SIM e [2] - NAO: ");
                scanf("%d", &continuar);
                if(continuar==1) op = 2;
                else if (continuar==2) op = 0;
                if(assentos[1]==0) {printf("Nao temos mais assentos disponiveis =("); break;}
            }
        }

        //S A   L   A   03
        else if(op==3){
            system("cls");
            while(op==3){
                //MOSTRAR ASSENTOS
                for(i=0;i<8;i++){
                    printf("\n");
                    printf("%d  }\t", i+1);
                    for(j=0;j<9;j++){
                        if(sala3[i][j]!= -3) printf("| %d | ", j+1);
                        else printf("| X | ");
                    }
                }

                printf("\nAssentos Disponiveis: %d", assentos[2]);                   //Quantidade de Assentos Disponiveis

                printf("\nQual fileira: ");                                         //Escolha de Fileira
                scanf("%d", &fileira);
                if(fileira>8 || fileira<1){printf("Fileira nao existe\n\n"); continue;}

                printf("\nQual assento: ");                                         //Escolha de Assento
                scanf("%d", &assento);
                if(assento>9 || assento<1){printf("Assento nao existe\n\n"); continue;}
                else{
                    if(sala3[fileira-1][assento-1] == -3) {printf("Assento ja ocupado"); continue;}
                    else sala3[fileira-1][assento-1] = -3;
                }

                printf("\nIngresso eh inteira [1] ou meia [2]: ");
                scanf("%d", &tipoIngresso);
                if(tipoIngresso == 1){
                    ing3_int++, ing_intTotal++; //Quantidade de Ingressos Inteiros Sala 03 e Geral
                    total_3 += valorSalas[2], totalGeral += valorSalas[2];  //Total Faturado Ingressos Inteiros Sala 03 e Geral
                }
                else if(tipoIngresso == 2){
                    ing3_meia++, ing_meiaTotal++;   //Quantidade de Ingressos Meia Sala 03 e Geral
                    total_3 += (valorSalas[2]/2), totalGeral += (valorSalas[2]/2);  //Total Faturado Ingressos Meia Sala 03 e Geral
                }

                k++;
                assentos[2]--; //Diminui a quantidade de assentos SALA 03

                //Continuar compra sala 02
                printf("\nComprar mais um ingresso [1] - SIM e [2] - NAO: ");
                scanf("%d", &continuar);
                if(continuar==1) op = 3;
                else if (continuar==2) op = 0;
                else if (continuar != 2 && continuar!= 1) continue;

                if(assentos[2]==0) {printf("Nao temos mais assentos disponiveis =("); break;}
            }
    }

        //S A   L   A       I   N   E   X   I   S   T   E   N   T   E
        else if(op<0 || op>3) {printf("Essa sala nao existe, tente novamente"); continue;};
    }
    // R    E   L   A   T   O   R   I   O
    printf("\n\n\n ************** R E L A T O R I O **************\n\n");

    printf("----\ SALA 01 /----");
    printf("\nNumero de Ingressos Inteiros: %d\nNumero de Ingressos Meia: %d", ing1_int, ing1_meia);
    printf("\nTotal Faturado em Ingressos: R$%.2f\nQuantidade de Assentos NAO Ocupados: %d", total_1, (50 - (ing1_int+ing1_meia)));   //50 Total de Assentos na Sala 01

    printf("\n\n----\ SALA 02 /----");
    printf("\nNumero de Ingressos Inteiros: %d\nNumero de Ingressos Meia: %d", ing2_int, ing2_meia);
    printf("\nTotal Faturado em Ingressos: R$%.2f\nQuantidade de Assentos NAO Ocupados: %d", total_2, (66 - (ing2_int+ing2_meia)));   //66 Total de Assentos na Sala 02

    printf("\n\n----\ SALA 03 /----");
    printf("\nNumero de Ingressos Inteiros: %d\nNumero de Ingressos Meia: %d", ing3_int, ing3_meia);
    printf("\nTotal Faturado em Ingressos: R$%.2f\nQuantidade de Assentos NAO Ocupados: %d", total_3, (72 - (ing3_int+ing3_meia)));   //72 Total de Assentos na Sala 03

    printf("\n\n----\ TOTAL /----");
    printf("\nNumero de Ingressos Inteiros: %d\nNumero de Ingressos Meia: %d", ing_intTotal, ing_meiaTotal);
    printf("\nTotal Faturado em Ingressos: R$%.2f\nQuantidade de Assentos NAO Ocupados: %d\n\n\n\n", totalGeral, (188-k)); //188 Total de Assentos
}
