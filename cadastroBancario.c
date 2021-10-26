#include <stdio.h>

int cadastraUsuario(int *chave, int *senha){

    int tentativas;

    printf("\n----------------- Sistema Bancario ----------------------\n");
    printf("Faca seu cadastro! Insira sua chave bancaria e escolha uma senha.\n");


    printf("\nInsira sua chave bancaria: ");
    scanf("%d", &(*chave));

    printf("\n\nDefina sua senha: ");
    scanf("%d", &(*senha));

    while((*chave < 1000) || (*chave > 999999)){
        printf("\nX--X--X--X--X--X--X--X--X--X--X--X--X");
        printf("\n   Ops! Chave e/ou senha invalidas!");
        printf("\nX--X--X--X--X--X--X--X--X--X--X--X--X\n");

        printf("\nInsira sua chave bancaria: ");
        scanf("%d", &(*chave));

        printf("\n\nDefina sua senha: ");
        scanf("%d", &(*senha));
    }

    while((*senha < 1000) || (*senha > 999999)){
        printf("\nInsira sua chave bancaria: ");
        scanf("%d", &(*chave));

        printf("\n\nDefina sua senha: ");
        scanf("%d", &(*senha));
    }

    if(*chave > 2000){
        tentativas = 3;
    }
    else{
        tentativas = 5;
    }

    printf("\n---------------------------------------\n");

    printf("\nA chave e: %d", *chave);
    printf("\nA senha e: %d", *senha);

    printf("\n\nO endereco armazenado na chave e: %x", chave);
    printf("\nO endereco armazenado na senha e: %x", senha);

    printf("\n\nO endereco da chave e: %x", &chave);
    printf("\nO endereco da senha e: %x", &senha);

    printf("\n\nTentativas: %d\n", tentativas);

    printf("\n---------------------------------------\n");

    return tentativas;
}

int verificaSenha(int tentativa, int senha, int controleDaSenhaPorMultiplos){
    if(tentativa == senha){
        return 1;
    }
    else if(controleDaSenhaPorMultiplos != 0){
        printf("\nX--X--X--X--X--X--X");
        printf("\n  Senha incorreta!");
        printf("\nX--X--X--X--X--X--X\n");
        return 0;
    }
}

int acessoConta(int senha, int n){
    int tentativaDeSenha;
    int controleDaSenhaPorMultiplos = 0; // Ativado: 1  /  Desativado: 0

    while((n != 0)){

        printf("\nInsira a senha cadastrada para acessar sua conta: ");
        scanf("%d", &tentativaDeSenha);

        if(verificaSenha(tentativaDeSenha, senha, controleDaSenhaPorMultiplos)){
            return 1;
        }

        if(controleDaSenhaPorMultiplos){
            if((senha % tentativaDeSenha == 0) || (tentativaDeSenha % senha ==0)){
                return 1;
            }
        }

        if(tentativaDeSenha == -999){
            controleDaSenhaPorMultiplos = 1;

            printf("\n//-**-//-**-//-**-//-**-//-**-//-**-//-**-//-**-//-**-//-**-//");
            printf("\n  Voce optou por logar com um multiplo da senha cadastrada.");
            printf("\n//-**-//-**-//-**-//-**-//-**-//-**-//-**-//-**-//-**-//-**-//\n");
        }

        n--;
    }

    return 0;
}

char cartaoCredito(int score){

    if(score < 0 || score > 1000){
        printf("Score invalido\n");
        printf("A categoriado cartao e: ");
        return 'X';
    }

    if(score <= 400){
        printf("Cartao negado\n");
        printf("A categoriado cartao e: "); 
        return 'N';
    }

    if(score >= 401 && score <= 600){
        printf("Necessita de mais detalhes\n");
        printf("A categoriado cartao e: ");
        return 'X';
    }

    if(score >= 601 && score <= 800){
        printf("Cartao basico\n");
        printf("A categoriado cartao e: ");
        return 'B';
    }

    if(score >= 801 && score <= 1000){
        printf("Cartao gold\n");
        printf("A categoriado cartao e: ");
        return 'A';
    }
}

int codigoVerificador(int chave){
    int numeroDeBits1DaChave;
    int codigoDeVerificacao;

    while(chave != 0){
        if((chave % 2 == 0)){
            chave = chave / 2;
        }
        else{
            numeroDeBits1DaChave++;
            chave = chave / 2;
        }
    }

    if(numeroDeBits1DaChave >= 10){
        codigoDeVerificacao = numeroDeBits1DaChave;

        while(codigoDeVerificacao > 10){
            codigoDeVerificacao -= 10;
        }

        return codigoDeVerificacao;
    }
    
    return numeroDeBits1DaChave;
}

void banco(){

    int chaveDaConta;
    int senhaDaConta;
    int numeroDeTentativas = cadastraUsuario(&chaveDaConta, &senhaDaConta);

    if(acessoConta(senhaDaConta, numeroDeTentativas)){
        printf("Acesso realizado com sucesso\n");

        printf("%c", cartaoCredito(chaveDaConta % 1000));
    }
    else{
        printf("\n XXXXX Cliente bloqueado XXXXX\n");
    }
}

void main(){
    banco();
}




