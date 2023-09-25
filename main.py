SIZE = 32

class DataItem:
    def __init__(self):
        self.nome = ""
        self.email = ""
        self.telefone = ""
        self.chave = 0

def multiplicacao(d):
    key = d.chave
    key = key * 2654435761
    key = key % SIZE
    return key

def initHashTable():
    global hashTable
    hashTable = [None] * SIZE

def insert(item):
    chave = item.chave
    hashIndex = multiplicacao(item)
    stepSize = 7 - (chave % 7)

    while hashTable[hashIndex] is not None:
        hashIndex += stepSize
        hashIndex %= SIZE

    hashTable[hashIndex] = item

def listContacts():
    print("\nLista de Contatos:")
    for i in range(SIZE):
        if hashTable[i] is not None:
            print("Chave:", hashTable[i].chave)
            print("Nome:", hashTable[i].nome)
            print("Email:", hashTable[i].email)
            print("Telefone:", hashTable[i].telefone, "\n")

def editContact(chave):
    for i in range(SIZE):
        if hashTable[i] is not None and hashTable[i].chave == chave:
            print("Novo nome:", end=" ")
            hashTable[i].nome = input()
            print("Novo email:", end=" ")
            hashTable[i].email = input()
            print("Novo telefone:", end=" ")
            hashTable[i].telefone = input()
            print("Contato editado com sucesso!")
            return
    print("Contato nao encontrado.")

def deleteContact(chave):
    for i in range(SIZE):
        if hashTable[i] is not None and hashTable[i].chave == chave:
            del hashTable[i]
            hashTable[i] = None
            print("Contato excluido com sucesso!")
            return
    print("Contato nao encontrado.")

def viewCollisions():
    print("\nColisoes de Entrada:")
    for i in range(SIZE):
        if hashTable[i] is not None:
            hashIndex = multiplicacao(hashTable[i])
            if hashIndex != i:
                print("Chave:", hashTable[i].chave, "Colidiu com chave na posicao:", hashIndex)

def createContactFile():
    file = open("contatos.txt", "w")
    if file is None:
        print("Erro ao criar o arquivo de contatos.")
        return

    for i in range(SIZE):
        if hashTable[i] is not None:
            file.write("Chave: {}\n".format(hashTable[i].chave))
            file.write("Nome: {}\n".format(hashTable[i].nome))
            file.write("Email: {}\n".format(hashTable[i].email))
            file.write("Telefone: {}\n\n".format(hashTable[i].telefone))

    file.close()
    print("Arquivo de contatos criado com sucesso.")

def main():
    initHashTable()

    while True:
        print("\nMenu:")
        print("1. Adicionar novo contato")
        print("2. Listar todos os contatos")
        print("3. Editar um contato")
        print("4. Excluir um contato")
        print("5. Visualizar colisoes de entrada")
        print("6. Criar arquivo de contatos")
        print("7. Sair")
        choice = int(input("Escolha uma opcao: "))

        if choice == 1:
            newItem = DataItem()
            newItem.chave = int(input("Chave: "))
            newItem.nome = input("Nome: ")
            newItem.email = input("Email: ")
            newItem.telefone = input("Telefone: ")
            insert(newItem)
        elif choice == 2:
            listContacts()
        elif choice == 3:
            chave = int(input("Digite a chave do contato que deseja editar: "))
            editContact(chave)
        elif choice == 4:
            chave = int(input("Digite a chave do contato que deseja excluir: "))
            deleteContact(chave)
        elif choice == 5:
            viewCollisions()
        elif choice == 6:
            createContactFile()
        elif choice == 7:
            print("Saindo do programa...")
            break
        else:
            print("Opcao invalida. Tente novamente.")

if __name__ == "__main__":
    main()
