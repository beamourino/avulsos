#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void verificar_previsao_tempo();
void doar_para_vitimas();
void enviar_mensagens_apoio();

int main() {
    int escolha;
    do {
        printf("\n\n### Menu de Opções ###\n");
        printf("1. Verificar a Previsão do tempo\n");
        printf("2. Doar para vítimas das chuvas\n");
        printf("3. Enviar mensagens de apoio\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                verificar_previsao_tempo();
                break;
            case 2:
                doar_para_vitimas();
                break;
            case 3:
                enviar_mensagens_apoio();
                break;
            case 4:
                printf("Encerrando o programa. Até logo!\n");
                break;
            default:
                printf("Opção inválida. Escolha novamente.\n");
        }
    } while (escolha != 4); 

    return 0;
}

void verificar_previsao_tempo() {
    FILE *arquivo;
    int dia, mes;
    char nome_arquivo[] = "previsao_do_tempo.txt";
    char previsao_do_tempo[50];
     char cidade[20];
    // Abrir arquivo para escrita
    arquivo = fopen(nome_arquivo, "a");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo %s.\n", nome_arquivo);
        return;
    }
    printf("\n### Verificar Previsão do Tempo ###\n");
    printf("Digite o dia e o mês para verificar a previsão (dia(23) mês(3)): ");
    scanf("%d %d", &dia, &mes);
    while(!(dia <= 31 && dia >= 1 && mes >= 1 && mes <= 12)){ 
        printf("Dia ou Mes inválido, digite novamente\n");
        scanf("%d %d", &dia, &mes);
    }
    printf("digite agora a cidade do local que deseja verificar (em caso de cidades com espaço escreva _ \n ex: sao_paulo): ");
    scanf("%s",cidade); 
    if(dia %3 == 0){
        fprintf(arquivo, "Previsão para %02d/%02d em %s: Ensolarado\n", dia, mes, cidade);
        printf("Previsão do tempo para %d/%d salva no arquivo %s.\n", dia, mes, nome_arquivo);
    }
    else if(dia %3 == 1){
        fprintf(arquivo, "Previsão para %02d/%02d em %s: Nublado\n", dia, mes, cidade);
        printf("Previsão do tempo para %d/%d salva no arquivo %s.\n", dia, mes, nome_arquivo);
    }
    else{
            fprintf(arquivo, "Previsão para %02d/%02d em %s: Chuvoso\n", dia, mes, cidade);
            printf("Previsão do tempo para %d/%d salva no arquivo %s.\n", dia, mes, nome_arquivo);
    }
    fclose(arquivo);
}
void doar_para_vitimas() {
    printf("\n### Doar para Vítimas das Chuvas ###\n");
    printf("Como e o que doar:\n");
    printf("- Dinheiro: chave pix do governo do RS: 92.958.800/0001-38 \n\n");
    printf("- Alimentos: Rede de Bancos de alimentos do RS e bancos sociais.\n Site:  http://www.doealimentos.com.br\n\n");
    printf("- Itens: Podem ser entregues nos abrigos ou postos de coleta ou por meio de lojas comerciais bem intencionadas como a CVC.\n\n");
    printf("- Como ser voluntário: preencher o cadastro no no site da SES em https://saude.rs.gov.br/cadastro-de-profissionais.\n\n");
}
void enviar_mensagens_apoio() {
    int idade;
    printf("digite a idade do tipo de pessoa que deseja apoiar: ");
    scanf("%d", &idade);
    printf("\n### Enviar Mensagens de Apoio ###\n");
    
    if(idade<13) {
        printf("- Mantenha-se forte! Vamos passar por isso juntos.\n");
    }else if(idade< 18){
    printf("- Sua ajuda é essencial para reconstruirmos nossa comunidade.\n");
    }else {
    printf("- Unidos podemos superar qualquer desafio. Conte conosco.\n");
}}
