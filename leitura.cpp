#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

// Definicao das estruturas
struct Cidades {
    int codigo;
    std::string nome;
    std::string UF;
};

struct Especialidades {
    int codigo1;
    std::string descricao;
};

struct Medicos {
    int codigo2;
    std::string nome;
    int codigo_especialidade;
    std::string endereco;
    std::string telefone;
    int codigo_cidade;
};

struct Pacientes {
    long long CPF;
    std::string nome;
    std::string endereco;
    int codigo_cidade;
};

struct CID {
    int codigo3;
    std::string descricaoc;
};

struct Medicamentos {
    int codigo;
    std::string descricao;
    int quant_estoque;
    int estoque_minimo;
    int estoque_maximo;
    double preco_unitario;
};

struct Consultas {
    long long CPF;
    int cod_medico;
    std::string data;
    std::string horario;
    int cod_CID;
    int cod_medicamento;
    int qtde_medicamento;
};

// Funcoes para leitura de dados
void lerCidade(Cidades &cidade) {
    std::cout << "Informe o codigo da cidade: ";
    std::cin >> cidade.codigo;
    std::cout << "Informe o nome da cidade: ";
    std::cin.ignore(); // Limpar o buffer do teclado
    std::getline(std::cin, cidade.nome);
    std::cout << "Informe a UF da cidade: ";
    std::cin >> cidade.UF;
}

void lerEspecialidade(Especialidades &especialidade) {
    std::cout << "Informe o codigo da especialidade: ";
    std::cin >> especialidade.codigo1;
    std::cout << "Informe a descricao da especialidade: ";
    std::cin.ignore(); // Limpar o buffer do teclado
    std::getline(std::cin, especialidade.descricao);
}

void lerCID(CID &cid) {
    std::cout << "Informe o codigo do CID: ";
    std::cin >> cid.codigo3;
    std::cout << "Informe a descricao do CID: ";
    std::cin.ignore(); // Limpar o buffer do teclado
    std::getline(std::cin, cid.descricaoc);
}

void lerMedicamento(Medicamentos &medicamento) {
    std::cout << "Informe o codigo do medicamento: ";
    std::cin >> medicamento.codigo;
    std::cout << "Informe a descricao do medicamento: ";
    std::cin.ignore(); // Limpar o buffer do teclado
    std::getline(std::cin, medicamento.descricao);
    std::cout << "Informe a quantidade em estoque: ";
    std::cin >> medicamento.quant_estoque;
    std::cout << "Informe o estoque minimo: ";
    std::cin >> medicamento.estoque_minimo;
    std::cout << "Informe o estoque maximo: ";
    std::cin >> medicamento.estoque_maximo;
    std::cout << "Informe o preco unitario: ";
    std::cin >> medicamento.preco_unitario;
}

int main() {
    int opcao;
    do {
        std::cout << "Escolha uma opcao:\n";
        std::cout << "1. Cadastrar cidade\n";
        std::cout << "2. Cadastrar especialidade\n";
        std::cout << "3. Cadastrar CID\n";
        std::cout << "4. Cadastrar medicamento\n";
        std::cout << "0. Sair\n";
        std::cout << "Opcao: ";
        std::cin >> opcao;

        switch (opcao) {
            case 1: {
                Cidades cidade;
                lerCidade(cidade);
                std::cout << "Cidade cadastrada com sucesso!\n";
                break;
            }
            case 2: {
                Especialidades especialidade;
                lerEspecialidade(especialidade);
                std::cout << "Especialidade cadastrada com sucesso!\n";
                break;
            }
            case 3: {
                CID cid;
                lerCID(cid);
                std::cout << "CID cadastrado com sucesso!\n";
                break;
            }
            case 4: {
                Medicamentos medicamento;
                lerMedicamento(medicamento);
                std::cout << "Medicamento cadastrado com sucesso!\n";
                break;
            }
            case 0:
                std::cout << "Saindo...\n";
                break;
            default:
                std::cout << "Opcao invalida! Tente novamente.\n";
                break;
        }
    } while (opcao != 0);

    return 0;
}
