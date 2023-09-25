#define SIZE 32

typedef struct DataItem {
    char nome[50];
    char email[100];
    char telefone[15];
    int chave;
} DataItem;

DataItem *hashTable[SIZE];

int multiplicacao(DataItem *d) {
    long long int key = (long long int)d->chave;
    key = key * 2654435761LL;
    return (int)(key % SIZE);
}

void initHashTable() {
    for (int i = 0; i < SIZE; i++) {
        hashTable[i] = NULL;
    }
}

void insert(DataItem *item) {
    int chave = item->chave;
    int hashIndex = multiplicacao(item);
    int stepSize = 7 - (chave % 7);

    while (hashTable[hashIndex] != NULL) {
        hashIndex += stepSize;
        hashIndex %= SIZE;
    }

    hashTable[hashIndex] = item;
}

void listContacts() {
    printf("\nLista de Contatos:\n");
    for (int i = 0; i < SIZE; i++) {
        if (hashTable[i] != NULL) {
            printf("Chave: %d\n", hashTable[i]->chave);
            printf("Nome: %s\n", hashTable[i]->nome);
            printf("Email: %s\n", hashTable[i]->email);
            printf("Telefone: %s\n\n", hashTable[i]->telefone);
        }
    }
}

void editContact(int chave) {
    for (int i = 0; i < SIZE; i++) {
        if (hashTable[i] != NULL && hashTable[i]->chave == chave) {
            printf("Novo nome: ");
            scanf("%s", hashTable[i]->nome);
            printf("Novo email: ");
            scanf("%s", hashTable[i]->email);
            printf("Novo telefone: ");
            scanf("%s", hashTable[i]->telefone);
            printf("Contato editado com sucesso!\n");
            return;
        }
    }
    printf("Contato nao encontrado.\n");
}

void deleteContact(int chave) {
    for (int i = 0; i < SIZE; i++) {
        if (hashTable[i] != NULL && hashTable[i]->chave == chave) {
            free(hashTable[i]);
            hashTable[i] = NULL;
            printf("Contato excluido com sucesso!\n");
            return;
        }
    }
    printf("Contato nao encontrado.\n");
}

void viewCollisions() {
    printf("\nColisoes de Entrada:\n");
    for (int i = 0; i < SIZE; i++) {
        if (hashTable[i] != NULL) {
            int hashIndex = multiplicacao(hashTable[i]);
            if (hashIndex != i) {
                printf("Chave: %d, Colidiu com chave na posicao: %d\n", hashTable[i]->chave, hashIndex);
            }
        }
    }
}

void createContactFile() {
    FILE *file = fopen("contatos.txt", "w");
    if (file == NULL) {
        printf("Erro ao criar o arquivo de contatos.\n");
        return;
    }

    for (int i = 0; i < SIZE; i++) {
        if (hashTable[i] != NULL) {
            fprintf(file, "Chave: %d\n", hashTable[i]->chave);
            fprintf(file, "Nome: %s\n", hashTable[i]->nome);
            fprintf(file, "Email: %s\n", hashTable[i]->email);
            fprintf(file, "Telefone: %s\n\n", hashTable[i]->telefone);
        }
    }

    fclose(file);
    printf("Arquivo de contatos criado com sucesso.\n");
}

int main() {
    initHashTable();
    int choice;

    do {
        printf("\nMenu:\n");
        printf("1. Adicionar novo contato\n");
        printf("2. Listar todos os contatos\n");
        printf("3. Editar um contato\n");
        printf("4. Excluir um contato\n");
        printf("5. Visualizar colisoes de entrada\n");
        printf("6. Criar arquivo de contatos\n");
        printf("7. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                {
                    DataItem *newItem = (DataItem *)malloc(sizeof(DataItem));
                    printf("Chave: ");
                    scanf("%d", &newItem->chave);
                    printf("Nome: ");
                    scanf("%s", newItem->nome);
                    printf("Email: ");
                    scanf("%s", newItem->email);
                    printf("Telefone: ");
                    scanf("%s", newItem->telefone);
                    insert(newItem);
                }
                break;
            case 2:
                listContacts();
                break;
            case 3:
                {
                    int chave;
                    printf("Digite a chave do contato que deseja editar: ");
                    scanf("%d", &chave);
                    editContact(chave);
                }
                break;
            case 4:
                {
                    int chave;
                    printf("Digite a chave do contato que deseja excluir: ");
                    scanf("%d", &chave);
                    deleteContact(chave);
                }
                break;
            case 5:
                viewCollisions();
                break;
            case 6:
                createContactFile();
                break;
            case 7:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
                break;
        }
    } while (choice != 7);

    return 0;
}
