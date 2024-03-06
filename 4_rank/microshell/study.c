// Includes


// Função para escrever uma mensagem de erro no erro padrão (descritor de arquivo 2)


// Função (cd) para alterar o diretório atual


// Função (exec) para executar um comando
    // Cria um array de inteiros para armazenar os descritores de arquivo para o pipe
    // Cria variável para armazenar o status do processo filho
    // Verifica se um pipe ("|") está presente no comando (bool)
    // Cria um novo pipe, Se um pipe está presente e a criação do pipe falha, retorna um erro
    // Cria um processo filho
    // Se estamos no processo filho
        // Define o elemento após a barra vertical ou ponto e vírgula como nulo
        // Se um pipe está presente e o redirecionamento ou fechamento do pipe falha, retorna um erro
        // Executa o comando
        // Se a execução falhar, retorna um erro
    // No processo pai, aguarda o processo filho terminar
    // Se um pipe está presente e o redirecionamento ou fechamento do pipe falha, retorna um erro
    // Retorna o status de saída do processo filho


// Main
// Mova o ponteiro para frente
// Redefinir i para 0
// Encontrar o proximo pipes ou ;
// execute o camando cd (*argv)
// execute outros comandos
