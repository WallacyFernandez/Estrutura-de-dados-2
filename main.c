#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <locale.h>

#define TABLE_SIZE 32

struct Contact {
    char name[100];
    char email[100];
    char phone[20];
    bool occupied;
};

struct HashTable {
    struct Contact* table[TABLE_SIZE];
};

int hash(char* key) {
    unsigned long hash = 0;
    int a = 31;
    int len = strlen(key);

    for (int i = 0; i < len; i++) {
        hash = (hash * a + key[i]) % TABLE_SIZE;
    }

    return (int)hash;
}

int hash_secondary(char* key) {
    int hash = 0;
    int len = strlen(key);

    for (int i = 0; i < len; i++) {
        hash += key[i];
    }

    return (hash % (TABLE_SIZE - 1)) + 1;
}

struct HashTable* createHashTable() {
    struct HashTable* ht = (struct HashTable*)malloc(sizeof(struct HashTable));
    for (int i = 0; i < TABLE_SIZE; i++) {
        ht->table[i] = NULL;
    }
    return ht;
}

void insert(struct HashTable* ht, char* name, char* email, char* phone) {
    int index = hash(phone);
    int step = hash_secondary(phone);

    while (ht->table[index] != NULL && strcmp(ht->table[index]->phone, phone) != 0) {
        index = (index + step) % TABLE_SIZE;
    }

    if (ht->table[index] == NULL) {
        ht->table[index] = (struct Contact*)malloc(sizeof(struct Contact));
        strcpy(ht->table[index]->name, name);
        strcpy(ht->table[index]->email, email);
        strcpy(ht->table[index]->phone, phone);
        ht->table[index]->occupied = true;
    } else {
        strcpy(ht->table[index]->name, name);
        strcpy(ht->table[index]->email, email);
    }
}

struct Contact* search(struct HashTable* ht, char* phone) {
    int index = hash(phone);
    int step = hash_secondary(phone);

    while (ht->table[index] != NULL) {
        if (strcmp(ht->table[index]->phone, phone) == 0) {
            return ht->table[index];
        }
        index = (index + step) % TABLE_SIZE;
    }

    return NULL;
}

void listContacts(struct HashTable* ht) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (ht->table[i] != NULL && ht->table[i]->occupied) {
            printf("Nome: %s\n", ht->table[i]->name);
            printf("Email: %s\n", ht->table[i]->email);
            printf("Telefone: %s\n", ht->table[i]->phone);
        }
    }
}

void deleteContact(struct HashTable* ht, char* phone) {
    int index = hash(phone);
    int step = hash_secondary(phone);

    while (ht->table[index] != NULL) {
        if (strcmp(ht->table[index]->phone, phone) == 0) {
            ht->table[index]->occupied = false;
            free(ht->table[index]);
            return;
        }
        index = (index + step) % TABLE_SIZE;
    }
}

void viewCollisions(struct HashTable* ht) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (ht->table[i] != NULL && !ht->table[i]->occupied) {
            printf("Colisão no índice %d\n", i);
        }
    }
}

void createContactFile(struct HashTable* ht) {
    FILE* file = fopen("contatos.txt", "w");
    if (file == NULL) {
        printf("Erro ao criar o arquivo.\n");
        return;
    }

    for (int i = 0; i < TABLE_SIZE; i++) {
        if (ht->table[i] != NULL && ht->table[i]->occupied) {
            fprintf(file, "Nome: %s\n", ht->table[i]->name);
            fprintf(file, "Email: %s\n", ht->table[i]->email);
            fprintf(file, "Telefone: %s\n", ht->table[i]->phone);
        }
    }

    fclose(file);
    printf("Arquivo contatos.txt criado com sucesso!\n");
}

int main() {

    setlocale(LC_ALL, "pt_BR.UTF-8");
    struct HashTable* ht = createHashTable();
    int choice;
    char name[100], email[100], phone[20];

    while (1) {
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
                printf("Nome: ");
                scanf("%s", name);
                printf("Email: ");
                scanf("%s", email);
                printf("Telefone: ");
                scanf("%s", phone);
                insert(ht, name, email, phone);
                printf("Contato adicionado com sucesso!\n");
                break;

            case 2:
                listContacts(ht);
                break;

            case 3:
                printf("Telefone do contato que deseja editar: ");
                scanf("%s", phone);
                struct Contact* editContact = search(ht, phone);
                if (editContact != NULL) {
                    printf("Nome: ");
                    scanf("%s", name);
                    printf("Email: ");
                    scanf("%s", email);
                    strcpy(editContact->name, name);
                    strcpy(editContact->email, email);
                    printf("Contato editado com sucesso!\n");
                } else {
                    printf("Contato não encontrado.\n");
                }
                break;

            case 4:
                printf("Telefone do contato que deseja excluir: ");
                scanf("%s", phone);
                deleteContact(ht, phone);
                printf("Contato excluído com sucesso!\n");
                break;

            case 5:
                viewCollisions(ht);
                break;

            case 6:
                createContactFile(ht);
                break;

            case 7:
                for (int i = 0; i < TABLE_SIZE; i++) {
                    if (ht->table[i] != NULL) {
                        free(ht->table[i]);
                    }
                }
                free(ht);
                return 0;

            default:
                printf("Opção inválida!\n");
        }
    }

    return 0;
}
