Relatório sobre o Código em C Tratamento de Colisões utilizando o método da multiplicação e duplo hash
Introdução
Este relatório analisa um programa em linguagem C que implementa uma tabela hash com tratamento de colisões e oferece funcionalidades para gerenciar contatos. O código demonstra conceitos importantes de estruturas de dados, como funções de hash, tratamento de colisões e interação com o usuário.

Visão Geral do Código
O código consiste em várias funções e estruturas de dados que trabalham juntas para criar e gerenciar uma tabela hash de contatos. Abaixo, descrevemos cada parte do código em detalhes:

Estrutura de Dados
A estrutura de dados central é a DataItem, que representa um item na tabela hash. Possui os seguintes campos:

nome: Uma string com até 50 caracteres para armazenar o nome do contato.
email: Uma string com até 100 caracteres para armazenar o endereço de email do contato.
telefone: Uma string com até 15 caracteres para armazenar o número de telefone do contato.
chave: Um inteiro que serve como chave para identificar o contato na tabela hash.

A tabela hash em si é representada por um array de ponteiros para DataItem, chamado hashTable. O tamanho da tabela é definido pela constante SIZE.

Função de Hash
A função multiplicação é responsável por calcular o índice da tabela hash para um determinado DataItem. Ela utiliza o método de multiplicação, recomendado para espalhar as chaves de forma uniforme. O código também utiliza uma constante de multiplicação (2654435761LL) para melhorar a distribuição das chaves.

Inicialização
A função initHashTable inicializa a tabela hash, percorrendo todo o array hashTable e definindo todos os elementos como NULL. Essa função deve ser chamada antes de usar a tabela hash.

Inserção de Contatos
A função insert permite a inserção de um novo contato na tabela hash. Ela calcula o índice usando a função de hash e lida com colisões usando o método de endereçamento duplo. Se a posição calculada já estiver ocupada, a função procura a próxima posição disponível.

Listagem de Contatos
A função listContacts lista todos os contatos presentes na tabela hash. Ela percorre o array hashTable, verificando se cada posição contém um contato e, se sim, imprime os detalhes desse contato, incluindo nome, email, telefone e chave.

Edição de Contato
A função editContact permite editar as informações de um contato com base em sua chave. O usuário fornece a chave do contato que deseja editar, e a função procura o contato correspondente na tabela hash. Se encontrado, o código solicita ao usuário que insira o novo nome, email e telefone para atualização.

Exclusão de Contato
A função deleteContact permite a exclusão de um contato com base em sua chave. O usuário fornece a chave do contato que deseja excluir, e a função procura o contato correspondente na tabela hash. Se encontrado, o código libera a memória alocada para o contato e define a posição como NULL.

Visualização de Colisões
A função viewCollisions verifica e exibe colisões de entrada na tabela hash. Ela percorre o array hashTable e, para cada posição ocupada, calcula o índice usando a função de hash e verifica se esse índice é diferente da posição atual. Se for diferente, isso indica uma colisão, e os detalhes do contato são impressos juntamente com o índice calculado.

Criação de Arquivo de Contatos
A função createContactFile cria um arquivo de texto chamado "contatos.txt" e escreve os detalhes de todos os contatos presentes na tabela hash. Ela abre o arquivo em modo de escrita, percorre a tabela hash e escreve os dados formatados no arquivo. Após concluir a escrita, fecha o arquivo e exibe uma mensagem de sucesso.


Menu Principal
A função main é responsável pela interação com o usuário por meio de um menu de opções. O menu oferece as seguintes opções:


Adicionar novo contato.
Listar todos os contatos.
Editar um contato.
Excluir um contato.
Visualizar colisões de entrada.
Criar arquivo de contatos.
Sair do programa.

O programa entra em um loop que continua exibindo o menu até que o usuário escolha a opção de sair (opção 7). Com base na escolha do usuário, a função main chama as funções correspondentes para executar as operações desejadas.

Conclusão
O código em C fornece uma implementação funcional de uma tabela hash com tratamento de colisões. Ele demonstra de maneira clara e didática os principais conceitos relacionados a tabelas hash, como funções de hash, tratamento de colisões e manipulação de estruturas de dados. No entanto, o código possui um tamanho fixo para a tabela hash (definido pela constante SIZE), o que limita o número de contatos que podem ser armazenados. Além disso, pode haver oportunidades de melhoria, como adicionar validações de entrada e tratamento de erros mais robustos. No geral, este código serve como um exemplo útil para aprender sobre tabelas hash e programação em C.

 
