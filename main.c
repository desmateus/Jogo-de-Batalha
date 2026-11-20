#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SAUDE 100

void MostrarStatus(int saudeHeroi, int saudeMonstro){
    printf("######### Jogo de Batalha ⚔️  #########\n");
    printf("######## Herói 🦸  x 👹  Monstro #######\n");
    printf("--------------------------------------\n");
    printf("Herói: %d \n",saudeHeroi );
    printf("Monstro: %d \n",saudeMonstro);
    printf("--------------------------------------\n");
}

void AtaqueHeroi(int *saude_Monstro){
    int dano = rand() % 11 + 20;
    *saude_Monstro = *saude_Monstro - dano;
    printf("Seu ataque causou %d de dano no Monstro 🗡️ \n", dano);
}

void AtaqueMonstro(int *saude_Heroi){
    int dano = rand() % 11 + 20;
    *saude_Heroi = *saude_Heroi - dano;
    printf("O ataque do Monstro causou %d de dano em você. 💀 👹️  \n", dano);
}

int CuraHeroi(int *saude_Heroi){
    int cura = rand() % 11 + 25;
    *saude_Heroi = *saude_Heroi + cura;
    if(*saude_Heroi > MAX_SAUDE){
        *saude_Heroi = MAX_SAUDE;
        printf("A vida do herói foi limitada a 100 HP\n");
    }
    printf("A cura foi de %d HP. 🧪  \n", cura);
}

int VerificaGanhador(int *saude_Heroi, int *saude_Monstro){
    if(*saude_Heroi <= 0 || *saude_Monstro <= 0 ){
        return 1;
    }
    return 0;
}

void MostraGanhador(int *saude_Heroi, int *saude_Monstro){
    if(*saude_Monstro <= 0){
        printf(" 🏆 🦸  Parabéns, você derrotou o Monstro! 🦸 🏆 \n");
    }
    else if(*saude_Heroi <= 0){
        printf(" ☠️ 👹   O Monstro venceu, tente jogar novamente! 👹 ☠️ \n");
    }
    else{
        printf(" Jogo encerrado! \nMas a aventura continua te esperando! \n");
        printf("Até a próxima! \n");
    }
}

int main()
{
    int saudeMonstro, saudeHeroi;
    char jogada, continua;
   
    do{
        saudeHeroi = MAX_SAUDE;
        saudeMonstro = MAX_SAUDE;
        srand(time(NULL));
        do{
            system("clear");
            MostrarStatus(saudeHeroi, saudeMonstro);
            printf("  -> 1 - Ataque 🗡\n");
            printf("  -> 2 - Cura 🧪 \n");
            printf("  -> 3 - Defesa 🛡️ \n");
            printf("  -> 4 - Sair 🚪 🔚\n");
            printf("  Digite a sua jogada: ");
            scanf("%c", &jogada);
            if(jogada == '1'){
                AtaqueHeroi(&saudeMonstro);
            }
            else if(jogada == '2'){
                CuraHeroi(&saudeHeroi);
            }
            else if(jogada == '3'){
                printf("Você defendeu o ataque do Monstro 🛡 \n");
                printf("Pressione Enter para continuar... \n");
                getchar(); 
                getchar(); 
                continue;
            }
            else if(jogada == '4'){
                printf("Você desistiu do jogo 🚪 🔚 \n ");
            }
            else{
                printf("Jogada inválida ⚠️ \n");
                printf("Pressione Enter para continuar... \n");
                getchar();
                getchar(); 
                continue;
            }
           
            if(saudeMonstro > 0){
                AtaqueMonstro(&saudeHeroi);
            }
           
            if(VerificaGanhador(&saudeHeroi, &saudeMonstro)){
                break;
            }
           
            printf("Pressione Enter para continuar... \n");
            getchar();
            getchar();      
        }while(jogada != '4');
        MostrarStatus(saudeHeroi, saudeMonstro);
        MostraGanhador(&saudeHeroi, &saudeMonstro);
        printf("Deseja continuar jogando(s/n)? ");
        scanf(" %c",&continua);
    }while(continua != 'n');

    return 0;
}
