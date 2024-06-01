#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

// Definição das estruturas
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

// Funções para leitura de dados
Cidades lerCidade() {
    Cidades cidade;
    // Implemente a leitura dos dados de uma cidade
    return cidade;
}

Especialidades lerEspecialidade() {
    Especialidades especialidade;
    // Implemente a leitura dos dados de uma especialidade
    return especialidade;
}

Medicos lerMedico() {
    Medicos medico;
    // Implemente a leitura dos dados de um médico
    return medico;
}

Pacientes lerPaciente() {
    Pacientes paciente;
    // Implemente a leitura dos dados de um paciente
    return paciente;
}

CID lerCID() {
    CID cid;
    // Implemente a leitura dos dados de um CID
    return cid;
}

Medicamentos lerMedicamento() {
    Medicamentos medicamento;
    // Implemente a leitura dos dados de um medicamento
    return medicamento;
}

Consultas lerConsulta() {
    Consultas consulta;
    // Implemente a leitura dos dados de uma consulta
    return consulta;
}

// Funções para exibir dados
void mostrarCidades(const std::vector<Cidades>& cidades) {
    std::cout << "---------------------------------------------------------------------------\n";
    for (const auto& cidade : cidades) {
        std::cout << "Codigo: " << cidade.codigo << ", Nome: " << cidade.nome << ", UF: " << cidade.UF << std::endl;
    }
    std::cout << "---------------------------------------------------------------------------\n";
}

void mostrarEspecialidades(const std::vector<Especialidades>& especialidades) {
    for (const auto& especialidade : especialidades) {
        std::cout << "Codigo da Especialidade: " << especialidade.codigo1 << ", Especialidade: " << especialidade.descricao << std::endl;
    }
    std::cout << "---------------------------------------------------------------------------\n";
}

void mostrarMedicos(const std::vector<Medicos>& medicos) {
    std::cout << "CADASTRO DE MEDICOS\n";
    for (const auto& medico : medicos) {
        std::cout << "Codigo do Medico: " << medico.codigo2 << "\n"
                  << "Medico: " << medico.nome << "\n"
                  << "Codigo Especialidade: " << medico.codigo_especialidade << "\n"
                  << "Endereco: " << medico.endereco << "\n"
                  << "Telefone: " << medico.telefone << "\n"
                  << "Codigo Cidade: " << medico.codigo_cidade << "\n"
                  << "---------------------------------------------------------------------------\n";
    }
}

void mostrarPacientes(const std::vector<Pacientes>& pacientes) {
    std::cout << "CADASTRO DE PACIENTES\n";
    for (const auto& paciente : pacientes) {
        std::cout << "CPF paciente: " << paciente.CPF << "\n"
                  << "Nome paciente: " << paciente.nome << "\n"
                  << "Endereco: " << paciente.endereco << "\n"
                  << "Codigo Cidade: " << paciente.codigo_cidade << "\n"
                  << "---------------------------------------------------------------------------\n";
    }
}

void mostrarCID(const std::vector<CID>& doencas) {
    std::cout << "CADASTRO DE CID\n";
    for (const auto& doenca : doencas) {
        std::cout << "Codigo: " << doenca.codigo3 << "\n"
                  << "Descricao: " << doenca.descricaoc << "\n"
                  << "---------------------------------------------------------------------------\n";
    }
}

void mostrarMedicamentos(const std::vector<Medicamentos>& medicines) {
    for (const auto& medicine : medicines) {
        std::cout << "Codigo: " << medicine.codigo << "\n"
                  << "Descricao: " << medicine.descricao << "\n"
                  << "Quantidade em estoque: " << medicine.quant_estoque << "\n"
                  << "Estoque Minimo: " << medicine.estoque_minimo << "\n"
                  << "Estoque Maximo: " << medicine.estoque_maximo << "\n"
                  << "Preco Unitario: " << medicine.preco_unitario << "\n"
                  << "---------------------------------------------------------------------------\n";
    }
}

void mostrarConsultas(const std::vector<Consultas>& consultas) {
    for (const auto& consulta : consultas) {
        std::cout << "CPF do Paciente: " << consulta.CPF << "\n"
                  << "Codigo do Medico: " << consulta.cod_medico << "\n"
                  << "Data: " << consulta.data << "\n"
                  << "Horario: " << consulta.horario << "\n"
                  << "Codigo da Doenca: " << consulta.cod_CID << "\n"
                  << "Codigo do Medicamento: " << consulta.cod_medicamento << "\n"
                  << "Quantidade de Medicamento: " << consulta.qtde_medicamento << "\n"
                  << "---------------------------------------------------------------------------\n";
    }
}

// Função principal com menu
int main() {
    // Inicializando as estruturas com os dados fornecidos
    std::vector<Cidades> cidades = {
        {1, "Assis", "SP"},
        {2, "Candido Mota", "SP"},
        {3, "Londrina", "PR"},
        {4, "Esteio", "RS"},
        {5, "Xanxere", "SC"}
    };

    std::vector<Especialidades> especialidades = {
        {1, "Oftalmologia"},
        {2, "Cardiologista"},
        {3, "Generalista"},
        {4, "Pediatria"},
        {5, "Psiquiatria"}
    };

    std::vector<Medicos> medicos = {
        {1, "Dr. Carlos", 1, "Rua 1, 123", "1234-5678", 1},
        {2, "Dr. Joao", 2, "Rua 2, 456", "1234-5678", 2},
        {3, "Dr. Pedro", 3, "Rua 3, 789", "1234-5678", 3},
        {4, "Dra. Maria", 4, "Rua 4, 012", "1234-5678", 4},
        {5, "Dr. Marcos", 5, "Rua 5, 345", "1234-5678", 5}
    };

    std::vector<Pacientes> pacientes = {
        {33666790003, "Carlos Felipe", "Travessa Antonio Ferreira, 123", 1},
        {24880474061, "Luis Guilherme", "Avenida Rio Branco, 420", 2},
        {44672557022, "Ana Luiza", "Rua dos Carijos, 1024", 3},
        {33689294029, "Henrique Silva", "Rua 1, 123", 4},
        {20824063007, "Pedro Henrique", "Rua Arlindo Nogueira, 123", 5}
    };

    std::vector<CID> doencas = {
        {1, "Caxumba"},
        {2, "Febre Amarela"},
        {3, "Gripe"},
        {4, "Dengue"},
        {5, "Covid"}
    };

    std::vector<Medicamentos> medicines = {
        {1, "Penicilina", 100, 50, 200, 50.0},
        {2, "Aspirina", 50, 25, 100, 60.0},
        {3, "Losartana", 75, 30, 150, 70.0},
        {4, "Rivotril", 120, 60, 200, 80.0},
        {5, "Omeprazol", 80, 40, 160, 90.0}
    };

    std::vector<Consultas> consultas = {
        {33666790003, 1, "2022-01-01", "10:00", 3, 2, 10},
        {24880474061, 2, "2022-01-02", "14:00", 2, 1, 5},
        {44672557022, 3, "2022-01-03", "08:00", 1, 3, 8},
        {33689294029, 1, "2022-01-04", "12:00", 5, 4, 3},
        {20824063007, 2, "2022-01-05", "16:00", 4, 5, 7}
    };

    int escolha;

    do {
        std::cout << "Menu de Opcoes" << std::endl;
        std::cout << "1. Mostrar Cidades" << std::endl;
        std::cout << "2. Mostrar Especialidades" << std::endl;
        std::cout << "3. Mostrar Medicos" << std::endl;
        std::cout << "4. Mostrar Pacientes" << std::endl;
        std::cout << "5. Mostrar CID" << std::endl;
        std::cout << "6. Mostrar Medicamentos" << std::endl;
        std::cout << "7. Mostrar Consultas" << std::endl;
        std::cout << "0. Sair" << std::endl;
        std::cout << "Escolha uma opcao: ";
        std::cin >> escolha;

        switch (escolha) {
            case 1:
                mostrarCidades(cidades);
                break;
            case 2:
                mostrarEspecialidades(especialidades);
                break;
            case 3:
                mostrarMedicos(medicos);
                break;
            case 4:
                mostrarPacientes(pacientes);
                break;
            case 5:
                mostrarCID(doencas);
                break;
            case 6:
                mostrarMedicamentos(medicines);
                break;
            case 7:
                mostrarConsultas(consultas);
                break;
            case 0:
                std::cout << "Saindo do programa..." << std::endl;
                break;
            default:
                std::cout << "Opçao invalida! Tente novamente." << std::endl;
        }

    } while (escolha != 0);

    return 0;
}
