#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ALUNOS 5
#define MAX_NOME 50
#define ARQUIVO "alunos.txt"

struct Aluno {
    char nome[MAX_NOME];
    int idade;
    float nota;
};

struct Aluno alunos[MAX_ALUNOS];
int numAlunos = 0;

void incluirAluno() {
    if (numAlunos < MAX_ALUNOS) {
        printf("Digite o nome do aluno: ");
        scanf("%s", alunos[numAlunos].nome);
        printf("Digite a idade do aluno: ");
        scanf("%d", &alunos[numAlunos].idade);
        printf("Digite a nota do aluno: ");
        scanf("%f", &alunos[numAlunos].nota);
        numAlunos++;
        printf("Aluno cadastrado com sucesso!\n");
    } else {
        printf("Limite de alunos atingido!\n");
    }
}

void editarAluno() {
    int index;
    printf("Digite o número do aluno que deseja editar: ");
    scanf("%d", &index);
    if (index >= 0 && index < numAlunos) {
        printf("Digite o novo nome do aluno: ");
        scanf("%s", alunos[index].nome);
        printf("Digite a nova idade do aluno: ");
        scanf("%d", &alunos[index].idade);
        printf("Digite a nova nota do aluno: ");
        scanf("%f", &alunos[index].nota);
        printf("Aluno editado com sucesso!\n");
    } else {
        printf("Aluno não encontrado!\n");
    }
}

void consultarAluno() {
    int index;
    printf("Digite o número do aluno que deseja consultar: ");
    scanf("%d", &index);
    if (index >= 0 && index < numAlunos) {
        printf("Nome: %s\n", alunos[index].nome);
        printf("Idade: %d\n", alunos[index].idade);
        printf("Nota: %.2f\n", alunos[index].nota);
    } else {
        printf("Aluno não encontrado!\n");
    }
}

void deletarAluno() {
    int index;
    printf("Digite o número do aluno que deseja deletar: ");
    scanf("%d", &index);
    if (index >= 0 && index < numAlunos) {
        for (int i = index; i < numAlunos - 1; i++) {
            strcpy(alunos[i].nome, alunos[i + 1].nome);
            alunos[i].idade = alunos[i + 1].idade;
            alunos[i].nota = alunos[i + 1].nota;
        }
        numAlunos--;
        printf("Aluno deletado com sucesso!\n");
    } else {
        printf("Aluno não encontrado!\n");
    }
}

void imprimirAlunos() {
    printf("Lista de Alunos:\n");
    for (int i = 0; i < numAlunos; i++) {
        printf("Aluno %d\n", i);
        printf("Nome: %s\n", alunos[i].nome);
        printf("Idade: %d\n", alunos[i].idade);
        printf("Nota: %.2f\n", alunos[i].nota);
    }
}

void salvarEmArquivo() {
    FILE *arquivo = fopen(ARQUIVO, "w");
    if (arquivo != NULL) {
        for (int i = 0; i < numAlunos; i++) {
            fprintf(arquivo, "%s %d %.2f\n", alunos[i].nome, alunos[i].idade, alunos[i].nota);
        }
        fclose(arquivo);
        printf("Dados salvos em arquivo.\n");
    } else {
        printf("Erro ao abrir arquivo para escrita.\n");
    }
}

void carregarDoArquivo() {
    FILE *arquivo = fopen(ARQUIVO, "r");
    if (arquivo != NULL) {
        while (!feof(arquivo) && numAlunos < MAX_ALUNOS) {
            fscanf(arquivo, "%s %d %f\n", alunos[numAlunos].nome, &alunos[numAlunos].idade, &alunos[numAlunos].nota);
            numAlunos++;
        }
        fclose(arquivo);
        printf("Dados carregados do arquivo.\n");
    } else {
        printf("Arquivo de dados não encontrado.\n");
    }
}

int main() {
    int opcao;
    carregarDoArquivo();

    do {
        printf("\nMenu:\n");
        printf("1. Incluir Aluno\n");
        printf("2. Editar Aluno\n");
        printf("3. Consultar Aluno\n");
        printf("4. Deletar Aluno\n");
        printf("5. Imprimir Alunos\n");
        printf("6. Salvar em Arquivo\n");
        printf("7. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                incluirAluno();
                break;
            case 2:
                editarAluno();
                break;
            case 3:
                consultarAluno();
                break;
            case 4:
                deletarAluno();
                break;
            case 5:
                imprimirAlunos();
                break;
            case 6:
                salvarEmArquivo();
                break;
            case 7:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 7);

    return 0;
}
