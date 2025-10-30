#include <iostream>  // Biblioteca para entrada e saída em C++
#include <limits>    // Para limpar o buffer de entrada

// Definição das constantes para o tamanho do tabuleiro e dos navios (para Batalha Naval)
const int TAM_TABULEIRO = 10;  // Tamanho fixo do tabuleiro (10x10)
const int TAM_NAVIO = 3;       // Tamanho fixo dos navios (3 posições)

// Função para inicializar o tabuleiro com 0s (representando água) - para Batalha Naval
void inicializarTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    for (int i = 0; i < TAM_TABULEIRO; ++i) {
        for (int j = 0; j < TAM_TABULEIRO; ++j) {
            tabuleiro[i][j] = 0;  // Todas as posições começam com 0
        }
    }
}

// Função para verificar se uma posição está dentro dos limites do tabuleiro - para Batalha Naval
bool posicaoValida(int linha, int coluna) {
    return (linha >= 0 && linha < TAM_TABULEIRO && coluna >= 0 && coluna < TAM_TABULEIRO);
}

// Função para verificar se as posições do navio estão livres (não sobrepostas) - para Batalha Naval
bool posicoesLivres(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna, bool horizontal) {
    for (int i = 0; i < TAM_NAVIO; ++i) {
        int l = horizontal ? linha : linha + i;
        int c = horizontal ? coluna + i : coluna;
        if (!posicaoValida(l, c) || tabuleiro[l][c] != 0) {
            return false;  // Posição inválida ou ocupada
        }
    }
    return true;
}

// Função para posicionar um navio no tabuleiro - para Batalha Naval
void posicionarNavio(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna, bool horizontal) {
    // Verifica se o posicionamento é válido
    if (!posicoesLivres(tabuleiro, linha, coluna, horizontal)) {
        std::cout << "Erro: Posicionamento inválido para o navio em (" << linha << ", " << coluna << ") - " 
                  << (horizontal ? "horizontal" : "vertical") << std::endl;
        return;  // Não posiciona se inválido
    }

    // Posiciona o navio marcando com 3
    for (int i = 0; i < TAM_NAVIO; ++i) {
        int l = horizontal ? linha : linha + i;
        int c = horizontal ? coluna + i : coluna;
        tabuleiro[l][c] = 3;  // Marca a posição com 3
    }
}

// Função para exibir o tabuleiro no console - para Batalha Naval
void exibirTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    std::cout << "Tabuleiro do Batalha Naval:" << std::endl;
    for (int i = 0; i < TAM_TABULEIRO; ++i) {
        for (int j = 0; j < TAM_TABULEIRO; ++j) {
            std::cout << tabuleiro[i][j] << " ";  // Imprime o valor da posição seguido de espaço
        }
        std::cout << std::endl;  // Nova linha após cada linha do tabuleiro
    }
}

// Função para imprimir uma matriz 3x3 - para exemplos de matrizes
void imprimirMatriz(const int matriz[3][3]) {
    std::cout << "Matriz 3x3:" << std::endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << matriz[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

// Função para executar o desafio de Batalha Naval
void executarBatalhaNaval() {
    // Declaração da matriz do tabuleiro
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];

    // Inicializa o tabuleiro com 0s
    inicializarTabuleiro(tabuleiro);

    // Coordenadas iniciais dos navios (definidas diretamente no código)
    // Navio 1: Horizontal na linha 0, coluna 0
    int linhaNavio1 = 0;
    int colunaNavio1 = 0;
    bool horizontalNavio1 = true;

    // Navio 2: Vertical na linha 2, coluna 5
    int linhaNavio2 = 2;
    int colunaNavio2 = 5;
    bool horizontalNavio2 = false;

    // Posiciona os navios no tabuleiro
    posicionarNavio(tabuleiro, linhaNavio1, colunaNavio1, horizontalNavio1);
    posicionarNavio(tabuleiro, linhaNavio2, colunaNavio2, horizontalNavio2);

    // Exibe o tabuleiro final
    exibirTabuleiro(tabuleiro);
}

// Função para executar os exemplos de matrizes
void executarExemplosMatrizes() {
    int subOpcao;

    std::cout << "\nEscolha um exemplo de matriz:" << std::endl;
    std::cout << "1 - Matriz inicializada diretamente" << std::endl;
    std::cout << "2 - Matriz inicializada elemento por elemento" << std::endl;
    std::cout << "Digite sua opcao: ";

    if (!(std::cin >> subOpcao)) {
        std::cout << "Entrada invalida! Digite um numero." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }

    switch (subOpcao) {
        case 1: {
            int matriz[3][3] = {
                {1, 2, 3},
                {4, 5, 6},
                {7, 8, 9}
            };
            imprimirMatriz(matriz);
            std::cout << "Elemento na posicao [0][0]: " << matriz[0][0] << std::endl;
            std::cout << "Elemento na posicao [1][1]: " << matriz[1][1] << std::endl;
            std::cout << "Elemento na posicao [2][2]: " << matriz[2][2] << std::endl;
            break;
        }
        case 2: {
            int matriz[3][3];
            matriz[0][0] = 1;
            matriz[0][1] = 2;
            matriz[0][2] = 3;
            matriz[1][0] = 4;
            matriz[1][1] = 5;
            matriz[1][2] = 6;
            matriz[2][0] = 7;
            matriz[2][1] = 8;
            matriz[2][2] = 9;
            imprimirMatriz(matriz);
            std::cout << "Elemento na posicao [0][0]: " << matriz[0][0] << std::endl;
            std::cout << "Elemento na posicao [1][1]: " << matriz[1][1] << std::endl;
            break;
        }
        default:
            std::cout << "Opcao invalida!" << std::endl;
            break;
    }
}

int main() {
    int opcao;

    // Loop principal para permitir múltiplas execuções
    while (true) {
        std::cout << "\n=== Menu Principal ===" << std::endl;
        std::cout << "1 - Executar Batalha Naval (Posicionar Navios)" << std::endl;
        std::cout << "2 - Exemplos de Matrizes" << std::endl;
        std::cout << "3 - Sair" << std::endl;
        std::cout << "Digite sua opcao: ";

        // Validação de entrada para evitar erros
        if (!(std::cin >> opcao)) {
            std::cout << "Entrada invalida! Digite um numero." << std::endl;
            std::cin.clear();  // Limpa o estado de erro
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ignora entrada inválida
            continue;
        }

        switch (opcao) {
            case 1:
                executarBatalhaNaval();  // Chama a função para Batalha Naval
                break;
            case 2:
                executarExemplosMatrizes();  // Chama a função para exemplos de matrizes
                break;
            case 3:
                std::cout << "Saindo do programa..." << std::endl;
                return 0;  // Sai do programa
            default:
                std::cout << "Opcao invalida! Tente novamente." << std::endl;
                break;
        }
    }

    return 0;
}
