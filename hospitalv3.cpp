#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>

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
    std::cout << "Digite o codigo da cidade: ";
    std::cin >> cidade.codigo;
    std::cin.ignore();
    std::cout << "Digite o nome da cidade: ";
    std::getline(std::cin, cidade.nome);
    std::cout << "Digite a UF da cidade: ";
    std::getline(std::cin, cidade.UF);
    return cidade;
}

Especialidades lerEspecialidade() {
    Especialidades especialidade;
    std::cout << "Digite o codigo da especialidade: ";
    std::cin >> especialidade.codigo1;
    std::cin.ignore();
    std::cout << "Digite a descricao da especialidade: ";
    std::getline(std::cin, especialidade.descricao);
    return especialidade;
}

Medicos lerMedico() {
    Medicos medico;
    std::cout << "Digite o codigo do medico: ";
    std::cin >> medico.codigo2;
    std::cin.ignore();
    std::cout << "Digite o nome do medico: ";
    std::getline(std::cin, medico.nome);
    std::cout << "Digite o codigo da especialidade: ";
    std::cin >> medico.codigo_especialidade;
    std::cin.ignore();
    std::cout << "Digite o endereco do medico: ";
    std::getline(std::cin, medico.endereco);
    std::cout << "Digite o telefone do medico: ";
    std::getline(std::cin, medico.telefone);
    std::cout << "Digite o codigo da cidade do medico: ";
    std::cin >> medico.codigo_cidade;
    return medico;
}

Pacientes lerPaciente() {
    Pacientes paciente;
    std::cout << "Digite o CPF do paciente: ";
    std::cin >> paciente.CPF;
    std::cin.ignore();
    std::cout << "Digite o nome do paciente: ";
    std::getline(std::cin, paciente.nome);
    std::cout << "Digite o endereco do paciente: ";
    std::getline(std::cin, paciente.endereco);
    std::cout << "Digite o codigo da cidade do paciente: ";
    std::cin >> paciente.codigo_cidade;
    return paciente;
}

CID lerCID() {
    CID cid;
    std::cout << "Digite o codigo do CID: ";
    std::cin >> cid.codigo3;
    std::cin.ignore();
    std::cout << "Digite a descricao do CID: ";
    std::getline(std::cin, cid.descricaoc);
    return cid;
}

Medicamentos lerMedicamento() {
    Medicamentos medicamento;
    std::cout << "Digite o codigo do medicamento: ";
    std::cin >> medicamento.codigo;
    std::cin.ignore();
    std::cout << "Digite a descricao do medicamento: ";
    std::getline(std::cin, medicamento.descricao);
    std::cout << "Digite a quantidade em estoque: ";
    std::cin >> medicamento.quant_estoque;
    std::cout << "Digite o estoque minimo: ";
    std::cin >> medicamento.estoque_minimo;
    std::cout << "Digite o estoque maximo: ";
    std::cin >> medicamento.estoque_maximo;
    std::cout << "Digite o preco unitario: ";
    std::cin >> medicamento.preco_unitario;
    return medicamento;
}

Consultas lerConsulta() {
    Consultas consulta;
    std::cout << "Digite o CPF do paciente: ";
    std::cin >> consulta.CPF;
    std::cout << "Digite o codigo do medico: ";
    std::cin >> consulta.cod_medico;
    std::cin.ignore();
    std::cout << "Digite a data da consulta: ";
    std::getline(std::cin, consulta.data);
    std::cout << "Digite o horario da consulta: ";
    std::getline(std::cin, consulta.horario);
    std::cout << "Digite o codigo do CID: ";
    std::cin >> consulta.cod_CID;
    std::cout << "Digite o codigo do medicamento: ";
    std::cin >> consulta.cod_medicamento;
    std::cout << "Digite a quantidade de medicamento: ";
    std::cin >> consulta.qtde_medicamento;
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

// Funções para adicionar dados
void adicionarCidade(std::vector<Cidades>& cidades) {
    Cidades novaCidade = lerCidade();
    auto it = std::find_if(cidades.begin(), cidades.end(), [&novaCidade](const Cidades& cidade) {
        return cidade.codigo == novaCidade.codigo;
    });
    if (it == cidades.end()) {
        cidades.push_back(novaCidade);
        std::cout << "Cidade adicionada com sucesso!\n";
    } else {
        std::cout << "Cidade com este código já existe!\n";
    }
}

void adicionarEspecialidade(std::vector<Especialidades>& especialidades) {
    Especialidades novaEspecialidade = lerEspecialidade();
    auto it = std::find_if(especialidades.begin(), especialidades.end(), [&novaEspecialidade](const Especialidades& especialidade) {
        return especialidade.codigo1 == novaEspecialidade.codigo1;
    });
    if (it == especialidades.end()) {
        especialidades.push_back(novaEspecialidade);
        std::cout << "Especialidade adicionada com sucesso!\n";
    } else {
        std::cout << "Especialidade com este código já existe!\n";
    }
}

void adicionarMedico(std::vector<Medicos>& medicos) {
    Medicos novoMedico = lerMedico();
    auto it = std::find_if(medicos.begin(), medicos.end(), [&novoMedico](const Medicos& medico) {
        return medico.codigo2 == novoMedico.codigo2;
    });
    if (it == medicos.end()) {
        medicos.push_back(novoMedico);
        std::cout << "Medico adicionado com sucesso!\n";
    } else {
        std::cout << "Medico com este código já existe!\n";
    }
}

void adicionarPaciente(std::vector<Pacientes>& pacientes) {
    Pacientes novoPaciente = lerPaciente();
    auto it = std::find_if(pacientes.begin(), pacientes.end(), [&novoPaciente](const Pacientes& paciente) {
        return paciente.CPF == novoPaciente.CPF;
    });
    if (it == pacientes.end()) {
        pacientes.push_back(novoPaciente);
        std::cout << "Paciente adicionado com sucesso!\n";
    } else {
        std::cout << "Paciente com este CPF já existe!\n";
    }
}

void adicionarCID(std::vector<CID>& doencas) {
    CID novaDoenca = lerCID();
    auto it = std::find_if(doencas.begin(), doencas.end(), [&novaDoenca](const CID& doenca) {
        return doenca.codigo3 == novaDoenca.codigo3;
    });
    if (it == doencas.end()) {
        doencas.push_back(novaDoenca);
        std::cout << "CID adicionada com sucesso!\n";
    } else {
        std::cout << "CID com este código já existe!\n";
    }
}

void adicionarMedicamento(std::vector<Medicamentos>& medicines) {
    Medicamentos novoMedicamento = lerMedicamento();
    auto it = std::find_if(medicines.begin(), medicines.end(), [&novoMedicamento](const Medicamentos& medicamento) {
        return medicamento.codigo == novoMedicamento.codigo;
    });
    if (it == medicines.end()) {
        medicines.push_back(novoMedicamento);
        std::cout << "Medicamento adicionado com sucesso!\n";
    } else {
        std::cout << "Medicamento com este código já existe!\n";
    }
}

int main() {
    // Inicializando a estrutura Cidades com os dados fornecidos
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
        std::cout << "Menu de Opções\n";
        std::cout << "1. Mostrar Cidades\n";
        std::cout << "2. Mostrar Especialidades\n";
        std::cout << "3. Mostrar Medicos\n";
        std::cout << "4. Mostrar Pacientes\n";
        std::cout << "5. Mostrar CID\n";
        std::cout << "6. Mostrar Medicamentos\n";
        std::cout << "7. Mostrar Consultas\n";
        std::cout << "8. Adicionar Cidade\n";
        std::cout << "9. Adicionar Especialidade\n";
        std::cout << "10. Adicionar Medico\n";
        std::cout << "11. Adicionar Paciente\n";
        std::cout << "12. Adicionar CID\n";
        std::cout << "13. Adicionar Medicamento\n";
        std::cout << "0. Sair\n";
        std::cout << "Escolha uma opção: ";
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
            case 8:
                adicionarCidade(cidades);
                break;
            case 9:
                adicionarEspecialidade(especialidades);
                break;
            case 10:
                adicionarMedico(medicos);
                break;
            case 11:
                adicionarPaciente(pacientes);
                break;
            case 12:
                adicionarCID(doencas);
                break;
            case 13:
                adicionarMedicamento(medicines);
                break;
            case 0:
                std::cout << "Saindo do programa...\n";
                break;
            default:
                std::cout << "Opção inválida! Tente novamente.\n";
        }
    } while (escolha != 0);

    return 0;
}
